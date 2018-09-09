namespace SearchOfExit
{
    partial class Menu
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Menu));
            this.EnterL = new System.Windows.Forms.Button();
            this.ExitL = new System.Windows.Forms.Button();
            this.InstructionsL = new System.Windows.Forms.Button();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // EnterL
            // 
            this.EnterL.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.EnterL.BackColor = System.Drawing.SystemColors.Control;
            this.EnterL.Cursor = System.Windows.Forms.Cursors.Hand;
            this.EnterL.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.EnterL.Location = new System.Drawing.Point(200, 40);
            this.EnterL.Margin = new System.Windows.Forms.Padding(200, 40, 200, 40);
            this.EnterL.Name = "EnterL";
            this.EnterL.Size = new System.Drawing.Size(135, 46);
            this.EnterL.TabIndex = 0;
            this.EnterL.Text = "Ввести лабіринт";
            this.EnterL.UseVisualStyleBackColor = false;
            this.EnterL.Click += new System.EventHandler(this.EnterL_Click);
            // 
            // ExitL
            // 
            this.ExitL.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.ExitL.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ExitL.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ExitL.Location = new System.Drawing.Point(200, 292);
            this.ExitL.Margin = new System.Windows.Forms.Padding(200, 40, 200, 40);
            this.ExitL.Name = "ExitL";
            this.ExitL.Size = new System.Drawing.Size(135, 48);
            this.ExitL.TabIndex = 2;
            this.ExitL.Text = "Вихід";
            this.ExitL.UseVisualStyleBackColor = true;
            this.ExitL.Click += new System.EventHandler(this.ExitL_Click);
            // 
            // InstructionsL
            // 
            this.InstructionsL.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.InstructionsL.Cursor = System.Windows.Forms.Cursors.Hand;
            this.InstructionsL.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.InstructionsL.Location = new System.Drawing.Point(200, 166);
            this.InstructionsL.Margin = new System.Windows.Forms.Padding(200, 40, 200, 40);
            this.InstructionsL.Name = "InstructionsL";
            this.InstructionsL.Size = new System.Drawing.Size(135, 46);
            this.InstructionsL.TabIndex = 3;
            this.InstructionsL.Text = "Інструкції";
            this.InstructionsL.UseVisualStyleBackColor = true;
            this.InstructionsL.Click += new System.EventHandler(this.InstructionsL_Click);
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.BackColor = System.Drawing.Color.Transparent;
            this.tableLayoutPanel1.ColumnCount = 1;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.Controls.Add(this.InstructionsL, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.ExitL, 0, 2);
            this.tableLayoutPanel1.Controls.Add(this.EnterL, 0, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 3;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(535, 380);
            this.tableLayoutPanel1.TabIndex = 4;
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // Menu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(535, 380);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Menu";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Пошук найкоротшого виходу з лабіринту";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button EnterL;
        private System.Windows.Forms.Button ExitL;
        private System.Windows.Forms.Button InstructionsL;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
    }
}

