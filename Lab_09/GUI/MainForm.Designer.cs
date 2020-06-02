namespace GUI
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.colorDialogLine = new System.Windows.Forms.ColorDialog();
            this.colorDialogCutter = new System.Windows.Forms.ColorDialog();
            this.colorDialogCuttedLine = new System.Windows.Forms.ColorDialog();
            this.btnCut = new System.Windows.Forms.Button();
            this.pbCanvas = new System.Windows.Forms.PictureBox();
            this.btnClear = new System.Windows.Forms.Button();
            this.labelCuttedLineColor = new System.Windows.Forms.Label();
            this.pbCuttedLine = new System.Windows.Forms.PictureBox();
            this.labelCutterColor = new System.Windows.Forms.Label();
            this.pbCutterColor = new System.Windows.Forms.PictureBox();
            this.labelLineColor = new System.Windows.Forms.Label();
            this.pbLineColor = new System.Windows.Forms.PictureBox();
            this.checkBoxPolygon = new System.Windows.Forms.CheckBox();
            this.checkBoxCutter = new System.Windows.Forms.CheckBox();
            this.labelInput = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pbCanvas)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbCuttedLine)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbCutterColor)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbLineColor)).BeginInit();
            this.SuspendLayout();
            // 
            // btnCut
            // 
            this.btnCut.Location = new System.Drawing.Point(1061, 188);
            this.btnCut.Name = "btnCut";
            this.btnCut.Size = new System.Drawing.Size(198, 36);
            this.btnCut.TabIndex = 30;
            this.btnCut.Text = "Cut";
            this.btnCut.UseVisualStyleBackColor = true;
            this.btnCut.Click += new System.EventHandler(this.btnCut_Click);
            // 
            // pbCanvas
            // 
            this.pbCanvas.BackColor = System.Drawing.Color.White;
            this.pbCanvas.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pbCanvas.Location = new System.Drawing.Point(12, 12);
            this.pbCanvas.Name = "pbCanvas";
            this.pbCanvas.Size = new System.Drawing.Size(1027, 713);
            this.pbCanvas.TabIndex = 29;
            this.pbCanvas.TabStop = false;
            this.pbCanvas.Click += new System.EventHandler(this.pbCanvas_Click);
            this.pbCanvas.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pbCanvas_MouseMove);
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(1061, 241);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(198, 36);
            this.btnClear.TabIndex = 28;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // labelCuttedLineColor
            // 
            this.labelCuttedLineColor.AutoSize = true;
            this.labelCuttedLineColor.Location = new System.Drawing.Point(1058, 66);
            this.labelCuttedLineColor.Name = "labelCuttedLineColor";
            this.labelCuttedLineColor.Size = new System.Drawing.Size(80, 17);
            this.labelCuttedLineColor.TabIndex = 27;
            this.labelCuttedLineColor.Text = "Cutted Line";
            // 
            // pbCuttedLine
            // 
            this.pbCuttedLine.BackColor = System.Drawing.Color.Black;
            this.pbCuttedLine.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pbCuttedLine.Location = new System.Drawing.Point(1147, 66);
            this.pbCuttedLine.Name = "pbCuttedLine";
            this.pbCuttedLine.Size = new System.Drawing.Size(112, 21);
            this.pbCuttedLine.TabIndex = 26;
            this.pbCuttedLine.TabStop = false;
            // 
            // labelCutterColor
            // 
            this.labelCutterColor.AutoSize = true;
            this.labelCutterColor.Location = new System.Drawing.Point(1058, 39);
            this.labelCutterColor.Name = "labelCutterColor";
            this.labelCutterColor.Size = new System.Drawing.Size(46, 17);
            this.labelCutterColor.TabIndex = 25;
            this.labelCutterColor.Text = "Cutter";
            // 
            // pbCutterColor
            // 
            this.pbCutterColor.BackColor = System.Drawing.Color.Black;
            this.pbCutterColor.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pbCutterColor.Location = new System.Drawing.Point(1147, 39);
            this.pbCutterColor.Name = "pbCutterColor";
            this.pbCutterColor.Size = new System.Drawing.Size(112, 21);
            this.pbCutterColor.TabIndex = 24;
            this.pbCutterColor.TabStop = false;
            // 
            // labelLineColor
            // 
            this.labelLineColor.AutoSize = true;
            this.labelLineColor.Location = new System.Drawing.Point(1058, 12);
            this.labelLineColor.Name = "labelLineColor";
            this.labelLineColor.Size = new System.Drawing.Size(35, 17);
            this.labelLineColor.TabIndex = 23;
            this.labelLineColor.Text = "Line";
            // 
            // pbLineColor
            // 
            this.pbLineColor.BackColor = System.Drawing.Color.Black;
            this.pbLineColor.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pbLineColor.Location = new System.Drawing.Point(1147, 12);
            this.pbLineColor.Name = "pbLineColor";
            this.pbLineColor.Size = new System.Drawing.Size(112, 21);
            this.pbLineColor.TabIndex = 22;
            this.pbLineColor.TabStop = false;
            // 
            // checkBoxPolygon
            // 
            this.checkBoxPolygon.AutoSize = true;
            this.checkBoxPolygon.Checked = true;
            this.checkBoxPolygon.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxPolygon.Location = new System.Drawing.Point(1061, 120);
            this.checkBoxPolygon.Name = "checkBoxPolygon";
            this.checkBoxPolygon.Size = new System.Drawing.Size(81, 21);
            this.checkBoxPolygon.TabIndex = 32;
            this.checkBoxPolygon.Text = "Polygon";
            this.checkBoxPolygon.UseVisualStyleBackColor = true;
            this.checkBoxPolygon.CheckedChanged += new System.EventHandler(this.checkBoxLine_CheckedChanged);
            // 
            // checkBoxCutter
            // 
            this.checkBoxCutter.AutoSize = true;
            this.checkBoxCutter.Location = new System.Drawing.Point(1061, 147);
            this.checkBoxCutter.Name = "checkBoxCutter";
            this.checkBoxCutter.Size = new System.Drawing.Size(68, 21);
            this.checkBoxCutter.TabIndex = 33;
            this.checkBoxCutter.Text = "Cutter";
            this.checkBoxCutter.UseVisualStyleBackColor = true;
            this.checkBoxCutter.CheckedChanged += new System.EventHandler(this.checkBoxCutter_CheckedChanged);
            // 
            // labelInput
            // 
            this.labelInput.AutoSize = true;
            this.labelInput.Location = new System.Drawing.Point(1058, 100);
            this.labelInput.Name = "labelInput";
            this.labelInput.Size = new System.Drawing.Size(43, 17);
            this.labelInput.TabIndex = 34;
            this.labelInput.Text = "Input:";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1282, 733);
            this.Controls.Add(this.labelInput);
            this.Controls.Add(this.checkBoxCutter);
            this.Controls.Add(this.checkBoxPolygon);
            this.Controls.Add(this.btnCut);
            this.Controls.Add(this.pbCanvas);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.labelCuttedLineColor);
            this.Controls.Add(this.pbCuttedLine);
            this.Controls.Add(this.labelCutterColor);
            this.Controls.Add(this.pbCutterColor);
            this.Controls.Add(this.labelLineColor);
            this.Controls.Add(this.pbLineColor);
            this.Name = "MainForm";
            this.Text = "Lab_09";
            ((System.ComponentModel.ISupportInitialize)(this.pbCanvas)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbCuttedLine)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbCutterColor)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbLineColor)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ColorDialog colorDialogLine;
        private System.Windows.Forms.ColorDialog colorDialogCutter;
        private System.Windows.Forms.ColorDialog colorDialogCuttedLine;
        private System.Windows.Forms.Button btnCut;
        private System.Windows.Forms.PictureBox pbCanvas;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Label labelCuttedLineColor;
        private System.Windows.Forms.PictureBox pbCuttedLine;
        private System.Windows.Forms.Label labelCutterColor;
        private System.Windows.Forms.PictureBox pbCutterColor;
        private System.Windows.Forms.Label labelLineColor;
        private System.Windows.Forms.PictureBox pbLineColor;
        private System.Windows.Forms.CheckBox checkBoxPolygon;
        private System.Windows.Forms.CheckBox checkBoxCutter;
        private System.Windows.Forms.Label labelInput;
    }
}

