using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace iags
{
    public partial class LoginForm : Form
    {
        private string username = "";
        private string password = "";

        public LoginForm()
        {
            InitializeComponent();
        }

        private void okClicked(object sender, EventArgs e)
        {
            CheckLogin();
        }

        private void cancelClicked(object sender, EventArgs e)
        {
            this.Close();
        }

        private void passEdit_KeyDown(object sender, KeyEventArgs e)
        {
            int k = e.KeyValue;
            // enter
            if (k == 13)
            {
                CheckLogin();
            }
        }

        void CheckLogin()
        {
            username = userEdit.Text;
            password = passEdit.Text;

            if (Program.main.Login(username, password))
            {
                this.Close();
            }
        }
    }
}