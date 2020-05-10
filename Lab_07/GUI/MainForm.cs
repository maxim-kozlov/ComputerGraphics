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
    public partial class MainForm : System.Windows.Forms.Form
    {
        public MainForm()
        {
            InitializeComponent();
            ManagerDraw = new ManagerDraw(pbCanvas, pbLineColor, pbCutterColor, pbCuttedLine);
            Cutter = new CutterCohenSutherland();
        }

        private ManagerDraw ManagerDraw { get; }
        private Cutter Cutter { get; }

        private void btnClear_Click(object sender, EventArgs e)
        {
            ManagerDraw.Clear();
        }

        private void btnCut_Click(object sender, EventArgs e)
        {
            Cutter.SetAB(ManagerDraw.Cutter.A, ManagerDraw.Cutter.B);
            ManagerDraw.DrawCutter();

            foreach (var line in ManagerDraw.Lines)
            {
                var points = Cutter.Cut(line.A, line.B);
                if (points != null)
                {
                    ManagerDraw.DrawCuttedLine(points[0], points[1]);
                }
            }
            pbCanvas.Refresh();
        }

        private void pbCanvas_Click(object sender, EventArgs e)
        {
            Point mousePos = pbCanvas.PointToClient(MousePosition);

            if (((MouseEventArgs)e).Button == MouseButtons.Left)
            {
                ManagerDraw.InputLine(mousePos, ModifierKeys == Keys.Shift);
            }

            else if (((MouseEventArgs)e).Button == MouseButtons.Right)
            {
                ManagerDraw.InputCutter(mousePos);
            }
        }

        private void pbCanvas_MouseMove(object sender, MouseEventArgs e)
        {
            Point mousePos = pbCanvas.PointToClient(MousePosition);
            if (ManagerDraw.IsInputCutter)
            {
                ManagerDraw.DrawMovingCutter(mousePos);
            }
            else if (ManagerDraw.IsInputLine)
            {
                ManagerDraw.DrawMovingLine(mousePos, ModifierKeys == Keys.Shift);
            }
        }
    }
}
