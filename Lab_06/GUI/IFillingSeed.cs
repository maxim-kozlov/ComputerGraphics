using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;

namespace GUI
{
    interface IFillingSeed
    {
        float FillArea(Bitmap canvas, Color fillColor, Color borderColor, Point seed);
        void FillAreaWithDelay(Bitmap canvas, Color fillColor, Color borderColor, Point seed, PictureBox pb, int delay);
    }
}
