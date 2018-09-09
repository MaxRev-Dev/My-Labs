using System;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace SearchOfExit
{
    public partial class Editor : Form
    {
        Menu mainform;
        public Editor(Menu mainform)
        {
            this.mainform = mainform;
            InitializeComponent();
            delRoomBtn.Click += DelRoomBtn_Click;
            SaveMazeBtn.Click += SaveMazeBtn_Click;
            SolveBtn.Click += SolveBtn_Click;
            LoadMazeBtn.Click += LoadMazeBtn_Click;
            ExportBtn.Click += ExportBtn_Click;
            ImportBtn.Click += ImportBtn_Click;
            AddRoomBtn.Click += AddRoomBtn_Click;
            ShowGridCheck.CheckedChanged += ShowGridCheck_CheckedChanged;
            Load += Editor_Load;
        }

        private void Editor_Load(object sender, EventArgs e)
        { 
        }

        private void ImportBtn_Click(object sender, EventArgs e)
        {
            mazeControl1.Import();
        }

        private void ShowGridCheck_CheckedChanged(object sender, EventArgs e)
        {
            mazeControl1.GridVisibililty((sender as CheckBox).Checked);
        }

        private void ExportBtn_Click(object sender, EventArgs e)
        {
            mazeControl1.Export();
        }

        private void LoadMazeBtn_Click(object sender, EventArgs e)
        {
            mazeControl1.LoadMaze();
        }


        private void SolveBtn_Click(object sender, EventArgs e)
        {
            mazeControl1.Solve();
        }

        private void SaveMazeBtn_Click(object sender, EventArgs e)
        {
            mazeControl1.SaveMaze();
        }

        private void DelRoomBtn_Click(object sender, EventArgs e)
        {
            mazeControl1.RemoveGrid();
        }


        private void EditorBackBtn_Click(object sender, EventArgs e)
        {
            mainform.ActivateButtonE();
            Close();
        }
        private void AddRoomBtn_Click(object sender, EventArgs e)
        {
            mazeControl1.CreateGrid();
        }

    }
}
