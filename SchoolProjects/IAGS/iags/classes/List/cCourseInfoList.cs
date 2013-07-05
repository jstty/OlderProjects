using System;
using System.Windows.Forms;
using System.Text;
using System.IO;
using System.Collections;
using System.Collections.Generic;

namespace iags
{
    class cCourseInfoList : cDBItemList
    {
        private ArrayList course_name_list;

        public cCourseInfoList()
        {
            course_name_list = new ArrayList();

            entity_name = "Course Info.";
            tbl_name = "js_course_info";
            loadfile_name = "course_info.csv";

            nlist.Add("course_id");
            nlist.Add("short_name");
            nlist.Add("long_name");
            nlist.Add("description");
            nlist.Add("worth");
        }


        public override int Init()
        {
            string sql = string.Format("course_id, short_name, long_name FROM {0}", tbl_name);
            Select(sql);
            return 0;
        }

        //
        public override int Create()
        {
            sql = tbl_name + "(";

            if (cDB.Type == "MySQL")
            {
                sql += "course_id    INTEGER      NOT NULL AUTO_INCREMENT,";
                sql += "short_name   VARCHAR(32)  NOT NULL,";
                sql += "long_name    VARCHAR(128),";
                sql += "description  VARCHAR(1024),";
                sql += "worth        INTEGER      NOT NULL,";

                sql += "PRIMARY KEY(course_id)";
            }
            else if (cDB.Type == "Oracle")
            {
                sql += "course_id   INTEGER       NOT NULL,";
                sql += "short_name  VARCHAR2(32)  NOT NULL,";
                sql += "long_name   VARCHAR2(128) ,";
                sql += "description VARCHAR2(1024),";
                sql += "worth       INTEGER       NOT NULL,";

                sql += "PRIMARY KEY(course_id)";
            }

            sql += ")";
            return CreateTableDB(sql);
        }

        public override object ReadData(object[] row)
        {
            // if init. course info selection
            if (row.Length == 3)
            {
                cCourseInfo ci = new cCourseInfo();
                ci.data[0] = Convert.ToInt32(row[0]);
                ci.data[1] = Convert.ToString(row[1]);
                ci.data[2] = Convert.ToString(row[2]);

                course_name_list.Add(ci);

                return ci;
            }
            else
                return base.ReadData(row);
        }

        public override int dataGrid_Define(DataGridView dg, ArrayList col)
        {
            col.Add("Course ID");
            col.Add("Short Name");
            col.Add("Long Name");

            DataGridViewTextBoxColumn tb = new DataGridViewTextBoxColumn();
            tb.Name = tb.HeaderText = "Description";
            tb.Width = 150;

            col.Add(tb);
            col.Add("Worth");

            return 0;
        }

        public override cBaseItem getNewRow()
        {
            return new cCourseInfo();
        }

        public string GetCourseName(int id)
        {
            for(int i = 0; i < course_name_list.Count; i++)
            {
                cCourseInfo ci = (cCourseInfo)course_name_list[i];
                if (ci != null)
                {
                    if ((int)ci.data[0] == id)
                    {
                        return string.Format("{0} - {1}",
                            (string)ci.data[1],
                            (string)ci.data[2]);
                    }
                }
            }

            return "";
        }


    }
}
