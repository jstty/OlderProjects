using System;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;

namespace iags
{
    class cSectionList : cDBItemList
    {
        public static ArrayList SeasonList;

        // select * from js_section;
        public cSectionList()
        {
            entity_name = "Section";
            tbl_name = "js_section";
            loadfile_name = "section.csv";

            nlist.Add("section_id");
            nlist.Add("course_id");
            nlist.Add("id");
            nlist.Add("crn");
            nlist.Add("season_num");
            nlist.Add("start_date");
            nlist.Add("end_date");
            nlist.Add("max_students");

            SeasonList = new ArrayList();
            SeasonList.Add("Fall");
            SeasonList.Add("Winter");
            SeasonList.Add("Spring");
            SeasonList.Add("Summer");
        }

        //
        public override int Create()
        {
            sql = tbl_name + "(";

            if (cDB.Type == "MySQL")
            {
                sql += "section_id   INTEGER      NOT NULL AUTO_INCREMENT,";
                sql += "course_id    INTEGER      NOT NULL,";
                sql += "id           INTEGER      NOT NULL,";
                sql += "crn          INTEGER      NOT NULL,";
                sql += "season_num   INTEGER      NOT NULL,";
                sql += "start_date   DATETIME     NOT NULL,";
                sql += "end_date     DATETIME     NOT NULL,";
                sql += "max_students INTEGER      NOT NULL,";

                sql += "PRIMARY KEY(section_id),";
                sql += "FOREIGN KEY(course_id) REFERENCES js_course_info(course_id),";
                sql += "FOREIGN KEY(id)        REFERENCES js_person(id)";
            }
            else if (cDB.Type == "Oracle")
            {
                sql += "section_id   INTEGER      NOT NULL,";
                sql += "course_id    INTEGER      NOT NULL,";
                sql += "id           INTEGER      NOT NULL,";
                sql += "crn          INTEGER      NOT NULL,";
                sql += "season_num   INTEGER      NOT NULL,";
                sql += "start_date   DATE         NOT NULL,";
                sql += "end_date     DATE         NOT NULL,";
                sql += "max_students INTEGER      NOT NULL,";

                sql += "PRIMARY KEY(section_id),";
                sql += "FOREIGN KEY(course_id) REFERENCES js_course_info(course_id),";
                sql += "FOREIGN KEY(id)        REFERENCES js_person(id)";
            }

            sql += ")";
            return CreateTableDB(sql);
        }

        public override int dataGrid_Define(DataGridView dg, ArrayList col)
        {
            col.Add("Section ID");
            col.Add("Course ID");
            col.Add("Instructor ID");
            col.Add("CRN");

            DataGridViewComboBoxColumn cc = new DataGridViewComboBoxColumn();
            cc.Name = cc.HeaderText = "Season";
            cc.Items.AddRange(SeasonList.ToArray());

            col.Add(cc);
            col.Add("Start Date");
            col.Add("End Date");
            col.Add("Max No. Students Allowed");

            return 0;
        }

        public override cBaseItem getNewRow()
        {
            return new cSection();
        }

#if false
        public override object ReadData(object[] row)
        {
            if(row.Length == 8)
            {
                cSection d = new cSection();

                d.data[0] = Convert.ToInt32(row[0]);
                d.data[1] = Convert.ToInt32(row[1]);
                d.data[2] = Convert.ToInt32(row[2]);

                d.data[3] = Convert.ToUInt32(row[3]);
                d.data[4] = Convert.ToByte(row[4]);

                if(row[5].ToString().Length > 1)
                    d.data[5] = Convert.ToDateTime(row[5]);
                if (row[6].ToString().Length > 1)
                    d.data[6] = Convert.ToDateTime(row[6]);
                d.data[7] = Convert.ToUInt16(row[7]);

                d.already_inDB = true;
                d.is_new = false;
                dlist.Add(d);
                return d;
            }

            return null;
        }

        public override int SelectAll()
        {
            if (Program.main.SecurityLevel == 2)
            {
                base.SelectAll();
            } else {
                Clear();
                string sql = "";

                if (cDB.Type == "MySQL")
                {
                    // need to fix
                    sql = string.Format(
                        "* FROM {0} WHERE " +
                        "season_num={2} AND " +
                        "id={1} AND " +
                        "start_date >= DATE('{3}-1-1') AND " +
                        "end_date <= DATE('{3}-12-31')",
                        tbl_name,
                        Program.main.CurrentUserID,
                        Program.main.CurrentSemNum,
                        Program.main.CurrentYear);
                }
                else if (cDB.Type == "Oracle")
                {
                    sql = string.Format(
                        "* FROM {0} WHERE " +
                        "season_num={2} AND " +
                        "id={1} AND " +
                        "start_date >= to_date('1/1/{3}', 'mm/dd/yyyy') AND " +
                        "end_date <= to_date('12/31/{3}', 'mm/dd/yyyy')",
                        tbl_name,
                        Program.main.CurrentUserID,
                        Program.main.CurrentSemNum,
                        Program.main.CurrentYear);
                }

                return Select(sql);
            }

            return 1;
        }
#endif

    }
}
