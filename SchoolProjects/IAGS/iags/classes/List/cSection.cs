using System;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    class cSection : cBaseItem
    {
        public cSection()
        {
            data.Add(-1); // int section_id;   pk
            data.Add(0);  // int course_id;    fk(couse_info)
            data.Add(0);  // int id;           fk(person) who teachers

            data.Add(0);  // uint crn
            data.Add(0);  // byte season_num    0 = fall, 1 = winter, 2 = spring, 3 = summer...
            data.Add(new DateTime()); // DateTime start_date
            data.Add(new DateTime()); // DateTime end_date
            data.Add(0);  // ushort max_students
        }

        public override object RenderCell(int index)
        {
            if (index == 4)
            {
                // for drop list
                int sn = Convert.ToInt32(data[index]);
                return cSectionList.SeasonList[sn];
            }
            return base.RenderCell(index);
        }

        public override bool UpdateCell(int index, object value)
        {
            if (index + offset < data.Count)
            {
                if (index == 4)
                {
                    // for drop list
                    data[index] = cSectionList.SeasonList.IndexOf(value.ToString());
                    is_new = false;
                    return true;
                }

                return base.UpdateCell(index, value);
            }

            return false;
        }
    }
}
