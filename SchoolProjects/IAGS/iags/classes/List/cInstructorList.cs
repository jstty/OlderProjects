using System;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;

namespace iags
{
    class cInstructorList : cDBItemList
    {
        // select * from js_instructor;
        public cInstructorList()
        {
            entity_name = "Instructor";
            tbl_name = "js_instructor";
            loadfile_name = "instructor.csv";

            nlist.Add("id");
            nlist.Add("password");
            nlist.Add("website");
            nlist.Add("s_email");
            nlist.Add("s_phone");
        }

        //
        public override int Create()
        {
            sql = tbl_name + "(";

            if (cDB.Type == "MySQL")
            {
                sql += "id        INTEGER     NOT NULL AUTO_INCREMENT,";
                sql += "password  VARCHAR(32) NOT NULL,";
                sql += "website   VARCHAR(256),";
                sql += "s_email   VARCHAR(128),";
                sql += "s_phone   VARCHAR(16) ,";

                sql += "FOREIGN KEY(id) REFERENCES js_person(id)";
            }
            else if (cDB.Type == "Oracle")
            {
                sql += "id        INTEGER      NOT NULL,";
                sql += "password  VARCHAR2(32) NOT NULL,";
                sql += "website   VARCHAR2(256),";
                sql += "s_email   VARCHAR2(128),";
                sql += "s_phone   VARCHAR2(16) ,";

                sql += "FOREIGN KEY(id) REFERENCES js_person(id)";
            }

            sql += ")";
            return CreateTableDB(sql);
        }

        public bool Login(int user, string pass)
        {
            // turn off DB error message
            display_error = false;
            int rc = RowCount(
                string.Format("{0} WHERE id={1} AND password='{2}'",
                tbl_name,
                user, pass)
            );

            // turn on DB error message
            display_error = true;
            if (rc > 0) return true;

            return false;
        }

        public override int dataGrid_Define(DataGridView dg, ArrayList col)
        {
            col.Add("Person ID");
            col.Add("Password");
            col.Add("Website");
            col.Add("Second Email");
            col.Add("Second Phone");

            return 0;
        }

        public override cBaseItem getNewRow()
        {
            return new cInstructor();
        }
    }
}
