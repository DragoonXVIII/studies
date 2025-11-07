using Microsoft.AspNetCore.Identity.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore;

namespace Lab7.Data;

public class ApplicationDbContext : IdentityDbContext<Lab7.Areas.Identity.Data.ApplicationUser> 
{
    public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
        : base(options)
    {
    }
}
