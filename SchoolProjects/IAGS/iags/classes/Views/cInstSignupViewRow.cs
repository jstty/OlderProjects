using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    class cInstSignupViewRow : cBaseItem
    {
        public cInstSignupViewRow()
        {
            offset = 3;
            data.Add(0); // 0 - year (RO)
            data.Add(0); // 1 - season number (RO)
            data.Add(0); // 2 - section id (RO)

            data.Add(0);    // 3 - student id (RO)
            data.Add("");   // 4 - student name (RO)
            data.Add("");   // 5 - student final grade letter (RW)
            data.Add(0.00); // 6 - student total grade points (RW)
            data.Add(0.00); // 7 - student calc grade points (RO)
            data.Add("");   // 8 - details (RW)
        }

        public string Last4ID
        {
            get
            {
                string s = string.Format("{0:0000}", (int)data[3]);
                return s.Substring(s.Length - 4);
            }
        }

        public string GradePoints
        {
            get
            {
                return string.Format("{0:00.0}%", (double)data[6]);
            }
        }

        public string GradeLetter
        {
            get
            {
                return (string)data[5];
            }
        }

    }
}
