using System;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;

namespace iags
{
    class cInstSectionView : cDBItemList
    {
        // 0 - section ID (RO)
        // 1 - instructor ID (RO)
        // 2 - Year (RO)
        // 3 - Season Name(from season no.) (RO)
        // 4 - Course ID (RO)

        // 5 - units worth (RO)
        // 6 - CRN (RO)
        // 7 - course short name (RO)
        // 8 - current number of students (RO)
        // 9 - max number of students (RO)
        // 10 - min grade points (RO)
        // 11 - max grade points (RO)
        // 12 - avg grade points (RO)

        public cInstSectionView()
        {
            entity_name = "Section View";
            tbl_name = "js_section_inst_view";
            
            nlist.Add("section_id");
            nlist.Add("iid");
            nlist.Add("year");
            nlist.Add("season_num");
            nlist.Add("course_id");

            nlist.Add("worth");
            nlist.Add("crn");
            nlist.Add("short_name");
            nlist.Add("COUNT(sid) num_student");
            nlist.Add("max_students");
            nlist.Add("MIN(grade_points) min_points");
            nlist.Add("MAX(grade_points) max_points");
            nlist.Add("AVG(grade_points) avg_points");
        }

        // 
        public override int DropTable()
        {
            if (cDB.Type == "MySQL")
            {
                DropView("js_section_inst_int");
            }

            return DropView();
        }

        // 
        public override int Create()
        {
            sql = "";

            if (cDB.Type == "Oracle" )
            {
                sql = string.Format(
                @"{0} AS 
                    SELECT {1}
                    FROM (
                       SELECT 
                          si.id sid, 
                          to_number(to_char(start_date, 'YYYY')) year,
                          se.section_id section_id,
                          se.id iid,
                          se.season_num season_num,
                          se.crn crn,
                          ci.course_id course_id,
                          ci.short_name short_name,
                          se.max_students max_students,
                          si.grade_points,
                          ci.worth worth
                       FROM js_section se, js_course_info ci, js_signup si
                       WHERE se.course_id = ci.course_id AND
                             se.section_id = si.section_id(+)
                    )
                    GROUP BY section_id, iid, year,
                             season_num, crn, course_id,
                             short_name, max_students, worth",
                    tbl_name,
                    cSqlValueList.Implode(nlist)
                );
            }
            else if (cDB.Type == "MySQL")
            {
                // mysql won't let you do a sub select in a view, 
                // so an intermedia view was create
                sql = @"js_section_inst_int AS
                           SELECT 
                              si.id sid, 
                              year(start_date) year,
                              se.section_id,
                              se.id iid,
                              se.season_num season_num,
                              se.crn crn,
                              ci.course_id course_id,
                              ci.short_name short_name,
                              se.max_students max_students,
                              si.grade_points,
                              ci.worth worth
                           FROM js_course_info ci, 
                                js_section se LEFT JOIN js_signup si 
                                 ON (se.section_id = si.section_id)
                           WHERE se.course_id = ci.course_id";
                CreateView(sql);
                
                sql = string.Format(
                    @"{0} AS
                       SELECT {1}
                       FROM js_section_inst_int
                       GROUP BY section_id, iid, year, 
                                season_num, crn, short_name",
                       tbl_name,
                       cSqlValueList.Implode(nlist)
                    );
            }

            return CreateView(sql);
        }

        public override cBaseItem getNewRow()
        {
            return new cInstSectionViewRow();
        }

        public override int dataGrid_Define(DataGridView dg, ArrayList col)
        {
            int i;
            DataGridViewTextBoxColumn[] tb = new DataGridViewTextBoxColumn[8];

            for(i = 0; i < 8; i++)
            {
                tb[i] = new DataGridViewTextBoxColumn();
                tb[i].ReadOnly = true;
                tb[i].DefaultCellStyle.BackColor = System.Drawing.SystemColors.Control;
            }

            tb[0].Name = tb[0].HeaderText = "Worth";
            tb[0].Width = 50;
            tb[1].Name = tb[1].HeaderText = "CRN";
            tb[1].Width = 50;
            tb[2].Name = tb[2].HeaderText = "Name";
            tb[2].Width = 75;
            tb[3].Name = tb[3].HeaderText = "Current Entrolled";
            tb[3].Width = 60;
            tb[4].Name = tb[4].HeaderText = "Max Students";
            tb[4].Width = 60;
            tb[5].Name = tb[5].HeaderText = "Min. Grade Points";
            tb[5].Width = 60;
            tb[6].Name = tb[6].HeaderText = "Max. Grade Points";
            tb[6].Width = 60;
            tb[7].Name = tb[7].HeaderText = "Avg. Grade Points";
            tb[7].Width = 60;

            for(i = 0; i < 8; i++)
            {
                col.Add(tb[i]);
            }

            dg.AllowUserToAddRows = false;

            return 0;
        }

        public cInstSectionViewRow GetRow(int row)
        {
            if (row < dlist.Count)
            {
                cInstSectionViewRow d = (cInstSectionViewRow)dlist[row];
                return d;
            }

            return null;
        }


        public override int SelectAll()
        {
            Clear();
            string sql = "";

            if ( (cDB.Type == "Oracle") || (cDB.Type == "MySQL") )
            {
                sql = string.Format(
                    @"* FROM {0} WHERE
                        iid={1} AND
                        season_num={2} AND
                        year={3}",
                    tbl_name,
                    Program.main.CurrentUserID,
                    Program.main.CurrentSemNum,
                    Program.main.CurrentYear);
            }

            return Select(sql);
        }

        public override int InsertDB(object o)
        {
            // do nothing, this user can not insert in section
            return 1;
        }

        public override int DeleteDB(object o)
        {
            // do nothing, this user can not delete from section
            return 1;
        }

        // for row selection
        public int GetIndex(int id)
        {
            for (int i = 0; i < dlist.Count; i++)
            {
                cInstSectionViewRow d = (cInstSectionViewRow)dlist[i];
                if (d != null)
                {
                    if (id == d.ID) return i;
                }
            }

            return 0;
        }
    }
}
