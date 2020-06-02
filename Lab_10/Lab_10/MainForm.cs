using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using LibraryFunctions;

namespace Lab_10
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
            
            FloatHorizont = new FloatHorizont();
            FloatHorizont.screenSize = pbCanvas.Size;

            Functions = new List<Function>();
            Functions.Add(new Function("x*x + z*z", (x, z) => (x * x + z * z) / 5 - 5));
            Functions.Add(new Function("sin(sqrt(x*x + z*z))", (x, z) => Math.Sin(Math.Sqrt(x * x + z * z))));
            Functions.Add(new Function("x + z", (x, z) => (x + z)/1.5));
            Functions.Add(new Function("sin(x + z)", (x, z) => Math.Sin(x + z)));

            foreach (var func in Functions)
                checkedListBoxFunctions.Items.Add(func.Name);
            checkedListBoxFunctions.SelectedIndex = 0;

            UserPen = new UserPen(pbPlotColor);
            UserPen.Pen = new Pen(Color.Black, 1);

            result = new Bitmap(pbCanvas.Width, pbCanvas.Height);
            g = Graphics.FromImage(result);
            pbCanvas.Image = result;
        }

        private Bitmap result { get; }
        private Graphics g { get; }

        private IList<Function> Functions { get; }
        private UserPen UserPen { get;  }

        private FloatHorizont FloatHorizont { get; }

        private double GetRadians(decimal angle) => Math.PI * Convert.ToDouble(angle) / 180;

        private void Draw()
        {
            g.Clear(Color.White);

            var func = Functions[checkedListBoxFunctions.SelectedIndex];

            double ox = GetRadians(RotateX.Value);
            double oy = GetRadians(RotateY.Value);
            double oz = GetRadians(RotateZ.Value);

            double xStart = Convert.ToDouble(XStart.Value);
            double xEnd = Convert.ToDouble(XEnd.Value);
            double xStep = Convert.ToDouble(XStep.Value);

            double zStart = Convert.ToDouble(ZStart.Value);
            double zEnd = Convert.ToDouble(ZEnd.Value);
            double zStep = Convert.ToDouble(ZStep.Value);

            FloatHorizont.screenSize = pbCanvas.Size;
            FloatHorizont.Draw(
                func.FuncY,
                ox, oy, oz,
                zStart, zEnd, zStep,
                xStart, xEnd, xStep,
                g, UserPen.Pen
                );

            pbCanvas.Refresh();
        }

        private void checkedListBoxFunctions_SelectedIndexChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < checkedListBoxFunctions.Items.Count; i++)
                checkedListBoxFunctions.SetItemChecked(i, false);

            if (checkedListBoxFunctions.Items.Count > 0)
                checkedListBoxFunctions.SetItemChecked(checkedListBoxFunctions.SelectedIndex, true);
        }

        private void btnDraw_Click(object sender, EventArgs e)
        {
            RotateX.Value = 0;
            RotateY.Value = 0;
            RotateZ.Value = 0;
            Draw();
        }

        private void XStart_ValueChanged(object sender, EventArgs e) => Draw();
        private void XEnd_ValueChanged(object sender, EventArgs e) => Draw();

        private void ZStart_ValueChanged(object sender, EventArgs e) => Draw();
        private void ZEnd_ValueChanged(object sender, EventArgs e) => Draw();

        private void RotateX_ValueChanged(object sender, EventArgs e) => Draw();
        private void RotateY_ValueChanged(object sender, EventArgs e) => Draw();
        private void RotateZ_ValueChanged(object sender, EventArgs e) => Draw();
    }
}
