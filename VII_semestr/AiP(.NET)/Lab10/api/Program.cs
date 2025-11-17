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
            try
            {
                censor.Blacklist = await client.GetFromJsonAsync<List<string>>(
                    "https://localhost:60919/api/Blacklist"
                ) ?? [];
                Console.Write(censor.Blacklist);
                return Results.Ok(censor.CensorText(text));
            }
            catch (HttpRequestException ex)
            {
                return Results.Problem(
                    detail: "Unable to fetch blacklist from API",
                    statusCode: StatusCodes.Status503ServiceUnavailable
                );
            }
            catch (Exception ex)
            {
                return Results.Problem(
                    detail: "An error occurred while processing the request",
                    statusCode: StatusCodes.Status500InternalServerError
                );
            }
        }
    )
    .WithName("Censor");

app.UseFileServer();

app.Run();
