using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab8
{
    public partial class Form1: Form
    {
        // custom 
        private string apiUrl = "http://localhost:8080/api/"; // Zmień na odpowiedni URL

        public Form1()
        {
            InitializeComponent();
        }

        // custom 
        private async void btnLogin_Click(object sender, EventArgs e)
        {
            //rtbToken.Text = "elozelotescik";

            var username = txtUsername.Text;
            var password = txtPassword.Text;

            var loginRequest = new
            {
                Username = username,
                Password = password
            };

            var client = new HttpClient();
            var response = await client.PostAsync(apiUrl + "users/authenticate", new StringContent(JsonConvert.SerializeObject(loginRequest), Encoding.UTF8, "application/json"));

            if (response.IsSuccessStatusCode)
            {
                var responseContent = await response.Content.ReadAsStringAsync();
                dynamic jsonResponse = JsonConvert.DeserializeObject(responseContent);
                string token = jsonResponse.token;
                rtbToken.Text = token;  
            }
            else
            {
                MessageBox.Show("Login failed");
            }
        }

        // custom
        private async void btnGetUserCount_Click(object sender, EventArgs e)
        {
            var token = rtbToken.Text;

            if (string.IsNullOrEmpty(token))
            {
                MessageBox.Show("Please log in first");
                return;
            }

            var client = new HttpClient();
            client.DefaultRequestHeaders.Add("Authorization", "Bearer " + token);

            var response = await client.GetAsync(apiUrl + "users/count");  

            if (response.IsSuccessStatusCode)
            {
                var result = await response.Content.ReadAsStringAsync();
                var jsonResponse = JsonConvert.DeserializeObject<dynamic>(result);
                int userCount = jsonResponse.count;
                rtbData.Text = "User Count: " + userCount;
            }
            else
            {
                MessageBox.Show("Failed to fetch user count");
            }
        }

        // custom
        private async void btnGetPrimeNumber_Click(object sender, EventArgs e)
        {
            var token = rtbToken.Text;

            if (string.IsNullOrEmpty(token))
            {
                MessageBox.Show("Please log in first");
                return;
            }

            var client = new HttpClient();
            client.DefaultRequestHeaders.Add("Authorization", "Bearer " + token);

            var response = await client.GetAsync(apiUrl + "number/prime");  

            if (response.IsSuccessStatusCode)
            {
                var result = await response.Content.ReadAsStringAsync();
                var jsonResponse = JsonConvert.DeserializeObject<dynamic>(result);
                int primeNumber = jsonResponse.primeNumber;
                rtbData.Text = "Prime Number: " + primeNumber;
            }
            else
            {
                MessageBox.Show("Failed to fetch prime number");
            }
        }

        // custom
        private async void btnGetUsersList_Click(object sender, EventArgs e)
        {
            var token = rtbToken.Text;

            if (string.IsNullOrEmpty(token))
            {
                MessageBox.Show("Please log in first");
                return;
            }

            var client = new HttpClient();
            client.DefaultRequestHeaders.Add("Authorization", "Bearer " + token);

            var response = await client.GetAsync(apiUrl + "users/all");  // Zmień na odpowiedni URL

            if (response.IsSuccessStatusCode)
            {
                var result = await response.Content.ReadAsStringAsync();
                var jsonArray = JArray.Parse(result);
                var users = jsonArray.Select(user => user["username"].ToString()).ToList();
                rtbData.Text = "Lista użytkowników:\n" + string.Join("\n", users);
            }
            else
            {
                MessageBox.Show("Failed to fetch users list");
            }
        }




        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
