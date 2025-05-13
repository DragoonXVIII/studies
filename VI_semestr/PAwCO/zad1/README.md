# Weather App

Aplikacja do wyświetlania pogody przy użyciu OpenWeather API.

https://home.openweathermap.org/

## 🔧 Instalacja

1. Sklonuj repozytorium:
   ```bash
   git clone https://github.com/Nyctovir/PAwCO2
   cd PAwCO2
   ```

2. Zbuduj obraz Dockera:
   ```bash
   docker build -t weather-app .
   ```

3. Uruchom kontener (zastąp `{twój_klucz_api}` własnym kluczem do API pogodowego):
   ```bash
   docker run -d -p 5000:5000 -e WEATHER_API_KEY={twój_klucz_api} --name weather_container weather-app
   ```

## 📋 Logi kontenera

Aby sprawdzić logi kontenera:
```bash
docker logs weather_container
```
Przykładowy output:
```
 * Running on http://0.0.0.0:5000/ (Press CTRL+C to quit)
```

## 📦 Informacje o warstwach obrazu

Ilość warstw obrazu:
```bash
docker inspect --format='{{.RepoTags}} -> {{len .RootFS.Layers}} layers' weather-app:latest
```
Przykładowy output:
```
[weather-app:latest] -> 8 layers
```

Rozmiar obrazu:
```bash
docker images weather-app:latest --format "{{.Repository}}:{{.Tag}} -> {{.Size}}"
```
Przykładowy output:
```
weather-app:latest -> 197MB
```

## 📁 Opisy plików

Krótkie opisy działania plików `Dockerfile` i `app.py` znajdują się w komentarzach w ich wnętrzu.


