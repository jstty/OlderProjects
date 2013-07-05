using System;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;

namespace iags
{
    class cInstSignupView : cDBItemList
    {
        // 0 - year (RO)
        // 1 - season number (RO)
        // 2 - section id (RO)

        // 3 - student id (RO)
        // 4 - student name (RO)
        // 5 - student final grade letter (RW)
        // 6 - student total grade points (RW)
        // 7 - student calc grade points (RO)
        // 8 - details (RW)

        public cInstSignupView()
        {
            entity_name = "Instructor Sign-up View";
            tbl_name = "js_signup_inst_view";

            // for update
            nlist.Add("id");
            nlist.Add("section_id");
            nlist.Add("grade_letter");
            nlist.Add("grade_points");
            nlist.Add("details");
        }

        public override int DropTable()
        {
            if (cDB.Type == "Oracle")
            {
                DropFunc("js_calc_final_points");
            }

            return DropView();
        }

        public override int Create()
        {
            sql = "";

            if (cDB.Type == "Oracle" )
            {
                sql = @"js_calc_final_points(stu_id INTEGER, sec_id INTEGER)
                    RETURN FLOAT
                    AS
                      mtPts js_assign.max_points%TYPE := 0;
                      stPts js_grade.points%TYPE := 0;
                      fnPts FLOAT := 0.00;
                      CURSOR allGrades IS 
                         SELECT * 
                         FROM js_grade_gen_view 
                         WHERE section_id = sec_id AND
                               id = stu_id;
                    BEGIN
                      FOR g IN allGrades 
                      LOOP
                         IF (g.points IS NOT NULL) THEN
                            stPts := stPts + g.points;
                         END IF;
                         
                         IF (g.is_extra < 1) THEN
                            mtPts := mtPts + g.max_points;
                         END IF;
                      END LOOP;
                      
                      IF (mtPts > 0) THEN
                         fnPts := (stPts/mtPts)*100;
                      END IF;
                      
                      RETURN fnPts;
                    END;";
                CreateFunc(sql);

                sql = string.Format(
                @"{0} AS 
                SELECT
                    to_number(to_char(se.start_date, 'YYYY')) year,
                    se.season_num,
                    se.section_id,
                    si.id,
                    (p.fname || ' ' || p.mname || ' ' || p.lname) name,
                    si.grade_letter,
                    si.grade_points,
                    js_calc_final_points(si.id, se.section_id) calc_points,
                    si.details
                FROM js_section se, js_signup si, js_person p
                WHERE si.section_id = se.section_id AND
                    si.id = p.id",
                tbl_name);
            }
            else if (cDB.Type == "MySQL")
            {
                sql = string.Format(
                @"{0} AS 
                SELECT
                    year(se.start_date) year,
                    se.season_num,
                    se.section_id,
                    si.id,
                    concat(p.fname, ' ', p.mname, ' ', p.lname) name,
                    si.grade_letter,
                    si.grade_points,
                    0.00 calc_points,
                    si.details
                FROM js_section se, js_signup si, js_person p
                WHERE si.section_id = se.section_id AND
                    si.id = p.id",
                tbl_name);
            }

            return CreateView(sql);
        }

        public override cBaseItem getNewRow()
        {
            return new cInstSignupViewRow();
        }

        public override int dataGrid_Define(DataGridView dg, ArrayList col)
        {
            int i;
            DataGridViewTextBoxColumn[] tb = new DataGridViewTextBoxColumn[6];

            for (i = 0; i < 6; i++)
            {
                tb[i] = new DataGridViewTextBoxColumn();
            }
            
            tb[0].Name = tb[0].HeaderText = "ID";
            tb[0].ReadOnly = true;
            tb[0].DefaultCellStyle.BackColor = System.Drawing.SystemColors.Control;
            tb[0].Width = 75;
            col.Add(tb[0]);

            tb[1].Name = tb[1].HeaderText = "Name";
            tb[1].ReadOnly = true;
            tb[1].DefaultCellStyle.BackColor = System.Drawing.SystemColors.Control;
            tb[1].Width = 125;
            col.Add(tb[1]);

            tb[2].Name = tb[2].HeaderText = "Grade Letter";
            tb[2].Width = 60;
            col.Add(tb[2]);

            tb[3].Name = tb[3].HeaderText = "Grade Points";
            tb[3].Width = 60;
            col.Add(tb[3]);

            tb[4].Name = tb[4].HeaderText = "Calc. Points";
            tb[4].ReadOnly = true;
            tb[4].DefaultCellStyle.BackColor = System.Drawing.SystemColors.Control;
            tb[4].Width = 50;
            col.Add(tb[4]);


            tb[5] = new DataGridViewTextBoxColumn();
            tb[5].Name = tb[5].HeaderText = "Details";
            tb[5].Width = 200;
            col.Add(tb[5]);

            dg.AllowUserToAddRows = false;
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

        public override int UpdateDB(object o)
        {
            // custom update signup
            cInstSignupViewRow d = (cInstSignupViewRow)o;
            if (d != null)
            {
                vlist.Reset();

                vlist.Add(nlist[2].ToString(), d.data[5]); // grade_letter
                vlist.Add(nlist[3].ToString(), d.data[6]); // grade_points
                vlist.Add(nlist[4].ToString(), d.data[8]); // details
                
                string sql = string.Format("{0} WHERE {1}={2} AND {3}={4}", 
                    vlist.SQL, 
                    nlist[0], d.data[3],
                    nlist[1], d.data[2]
                    );

                return Update("js_signup", sql);
            }

            return 1;
        }

        public override int InsertDB(object o)
        {
            // do nothing, this user can not insert a student into sign-up
            return 1;
        }

        public override int DeleteDB(object o)
        {
            // do nothing, this user can not delete a student from sign-up
            return 1;
        }
    }
}
