from flask import Flask, render_template_string, request, url_for
import requests
import logging
from datetime import datetime
import os


# Dane uzywane do logowania oraz predefiniowane lokacje i kod strony
AUTHOR = "Jan Kowalski"
PORT = 5000
API_KEY = os.getenv("WEATHER_API_KEY")

locations = {
    "Poland": ["Warsaw", "Krakow"],
    "Germany": ["Berlin", "Munich"],
    "USA": ["New York", "Los Angeles"]
}

HTML_CODE = '''
<!doctype html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Weather App</title>
  <link rel="stylesheet" href="{{ url_for('static', filename='style.css') }}">
</head>
<body>
<div class="container">
  <h1>🌤️ Weather App</h1>
  <form method="POST">
      <label>Country:</label>
      <select name="country" id="country" onchange="updateCities()">
          {% for country in countries %}
              <option value="{{ country }}" {% if country == selected_country %}selected{% endif %}>{{ country }}</option>
          {% endfor %}
      </select>
      <label>City:</label>
      <select name="city" id="city">
          {% for city in cities %}
              <option value="{{ city }}" {% if city == selected_city %}selected{% endif %}>{{ city }}</option>
          {% endfor %}
      </select>
      <button type="submit">Get Weather</button>
  </form>

  {% if weather %}
      <div class="weather-box">
          <h2>Weather in {{ selected_city }}</h2>
          <p><strong>Temperature:</strong> {{ weather['main']['temp'] }}°C</p>
          <p><strong>Condition:</strong> {{ weather['weather'][0]['description'] }}</p>
          <p><strong>Humidity:</strong> {{ weather['main']['humidity'] }}%</p>
      </div>
  {% endif %}
</div>

<script>
function updateCities() {
    const cities = {
        "Poland": ["Warsaw", "Krakow"],
        "Germany": ["Berlin", "Munich"],
        "USA": ["New York", "Los Angeles"]
    };
    const country = document.getElementById("country").value;
    const citySelect = document.getElementById("city");
    citySelect.innerHTML = "";
    cities[country].forEach(function(city) {
        let option = document.createElement("option");
        option.value = city;
        option.text = city;
        citySelect.add(option);
    });
}
</script>
</body>
</html>
'''


# Konfiguracja logów które pojawią się na początku działania aplikacji
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)
logger.info(f"Start: {datetime.now()}, Author: {AUTHOR}, Listening on TCP port: {PORT}")


# Utworzenie aplikacji i ustawienie routa /
app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    selected_country = "Poland"
    selected_city = "Warsaw"
    weather_data = None

    if request.method == "POST":
        selected_country = request.form["country"]
        selected_city = request.form["city"]
        url = f"http://api.openweathermap.org/data/2.5/weather?q={selected_city}&appid={API_KEY}&units=metric"
        response = requests.get(url)
        if response.ok:
            weather_data = response.json()

    return render_template_string(
        HTML_CODE,
        countries=list(locations.keys()),
        cities=locations[selected_country],
        selected_country=selected_country,
        selected_city=selected_city,
        weather=weather_data
    )


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=PORT)
