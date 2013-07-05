using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    class cPerson : cBaseItem
    {
        public cPerson()
        {
            data.Add(-1);   // int    id
            data.Add(""); // string fname    max 64
            data.Add(""); // string mname    max 64
            data.Add(""); // string lname    max 64
            data.Add(""); // string p_email max 128
            data.Add(""); // string p_phone max 16
        }

        // override base class ToString
        public override string ToString()
        {
            return string.Format("{0} {1} {2}", data[1], data[2], data[3]);
        }
    }
}
