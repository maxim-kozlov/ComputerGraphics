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
    }
}
