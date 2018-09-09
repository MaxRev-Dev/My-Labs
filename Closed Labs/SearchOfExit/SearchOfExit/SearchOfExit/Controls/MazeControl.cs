
using Newtonsoft.Json;
using SearchOfExit.Code;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Windows.Forms;

namespace SearchOfExit
{
    public partial class MazeControl : UserControl
    {
        int shiftKey = 0x10, ctrl = 0x11;
        static int wall = 30;

        public MazeControl()
        {
            InitializeComponent();
            this.Padding = new Padding(10);
            Load += MazeControl_Load;

            cellsCurrent = new CellControl[wall * wall]
               .Select(x =>
               {
                   x = CellControl.CreateCellControl();
                   x.Selected += X_Selected;
                   return x;
               }).ToArray();
        }

        private void MazeControl_Load(object sender, System.EventArgs e)
        {
            panel.Controls.AddRange(cellsCurrent);

            // Load Maze on form load
            LoadMaze();
        }

        #region CellsArray
        CellControl[] cellsCurrent;
        List<List<CellControl>> Cells2D
        {
            get => cellsCurrent.Split().Select(x => x.ToList()).ToList();
            set => cellsCurrent = value.Concat().ToArray();
        }
        #endregion

        #region CellSelectedHandler
        CellControl LastSelected;
        private void X_Selected(object sender, CellControl.SelectedCellEventArgs e)
        {
            bool reserve = false;
            if (Tools.IsPressed(shiftKey))
            {
                if (LastSelected == null)
                {
                    LastSelected = sender as CellControl;
                    return;
                }
                reserve = true;
                var p1 = Tools.GetCell(Cells2D, LastSelected);
                var p2 = Tools.GetCell(Cells2D, sender as CellControl);
                if (p1.X == p2.X)
                {
                    int first = p1.Y < p2.Y ? p1.Y : p2.Y;
                    int lastp = p1.Y > p2.Y ? p1.Y : p2.Y;
                    for (int i = first; i < lastp; i++)
                        Cells2D[p1.X][i].BackColor = Tools.ColorWas(e.Buttons) ?? Cells2D[p1.X][i].BackColor;
                }
                else if (p1.Y == p2.Y)
                {
                    int first = p1.X < p2.X ? p1.X : p2.X;
                    int lastp = p1.X > p2.X ? p1.X : p2.X;
                    for (int i = first; i < lastp; i++)
                        Cells2D[i][p1.Y].BackColor = Tools.ColorWas(e.Buttons) ?? Cells2D[i][p1.Y].BackColor;

                }
                LastSelected = sender as CellControl;
            }
            if (Tools.IsPressed(ctrl))
            {
                var p = Tools.GetCell(Cells2D, sender as CellControl);
                var color =
                    e.Buttons == MouseButtons.Left ?
                    Lead.Current.Config.StartColor:
                            (e.Buttons==MouseButtons.Right?
                                Lead.Current.Config.EndColor: 
                                  Lead.Current.Config.BackColor); //Default
                
                for (int i = 0; i < Cells2D.Count; i++) 
                    for (int j = 0; j < Cells2D.First().Count; j++) 
                        if (Cells2D[j][i].BackColor == color) Cells2D[j][i].BackColor = Lead.Current.Config.BackColor;
            
                Cells2D[p.X][p.Y].BackColor =color;
                LastSelected = null;
            } 
            if (!reserve)
                LastSelected = null;
        }
        #endregion

        #region Grid
        public void GridVisibililty(bool visible)
        {
            if (visible)
                foreach (CellControl cell in this.panel.Controls)
                    cell.BorderStyle = BorderStyle.FixedSingle;
            else
                foreach (CellControl cell in this.panel.Controls)
                    cell.BorderStyle = BorderStyle.None;
        }
        public void RemoveGrid()
        {
            foreach (var i in this.panel.Controls)
                (i as CellControl).BackColor = DefaultBackColor;
        }
        public void CreateGrid()
        {
            foreach (var i in this.panel.Controls)
                (i as CellControl).BackColor = Lead.Current.Config.BackColor;
            for (int i = 0; i < Cells2D.Count; i++)
            {
                Cells2D[i][0].BackColor = Lead.Current.Config.WallColor;
                Cells2D[0][i].BackColor = Lead.Current.Config.WallColor;
                Cells2D[i][Cells2D.Count - 1].BackColor = Lead.Current.Config.WallColor;
                Cells2D[Cells2D.Count - 1][i].BackColor = Lead.Current.Config.WallColor;
            }
        }
        #endregion

        #region ImportExport
        public void Import()
        {
            OpenFileDialog dialog = new OpenFileDialog()
            {
                FileName = "map.maze",
                Filter = "Maze map file|*.maze",
                InitialDirectory = Directory.GetCurrentDirectory(),
                Title = "Відкрити лабіринт"
            };
            var r = dialog.ShowDialog();
            if (r == DialogResult.OK)
            {
                var f = dialog.FileName;
                var maze = JsonConvert.DeserializeObject<Maze>(File.ReadAllText(f));
                LoadMaze(maze);
            }
        }
        public void Export()
        {
            SaveFileDialog dialog = new SaveFileDialog()
            {
                FileName = "map.maze",
                Filter = "Maze map file|*.maze",
                InitialDirectory = Directory.GetCurrentDirectory(),
                Title = "Зберегти лабіринт як",

            };
            var r = dialog.ShowDialog();
            if (r == DialogResult.OK)
            {
                var f = dialog.FileName;
                File.WriteAllText(f, JsonConvert.SerializeObject(GetCurrentMaze()));
            }
        }
        #endregion

        public void SaveMaze()
        {
            Lead.MazeManager.Current.SaveToSettings(GetCurrentMaze());
        }
        public void ClearAll()
        {
            Lead.MazeManager.Current.ClearAll();
        }

        public void Solve()
        {
            GetCurrentMaze().Solve(cellsCurrent);
        }

        private Maze GetCurrentMaze()
        {
            return new Maze("main", Cells2D);
        }
        public void LoadMaze(Maze maze = null)
        {
            var newMaze = (maze ?? Lead.MazeManager.Current.GetFromSettings("main"))?
                 .GetCellControls().Select(line => line.ToList()).ToList();
            if (newMaze == null) return;
            for (int i = 0; i < newMaze.Count; i++)
            {
                for (int j = 0; j < newMaze.First().Count; j++)
                {
                    Cells2D[i][j].SetWallType(newMaze[i][j].GetWallType());
                }
            }
        }
    }
}
