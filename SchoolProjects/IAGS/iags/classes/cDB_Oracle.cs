using System;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.Data.OleDb;
using System.Data.Common;

namespace iags
{
    class cDB_Oracle : cDB_Base
    {
        private OleDbConnection dbCon = null;
        private OleDbCommand dbCmd = null;

        public void Disconnect()
        {
            if (dbCon != null)
            {
                dbCon.Close();
                dbCon.Dispose();
                dbCon = null;
            }
        }

        public void Connect()
        {
            string conStr = "";
            conStr = "Provider=MSDAORA.1;" +
                     "User ID=cs342;" +
                     "Password=student2;" +
                     "Data Source=PROVERDB";

            dbCon = new OleDbConnection(conStr);
        }

        // execute stored procedure
        public int ExecProc(string func_sql)
        {
            dbCmd = new OleDbCommand(func_sql, dbCon);
            dbCon.Open();
            dbCmd.CommandType = CommandType.StoredProcedure;
            dbCmd.ExecuteNonQuery();

            return 0;
        }

        // execute SQL statement
        public int ExecSQL(cDB obj, string sql, bool is_quary)
        {
            if(is_quary)
            {
                // select
                using( DbDataAdapter dbda = new OleDbDataAdapter(sql, dbCon) )
                {
                    obj.FillList(dbda);
                }
            }
            else
            {
                // delete, create, update, insert
                dbCmd = new OleDbCommand(sql, dbCon);
                dbCon.Open();
                dbCmd.ExecuteNonQuery();
            }

            return 0;
        }

        // execute special select SQL statement
        public int ExecSQL_RowCount(cDB obj, string sql, string tbl_name)
        {
            int rc = 0;
            using(DbDataAdapter dbda = new OleDbDataAdapter(sql, dbCon))
            {
                using(DataTable dtbl = new DataTable(tbl_name))
                {
                    dbda.Fill(dtbl);

                    if (dtbl.Rows.Count > 0)
                    {
                        if (dtbl.Rows[0].ItemArray.Length > 0)
                        {
                            rc = Convert.ToInt32(dtbl.Rows[0].ItemArray[0]);
                        }
                    }
                }
            }

            return rc;
        }
    }
}
