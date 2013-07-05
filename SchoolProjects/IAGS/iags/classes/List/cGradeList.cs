using System;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    class cGradeList : cDBItemList
    {
        // select * from js_grade;
        public cGradeList()
        {
            entity_name = "Grade";
            tbl_name = "js_grade";
            loadfile_name = "grade.csv";

            nlist.Add("grade_id");
            nlist.Add("assign_id");
            nlist.Add("id");
            nlist.Add("points");
            nlist.Add("date_entered");
            nlist.Add("details");
        }

        //
        public override int Create()
        {
            sql = tbl_name + "(";

            if (cDB.Type == "MySQL")
            {
                sql += "grade_id     INTEGER      NOT NULL AUTO_INCREMENT,";
                sql += "assign_id    INTEGER      NOT NULL,";
                sql += "id           INTEGER      NOT NULL,";
                sql += "points       INTEGER      NOT NULL,";
                sql += "date_entered DATETIME     NOT NULL,";
                sql += "details      VARCHAR(1024),";

                sql += "PRIMARY KEY(grade_id),";
                sql += "FOREIGN KEY(assign_id) REFERENCES js_assign(assign_id),";
                sql += "FOREIGN KEY(id)        REFERENCES js_person(id)";
            }
            else if (cDB.Type == "Oracle")
            {
                sql += "grade_id     INTEGER      NOT NULL,";
                sql += "assign_id    INTEGER      NOT NULL,";
                sql += "id           INTEGER      NOT NULL,";
                sql += "points       INTEGER      NOT NULL,";
                sql += "date_entered DATE         NOT NULL,";
                sql += "details      VARCHAR2(1024),";

                sql += "PRIMARY KEY(grade_id),";
                sql += "FOREIGN KEY(assign_id) REFERENCES js_assign(assign_id),";
                sql += "FOREIGN KEY(id)        REFERENCES js_person(id)";
            }

            sql += ")";
            return CreateTableDB(sql);
        }

        public override int dataGrid_Define(DataGridView dg, ArrayList col)
        {
            col.Add("Grade ID");
            col.Add("Assign ID");
            col.Add("Person ID");
            col.Add("Points");
            col.Add("Date Entered");
            col.Add("Details");

            return 0;
        }

        public override cBaseItem getNewRow()
        {
            return new cGrade();
        }
    }
}
