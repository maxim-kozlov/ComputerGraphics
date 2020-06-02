namespace Lab_10
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
            this.pbCanvas = new System.Windows.Forms.PictureBox();
            this.labelPlotColor = new System.Windows.Forms.Label();
            this.pbPlotColor = new System.Windows.Forms.PictureBox();
            this.XStart = new System.Windows.Forms.NumericUpDown();
            this.XEnd = new System.Windows.Forms.NumericUpDown();
            this.XStep = new System.Windows.Forms.NumericUpDown();
            this.groupX = new System.Windows.Forms.GroupBox();
            this.labelXStep = new System.Windows.Forms.Label();
            this.labelXEnd = new System.Windows.Forms.Label();
            this.labelXStart = new System.Windows.Forms.Label();
            this.groupZ = new System.Windows.Forms.GroupBox();
            this.labelZStep = new System.Windows.Forms.Label();
            this.labelZEnd = new System.Windows.Forms.Label();
            this.labelZStart = new System.Windows.Forms.Label();
            this.ZEnd = new System.Windows.Forms.NumericUpDown();
            this.ZStep = new System.Windows.Forms.NumericUpDown();
            this.ZStart = new System.Windows.Forms.NumericUpDown();
            this.RotateX = new System.Windows.Forms.NumericUpDown();
            this.RotateY = new System.Windows.Forms.NumericUpDown();
            this.RotateZ = new System.Windows.Forms.NumericUpDown();
            this.groupRotate = new System.Windows.Forms.GroupBox();
            this.labelRotateZ = new System.Windows.Forms.Label();
            this.labelRotateY = new System.Windows.Forms.Label();
            this.labelRotateX = new System.Windows.Forms.Label();
            this.groupCurves = new System.Windows.Forms.GroupBox();
            this.checkedListBoxFunctions = new System.Windows.Forms.CheckedListBox();
            this.btnDraw = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pbCanvas)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbPlotColor)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.XStart)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.XEnd)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.XStep)).BeginInit();
            this.groupX.SuspendLayout();
            this.groupZ.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ZEnd)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ZStep)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ZStart)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.RotateX)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.RotateY)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.RotateZ)).BeginInit();
            this.groupRotate.SuspendLayout();
            this.groupCurves.SuspendLayout();
            this.SuspendLayout();
            // 
            // pbCanvas
            // 
            this.pbCanvas.BackColor = System.Drawing.Color.White;
            this.pbCanvas.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pbCanvas.Location = new System.Drawing.Point(13, 12);
            this.pbCanvas.Name = "pbCanvas";
            this.pbCanvas.Size = new System.Drawing.Size(900, 630);
            this.pbCanvas.TabIndex = 30;
            this.pbCanvas.TabStop = false;
            // 
            // labelPlotColor
            // 
            this.labelPlotColor.AutoSize = true;
            this.labelPlotColor.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelPlotColor.Location = new System.Drawing.Point(935, 22);
            this.labelPlotColor.Name = "labelPlotColor";
            this.labelPlotColor.Size = new System.Drawing.Size(97, 25);
            this.labelPlotColor.TabIndex = 32;
            this.labelPlotColor.Text = "Plot Color";
            // 
            // pbPlotColor
            // 
            this.pbPlotColor.BackColor = System.Drawing.Color.Black;
            this.pbPlotColor.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pbPlotColor.Location = new System.Drawing.Point(1049, 22);
            this.pbPlotColor.Name = "pbPlotColor";
            this.pbPlotColor.Size = new System.Drawing.Size(245, 25);
            this.pbPlotColor.TabIndex = 31;
            this.pbPlotColor.TabStop = false;
            // 
            // XStart
            // 
            this.XStart.DecimalPlaces = 2;
            this.XStart.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.XStart.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.XStart.Location = new System.Drawing.Point(10, 55);
            this.XStart.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.XStart.Minimum = new decimal(new int[] {
            1000,
            0,
            0,
            -2147483648});
            this.XStart.Name = "XStart";
            this.XStart.Size = new System.Drawing.Size(100, 24);
            this.XStart.TabIndex = 34;
            this.XStart.Value = new decimal(new int[] {
            5,
            0,
            0,
            -2147483648});
            this.XStart.ValueChanged += new System.EventHandler(this.XStart_ValueChanged);
            // 
            // XEnd
            // 
            this.XEnd.DecimalPlaces = 2;
            this.XEnd.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.XEnd.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.XEnd.Location = new System.Drawing.Point(131, 55);
            this.XEnd.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.XEnd.Minimum = new decimal(new int[] {
            1000,
            0,
            0,
            -2147483648});
            this.XEnd.Name = "XEnd";
            this.XEnd.Size = new System.Drawing.Size(100, 24);
            this.XEnd.TabIndex = 35;
            this.XEnd.Value = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.XEnd.ValueChanged += new System.EventHandler(this.XEnd_ValueChanged);
            // 
            // XStep
            // 
            this.XStep.DecimalPlaces = 2;
            this.XStep.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.XStep.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.XStep.Location = new System.Drawing.Point(252, 55);
            this.XStep.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.XStep.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.XStep.Name = "XStep";
            this.XStep.Size = new System.Drawing.Size(100, 24);
            this.XStep.TabIndex = 36;
            this.XStep.Value = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            // 
            // groupX
            // 
            this.groupX.Controls.Add(this.labelXStep);
            this.groupX.Controls.Add(this.labelXEnd);
            this.groupX.Controls.Add(this.labelXStart);
            this.groupX.Controls.Add(this.XEnd);
            this.groupX.Controls.Add(this.XStep);
            this.groupX.Controls.Add(this.XStart);
            this.groupX.Location = new System.Drawing.Point(928, 282);
            this.groupX.Name = "groupX";
            this.groupX.Size = new System.Drawing.Size(364, 90);
            this.groupX.TabIndex = 37;
            this.groupX.TabStop = false;
            this.groupX.Text = "X";
            // 
            // labelXStep
            // 
            this.labelXStep.AutoSize = true;
            this.labelXStep.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelXStep.Location = new System.Drawing.Point(249, 27);
            this.labelXStep.Name = "labelXStep";
            this.labelXStep.Size = new System.Drawing.Size(53, 25);
            this.labelXStep.TabIndex = 39;
            this.labelXStep.Text = "Step";
            // 
            // labelXEnd
            // 
            this.labelXEnd.AutoSize = true;
            this.labelXEnd.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelXEnd.Location = new System.Drawing.Point(128, 27);
            this.labelXEnd.Name = "labelXEnd";
            this.labelXEnd.Size = new System.Drawing.Size(47, 25);
            this.labelXEnd.TabIndex = 39;
            this.labelXEnd.Text = "End";
            // 
            // labelXStart
            // 
            this.labelXStart.AutoSize = true;
            this.labelXStart.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelXStart.Location = new System.Drawing.Point(10, 27);
            this.labelXStart.Name = "labelXStart";
            this.labelXStart.Size = new System.Drawing.Size(53, 25);
            this.labelXStart.TabIndex = 38;
            this.labelXStart.Text = "Start";
            // 
            // groupZ
            // 
            this.groupZ.Controls.Add(this.labelZStep);
            this.groupZ.Controls.Add(this.labelZEnd);
            this.groupZ.Controls.Add(this.labelZStart);
            this.groupZ.Controls.Add(this.ZEnd);
            this.groupZ.Controls.Add(this.ZStep);
            this.groupZ.Controls.Add(this.ZStart);
            this.groupZ.Location = new System.Drawing.Point(928, 389);
            this.groupZ.Name = "groupZ";
            this.groupZ.Size = new System.Drawing.Size(364, 90);
            this.groupZ.TabIndex = 40;
            this.groupZ.TabStop = false;
            this.groupZ.Text = "Z";
            // 
            // labelZStep
            // 
            this.labelZStep.AutoSize = true;
            this.labelZStep.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelZStep.Location = new System.Drawing.Point(249, 27);
            this.labelZStep.Name = "labelZStep";
            this.labelZStep.Size = new System.Drawing.Size(53, 25);
            this.labelZStep.TabIndex = 39;
            this.labelZStep.Text = "Step";
            // 
            // labelZEnd
            // 
            this.labelZEnd.AutoSize = true;
            this.labelZEnd.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelZEnd.Location = new System.Drawing.Point(128, 27);
            this.labelZEnd.Name = "labelZEnd";
            this.labelZEnd.Size = new System.Drawing.Size(47, 25);
            this.labelZEnd.TabIndex = 39;
            this.labelZEnd.Text = "End";
            // 
            // labelZStart
            // 
            this.labelZStart.AutoSize = true;
            this.labelZStart.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelZStart.Location = new System.Drawing.Point(10, 27);
            this.labelZStart.Name = "labelZStart";
            this.labelZStart.Size = new System.Drawing.Size(53, 25);
            this.labelZStart.TabIndex = 38;
            this.labelZStart.Text = "Start";
            // 
            // ZEnd
            // 
            this.ZEnd.DecimalPlaces = 2;
            this.ZEnd.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ZEnd.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.ZEnd.Location = new System.Drawing.Point(131, 55);
            this.ZEnd.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.ZEnd.Minimum = new decimal(new int[] {
            1000,
            0,
            0,
            -2147483648});
            this.ZEnd.Name = "ZEnd";
            this.ZEnd.Size = new System.Drawing.Size(100, 24);
            this.ZEnd.TabIndex = 35;
            this.ZEnd.Value = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.ZEnd.ValueChanged += new System.EventHandler(this.ZEnd_ValueChanged);
            // 
            // ZStep
            // 
            this.ZStep.DecimalPlaces = 2;
            this.ZStep.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ZStep.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.ZStep.Location = new System.Drawing.Point(252, 55);
            this.ZStep.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.ZStep.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            131072});
            this.ZStep.Name = "ZStep";
            this.ZStep.Size = new System.Drawing.Size(100, 24);
            this.ZStep.TabIndex = 36;
            this.ZStep.Value = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            // 
            // ZStart
            // 
            this.ZStart.DecimalPlaces = 2;
            this.ZStart.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ZStart.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.ZStart.Location = new System.Drawing.Point(10, 55);
            this.ZStart.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            this.ZStart.Minimum = new decimal(new int[] {
            1000,
            0,
            0,
            -2147483648});
            this.ZStart.Name = "ZStart";
            this.ZStart.Size = new System.Drawing.Size(100, 24);
            this.ZStart.TabIndex = 34;
            this.ZStart.Value = new decimal(new int[] {
            5,
            0,
            0,
            -2147483648});
            this.ZStart.ValueChanged += new System.EventHandler(this.ZStart_ValueChanged);
            // 
            // RotateX
            // 
            this.RotateX.DecimalPlaces = 2;
            this.RotateX.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.RotateX.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.RotateX.Location = new System.Drawing.Point(8, 56);
            this.RotateX.Maximum = new decimal(new int[] {
            360,
            0,
            0,
            0});
            this.RotateX.Minimum = new decimal(new int[] {
            360,
            0,
            0,
            -2147483648});
            this.RotateX.Name = "RotateX";
            this.RotateX.Size = new System.Drawing.Size(100, 24);
            this.RotateX.TabIndex = 40;
            this.RotateX.ValueChanged += new System.EventHandler(this.RotateX_ValueChanged);
            // 
            // RotateY
            // 
            this.RotateY.DecimalPlaces = 2;
            this.RotateY.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.RotateY.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.RotateY.Location = new System.Drawing.Point(131, 56);
            this.RotateY.Maximum = new decimal(new int[] {
            360,
            0,
            0,
            0});
            this.RotateY.Minimum = new decimal(new int[] {
            360,
            0,
            0,
            -2147483648});
            this.RotateY.Name = "RotateY";
            this.RotateY.Size = new System.Drawing.Size(100, 24);
            this.RotateY.TabIndex = 41;
            this.RotateY.ValueChanged += new System.EventHandler(this.RotateY_ValueChanged);
            // 
            // RotateZ
            // 
            this.RotateZ.DecimalPlaces = 2;
            this.RotateZ.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.RotateZ.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.RotateZ.Location = new System.Drawing.Point(252, 56);
            this.RotateZ.Maximum = new decimal(new int[] {
            360,
            0,
            0,
            0});
            this.RotateZ.Minimum = new decimal(new int[] {
            360,
            0,
            0,
            -2147483648});
            this.RotateZ.Name = "RotateZ";
            this.RotateZ.Size = new System.Drawing.Size(100, 24);
            this.RotateZ.TabIndex = 42;
            this.RotateZ.ValueChanged += new System.EventHandler(this.RotateZ_ValueChanged);
            // 
            // groupRotate
            // 
            this.groupRotate.Controls.Add(this.labelRotateZ);
            this.groupRotate.Controls.Add(this.labelRotateY);
            this.groupRotate.Controls.Add(this.labelRotateX);
            this.groupRotate.Controls.Add(this.RotateZ);
            this.groupRotate.Controls.Add(this.RotateX);
            this.groupRotate.Controls.Add(this.RotateY);
            this.groupRotate.Location = new System.Drawing.Point(928, 508);
            this.groupRotate.Name = "groupRotate";
            this.groupRotate.Size = new System.Drawing.Size(362, 88);
            this.groupRotate.TabIndex = 43;
            this.groupRotate.TabStop = false;
            this.groupRotate.Text = "Rotate";
            // 
            // labelRotateZ
            // 
            this.labelRotateZ.AutoSize = true;
            this.labelRotateZ.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelRotateZ.Location = new System.Drawing.Point(249, 28);
            this.labelRotateZ.Name = "labelRotateZ";
            this.labelRotateZ.Size = new System.Drawing.Size(24, 25);
            this.labelRotateZ.TabIndex = 44;
            this.labelRotateZ.Text = "Z";
            // 
            // labelRotateY
            // 
            this.labelRotateY.AutoSize = true;
            this.labelRotateY.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelRotateY.Location = new System.Drawing.Point(128, 28);
            this.labelRotateY.Name = "labelRotateY";
            this.labelRotateY.Size = new System.Drawing.Size(25, 25);
            this.labelRotateY.TabIndex = 43;
            this.labelRotateY.Text = "Y";
            // 
            // labelRotateX
            // 
            this.labelRotateX.AutoSize = true;
            this.labelRotateX.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelRotateX.Location = new System.Drawing.Point(6, 28);
            this.labelRotateX.Name = "labelRotateX";
            this.labelRotateX.Size = new System.Drawing.Size(26, 25);
            this.labelRotateX.TabIndex = 40;
            this.labelRotateX.Text = "X";
            // 
            // groupCurves
            // 
            this.groupCurves.Controls.Add(this.checkedListBoxFunctions);
            this.groupCurves.Location = new System.Drawing.Point(928, 53);
            this.groupCurves.Name = "groupCurves";
            this.groupCurves.Size = new System.Drawing.Size(362, 223);
            this.groupCurves.TabIndex = 44;
            this.groupCurves.TabStop = false;
            this.groupCurves.Text = "Functions";
            // 
            // checkedListBoxFunctions
            // 
            this.checkedListBoxFunctions.CheckOnClick = true;
            this.checkedListBoxFunctions.Dock = System.Windows.Forms.DockStyle.Fill;
            this.checkedListBoxFunctions.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.checkedListBoxFunctions.FormattingEnabled = true;
            this.checkedListBoxFunctions.Location = new System.Drawing.Point(3, 18);
            this.checkedListBoxFunctions.Name = "checkedListBoxFunctions";
            this.checkedListBoxFunctions.Size = new System.Drawing.Size(356, 202);
            this.checkedListBoxFunctions.TabIndex = 0;
            this.checkedListBoxFunctions.SelectedIndexChanged += new System.EventHandler(this.checkedListBoxFunctions_SelectedIndexChanged);
            // 
            // btnDraw
            // 
            this.btnDraw.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.btnDraw.Location = new System.Drawing.Point(931, 603);
            this.btnDraw.Name = "btnDraw";
            this.btnDraw.Size = new System.Drawing.Size(361, 39);
            this.btnDraw.TabIndex = 45;
            this.btnDraw.Text = "Draw";
            this.btnDraw.UseVisualStyleBackColor = true;
            this.btnDraw.Click += new System.EventHandler(this.btnDraw_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1304, 652);
            this.Controls.Add(this.btnDraw);
            this.Controls.Add(this.groupCurves);
            this.Controls.Add(this.groupRotate);
            this.Controls.Add(this.groupZ);
            this.Controls.Add(this.groupX);
            this.Controls.Add(this.labelPlotColor);
            this.Controls.Add(this.pbPlotColor);
            this.Controls.Add(this.pbCanvas);
            this.Name = "MainForm";
            this.Text = "Lab_10";
            ((System.ComponentModel.ISupportInitialize)(this.pbCanvas)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbPlotColor)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.XStart)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.XEnd)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.XStep)).EndInit();
            this.groupX.ResumeLayout(false);
            this.groupX.PerformLayout();
            this.groupZ.ResumeLayout(false);
            this.groupZ.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ZEnd)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ZStep)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ZStart)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.RotateX)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.RotateY)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.RotateZ)).EndInit();
            this.groupRotate.ResumeLayout(false);
            this.groupRotate.PerformLayout();
            this.groupCurves.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pbCanvas;
        private System.Windows.Forms.Label labelPlotColor;
        private System.Windows.Forms.PictureBox pbPlotColor;
        private System.Windows.Forms.NumericUpDown XStart;
        private System.Windows.Forms.NumericUpDown XEnd;
        private System.Windows.Forms.NumericUpDown XStep;
        private System.Windows.Forms.GroupBox groupX;
        private System.Windows.Forms.Label labelXStart;
        private System.Windows.Forms.Label labelXStep;
        private System.Windows.Forms.Label labelXEnd;
        private System.Windows.Forms.GroupBox groupZ;
        private System.Windows.Forms.Label labelZStep;
        private System.Windows.Forms.Label labelZEnd;
        private System.Windows.Forms.Label labelZStart;
        private System.Windows.Forms.NumericUpDown ZEnd;
        private System.Windows.Forms.NumericUpDown ZStep;
        private System.Windows.Forms.NumericUpDown ZStart;
        private System.Windows.Forms.NumericUpDown RotateX;
        private System.Windows.Forms.NumericUpDown RotateY;
        private System.Windows.Forms.NumericUpDown RotateZ;
        private System.Windows.Forms.GroupBox groupRotate;
        private System.Windows.Forms.Label labelRotateZ;
        private System.Windows.Forms.Label labelRotateY;
        private System.Windows.Forms.Label labelRotateX;
        private System.Windows.Forms.GroupBox groupCurves;
        private System.Windows.Forms.CheckedListBox checkedListBoxFunctions;
        private System.Windows.Forms.Button btnDraw;
    }
}

