using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    class cCourseInfo : cBaseItem
    {
        public cCourseInfo()
        {
            data.Add(-1);  // int    course_id;
            data.Add(""); // string short_name;
            data.Add(""); // string long_name;
            data.Add(""); // string description;
            data.Add(0);  // ushort worth;
        }
    }
}

