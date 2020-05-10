using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows;

namespace GUI
{
    class Cutter : ICutter
    {
        public Cutter()
        {
            points = new List<Point>();
        }

        private List<Point> points;
        public List<Point> Points
        {
            get => points;
            set => SetPoints(value);
        }

        public Vector[] Normals { get; private set; }

        public PointF[] Cut(PointF A, PointF B)
        {
            float tDown = 0, tUp = 1;
            float tTemp;

            Vector D = new Vector(A, B);
            Vector W;

            float DScalar, WScalar;

            for (int i = 0; i < Points.Count; i++)
            {
                W = new Vector(Points[i], A);
                
                DScalar = Vector.Scalar(D, Normals[i]);
                WScalar = Vector.Scalar(W, Normals[i]);

                if (DScalar == 0) // отрезок выродился в точку или отрезок паралелен 
                {
                    if (WScalar < 0)
                        return null;
                    // иначе точка видима относительно текущей границы
                }
                else
                {
                    tTemp = -WScalar / DScalar;
                    if (DScalar > 0) // поиск нижнего предела
                    {
                        if (tTemp > 1)
                            return null;
                        tDown = Math.Max(tDown, tTemp);
                    }
                    else // поиск верхнего предела
                    {
                        if (tTemp < 0)
                            return null;
                        tUp = Math.Min(tUp, tTemp);
                    }
                }

                if (tDown > tUp)
                    return null;
            }


            var newA = new PointF(A.X + D.X * tDown, A.Y + D.Y * tDown);
            var newB = new PointF(A.X + D.X * tUp, A.Y + D.Y * tUp);

            return new PointF[2] { newA, newB };
        }

        // Получить напрвление обхода
        // 1 = против часовой
        // 0 = мн-к невыпуклый
        // -1 = по часовой стрелке
        private int GetRoundDirection()
        {
            if (points.Count < 3)
                return 0;

            Vector A = new Vector(points.Last(), points.First());

            int sign = 0;

            for (int i = 0; i < points.Count - 1; i++)
            {
                var B = new Vector(points[i], points[i + 1]);
                int res = Math.Sign(Vector.Multiplication(A, B));

                if (res != 0)
                {

                    if (sign == 0)
                        sign = res;
                    else if (sign != res)
                        return 0;
                }
                A = B;
            }
            return sign;
        }

        private Vector[] GetNormals(int direction)
        {
            var normals = new Vector[points.Count];

            Vector N;
            float temp;
            for (int i = 0; i < Points.Count - 1; i++)
            {
                N = new Vector(points[i], points[i + 1]);

                // Nx = -Vy; Ny = Vx
                // (N, V) = Nx*Vx + Ny*Vy = -Vy*Vx + Vx*Vy = 0
                temp = N.X;
                N.X = -N.Y;
                N.Y = temp;

                if (direction == -1)
                    N.Negative();
                normals[i] = N;
            }

            N = new Vector(points.Last(), points.First());
            temp = N.X;
            N.X = -N.Y;
            N.Y = temp;

            if (direction == -1)
                N.Negative();
            normals[Points.Count - 1] = N;

            return normals;
        }


        private void SetPoints(List<Point> points)
        {
            this.points = points;
            int direction = GetRoundDirection();
            if (direction == 0)
                throw new NoConvexCutterException();

            Normals = GetNormals(direction);
        }
    }
}
