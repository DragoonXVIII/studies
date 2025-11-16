using Lab9.Data;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.AspNetCore.Identity;
using Microsoft.EntityFrameworkCore;
using Microsoft.IdentityModel.Tokens;
using System.Text;

var builder = WebApplication.CreateBuilder(args);
var connectionString = builder.Configuration.GetConnectionString("ApplicationDbContextConnection") ?? throw new InvalidOperationException("Connection string 'ApplicationDbContextConnection' not found.");

builder.Services.AddControllers();

builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

builder.Services.AddSingleton<IFoxesRepository, FoxesRepository>();

builder.Services.AddDbContext<ApplicationDbContext>(options => options.UseSqlite("Data Source=identity.db"));

builder.Services
    .AddDefaultIdentity<IdentityUser>(options =>
    {
        options.SignIn.RequireConfirmedAccount = true;

        // wymagania dotycz¹ce has³a
        options.Password.RequireUppercase = false;
        options.Password.RequireDigit = false;
        options.Password.RequireNonAlphanumeric = false;
        options.Password.RequiredLength = 8;
    })
    .AddRoles<IdentityRole>()
    .AddEntityFrameworkStores<ApplicationDbContext>();

builder.Services.AddAuthentication()
    .AddCookie() 
    .AddJwtBearer(JwtBearerDefaults.AuthenticationScheme, options =>
    {
        options.TokenValidationParameters = new TokenValidationParameters
        {
            ValidateIssuer = true,                     
            ValidateAudience = true,                   
            ValidateLifetime = true,                   
            ValidateIssuerSigningKey = true,           
            ValidIssuer = builder.Configuration["Tokens:Issuer"],
            ValidAudience = builder.Configuration["Tokens:Audience"],
            IssuerSigningKey = new SymmetricSecurityKey(
                Encoding.UTF8.GetBytes(builder.Configuration["Tokens:Key"]))
        };
    });

builder.Services.AddAuthorization(options =>
{
    options.AddPolicy("IsAdminJwt", policy =>
        policy.RequireRole("Admin")
              .AddAuthenticationSchemes(JwtBearerDefaults.AuthenticationScheme));
});


builder.Services.AddRazorPages();

var app = builder.Build();

if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseRouting();

app.UseAuthentication();
app.UseAuthorization();

app.UseFileServer();

app.MapControllers();

app.MapRazorPages();

using (var scope = app.Services.CreateScope())
{
    using (var roleManager = scope.ServiceProvider.GetService<RoleManager<IdentityRole>>())
    using (var userManager = scope.ServiceProvider.GetService<UserManager<IdentityUser>>())
    {     
        if (!await roleManager.RoleExistsAsync("Admin"))
        {
            await roleManager.CreateAsync(new IdentityRole("Admin"));
        }
  
        foreach (var user in userManager.Users.Where(x => x.Email.EndsWith("@example.com")))
        {
            if (!await userManager.IsInRoleAsync(user, "Admin"))
            {
                await userManager.AddToRoleAsync(user, "Admin");
            }
        }
    }
}

app.Run();
