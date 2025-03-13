using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Configuration;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using lab8.Model;
using lab8.Sevices.Users;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.AspNetCore.Authorization;

namespace lab8.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class UsersController : ControllerBase
    {
        private IUserService userService;
        public UsersController(IUserService userService)
        {
            this.userService = userService;
        }

        [HttpPost("authenticate")]  
        public IActionResult
        Authenticate(AuthenticationRequest request)
        {
            var response = userService.Authenticate(request);

            if (response == null)
                return BadRequest(new
                {
                    message = "Username or password is incorrect" 
                }); 
            return Ok(response);
        }

        // Z.8.3.2
        [Authorize(Roles = "admin", AuthenticationSchemes = JwtBearerDefaults.AuthenticationScheme)]
        [HttpGet("all")]
        public IActionResult GetAllUsers()
        {
            try
            {
                // Pobierz wszystkich użytkowników za pomocą usługi
                var users = userService.GetUsers();

                if (users == null || !users.Any())
                    return NotFound(new { message = "No users found." });

                return Ok(users);
            }
            catch (Exception ex)
            {
                // Obsługuje wyjątki i zwraca odpowiedni status
                return StatusCode(500, new { message = "An error occurred while fetching the users.", details = ex.Message });
            }
        }

        // Z.8.4.3
        [Authorize(Roles = "user")]
        [HttpGet("count")]
        public IActionResult GetUsersCount()
        {
            try
            {
                // Zwrócenie liczby użytkowników
                var userCount = userService.GetUsersCount();

                return Ok(new { count = userCount });
            }
            catch (Exception ex)
            {
                return StatusCode(500, new { message = "An error occurred while fetching the user count.", details = ex.Message });
            }
        }

    }
}
