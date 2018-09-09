using System;
using System.Windows.Forms;

namespace SearchOfExit
{
    public partial class Menu : Form
    {
        public Menu()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs a)
        {

        }

        private void EnterL_Click(object sender, EventArgs e)
        {
            Editor newForm = new Editor(this);
            newForm.Show();
            EnterL.Enabled = false;
        }
        //Уточнити завантаження
        private void DownloadL_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                System.IO.StreamReader sr = new System.IO.StreamReader(openFileDialog1.FileName);
                MessageBox.Show(sr.ReadToEnd());
                sr.Close();
            }
        }

        private void InstructionsL_Click(object sender, EventArgs e)
        {
            Instructions newForm = new Instructions(this);
            newForm.Show();
            InstructionsL.Enabled = false;
        }
        public void ActivateButtonI()
        {
            InstructionsL.Enabled = true;
        }
        public void ActivateButtonE()
        {
            EnterL.Enabled = true;
        }

        private void ExitL_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show(this, "Закрити програму?", "Вихід з програми", MessageBoxButtons.YesNo);
            if(result == DialogResult.Yes)
            {
                Application.Exit();
            }
        }
          
    }
}
