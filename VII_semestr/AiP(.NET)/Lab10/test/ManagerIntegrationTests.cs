using Microsoft.AspNetCore.Mvc.Testing;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace test
{
    public class ManagerIntegrationTests :
    IClassFixture<CustomWebApplicationFactory<Program>>
    {
        private readonly HttpClient _client;
        private readonly CustomWebApplicationFactory<Program>
        _factory;
        public
        ManagerIntegrationTests(CustomWebApplicationFactory<Program>
        factory)
        {
            _factory = factory;
            _client = factory.CreateClient(
            new WebApplicationFactoryClientOptions
            {
                AllowAutoRedirect = false
            }
            );
        }
        [Fact]
        public async void Get_WhenEmpty_ReturnEmptyList()
        {
            var act = await _client.GetAsync("/api/Blacklist");
            Assert.True(act.IsSuccessStatusCode);
            var json = JsonSerializer.Deserialize<string[]>(await
            act.Content.ReadAsStringAsync());
            Assert.Empty(json);
        }

        [Fact]
        public async Task Post_AddWord_WordAppearsInList()
        {
            string newWord = "bomba";
            var postResponse = await _client.PostAsync($"/api/Blacklist?word={newWord}", null);
            Assert.True(postResponse.IsSuccessStatusCode);

            var getResponse = await _client.GetAsync("/api/Blacklist");
            Assert.True(getResponse.IsSuccessStatusCode);

            var list = JsonSerializer.Deserialize<string[]>(await getResponse.Content.ReadAsStringAsync());

            Assert.Contains(newWord, list);
        }
    }
}
