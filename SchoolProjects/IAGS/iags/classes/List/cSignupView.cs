using System;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;

namespace iags
{
    class cSignupView : cDBItemList
    {
        // 0 - id
        // 1 - section id
        // 2 - year
        // 3 - season number
        // 4 - section short name
        // 5 - student total grade points
        // 6 - student final grade letter
        // 7 - details

        public cSignupView()
        {
            entity_name = "Signup View";
            tbl_name = "js_signup_gen_view";
        }

        // 
        public override int DropTable()
        {
            return DropView();
        }

        // 
        public override int Create()
        {
            sql = "";
            string year = "";

            if (cDB.Type == "Oracle" )
            {
                year = "to_number(to_char(se.start_date, 'YYYY'))";
            }
            else if (cDB.Type == "MySQL")
            {
                year = "year(se.start_date)";
            }

            sql = string.Format(
            @"{0} AS 
                SELECT
                    si.id,
                    se.section_id, 
                    {1} year,
                    se.season_num,
                    ci.short_name,
                    ci.long_name,
                    si.grade_letter,
                    si.grade_points,
                    si.details
                FROM  js_section se, js_signup si, js_course_info ci 
                WHERE se.course_id = ci.course_id AND 
                      si.section_id = se.section_id",
                tbl_name, year);

            return CreateView(sql);
        }

        public override cBaseItem getNewRow()
        {
            return new cSignupViewRow();
        }

        public override int dataGrid_Define(ArrayList col)
        {
            DataGridViewTextBoxColumn tb1 = new DataGridViewTextBoxColumn();
            tb1.Name = tb1.HeaderText = "Short Name";
            tb1.ReadOnly = true;

            DataGridViewTextBoxColumn tb2 = new DataGridViewTextBoxColumn();
            tb2.Name = tb2.HeaderText = "Long Name";
            tb2.ReadOnly = true;

            col.Add("Grade Points");
            col.Add("Grade Letter");
            col.Add("Details");

            return 0;
        }


        public override int SelectAll()
        {
            Clear();
            string sql = "";

            if ((cDB.Type == "Oracle") || (cDB.Type == "MySQL"))
            {
                sql = string.Format(
                    @"* FROM {0} WHERE
                        season_num={1} AND
                        year={2} AND
                            ",
                    tbl_name,
                    Program.main.CurrentSemNum,
                    Program.main.CurrentYear,
                    );
            }

            return Select(sql);
        }
    }
}
