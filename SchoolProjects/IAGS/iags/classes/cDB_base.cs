using System;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    interface cDB_Base
    {
        void Connect();
        void Disconnect();

        // execute stored procedure
        int ExecProc(string func_sql);

        // execute SQL statement
        int ExecSQL(cDB obj, string sql, bool is_quary);

        // execute special select SQL statement
        int ExecSQL_RowCount(cDB obj, string sql, string tbl_name);
    }
}
