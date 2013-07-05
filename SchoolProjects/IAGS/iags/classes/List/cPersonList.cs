using System;
using System.Windows.Forms;
using System.Text;
using System.Collections;
using System.Collections.Generic;

namespace iags
{
    class cPersonList : cDBItemList
    {
        public cPersonList()
        {
            entity_name = "Person";
            tbl_name = "js_person";
            loadfile_name = "person.csv";

            nlist.Add("id");
            nlist.Add("fname");
            nlist.Add("mname");
            nlist.Add("lname");
            nlist.Add("p_email");
            nlist.Add("p_phone");
        }

        //
        public override int Create()
        {
            sql = tbl_name + "(";

            if (cDB.Type == "MySQL")
            {
                sql += "id      INTEGER      NOT NULL AUTO_INCREMENT,";
                sql += "fname   VARCHAR(64)  NOT NULL,";
                sql += "mname   VARCHAR(64),";
                sql += "lname   VARCHAR(64)  NOT NULL,";
                sql += "p_email VARCHAR(128),";
                sql += "p_phone VARCHAR(16),";

                sql += "PRIMARY KEY(id)";
            }
            else if (cDB.Type == "Oracle")
            {
                sql += "id      INTEGER      NOT NULL,";
                sql += "fname   VARCHAR2(64) NOT NULL,";
                sql += "mname   VARCHAR2(64) ,";
                sql += "lname   VARCHAR2(64) NOT NULL,";
                sql += "p_email VARCHAR2(128),";
                sql += "p_phone VARCHAR2(16) ,";

                sql += "PRIMARY KEY(id)";
            }

            sql += ")";
            return CreateTableDB(sql);
        }

        public bool Login(int user)
        {
            // turn off DB error message
            display_error = false;
            int rc = RowCount(tbl_name + " WHERE id=" + user);

            // turn on DB error message
            display_error = true;
            if (rc > 0) return true;

            return false;
        }

        public override int dataGrid_Define(DataGridView dg, ArrayList col)
        {
            col.Add("Person ID");
            col.Add("First Name");
            col.Add("Middle Name");
            col.Add("Last Name");
            col.Add("Primary Email");
            col.Add("Primary Phone");

            return 0;
        }

        public override cBaseItem getNewRow()
        {
            return new cPerson();
        }


        // get a person object based on id
        public cPerson GetPerson(int id)
        {
            cPerson p = new cPerson();
            int size = dlist.Count;

            string sql = string.Format("* FROM {0} WHERE {1}={2}",
                tbl_name,
                nlist[0],
                id);

            // the select will fill the dlist array
            Select(sql);

            // after copying person over, now delete from array
            if(dlist.Count > size) {
                p = (cPerson)dlist[size];
                dlist.RemoveAt(size);
            }

            return p;
        }
    }
}
