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
            ManagerDraw = new ManagerDraw(Canvas, pictureBoxFillColor);
            FillingSeed = new LineSeedAlgorithm();
        }

        private ManagerDraw ManagerDraw { get; }
        private IFillingSeed FillingSeed { get; }

        private void btnClear_Click(object sender, EventArgs e)
        {
            ManagerDraw.ClearPolygons();
        }

        private void btnChangeFillColor_Click(object sender, EventArgs e)
        {
            if (colorDialog.ShowDialog() == DialogResult.OK)
                ManagerDraw.PenFill = new Pen(colorDialog.Color, 1);

        }

        private void Canvas_Click(object sender, EventArgs e)
        {
            Point mousePos = Canvas.PointToClient(MousePosition);
            
            if (((MouseEventArgs)e).Button == MouseButtons.Left)
            {
                if (IsInputVertHorLine())
                    ManagerDraw.AddHorVertLinePolygon(mousePos);

                else if (isInputSeed())
                {
                    ManagerDraw.ClearCanvas();
                    ManagerDraw.DrawPolygons();
                    if (numericUpDownDelay.Value != 0)
                        FillingSeed.FillAreaWithDelay(ManagerDraw.Canvas, ManagerDraw.PenFill.Color, ManagerDraw.PenEdges.Color, mousePos, Canvas, (int)numericUpDownDelay.Value);
                    else
                        FillingSeed.FillArea(ManagerDraw.Canvas, ManagerDraw.PenFill.Color, ManagerDraw.PenEdges.Color, mousePos);
                    Canvas.Refresh();
                }
                else
                    ManagerDraw.AddPointPolygon(mousePos);
            }

            if (((MouseEventArgs)e).Button == MouseButtons.Right)
                ManagerDraw.ClosePolygon();
        }

        private void Canvas_MouseMove(object sender, MouseEventArgs e)
        {
            Point mousePos = Canvas.PointToClient(MousePosition);
            if (IsInputVertHorLine())
                mousePos = ManagerDraw.GetPointHorVertLine(mousePos);

            ManagerDraw.DrawMovingEdge(mousePos);
        }

        private bool IsInputVertHorLine()
        {
            return ModifierKeys == Keys.Shift;
        }

        private bool isInputSeed()
        {
            return ModifierKeys == Keys.Control;
        }
    }
}
