using System;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;

namespace iags
{
    class cGradeView : cDBItemList
    {
        // 0 - id
        // 1 - section id
        // 2 - assignment id
        // 3 - assignment name

        // 4 - assignment max points
        // 5 - assignment is extra
        // 6 - assignment points got

        public cGradeView()
        {
            entity_name = "Grade View";
            tbl_name = "js_grade_gen_view";
            
            nlist.Add("s.id");
            nlist.Add("s.section_id,");
            nlist.Add("s.assign_id,");
            nlist.Add("s.name");

            nlist.Add("s.max_points");
            nlist.Add("s.is_extra");
            nlist.Add("a.points");
        }

        // 
        public override int DropTable()
        {
            return DropView();
        }

        // 
        public override int Create()
        {
            sql = "";

            if (cDB.Type == "Oracle" )
            {
                sql = string.Format(
                @"{0} AS 
                       SELECT {1}
                       FROM  js_signup_section_assign_view s, 
                             js_assign_grade_view a
                       WHERE s.section_id = a.section_id(+) AND
                             s.assign_id = a.assign_id(+) AND
                             s.id = a.id(+)",
                    tbl_name,
                    cSqlValueList.Implode(nlist)
                );
            }
            else if (cDB.Type == "MySQL")
            {               
                // TODO
            }

            return CreateView(sql);
        }


    }
}
