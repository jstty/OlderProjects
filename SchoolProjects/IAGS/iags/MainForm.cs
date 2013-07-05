using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace iags
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();

            yearNum.Minimum = 1900;
            yearNum.Maximum = 3000;
            chooseBox.SelectedIndex = 0;

            sectionLink.Text = "";
            assignLink.Text = "";
        }

        private void Login(object sender, EventArgs e)
        {
            if (!Program.main.LoggedIn)
            {
                LoginForm login = new LoginForm();
                login.ShowDialog();

                if (Program.main.LoggedIn) {
                    loginMenu.Text = "Logout";
                }
            }
            else
            {
                Program.main.Logout();
                loginMenu.Text = "Login";
            }
        }

        private void exitClick(object sender, EventArgs e)
        {
            Close();
        }

        private void selectTable_IndexChanged(object sender, EventArgs e)
        {
            ComboBox bc = (ComboBox)sender;
            string s = bc.SelectedItem.ToString();

            Program.main.SwitchView(s);
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            selectTable.SelectedIndex = 0;
        }

        private void yearBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            char c = e.KeyChar;

            if( (c == '\b') ||
                ((c >= (int)'0') && (c <= (int)'9'))
                )
            {
                e.Handled = false;
            } else {
                e.Handled = true;
            }
        }

        private void semesterBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            ComboBox bc = (ComboBox)sender;
            string s = bc.SelectedItem.ToString();

            Program.main.CurrentSem = s;
        }

        private void yearBox_TextChanged(object sender, EventArgs e)
        {
            TextBox t = (TextBox)sender;

            if(t.Text.Length > 0)
                Program.main.CurrentYear = Convert.ToInt32(t.Text);
        }

        // -----------------------------------------
        // DataGrid Events

        // get data for current row, cell
        private void dataGrid_CellValueNeeded(object sender, DataGridViewCellValueEventArgs e)
        {
            Program.main.dataGrid_CellValueNeeded(e);
        }

        // write to current row, cell
        private void dataGrid_CellValuePushed(object sender, DataGridViewCellValueEventArgs e)
        {
            Program.main.dataGrid_CellValuePushed(e);
        }

        // on new row
        private void dataGrid_NewRowNeeded(object sender, DataGridViewRowEventArgs e)
        {
            try
            {
                Program.main.dataGrid_NewRowNeeded(e);
            }
            catch (Exception exp)
            {
                string err = exp.Message; // error
            }
        }

        // cancel row edit
        private void dataGrid_CancelRowEdit(object sender, QuestionEventArgs e)
        {  
            Program.main.dataGrid_CancelRowEdit(e);
        }

        // delete row
        private void dataGrid_UserDeletingRow(object sender, DataGridViewRowCancelEventArgs e)
        {
            try
            {
                Program.main.dataGrid_UserDeletingRow(e);
                e.Cancel = false;
            }
            catch (Exception exp)
            {
                string err = exp.Message; // error
                // on error don't apply change
                e.Cancel = true;
            }
        }

        // on new row selection
        private void dataGrid_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            if (dataGrid.Rows.Count > e.RowIndex)
            {
                Program.main.RowChanged(e.RowIndex);
            }
        }

        // check row, if valid then done editing, othewise stop
        private void dataGrid_RowValidating(object sender, DataGridViewCellCancelEventArgs e)
        {
            try
            {
                Program.main.dataGrid_RowValidating(e);
                e.Cancel = false;
            }
            catch (Exception exp)
            {
                string err = exp.Message; // error
                e.Cancel = true;
            }
        }

        // after adding a row, auto resize if content to big for cell
        private void dataGrid_RowsAdded(object sender, DataGridViewRowsAddedEventArgs e)
        {
            dataGrid.AutoResizeRows();
        }

        // -----------------------------------------       


        private void aboutMenuItem_Click(object sender, EventArgs e)
        {
            AboutForm about = new AboutForm();
            about.ShowDialog();
        }

        private void pDFHelpDocumentMenuItem_Click(object sender, EventArgs e)
        {
            string doc = "pdf/help.pdf";
            // simple execute this document using the default application
            if (System.Diagnostics.Process.Start(doc) == null)
            {
                MessageBox.Show(string.Format("Unable to execute \"{0}\".\n"+
                                              "You need a PDF viewer to display this document.",
                                              doc)
                                              , "Error");
            }
        }

        private void yearNum_ValueChanged(object sender, EventArgs e)
        {
            NumericUpDown n = (NumericUpDown)sender;
            
            if (n.Value > 0)
                Program.main.CurrentYear = (int)n.Value;
        }


        private void createDBMenu_Click(object sender, EventArgs e)
        {
            Program.main.CreateAll();
        }

        private void importDataMenu_Click(object sender, EventArgs e)
        {
            Program.main.LoadAll();
        }

        private void exportDB_Click(object sender, EventArgs e)
        {
            Program.main.SaveAll();
        }

        private void sectionButton_Click(object sender, EventArgs e)
        {
            Program.main.NextState();
        }

        private void assignButton_Click(object sender, EventArgs e)
        {
            Program.main.NextState();
        }

        private void sectionLink_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Program.main.SelectSection();
        }

        private void assignLink_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Program.main.SelectAssignment();
        }

        public void ShowState(int level, int state)
        {
            // the boolean is used so the control is only set once,
            // this prevent flashing.
            bool[] b = new bool[19];
            // 0 - importDBMenu.Visible
            // 1 - exportDBMenu.Visible
            // 2 - createDBMenu.Visible
            // 3 - selectTable.Visible
            
            // 4 - yearLabel.Visible
            // 5 - yearNum.Visible
            // 6 - yearNum.Enabled
            // 7 - semesterLabel.Visible
            // 8 - semesterBox.Visible
            // 9 - semesterBox.Enabled

            // 10 - sectionLink.Visible
            // 11 - section_selectButton.Visible
            // 12 - section_selectButton.Enabled
            // 13 - chooseBox.Visible
            // 14 - assignLink.Visible
            // 15 - assign_selectButton.Visible
            // 16 - assign_selectButton.Enabled

            // 17 - addStudentsMenuItem.Visible
            // 18 - reportButton.Visible


            // student, instructor
            if ((level == 0) || (level == 1))
            {
                b[4] = true;  //yearLabel.Visible = true;
                b[5] = true;  //yearNum.Visible = true;
                b[6] = false; //yearNum.Enabled = false;

                b[7] = true;  //semesterLabel.Visible = true;
                b[8] = true;  //semesterBox.Visible = true;
                b[9] = false; //semesterBox.Enabled = false;

                b[10] = true; //sectionLink.Visible = true;

                if (state == 0)
                {
                    b[11] = true; //section_selectButton.Visible = true;

                    if (sectionLink.Text.Length > 1)
                        b[12] = true; //section_selectButton.Enabled = true;
                    else
                        b[12] = false; //section_selectButton.Enabled = false;

                    b[6] = true; //yearNum.Enabled = true;
                    b[9] = true; //semesterBox.Enabled = true;
                }
                else if (state == 1)
                {
                    b[13] = true; //chooseBox.Visible = true;
                    b[18] = true; //reportButton.Visible = true;
                }
                else if (state == 2)
                {
                    b[13] = true;  //chooseBox.Visible = true;
                    b[14] = true;  //assignLink.Visible = true;
                    b[15] = true;  //assign_selectButton.Visible = true;
                    b[18] = true; //reportButton.Visible = true;

                    if (assignLink.Text.Length > 1)
                        b[16] = true; //assign_selectButton.Enabled = true;
                    else
                        b[16] = false; //assign_selectButton.Enabled = false;
                }
                else if (state == 3)
                {
                    b[13] = true; //chooseBox.Visible = true;
                    b[14] = true; //assignLink.Visible = true;
                    b[18] = true; //reportButton.Visible = true;
                }
            }
            // admin
            else if (level == 2)
            {
                b[0] = true; //importDBMenu.Enabled = true;
                b[1] = true; //exportDBMenu.Enabled = true;
                b[2] = true; //createDBMenu.Enabled = true;
                b[3] = true; //selectTable.Visible = true;
                //b[17] = true; //addStudentsMenuItem.Visible = true;
            }

            addStudentsMenuItem.Visible = b[17];
            menuSeparator1.Visible = b[17];

            importDBMenu.Visible = b[0];
            exportDBMenu.Visible = b[1];
            createDBMenu.Visible = b[2];
            menuSeparator2.Visible = b[0] | b[1] | b[2];

            selectTable.Visible = b[3];

            yearLabel.Visible = b[4];
            yearNum.Visible = b[5];
            yearNum.Enabled = b[6];
            semesterLabel.Visible = b[7];
            semesterBox.Visible = b[8];
            semesterBox.Enabled = b[9];

            sectionLink.Visible = b[10];
            section_selectButton.Visible = b[11];
            section_selectButton.Enabled = b[12];
            chooseBox.Visible = b[13];
            assignLink.Visible = b[14];
            assign_selectButton.Visible = b[15];
            assign_selectButton.Enabled = b[16];

            reportButton.Visible = b[18];
        }

        // enable or disable all controls
        public void EnableAll(bool enable)
        {
            menuMain.Enabled = enable;
            dataGrid.Enabled = enable;
            selectTable.Enabled = enable;

            semesterLabel.Enabled = enable;
            semesterBox.Enabled = enable;

            yearLabel.Enabled = enable;
            yearNum.Enabled = enable;

            sectionLink.Enabled = enable;
            section_selectButton.Enabled = enable;
            chooseBox.Enabled = enable;
            assignLink.Enabled = enable;
            assign_selectButton.Enabled = enable;
        }

        private void chooseBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            ComboBox cb = (ComboBox)sender;

            // only if visable
            if (cb.Visible)
            {
                if (cb.SelectedIndex == 0)
                {
                    Program.main.SelectSignup();
                }
                else
                {
                    Program.main.SelectAssignment();
                }
            }
        }

        private void dataGrid_DataError(object sender, DataGridViewDataErrorEventArgs e)
        {
            // ignore errors, handled else were
            // there is a particular bug, when selecting a cell with a combobox then clearing all rows
            // it causes and error
        }

        private void addStudentsMenuItem_Click(object sender, EventArgs e)
        {
            Program.main.AddStudentsFile();
        }

        private void reportButton_Click(object sender, EventArgs e)
        {
            Program.main.PopupReport();
        }

    }
}