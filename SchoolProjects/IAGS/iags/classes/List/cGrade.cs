using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    class cGrade : cBaseItem
    {
        public cGrade()
        {
            data.Add(-1);  // int grade_id;       max 999999999999
            data.Add(0);  // int assign_id;      max 999999999999
            data.Add(0);  // int id;             max 999999999999
            data.Add(0);  // int points;         max 999999999999
            data.Add(new DateTime()); // DateTime date_entered;
            data.Add(""); // string   details    max 1024
        }
    }
}
