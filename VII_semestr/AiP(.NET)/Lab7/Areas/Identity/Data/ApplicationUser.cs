using Microsoft.AspNetCore.Identity;

namespace Lab7.Areas.Identity.Data
{
    public class ApplicationUser : IdentityUser
    {
        public long CustomerId { get; set; }
    }
}
