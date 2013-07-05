using System;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;

namespace iags
{
    class cInstGradeView : cDBItemList
    {
        // 0 - section id (RO)
        // 1 - assignment id  (RO)
        // 2 - assignment name  (RO)

        // 3 - student id  (RO)
        // 4 - student name  (RO)
        // 5 - points  (RW)
        // 6 - max points (RO)
        // 7 - is extra (RO)
        // 8 - details (RW)

        public cInstGradeView()
        {
            entity_name = "Instructor Grade View";
            tbl_name = "js_grade_gen_view";

            nlist.Add("s.section_id");
            nlist.Add("s.assign_id");
            nlist.Add("s.aname");

            nlist.Add("s.id");
            nlist.Add("s.sname");
            nlist.Add("a.points");
            nlist.Add("s.max_points");
            nlist.Add("s.is_extra");
            nlist.Add("a.details");
        }

        public override int DropTable()
        {
            DropView("js_latest_grade_view");
            DropView("js_assign_grade_view");
            DropView("js_signup_section_assign_view");

            if (cDB.Type == "Oracle")
            {
                DropProc("js_insert_grade");
            }

            return DropView(tbl_name);
        }

        public override int Init()
        {
            //DropTable();
            //Create();
            return base.Init();
        }

        public override int Create()
        {
            sql = "";

            // create latest grades view
            sql = @"js_latest_grade_view AS
                       SELECT g1.*
                       FROM js_grade g1
                       WHERE 
                          NOT EXISTS(
                             SELECT * from js_grade g2
                             WHERE  g1.date_entered < g2.date_entered AND
                                    g1.assign_id = g2.assign_id AND
                                    g1.id = g2.id)";
            CreateView(sql);

            // create assign grade view
            sql = @"js_assign_grade_view AS
                       SELECT a.section_id, a.assign_id, g.id, g.points, g.details
                       FROM  js_assign a, js_latest_grade_view g
                       WHERE a.assign_id = g.assign_id";
            CreateView(sql);

            if (cDB.Type == "Oracle")
            {
                sql = @"js_insert_grade(sid INTEGER, aid INTEGER, grade INTEGER, details VARCHAR2) AS 
                        BEGIN
                            INSERT INTO js_grade VALUES(js_grade_seq.nextval, aid, sid, grade, SYSDATE, details);
                            RETURN 1;
                        END;";
                CreateProc(sql);

                // create signup section assign view
                sql = @"js_signup_section_assign_view AS
                           SELECT  si.id, se.section_id, a.assign_id, a.name aname, a.max_points, a.is_extra,
                                   (p.fname || ' ' || p.mname || ' ' || p.lname) sname
                           FROM  js_signup si, js_section se, js_assign a, js_person p
                           WHERE si.section_id = se.section_id AND
                                 se.section_id = a.section_id AND
                                 si.id = p.id";
                CreateView(sql);

                // create generic grade view
                sql = string.Format(@"{0} AS
                           SELECT {1}
                           FROM  js_signup_section_assign_view s, 
                                 js_assign_grade_view a
                           WHERE s.section_id = a.section_id(+) AND
                                 s.assign_id = a.assign_id(+) AND
                                 s.id = a.id(+)",
                        tbl_name,
                        cSqlValueList.Implode(nlist));

            }
            else if (cDB.Type == "MySQL")
            {
                // create signup section assign view
                sql = @"js_signup_section_assign_view AS
                           SELECT  si.id, se.section_id, a.assign_id, a.name aname, a.max_points, a.is_extra,
                                   concat(p.fname, ' ', p.mname, ' ', p.lname) sname
                           FROM  js_signup si, js_section se, js_assign a, js_person p
                           WHERE si.section_id = se.section_id AND
                                 se.section_id = a.section_id AND
                                 si.id = p.id";
                CreateView(sql);

                // create generic grade view
                sql = string.Format(@"{0} AS
                           SELECT {1}
                           FROM  js_signup_section_assign_view s LEFT JOIN js_assign_grade_view a
                           ON    (s.section_id = a.section_id AND
                                 s.assign_id = a.assign_id AND
                                 s.id = a.id)",
                        tbl_name,
                        cSqlValueList.Implode(nlist));
            }

            return CreateView(sql);
        }

        public override cBaseItem getNewRow()
        {
            return new cGradeViewRow();
        }

        public override int dataGrid_Define(DataGridView dg, ArrayList col)
        {
            int i;
            DataGridViewTextBoxColumn[] tb = new DataGridViewTextBoxColumn[5];
            for (i = 0; i < 5; i++)
            {
                tb[i] = new DataGridViewTextBoxColumn();
            }

            tb[0].Name = tb[0].HeaderText = "Student ID";
            tb[0].ReadOnly = true;
            tb[0].DefaultCellStyle.BackColor = System.Drawing.SystemColors.Control;
            tb[0].Width = 75;
            col.Add(tb[0]);
            
            tb[1].Name = tb[1].HeaderText = "Student Name";
            tb[1].ReadOnly = true;
            tb[1].DefaultCellStyle.BackColor = System.Drawing.SystemColors.Control;
            tb[1].Width = 125;
            col.Add(tb[1]);

            tb[2].Name = tb[2].HeaderText = "Points";
            tb[2].Width = 60;
            col.Add(tb[2]);

            tb[3].Name = tb[3].HeaderText = "Max Points";
            tb[3].ReadOnly = true;
            tb[3].DefaultCellStyle.BackColor = System.Drawing.SystemColors.Control;
            tb[3].Width = 60;
            col.Add(tb[3]);

            DataGridViewCheckBoxColumn cb = new DataGridViewCheckBoxColumn();
            cb.Name = cb.HeaderText = "Is Extra";
            cb.ReadOnly = true;
            cb.DefaultCellStyle.BackColor = System.Drawing.SystemColors.Control;
            cb.Width = 50;
            col.Add(cb);

            tb[4].Name = tb[4].HeaderText = "Details";
            tb[4].Width = 125;
            col.Add(tb[4]);

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
                    @"* FROM {0} WHERE assign_id={1}",
                    tbl_name,
                    Program.main.CurrentAssign);
            }

            return Select(sql);
        }

        public override int UpdateDB(object o)
        {
            // custom grade insert
            cGradeViewRow d = (cGradeViewRow)o;
            if (d != null)
            {
                string sql = "";
                // insert_grade
                // 0 - student id
                // 1 - assignment id
                // 2 - points
                // 3 - details
                
                // because mysql limited stored function support the insert had to be done manuly
                if (cDB.Type == "MySQL")
                {
                    sql = string.Format("NULL, {1}, {0}, {2}, NOW(), '{3}'",
                        d.data[3], d.data[1], d.data[5], d.data[8]
                        );

                    return Insert("js_grade", sql);
                }
                else if (cDB.Type == "Oracle")
                {
                    sql = string.Format("js_insert_grade({0}, {1}, {2}, '{3}')",
                        d.data[3], d.data[1], d.data[5], d.data[8]
                        );

                    return ExecProcedure(sql);
                }
                
            }

            return 1;
        }

        public override int InsertDB(object o)
        {
            // update will be used instead
            return 1;
        }

        public override int DeleteDB(object o)
        {
            // do nothing, this user can not delete a grade
            return 1;
        }

    }
}
