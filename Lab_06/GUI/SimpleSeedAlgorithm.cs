using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
using System.Diagnostics;

namespace GUI
{
    class SimpleSeedAlgorithm : IFillingSeed
    {
        public float FillArea(Bitmap canvas, Color fillColor, Color borderColor, Point seed)
        {
            var sw = new Stopwatch();
            sw.Start();

            Stack<Point> stack = new Stack<Point>();
            Point curPoint;
            Color curColor;

            stack.Push(seed);
            while (stack.Count > 0)
            {
                curPoint = stack.Pop();
                curColor = canvas.GetPixel(curPoint.X, curPoint.Y);
                if (curColor != fillColor && curColor != borderColor)
                    canvas.SetPixel(curPoint.X, curPoint.Y, fillColor);

                if (!PixelIsFillOrBorder(canvas, curPoint.X + 1, curPoint.Y, curColor, fillColor, borderColor))
                    stack.Push(new Point(curPoint.X + 1, curPoint.Y));
                if (!PixelIsFillOrBorder(canvas, curPoint.X, curPoint.Y + 1, curColor, fillColor, borderColor))
                    stack.Push(new Point(curPoint.X, curPoint.Y + 1));
                if (!PixelIsFillOrBorder(canvas, curPoint.X - 1, curPoint.Y, curColor, fillColor, borderColor))
                    stack.Push(new Point(curPoint.X - 1, curPoint.Y));
                if (!PixelIsFillOrBorder(canvas, curPoint.X, curPoint.Y - 1, curColor, fillColor, borderColor))
                    stack.Push(new Point(curPoint.X, curPoint.Y - 1));
            }

            sw.Stop();
            Console.WriteLine($"Time: {sw.ElapsedMilliseconds}");
            return sw.ElapsedMilliseconds;
        }

        public void FillAreaWithDelay(Bitmap canvas, Color fillColor, Color borderColor, Point seed, PictureBox pb, int delay)
        {
            Stack<Point> stack = new Stack<Point>();
            Point curPoint;
            Color curColor;

            stack.Push(seed);
            while (stack.Count > 0)
            {
                curPoint = stack.Pop();
                curColor = canvas.GetPixel(curPoint.X, curPoint.Y);
                if (curColor != fillColor && curColor != borderColor)
                    canvas.SetPixel(curPoint.X, curPoint.Y, fillColor);

                if (!PixelIsFillOrBorder(canvas, curPoint.X + 1, curPoint.Y, curColor, fillColor, borderColor))
                    stack.Push(new Point(curPoint.X + 1, curPoint.Y));
                if (!PixelIsFillOrBorder(canvas, curPoint.X, curPoint.Y + 1, curColor, fillColor, borderColor))
                    stack.Push(new Point(curPoint.X, curPoint.Y + 1));
                if (!PixelIsFillOrBorder(canvas, curPoint.X - 1, curPoint.Y, curColor, fillColor, borderColor))
                    stack.Push(new Point(curPoint.X - 1, curPoint.Y));
                if (!PixelIsFillOrBorder(canvas, curPoint.X, curPoint.Y - 1, curColor, fillColor, borderColor))
                    stack.Push(new Point(curPoint.X, curPoint.Y - 1));
                pb.Refresh();
            }
        }


        // Возвращает true, если пиксель уже закрашен или граничный
        private bool PixelIsFillOrBorder(Bitmap canvas, int x, int y, Color curColor, Color fillColor, Color borderColor)
        {
            if ((x >= 0) && (x < canvas.Width) && (y >= 0) && (y < canvas.Height))
            {
                Color pixelColor = canvas.GetPixel(x, y);
                return pixelColor.ToArgb() == fillColor.ToArgb() || pixelColor.ToArgb() == borderColor.ToArgb();
            }
            return true;
        }
    }
}
