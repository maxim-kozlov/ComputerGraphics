using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;

namespace GUI
{
    class ManagerDraw
    {
        public ManagerDraw(PictureBox pictureBox, PictureBox pictureBoxFillColor)
        {
            Canvas = new Bitmap(pictureBox.Width, pictureBox.Height);
            g = Graphics.FromImage(Canvas);
            gMove = pictureBox.CreateGraphics();
            pictureBox.Image = Canvas;

            this.pictureBox = pictureBox;
            this.pictureBoxFillColor = pictureBoxFillColor;

            PenFill = new Pen(Color.Red, 1);
            PenEdges = new Pen(Color.Black, 1);

            Polygons = new List<List<Point>>();
            InputingPolygon = new List<Point>();
        }

        public Bitmap Canvas { get; set; }

        private PictureBox pictureBox { get;  }
        private PictureBox pictureBoxFillColor { get; }

        private Graphics g { get; }
        private Graphics gMove { get; }


        public Pen PenEdges { get; set; }
        
        private Pen _penFill;
        public Pen PenFill
        {
            get => _penFill;
            set
            {
                pictureBoxFillColor.BackColor = value.Color;
                _penFill = value;
            }
        }

        // рисуемые мн-ики
        public List<List<Point>> Polygons { get; private set; }
        // текущий мн-к
        public List<Point> InputingPolygon { get; private set; }

        public void ClearPolygons()
        {
            Polygons.Clear();
            InputingPolygon.Clear();
            ClearCanvas();
        }

        public void ClearCanvas()
        {
            g.Clear(Color.White);
            pictureBox.Refresh();
        }

        public void AddHorVertLinePolygon(Point point)
        {
            AddPointPolygon(GetPointHorVertLine(point));
        }

        public void AddPointPolygon(Point point)
        {
            if (InputingPolygon.Count > 0)
                DrawEdge(g, InputingPolygon.Last(), point);

            InputingPolygon.Add(point);
        }

        public void ClosePolygon()
        {
            if (InputingPolygon.Count > 1)
            {
                DrawEdge(g, InputingPolygon.Last(), InputingPolygon.First());
                Polygons.Add(InputingPolygon);
            }
            InputingPolygon = new List<Point>();
        }

        public Point GetPointHorVertLine(Point cur)
        {
            if (InputingPolygon.Count > 0)
                cur = GetPointHorVertLine(cur, InputingPolygon.Last());
            return cur;
        }

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


        // рисует линию ребра
        private void DrawEdge(Graphics graphics, Point a, Point b)
        {
            graphics.DrawLine(PenEdges, a, b);
            pictureBox.Refresh();
        }

        public void DrawPolygons()
        {
            foreach (var polygon in Polygons)
            {
                if (polygon.Count > 1)
                    g.DrawPolygon(PenEdges, polygon.ToArray());
            }
            pictureBox.Refresh();
        }

        public void DrawMovingEdge(Point newPoint)
        { 
            if (InputingPolygon.Count > 0)
            {
                pictureBox.Refresh();
                gMove.DrawLine(PenEdges, InputingPolygon.Last(), newPoint);
            }
        }
    }
}
