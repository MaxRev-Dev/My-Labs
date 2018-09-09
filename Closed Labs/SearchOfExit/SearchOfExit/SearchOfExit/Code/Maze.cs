using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;

namespace SearchOfExit.Code
{
    [Serializable]
    public class Maze
    {
        [JsonProperty("name")]
        public string Name;
        public Maze() { }
        public Maze(string name) { this.Name = name; }
        public Maze(string name, IEnumerable<IEnumerable<CellControl>> mazeMap) : this(name)
        {
            this.MazeMap = mazeMap.Select(line => line.Select(cell => (int)cell.GetWallType()));
        }
        public void Solve(CellControl[] cells)
        {
            var cellsList = cells.ToList();
            var cellsList2D = cells.Split().Select(line => line.ToList()).ToList();
            var indexes2D = cellsList.Select(x => cellsList.IndexOf(x)).ToArray().Split().Select(li => li.ToArray()).ToArray();
            this.MazeMap = cellsList2D.Select(line => line.Select(cell => (int)cell.GetWallType()));

            //solve maze
            var astar = new AstarSolver(indexes2D, MazeMap);
            //then perf draw to refresh wall type
            var res = astar.currentMazeMapFlat.Select(li => li.ToArray()).ToArray();
            for (int i = 0; i < cellsList2D.Count(); i++)
                for (int j = 0; j < cellsList2D.Count(); j++)
                    cellsList2D[j][i].SetWallType((CellControl.WallType)res[j][i]);
        }

        [JsonProperty("map")]
        private IEnumerable<IEnumerable<int>> MazeMap { get; set; }
        public IEnumerable<IEnumerable<CellControl>> GetCellControls()
        {
            return MazeMap.Select(line => line.Select(cell => CellControl.CreateCellControl(cell)));
        }

        public override bool Equals(object obj)
        {
            if (!(obj is Maze)) return false;
            Maze j = obj as Maze;
            return Name == j.Name;
        }
        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

    }

    public class AstarSolver
    {
        public readonly List<List<int>> currentMazeMapFlat;

        public AstarSolver(int[][] cells, IEnumerable<IEnumerable<int>> currentMazeMap)
        {
            /// solving plot grid
            var grid = new SquareGrid(cells.First().Count(), cells.Count());
            // converting to flat list
            currentMazeMapFlat = currentMazeMap.Select(l => l.ToList()).ToList();

            // toArray for indexing
            var currentMazeMapArray = currentMazeMap.Select(x => x.ToArray()).ToArray();

            GraphPoint start = new GraphPoint(0, 0), end = new GraphPoint(0, 0); // default values
            // adding  map to grid
            for (int i = 0; i < cells.First().Count(); i++)
            {
                for (int j = 0; j < cells.Count(); j++)
                {
                    if ((CellControl.WallType)currentMazeMapFlat[j][i] == CellControl.WallType.Solid)
                        grid.walls.Add(new GraphPoint(i, j));
                    if (currentMazeMapArray[j][i] == (int)CellControl.WallType.Start)
                        start = new GraphPoint(i, j);
                    if (currentMazeMapArray[j][i] == (int)CellControl.WallType.End)
                        end = new GraphPoint(i, j);
                }
            }

            // initializing search 
            var astar = new AStarSearch(grid, start, end);
            // reconstructing path from "memory array" 
            var path = ReconstructPath(grid, astar);
            if (path == null) return; //no solution
            //Performing cells visual updating
            for (int i = 0; i < cells.First().Count(); i++)
            {
                for (int j = 0; j < cells.Count(); j++)
                {
                    if (currentMazeMapFlat[j][i] == (int)(CellControl.WallType.CorrectPath))
                        currentMazeMapFlat[j][i] = (int)(CellControl.WallType.None);
                    var a = path.Where(x => x.x == i && x.y == j);
                    if (a.Any() && currentMazeMapFlat[j][i] != (int)(CellControl.WallType.End))// end overdraving fix
                        currentMazeMapFlat[j][i] = (int)(CellControl.WallType.CorrectPath);
                }
            }

        }

