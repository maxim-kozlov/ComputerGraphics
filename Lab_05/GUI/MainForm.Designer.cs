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
            this.pictureBox = new System.Windows.Forms.PictureBox();
            this.btnFill = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.labelDelay = new System.Windows.Forms.Label();
            this.pictureBoxFillColor = new System.Windows.Forms.PictureBox();
            this.btnChangeFillColor = new System.Windows.Forms.Button();
            this.labelFillColor = new System.Windows.Forms.Label();
            this.colorDialogFill = new System.Windows.Forms.ColorDialog();
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.numericUpDownDelay = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxFillColor)).BeginInit();
            this.menuStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDelay)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox
            // 
            this.pictureBox.BackColor = System.Drawing.Color.White;
            this.pictureBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox.Location = new System.Drawing.Point(12, 31);
            this.pictureBox.Name = "pictureBox";
            this.pictureBox.Size = new System.Drawing.Size(1027, 713);
            this.pictureBox.TabIndex = 0;
            this.pictureBox.TabStop = false;
            this.pictureBox.Click += new System.EventHandler(this.pictureBox_Click);
            this.pictureBox.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBox_MouseMove);
            // 
            // btnFill
            // 
            this.btnFill.Location = new System.Drawing.Point(1083, 163);
            this.btnFill.Name = "btnFill";
            this.btnFill.Size = new System.Drawing.Size(96, 35);
            this.btnFill.TabIndex = 1;
            this.btnFill.Text = "Fill";
            this.btnFill.UseVisualStyleBackColor = true;
            this.btnFill.Click += new System.EventHandler(this.btnFill_Click);
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(1185, 163);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(96, 36);
            this.btnClear.TabIndex = 2;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // labelDelay
            // 
            this.labelDelay.AutoSize = true;
            this.labelDelay.Location = new System.Drawing.Point(1080, 128);
            this.labelDelay.Name = "labelDelay";
            this.labelDelay.Size = new System.Drawing.Size(44, 17);
            this.labelDelay.TabIndex = 4;
            this.labelDelay.Text = "Delay";
            // 
            // pictureBoxFillColor
            // 
            this.pictureBoxFillColor.BackColor = System.Drawing.Color.Black;
            this.pictureBoxFillColor.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBoxFillColor.Location = new System.Drawing.Point(1134, 41);
            this.pictureBoxFillColor.Name = "pictureBoxFillColor";
            this.pictureBoxFillColor.Size = new System.Drawing.Size(147, 21);
            this.pictureBoxFillColor.TabIndex = 5;
            this.pictureBoxFillColor.TabStop = false;
            // 
            // btnChangeFillColor
            // 
            this.btnChangeFillColor.Location = new System.Drawing.Point(1083, 68);
            this.btnChangeFillColor.Name = "btnChangeFillColor";
            this.btnChangeFillColor.Size = new System.Drawing.Size(198, 36);
            this.btnChangeFillColor.TabIndex = 6;
            this.btnChangeFillColor.Text = "Change";
            this.btnChangeFillColor.UseVisualStyleBackColor = true;
            this.btnChangeFillColor.Click += new System.EventHandler(this.btnChangeFillColor_Click);
            // 
            // labelFillColor
            // 
            this.labelFillColor.AutoSize = true;
            this.labelFillColor.Location = new System.Drawing.Point(1080, 41);
            this.labelFillColor.Name = "labelFillColor";
            this.labelFillColor.Size = new System.Drawing.Size(41, 17);
            this.labelFillColor.TabIndex = 7;
            this.labelFillColor.Text = "Color";
            // 
            // menuStrip
            // 
            this.menuStrip.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.helpToolStripMenuItem});
            this.menuStrip.Location = new System.Drawing.Point(0, 0);
            this.menuStrip.Name = "menuStrip";
            this.menuStrip.Size = new System.Drawing.Size(1312, 28);
            this.menuStrip.TabIndex = 8;
            this.menuStrip.Text = "menuStrip1";
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(52, 24);
            this.helpToolStripMenuItem.Text = "help";
            // 
            // numericUpDownDelay
            // 
            this.numericUpDownDelay.Location = new System.Drawing.Point(1130, 128);
            this.numericUpDownDelay.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.numericUpDownDelay.Name = "numericUpDownDelay";
            this.numericUpDownDelay.Size = new System.Drawing.Size(151, 22);
            this.numericUpDownDelay.TabIndex = 9;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1312, 756);
            this.Controls.Add(this.numericUpDownDelay);
            this.Controls.Add(this.labelFillColor);
            this.Controls.Add(this.btnChangeFillColor);
            this.Controls.Add(this.pictureBoxFillColor);
            this.Controls.Add(this.labelDelay);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.btnFill);
            this.Controls.Add(this.pictureBox);
            this.Controls.Add(this.menuStrip);
            this.MainMenuStrip = this.menuStrip;
            this.Name = "MainForm";
            this.Text = "Lab_05";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxFillColor)).EndInit();
            this.menuStrip.ResumeLayout(false);
            this.menuStrip.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownDelay)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox;
        private System.Windows.Forms.Button btnFill;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Label labelDelay;
        private System.Windows.Forms.PictureBox pictureBoxFillColor;
        private System.Windows.Forms.Button btnChangeFillColor;
        private System.Windows.Forms.Label labelFillColor;
        private System.Windows.Forms.ColorDialog colorDialogFill;
        private System.Windows.Forms.MenuStrip menuStrip;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.NumericUpDown numericUpDownDelay;
    }
}

