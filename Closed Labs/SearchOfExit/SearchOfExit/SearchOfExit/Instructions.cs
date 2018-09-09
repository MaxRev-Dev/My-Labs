using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SearchOfExit
{
    public partial class Instructions : Form
    {
        Menu mainform;
        public Instructions(Menu mainform)
        {
            this.mainform = mainform;
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            mainform.ActivateButtonI();
            Close();
        }
    }
}
