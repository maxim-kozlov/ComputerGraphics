using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace GUI
{
    interface ICutter
    {
        PointF[] Cut(PointF A, PointF B);
        List<Point> Points { get; set; }
    }
}
