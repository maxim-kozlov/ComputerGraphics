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
        public ManagerDraw(PictureBox pbCanvas, PictureBox pbLineColor, PictureBox pbCutterColor, PictureBox pbCuttedLineColor)
        {
            Canvas = new Bitmap(pbCanvas.Width, pbCanvas.Height);
            g = Graphics.FromImage(Canvas);
            gMove = pbCanvas.CreateGraphics();
            pbCanvas.Image = Canvas;
            PbCanvas = pbCanvas;

            _penLine = new UserPen(pbLineColor);
            _penCutter = new UserPen(pbCutterColor);
            _penCuttedLine = new UserPen(pbCuttedLineColor);

            IsInputCutter = false;
            IsInputPolygon = false;

            Polygon = new Polygon();
            Cutter = new Polygon();

            PenLine = new Pen(Color.Black);
            PenCutter = new Pen(Color.Red);
            PenCuttedLine = new Pen(Color.Green);
        }


        public void DrawMovingPolygon(Point cur, bool isVertHor)
        {
            PbCanvas.Refresh();

            if (isVertHor)
                cur = ManagerMath.GetPointHorVertLine(cur, Polygon.Points.Last());

            gMove.DrawLine(Polygon.Pen, cur, Polygon.Points.Last());
        }

        public void InputPolygon(Point cur, bool isVertHor)
        {
            IsInputCutter = false;

            if (isVertHor && Polygon.Points.Count() > 0)
                cur = ManagerMath.GetPointHorVertLine(cur, Polygon.Points.Last());

            if (IsInputPolygon)
                g.DrawLine(Polygon.Pen, cur, Polygon.Points.Last());

            else
                ClearPolygon();

            Polygon.Points.Add(cur);
            IsInputPolygon = true;
        }

        public void ClosePolygon()
        {
            if (IsInputPolygon)
            {
                IsInputPolygon = false;
                if (Polygon.Points.Count > 2)
                {
                    g.DrawLine(Polygon.Pen, Polygon.Points.First(), Polygon.Points.Last());
                }
                else
                    ClearPolygon();
                PbCanvas.Refresh();
            }
        }


        public void DrawMovingCutter(Point cur, bool isVertHor)
        {
            PbCanvas.Refresh();

            if (isVertHor)
                cur = ManagerMath.GetPointHorVertLine(cur, Cutter.Points.Last());

            gMove.DrawLine(Cutter.Pen, cur, Cutter.Points.Last());
        }

        public void InputCutter(Point cur, bool isVertHor)
        {
            IsInputPolygon = false;

            if (isVertHor && Cutter.Points.Count() > 0)
                cur = ManagerMath.GetPointHorVertLine(cur, Cutter.Points.Last());

            if (IsInputCutter)
                g.DrawLine(Cutter.Pen, cur, Cutter.Points.Last());

            else
                ClearCutter();

            Cutter.Points.Add(cur);
            IsInputCutter = true;
        }

        public void CloseCutter()
        {
            if (IsInputCutter)
            {
                IsInputCutter = false;
                if (Cutter.Points.Count > 2)
                {
                    g.DrawLine(Cutter.Pen, Cutter.Points.First(), Cutter.Points.Last());
                }
                else
                    ClearCutter();
                PbCanvas.Refresh();
            }
        }

        public Bitmap Canvas { get; set; }
        private PictureBox PbCanvas { get; }

        private Graphics g { get; }
        private Graphics gMove { get; }

        public bool IsInputPolygon { get; private set; }
        public Polygon Polygon { get; private set; }


        public bool IsInputCutter { get; private set; }
        public Polygon Cutter { get; private set; }

        private UserPen _penLine;
        public Pen PenLine { get => _penLine.Pen; set { _penLine.Pen = value; Polygon.Pen = value; } }

        private UserPen _penCutter;
        public Pen PenCutter { get => _penCutter.Pen; set { _penCutter.Pen = value; Cutter.Pen = value; } }

        private UserPen _penCuttedLine;
        public Pen PenCuttedLine { get => _penCuttedLine.Pen; set => _penCuttedLine.Pen = value; }


        public void ClearCanvas()
        {
            g.Clear(Color.White);
            PbCanvas.Refresh();
        }

        public void DrawCuttedLine(PointF A, PointF B)
        {
            g.DrawLine(PenCuttedLine, A, B);
        }

        public void DrawCutter()
        {
            Cutter?.Draw(g);
        }
        
        public void DrawPolygon()
        {
            Polygon?.Draw(g);
        }

        private void ClearCutter()
        {
            Cutter.Points.Clear();
            ClearCanvas();
            DrawPolygon();
            PbCanvas.Refresh();
        }

        private void ClearPolygon()
        {
            Polygon.Points.Clear();
            ClearCanvas();
            DrawCutter();
            PbCanvas.Refresh();
        }

        public void Clear()
        {
            IsInputCutter = false;
            IsInputPolygon = false;

            Polygon.Points.Clear();
            Cutter.Points.Clear();

            ClearCanvas();
        }
    }
}
