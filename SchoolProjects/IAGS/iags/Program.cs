using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace iags
{
    static class Program
    {
        static public cIAGS main = new cIAGS();

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            try
            {               
                Application.EnableVisualStyles();
                Application.SetCompatibleTextRenderingDefault(false);

                MainForm f = new MainForm();
                main.Init(f);

                Application.Run(f);
            }
            catch(SystemException exp)
            {
                cIAGS.PopupError(exp);
            } // catch error
        } // main
    }
}