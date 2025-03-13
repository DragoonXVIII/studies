using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Linq;

namespace lab8.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class NumberController : ControllerBase
    {
        [Authorize(Roles = "number")]
        [HttpGet("prime")]
        public IActionResult GetRandomPrime()
        {
            try
            {
                var primeNumbers = new[] { 2, 3, 5, 7, 11, 13 };
                var random = new Random();
                var randomPrime = primeNumbers[random.Next(primeNumbers.Length)];

                return Ok(new { primeNumber = randomPrime });
            }
            catch (Exception ex)
            {
                return StatusCode(500, new { message = "An error occurred while generating the prime number.", details = ex.Message });
            }
        }
    }
}
