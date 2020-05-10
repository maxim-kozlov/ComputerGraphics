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
            this.Canvas = new System.Windows.Forms.PictureBox();
            this.labelFillColor = new System.Windows.Forms.Label();
            this.btnChangeFillColor = new System.Windows.Forms.Button();
            this.pictureBoxFillColor = new System.Windows.Forms.PictureBox();
            this.numericUpDownDelay = new System.Windows.Forms.NumericUpDown();
            this.labelDelay = new System.Windows.Forms.Label();
            this.btnClear = new System.Windows.Forms.Button();
            this.colorDialog = new System.Windows.Forms.ColorDialog();
            ((System.ComponentModel.ISupportInitialize)(this.Canvas)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxFillColor)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDelay)).BeginInit();
            this.SuspendLayout();
            // 
            // Canvas
            // 
            this.Canvas.BackColor = System.Drawing.Color.White;
            this.Canvas.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.Canvas.Location = new System.Drawing.Point(12, 12);
            this.Canvas.Name = "Canvas";
            this.Canvas.Size = new System.Drawing.Size(1027, 713);
            this.Canvas.TabIndex = 1;
            this.Canvas.TabStop = false;
            this.Canvas.Click += new System.EventHandler(this.Canvas_Click);
            this.Canvas.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Canvas_MouseMove);
            // 
            // labelFillColor
            // 
            this.labelFillColor.AutoSize = true;
            this.labelFillColor.Location = new System.Drawing.Point(1064, 34);
            this.labelFillColor.Name = "labelFillColor";
            this.labelFillColor.Size = new System.Drawing.Size(41, 17);
            this.labelFillColor.TabIndex = 10;
            this.labelFillColor.Text = "Color";
            // 
            // btnChangeFillColor
            // 
            this.btnChangeFillColor.Location = new System.Drawing.Point(1067, 61);
            this.btnChangeFillColor.Name = "btnChangeFillColor";
            this.btnChangeFillColor.Size = new System.Drawing.Size(198, 36);
            this.btnChangeFillColor.TabIndex = 9;
            this.btnChangeFillColor.Text = "Change";
            this.btnChangeFillColor.UseVisualStyleBackColor = true;
            this.btnChangeFillColor.Click += new System.EventHandler(this.btnChangeFillColor_Click);
            // 
            // pictureBoxFillColor
            // 
            this.pictureBoxFillColor.BackColor = System.Drawing.Color.Black;
            this.pictureBoxFillColor.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBoxFillColor.Location = new System.Drawing.Point(1118, 34);
            this.pictureBoxFillColor.Name = "pictureBoxFillColor";
            this.pictureBoxFillColor.Size = new System.Drawing.Size(147, 21);
            this.pictureBoxFillColor.TabIndex = 8;
            this.pictureBoxFillColor.TabStop = false;
            // 
            // numericUpDownDelay
            // 
            this.numericUpDownDelay.Location = new System.Drawing.Point(1114, 120);
            this.numericUpDownDelay.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.numericUpDownDelay.Name = "numericUpDownDelay";
            this.numericUpDownDelay.Size = new System.Drawing.Size(151, 22);
            this.numericUpDownDelay.TabIndex = 14;
            // 
            // labelDelay
            // 
            this.labelDelay.AutoSize = true;
            this.labelDelay.Location = new System.Drawing.Point(1064, 120);
            this.labelDelay.Name = "labelDelay";
            this.labelDelay.Size = new System.Drawing.Size(44, 17);
            this.labelDelay.TabIndex = 13;
            this.labelDelay.Text = "Delay";
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(1067, 155);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(198, 36);
            this.btnClear.TabIndex = 12;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1292, 740);
            this.Controls.Add(this.numericUpDownDelay);
            this.Controls.Add(this.labelDelay);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.labelFillColor);
            this.Controls.Add(this.btnChangeFillColor);
            this.Controls.Add(this.pictureBoxFillColor);
            this.Controls.Add(this.Canvas);
            this.Name = "MainForm";
            this.Text = "Lab_06";
            ((System.ComponentModel.ISupportInitialize)(this.Canvas)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxFillColor)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDelay)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox Canvas;
        private System.Windows.Forms.Label labelFillColor;
        private System.Windows.Forms.Button btnChangeFillColor;
        private System.Windows.Forms.PictureBox pictureBoxFillColor;
        private System.Windows.Forms.NumericUpDown numericUpDownDelay;
        private System.Windows.Forms.Label labelDelay;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.ColorDialog colorDialog;
    }
}

