/*
 * Copyright (c) 2006, Joseph E. Sutton
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, 
 * with or without modification, are permitted provided 
 * that the following conditions are met:
 * 
 *  * Redistributions of source code must retain the above 
 *    copyright notice, this list of conditions and the 
 *    following disclaimer.
 *  * Redistributions in binary form must reproduce the above 
 *    copyright notice, this list of conditions and the 
 *    following disclaimer in the documentation and/or other 
 *    materials provided with the distribution.
 *  * Neither the name of the PolyFaust nor the names of its 
 *    contributors may be used to endorse or promote products 
 *    derived from this software without specific prior written 
 *    permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR 
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * */

using System;
using System.Threading;
using System.Windows.Forms;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    public delegate void ProgEventHandler(object sender, cProgArgs args);
    public delegate void ControlsEventHandler(object sender, cControlsArgs args);

    class cIAGS
    {
        /// <summary>
        /// Login ------>DBAdmin->ListAllTables(edit) 
        ///         -
        ///         ---->Instructor->Year/Season(view)->Section(view)->FinalGrade Signup(edit)
        ///         -                                                -
        ///         -                                                ->Assignment(edit)->Grades(edit)
        ///         -
        ///         ---->Student->Year/Season(view)->Section/FinalGrade(view)->Grades(view)
        /// </summary>

        private string default_dir = "";
        public static string ErrorMsg = "";
        public static bool DisplayError = true;
        // 0 - Student (view selected parts only)
        // 1 - Instructor (view/manage selected parts)
        // 2 - DB Admin (view/manage all tables)
        private static int      security_level = -2;
        // level 0
        //   0 - select section/signup
        //   3 - select grade
        // level 1
        //   0 - select section
        //   select signup or assignment
        //     1 - select signup
        //     2 - select assignment
        //       3 - select grade
        private static int sub_state = 0;

        // basic lists
        private cPersonList     person_list;
        private cCourseInfoList course_info_list;
        private cInstructorList inst_list;
        private cSectionList    section_list;
        private cAssignmentList assign_list;
        private cSignupList     signup_list;
        private cGradeList      grade_list;

        // views
        private cInstSectionView section_view;
        private cInstSignupView inst_signup_view;
        private cInstAssignView inst_assign_view;
        private cInstGradeView inst_grade_view;

        private cDBItemList current_view;
        private int current_id = -1; // student/instructor
        private cPerson current_login;
        private int current_sem = -1;
        private int current_year = 0;
        private cInstSectionViewRow current_section = null; // section row
        private cInstAssignViewRow current_assign = null; // assign id

        private MainForm main_form;

        private static cProgArgs prog_args;
        private static event ProgEventHandler UpdateProg;

        private TextBox      pt;
        private ProgressBar  pb;
        private MenuStrip    mm;
        private DataGridView dg;

        public cIAGS()
        {
            current_view     = null;
            person_list      = new cPersonList();
            course_info_list = new cCourseInfoList();
            inst_list        = new cInstructorList();
            section_list     = new cSectionList();
            assign_list      = new cAssignmentList();
            signup_list      = new cSignupList();
            grade_list       = new cGradeList();

            // view
            section_view = new cInstSectionView();
            inst_signup_view = new cInstSignupView();
            inst_assign_view = new cInstAssignView();
            inst_grade_view = new cInstGradeView();

            // self register for event
            prog_args = new cProgArgs();
            UpdateProg += new ProgEventHandler(UpdateProgHandler);

            default_dir = Directory.GetCurrentDirectory();
        }

        public int Init(MainForm f)
        {
            main_form = f;
            pt = main_form.progressText;
            pb = main_form.progressPerc;
            mm = main_form.menuMain;
            dg = main_form.dataGrid;
            Logout();

            // This is the DB connection switch, 
            // that should be set by a config file
            //cDB.Type = "MySQL";
            cDB.Type = "Oracle";

            course_info_list.Init();
            person_list.Init();
            inst_list.Init();
            section_list.Init();
            assign_list.Init();
            signup_list.Init();
            grade_list.Init();

            section_view.Init();
            inst_signup_view.Init();
            inst_assign_view.Init();
            inst_grade_view.Init();

            return 0;
        }

        public int CurrentSemNum
        {
            get { return current_sem; }
        }

        public int CurrentUserID
        {
            get { return current_id; }
        }

        public string CurrentLogin
        {
            get { return current_login.ToString(); }
        }

        public string CurrentSeason
        {
            get { return (string)cSectionList.SeasonList[current_sem]; }
        }

        public string CurrentCourse
        {
            get {
                string s = "";
                if (current_section != null)
                {
                    s = course_info_list.GetCourseName(current_section.CID);
                }
                return s;
            }
        }

        public string CurrentSem
        {
            get { return current_sem.ToString(); }
            set {
                int ts = cSectionList.SeasonList.IndexOf(value.ToString());
                if(current_sem != ts &&
                   main_form != null)
                {
                    // change semester
                    current_sem = ts;
                    main_form.semesterBox.SelectedIndex = current_sem;

                    UpdateView();
                }
            }
        }

        public int CurrentYear
        {
            get { return current_year; }
            set
            {
                if(current_year != value &&
                   main_form != null)
                {
                    // change year
                    current_year = value;
                    main_form.yearNum.Value = current_year;

                    UpdateView();
                }
            }
        }

        public int CurrentSection
        {
            get { return current_section.ID; }
        }

        public int CurrentAssign
        {
            get { return current_assign.ID; }
        }

        public bool LoggedIn
        {
            get
            {
                if (security_level < 0)
                    return false;
                else
                    return true;
            }
        }

        public void Logout()
        {
            CurrentYear = DateTime.Now.Year;
            CurrentSem = "Fall";

            current_view = null;
            current_id = -1;
            current_login = null;
            current_section = null;
            current_assign = null;
            sub_state = 0;
            UpdateSecurityLevel(-1);
        }

        public bool CheckSignup(int id, int section_id)
        {
            return signup_list.CheckSignup(id, section_id);
        }

        public int SecurityLevel
        {
            get { return security_level; }
        }

        private void UpdateSecurityLevel(int level)
        {
            int old_sl = security_level;
            security_level = level;

            ResetDataGrid();
            
            // if level changed
            if (security_level != old_sl)
            {
                sub_state = 0;

                // admin
                if (level == 2)
                {
                    current_view = null;
                    main_form.selectTable.SelectedIndex = 0;
                }
                // student/instructor
                else if (level == 0 || level == 1)
                {
                    if (level == 0)
                    {
                        SwitchView("Sign-up");
                    }
                    else
                    {
                        SwitchView("Section View");
                    }
                }
            }

            UpdateState();
        }

        public bool Login(string user, string pass)
        {
            if(user.Length < 1)
            {
                MessageBox.Show("You need to enter a User ID", "Login Error");
            }
            else if(user.ToLower().CompareTo("admin") == 0)
            {
                // trying to login as admin
                if(pass.Length < 1)
                {
                    MessageBox.Show("You need to enter in Password", "Login Error");
                } else {
                    if(pass.CompareTo("test") == 0)
                    {
                        current_id = -1;
                        UpdateSecurityLevel(2);
                        return true;
                    } else {
                        MessageBox.Show("Incorrect Password", "Login Error");
                    }
                }
            } else {
                int userid = -1;

                try {
                    userid = Convert.ToInt32(user);
                }
                catch(Exception exp) {
                    string err = exp.Message; // error
                    MessageBox.Show("Invalid User ID, numbers are only allowed", "Login Error");
                    return false;
                }

                if( pass.Length > 0 )
                {
                    // trying to login as instructor
                    if (inst_list.Login(userid, pass))
                    {
                        current_id = userid;
                        current_login = person_list.GetPerson(current_id);
                        UpdateSecurityLevel(1);
                        return true;
                    } else {
                        MessageBox.Show("Incorrect User ID or Password", "Login Error");
                    }
                }
                else
                {
                    MessageBox.Show("Login as Student feature was not been implimented.", "Login Error");
                    #if false
                    // trying to login as student
                    if (person_list.Login(userid))
                    {
                        current_id = userid;
                        current_login = person_list.GetPerson(current_id);
                        UpdateSecurityLevel(0);
                        return true;
                    } else {
                        MessageBox.Show("Incorrect User ID", "Login Error");
                    }
                    #endif
                }
            }

            return false;
        }

        private void CreateAllProc()
        {
            // disable all controls
            ControlsHandler(this, new cControlsArgs(false));
          

            // drop objects
            cIAGS.DisplayError = false;
                // drop all tables;
                SetProgText("Dropping Table(s)...");
                SetProgMinMax(0, 7);

                SetProgValue(0);
                grade_list.DropTable();
                SetProgValue(1);
                signup_list.DropTable();
                SetProgValue(2);
                assign_list.DropTable();
                SetProgValue(3);
                section_list.DropTable();
                SetProgValue(4);
                inst_list.DropTable();
                SetProgValue(5);
                person_list.DropTable();
                SetProgValue(6);
                course_info_list.DropTable();

                // dropt all view
                SetProgText("Dropping View(s)...");
                SetProgMinMax(0, 4);

                SetProgValue(0);
                section_view.DropTable();
                SetProgValue(1);
                inst_signup_view.DropTable();
                SetProgValue(2);
                inst_assign_view.DropTable();
                SetProgValue(3);
                inst_grade_view.DropTable();
                
            cIAGS.DisplayError = true;
            // 

            // create objects
                SetProgText("Creating Table(s)...");
                SetProgMinMax(0, 7);

                SetProgValue(0);
                person_list.Create();
                SetProgValue(1);
                course_info_list.Create();
                SetProgValue(2);
                inst_list.Create();
                SetProgValue(3);
                section_list.Create();
                SetProgValue(4);
                assign_list.Create();
                SetProgValue(5);
                signup_list.Create();
                SetProgValue(6);
                grade_list.Create();

                // create views
                SetProgText("Creating View(s)...");
                section_view.Create();
                SetProgMinMax(0, 4);

                SetProgValue(0);
                section_view.Create();
                SetProgValue(1);
                inst_grade_view.Create();    
                SetProgValue(2);
                inst_signup_view.Create();
                SetProgValue(3);
                inst_assign_view.Create();
                
                //
                SetProgValue(0);
                SetProgText("Done.");
            //

            // enable all controls
            ControlsHandler(this, new cControlsArgs(true));
        }

        private void SaveAllProc()
        {
            // disable all controls
            ControlsHandler(this, new cControlsArgs(false));

            // Save ALL to File
            grade_list.SaveToFile();
            signup_list.SaveToFile();
            assign_list.SaveToFile();
            section_list.SaveToFile();
            inst_list.SaveToFile();
            person_list.SaveToFile();
            course_info_list.SaveToFile();

            //
            SetProgValue(0);
            SetProgText("Done.");

            //

            // reset dir to default
            Directory.SetCurrentDirectory(default_dir);
            // enable all controls
            ControlsHandler(this, new cControlsArgs(true));
        }


        private void LoadAllProc()
        {
            // disable all controls
            ControlsHandler(this, new cControlsArgs(false));

            // import data
            cIAGS.DisplayError = false;
            person_list.LoadFromFile();
            course_info_list.LoadFromFile();
            inst_list.LoadFromFile();
            section_list.LoadFromFile();
            assign_list.LoadFromFile();
            signup_list.LoadFromFile();
            grade_list.LoadFromFile();
            cIAGS.DisplayError = true;

            SetProgValue(0);
            SetProgText("Done.");

            // reset dir to default
            Directory.SetCurrentDirectory(default_dir);
            // enable all controls
            ControlsHandler(this, new cControlsArgs(true));
        }

        // Create DB Schema
        public int CreateAll()
        {
            DialogResult dr = MessageBox.Show(main_form,
                "!!!Warning!!!\n"+
                "This function will destroy ALL data in the database.\n",
                "Warning!",
                MessageBoxButtons.OKCancel);
            if(dr == DialogResult.OK)
            {
                // run load in thread
                Thread loadThread = new Thread(
                        new ThreadStart(CreateAllProc)
                    );

                loadThread.Start();
            }

            return 0;
        }

        // Import DB Data
        public int LoadAll()
        {
            // popup directory Q
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            fbd.Description = "Please select a folder that contains the CSV files to Import into the database.";
            fbd.SelectedPath = Directory.GetCurrentDirectory();
            DialogResult dr = fbd.ShowDialog(main_form);
            if (dr == DialogResult.OK)
            {
                Directory.SetCurrentDirectory(fbd.SelectedPath);

                // run load in thread
                Thread loadThread = new Thread(
                        new ThreadStart( LoadAllProc )
                    );

                loadThread.Start();
            }
            //

            return 0;
        }

        // Export DB Data
        public int SaveAll()
        {
            // popup directory Q
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            fbd.Description = "Please select a folder that will contain the Exported CSV files with the database data.";
            fbd.SelectedPath = Directory.GetCurrentDirectory();
            DialogResult rd = fbd.ShowDialog(main_form);
            if (rd == DialogResult.OK)
            {
                Directory.SetCurrentDirectory(fbd.SelectedPath);

                // run load in thread
                Thread saveThread = new Thread(
                        new ThreadStart(SaveAllProc)
                    );

                saveThread.Start();
            }
            //

            return 0;
        }


        public int AddStudentsFile()
        {
            MessageBox.Show(main_form, "This feature will be added to the next version.");
            return 0;
        }

        void ControlsHandler(object sender, cControlsArgs args)
        {
            ///////////////////////////////////////
            // so thread don't mess with render
            // is this being called from main thread?
            if (main_form.InvokeRequired)
            {
                main_form.Invoke(new ControlsEventHandler(ControlsHandler),
                                 new object[] { sender, args });
                return;
            }
            ///////////////////////////////////////

            main_form.EnableAll(args.enable);
        }

        void UpdateProgHandler(object sender, cProgArgs args)
        {
            ///////////////////////////////////////
            // so thread don't mess with render
            // is this being called from main thread?
            if(main_form.InvokeRequired)
            {
                main_form.Invoke(new ProgEventHandler(UpdateProgHandler), 
                                 new object[] { sender, args } );
                return;
            }
            ///////////////////////////////////////

            pt.Text = args.msg;
            pb.Minimum = args.min;
            pb.Maximum = args.max;
            pb.Value = args.value;
        }


        public void SwitchView(string name)
        {
            switch(name)
            {
                case "Course Info.":
                    current_view = course_info_list;
                    break;

                case "Person":
                    current_view = person_list;
                    break;

                case "Instructor":
                    current_view = inst_list;
                    break;

                case "Section":
                    current_view = section_list;
                    break;

                case "Section View":
                    current_view = section_view;
                    break;

                case "Assignment":
                    current_view = assign_list;
                    break;

                case "Grade":
                    current_view = grade_list;
                    break;

                case "Sign-up":
                    current_view = signup_list;
                    break;

                case "Inst Sign-up View":
                    current_view = inst_signup_view;
                    break;

                case "Inst Assign View":
                    current_view = inst_assign_view;
                    break;

                case "Inst Grade View":
                    current_view = inst_grade_view;
                    break;
            }

            if(current_view != null)
            {
                UpdateView();
            }
        }

        private void ResetDataGrid()
        {
            try
            {
                if (dg.Rows.Count > 0)
                    dg.Rows.Clear();

                if (dg.Columns.Count > 0)
                    dg.Columns.Clear();
            }
            catch (Exception exp)
            {
                // error?
                MessageBox.Show(exp.ToString());
            }
        }

        public int UpdateView()
        {
            ResetDataGrid();

            if(current_view != null)
            {
                ArrayList col = new ArrayList();

                // reset allow new
                dg.AllowUserToAddRows = true;

                current_view.UpdateView();
                current_view.dataGrid_Define(dg, col);

                for(int i = 0; i < col.Count; i++)
                {
                    if (col[i] is string)
                    {
                        dg.Columns.Add(col[i].ToString(),
                                       col[i].ToString());
                    }
                    else
                    {
                        dg.Columns.Add((DataGridViewColumn)col[i]);
                    }
                }

                if (current_view.count > 0)
                {
                    dg.RowCount = current_view.count;

                    if (dg.AllowUserToAddRows)
                        dg.RowCount++;
                }
                else
                    dg.RowCount = 1;
            }

            RowChanged(0);
            UpdateState();
            return 0;
        }


        public int State
        {
            set {
                if ((value > -1) || (value < 4)) {
                    sub_state = value;
                    UpdateState();
                }
            }
        }

        public void NextState()
        {
            // instructor
            if (security_level == 1)
            {
                if (sub_state == 0)
                {
                    // select final grade from combo box
                    main_form.chooseBox.Text = "Final Grades";

                    State = 1;
                    SwitchView("Inst Sign-up View");
                }
                else if (sub_state == 1)
                {
                    State = 2;
                    SwitchView("Inst Assign View");
                }
                else if (sub_state == 2)
                {
                    State = 3;
                    SwitchView("Inst Grade View");
                }
            }
        }

        protected void UpdateState()
        {
            UpdateInfoText();
            main_form.ShowState(security_level, sub_state);
        }

        protected void UpdateInfoText()
        {
            string s = string.Format("Click on Login to start");

            // DB admin
            if (security_level == 2)
            {
                if (current_view == null)
                    s = string.Format("DB Admin: Select a Table");
                else
                    s = string.Format("DB Admin: {0}", current_view);
            }
            // instructor
            else if ((current_login != null) &&
                     (security_level == 1))
            {
                if (sub_state == 0) // section
                {
                    s = string.Format("{0}: {2} {1} - Select a Section then Click '>>>' to manage Final Grades and Assignments.", 
                        current_login,
                        current_year,
                        cSectionList.SeasonList[current_sem]);
                }
                else if (sub_state == 1)
                {
                    s = string.Format("{0}: {2} {1} - {3}", 
                        current_login, current_year,
                        cSectionList.SeasonList[current_sem],
                        current_section);
                }
                else if (sub_state == 2)
                {
                    s = string.Format("{0}: {2} {1} - {3} - Select an Assignment then Click '>>>' to add/edit a Grade.",
                        current_login, current_year,
                        cSectionList.SeasonList[current_sem],
                        current_section);
                }
                else if (sub_state == 3)
                {
                    s = string.Format("{0}: {2} {1} - {3} - {4}",
                        current_login, current_year,
                        cSectionList.SeasonList[current_sem],
                        current_section, current_assign);
                }
            }

            main_form.titleBox.Text = s;
        }

        public void RowChanged(int row)
        {
            // instructor
            if (security_level == 1)
            {
                if (sub_state == 0) // section
                {
                    current_section = section_view.GetRow(row);

                    if(current_section != null)
                        main_form.sectionLink.Text = current_section.ToString();
                    else
                        main_form.sectionLink.Text = "";
                }
                else if (sub_state == 2) // assignment
                {
                    current_assign = inst_assign_view.GetRow(row);

                    if (current_assign != null)
                        main_form.assignLink.Text = current_assign.ToString();
                    else
                        main_form.assignLink.Text = "";
                }
               
                UpdateState();
            }
        }

        public void SelectSection()
        {
            // instructor
            if (security_level == 1)
            {
                int section_id = -1;
                int index = 0;
                if (current_section != null) section_id = current_section.ID;

                State = 0;
                SwitchView("Section View");

                // if there is an id
                if (section_id != -1)
                    index = section_view.GetIndex(section_id);

                // if index change
                if (index != 0)
                {
                    main_form.dataGrid.Rows[0].Selected = false;
                    // selects the current cell and moves the arrow
                    main_form.dataGrid.Rows[index].Cells[0].Selected = true;
                    main_form.dataGrid.CurrentCell = main_form.dataGrid.Rows[index].Cells[0];
                }
            }
        }

        public void SelectSignup()
        {
            // instructor
            if (security_level == 1)
            {
                State = 1;
                SwitchView("Inst Sign-up View");
            }
        }

        public void SelectAssignment()
        {
            // instructor
            if (security_level == 1)
            {
                int assign_id = -1;
                int index = 0;
                // capture id before current changes to first row item
                if (current_assign != null)  assign_id = current_assign.ID;


                State = 2;
                SwitchView("Inst Assign View");

                // if there is an id
                if (assign_id != -1)
                    index = inst_assign_view.GetIndex(assign_id);

                // if index change
                if (index != 0)
                {
                    main_form.dataGrid.Rows[0].Selected = false;
                    // selects the current cell and moves the arrow
                    main_form.dataGrid.Rows[index].Cells[0].Selected = true;
                    main_form.dataGrid.CurrentCell = main_form.dataGrid.Rows[index].Cells[0];
                }
            }
        }

        // -----------------------------------------
        // DataGrid Events
        public void dataGrid_CellValueNeeded(DataGridViewCellValueEventArgs e)
        {
            if (current_view == null) return;
            current_view.dataGrid_CellValueNeeded(main_form.dataGrid, e);
        }

        public void dataGrid_CellValuePushed(DataGridViewCellValueEventArgs e)
        {
            if(current_view == null) return;
            current_view.dataGrid_CellValuePushed(e);
        }

        public void dataGrid_NewRowNeeded(DataGridViewRowEventArgs e)
        {
            if(current_view == null) return;
            current_view.dataGrid_NewRowNeeded(e);
        }

        public void dataGrid_RowValidating(DataGridViewCellCancelEventArgs e)
        {
            if(current_view == null) return;

            try
            {
                current_view.dataGrid_RowValidating(e);
            }
            catch (Exception exp)
            {
                MessageBox.Show(main_form,
                                "There is a problem with the new/updated row.\n" +
                                "You may not have permission to do this.\n" +
                                "Press 'ESC' to cancel edit.", "Error");
                throw exp;
            }
        }

        public void dataGrid_CancelRowEdit(QuestionEventArgs e)
        {
            if (current_view == null) return;
            current_view.dataGrid_CancelRowEdit(e);
        }

        public void dataGrid_UserDeletingRow(DataGridViewRowCancelEventArgs e)
        {
            if (current_view == null) return;

            try
            {
                current_view.dataGrid_UserDeletingRow(e);
            }
            catch (Exception exp)
            {
                MessageBox.Show(main_form, 
                                "There is a problem removing this row.\n" +
                                "Another table may relay on this entry or\n"+
                                " you do not have permission to delete this row."
                                , "Error");
                throw exp;
            }
        }
        // -----------------------------------------

        // for prog args
        public static void SetProgText(string msg)
        {
            prog_args.msg = msg;
            UpdateProg(null, prog_args);
        }

        // for prog args
        public static void SetProgValue(int v)
        {
            prog_args.value = v;
            UpdateProg(null, prog_args);
        }

        // for prog args
        public static void SetProgMinMax(int min, int max)
        {
            prog_args.min = min;
            prog_args.max = max;
            prog_args.value = min;
            UpdateProg(null, prog_args);
        }

        // resets progress args for status bar
        public static void ProgReset()
        {
            prog_args.min = 0;
            prog_args.max = 1;
            prog_args.value = 0;
            prog_args.msg = "";
            UpdateProg(null, prog_args);
        }

        // displays an error message
        public static void PopupError(Exception exp)
        {
            if (ErrorMsg != null)
            {
                if (ErrorMsg.Length < 1)
                {
                    MessageBox.Show("There was an unknown error.\n"+
                                    "Please contact the Database Administrator.");
                }
                else
                {
                    MessageBox.Show(ErrorMsg);
                }
            }
        }

        // popup report dialog box
        public void PopupReport()
        {
            if (current_section != null)
            {
                string title = string.Format("Final Grade Report Form: {1} {0} - {2}",
                    current_year,
                    cSectionList.SeasonList[current_sem],
                    current_section
                );

                ReportForm rf = new ReportForm();
                rf.Text = title;

                // returns an html page containing the final grade report
                cFinalGradeReport fg = new cFinalGradeReport();
                rf.html_data = fg.GenerateReport();

                rf.ShowDialog(main_form);
            }
        }
    }
}


