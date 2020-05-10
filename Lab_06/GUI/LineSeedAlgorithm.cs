using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Windows.Forms;
using System.Drawing;
using System.Diagnostics;

namespace GUI
{
    class LineSeedAlgorithm : IFillingSeed
    {
        public float FillArea(Bitmap canvas, Color fillColor, Color borderColor, Point seed)
        {
            var sw = new Stopwatch();
            sw.Start();

            Stack<Point> stack = new Stack<Point>();
            Point curPoint;
            int x, y, xRight, xLeft;
            stack.Push(seed);
            while (stack.Count > 0)
            {
                curPoint = stack.Pop();
                x = curPoint.X;
                y = curPoint.Y;

                while(!PixelIsBorder(canvas, x, y, borderColor) && x < canvas.Width)
                {
                    canvas.SetPixel(x, y, fillColor);
                    x++;
                }
                xRight = x - 1;

                x = curPoint.X - 1;
                while (!PixelIsBorder(canvas, x, y, borderColor) && x >= 0)
                {
                    canvas.SetPixel(x, y, fillColor);
                    x--;
                }
                xLeft = x + 1;

                if (y > 0)
                    FindSeed(stack, canvas, xLeft, xRight, y - 1, fillColor, borderColor);
                if (y < canvas.Height - 1)
                    FindSeed(stack, canvas, xLeft, xRight, y + 1, fillColor, borderColor);
            }

            sw.Stop();
            Console.WriteLine($"Time: {sw.ElapsedMilliseconds}");
            return sw.ElapsedMilliseconds;
        }

        public void FillAreaWithDelay(Bitmap canvas, Color fillColor, Color borderColor, Point seed, PictureBox pb, int delay)
        {
            Stack<Point> stack = new Stack<Point>();
            Point curPoint;
            int x, y, xRight, xLeft;
            stack.Push(seed);
            
            canvas.SetPixel(seed.X, seed.Y, fillColor);
            pb.Refresh();

            while (stack.Count > 0)
            {
                curPoint = stack.Pop();
                x = curPoint.X;
                y = curPoint.Y;

                canvas.SetPixel(x, y, Color.Black);
                x++;
                while (!PixelIsBorder(canvas, x, y, borderColor) && x < canvas.Width)
                {
                    canvas.SetPixel(x, y, fillColor);
                    x++;
                }
                xRight = x - 1;

                x = curPoint.X - 1;
                while (!PixelIsBorder(canvas, x, y, borderColor) && x >= 0)
                {
                    canvas.SetPixel(x, y, fillColor);
                    x--;
                }
                xLeft = x + 1;

                if (y > 0)
                    FindSeed(stack, canvas, xLeft, xRight, y - 1, fillColor, borderColor);
                if (y < canvas.Height - 1)
                    FindSeed(stack, canvas, xLeft, xRight, y + 1, fillColor, borderColor);
                Thread.Sleep(delay);
                pb.Refresh();
            }
        }

        private bool IsEqualColors(Color colorA, Color colorB)
        {
            return colorA.ToArgb() == colorB.ToArgb();
        }

        // Возвращает true, если пиксель граничный
        private bool PixelIsBorder(Bitmap canvas, int x, int y, Color borderColor)
        {
            if ((x >= 0) && (x < canvas.Width) && (y >= 0) && (y < canvas.Height))
            {
                Color pixelColor = canvas.GetPixel(x, y);
                return IsEqualColors(pixelColor, borderColor);
            }
            return false;
        }

        private void FindSeed(Stack<Point> stack, Bitmap canvas, int xLeft, int xRight, int y, Color fillColor, Color borderColor)
        {
            // поиск слева на право новых затравочных пикселей
            int x = xLeft;
            bool flag = false; // найден не закрашенный пиксель
            while (x <= xRight)
            {
                // Проходим до конца незакрашенного интервала
                while (!PixelIsFillOrBorder(canvas, x, y, fillColor, borderColor) && x <= xRight)
                {
                    flag = true;
                    x++;
                }

                if (flag)
                {
                    // В стек помещаем крайний справа пиксель
                    if (x == xRight && !PixelIsFillOrBorder(canvas, x, y, fillColor, borderColor))
                        stack.Push(new Point(x, y));
                    else
                        stack.Push(new Point(x - 1, y));
                    flag = false;
                }

                // Продолжим проверку, если интервал был прерван
                do
                {
                    x++;
                }
                while (PixelIsFillOrBorder(canvas, x, y, fillColor, borderColor) && x <= xRight);
            }
        }

        // Возвращает true, если пиксель уже закрашен или граничный
        private bool PixelIsFillOrBorder(Bitmap canvas, int x, int y, Color fillColor, Color borderColor)
        {
            if ((x >= 0) && (x < canvas.Width) && (y >= 0) && (y < canvas.Height))
            {
                Color pixelColor = canvas.GetPixel(x, y);
                return IsEqualColors(pixelColor, fillColor) || IsEqualColors(pixelColor, borderColor);
            }
            return false;
        }
    }
}
