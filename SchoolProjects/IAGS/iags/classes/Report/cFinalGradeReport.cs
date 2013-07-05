using System;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;

namespace iags
{
    // essentually the same this as the "cInstSignupView" but it's 
    // main purouse is to generate an html report
    class cFinalGradeReport : cDBItemList
    {
        // 0 - year (RO)
        // 1 - season number (RO)
        // 2 - section id (RO)

        // 3 - student id (RO)
        // 4 - student name (RO)
        // 5 - student final grade letter (RO)
        // 6 - student total grade points (RO)
        // 7 - student calc grade points (RO)
        // 8 - details (RO)

        public cFinalGradeReport()
        {
            entity_name = "Final Grade Report";
            tbl_name = "js_signup_inst_view";
        }


        public override cBaseItem getNewRow()
        {
            return new cInstSignupViewRow();
        }

        public override int SelectAll()
        {
            Clear();
            string sql = "";

            if ((cDB.Type == "Oracle") || (cDB.Type == "MySQL"))
            {
                sql = string.Format(
                    @"* FROM {0} WHERE
                            year={1} AND                        
                            season_num={2} AND
                            section_id={3}",
                    tbl_name,
                    Program.main.CurrentYear,
                    Program.main.CurrentSemNum,
                    Program.main.CurrentSection);
            }

            return Select(sql);
        }

        public string GenerateReport()
        {
            SelectAll();
            string main_tmpl = File.ReadAllText("tmpl/final_grade_main.htm");
            string erow = GetSub(main_tmpl, "<%erow%>", "</%erow%>");
            string orow = GetSub(main_tmpl, "<%orow%>", "</%orow%>");
            string rows = "";
            string trow = "";

            //
            main_tmpl = main_tmpl.Replace("%inst_name%", Program.main.CurrentLogin);
            main_tmpl = main_tmpl.Replace("%season%", Program.main.CurrentSeason);
            main_tmpl = main_tmpl.Replace("%year%", Program.main.CurrentYear.ToString());
            main_tmpl = main_tmpl.Replace("%course_name%", Program.main.CurrentCourse);

            for(int i = 0; i < dlist.Count; i++)
            {
                cInstSignupViewRow d = (cInstSignupViewRow)dlist[i];
                if (d != null)
                {
                    if ((i & 1) == 1) trow = orow; // odd
                    else              trow = erow; // even

                    trow = trow.Replace("%id%", d.Last4ID);
                    trow = trow.Replace("%grade_points%", d.GradePoints);

                    string gl = d.GradeLetter;
                    if(gl.Length < 1) trow = trow.Replace("%grade_letter%", "&nbsp;");
                    else              trow = trow.Replace("%grade_letter%", gl);

                    rows += trow;
                }
            }

            main_tmpl = ReplaceSub(main_tmpl, rows, "<%rows%>", "</%rows%>");

            return main_tmpl;
        }

        private string ReplaceSub(string tmpl, string replace, string start_tag, string end_tag)
        {
            int s = tmpl.IndexOf(start_tag) + start_tag.Length;
            int e = tmpl.IndexOf(end_tag);
            tmpl = tmpl.Remove(s, e - s);
            return tmpl.Insert(s, replace);
        }

        private string GetSub(string tmpl, string start_tag, string end_tag)
        {
            int s = tmpl.IndexOf(start_tag) + start_tag.Length;
            int e = tmpl.IndexOf(end_tag);
            return tmpl.Substring(s, e - s);
        }
    }
}
