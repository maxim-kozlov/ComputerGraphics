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
        public Line()
        {

        }

        public void Draw(Graphics g)
        {
            g.DrawLine(Pen, A.X, A.Y, B.X, B.Y);
        }

        public Pen Pen { get; set; }
        public Point A { get; set; }
        public Point B { get; set; }

        public void SetHorVertLine(Point cur)
        {
            B = ManagerMath.GetPointHorVertLine(cur, A);
        }
    }
}
