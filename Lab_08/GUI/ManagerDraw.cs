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
            IsInputLine = false;

            Lines = new List<Line>();
            Cutter = new Polygon();
            InputingLine = new Line();

            PenLine = new Pen(Color.Black);
            PenCutter = new Pen(Color.Red);
            PenCuttedLine = new Pen(Color.Green);
        }


        public void DrawMovingLine(Point cur, bool isVertHor)
        {
            PbCanvas.Refresh();

            if (isVertHor)
                InputingLine.SetHorVertLine(cur);
            else
                InputingLine.B = cur;

            InputingLine.Draw(gMove);
        }

        public void InputLine(Point cur, bool isVertHor)
        {
            IsInputCutter = false;
            if (!IsInputLine)
            {
                InputingLine.A = cur;
                InputingLine.B = cur;
                IsInputLine = true;
            }
            else
            {
                if (isVertHor)
                    InputingLine.SetHorVertLine(cur);
                else
                    InputingLine.B = cur;

                InputingLine.Draw(g);
                Lines.Add(new Line() { Pen = InputingLine.Pen, A = InputingLine.A, B = InputingLine.B });
                IsInputLine = false;
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
            IsInputLine = false;

            if (isVertHor)
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

        public List<Line> Lines { get; private set; }

        public bool IsInputLine { get; private set; }
        private Line InputingLine { get; set; }

        public bool IsInputCutter { get; private set; }
        public Polygon Cutter { get; private set; }

        private UserPen _penLine;
        public Pen PenLine { get => _penLine.Pen; set { _penLine.Pen = value; InputingLine.Pen = value; } }

        private UserPen _penCutter;
        public Pen PenCutter { get => _penCutter.Pen; set { _penCutter.Pen = value; Cutter.Pen = value; } }

        private UserPen _penCuttedLine;
        public Pen PenCuttedLine { get => _penCuttedLine.Pen; set => _penCuttedLine.Pen = value; }


        public void ClearCanvas()
        {
            g.Clear(Color.White);
            PbCanvas.Refresh();
        }

        public void DrawLines()
        {
            foreach (var line in Lines)
                line.Draw(g);
        }

        public void DrawCuttedLine(PointF A, PointF B)
        {
            g.DrawLine(PenCuttedLine, A, B);
        }

        public void DrawCutter()
        {
            Cutter?.Draw(g);
        }

        private void ClearCutter()
        {
            Cutter.Points.Clear();
            ClearCanvas();
            DrawLines();
            PbCanvas.Refresh();
        }

        public void Clear()
        {
            IsInputCutter = false;
            IsInputLine = false;
            // InputingLine = null;
            Cutter.Points.Clear();

            Lines.Clear();
            ClearCanvas();
        }
    }
}
