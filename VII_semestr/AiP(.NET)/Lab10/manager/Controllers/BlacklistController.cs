using manager.Data;
using Microsoft.AspNetCore.Mvc;

namespace manager.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class BlacklistController : ControllerBase
    {
        private readonly IBlacklistStorage _storage;

        public BlacklistController(IBlacklistStorage storage)
        {
            _storage = storage;
        }

        [HttpGet]
        public List<string> Get()
        {
            return _storage.Get().ToList();
        }

        [HttpPost]
        public IActionResult Post(string word)
        {
            _storage.Add(word);
            return Ok();
        }
    }
}
