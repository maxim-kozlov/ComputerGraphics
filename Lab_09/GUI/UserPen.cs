using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;

namespace GUI
{
    class UserPen
    {
        public UserPen(PictureBox pbColor)
        {
            PbColor = pbColor;
            PbColor.Click += PbColor_Click;
        }

        private void PbColor_Click(object sender, EventArgs e)
        {
            ColorDialog colorDialog = new ColorDialog();
            if (colorDialog.ShowDialog() == DialogResult.OK)
                Pen = new Pen(colorDialog.Color, 1);
        }

        private Pen _pen;
        public Pen Pen 
        {
            get => _pen;
            set
            {
                _pen = value;
                PbColor.BackColor = value.Color;
            }
        }

        private PictureBox PbColor { get; }
    }
}
