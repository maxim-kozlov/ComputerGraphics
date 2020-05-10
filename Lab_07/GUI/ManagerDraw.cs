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

            _penLine = new UserPen(Color.Black, pbLineColor);
            _penCutter = new UserPen(Color.Red, pbCutterColor);
            _penCuttedLine = new UserPen(Color.Green, pbCuttedLineColor);

            PbCanvas.MouseClick += PbCanvas_MouseClick;
            IsInputCutter = false;
            IsInputLine = false;

            Lines = new List<Line>();
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
            if (!IsInputLine)
            {
                InputingLine = new Line(PenLine, cur, cur);
                IsInputLine = true;
            }
            else
            {
                if (isVertHor)
                    InputingLine.SetHorVertLine(cur);
                else
                    InputingLine.B = cur;

                InputingLine.Draw(g);
                Lines.Add(InputingLine);
                IsInputLine = false;
            }
        }


        public void DrawMovingCutter(Point cur)
        {
            PbCanvas.Refresh();
            Cutter.B = cur;
            Cutter.Draw(gMove);
        }

        public void InputCutter(Point cur)
        {
            if (!IsInputCutter)
            {
                ClearCanvas();
                DrawLines();
                Cutter = new Rectangle(PenCutter, cur, cur);
                IsInputCutter = true;
            }
            else
            {
                Cutter.B = cur;
                Cutter.Draw(g);
                IsInputCutter = false;
            }
        }

        private void PbCanvas_MouseClick(object sender, MouseEventArgs e)
        {
            if (IsInputCutter && e.Button != MouseButtons.Right)
            {
                IsInputCutter = false;
                DrawCutter();
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
        public Rectangle Cutter { get; private set; }

        private UserPen _penLine;
        public Pen PenLine { get => _penLine.Pen; set => _penLine.Pen = value; }

        private UserPen _penCutter;
        public Pen PenCutter { get => _penCutter.Pen; set => _penCutter.Pen = value; }

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

        public void Clear()
        {
            IsInputCutter = false;
            IsInputLine = false;
            InputingLine = null;
            Cutter = null;
            Lines.Clear();
            ClearCanvas();
        }
    }
}
