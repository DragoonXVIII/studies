using api;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();
builder.Services.AddHttpClient();
builder.Services.AddSingleton<Censor>();

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.MapPost(
        "/censor",
        async (string text, Censor censor, HttpClient client) =>
        {
            censor.Blacklist = await client.GetFromJsonAsync<List<string>>(
                "http://localhost:5153/api/blacklist"
            ) ?? [];
            return text;
        }
    )
    .WithName("Censor");

app.Run();
