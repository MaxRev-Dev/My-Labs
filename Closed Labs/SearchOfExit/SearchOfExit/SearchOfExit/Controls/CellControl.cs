using SearchOfExit.Code;
using System.Drawing;
using System.Windows.Forms;
using System.Diagnostics;
using System;

namespace SearchOfExit
{
    public partial class CellControl : UserControl
    {
        public CellControl()
        {
            InitializeComponent();
            Margin = new Padding(0);
            Padding = new Padding(1);
            BorderStyle = BorderStyle.FixedSingle;
            this.BackColor = Lead.Current.Config.BackColor;
            this.Cursor = Cursors.Hand;

            MouseDown += (s, e) => Tools.FindControlAtCursor(this.FindForm()).CheckBounds();
            MouseMove += (s, e) => Tools.FindControlAtCursor(this.FindForm()).CheckBounds();
        }
        public class SelectedCellEventArgs
        {
            public SelectedCellEventArgs(int indexInArray, MouseButtons key)
            {
                IndexInArray = indexInArray;
                Buttons = key;
            }
            public MouseButtons Buttons { get; }
            public int IndexInArray { get; }
        }
        
        #region WallTypes
        public enum WallType { None, Solid, CorrectPath, Start, End }
        public WallType GetWallType()
        {
            var cfg = Lead.Current.Config;
            if (this.BackColor.Name == cfg.WallColor.Name)
                return WallType.Solid;
            if (this.BackColor.Name == cfg.CorrectColor.Name)
                return WallType.CorrectPath;
            if (this.BackColor.Name == cfg.StartColor.Name)
                return WallType.Start;
            if (this.BackColor.Name == cfg.EndColor.Name)
                return WallType.End;
            return WallType.None;
        }
        public void SetWallType(WallType type)
        {
            var cfg = Lead.Current.Config;
            switch (type)
            {
                case WallType.Solid:
                    this.BackColor = cfg.WallColor;
                    break;
                case WallType.CorrectPath:
                    this.BackColor = cfg.CorrectColor;
                    break;
                case WallType.End:
                    this.BackColor = cfg.EndColor;
                    break;
                case WallType.Start:
                    this.BackColor = cfg.StartColor;
                    break;
                case WallType.None:
                default:
                    this.BackColor = cfg.BackColor;
                    break;
            }
        }
        #endregion

        public static CellControl CreateCellControl(int val = 0)
        {
            var c = new CellControl()
            {
                Height = 15,
                Width = 15
            };
            c.SetWallType((CellControl.WallType)val);
            return c;
        }

        public int GetID => (this.Parent as FlowLayoutPanel).Controls.IndexOf(this);
        public delegate void OnSelected(object sender, SelectedCellEventArgs e);
        public event OnSelected Selected;
        private void GotSelected(MouseButtons key)
        {
            if (key != MouseButtons.None)
                Selected?.Invoke(this,
                    new SelectedCellEventArgs(GetID, key));
        }
        public void DoEvents(MouseButtons key)
        {
            GotSelected(key);
        }
    }
}
