using System;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace iags
{
    class cBaseItem
    {
        // has this record been added to the database
        public bool already_inDB = false;

        // none of the data has been changed from the default
        // used when displaying(or not) the record
        public bool is_new = true;

        // used to offset the columns being displayed
        public int offset = 0;

        public ArrayList data = new ArrayList();


        public virtual object RenderCell(int index)
        {
            if (index + offset < data.Count){

                if(data[index + offset] is double)
                    return string.Format("{0:F}", data[index + offset]);
                else
                    return data[index + offset];
            }

            return null;
        }

        public virtual bool UpdateCell(int index, object value)
        {
            if (index + offset < data.Count)
            {
                Type t = data[index + offset].GetType();

                // if value null, and data type expected, is not string
                if (!(data[index + offset] is string) &&
                     (value == null))
                {
                    value = 0;
                }

                data[index + offset] = Convert.ChangeType(value, t);
                is_new = false;
                return true;
            }

            return false;
        }
    }
}
