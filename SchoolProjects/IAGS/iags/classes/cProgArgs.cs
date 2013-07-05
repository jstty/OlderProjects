using System;
using System.Text;

namespace iags
{
    class cProgArgs : EventArgs
    {
        public int min = 0;
        public int max = 1;
        public int value = 0;
        public string msg = "";
    }
}
