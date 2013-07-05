using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    class cInstAssignViewRow : cBaseItem
    {
        public cInstAssignViewRow()
        {
            offset = 2;
            data.Add(-1);   // 0 - assign id (RO)
            data.Add(0);    // 1 - section id (RO)

            data.Add("");   // 2 - assignment name (RW)
            data.Add(0);    // 3 - assignment type (RW)
            data.Add(0);    // 4 - is extra (RW)
            data.Add(0);    // 5 - max points (RW)
            data.Add(0);    // 6 - student min points (RO)
            data.Add(0);    // 7 - student max points (RO)
            data.Add(0.00); // 8 - student avg points (RO)
            data.Add("");   // 9 - details (RW)
        }

        public int ID
        {
            get
            {
                return (int)data[0];
            }
        }

        public override string ToString()
        {
            string s = data[2].ToString();
            return s;
        }

        public override object RenderCell(int index)
        {
            if (index == 1)
            {
                // for drop list
                int n = Convert.ToInt32(data[index + offset]);
                return cAssignmentList.AssignTypes[n];
            }
            else if (index == 2)
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
                if (index == 1)
                {
                    // for drop list
                    data[index + offset] = cAssignmentList.AssignTypes.IndexOf(value.ToString());
                    is_new = false;
                    return true;
                }
                else if (index == 2)
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
