using Newtonsoft.Json;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Windows.Forms;

namespace SearchOfExit.Code
{
    public class Config
    {
        public Color EndColor { get; set; }
        public Color StartColor { get; set; }
        public Color WallColor { get; set; }
        public Color BackColor { get; set; }
        public Color CorrectColor { get; set; }
    }
    public class Lead
    {
        private static Lead lead;
        public static Lead Current => lead ?? (lead = new Lead());
        public Lead()
        {
            Config = new Config()
            {
                BackColor = Color.Gray,
                WallColor = Color.Black,
                CorrectColor = Color.Yellow,
                EndColor = Color.Green,
                StartColor = Color.Red
            };
        }


        public Config Config;
        public class MazeManager
        {
            private static MazeManager manager;
            public static MazeManager Current => manager ?? (manager = new MazeManager());
            public MazeManager()
            {
                list = new List<Maze>();
                Reload();
            }
            private List<Maze> list;

            public void SaveToSettings(Maze obj)
            {
                if (list.Where(x => x.Name == obj.Name).Count() > 0)
                    list = list.Where(x => x.Name != obj.Name).ToList();
                list.Add(obj);
                SerializeList();
                Reload();
            }
            private void SerializeList()
            {
                Properties.Settings.Default.Collection.Clear();
                foreach (var i in list)
                    Properties.Settings.Default.Collection.Add(JsonConvert.SerializeObject(i));
                Properties.Settings.Default.Save();
            }
            private void Reload()
            {
                list.Clear();
                var d = Properties.Settings.Default.Collection;
                if (d == null) d = new System.Collections.Specialized.StringCollection();
                foreach (var i in d)
                    if (!string.IsNullOrWhiteSpace(i))
                        list.Add(JsonConvert.DeserializeObject<Maze>(i));
            }
            public void ClearAll()
            {
                Properties.Settings.Default.Collection.Clear();
                Properties.Settings.Default.Save();
            }
            public Maze GetFromSettings(string name)
            {
                Reload();
                return list.Where(x => x.Name == name).FirstOrDefault();
            }
            public bool RemoveFromSettings(string name)
            {
                if (list.Where(x => x.Name == name).Count() == 0) return false;

                Properties.Settings.Default.Collection.Remove(
                   JsonConvert.SerializeObject(list.Where(x => x.Name == name).First()));
                Properties.Settings.Default.Save();
                Reload();
                return true;
            }
        }
    }
}
