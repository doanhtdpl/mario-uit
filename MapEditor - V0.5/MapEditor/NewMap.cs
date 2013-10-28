using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MapEditor
{
    public partial class NewMap : Form
    {
        public int cols, rows;
        
        public NewMap()
        {
            InitializeComponent();
        }

        private void btnCreate_Click(object sender, EventArgs e)
        {
            try
            {
                cols = Int32.Parse(txtColum.Text);
                rows = Int32.Parse(txtRow.Text);
                this.Close();
            }
            catch
            {
                MessageBox.Show("Error type number");
            }
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            cols = Map_Const.X;
            rows = Map_Const.Y;
            this.Close();
        }
    }
}
