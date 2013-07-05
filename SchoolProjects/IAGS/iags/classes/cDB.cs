using System;
using System.Windows.Forms;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.Data.OleDb;
using System.Data.Odbc;
using System.Data.Common;

namespace iags
{
    class cDB
    {
        // remove static, make base class for all lists
        // change to Ole

        protected int e = 0;
        protected static int type = 0; // 0 = MySQL, 1 = Oracle
        private string sqlCmd = "";
        private cDB_Base db = null;
        protected bool display_error = true;
        protected string tbl_name;

        public static string Type
        {
            set {
                if(value == "MySQL")
                    type = 0;
                else if(value == "Oracle")
                    type = 1;
            }

            get {
                if (type == 0)
                    return "MySQL";
                else if (type == 1)
                    return "Oracle";

                return "";
            }
        }

        private void Disconnect()
        {
            if(db != null) db.Disconnect();
        }

        private void Connect()
        {
            e = 0;
            Disconnect();

            if (type == 0)
            {
                db = new cDB_MySQL();
            }
            else if (type == 1)
            {
                db = new cDB_Oracle();
            }

#if false
            if(type == 0) {
                conStr += "DRIVER={MySQL ODBC 3.51 Driver};" +
                        "SERVER=127.0.0.1;" +
                        "DATABASE=test;" +
                        "UID=php;" +
                        "PASSWORD=12345;" +
                        "OPTION=3";     
            }
            else if (type == 1) {
                conStr += "DRIVER={Oracle ODBC Driver};" +
                    "SERVER=prover.cs.csubak.edu;" +
                    //"DATABASE=database;" +
                    "UID=cs342;" +
                    "PWD=student2";
            }
#endif

            try
            {
               db.Connect();

            } catch(SystemException exp) {
                string err = exp.Message;
                cIAGS.ErrorMsg = string.Format("Could not connect to \"{0}\" Database Server.", cDB.Type);
                MessageBox.Show(cIAGS.ErrorMsg, "DBMS Connection Error");

                e = 2;
            }
        }

        // DB_base object is going to call this function to custom fill the array list
        public virtual object ReadData(object[] row)
        {
            // overloaded in cDBItemList
            return null;
        }

        public void FillList(DbDataAdapter dbda)
        {
            using( DataTable dtbl = new DataTable(tbl_name) )
            {
                dbda.Fill(dtbl);

                for (int i = 0; i < dtbl.Rows.Count; ++i)
                {
                    ReadData(dtbl.Rows[i].ItemArray);
                }
            }
        }

        private int ExecSQL(string sql, bool is_quary)
        {
            Connect();

            try
            {
                if (sql.Length < 1)
                {
                    throw (new SystemException()); // error
                }

                db.ExecSQL(this, sql, is_quary);
            }
            catch(SystemException exp)
            {
                cIAGS.ErrorMsg = string.Format("Error In SQL execution.\n\"{0}\"\n\"{1}\"",
                    sql,
                    exp);

                if (cIAGS.DisplayError && display_error)
                    MessageBox.Show(cIAGS.ErrorMsg, "SQL Error");

                e = 1;
            }
            finally
            {
                Disconnect();
            }

            return e;
        }

        private int ExecSQL_RowCount(string sql)
        {
            int rc = 0;
            Connect();

            try  {
                if(sql.Length < 1)  {
                    throw (new SystemException()); // error
                }

                rc = db.ExecSQL_RowCount(this, sql, tbl_name);
            }
            catch (SystemException exp) {
                cIAGS.ErrorMsg = string.Format("Error In SQL execution.\n\"{0}\"\n\"{1}\"",
                    sql,
                    exp);

                if (cIAGS.DisplayError && display_error)
                    MessageBox.Show(cIAGS.ErrorMsg, "SQL Error");
            } finally {
                Disconnect();
            }

            return rc;
        }

        private int ExecProc(string sql)
        {
            Connect();

            try
            {
                if (sql.Length < 1)
                {
                    throw (new SystemException()); // error
                }

                db.ExecProc(sql);
            }
            catch (SystemException exp)
            {
                cIAGS.ErrorMsg = string.Format("Error In SQL execution.\n\"{0}\"\n\"{1}\"",
                    sql,
                    exp);

                if (cIAGS.DisplayError && display_error)
                    MessageBox.Show(cIAGS.ErrorMsg, "SQL Error");

                e = 1;
            }
            finally
            {
                Disconnect();
            }

            return e;
        }

        //
        public int Select(string sql)
        {
            sqlCmd = string.Format("SELECT {0}", sql);

            e = ExecSQL(sqlCmd, true);
            return e;
        }

        //
        public int SelectAll(string tbl_name)
        {
            sqlCmd = string.Format("SELECT * FROM {0}", tbl_name);

            e = ExecSQL(sqlCmd, true);
            return e;
        }

        public bool CheckTable(string tbl_name)
        {
            try
            {
                RowCount(tbl_name);
                return true;
            }
            catch (Exception exp)
            {
                string err = exp.Message; // error
            }
            
            return false;
        }

