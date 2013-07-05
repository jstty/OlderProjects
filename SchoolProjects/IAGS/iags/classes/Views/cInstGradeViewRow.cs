using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    class cGradeViewRow : cBaseItem
    {
        public cGradeViewRow()
        {
            offset = 3;
            data.Add(-1);  // 0 - section id (RO)
            data.Add(-1);  // 1 - assignment id  (RO)
            data.Add("");  // 2 - assignment name  (RO)

            data.Add(0);   // 3 - student id  (RO)
            data.Add("");  // 4 - student name  (RO)
            data.Add(0);   // 5 - points  (RW)
            data.Add(0);   // 6 - max points (RO)
            data.Add(0);   // 7 - is extra (RO)
            data.Add("");  // 8 - details (RW)
        }

        public override object RenderCell(int index)
        {
            if (index == 4)
            {
                // for check box, true/false
                int n = Convert.ToInt32(data[index + offset]);
                if (n > 0) return true;
                else return false;
            }

            return base.RenderCell(index);
        }

        public override bool UpdateCell(int index, object value)
        {
            if (index + offset < data.Count)
            {
                if (index == 4)
                {
                    // for check box, true/false
                    int n = Convert.ToInt32(value);
                    data[index + offset] = n;
                }

                return base.UpdateCell(index, value);
            }

            return false;
        }
    }
}
