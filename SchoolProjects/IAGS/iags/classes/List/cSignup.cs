using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    class cSignup : cBaseItem
    {
        public cSignup()
        {
            data.Add(-1);   // int id    fk(person) who student
            data.Add(0);   // int section_id   pk

            data.Add("");  // string grade_letter  max 4
            data.Add(0.0); // double grade_points
            data.Add("");  // string details       max 1024, null allowed
        }
    }
}
