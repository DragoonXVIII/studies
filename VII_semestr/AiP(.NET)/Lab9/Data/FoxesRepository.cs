using Lab9.Models;

namespace Lab9.Data;

public interface IFoxesRepository
{
    void Add(Fox f);
    Fox Get(int id);
    IEnumerable<Fox> GetAll();
    void Update(int id, Fox f);
}

public class FoxesRepository : IFoxesRepository
{
    private readonly List<Fox> db;

    public FoxesRepository()
    {
        db = new List<Fox>();
    }

    public void Add(Fox f)
    {
        f.Id = db.Count() > 0 ? db.Max(x => x.Id) + 1 : 1;
        db.Add(f);
    }

    public Fox Get(int id)
    {
        return db.FirstOrDefault(x => x.Id == id);
    }

    public IEnumerable<Fox> GetAll()
    {
        return db.AsEnumerable();
    }

    public void Update(int id, Fox f)
    {
        var c = db.FirstOrDefault(x => x.Id == id);
        c.Loves = f.Loves;
        c.Hates = f.Hates;
    }
}
