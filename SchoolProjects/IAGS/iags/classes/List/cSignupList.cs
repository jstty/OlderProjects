using System;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;

namespace iags
{
    class cSignupList : cDBItemList
    {
        // select * from js_section;
        public cSignupList()
        {
            entity_name = "Signup";
            tbl_name = "js_signup";
            loadfile_name = "signup.csv";

            nlist.Add("id");
            nlist.Add("section_id");
            nlist.Add("grade_letter");
            nlist.Add("grade_points");
            nlist.Add("details");
        }

        //
        public override int Create()
        {
            sql = tbl_name + "(";

            if (cDB.Type == "MySQL")
            {
                sql += "id           INTEGER      NOT NULL AUTO_INCREMENT,";
                sql += "section_id   INTEGER      NOT NULL,";
                sql += "grade_letter VARCHAR(4)  ,";
                sql += "grade_points FLOAT        ,";
                sql += "details      VARCHAR(1024) ,";

                sql += "FOREIGN KEY(id)         REFERENCES js_person(id),";
                sql += "FOREIGN KEY(section_id) REFERENCES js_section(section_id)";
            }
            else if (cDB.Type == "Oracle")
            {
                sql += "id           INTEGER      NOT NULL,";
                sql += "section_id   INTEGER      NOT NULL,";
                sql += "grade_letter VARCHAR2(4)  ,";
                sql += "grade_points FLOAT        ,";
                sql += "details    VARCHAR2(1024) ,";

                sql += "FOREIGN KEY(id)         REFERENCES js_person(id),";
                sql += "FOREIGN KEY(section_id) REFERENCES js_section(section_id)";
            }

            sql += ")";
            return CreateTableDB(sql);
        }

        public override int dataGrid_Define(DataGridView dg, ArrayList col)
        {
            col.Add("Person ID");
            col.Add("Section ID");           
            col.Add("Final Grade Letter");
            col.Add("Final Grade Points");
            col.Add("Details");

            return 0;
        }

        public override cBaseItem getNewRow()
        {
            return new cSignup();
        }

        public bool CheckSignup(int id, int section_id)
        {
            // turn off DB error message
            display_error = false;
            int rc = RowCount( string.Format(
                "{0} WHERE id={1} AND section_id={2}",
                tbl_name,
                id,
                section_id)
            );

            // turn on DB error message
            display_error = true;
            if (rc > 0) return true;

            return false;
        }
    }
}
