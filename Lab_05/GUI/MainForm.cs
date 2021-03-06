﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace GUI
{
    public partial class MainForm : Form
    {
        // рисуемый многоугольник
        private List<List<Point>> Polygons { get; set; }

        private List<Point> InputingPolygon { get; set; }

        Bitmap saved_picture;
        private Graphics g;
        private Graphics g_move;

        private Pen PenEdges { get; set; } // edges

        private Pen _penFill;
        private Pen PenFill
        {
            get => _penFill;
            set
            {
                pictureBoxFillColor.BackColor = value.Color;
                _penFill = value;
            }
        }

        private IFilling Filling { get; set; }

        public MainForm()
        {
            InitializeComponent();

            Polygons = new List<List<Point>>();
            InputingPolygon = new List<Point>();

            saved_picture = new Bitmap(pictureBox.Width, pictureBox.Height);
            g = Graphics.FromImage(saved_picture);
            // g.SmoothingMode = SmoothingMode.AntiAlias;

            g_move = pictureBox.CreateGraphics();
            // g_move.SmoothingMode = SmoothingMode.AntiAlias;

            pictureBox.Image = saved_picture;
            
            PenEdges = new Pen(Color.FromArgb(1, 1, 1), 1);
            PenFill = new Pen(Color.Black, 1);

            Filling = new RibFillWithSeptum();
        }

        private void btnFill_Click(object sender, EventArgs e)
        {
            g.Clear(Color.White);
            // DrawAllPolygons(g);
            pictureBox.Refresh();

            int delay = (int)numericUpDownDelay.Value;
            if (delay != 0)
            {
                Filling.FillAreaWithDelay(saved_picture, PenFill.Color, Color.White, Polygons, pictureBox, delay);
            }
            else
            {
                Filling.FillArea(saved_picture, PenFill.Color, Color.White, Polygons);
            }
            //Thread.Sleep(1000);
            // DrawAllPolygons(g);
            pictureBox.Refresh();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            Polygons.Clear();
            InputingPolygon.Clear();
            g.Clear(Color.White);
            pictureBox.Refresh();
        }

        private void btnChangeFillColor_Click(object sender, EventArgs e)
        {
            if (colorDialogFill.ShowDialog() == DialogResult.OK)
            {
                PenFill = new Pen(colorDialogFill.Color, 1);
            }
        }

        // Нажатие на холст
        private void pictureBox_Click(object sender, EventArgs e)
        {
            Point mousePos = pictureBox.PointToClient(MousePosition);

            if (((MouseEventArgs)e).Button == MouseButtons.Left)
            {
                // если зажат shift
                if (ModifierKeys == Keys.Shift && InputingPolygon.Count > 0)
                {
                    InputingPolygon.Add(GetPointWithShift(mousePos,
                        InputingPolygon[InputingPolygon.Count - 1]));
                }
                else
                {
                    InputingPolygon.Add(mousePos);
                }

                DrawStaticEdge(last: false);
            }

            if (((MouseEventArgs)e).Button == MouseButtons.Right && InputingPolygon.Count > 1)
            {
                DrawStaticEdge(last: true);
                Polygons.Add(InputingPolygon);
                InputingPolygon = new List<Point>();
            }
        }

        // перемещение мыши
        private void pictureBox_MouseMove(object sender, MouseEventArgs e)
        {
            pictureBox.Refresh();
            DrawMovingEdge();
        }

        // Рисует все сохраненные точки
        private void DrawAllPolygons(Graphics graphics)
        {
            foreach (var polygon in Polygons)
            {
                if (polygon.Count > 1)
                    graphics.DrawPolygon(PenEdges, polygon.ToArray());
            }
        }

        // возвращает точку при зажатом shift
        private Point GetPointWithShift(Point cur, Point last)
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
        }

        // Рисует линии к мыши из последней точки (без сохранения)  
        private void DrawMovingEdge()
        {
            if (InputingPolygon.Count > 0)
            {
                Point a = InputingPolygon[InputingPolygon.Count - 1];
                Point b = pictureBox.PointToClient(MousePosition);

                if (ModifierKeys == Keys.Shift)
                    b = GetPointWithShift(b, a);

                DrawEdge(g_move, a, b);
            }
        }

        // Рисует линии к мыши из последней точки (с сохранением)  
        private void DrawStaticEdge(bool last)
        {
            if (InputingPolygon.Count > 1)
            {
                Point a = InputingPolygon[InputingPolygon.Count - 1];
                Point b;
                if (last)
                    b = InputingPolygon[0];
                else
                    b = InputingPolygon[InputingPolygon.Count - 2];

                DrawEdge(g, a, b);
            }
        }
    }
}
