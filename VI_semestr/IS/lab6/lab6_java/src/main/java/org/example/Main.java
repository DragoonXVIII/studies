package org.example;

import java.util.List;
import java.util.Scanner;

public class Main {

    //private static final String BASE_URL = "http://localhost:4567/cities"; // Adres REST API

    public static void main(String[] args) {
        CityService cityService = new CityService();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\nWybierz opcję:");
            System.out.println("1 - Pobierz listę miast (GET)");
            System.out.println("2 - Pobierz miasto po ID (GET)");
            System.out.println("3 - Dodaj miasto (POST)");
            System.out.println("4 - Zaktualizuj miasto (PUT)");
            System.out.println("5 - Usuń miasto (DELETE)");
            System.out.println("0 - Wyjdź");
            System.out.print("Wybór: ");

            int choice = scanner.nextInt();
            scanner.nextLine();

            try {
                switch (choice) {
                    case 1:
                        List<City> cities = cityService.fetchCities();
                        cities.forEach(System.out::println);
                        break;
                    case 2:
                        System.out.print("Podaj ID miasta: ");
                        int cityId = scanner.nextInt();
                        System.out.println(cityService.getCityById(cityId));
                        break;
                    case 3:
                        System.out.print("Podaj nazwę miasta: ");
                        String name = scanner.nextLine();
                        System.out.print("Podaj populację: ");
                        int population = scanner.nextInt();
                        scanner.nextLine();
                        System.out.print("Podaj kod kraju (musi byc zgodny z tabela countries z bazy danych world): ");
                        String country = scanner.nextLine();
                        System.out.print("Podaj dystrykt: ");
                        String district = scanner.nextLine();

                        cityService.addCity(name, population, country, district);
                        break;
                    case 4:
                        System.out.print("Podaj ID miasta do aktualizacji: ");
                        int updateId = scanner.nextInt();
                        scanner.nextLine();
                        System.out.print("Podaj nową nazwę miasta: ");
                        String newName = scanner.nextLine();
                        System.out.print("Podaj nową populację: ");
                        int newPopulation = scanner.nextInt();
                        scanner.nextLine();
                        System.out.print("Podaj nowy kraj: ");
                        String newCountry = scanner.nextLine();
                        System.out.print("Podaj dystrykt: ");
                        String newDistrict = scanner.nextLine();

                        cityService.updateCity(updateId, newName, newPopulation, newCountry, newDistrict);
                        break;
                    case 5:
                        System.out.print("Podaj ID miasta do usunięcia: ");
                        int deleteId = scanner.nextInt();
                        cityService.deleteCity(deleteId);
                        break;
                    case 0:
                        System.out.println("Zamykanie programu...");
                        scanner.close();
                        return;
                    default:
                        System.out.println("Niepoprawna opcja.");
                }
            } catch (Exception e) {
                System.err.println("Błąd: " + e.getMessage());
            }
        }
    }
}
