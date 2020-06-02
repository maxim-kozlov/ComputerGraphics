using System;
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

            ManagerDraw.Cutter.Points.Add(new Point(100, 200));
            ManagerDraw.Cutter.Points.Add(new Point(100, 400));
            ManagerDraw.Cutter.Points.Add(new Point(600, 400));
            ManagerDraw.Cutter.Points.Add(new Point(600, 200));
            ManagerDraw.DrawCutter();

            ManagerDraw.Polygon.Points.Add(new Point(86, 122));
            ManagerDraw.Polygon.Points.Add(new Point(13, 250));
            ManagerDraw.Polygon.Points.Add(new Point(144, 152));
            /*ManagerDraw.Polygon.Points.Add(new Point(258, 278));
            ManagerDraw.Polygon.Points.Add(new Point(193, 116));
            ManagerDraw.Polygon.Points.Add(new Point(284, 66));
            ManagerDraw.Polygon.Points.Add(new Point(620, 87));
            ManagerDraw.Polygon.Points.Add(new Point(730, 258));
            ManagerDraw.Polygon.Points.Add(new Point(600, 237));
            ManagerDraw.Polygon.Points.Add(new Point(599, 201));
            ManagerDraw.Polygon.Points.Add(new Point(340, 201));
            ManagerDraw.Polygon.Points.Add(new Point(288, 136));*/
            ManagerDraw.DrawPolygon();
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
            else if (ManagerDraw.IsInputPolygon)
            {
                ManagerDraw.DrawMovingPolygon(mousePos, ModifierKeys == Keys.Shift);
            }
        }

        private void pbCanvas_Click(object sender, EventArgs e)
        {
            Point mousePos = pbCanvas.PointToClient(MousePosition);

            if (checkBoxPolygon.Checked)
            {
                if (((MouseEventArgs)e).Button == MouseButtons.Left)
                {
                    ManagerDraw.InputPolygon(mousePos, ModifierKeys == Keys.Shift);
                }
                else if (((MouseEventArgs)e).Button == MouseButtons.Right)
                {
                    ManagerDraw.ClosePolygon();
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
            checkBoxCutter.Checked = !checkBoxPolygon.Checked;

        }

        private void checkBoxCutter_CheckedChanged(object sender, EventArgs e)
        {
            checkBoxPolygon.Checked = !checkBoxCutter.Checked;
        }


        private void Cut()
        {
            try
            {
                Cutter.Points = new List<Point>(ManagerDraw.Cutter);

                var points = Cutter.Cut(ManagerDraw.Polygon.Points);
                if (points != null)
                {
                    for (int i = 1; i < points.Count(); i++)
                        ManagerDraw.DrawCuttedLine(points[i - 1], points[i]);

                    ManagerDraw.DrawCuttedLine(points.Last(), points.First());
                }
            }
            catch (NoConvexCutterException e)
            {
                MessageBox.Show(e.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
