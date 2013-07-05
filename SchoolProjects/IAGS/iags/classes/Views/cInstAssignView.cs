using System;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;

namespace iags
{
    class cInstAssignView : cDBItemList
    {
        // 0 - assign id (RO)
        // 1 - section id (RO)

        // 2 - assignment name (RW)
        // 3 - assignment type (RW)
        // 4 - is extra (RW)
        // 5 - max points (RW)
        // 6 - student min points (RO)
        // 7 - student max points (RO)
        // 8 - student avg points (RO)
        // 9 - details (RW)

        public cInstAssignView()
        {
            entity_name = "Instructor Assignment View";
            tbl_name = "js_assign_inst_view";

            // for update
            nlist.Add("a.assign_id");
            nlist.Add("a.section_id");
            nlist.Add("a.name");
            nlist.Add("a.type_num");
            nlist.Add("a.is_extra");
            nlist.Add("a.max_points");
            nlist.Add("MIN(g.points) min_pts");
            nlist.Add("MAX(g.points) max_pts");
            nlist.Add("AVG(g.points) avg_pts");
            nlist.Add("a.details");
        }

        public override int DropTable()
        {
            return DropView();
        }

        public override int Create()
        {
            sql = "";
            string from = "";

            if (cDB.Type == "Oracle" )
            {
                from = "js_assign a, js_grade g WHERE a.assign_id = g.assign_id(+)";
            }
            else if (cDB.Type == "MySQL")
            {
                from = "js_assign a LEFT JOIN js_grade g ON(a.assign_id = g.assign_id)";
            }

            sql = string.Format(
                @"{0} AS 
                SELECT {1}
                FROM {2} 
                GROUP BY a.assign_id, a.section_id, a.name,
                         a.type_num, a.is_extra, a.max_points,
                         a.details",
                tbl_name,
                cSqlValueList.Implode(nlist),
                from);

            return CreateView(sql);
        }

        public override cBaseItem getNewRow()
        {
            return new cInstAssignViewRow();
        }

        public override int dataGrid_Define(DataGridView dg, ArrayList col)
        {
            int i;
            DataGridViewTextBoxColumn[] tb = new DataGridViewTextBoxColumn[6];

            for (i = 0; i < 6; i++)
            {
                tb[i] = new DataGridViewTextBoxColumn();
            }

            tb[0].Name = tb[0].HeaderText = "Name";
            tb[0].Width = 75;
            col.Add(tb[0]);

            DataGridViewComboBoxColumn cc = new DataGridViewComboBoxColumn();
            cc.Name = cc.HeaderText = "Type No.";
            cc.Items.AddRange(cAssignmentList.AssignTypes.ToArray());
            col.Add(cc);

            DataGridViewCheckBoxColumn cb = new DataGridViewCheckBoxColumn();
            cb.Name = cb.HeaderText = "Is Extra";
            col.Add(cb);

            tb[1].Name = tb[1].HeaderText = "Max Points";
            tb[1].Width = 60;
            col.Add(tb[1]);

            tb[2].Name = tb[2].HeaderText = "Student Min. Points";
            tb[2].ReadOnly = true;
            tb[2].DefaultCellStyle.BackColor = System.Drawing.SystemColors.Control;
            tb[2].Width = 60;
            col.Add(tb[2]);

            tb[3].Name = tb[3].HeaderText = "Student Max. Points";
            tb[3].ReadOnly = true;
            tb[3].DefaultCellStyle.BackColor = System.Drawing.SystemColors.Control;
            tb[3].Width = 60;
            col.Add(tb[3]);

            tb[4].Name = tb[4].HeaderText = "Student Avg. Points";
            tb[4].ReadOnly = true;
            tb[4].DefaultCellStyle.BackColor = System.Drawing.SystemColors.Control;
            tb[4].Width = 60;
            col.Add(tb[4]);

            tb[5].Name = tb[5].HeaderText = "Details";
            tb[5].Width = 125;
            col.Add(tb[5]);

            return 0;
        }


        public override int SelectAll()
        {
            Clear();
            string sql = "";

            if ((cDB.Type == "Oracle") || (cDB.Type == "MySQL"))
            {
                sql = string.Format(
                    @"* FROM {0} WHERE section_id={1}",
                    tbl_name,
                    Program.main.CurrentSection);
            }

            return Select(sql);
        }

        public override int InsertDB(object o)
        {
            // custom update assignment
            cInstAssignViewRow d = (cInstAssignViewRow)o;
            if (d != null)
            {
                vlist.Reset();

                vlist.AddSeqNextValue("js_assign");
                vlist.Add(Program.main.CurrentSection);
                vlist.Add(d.data[2]);
                vlist.Add(d.data[3]);
                vlist.Add(d.data[4]);
                vlist.Add(d.data[5]);
                vlist.Add(d.data[9]);

                return Insert("js_assign", vlist.SQL);
            }

            return 1;
        }

        public override int UpdateDB(object o)
        {
            // custom update assignment
            cInstAssignViewRow d = (cInstAssignViewRow)o;
            if (d != null)
            {
                vlist.Reset();

                vlist.Add("name", d.data[2]);       // assignment name
                vlist.Add("type_num", d.data[3]);   // assignment type           
                vlist.Add("is_extra", d.data[4]);   // is extra
                vlist.Add("max_points", d.data[5]); // max points
                vlist.Add("details", d.data[9]);    // details

                string sql = string.Format("{0} WHERE assign_id={1}",
                    vlist.SQL,
                    d.data[0]
                    );

                return Update("js_assign", sql);
            }

            return 1;
        }

        public override int DeleteDB(object o)
        {
            cInstAssignViewRow d = (cInstAssignViewRow)o;
            if (d != null)
            {
                vlist.Reset();
                vlist.Add("assign_id", d.data[0]);

                return Delete("js_assign", vlist.SQL);
            }

            return 1;
        }

        public cInstAssignViewRow GetRow(int row)
        {
            if (row < dlist.Count)
            {
                cInstAssignViewRow d = (cInstAssignViewRow)dlist[row];
                return d;
            }

            return null;
        }

        // for row selection
        public int GetIndex(int id)
        {
            for (int i = 0; i < dlist.Count; i++)
            {
                cInstAssignViewRow d = (cInstAssignViewRow)dlist[i];
                if (d != null)
                {
                    if (id == d.ID) return i;
                }
            }

            return 0;
        }
    }
}
