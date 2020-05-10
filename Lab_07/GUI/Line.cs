using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace GUI
{
    class Line
    {
        public Line(Pen pen, Point A, Point B)
        {
            this.A = A;
            this.B = B;
            Pen = pen;
        }
        public void Draw(Graphics g)
        {
            g.DrawLine(Pen, A.X, A.Y, B.X, B.Y);
        }

        public Pen Pen { get; set; }
        public Point A { get; set; }
        public Point B { get; set; }

        // возвращает точку для рисования гор или верт линии
        private Point GetPointHorVertLine(Point cur, Point last)
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

        public void SetHorVertLine(Point cur)
        {
            B = GetPointHorVertLine(cur, A);
        }
    }
}
