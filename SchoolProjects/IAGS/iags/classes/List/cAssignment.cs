using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    class cAssignment : cBaseItem
    {
        public cAssignment()
        {
            data.Add(-1); // int assign_id   0 - 9999999999
            data.Add(0);  // int section_id  0 - 9999999999
            data.Add(""); // string name      max 32
            data.Add(0);  // byte type_num    0 - 99
                          // 0 = test, 1 = homework, 2 = lab, 3 = quiz
            data.Add(0);  // int max_points   0 - 9999999999
            data.Add(0);  // byte is_extra    0 - 1
            data.Add(""); // string details   max 1024
        }

        public override object RenderCell(int index)
        {
            if (index == 3)
            {
                // for drop list
                int n = Convert.ToInt32(data[index]);
                return cAssignmentList.AssignTypes[n];
            }
            else if (index == 5)
            {
                // for check box, true/false
                int n = Convert.ToInt32(data[index]);
                if (n > 0) return true;
                else       return false;
            }

            return base.RenderCell(index);
        }

        public override bool UpdateCell(int index, object value)
        {
            if (index + offset < data.Count)
            {
                if (index == 3)
                {
                    // for drop list
                    data[index] = cAssignmentList.AssignTypes.IndexOf(value.ToString());
                    is_new = false;
                    return true;
                }
                else if (index == 5)
                {
                    // for check box, true/false
                    int n = Convert.ToInt32(value);
                    data[index] = n;
                }

                return base.UpdateCell(index, value);
            }

            return false;
        }
    }
}
