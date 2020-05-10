using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace GUI
{
    class CutterCohenSutherland : Cutter
    {
        public CutterCohenSutherland(Point A, Point B) : base(A, B){ }
        public CutterCohenSutherland() { }

        public override PointF[] Cut(PointF P1, PointF P2)
        {
            float m = 0;
            float Im = 0;
            float dx = P2.X - P1.X;
            float dy = P2.Y - P1.Y;
            bool isVert = dx == 0;
            bool isHor = dy == 0;
            if (!isVert)
                m = dy / dx;

            if (!isHor)
                Im = dx / dy;

            int mask = 0b1000;
            for (int i = 0; i < 4; i++)
            {
                int t0 = GetCode(P1);
                int t1 = GetCode(P2);

                Console.WriteLine($"{Convert.ToString(t0, 2)} {Convert.ToString(t1, 2)}");

                if (IsLineVisible(t0, t1))
                    return new PointF[] { P1, P2};
                if (IsTrivialInvisible(t0, t1))
                    return null;

                bool t0i = (t0 & mask) != 0;
                bool t1i = (t1 & mask) != 0;
                Console.WriteLine($"{t0i} {t1i} {i}");
                if (t0i != t1i) 
                {
                    if (!t0i) // Если точка A по видимую сторону
                        Swap(ref P1, ref P2);

                    if (!isVert && i < 2)
                    {
                        P1.Y = m * (this[i] - P1.X) + P1.Y;
                        P1.X = this[i];
                    }
                    else
                    {
                        if (!isHor)
                        {
                            P1.X = Im * (this[i] - P1.Y) + P1.X;
                            P1.Y = this[i];
                        }
                    }
                }
                mask /= 2;
            }
            return new PointF[] { P1, P2};
        }
    }
}
