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
    class RibFill : IFilling
    {
        public float FillArea(Bitmap canvas, Color fillColor, Color backgroundColor, List<List<Point>> polygons)
        {
            float time = 0;
            var sw = new Stopwatch();
            sw.Start();
            int maxX = GetMaxX(polygons);
            foreach (var polygon in polygons)
            {
                for (int i = 0; i < polygon.Count - 1; i++)
                    FillEdge(canvas, polygon[i], polygon[i + 1], maxX, fillColor, backgroundColor);
                FillEdge(canvas, polygon[polygon.Count - 1], polygon[0], maxX, fillColor, backgroundColor);
            }
            sw.Stop();
            Console.WriteLine($"Time: {sw.ElapsedMilliseconds}");
            return time;
        }

        public void FillAreaWithDelay(Bitmap canvas,
            Color fillColor, Color backgroundColor,
            List<List<Point>> polygons,
            PictureBox pb, int delay)
        {
            int maxX = GetMaxX(polygons);
            foreach (var polygon in polygons)
            {
                for (int i = 0; i < polygon.Count - 1; i++)
                {
                    FillEdgeWithDelay(canvas, polygon[i], polygon[i + 1], maxX, fillColor, backgroundColor, pb, delay);
                    pb.Refresh();
                    Console.ReadLine();
                    // Thread.Sleep(1000);
                }
                FillEdgeWithDelay(canvas, polygon[polygon.Count - 1], polygon[0], maxX, fillColor, backgroundColor, pb, delay);
                pb.Refresh();
                Console.ReadLine();
                // Thread.Sleep(1000);
            }
        }
            
        private void FillEdge(Bitmap canvas, Point A, Point B, int xMax,
            Color fillColor, Color backgroundColor)
        {
            if (A.Y == B.Y)
                return;

            if (A.Y > B.Y)
            {
                Point temp = A;
                A = B;
                B = temp;
            }

            float dx = (B.X - A.X) / (float)(B.Y - A.Y);
            float xStart = A.X;
            for (int y = A.Y; y < B.Y; y++)
            {
                // определяем пересечение  
                for (int x = (int)Math.Round(xStart); x < xMax; x++)
                    InvertColor(canvas, x, y, fillColor, backgroundColor);
                xStart += dx;
            }
        }

        private bool isExtremumY_B(Point A, Point B, Point C)
        {
            return A.Y < B.Y && C.Y < B.Y || A.Y > B.Y && C.Y > B.Y;
        }

        private void FillEdgeWithDelay(Bitmap canvas, 
            Point A, Point B, int xMax,
            Color fillColor, Color backgroundColor,
            PictureBox pb, int delay)
        {
            if (A.Y == B.Y)
                return;
            
            if (A.Y > B.Y)
            {
                Point temp = A;
                A = B;
                B = temp;
            }

            float dx = (B.X - A.X) / (float)(B.Y - A.Y);

            float xStart = A.X;
            for (int y = A.Y; y < B.Y; y++)
            {
                // определяем пересечение  
                for (int x = (int)Math.Round(xStart); x < xMax; x++)
                    InvertColor(canvas, x, y, fillColor, backgroundColor);
                xStart += dx;

                pb.Refresh();
                Thread.Sleep(delay);
            }
        }

        private void InvertColor(Bitmap canvas, int x, int y, Color fillColor, Color backgroundColor)
        {
            Color color = canvas.GetPixel(x, y);
            if (color.ToArgb() == fillColor.ToArgb())
                canvas.SetPixel(x, y, backgroundColor);
            else
                canvas.SetPixel(x, y, fillColor);
        }

        private int GetMaxX(List<List<Point>> polygons)
        {
            return polygons.Max(s => s.Max(t => t.X));
        }
    }
}
