using Lab5.Models;
using Microsoft.EntityFrameworkCore;

namespace Lab5.Data
{
    public class MoviesDbContext : DbContext
    {
        public DbSet<Movie> Movies { get; set; }
        public MoviesDbContext(DbContextOptions options) :
        base(options)
        {
        }
    }
}
