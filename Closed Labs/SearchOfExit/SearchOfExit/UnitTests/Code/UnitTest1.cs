using Microsoft.VisualStudio.TestTools.UnitTesting;
using SearchOfExit.Code;
using static SearchOfExit.Code.Lead;

namespace Code.Tests
{
    [TestClass()]
    public class UnitTest1
    {
        [TestMethod()]
        public void SaveAndRemove()
        {
            new Lead();
            Maze maze = new Maze("a");
            MazeManager.Current.SaveToSettings(maze); 
            bool f = MazeManager.Current.RemoveFromSettings("a");
            Assert.IsTrue(f);
        }

        [TestMethod()]
        public void GetSettingsTest()
        {
            new Lead();
            Maze maze = new Maze("a");
            MazeManager.Current.SaveToSettings(maze);

            var act = MazeManager.Current.GetFromSettings("a"); 
            Assert.AreEqual(maze, act);
        }
    }
}