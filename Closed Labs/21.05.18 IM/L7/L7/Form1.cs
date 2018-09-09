using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L7
{
    public partial class Form1 : Form
    {
        int scale = 400;
        public Form1()
        {
            InitializeComponent();
            Width = Height = scale + 200;
        }
        void Repaint()
        {

            var pen = new Pen(new SolidBrush(Color.Black));

            float y(float x) => (float)(Math.Acos(x) / (2 * x + 1));

            float xmin = 0.1f, xmax = 0.9f, dx = 0.1f;
            List<PointF> plist = new List<PointF>();
            for (float i = xmin; i <= xmax; i += dx)
                plist.Add(new PointF(i * scale, y(i) * scale));
            var g = this.CreateGraphics();
            g.Clear(DefaultBackColor);
            g.DrawCurve(pen, plist.ToArray());
            var h2 = this.Height / 2;
            g.DrawLine(pen, new PointF(0, h2), new PointF(this.Width, h2));
            var w2 = this.Width / 2;

            g.DrawLine(pen, new PointF(w2, 0), new PointF(w2, this.Height));
        }
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Repaint();


        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            Repaint();
        }
    }
}
