using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;

namespace Plot
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Paint += Form1_Paint;
            Height = 400;
            Width = 1200;
        }
        class XPoint
        {
            public XPoint() {
                /* Say hi in base*/
            }
            /// <summary>
            /// From real values setup
            /// </summary>
            /// <param name="x"></param>
            /// <param name="y"></param>
            public XPoint(double x, double y) : base() { this.RealX = x; this.RealY = y; }
            /// <summary>
            /// From form coords setup
            /// </summary>
            /// <param name="x"></param>
            /// <param name="y"></param>
            public XPoint(float x, float y) : base() { this.FormX = x; this.FormY = y; }
            public static int Scale = 400;
            public double RealX { get; set; }
            public double RealY { get; set; }
            public double FormX { get { return Scale * RealX; } private set { RealX = value / Scale; } }
            public double FormY { get { return Scale * RealY; } private set { RealY = value / Scale; } }
            public PointF Point() { return new PointF((float)FormX, (float)FormY); }
        }
        class Plot
        {
            public Plot(Pen pen, Graphics g)
            {
                this.pen = pen;
                this.g = g;
                AxisX = new XPoint[2];
                AxisY = new XPoint[2];
            }

            #region Properties
            enum Direction { X, Y }
            Graphics g;
            Pen pen;
            public int Width { get; set; }
            public int Height { get; set; }
            public int Margin { get; set; }
            public int Padding { get; set; }
            public int FractWidth { get; set; }
            public XPoint[] AxisX { get; set; }
            public XPoint[] AxisY { get; set; }
            private int NormalizingX;
            private float OffsetX, YinvertCoef;
            List<XPoint> fullPoints;
            #endregion

            #region Helpers & Converters
            /// <summary>
            /// Main points setup method
            /// </summary>
            /// <param name="fullPoints"></param>
            public void SetPoints(List<XPoint> fullPoints)
            {
                this.fullPoints = fullPoints;
                FlipPoints();
            }
            /// <summary>
            /// Axis bounds check and setup with padding
            /// </summary>
            public void SetAxis()
            {
                var Points = fullPoints.Select(x => x.Point()).ToArray();

                var points = Points.OrderByDescending(x => x.X).ToArray();
                float xmax = points.First().X, xmin = points.Last().X;
                points = points.OrderByDescending(x => x.Y).ToArray();
                float ymax = points.First().Y, ymin = points.Last().Y;

                AxisX[1] = new XPoint(Points.First().X - Padding, Padding);

                AxisX[0] = AxisY[0] = new XPoint(Points.First().X - Padding, ymax + Padding);

                AxisY[1] = new XPoint(Points.Last().X + Padding, ymax + Padding);

            }
            /// <summary>
            /// Moving points with screen coords
            /// </summary>
            /// <param name="point"></param>
            /// <param name="x"></param>
            /// <param name="y"></param>
            public void Move(ref PointF point, int x, int y) => point = new PointF(point.X + x, point.Y + y);
            /// <summary>
            /// Moving custom points
            /// </summary>
            /// <param name="point"></param>
            /// <param name="x"></param>
            /// <param name="y"></param>
            public void Move(ref XPoint point, int x, int y) => point = new XPoint((float)point.FormX + x, (float)point.FormY + y);
            /// <summary>
            /// Returns average value on X or Y axis
            /// </summary>
            /// <param name="d"></param>
            /// <returns></returns>
            private float GetAver(Direction d) => (float)(fullPoints.Select(x => d == Direction.X ? x.RealX : x.RealY).Aggregate((c, n) => c + n) * 1.0 / fullPoints.Count);
            /// <summary>
            /// Flips points of Y axis for relative position on screen
            /// </summary>
            private void FlipPoints()
            {
                if (fullPoints.Count == 0) return;
                // flip for screen coords
                fullPoints = fullPoints.OrderByDescending(x => x.RealY).ToList();
                YinvertCoef = (float)Math.Round(fullPoints.First().RealY - fullPoints.Last().RealY, MidpointRounding.AwayFromZero) + 1;
                fullPoints = fullPoints.OrderBy(x => x.RealX).ToList();
            }
            #endregion

            #region Drawing Methods
            /// <summary>
            /// For arrows on axises
            /// </summary>
            /// <param name="p"></param>
            /// <param name="d"></param>
            private void DrawArrow(XPoint p, Direction d)
            {
                XPoint la = null, ra = null;
                var len = FractWidth * 0.8;
                switch (d)
                {
                    case Direction.X:
                        {
                            la = new XPoint((float)(p.FormX - len * .5), (float)(p.FormY + len));
                            ra = new XPoint((float)(p.FormX + len * .5), (float)(p.FormY + len));
                        }
                        break;
                    case Direction.Y:
                        {
                            la = new XPoint((float)(p.FormX - len), (float)(p.FormY + len * .5));
                            ra = new XPoint((float)(p.FormX - len), (float)(p.FormY - len * .5));
                        }
                        break;
                    default:
                        return;
                }
                g.DrawLines(pen, new[] { la.Point(), p.Point(), ra.Point(),
                    new PointF(d == Direction.Y?p.Point().X-(float)(len/2.0):p.Point().X,
                    d == Direction.X ?p.Point().Y-(float)(len/2.0):p.Point().Y)
                    ,la.Point()});
            }
            /// <summary>
            /// For fractions on axises
            /// </summary>
            public void DrawFractions()
            {
                List<PointF[]> pointsY = new List<PointF[]>();
                List<XPoint> dp;
                var fa = GetAver(Direction.X);
                var fb = GetAver(Direction.Y);
                dp = this.fullPoints.Select(x =>
                {
                    return new XPoint(
                      fa > 1 ? Math.Round(x.RealX, MidpointRounding.AwayFromZero) - 1 : Math.Round(x.RealX, 1),
                            fb > 1 ? Math.Round(x.RealY, MidpointRounding.AwayFromZero) - 1 : Math.Round(x.RealY, 1));
                }).Distinct().ToList();

                OffsetX = (int)(-AxisY[0].Point().X + Margin);
                foreach (var e in dp)
                {
                    var xy = AxisX[0].Point().Y;
                    var yx = AxisY[0].Point().X;
                    var fw2 = (float)(FractWidth / 2.0);
                    var i = e.Point();
                    // X part
                    var h1 = new PointF(i.X + OffsetX, xy + fw2);
                    var h2 = new PointF(i.X + OffsetX, xy - fw2);
                    g.DrawString(string.Format("{0}",
                        e.RealX.ToString("f2")),
                        DefaultFont, new SolidBrush(Color.Red),
                        new PointF(i.X + OffsetX, xy + 5));
                    g.DrawLine(pen, h1, h2);

                    // Y part
                    h1 = new PointF(yx + OffsetX + fw2, i.Y);
                    h2 = new PointF(yx + OffsetX - fw2, i.Y);

                    // Y must be inverted on screen 
                    g.DrawString(string.Format("{0}",
                        (YinvertCoef - e.RealY).ToString("f2")),
                        DefaultFont, new SolidBrush(Color.Red),
                        new PointF(yx + OffsetX - 10, i.Y));
                    g.DrawLine(pen, h1, h2);
                }

            }
            /// <summary>
            /// Main component - curve
            /// </summary>
            private void DrawCurve()
            {
                NormalizingX = (int)-AxisX[0].Point().X;
                var desp = fullPoints.Select(x => { var p = x.Point(); Move(ref p, NormalizingX + Margin, 0); return p; }).ToArray();
                g.DrawCurve(pen, desp);

                foreach (var i in fullPoints)
                {
                    var p = i.Point(); Move(ref p, NormalizingX + Margin, 0);
                    g.DrawString(string.Format("({0},{1})", i.RealX.ToString("f2"), (YinvertCoef - i.RealY).ToString("f2")), DefaultFont, new SolidBrush(Color.Red), p);
                }
            }
            /// <summary>
            /// Main drawing method logic
            /// </summary>
            public void DrawComponent()
            {
                if (fullPoints.Count == 0) throw new Exception("Attempt to draw with no points setup");
                OffsetX = (float)(fullPoints.First().RealX - Math.Round(fullPoints.First().RealX, MidpointRounding.AwayFromZero)) * XPoint.Scale;

                SetAxis();
                // axises fractions
                DrawFractions();

                // main occasion)
                DrawCurve();

                // Moving axises lines
                AxisX = AxisX.Select(x => { Move(ref x, NormalizingX + Margin, 0); return x; }).ToArray();
                AxisY = AxisY.Select(x => { Move(ref x, NormalizingX + Margin, 0); return x; }).ToArray();

                // Drawing axises
                g.DrawLine(pen, AxisX[0].Point(), AxisX[1].Point());
                g.DrawLine(pen, AxisY[0].Point(), AxisY[1].Point());
                DrawArrow(AxisX[1], Direction.X);
                DrawArrow(AxisY[1], Direction.Y);
            }
            #endregion
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            var dx = 0.8;
            double xmin = 2.3, xmax = 5.4;
            double y(double val) => (val + Math.Cos(2 * val)) / (3.0 * val);//формула 
            var points = new List<XPoint>();
            for (double x = xmin; x <= xmax; x += dx)
                points.Add(new XPoint(x, y(x)));
            var p = new Plot(new Pen(new SolidBrush(Color.Black)), this.CreateGraphics())
            {
                Padding = 50,
                Margin = 30,
                FractWidth = 15
            };
            p.SetPoints(points);
            try
            {
                p.DrawComponent();
            }
            catch { }
        }
    }
}
