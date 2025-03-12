package org.example;

import org.json.JSONObject;

public class City {
    private int id;
    private String name;
    private int population;
    private String country;
    private String district;

    public City(int id, String name, int population, String country, String district) {
        this.id = id;
        this.name = name;
        this.population = population;
        this.country = country;
        this.district = district;
    }

    public static City fromJson(JSONObject json) {
        return new City(
                json.optInt("id", 0),
                json.optString("Name", "Unknown"),
                json.optInt("Population", 0),
                json.optString("CountryCode", "Unknown"),
                json.optString("District", "Unkown")
        );
    }

    public void updateFromJson(JSONObject json) {
        this.name = json.optString("Name", this.name);
        this.population = json.optInt("Population", this.population);
        this.country = json.optString("CountryCode", this.country);
        this.district = json.optString("District", "Unknown");
    }

    // Gettery i Settery
    public int getId() { return id; }
    public void setId(int id) { this.id = id; }

    public String getName() { return name; }
    public void setName(String name) { this.name = name; }

    public int getPopulation() { return population; }
    public void setPopulation(int population) { this.population = population; }

    public String getCountry() { return country; }
    public void setCountry(String country) { this.country = country; }

    public String getDistrict() { return district; }
    public void setDistrict(String district) { this.district = district; }

    @Override
    public String toString() {
        return "ID: " + id + ", Miasto: " + name + ", Populacja: " + population + ", CountryCode: " + country + ", Dystrykt: " + district;
    }
}
