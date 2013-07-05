using System;
using System.Text;

namespace iags
{
    class cControlsArgs : EventArgs
    {
        public bool enable = true;

        public cControlsArgs(bool e)
        {
            enable = e;
        }
    }
}
