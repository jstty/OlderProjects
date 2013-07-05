using System;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    class cInstructor : cBaseItem
    {
        public cInstructor()
        {
            data.Add(0); // string id
            data.Add(""); // string password max 32
            data.Add(""); // string website  max 256
            data.Add(""); // string s_email  max 128
            data.Add(""); // string s_phone  max 16
        }
    }
}
