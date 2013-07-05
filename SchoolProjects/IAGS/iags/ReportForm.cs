using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace iags
{
    public partial class ReportForm : Form
    {
        public ReportForm()
        {
            InitializeComponent();
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void ReportForm_Load(object sender, EventArgs e)
        {
            if(html_data.Length > 1)
                webBrowser.DocumentText = html_data;
        }

        private void printButton_Click(object sender, EventArgs e)
        {
            webBrowser.ShowPrintDialog();
        }

        private void pageSetupButton_Click(object sender, EventArgs e)
        {
            webBrowser.ShowPageSetupDialog();
        }

    }
}