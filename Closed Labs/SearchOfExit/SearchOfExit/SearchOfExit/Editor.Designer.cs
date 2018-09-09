namespace SearchOfExit
{
    partial class Editor
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Editor));
            this.EditorBackBtn = new System.Windows.Forms.Button();
            this.SaveMazeBtn = new System.Windows.Forms.Button();
            this.SolveBtn = new System.Windows.Forms.Button();
            this.delRoomBtn = new System.Windows.Forms.Button();
            this.ExportBtn = new System.Windows.Forms.Button();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.ShowGridCheck = new System.Windows.Forms.CheckBox();
            this.ImportBtn = new System.Windows.Forms.Button();
            this.AddRoomBtn = new System.Windows.Forms.Button();
            this.LoadMazeBtn = new System.Windows.Forms.Button();
            this.mazeControl1 = new SearchOfExit.MazeControl();
            this.tableLayoutPanel1.SuspendLayout();
            this.flowLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // EditorBackBtn
            // 
            this.EditorBackBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.EditorBackBtn.Location = new System.Drawing.Point(5, 357);
            this.EditorBackBtn.Margin = new System.Windows.Forms.Padding(5);
            this.EditorBackBtn.Name = "EditorBackBtn";
            this.EditorBackBtn.Size = new System.Drawing.Size(100, 35);
            this.EditorBackBtn.TabIndex = 0;
            this.EditorBackBtn.Text = "Назад";
            this.EditorBackBtn.UseVisualStyleBackColor = true;
            this.EditorBackBtn.Click += new System.EventHandler(this.EditorBackBtn_Click);
            // 
            // SaveMazeBtn
            // 
            this.SaveMazeBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.SaveMazeBtn.Location = new System.Drawing.Point(5, 312);
            this.SaveMazeBtn.Margin = new System.Windows.Forms.Padding(5);
            this.SaveMazeBtn.Name = "SaveMazeBtn";
            this.SaveMazeBtn.Size = new System.Drawing.Size(100, 35);
            this.SaveMazeBtn.TabIndex = 1;
            this.SaveMazeBtn.Text = "Зберегти лабіринт";
            this.SaveMazeBtn.UseVisualStyleBackColor = true;
            // 
            // SolveBtn
            // 
            this.SolveBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.SolveBtn.Location = new System.Drawing.Point(5, 222);
            this.SolveBtn.Margin = new System.Windows.Forms.Padding(5);
            this.SolveBtn.Name = "SolveBtn";
            this.SolveBtn.Size = new System.Drawing.Size(100, 35);
            this.SolveBtn.TabIndex = 2;
            this.SolveBtn.Text = "Рішення";
            this.SolveBtn.UseVisualStyleBackColor = true;
            // 
            // delRoomBtn
            // 
            this.delRoomBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.delRoomBtn.Location = new System.Drawing.Point(5, 132);
            this.delRoomBtn.Margin = new System.Windows.Forms.Padding(5);
            this.delRoomBtn.Name = "delRoomBtn";
            this.delRoomBtn.Size = new System.Drawing.Size(100, 35);
            this.delRoomBtn.TabIndex = 4;
            this.delRoomBtn.Text = "Видалити кімнату";
            this.delRoomBtn.UseVisualStyleBackColor = true;
            // 
            // ExportBtn
            // 
            this.ExportBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ExportBtn.Location = new System.Drawing.Point(5, 42);
            this.ExportBtn.Margin = new System.Windows.Forms.Padding(5);
            this.ExportBtn.Name = "ExportBtn";
            this.ExportBtn.Size = new System.Drawing.Size(100, 35);
            this.ExportBtn.TabIndex = 3;
            this.ExportBtn.Text = "Експорт";
            this.ExportBtn.UseVisualStyleBackColor = true;
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 21.13677F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 78.86324F));
            this.tableLayoutPanel1.Controls.Add(this.flowLayoutPanel1, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.mazeControl1, 1, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 1;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(606, 497);
            this.tableLayoutPanel1.TabIndex = 3;
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Controls.Add(this.ShowGridCheck);
            this.flowLayoutPanel1.Controls.Add(this.ExportBtn);
            this.flowLayoutPanel1.Controls.Add(this.ImportBtn);
            this.flowLayoutPanel1.Controls.Add(this.delRoomBtn);
            this.flowLayoutPanel1.Controls.Add(this.AddRoomBtn);
            this.flowLayoutPanel1.Controls.Add(this.SolveBtn);
            this.flowLayoutPanel1.Controls.Add(this.LoadMazeBtn);
            this.flowLayoutPanel1.Controls.Add(this.SaveMazeBtn);
            this.flowLayoutPanel1.Controls.Add(this.EditorBackBtn);
            this.flowLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.flowLayoutPanel1.FlowDirection = System.Windows.Forms.FlowDirection.TopDown;
            this.flowLayoutPanel1.Location = new System.Drawing.Point(3, 3);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(122, 491);
            this.flowLayoutPanel1.TabIndex = 0;
            // 
            // ShowGridCheck
            // 
            this.ShowGridCheck.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.ShowGridCheck.AutoSize = true;
            this.ShowGridCheck.Checked = true;
            this.ShowGridCheck.CheckState = System.Windows.Forms.CheckState.Checked;
            this.ShowGridCheck.Location = new System.Drawing.Point(10, 10);
            this.ShowGridCheck.Margin = new System.Windows.Forms.Padding(10);
            this.ShowGridCheck.Name = "ShowGridCheck";
            this.ShowGridCheck.Size = new System.Drawing.Size(102, 17);
            this.ShowGridCheck.TabIndex = 9;
            this.ShowGridCheck.Text = "Показати сітку";
            this.ShowGridCheck.UseVisualStyleBackColor = true;
            // 
            // ImportBtn
            // 
            this.ImportBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ImportBtn.Location = new System.Drawing.Point(5, 87);
            this.ImportBtn.Margin = new System.Windows.Forms.Padding(5);
            this.ImportBtn.Name = "ImportBtn";
            this.ImportBtn.Size = new System.Drawing.Size(100, 35);
            this.ImportBtn.TabIndex = 3;
            this.ImportBtn.Text = "Імпорт";
            this.ImportBtn.UseVisualStyleBackColor = true;
            // 
            // AddRoomBtn
            // 
            this.AddRoomBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.AddRoomBtn.Location = new System.Drawing.Point(5, 177);
            this.AddRoomBtn.Margin = new System.Windows.Forms.Padding(5);
            this.AddRoomBtn.Name = "AddRoomBtn";
            this.AddRoomBtn.Size = new System.Drawing.Size(100, 35);
            this.AddRoomBtn.TabIndex = 4;
            this.AddRoomBtn.Text = "Додати кімнату";
            this.AddRoomBtn.UseVisualStyleBackColor = true;
            // 
            // LoadMazeBtn
            // 
            this.LoadMazeBtn.Cursor = System.Windows.Forms.Cursors.Hand;
            this.LoadMazeBtn.Location = new System.Drawing.Point(5, 267);
            this.LoadMazeBtn.Margin = new System.Windows.Forms.Padding(5);
            this.LoadMazeBtn.Name = "LoadMazeBtn";
            this.LoadMazeBtn.Size = new System.Drawing.Size(100, 35);
            this.LoadMazeBtn.TabIndex = 0;
            this.LoadMazeBtn.Text = "Завантажити лабіринт";
            this.LoadMazeBtn.UseVisualStyleBackColor = true;
            // 
            // mazeControl1
            // 
            this.mazeControl1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.mazeControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.mazeControl1.Location = new System.Drawing.Point(131, 3);
            this.mazeControl1.Name = "mazeControl1";
            this.mazeControl1.Padding = new System.Windows.Forms.Padding(10);
            this.mazeControl1.Size = new System.Drawing.Size(472, 491);
            this.mazeControl1.TabIndex = 1;
            // 
            // Editor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(606, 497);
            this.ControlBox = false;
            this.Controls.Add(this.tableLayoutPanel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Editor";
            this.Text = "Введення лабіринту";
            this.tableLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button EditorBackBtn;
        private System.Windows.Forms.Button delRoomBtn;
        private System.Windows.Forms.Button SaveMazeBtn;
        private System.Windows.Forms.Button SolveBtn;
        private System.Windows.Forms.Button ExportBtn;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private MazeControl mazeControl1;
        private System.Windows.Forms.Button LoadMazeBtn;
        private System.Windows.Forms.CheckBox ShowGridCheck;
        private System.Windows.Forms.Button ImportBtn;
        private System.Windows.Forms.Button AddRoomBtn;
    }
}