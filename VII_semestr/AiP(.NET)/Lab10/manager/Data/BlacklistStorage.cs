namespace manager.Data
{
    public class BlacklistStorage : IBlacklistStorage
    {
        private readonly string _path;

        public BlacklistStorage(string path = "censor.db")
        {
            _path = path;
            if (!File.Exists(path))
                File.WriteAllText(path, string.Empty);
        }

        private string Serialize(HashSet<string> words)
        {
            return string.Join(";", words.ToArray());
        }

        private string Read()
        {
            return File.ReadAllText(_path);
        }

        public void Add(string word)
        {
            var list = Get();
            list.Add(word);

            File.WriteAllText(_path, Serialize(list));
        }

        public HashSet<string> Get()
        {
            var w = Read();
            return Deserialize(w);
        }

        private static HashSet<string> Deserialize(string w)
        {
            if (w != string.Empty)
                return w.Split(';').ToHashSet();
            else
                return new HashSet<string>();
        }
    }
}
