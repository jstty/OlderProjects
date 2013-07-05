using System;
using System.Windows.Forms;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    class cDBItemList : cDB
    {
        protected cBaseItem current_editrow; // current row when editing
        protected ArrayList dlist; // row data from table
        protected ArrayList nlist; // column name list
        protected string sql = "";
        protected string loadfile_name = "";
        protected string entity_name = "";
        protected cSqlValueList vlist;

        public cDBItemList()
        {
            dlist = new ArrayList();
            nlist = new ArrayList();
            vlist = new cSqlValueList();
        }

        // override base class ToString
        public override string ToString()
        {
            return entity_name;
        }

        public virtual void Clear()
        {
            dlist.Clear();
        }

        public virtual int count
        {
            get {
                return dlist.Count;
            }
        }

        public virtual int Init()
        {
            // do nothing
#if false
            if(!CheckTable(tbl_name))
            {
                Create();
                MessageBox.Show(string.Format("Table \"{0}\" does not exist.", tbl_name));
                LoadFromFile();
            }
#endif

            return 0;
        }

        public virtual int LoadFromFile()
        {
            ArrayList item_list = new ArrayList();

            try
            {
                cIAGS.ProgReset();
                cIAGS.SetProgText(
                    string.Format("Loading {0} from File...", entity_name)
                    );

                if (!File.Exists(loadfile_name))
                {
                    cIAGS.ErrorMsg = "Could not Load File (" + loadfile_name + ").";
                    throw new Exception();
                }

                // read file to data buffer
                // pars file
                using (StreamReader sr = File.OpenText(loadfile_name))
                {
                    string tmp;
                    while ((tmp = sr.ReadLine()) != null)
                    {
                        item_list.Add(tmp.Split(','));
                    }
                    sr.Close();
                }

                cIAGS.SetProgText(
                    string.Format("Inserting {0} data into DB...", entity_name)
                    );
                // insert list to SQL DB
                //cIAGS.GetProgRange(0, item_list.Count);
                cIAGS.SetProgMinMax(0, item_list.Count);
                for (int i = 0; i < item_list.Count; ++i)
                {
                    object o = ReadData((string[])item_list[i]);

                    e = InsertDB(o);
                    if (e != 0)
                    {
                        throw new Exception();
                    }

                    cIAGS.SetProgValue(i);
                }
            }
            catch (Exception exp)
            {
                // error
                cIAGS.PopupError(exp);
                return 1;
            }

            return 0;
        }

        //
        public virtual int SaveToFile()
        {
            cIAGS.ProgReset();
            cIAGS.SetProgText(
                string.Format("Getting {0} Data from DB...", entity_name)
                );
            SelectAll();

            //
            cIAGS.SetProgText(
                    string.Format("Saving {0} to File...", entity_name)
                );
            cIAGS.SetProgMinMax(0, dlist.Count);
            try
            {
                
                // write file
                using (StreamWriter sw = new StreamWriter(loadfile_name))
                {
                    for (int i = 0; i < dlist.Count; ++i)
                    {
                        WriteEntity(sw, i);
                        // update progress
                        cIAGS.SetProgValue(i);
                    }
                    sw.Close();
                }                
            } catch(Exception exp)
            {
                string err = exp.Message; // error
                return 1;
            }

            return 0;
        }

        public virtual void WriteEntity(StreamWriter sw, int i)
        {
            cSqlValueList vlist = new cSqlValueList();
            cBaseItem be = null;
            be = (cBaseItem)dlist[i];
            if (be != null)
            {
                vlist.Reset();
                vlist.Mode = 1; // for file

                for (int j = 0; j < be.data.Count; ++j)
                {
                    vlist.Add(be.data[j]);
                }

                // write line to file
                sw.WriteLine(vlist.SQL);
            }
        }

        public virtual int Create() { return 1; }

        public virtual int CreateTableDB(string sql)
        {
            int e = 0;
            if (type == 1) e = CreateSeq(tbl_name);
            e += CreateTable(sql);
            return e;
        }

        // drop sequance and table
        public virtual int DropTable()
        {
            int e = 0;
            if(type == 1) e = DropSeq(tbl_name);
            e += DropTable(tbl_name);
            return e;
        }

        public virtual int DropView()
        {
            int e = 0;
            e += DropView(tbl_name);
            return e;
        }

        public virtual int SelectAll()
        {
            Clear();
            return SelectAll(tbl_name);
        }

        public virtual int InsertDB(object o)
        {
            cBaseItem d = (cBaseItem)o;
            if (d != null)
            {
                vlist.Reset();
                int i = 0;

                // if index -1 then, need to use seqance
                if (((int)d.data[0]) == -1)
                {
                    vlist.AddSeqNextValue(tbl_name);
                    i++;
                }

                for(; i < d.data.Count; i++)
                {
                    vlist.Add(d.data[i]);
                }

                return Insert(tbl_name, vlist.SQL);
            }

            return 1;
        }

        public virtual int UpdateDB(object o)
        {
            cBaseItem d = (cBaseItem)o;
            if (d != null)
            {
                vlist.Reset();

                // don't update index
                for (int i = 1; i < nlist.Count; i++)
                    vlist.Add(nlist[i].ToString(), d.data[i]);

                string sql = string.Format("{0} WHERE {1}={2}", vlist.SQL, nlist[0], d.data[0]);

                return Update(tbl_name, sql);
            }

            return 1;
        }

        public virtual int DeleteDB(object o)
        {
            cBaseItem d = (cBaseItem)o;
            if (d != null)
            {
                vlist.Reset();
                vlist.Add(nlist[0].ToString(), d.data[0]);

                return Delete(tbl_name, vlist.SQL);
            }

            return 1;
        }

        public virtual int dataGrid_Define(DataGridView dg, ArrayList col) { return 0; }

        // -----------------------------------------
        // DataGrid Events
        // read from internal ArrayList
        public virtual void dataGrid_CellValueNeeded(DataGridView dg, DataGridViewCellValueEventArgs e)
        {
            if (e.RowIndex < dlist.Count)
            {
                cBaseItem d = (cBaseItem)dlist[e.RowIndex];
                e.Value = d.RenderCell(e.ColumnIndex);
            } else {
                // if displaying new row
                if (current_editrow != null)
                {
                    cBaseItem d = current_editrow;
                    e.Value = d.RenderCell(e.ColumnIndex);
                }

            }
        }

        // write to current
        public virtual void dataGrid_CellValuePushed(DataGridViewCellValueEventArgs e)
        {
            // if no current get selected as current
            if(current_editrow == null)
            {
                if (e.RowIndex < dlist.Count)
                {
                    current_editrow = (cBaseItem)dlist[e.RowIndex];
                }
            }

            // edit
            if (current_editrow != null)
            {
                cBaseItem d = current_editrow;
                try
                {
                    d.UpdateCell(e.ColumnIndex, e.Value);
                }
                catch (Exception exp)
                {
                    string err = exp.Message; // error
                    MessageBox.Show("Invalid data type.\nError: 1");
                }
            }
        }

        public virtual cBaseItem getNewRow()
        {
            return new cBaseItem();
        }

        // DB_base object is going to call this function to custom fill the array list
        public override object ReadData(object[] row)
        {
            cBaseItem d = getNewRow();

            if (row.Length == d.data.Count)
            {
                Type t;
                for (int i = 0; i < row.Length; i++)
                {
                    t = d.data[i].GetType();
                    
                    // prevent exception thrown when setting data type
                    // if null then set a empty string
                    if (row[i] is DBNull) {
                        row[i] = "";
                    }

                    // if string
                    if(row[i] is string)
                    {
                        string s = row[i].ToString();

                        // if empty string and expecting not a string
                        if ( (s.Length < 1) &&
                             !(d.data[i] is string))
                        {
                            d.data[i] = Convert.ChangeType(0, t);
                        }
                        else
                        {
                            // expecting a string
                            if (d.data[i] is string)
                            {
                                s = s.Replace("\\:", ",");  // replace all "\:" with commas ","
                                s = s.Replace("\\n", "\n"); // replace all "\n" with linefeeds
                                s = s.Replace("\\r", "\r"); // replace all "\r" with returns
                            }

                            d.data[i] = Convert.ChangeType(s, t);
                        }
                    } else {
                    // if type not string
                        d.data[i] = Convert.ChangeType(row[i], t);
                    }
                }

                d.already_inDB = true;
                d.is_new = false;
                dlist.Add(d);
                return d;
            }

            return null;
        }

        public virtual void dataGrid_NewRowNeeded(DataGridViewRowEventArgs e)
        {
            current_editrow = getNewRow();
        }

        // Finished editing a row, now write changed row out
        public virtual void dataGrid_RowValidating(DataGridViewCellCancelEventArgs e)
        {
            display_error = false;

            if(current_editrow != null)
            {
                // insert new, or update existing
                if(!current_editrow.is_new)
                {
                    int error = InsertUpdate(current_editrow);
                    if (error != 0) throw new Exception();

                    current_editrow = null;
                }
            }
        }

        public virtual void dataGrid_CancelRowEdit(QuestionEventArgs e)
        {
            current_editrow = null;
        }

        public virtual void dataGrid_UserDeletingRow(DataGridViewRowCancelEventArgs e)
        {
            int error = 0;
            if (e.Row.Index < dlist.Count)
            {
                cBaseItem d = (cBaseItem)dlist[e.Row.Index];
                error = DeleteDB(d);

                // if no error
                if (error == 0)
                    dlist.RemoveAt(e.Row.Index);
            }

            if (error != 0) throw new Exception();
        }
        // -----------------------------------------


        public virtual int UpdateView()
        {
            return SelectAll();
        }

        public virtual int InsertUpdate(cBaseItem d)
        {
            if (d.already_inDB) {
                return UpdateDB(d);
            } else {
                int e = InsertDB(d);
                if (e == 0)
                {
                    d.already_inDB = true;
                    dlist.Add(d);
                }

                return e;
            }
        }

    }
}
