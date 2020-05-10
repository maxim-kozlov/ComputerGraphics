using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace GUI
{
    abstract class Cutter
    {
        public Cutter(Point A, Point B)
        {
            this.A = A;
            this.B = B;
        }
        public Cutter() { }

        // левый нижний
        private Point _A;
        public Point A { get => _A; private set => _A = value; }

        // правый верхний
        private Point _B;
        public Point B { get => _B; private set => _B = value; }

        public void SetAB(Point a, Point b)
        {
            if (a.X < b.X)
            {
                _A.X = a.X;
                _B.X = b.X;
            }
            else
            {
                _A.X = b.X;
                _B.X = a.X;
            }
            if (a.Y < b.Y)
            {
                _A.Y = a.Y;
                _B.Y = b.Y;
            }
            else
            {
                _A.Y = b.Y;
                _B.Y = a.Y;
            }
        }

        public abstract PointF[] Cut(PointF A, PointF B);


        // Получение кода точки
        protected int GetCode(PointF p)
        {
            int sum = 0b0000;

            if (p.X < A.X) // left
                sum |= 0b1000;
            if (p.X > B.X) // right
                sum |= 0b0100;
            if (p.Y < A.Y) // down
                sum |= 0b0010;
            if (p.Y > B.Y) // up
                sum |= 0b0001;

            return sum;
        }

        // отрезок полносью видимый
        protected bool IsLineVisible(int t0, int t1)
        {
            return (t0 | t1) == 0;
        }

        // отрезок тривиально невидим
        protected bool IsTrivialInvisible(int t0, int t1)
        {
            return (t0 & t1) != 0;
        }

        protected void Swap<T>(ref T p1, ref T p2)
        {
            T temp = p1;
            p1 = p2;
            p2 = temp;
        }

        // массив
        protected int this[int index]
        {
            get
            {
                switch(index)
                {
                    case 0:
                        return A.X; // left
                    case 1:
                        return B.X; // right
                    case 2:
                        return A.Y; // down
                    case 3:
                        return B.Y; // up
                    default:
                        throw new IndexOutOfRangeException();
                }
            }
        }
    }
}
