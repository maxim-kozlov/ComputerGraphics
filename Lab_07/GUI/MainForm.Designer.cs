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
            this.labelLineColor = new System.Windows.Forms.Label();
            this.pbLineColor = new System.Windows.Forms.PictureBox();
            this.labelCutterColor = new System.Windows.Forms.Label();
            this.pbCutterColor = new System.Windows.Forms.PictureBox();
            this.labelCuttedLineColor = new System.Windows.Forms.Label();
            this.pbCuttedLine = new System.Windows.Forms.PictureBox();
            this.btnClear = new System.Windows.Forms.Button();
            this.pbCanvas = new System.Windows.Forms.PictureBox();
            this.btnCut = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pbLineColor)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbCutterColor)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbCuttedLine)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbCanvas)).BeginInit();
            this.SuspendLayout();
            // 
            // labelLineColor
            // 
            this.labelLineColor.AutoSize = true;
            this.labelLineColor.Location = new System.Drawing.Point(1058, 12);
            this.labelLineColor.Name = "labelLineColor";
            this.labelLineColor.Size = new System.Drawing.Size(35, 17);
            this.labelLineColor.TabIndex = 13;
            this.labelLineColor.Text = "Line";
            // 
            // pbLineColor
            // 
            this.pbLineColor.BackColor = System.Drawing.Color.Black;
            this.pbLineColor.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pbLineColor.Location = new System.Drawing.Point(1147, 12);
            this.pbLineColor.Name = "pbLineColor";
            this.pbLineColor.Size = new System.Drawing.Size(112, 21);
            this.pbLineColor.TabIndex = 11;
            this.pbLineColor.TabStop = false;
            // 
            // labelCutterColor
            // 
            this.labelCutterColor.AutoSize = true;
            this.labelCutterColor.Location = new System.Drawing.Point(1058, 39);
            this.labelCutterColor.Name = "labelCutterColor";
            this.labelCutterColor.Size = new System.Drawing.Size(46, 17);
            this.labelCutterColor.TabIndex = 16;
            this.labelCutterColor.Text = "Cutter";
            // 
            // pbCutterColor
            // 
            this.pbCutterColor.BackColor = System.Drawing.Color.Black;
            this.pbCutterColor.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pbCutterColor.Location = new System.Drawing.Point(1147, 39);
            this.pbCutterColor.Name = "pbCutterColor";
            this.pbCutterColor.Size = new System.Drawing.Size(112, 21);
            this.pbCutterColor.TabIndex = 14;
            this.pbCutterColor.TabStop = false;
            // 
            // labelCuttedLineColor
            // 
            this.labelCuttedLineColor.AutoSize = true;
            this.labelCuttedLineColor.Location = new System.Drawing.Point(1058, 66);
            this.labelCuttedLineColor.Name = "labelCuttedLineColor";
            this.labelCuttedLineColor.Size = new System.Drawing.Size(80, 17);
            this.labelCuttedLineColor.TabIndex = 18;
            this.labelCuttedLineColor.Text = "Cutted Line";
            // 
            // pbCuttedLine
            // 
            this.pbCuttedLine.BackColor = System.Drawing.Color.Black;
            this.pbCuttedLine.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pbCuttedLine.Location = new System.Drawing.Point(1147, 66);
            this.pbCuttedLine.Name = "pbCuttedLine";
            this.pbCuttedLine.Size = new System.Drawing.Size(112, 21);
            this.pbCuttedLine.TabIndex = 17;
            this.pbCuttedLine.TabStop = false;
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(1061, 158);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(198, 36);
            this.btnClear.TabIndex = 19;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // pbCanvas
            // 
            this.pbCanvas.BackColor = System.Drawing.Color.White;
            this.pbCanvas.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pbCanvas.Location = new System.Drawing.Point(12, 12);
            this.pbCanvas.Name = "pbCanvas";
            this.pbCanvas.Size = new System.Drawing.Size(1027, 713);
            this.pbCanvas.TabIndex = 20;
            this.pbCanvas.TabStop = false;
            this.pbCanvas.Click += new System.EventHandler(this.pbCanvas_Click);
            this.pbCanvas.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pbCanvas_MouseMove);
            // 
            // btnCut
            // 
            this.btnCut.Location = new System.Drawing.Point(1061, 105);
            this.btnCut.Name = "btnCut";
            this.btnCut.Size = new System.Drawing.Size(198, 36);
            this.btnCut.TabIndex = 21;
            this.btnCut.Text = "Cut";
            this.btnCut.UseVisualStyleBackColor = true;
            this.btnCut.Click += new System.EventHandler(this.btnCut_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1280, 731);
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
            this.Text = "Lab_07";
            ((System.ComponentModel.ISupportInitialize)(this.pbLineColor)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbCutterColor)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbCuttedLine)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbCanvas)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ColorDialog colorDialogLine;
        private System.Windows.Forms.ColorDialog colorDialogCutter;
        private System.Windows.Forms.ColorDialog colorDialogCuttedLine;
        private System.Windows.Forms.Label labelLineColor;
        private System.Windows.Forms.PictureBox pbLineColor;
        private System.Windows.Forms.Label labelCutterColor;
        private System.Windows.Forms.PictureBox pbCutterColor;
        private System.Windows.Forms.Label labelCuttedLineColor;
        private System.Windows.Forms.PictureBox pbCuttedLine;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.PictureBox pbCanvas;
        private System.Windows.Forms.Button btnCut;
    }
}

