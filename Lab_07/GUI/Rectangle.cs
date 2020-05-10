using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace GUI
{
    class Rectangle
    {
        public Rectangle(Pen pen, Point A, Point B)
        {
            this.A = A;
            this.B = B;
            Pen = pen;
        }

        public void Draw(Graphics g)
        {
            g.DrawLine(Pen, A.X, A.Y, A.X, B.Y);
            g.DrawLine(Pen, A.X, B.Y, B.X, B.Y);
            g.DrawLine(Pen, B.X, B.Y, B.X, A.Y);
            g.DrawLine(Pen, B.X, A.Y, A.X, A.Y);
        }

        public Pen Pen { get; set; }
        public Point A { get; set; }
        public Point B { get; set; }
    }
}
