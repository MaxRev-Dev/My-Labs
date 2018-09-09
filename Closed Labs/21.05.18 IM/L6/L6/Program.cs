using System;

namespace L6
{
    class Program
    {
        abstract class CoordSystem
        {
            public abstract void SetInPolar(float r, float phi);
            public abstract void SetInDecart(float x, float y);
        }
        class PolarSystem : CoordSystem
        {
            interface IPoint
            {
                float FirstBasis { get; set; }
                float SecondBasis { get; set; }
            }
            interface IDecartConverter { DecartPoint ToDecart(); }
            interface IPolarConverter { PolarPoint ToPolar(); }

            public abstract class Point
            {
                public abstract float FirstBasis { get; set; }
                public abstract float SecondBasis { get; set; }
            }
            public class PolarPoint : Point, IDecartConverter
            {
                public PolarPoint() { }
                public PolarPoint(float r, float phi) { this.SecondBasis = r; this.FirstBasis = phi; }
                //Main properties
                /// <summary>
                /// Rho base
                /// </summary>
                public override float FirstBasis { get; set; }
                /// <summary>
                /// Phi base
                /// </summary>
                public override float SecondBasis { get; set; }
                //convertion
                public DecartPoint ToDecart()
                {
                    return new DecartPoint()
                    {
                        FirstBasis = (float)Math.Round(SecondBasis * Math.Cos(FirstBasis), 2),
                        SecondBasis = (float)Math.Round(SecondBasis * Math.Sin(FirstBasis), 2)
                    };
                }
                //Making comparable
                public override bool Equals(object obj)
                {
                    if (obj == null || GetType() != obj.GetType()) return false;
                    var t = obj as PolarPoint;
                    if (this.FirstBasis == t.FirstBasis && this.SecondBasis == t.SecondBasis) return true;
                    return false;
                }
                public override int GetHashCode()
                {
                    return (int)(FirstBasis * SecondBasis);
                }
                ~PolarPoint() { }
            }
            public class DecartPoint : Point, IPolarConverter
            {
                public DecartPoint() { }
                public DecartPoint(float x, float y) { this.FirstBasis = x; this.SecondBasis = y; }
                //Main properties
                /// <summary>
                /// X base
                /// </summary>
                public override float FirstBasis { get; set; }
                /// <summary>
                /// Y base
                /// </summary>
                public override float SecondBasis { get; set; }
                //convertion
                public PolarPoint ToPolar()
                {
                    float r = (float)(Math.Sqrt(Math.Pow(FirstBasis, 2) + Math.Pow(SecondBasis, 2)));
                    float phi = 1;
                    if (r != 0)
                    {
                        if (FirstBasis > 0) phi = (float)(Math.Atan2(SecondBasis, FirstBasis));
                        else if (FirstBasis < 0 && SecondBasis >= 0) phi = (float)(Math.Atan2(SecondBasis, FirstBasis) + Math.PI);
                        else if (FirstBasis < 0 && SecondBasis < 0) phi = (float)(Math.Atan2(SecondBasis, FirstBasis) - Math.PI);
                        else if (FirstBasis == 0 && SecondBasis > 0) phi = (float)Math.PI / 2;
                        else if (FirstBasis == 0 && SecondBasis < 0) phi = (float)-Math.PI / 2;
                    }
                    return new PolarPoint()
                    {
                        SecondBasis = r,
                        FirstBasis = phi
                    };
                }
                //Making comparable
                public override bool Equals(object obj)
                {
                    if (obj == null || GetType() != obj.GetType()) return false;
                    var t = obj as DecartPoint;
                    if (this.FirstBasis == t.FirstBasis && this.SecondBasis == t.SecondBasis) return true;
                    return false;
                }
                public override int GetHashCode()
                {
                    return (int)(FirstBasis * SecondBasis * 100);
                }
                ~DecartPoint() { }
            }

            protected PolarPoint Polar { get; set; }
            protected DecartPoint Decart { get; set; }

            public PolarPoint ToPolar() => this.Decart?.ToPolar() ?? this.Polar?.ToDecart().ToPolar();
            public DecartPoint ToDecart() => this.Polar?.ToDecart() ?? this.Decart?.ToPolar().ToDecart();

            public override void SetInPolar(float r, float phi) => Polar = new PolarPoint(r, phi);
            public override void SetInDecart(float x, float y) => Decart = new DecartPoint(x, y);
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
            ~CylinderSystem() { }
        }
        static void Main(string[] args)
        {
            CylinderSystem cylinder = new CylinderSystem();
            PolarSystem polar = new PolarSystem();
            cylinder.SetInDecart(1, 1);
            polar.SetInDecart(1, 1);
            Console.WriteLine("Point in decart: x:{0} y:{1}", polar.ToDecart().FirstBasis, polar.ToDecart().SecondBasis);
            Console.WriteLine("Point in polar: R:{0} Phi:{1}", polar.ToPolar().SecondBasis, polar.ToPolar().FirstBasis);
            var polarval = cylinder.ToPolar();
            var decartval = polarval.ToDecart();
            var polarval2 = decartval.ToPolar();

            Console.WriteLine("Point in decart (converted): x:{0} y:{1}", decartval.FirstBasis, decartval.SecondBasis);
            Console.WriteLine("Point in polar  (converted): R:{0} Phi:{1}", polarval2.SecondBasis, polarval2.FirstBasis);
            if (cylinder.ToPolar().Equals(polarval2)) Console.WriteLine("Convertion forward-back  - success");
            else Console.WriteLine("Convertion not match");

            Console.ReadLine();
        }
    }
}
