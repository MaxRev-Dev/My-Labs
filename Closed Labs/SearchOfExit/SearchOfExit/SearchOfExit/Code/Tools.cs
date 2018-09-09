using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace SearchOfExit.Code
{
    public static class Tools
    {
        public static T Deserialize<T>(this string toDeserialize)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(T));
            StringReader textReader = new StringReader(toDeserialize);
            return (T)xmlSerializer.Deserialize(textReader);
        }

        public static string Serialize<T>(this T toSerialize)
        {
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(T));
            StringWriter textWriter = new StringWriter();
            xmlSerializer.Serialize(textWriter, toSerialize);
            return textWriter.ToString();
        }
        public static void CheckBounds(this Control control)
        {
            if (control == null || !(control is CellControl)) return;

            control.BackColor = ColorWas() ?? control.BackColor;
            (control as CellControl).DoEvents(Form.MouseButtons);
        }
        public static Color? ColorWas(MouseButtons? chk = null)
        {
            var t = chk ?? Form.MouseButtons;
            if (t == MouseButtons.Left)
                return Color.Black;
            else if (t == MouseButtons.Right)
                return Color.Gray;
            else if (t == MouseButtons.Middle)
                return Color.Yellow;
            else return null;
        }
        public static IEnumerable<IEnumerable<T>> Split<T>(this T[] array)
        {
            int size = (int)Math.Sqrt(array.Length);
            for (var i = 0; i < (float)array.Length / size; i++)
            {
                yield return array.Skip(i * size).Take(size);
            }
        }
        public static IEnumerable<T> Concat<T>(this List<List<T>> array)
        {
            int index = 0;
            int width = array.First().Count();
            int height = array.Count();
            T[] single = new T[width * height];
            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    single[index] = array[x][y];
                    index++;
                }
            }
            return single;
        }
        public static Control FindControlAtPoint(Control container, Point pos)
        {
            Control child;
            foreach (Control c in container.Controls)
            {
                if (c.Visible && c.Bounds.Contains(pos))
                {
                    child = FindControlAtPoint(c, new Point(pos.X - c.Left, pos.Y - c.Top));
                    if (child == null) return c;
                    else return child;
                }
            }
            return null;
        }

        public static Control FindControlAtCursor(Form form)
        {
            Point pos = Cursor.Position;
            if (form.Bounds.Contains(pos))
                return FindControlAtPoint(form, form.PointToClient(pos));
            return null;
        }

        public static Point GetCell(List<List<CellControl>> cells, CellControl last)
        {
            var ln = cells.Where(line => line.Where(cell => cell.GetID == last.GetID).Any()).First();
            int x = cells.IndexOf(ln);
            int y = ln.IndexOf(ln.Where(cell => cell.GetID == last.GetID).First());
            return new Point(x, y);
        }
        public static bool IsPressed(int vKey)
        {
            return GetAsyncKeyState(vKey) == -32767;
        }

        public class PriorityQueue<T>
        { 

            private List<Tuple<T, double>> elements = new List<Tuple<T, double>>();

            public int Count
            {
                get { return elements.Count; }
            }

            public void Enqueue(T item, double priority)
            {
                elements.Add(Tuple.Create(item, priority));
            }

            public T Dequeue()
            {
                int bestIndex = 0;

                for (int i = 0; i < elements.Count; i++)
                {
                    if (elements[i].Item2 < elements[bestIndex].Item2)
                    {
                        bestIndex = i;
                    }
                }

                T bestItem = elements[bestIndex].Item1;
                elements.RemoveAt(bestIndex);
                return bestItem;
            }
        }
        [DllImport("User32.dll")]
        private static extern short GetAsyncKeyState(int vKey);
    }
}
