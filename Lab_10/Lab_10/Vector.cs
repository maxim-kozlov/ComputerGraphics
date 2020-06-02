using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_10
{
    struct Point3f
    {
        public double X { get; set; }
        public double Y { get; set; }
        public double Z { get; set; }

        public Point3f(double x = 0, double y = 0, double z = 0)
        {
            X = x;
            Y = y;
            Z = z;
        }

        public Point3f RotateX(double dx)
        {
            double y = Y;
            Y = Math.Cos(dx) * Y - Math.Sin(dx) * Z;
            Z = Math.Cos(dx) * Z + Math.Sin(dx) * y;
            return this;
        }

        public Point3f RotateY(double dy)
        {
            double x = X;
            X = Math.Cos(dy) * X - Math.Sin(dy) * Z;
            Z = Math.Cos(dy) * Z + Math.Sin(dy) * x;
            return this;
        }

        public Point3f RotateZ(double dz)
        {
            double x = X;
            X = Math.Cos(dz) * X - Math.Sin(dz) * Y;
            Y = Math.Cos(dz) * Y + Math.Sin(dz) * x;
            return this;
        }

        public Point3f Move(double dx, double dy, double dz)
        {
            X += dx;
            Y += dy;
            Z += dz;
            return this;
        }

        public Point3f Dot(double value)
        {
            X *= value;
            Y *= value;
            Z *= value;
            return this;
        }

        public Point3f Clone()
        {
            Point3f x = new Point3f();
            x.X = X;
            x.Y = Y;
            x.Z = Z;
            return x;
        }
    }


    struct Point2i
    {
        public Point2i(int x, int y)
        {
            X = x;
            Y = y;
        }

        public Point2i(double x, double y)
        {
            X = (int)Math.Round(x);
            Y = (int)Math.Round(y);
        }
        public int X { get; set; }
        public int Y { get; set; }
    }
}
