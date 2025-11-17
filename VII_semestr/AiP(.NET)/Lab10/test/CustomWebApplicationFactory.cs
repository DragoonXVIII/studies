using manager.Data;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Mvc.Testing;
using Microsoft.Extensions.DependencyInjection;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace test
{
    public class CustomWebApplicationFactory<TStartup> :
    WebApplicationFactory<TStartup>
    where TStartup : class
    {
        private string temp = Path.GetRandomFileName();
        protected override void ConfigureWebHost(IWebHostBuilder
        builder)
        {
            builder.ConfigureServices(services =>
            {
                services.AddSingleton<IBlacklistStorage>(new BlacklistStorage(temp));
            });
        }
        protected override void Dispose(bool disposing)
        {
            base.Dispose(disposing);
            File.Delete(temp);
        }
    }
}
