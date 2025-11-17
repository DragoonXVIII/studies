namespace manager.Data
{
    public interface IBlacklistStorage
    {
        void Add(string word);
        HashSet<string> Get();
    }
}