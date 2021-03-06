﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GUI
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
            ManagerDraw = new ManagerDraw(pbCanvas, pbLineColor, pbCutterColor, pbCuttedLine);
            Cutter = new Cutter();

            ManagerDraw.Cutter.Points.Add(new Point(200, 400));
            ManagerDraw.Cutter.Points.Add(new Point(200, 100));
            ManagerDraw.Cutter.Points.Add(new Point(400, 400));
            ManagerDraw.DrawCutter();

            /*var l = new Line();
            l.Pen = ManagerDraw.PenLine;
            l.A = new Point(500, 400);
            l.B = l.A;//new Point(300, 100);
            ManagerDraw.Lines.Add(l);

            l = new Line();
            l.Pen = ManagerDraw.PenLine;
            l.A = new Point(300, 400);
            l.B = l.A;//new Point(100, 100);
            ManagerDraw.Lines.Add(l);

            ManagerDraw.DrawLines();*/
        }

        private ManagerDraw ManagerDraw { get; }
        private ICutter Cutter { get; }

        private void btnCut_Click(object sender, EventArgs e)
        {
            ManagerDraw.DrawCutter();
            Cut();
            pbCanvas.Refresh();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            ManagerDraw.Clear();
        }

        private void pbCanvas_MouseMove(object sender, MouseEventArgs e)
        {
            Point mousePos = pbCanvas.PointToClient(MousePosition);
            if (ManagerDraw.IsInputCutter)
            {
                ManagerDraw.DrawMovingCutter(mousePos, ModifierKeys == Keys.Shift);
            }
            else if (ManagerDraw.IsInputLine)
            {
                ManagerDraw.DrawMovingLine(mousePos, ModifierKeys == Keys.Shift);
            }
        }

        private void pbCanvas_Click(object sender, EventArgs e)
        {
            Point mousePos = pbCanvas.PointToClient(MousePosition);

            if (checkBoxLine.Checked)
            {
                if (((MouseEventArgs)e).Button == MouseButtons.Left)
                {
                    ManagerDraw.InputLine(mousePos, ModifierKeys == Keys.Shift);
                }
            }
            else
            {
                if (((MouseEventArgs)e).Button == MouseButtons.Left)
                {
                    ManagerDraw.InputCutter(mousePos, ModifierKeys == Keys.Shift);
                }
                else if (((MouseEventArgs)e).Button == MouseButtons.Right)
                {
                    ManagerDraw.CloseCutter();
                }
            }
        }

        private void checkBoxLine_CheckedChanged(object sender, EventArgs e)
        {
            checkBoxCutter.Checked = !checkBoxLine.Checked;

        }

        private void checkBoxCutter_CheckedChanged(object sender, EventArgs e)
        {
            checkBoxLine.Checked = !checkBoxCutter.Checked;
        }


        private void Cut()
        {
            try
            {
                Cutter.Points = new List<Point>(ManagerDraw.Cutter);

                foreach (var line in ManagerDraw.Lines)
                {
                    var points = Cutter.Cut(line.A, line.B);
                    if (points != null)
                    {
                        ManagerDraw.DrawCuttedLine(points[0], points[1]);
                    }
                }
            }
            catch (NoConvexCutterException e)
            {
                MessageBox.Show(e.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
