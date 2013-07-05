using System;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.Data.Odbc;

namespace iags
{
    class cDB_MySQL : cDB_Base
    {
        private OdbcConnection dbCon = null;
        private OdbcCommand dbCmd = null;

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
            conStr = "DRIVER={MySQL ODBC 3.51 Driver};" +
                     "SERVER=localhost;" +
                     "DATABASE=test;" +
                     "UID=php;" +
                     "PASSWORD=12345;" +
                     "OPTION=3";

            dbCon = new OdbcConnection(conStr);
        }

        // execute stored procedure
        public int ExecProc(string func_sql)
        {
            string sql = string.Format("EXECUTE {0}", func_sql);
            dbCmd = new OdbcCommand(sql, dbCon);
            dbCon.Open();
            dbCmd.ExecuteNonQuery();

            return 0;
        }

        // execute SQL statement
        public int ExecSQL(cDB obj, string sql, bool is_quary)
        {
            dbCmd = new OdbcCommand(sql, dbCon);
            dbCon.Open();

            if(is_quary)
            {
                // select
                using(OdbcDataReader dbr = dbCmd.ExecuteReader())
                {
                    int count;
                    object[] row;
                    while (dbr.Read())
                    {
                        // read each row at a time
                        count = dbr.FieldCount;
                        row = new object[count];
                        dbr.GetValues(row);
                        obj.ReadData(row);
                    }
                }
            }
            else
            {
                // delete, create, update, insert
                dbCmd.ExecuteNonQuery();
            }

            return 0;
        }

        // execute special select SQL statement
        public int ExecSQL_RowCount(cDB obj, string sql, string tbl_name)
        {
            int rc = 0;
            dbCmd = new OdbcCommand(sql, dbCon);
            dbCon.Open();

            using(OdbcDataReader dbr = dbCmd.ExecuteReader()) {

                int count;
                object[] row;
                if(dbr.Read())
                {
                    count = dbr.FieldCount;
                    row = new object[count];
                    dbr.GetValues(row);
                    rc = Convert.ToInt32(row[0]);
                }
            }

            return rc;
        }

    }
}