        List<GraphPoint> ReconstructPath(SquareGrid grid, AStarSearch astar)
        {
            //in reverse way -> end = start 
            GraphPoint end = astar.cameFrom.Where(x => x.Key.wType == GraphPoint.WType.start).First().Key;
            var tr = astar.cameFrom.Where(x => x.Key.wType == GraphPoint.WType.end);
            if (tr.Any())
            {
                GraphPoint cur = tr.First().Key;
                List<GraphPoint> path = new List<GraphPoint>();
                while (!cur.Equals(end))
                {
                    GraphPoint ptr = cur;
                    if (!astar.cameFrom.TryGetValue(cur, out ptr))
                        ptr = cur;
                    path.Add(cur);
                    cur = ptr;
                }
                return path;
            }
            else
            {
                DialogResult result = System.Windows.Forms.MessageBox.Show(Application.OpenForms[0],  "Лабіринт не має розв'язку","Помилка", MessageBoxButtons.YesNo); 
            }
            return null;
        }

        #region A* struct
        public struct GraphPoint
        {
            public enum WType { def, start, end }
            public WType wType;
            public readonly int x, y;
            public GraphPoint(int x, int y)
            {
                this.wType = default(WType);
                this.x = x;
                this.y = y;
            }
        }

        public interface IWeightedGraph<L>
        {
            double Cost(GraphPoint a, GraphPoint b);
            IEnumerable<GraphPoint> Neighbors(GraphPoint id);
        }

        public class SquareGrid : IWeightedGraph<GraphPoint>
        {
            public static readonly GraphPoint[] DIRS = new[]
                {
            new GraphPoint(1, 0),
            new GraphPoint(0, -1),
            new GraphPoint(-1, 0),
            new GraphPoint(0, 1)
        };

            public int width, height;
            public HashSet<GraphPoint> walls = new HashSet<GraphPoint>();

            public SquareGrid(int width, int height)
            {
                this.width = width;
                this.height = height;
            }

            public bool InBounds(GraphPoint id)
            {
                return 0 <= id.x && id.x < width
                    && 0 <= id.y && id.y < height;
            }

            public bool Passable(GraphPoint id)
            {
                return !walls.Contains(id);
            }

            public double Cost(GraphPoint a, GraphPoint b)
            {
                return 0.5 * Math.Sqrt(Math.Pow(a.x - b.x, 2) + Math.Pow(a.y - b.y, 2));
            }

            public IEnumerable<GraphPoint> Neighbors(GraphPoint id)
            {
                foreach (var dir in DIRS)
                {
                    GraphPoint next = new GraphPoint(id.x + dir.x, id.y + dir.y);
                    if (InBounds(next) && Passable(next))
                    {
                        yield return next;
                    }
                }
            }
        }

        public class AStarSearch
        {
            public Dictionary<GraphPoint, GraphPoint> cameFrom
                = new Dictionary<GraphPoint, GraphPoint>();
            public Dictionary<GraphPoint, double> costSoFar
                = new Dictionary<GraphPoint, double>();
            static public double Heuristic(GraphPoint a, GraphPoint b)
                => Math.Abs(a.x - b.x) + Math.Abs(a.y - b.y);

            public AStarSearch(IWeightedGraph<GraphPoint> graph, GraphPoint start, GraphPoint goal)
            {
                start.wType = GraphPoint.WType.start;
                goal.wType = GraphPoint.WType.end;
                var box = new Tools.PriorityQueue<GraphPoint>();
                box.Enqueue(start, 0);

                cameFrom[start] = start;
                costSoFar[start] = 0;

                while (box.Count > 0)
                {
                    var current = box.Dequeue();

                    if (current.x == goal.x && current.y == goal.y)
                    {

                        cameFrom[goal] = current;
                        break;
                    }

                    foreach (var next in graph.Neighbors(current))
                    {
                        double newCost = costSoFar[current]
                            + graph.Cost(current, next);
                        if (!costSoFar.ContainsKey(next)
                            || newCost < costSoFar[next])
                        {
                            costSoFar[next] = newCost;
                            double priority = newCost + Heuristic(next, goal);
                            box.Enqueue(next, priority);
                            cameFrom[next] = current;
                        }
                    }
                }
            }
        }
        #endregion
    }
}