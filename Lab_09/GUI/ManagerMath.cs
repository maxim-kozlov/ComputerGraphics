using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace GUI
{
    static class ManagerMath
    {
        // возвращает точку для рисования гор или верт линии
        public static Point GetPointHorVertLine(Point cur, Point last)
        {
            Point point = new Point(Math.Abs(cur.X - last.X), Math.Abs(cur.Y - last.Y));

            if (point.X > point.Y)
            {
                point.X = cur.X;
                point.Y = last.Y;
            }

            else
            {
                point.X = last.X;
                point.Y = cur.Y;
            }

            return point;
        }

        // Получить напрвление обхода
        // 1 = против часовой
        // 0 = мн-к невыпуклый
        // -1 = по часовой стрелке
        public static int GetRoundDirection(List<Point> points)
        {
            if (points.Count < 3)
                return 0;

            Vector A = new Vector(points.Last(), points.First());

            int sign = 0;
            for (int i = 0; i < points.Count; i++)
            {
                var B = new Vector(points[i], points[(i + 1) % points.Count]);
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

        public static Vector[] GetNormals(List<Point> points, int direction)
        {
            var normals = new Vector[points.Count];

            Vector N;
            float temp;
            for (int i = 0; i < points.Count - 1; i++)
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
            normals[points.Count - 1] = N;
            return normals;
        }
    }
}
