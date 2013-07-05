using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    class cSqlValueList
    {
        private string sql;
        private int count;
        private bool add_comma = true;
        public int Mode = 0;

        public string SQL {
            get {
                return sql;
            }
        }

        public cSqlValueList()
        {
            Reset();
        }

        public void Reset()
        {
            sql = "";
            count = 0;
        }

        public static string Implode(ArrayList al)
        {
            string s = "";
            for (int i = 0; i < al.Count; i++)
            {
                s += al[i].ToString();
                if (i + 1 < al.Count)
                {
                    s += ',';
                }
            }

            return s;
        }
        
        private void AddComma()
        {
            if (add_comma && (count > 0)) sql += ',';

            ++count;
        }

        public void AddNULL()
        {
            AddComma();
            sql += "NULL";
        }

        public void AddSeqNextValue(string tbl_name)
        {
            AddComma();

            if (cDB.Type.CompareTo("Oracle") == 0)
                sql += string.Format("{0}_seq.nextval", tbl_name);
            else
                sql += "NULL";
        }


        // special add two
        public void Add(string cname, object data)
        {
            if (count > 0) sql += ',';
            add_comma = false;

            sql += cname + "=";
            Add(data);
            add_comma = true;
        }


        public void Add(object o)
        {
            if (o == null)        AddNULL();
            else if (o is bool)   Add((bool)o);
            else if (o is byte)   Add((byte)o);
            else if (o is double) Add((double)o);
            else if (o is Int16)  Add((Int16)o);
            else if (o is Int32)  Add((Int32)o);
            else if (o is UInt16) Add((UInt16)o);
            else if (o is UInt32) Add((UInt32)o);
            else if (o is String) Add((String)o);
            else if (o is DateTime) Add((DateTime)o);
        }

        public void Add(string s)
        {
            AddComma();

            if (Mode == 1) // file
            {
                s = s.Replace(",", "\\:"); // replace all commas with \:
                s = s.Replace("\n", "\\n"); // replace all linefeeds with \n
                s = s.Replace("\r", "\\r"); // replace all returns with \r

                sql += s;
            }
            else
            {
                s = s.Trim(); // remove white space, from start and end

                // escape string
                s = s.Replace("\\", "\\\\"); // '\'  -> '\''\'
                s = s.Replace("\"", "\\\""); // '"'  -> '\''"'
                s = s.Replace("'", "\\'");   // '''  -> '\''''
                s = s.Replace("\n", "\\n");  // '\n' -> '\''n'
                s = s.Replace("\r", "\\r");  // '\r' -> '\''r'
                s = s.Replace("\x00", "\\x00"); // '\x00' -> '\''x''0''0'
                s = s.Replace("\x1a", "\\x1a"); // '\x1a' -> '\''x''1''a'

                sql += "'" + s + "'";
            }
        }

        public void Add(int d)
        {
            AddComma();
            sql += d;
        }

        public void Add(uint d)
        {
            AddComma();
            sql += d;
        }

        public void Add(byte d)
        {
            AddComma();
            sql += d;
        }

        public void Add(bool d)
        {
            AddComma();
            sql += d;
        }

        public void Add(short d)
        {
            AddComma();
            sql += d;
        }

        public void Add(ushort d)
        {
            AddComma();
            sql += d;
        }

        public void Add(float d)
        {
            AddComma();
            sql += d;
        }

        public void Add(double d)
        {
            AddComma();
            sql += d;
        }

        public void Add(DateTime d)
        {
            AddComma();

            if (Mode == 1) // file
            {
                sql += string.Format("{0} {1}",
                        d.ToShortDateString(),
                        d.ToLongTimeString());
            }
            else
            {
                if (cDB.Type == "MySQL")
                {
                    // yyyy-MM-dd H:mm:ss
                    sql += string.Format("\'{0}\'",
                                d.ToString("u").TrimEnd('Z')
                            );
                }
                else if (cDB.Type == "Oracle")
                {
                    // mm/dd/yyyy hh:mi:ss am
                    sql += string.Format("to_date(\'{0} {1}\', \'mm/dd/yyyy hh:mi:ss am\')",
                        d.ToShortDateString(),
                        d.ToLongTimeString());
                }
            }
        }

    }
}
