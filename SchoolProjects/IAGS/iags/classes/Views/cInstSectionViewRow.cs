using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    class cInstSectionViewRow : cBaseItem
    {
        public cInstSectionViewRow()
        {
            offset = 5;

            data.Add(0);    // 0 - section_id (RO)
            data.Add(0);    // 1 - instructor ID (RO)
            data.Add(0);    // 2 - Year (RO)
            data.Add(0);    // 3 - Season Name(from season no.) (RO)
            data.Add(0);    // 4 - Course ID (RO)

            data.Add(0);    // 5 - units worth (RO)
            data.Add(0);    // 6 - CRN (RO)
            data.Add("");   // 7 - course short name (RO)
            data.Add(0);    // 8 - current number of students (RO)
            data.Add(0);    // 9 - max number of students (RO)
            data.Add(0.00); // 10 - min grade points (RO)
            data.Add(0.00); // 11 - max grade points (RO)
            data.Add(0.00); // 12 - avg grade points (RO)
        }

        public int ID
        {
            get
            {
                if (data[0] is int) return (int)data[0];
                else return -1;
            }
        }

        public int CID
        {
            get
            {
                if (data[4] is int) return (int)data[4];
                else return -1;
            }
        }

        public override string ToString()
        {
            string s = "";
            string s1 = data[7].ToString();
            string s2 = data[6].ToString();
            if (s1.Length > 0 &&
                s2.Length > 0)
            {
                s = string.Format("{0} ({1})", s1, s2);
            }

            return s;
        }
    }
}
