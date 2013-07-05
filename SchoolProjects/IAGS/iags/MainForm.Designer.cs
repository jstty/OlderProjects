using System;

namespace iags
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

            try
            {
                base.Dispose(disposing);
            }
            catch (Exception exp)
            {
                string st = exp.StackTrace;
            }
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.menuMain = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.addStudentsMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.importDBMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.exportDBMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.createDBMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.menuSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.exit = new System.Windows.Forms.ToolStripMenuItem();
            this.loginMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pDFHelpDocumentMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.aboutMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dataGrid = new System.Windows.Forms.DataGridView();
            this.progressPerc = new System.Windows.Forms.ProgressBar();
            this.progressText = new System.Windows.Forms.TextBox();
            this.selectTable = new System.Windows.Forms.ComboBox();
            this.semesterBox = new System.Windows.Forms.ComboBox();
            this.semesterLabel = new System.Windows.Forms.Label();
            this.yearLabel = new System.Windows.Forms.Label();
            this.titleBox = new System.Windows.Forms.TextBox();
            this.section_selectButton = new System.Windows.Forms.Button();
            this.sectionLink = new System.Windows.Forms.LinkLabel();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.reportButton = new System.Windows.Forms.Button();
            this.assign_selectButton = new System.Windows.Forms.Button();
            this.assignLink = new System.Windows.Forms.LinkLabel();
            this.chooseBox = new System.Windows.Forms.ComboBox();
            this.yearNum = new System.Windows.Forms.NumericUpDown();
            this.menuMain.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGrid)).BeginInit();
            this.tableLayoutPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.yearNum)).BeginInit();
            this.SuspendLayout();
            // 
            // menuMain
            // 
            this.menuMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.loginMenu,
            this.helpToolStripMenuItem});
            this.menuMain.Location = new System.Drawing.Point(0, 0);
            this.menuMain.Name = "menuMain";
            this.menuMain.Size = new System.Drawing.Size(655, 24);
            this.menuMain.TabIndex = 0;
            this.menuMain.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addStudentsMenuItem,
            this.menuSeparator1,
            this.importDBMenu,
            this.exportDBMenu,
            this.createDBMenu,
            this.menuSeparator2,
            this.exit});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(35, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // addStudentsMenuItem
            // 
            this.addStudentsMenuItem.Name = "addStudentsMenuItem";
            this.addStudentsMenuItem.Size = new System.Drawing.Size(234, 22);
            this.addStudentsMenuItem.Text = "Add/Sign-up Students from File";
            this.addStudentsMenuItem.Click += new System.EventHandler(this.addStudentsMenuItem_Click);
            // 
            // menuSeparator1
            // 
            this.menuSeparator1.Name = "menuSeparator1";
            this.menuSeparator1.Size = new System.Drawing.Size(231, 6);
            // 
            // importDBMenu
            // 
            this.importDBMenu.Name = "importDBMenu";
            this.importDBMenu.Size = new System.Drawing.Size(234, 22);
            this.importDBMenu.Text = "Import into DB";
            this.importDBMenu.Click += new System.EventHandler(this.importDataMenu_Click);
            // 
            // exportDBMenu
            // 
            this.exportDBMenu.Name = "exportDBMenu";
            this.exportDBMenu.Size = new System.Drawing.Size(234, 22);
            this.exportDBMenu.Text = "Export All Data from DB";
            this.exportDBMenu.Click += new System.EventHandler(this.exportDB_Click);
            // 
            // createDBMenu
            // 
            this.createDBMenu.Name = "createDBMenu";
            this.createDBMenu.Size = new System.Drawing.Size(234, 22);
            this.createDBMenu.Text = "Create DB Schema";
            this.createDBMenu.Click += new System.EventHandler(this.createDBMenu_Click);
            // 
            // menuSeparator2
            // 
            this.menuSeparator2.Name = "menuSeparator2";
            this.menuSeparator2.Size = new System.Drawing.Size(231, 6);
            // 
            // exit
            // 
            this.exit.Name = "exit";
            this.exit.Size = new System.Drawing.Size(234, 22);
            this.exit.Text = "Exit";
            this.exit.Click += new System.EventHandler(this.exitClick);
            // 
            // loginMenu
            // 
            this.loginMenu.Name = "loginMenu";
            this.loginMenu.Size = new System.Drawing.Size(44, 20);
            this.loginMenu.Text = "Login";
            this.loginMenu.Click += new System.EventHandler(this.Login);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.pDFHelpDocumentMenuItem,
            this.toolStripSeparator1,
            this.aboutMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(40, 20);
            this.helpToolStripMenuItem.Text = "Help";
            this.helpToolStripMenuItem.TextDirection = System.Windows.Forms.ToolStripTextDirection.Horizontal;
            // 
            // pDFHelpDocumentMenuItem
            // 
            this.pDFHelpDocumentMenuItem.Name = "pDFHelpDocumentMenuItem";
            this.pDFHelpDocumentMenuItem.Size = new System.Drawing.Size(179, 22);
            this.pDFHelpDocumentMenuItem.Text = "PDF Help Document";
            this.pDFHelpDocumentMenuItem.Click += new System.EventHandler(this.pDFHelpDocumentMenuItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(176, 6);
            // 
            // aboutMenuItem
            // 
            this.aboutMenuItem.Name = "aboutMenuItem";
            this.aboutMenuItem.Size = new System.Drawing.Size(179, 22);
            this.aboutMenuItem.Text = "About";
            this.aboutMenuItem.Click += new System.EventHandler(this.aboutMenuItem_Click);
            // 
            // dataGrid
            // 
            this.dataGrid.AllowUserToOrderColumns = true;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.TopLeft;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGrid.AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
            this.dataGrid.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.dataGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGrid.Location = new System.Drawing.Point(0, 80);
            this.dataGrid.Margin = new System.Windows.Forms.Padding(3, 3, 3, 0);
            this.dataGrid.Name = "dataGrid";
            this.dataGrid.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.AutoSizeToAllHeaders;
            dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.TopLeft;
            dataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGrid.RowsDefaultCellStyle = dataGridViewCellStyle2;
            this.dataGrid.RowTemplate.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGrid.Size = new System.Drawing.Size(655, 393);
            this.dataGrid.TabIndex = 1;
            this.dataGrid.VirtualMode = true;
            this.dataGrid.UserDeletingRow += new System.Windows.Forms.DataGridViewRowCancelEventHandler(this.dataGrid_UserDeletingRow);
            this.dataGrid.RowValidating += new System.Windows.Forms.DataGridViewCellCancelEventHandler(this.dataGrid_RowValidating);
            this.dataGrid.RowEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGrid_RowEnter);
            this.dataGrid.CancelRowEdit += new System.Windows.Forms.QuestionEventHandler(this.dataGrid_CancelRowEdit);
            this.dataGrid.CellValueNeeded += new System.Windows.Forms.DataGridViewCellValueEventHandler(this.dataGrid_CellValueNeeded);
            this.dataGrid.RowsAdded += new System.Windows.Forms.DataGridViewRowsAddedEventHandler(this.dataGrid_RowsAdded);
            this.dataGrid.DataError += new System.Windows.Forms.DataGridViewDataErrorEventHandler(this.dataGrid_DataError);
            this.dataGrid.CellValuePushed += new System.Windows.Forms.DataGridViewCellValueEventHandler(this.dataGrid_CellValuePushed);
            this.dataGrid.NewRowNeeded += new System.Windows.Forms.DataGridViewRowEventHandler(this.dataGrid_NewRowNeeded);
            // 
            // progressPerc
            // 
            this.progressPerc.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.progressPerc.Location = new System.Drawing.Point(534, 476);
            this.progressPerc.Margin = new System.Windows.Forms.Padding(3, 1, 3, 3);
            this.progressPerc.Name = "progressPerc";
            this.progressPerc.Size = new System.Drawing.Size(121, 21);
            this.progressPerc.Step = 1;
            this.progressPerc.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            this.progressPerc.TabIndex = 6;
            // 
            // progressText
            // 
            this.progressText.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.progressText.BackColor = System.Drawing.SystemColors.Control;
            this.progressText.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.progressText.Location = new System.Drawing.Point(0, 476);
            this.progressText.Margin = new System.Windows.Forms.Padding(3, 1, 1, 3);
            this.progressText.Name = "progressText";
            this.progressText.ReadOnly = true;
            this.progressText.Size = new System.Drawing.Size(530, 20);
            this.progressText.TabIndex = 7;
            // 
            // selectTable
            // 
            this.selectTable.DropDownHeight = 200;
            this.selectTable.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.selectTable.FormattingEnabled = true;
            this.selectTable.IntegralHeight = false;
            this.selectTable.ItemHeight = 13;
            this.selectTable.Items.AddRange(new object[] {
            "Select Table",
            "-----------------------",
            "Course Info.",
            "Person",
            "Instructor",
            "Section",
            "Sign-up",
            "Assignment",
            "Grade"});
            this.selectTable.Location = new System.Drawing.Point(2, 31);
            this.selectTable.Name = "selectTable";
            this.selectTable.Size = new System.Drawing.Size(121, 21);
            this.selectTable.TabIndex = 8;
            this.selectTable.SelectedIndexChanged += new System.EventHandler(this.selectTable_IndexChanged);
            // 
            // semesterBox
            // 
            this.semesterBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.semesterBox.FormattingEnabled = true;
            this.semesterBox.Items.AddRange(new object[] {
            "Fall",
            "Winter",
            "Spring",
            "Summer"});
            this.semesterBox.Location = new System.Drawing.Point(135, 30);
            this.semesterBox.Name = "semesterBox";
            this.semesterBox.Size = new System.Drawing.Size(62, 21);
            this.semesterBox.TabIndex = 9;
            this.semesterBox.SelectedIndexChanged += new System.EventHandler(this.semesterBox_SelectedIndexChanged);
            // 
            // semesterLabel
            // 
            this.semesterLabel.AutoSize = true;
            this.semesterLabel.Location = new System.Drawing.Point(91, 34);
            this.semesterLabel.Name = "semesterLabel";
            this.semesterLabel.Size = new System.Drawing.Size(42, 13);
            this.semesterLabel.TabIndex = 10;
            this.semesterLabel.Text = "Quarter";
            // 
            // yearLabel
            // 
            this.yearLabel.AutoSize = true;
            this.yearLabel.Location = new System.Drawing.Point(0, 34);
            this.yearLabel.Name = "yearLabel";
            this.yearLabel.Size = new System.Drawing.Size(29, 13);
            this.yearLabel.TabIndex = 11;
            this.yearLabel.Text = "Year";
            // 
            // titleBox
            // 
            this.titleBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.titleBox.BackColor = System.Drawing.Color.White;
            this.titleBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.titleBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.titleBox.ForeColor = System.Drawing.Color.DarkBlue;
            this.titleBox.Location = new System.Drawing.Point(0, 56);
            this.titleBox.Name = "titleBox";
            this.titleBox.ReadOnly = true;
            this.titleBox.Size = new System.Drawing.Size(655, 22);
            this.titleBox.TabIndex = 13;
            this.titleBox.TabStop = false;
            // 
            // section_selectButton
            // 
            this.section_selectButton.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.section_selectButton.BackColor = System.Drawing.Color.LightGray;
            this.section_selectButton.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.section_selectButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.White;
            this.section_selectButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Gainsboro;
            this.section_selectButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.section_selectButton.Font = new System.Drawing.Font("Arial", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.section_selectButton.ForeColor = System.Drawing.Color.Blue;
            this.section_selectButton.Location = new System.Drawing.Point(82, 0);
            this.section_selectButton.Margin = new System.Windows.Forms.Padding(0);
            this.section_selectButton.Name = "section_selectButton";
            this.section_selectButton.Size = new System.Drawing.Size(38, 23);
            this.section_selectButton.TabIndex = 14;
            this.section_selectButton.Text = ">>>";
            this.section_selectButton.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.section_selectButton.TextImageRelation = System.Windows.Forms.TextImageRelation.TextAboveImage;
            this.section_selectButton.UseVisualStyleBackColor = false;
            this.section_selectButton.Click += new System.EventHandler(this.sectionButton_Click);
            // 
            // sectionLink
            // 
            this.sectionLink.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.sectionLink.AutoSize = true;
            this.sectionLink.Location = new System.Drawing.Point(3, 5);
            this.sectionLink.Name = "sectionLink";
            this.sectionLink.Padding = new System.Windows.Forms.Padding(5, 0, 0, 0);
            this.sectionLink.Size = new System.Drawing.Size(76, 13);
            this.sectionLink.TabIndex = 15;
            this.sectionLink.TabStop = true;
            this.sectionLink.Text = "Course Name";
            this.sectionLink.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.sectionLink_LinkClicked);
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.tableLayoutPanel1.ColumnCount = 6;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 124F));
            this.tableLayoutPanel1.Controls.Add(this.reportButton, 5, 0);
            this.tableLayoutPanel1.Controls.Add(this.sectionLink, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.section_selectButton, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.assign_selectButton, 4, 0);
            this.tableLayoutPanel1.Controls.Add(this.assignLink, 3, 0);
            this.tableLayoutPanel1.Controls.Add(this.chooseBox, 2, 0);
            this.tableLayoutPanel1.ForeColor = System.Drawing.SystemColors.WindowText;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(200, 29);
            this.tableLayoutPanel1.Margin = new System.Windows.Forms.Padding(0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 1;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel1.Size = new System.Drawing.Size(455, 23);
            this.tableLayoutPanel1.TabIndex = 17;
            this.tableLayoutPanel1.TabStop = true;
            // 
            // reportButton
            // 
            this.reportButton.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.reportButton.BackColor = System.Drawing.Color.LightGray;
            this.reportButton.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.reportButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.White;
            this.reportButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Gainsboro;
            this.reportButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.reportButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.reportButton.Location = new System.Drawing.Point(349, 0);
            this.reportButton.Margin = new System.Windows.Forms.Padding(0);
            this.reportButton.Name = "reportButton";
            this.reportButton.Size = new System.Drawing.Size(106, 23);
            this.reportButton.TabIndex = 19;
            this.reportButton.Text = "Final Grade Report";
            this.reportButton.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.reportButton.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.reportButton.UseVisualStyleBackColor = false;
            this.reportButton.Click += new System.EventHandler(this.reportButton_Click);
            // 
            // assign_selectButton
            // 
            this.assign_selectButton.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.assign_selectButton.BackColor = System.Drawing.Color.LightGray;
            this.assign_selectButton.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.assign_selectButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.White;
            this.assign_selectButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Gainsboro;
            this.assign_selectButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.assign_selectButton.Font = new System.Drawing.Font("Arial", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.assign_selectButton.ForeColor = System.Drawing.Color.Blue;
            this.assign_selectButton.Location = new System.Drawing.Point(293, 0);
            this.assign_selectButton.Margin = new System.Windows.Forms.Padding(0);
            this.assign_selectButton.Name = "assign_selectButton";
            this.assign_selectButton.Size = new System.Drawing.Size(38, 23);
            this.assign_selectButton.TabIndex = 17;
            this.assign_selectButton.Text = ">>>";
            this.assign_selectButton.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.assign_selectButton.TextImageRelation = System.Windows.Forms.TextImageRelation.TextAboveImage;
            this.assign_selectButton.UseVisualStyleBackColor = false;
            this.assign_selectButton.Click += new System.EventHandler(this.assignButton_Click);
            // 
            // assignLink
            // 
            this.assignLink.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.assignLink.AutoSize = true;
            this.assignLink.Location = new System.Drawing.Point(224, 5);
            this.assignLink.Name = "assignLink";
            this.assignLink.Padding = new System.Windows.Forms.Padding(5, 0, 0, 0);
            this.assignLink.Size = new System.Drawing.Size(66, 13);
            this.assignLink.TabIndex = 16;
            this.assignLink.TabStop = true;
            this.assignLink.Text = "Assignment";
            this.assignLink.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.assignLink_LinkClicked);
            // 
            // chooseBox
            // 
            this.chooseBox.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.chooseBox.DropDownHeight = 200;
            this.chooseBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.chooseBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chooseBox.FormattingEnabled = true;
            this.chooseBox.IntegralHeight = false;
            this.chooseBox.Items.AddRange(new object[] {
            "Final Grades",
            "Assignments"});
            this.chooseBox.Location = new System.Drawing.Point(130, 1);
            this.chooseBox.Margin = new System.Windows.Forms.Padding(10, 0, 5, 0);
            this.chooseBox.Name = "chooseBox";
            this.chooseBox.Size = new System.Drawing.Size(86, 21);
            this.chooseBox.TabIndex = 18;
            this.chooseBox.SelectedIndexChanged += new System.EventHandler(this.chooseBox_SelectedIndexChanged);
            // 
            // yearNum
            // 
            this.yearNum.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.yearNum.Location = new System.Drawing.Point(31, 31);
            this.yearNum.Name = "yearNum";
            this.yearNum.Size = new System.Drawing.Size(47, 20);
            this.yearNum.TabIndex = 18;
            this.yearNum.ValueChanged += new System.EventHandler(this.yearNum_ValueChanged);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(655, 497);
            this.Controls.Add(this.yearNum);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Controls.Add(this.titleBox);
            this.Controls.Add(this.yearLabel);
            this.Controls.Add(this.semesterLabel);
            this.Controls.Add(this.semesterBox);
            this.Controls.Add(this.selectTable);
            this.Controls.Add(this.progressText);
            this.Controls.Add(this.progressPerc);
            this.Controls.Add(this.dataGrid);
            this.Controls.Add(this.menuMain);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuMain;
            this.Name = "MainForm";
            this.Text = "IAGS - Instructor Assistant Grading System";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.menuMain.ResumeLayout(false);
            this.menuMain.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGrid)).EndInit();
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.yearNum)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.MenuStrip menuMain;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem importDBMenu;
        private System.Windows.Forms.ToolStripSeparator menuSeparator1;
        private System.Windows.Forms.ToolStripMenuItem exit;
        public System.Windows.Forms.DataGridView dataGrid;
        private System.Windows.Forms.ToolStripMenuItem loginMenu;
        public System.Windows.Forms.ProgressBar progressPerc;
        public System.Windows.Forms.TextBox progressText;
        public System.Windows.Forms.ComboBox selectTable;
        public System.Windows.Forms.ComboBox semesterBox;
        public System.Windows.Forms.Label semesterLabel;
        public System.Windows.Forms.Label yearLabel;
        private System.Windows.Forms.ToolStripMenuItem exportDBMenu;
        public System.Windows.Forms.TextBox titleBox;
        public System.Windows.Forms.Button section_selectButton;
        public System.Windows.Forms.LinkLabel sectionLink;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        public System.Windows.Forms.LinkLabel assignLink;
        public System.Windows.Forms.Button assign_selectButton;
        public System.Windows.Forms.ComboBox chooseBox;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem pDFHelpDocumentMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem aboutMenuItem;
        public System.Windows.Forms.NumericUpDown yearNum;
        private System.Windows.Forms.ToolStripMenuItem createDBMenu;
        private System.Windows.Forms.ToolStripMenuItem addStudentsMenuItem;
        private System.Windows.Forms.ToolStripSeparator menuSeparator2;
        private System.Windows.Forms.Button reportButton;
    }
}

