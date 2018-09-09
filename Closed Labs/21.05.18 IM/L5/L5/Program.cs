using System;

namespace L5
{
    class Program
    {
        class PolarSystem
        {
            public class PolarPoint
            {
                public PolarPoint() { }
                public PolarPoint(float r, float phi) { this.R = r; this.Phi = phi; }
                //Main properties
                public float Phi { get; set; }
                public float R { get; set; }
                //convertion
                public DecartPoint ToDecart()
                {
                    return new DecartPoint()
                    {
                        X = (float)Math.Round(R * Math.Cos(Phi), 2),
                        Y = (float)Math.Round(R * Math.Sin(Phi), 2)
                    };
                }
                //Making comparable
                public override bool Equals(object obj)
                {
                    if (obj == null || GetType() != obj.GetType()) return false;
                    var t = obj as PolarPoint;
                    if (this.Phi == t.Phi && this.R == t.R) return true;
                    return false;
                }
                public override int GetHashCode()
                {
                    return (int)(Phi * R);
                }
            }
            public class DecartPoint
            {
                public DecartPoint() { }
                public DecartPoint(float x, float y) { this.X = x; this.Y = y; }
                //Main properties
                public float X { get; set; }
                public float Y { get; set; }
                //convertion
                public PolarPoint ToPolar()
                {
                    float r = (float)(Math.Sqrt(Math.Pow(X, 2) + Math.Pow(Y, 2)));
                    float phi = 1;
                    if (r != 0)
                    {
                        if (X > 0) phi = (float)(Math.Atan2(Y, X));
                        else if (X < 0 && Y >= 0) phi = (float)(Math.Atan2(Y, X) + Math.PI);
                        else if (X < 0 && Y < 0) phi = (float)(Math.Atan2(Y, X) - Math.PI);
                        else if (X == 0 && Y > 0) phi = (float)Math.PI / 2;
                        else if (X == 0 && Y < 0) phi = (float)-Math.PI / 2;
                    }
                    return new PolarPoint()
                    {
                        R = r,
                        Phi = phi
                    };
                }
                //Making comparable
                public override bool Equals(object obj)
                {
                    if (obj == null || GetType() != obj.GetType()) return false;
                    var t = obj as DecartPoint;
                    if (this.X == t.X && this.Y == t.Y) return true;
                    return false;
                }
                public override int GetHashCode()
                {
                    return (int)(X * Y * 100);
                }
            }

            protected PolarPoint Polar { get; set; }
            protected DecartPoint Decart { get; set; }

            public PolarPoint ToPolar() => this.Decart?.ToPolar() ?? this.Polar?.ToDecart().ToPolar();
            public DecartPoint ToDecart() => this.Polar?.ToDecart() ?? this.Decart?.ToPolar().ToDecart();

            public virtual void SetInPolar(float r, float phi) => Polar = new PolarPoint(r, phi);
            public virtual void SetInDecart(float x, float y) => Decart = new DecartPoint(x, y);
        }
        class CylinderSystem : PolarSystem
        {
            public float Z { get; set; }
            public CylinderSystem() { }
            public override void SetInPolar(float r, float phi)
            {
                base.SetInPolar(r, phi);
                this.Z = 0;
            }
            public override void SetInDecart(float x, float y)
            {
                base.SetInDecart(x, y);
                this.Z = 0;
            }
        }
        static void Main(string[] args)
        {
            CylinderSystem cylinder = new CylinderSystem();
            PolarSystem polar = new PolarSystem();
            cylinder.SetInDecart(1, 1);
            polar.SetInDecart(1, 1);
            Console.WriteLine("Point in decart: x:{0} y:{1}", polar.ToDecart().X, polar.ToDecart().Y);
            Console.WriteLine("Point in polar: R:{0} Phi:{1}", polar.ToPolar().R, polar.ToPolar().Phi);
            var polarval = cylinder.ToPolar();
            var decartval = polarval.ToDecart();
            var polarval2 = decartval.ToPolar();

            Console.WriteLine("Point in decart (converted): x:{0} y:{1}", decartval.X, decartval.Y);
            Console.WriteLine("Point in polar  (converted): R:{0} Phi:{1}", polarval2.R, polarval2.Phi);
            if (cylinder.ToPolar().Equals(polarval2)) Console.WriteLine("Convertion forward-back  - success");
            else Console.WriteLine("Convertion not match");

            Console.ReadLine();
        }
    }
}
