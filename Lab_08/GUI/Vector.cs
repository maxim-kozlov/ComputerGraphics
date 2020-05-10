using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;


namespace GUI
{
    class Vector
    {
        public Vector(float x = 0, float y = 0)
        {
            X = x;
            Y = y;
        }

        // A->B
        public Vector(PointF A, PointF B)
        {
            X = B.X - A.X;
            Y = B.Y - A.Y;
        }

        public float X { get; set; }
        public float Y { get; set; }

        public void Negative()
        {
            X = -X;
            Y = -Y;
        }

        public void Multiplication(float value)
        {
            X *= value;
            Y *= value;
        }

        public static float Multiplication(Vector A, Vector B)
        {
            return A.X * B.Y - A.Y * B.X;
        }

        public static float Scalar(Vector A, Vector B)
        {
            return A.X * B.X + A.Y * B.Y;
        }
    }
}