        //
        public int Insert(string tbl_name, string values)
        {
            sqlCmd = string.Format("INSERT INTO {0} VALUES ({1})", tbl_name, values);

            e = ExecSQL(sqlCmd, false);
            if(e != 0)
            {
                cIAGS.ErrorMsg = string.Format("DB: Error inserting into {0}\n{1}", tbl_name, sqlCmd);
            }

            return e;
        }

        //
        public int Update(string tbl_name, string values)
        {
            sqlCmd = string.Format("UPDATE {0} SET {1}", tbl_name, values);

            e = ExecSQL(sqlCmd, false);
            return e;
        }

        //
        public int Delete(string tbl_name, string values)
        {
            sqlCmd = string.Format("DELETE FROM {0} WHERE {1}", tbl_name, values);

            e = ExecSQL(sqlCmd, false);
            if(e != 0)
            {
                cIAGS.ErrorMsg = string.Format("DB: Error deleting record from {0}\n{1}", tbl_name, sqlCmd);
            }

            return e;
        }


        public int CreateSeq(string tbl_name)
        {
            sqlCmd = string.Format("CREATE SEQUENCE {0}_seq", tbl_name);
            sqlCmd += " MINVALUE 0";
            sqlCmd += " MAXVALUE 999999999";
            sqlCmd += " START WITH 100";

            e = ExecSQL(sqlCmd, false);
            if (e != 0)
            {
                cIAGS.ErrorMsg = string.Format("DB: Error creating sequence {0}\n{1}", tbl_name, sqlCmd);
            }

            return e;
        }

        public int CreateTable(string sql)
        {
            sqlCmd = string.Format("CREATE TABLE {0}", sql);

            e = ExecSQL(sqlCmd, false);
            if(e != 0)
            {
                cIAGS.ErrorMsg = string.Format("DB: Error creating table {0}\n{1}", tbl_name, sqlCmd);
            }

            return e;
        }

        public int CreateView(string sql)
        {
            sqlCmd = string.Format("CREATE OR REPLACE VIEW {0}", sql);
            e = ExecSQL(sqlCmd, false);
            if (e != 0)
            {
                cIAGS.ErrorMsg = string.Format("DB: Error creating view {0}\n{1}", tbl_name, sqlCmd);
            }

            return e;
        }

        public int CreateProc(string sql)
        {
            sqlCmd = string.Format("CREATE PROCEDURE {0}", sql);

            e = ExecSQL(sqlCmd, false);
            if (e != 0)
            {
                cIAGS.ErrorMsg = string.Format("DB: Error in creating stored procedure\n{0}", sqlCmd);
            }
            return e;
        }

        public int CreateFunc(string sql)
        {
            sqlCmd = string.Format("CREATE FUNCTION {0}", sql);

            e = ExecSQL(sqlCmd, false);
            if (e != 0)
            {
                cIAGS.ErrorMsg = string.Format("DB: Error in creating stored procedure\n{0}", sqlCmd);
            }
            return e;
        }

        public int DropSeq(string tbl_name)
        {
            sqlCmd = string.Format("DROP SEQUENCE {0}_seq", tbl_name);

            e = ExecSQL(sqlCmd, false);
            if (e != 0)
            {
                cIAGS.ErrorMsg = string.Format("DB: Error dropping sequence from {0}\n{1}", tbl_name, sqlCmd);
            }
            return e;
        }

        public int DropTable(string tbl_name)
        {
            sqlCmd = string.Format("DROP TABLE {0}", tbl_name);
            e = ExecSQL(sqlCmd, false);

            return e;
        }

        public int DropView(string tbl_name)
        {
            sqlCmd = string.Format("DROP VIEW {0}", tbl_name);

            e = ExecSQL(sqlCmd, false);
            if (e != 0)
            {
                cIAGS.ErrorMsg = string.Format("DB: Error dropping view from {0}\n{1}", tbl_name, sqlCmd);
            }
            return e;
        }

        public int DropProc(string tbl_name)
        {
            sqlCmd = string.Format("DROP PROCEDURE {0}", tbl_name);

            e = ExecSQL(sqlCmd, false);
            if (e != 0)
            {
                cIAGS.ErrorMsg = string.Format("DB: Error dropping stored procedure from {0}\n{1}", tbl_name, sqlCmd);
            }
            return e;
        }

        public int DropFunc(string tbl_name)
        {
            sqlCmd = string.Format("DROP FUNCTION {0}", tbl_name);

            e = ExecSQL(sqlCmd, false);
            if (e != 0)
            {
                cIAGS.ErrorMsg = string.Format("DB: Error dropping stored procedure from {0}\n{1}", tbl_name, sqlCmd);
            }
            return e;
        }


        public int RowCount(string sql)
        {
            sqlCmd = string.Format("SELECT COUNT(*) \"Count\" FROM {0}", sql);

            e = ExecSQL_RowCount(sqlCmd);
            return e;
        }

        public int ExecProcedure(string sql)
        {
            e = ExecProc(sql);
            if (e != 0)
            {
                cIAGS.ErrorMsg = string.Format("DB: Error in function execution\n{0}", sqlCmd);
            }
            return e;
        }
    }
}
