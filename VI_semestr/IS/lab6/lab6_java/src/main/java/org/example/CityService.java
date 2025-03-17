package org.example;

import org.json.JSONArray;
import org.json.JSONObject;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.io.*;
import java.net.HttpURLConnection;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class CityService {

    private static final String BASE_URL = "http://localhost:8000/cities";
    // private static final String BASE_URL = "http://localhost/lab6/cities";

    // deprecated
    /*
    @deprecated
    public List<City> fetchCities() {
        List<City> cities = new ArrayList<>();

        try {
            System.out.println("Wysyłanie zapytania...");
            URL url = new URL(BASE_URL);
            InputStream is = url.openStream();
            System.out.println("Pobieranie odpowiedzi...");

            String source = new BufferedReader(new InputStreamReader(is))
                    .lines().collect(Collectors.joining("\n"));

            System.out.println("Przetwarzanie danych...");
            JSONObject json = new JSONObject(source);
            JSONArray receivedData = json.getJSONArray("cities");


            for (int i = 0; i < receivedData.length(); i++) {
                JSONObject cityJson = receivedData.getJSONObject(i);
                cities.add(City.fromJson(cityJson));
            }

        } catch (Exception e) {
            System.err.println("Wystąpił błąd podczas pobierania danych!");
            e.printStackTrace();
        }

        return cities;
    }
    */

    public List<City> fetchCities() throws Exception {
        String response = sendRequest(BASE_URL + "/read", "GET", null);
        JSONArray citiesArray = new JSONObject(response).getJSONArray("cities");

        List<City> cities = new ArrayList<>();
        for (int i = 0; i < citiesArray.length(); i++) {
            JSONObject obj = citiesArray.getJSONObject(i);
            cities.add(new City(
                    obj.getInt("ID"),
                    obj.getString("Name"),
                    obj.getInt("Population"),
                    obj.getString("CountryCode"),
                    obj.getString("District")
            ));
        }
        return cities;
    }

    // GET - miasto po ID
    public City getCityById(int id) throws Exception {
        String response = sendRequest(BASE_URL + "/read/" + id, "GET", null);
        //System.out.println("Odpowiedź serwera: " + response);
        JSONObject jsonResponse = new JSONObject(response);
        JSONArray citiesArray = jsonResponse.getJSONArray("cities");
        if (!citiesArray.isEmpty()) {
            JSONObject obj = citiesArray.getJSONObject(0); // Pobierz pierwsze miasto
            return new City(
                    obj.getInt("ID"),
                    obj.getString("Name"),
                    obj.getInt("Population"),
                    obj.getString("CountryCode"),
                    obj.getString("District")
            );
        }
        return null;
    }

    // POST - nowe miasto
    public void addCity(String name, int population, String country, String district) throws Exception {
        JSONObject json = new JSONObject();
        json.put("Name", name);
        json.put("Population", population);
        json.put("CountryCode", country);
        json.put("District", district);

        sendRequest(BASE_URL + "/create", "POST", json.toString());
        System.out.println("Miasto dodane!");
    }

    // PUT - Aktualizuje po ID
    public void updateCity(int id, String name, int population, String country, String district) throws Exception {
        JSONObject json = new JSONObject();
        json.put("Name", name);
        json.put("Population", population);
        json.put("CountryCode", country);
        json.put("District", district);

        sendRequest(BASE_URL + "/update/" + id, "PUT", json.toString());
        System.out.println("Miasto zaktualizowane!");
    }

    // DELETE - Usuwa po ID
    public void deleteCity(int id) throws Exception {
        sendRequest(BASE_URL + "/delete/" + id, "DELETE", null);
        System.out.println("Miasto usunięte!");
    }

    private String sendRequest(String urlStr, String method, String jsonBody) throws Exception {
        URL url = new URL(urlStr);
        HttpURLConnection conn = (HttpURLConnection) url.openConnection();
        conn.setRequestMethod(method);
        conn.setRequestProperty("Content-Type", "application/json");
        conn.setDoOutput(true);

        if (jsonBody != null) {
            try (OutputStream os = conn.getOutputStream()) {
                byte[] input = jsonBody.getBytes("utf-8");
                os.write(input, 0, input.length);
            }
        }

        try (BufferedReader br = new BufferedReader(new InputStreamReader(conn.getInputStream(), "utf-8"))) {
            return br.lines().collect(Collectors.joining("\n"));
        }
    }

}
