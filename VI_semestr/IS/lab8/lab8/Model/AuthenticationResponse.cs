using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using lab8.Entities;

namespace lab8.Model
{ 
    public class AuthenticationResponse
    {
        public int Id { get; set; }
        public string Username { get; set; }
        public string Token { get; set; }

        public AuthenticationResponse(User user, string token)
        {
            Id = user.Id;
            Username = user.Username;
            Token = token;
        }
    }
}
