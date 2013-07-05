using System;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;

namespace iags
{
    class cAssignmentList : cDBItemList
    {
        public static ArrayList AssignTypes;

        // select * from js_assign;
        public cAssignmentList()
        {
            entity_name = "Assignment";
            tbl_name = "js_assign";
            loadfile_name = "assign.csv";

            nlist.Add("assign_id");
            nlist.Add("section_id");
            nlist.Add("name");
            nlist.Add("type_num");
            nlist.Add("max_points");
            nlist.Add("is_extra");
            nlist.Add("details");

            cAssignmentList.AssignTypes = new ArrayList();
            cAssignmentList.AssignTypes.Add("Lab");
            cAssignmentList.AssignTypes.Add("Quiz");
            cAssignmentList.AssignTypes.Add("Test");
            cAssignmentList.AssignTypes.Add("Mid Term");
            cAssignmentList.AssignTypes.Add("Final");
        }

        //
        public override int Create()
        {
            sql = tbl_name + "(";

            if(cDB.Type == "MySQL")
            {
                sql += "assign_id    INTEGER       NOT NULL AUTO_INCREMENT,";
                sql += "section_id   INTEGER       NOT NULL,";
                sql += "name         VARCHAR(64)   NOT NULL,";
                sql += "type_num     INTEGER       NOT NULL,";
                sql += "max_points   INTEGER       NOT NULL,";
                sql += "is_extra     INTEGER       NOT NULL,";
                sql += "details      VARCHAR(1024),";

                sql += "PRIMARY KEY(assign_id),";
                sql += "FOREIGN KEY(section_id) REFERENCES js_section(section_id)";
            }
            else if (cDB.Type == "Oracle")
            {
                sql += "assign_id    INTEGER        NOT NULL,";
                sql += "section_id   INTEGER        NOT NULL,";
                sql += "name         VARCHAR2(64)   NOT NULL,";
                sql += "type_num     NUMBER(2)      NOT NULL,";
                sql += "max_points   INTEGER        NOT NULL,";
                sql += "is_extra     NUMBER(2)      NOT NULL,";
                sql += "details      VARCHAR2(1024) ,";

                sql += "PRIMARY KEY(assign_id),";
                sql += "FOREIGN KEY(section_id) REFERENCES js_section(section_id)";
            }

            sql += ")";
            return CreateTableDB(sql);
        }

        public override int dataGrid_Define(DataGridView dg, ArrayList col)
        {
            col.Add("Assign ID");
            col.Add("Section ID");
            col.Add("Name");
            
            DataGridViewComboBoxColumn cc = new DataGridViewComboBoxColumn();
            cc.Name = cc.HeaderText = "Type No.";
            cc.Items.AddRange(cAssignmentList.AssignTypes.ToArray());
            col.Add(cc);

            col.Add("Max Points");

            DataGridViewCheckBoxColumn cb = new DataGridViewCheckBoxColumn();
            cb.Name = cb.HeaderText = "Is Extra";
            col.Add(cb);

            col.Add("Details");

            return 0;
        }

        public override cBaseItem getNewRow()
        {
            return new cAssignment();
        }

    }
}
