using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Collections;

namespace GUI
{
    class Polygon : IEnumerable<Point>
    {
        public Polygon()
        {
            Points = new List<Point>();
        }

        public List<Point> Points { get; private set; }
        public Pen Pen { get; set; }

        public void Draw(Graphics g)
        {
            g.DrawPolygon(Pen, Points.ToArray());
        }

        public IEnumerator<Point> GetEnumerator()
        {
            return Points.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return Points.GetEnumerator();
        }
    }
}
