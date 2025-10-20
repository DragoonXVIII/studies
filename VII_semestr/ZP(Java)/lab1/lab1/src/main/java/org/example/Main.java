package org.example;

import java.io.*;
import java.util.*;
import java.util.stream.*;

public class Main {

    public static void zad1() {
        List<String> przedmioty = Arrays.asList(
                "Procesy wytwarzania oprogramowania",
                "Seminarium dyplomowe",
                "Architektura i programowanie w .NET",
                "Projekt zespołowy - implementacja",
                "Projekt zespołowy - projektowanie",
                "Zarządzanie bazami SQL i NoSQL",
                "Integracja systemów",
                "Interakcja człowiek - komputer",
                "Programowanie aplikacji mobilnych na platformę Android",
                "Programowanie aplikacji mobilnych na platformę iOS",
                "Programowanie aplikacji w chmurze obliczeniowej",
                "Komponentowe podejscie do wytwarzania aplikacji",
                "Zaawansowane programowanie w Javie",
                "Szkielety programistyczne w aplikacjach internetowych"
        );

        // filtr
        boolean zawieraZaaw = przedmioty.stream()
                .anyMatch(p -> p.toLowerCase().contains("zaaw")); // lub filter bez znaczenia
        System.out.println("Czy w liście są przedmioty z 'zaaw'? " + (zawieraZaaw ? "Tak" : "Nie"));

        // nowy strumie
        Map<String, Integer> przedmiotOcena = przedmioty.stream()
                .collect(Collectors.toMap(p -> p, p -> new Random().nextInt(4) + 2)); // oceny 2–5

        System.out.println("\nLista przedmiotów i ocen:");
        przedmiotOcena.forEach((p, o) -> System.out.println(p + " -> " + o));

        // powtorzenia check
        Map<Integer, Long> wystapienia = przedmiotOcena.values().stream()
                .collect(Collectors.groupingBy(o -> o, Collectors.counting()));

        System.out.println("\nPowtarzające się oceny:");
        wystapienia.forEach((ocena, liczba) -> {
            if (liczba > 1)
                System.out.println("Ocena " + ocena + " wystąpiła " + liczba + " razy");
        });
    }

    public static void zad2() {
        Map<String, Integer> przedmiotOcena = wczytajZPliku("oceny.txt");
        if (przedmiotOcena.isEmpty()) {
            System.out.println("Brak danych w pliku.");
            return;
        }

        List<Map.Entry<String, Integer>> sortOceny = przedmiotOcena.entrySet().stream()
                .sorted(Map.Entry.comparingByValue())
                .collect(Collectors.toList());

        // Zliczenie częstości występowania ocen
        Map<Integer, Long> freq = przedmiotOcena.values().stream()
                .collect(Collectors.groupingBy(o -> o, Collectors.counting()));

        // Sortowanie po częstości występowania (rosnąco)
        List<Map.Entry<Integer, Long>> sortPowtarzalnosc = freq.entrySet().stream()
                .sorted(Map.Entry.comparingByValue())
                .collect(Collectors.toList());

        try (FileWriter writer = new FileWriter("oceny_posortowane.txt")) {
            writer.write("=== Przedmioty z najniższymi ocenami (rosnąco) ===\n");
            for (Map.Entry<String, Integer> e : sortOceny) {
                writer.write(e.getKey() + " -> " + e.getValue() + "\n");
            }
            writer.write("\n=== Oceny najrzadziej występujące (rosnąco) ===\n");
            for (Map.Entry<Integer, Long> e : sortPowtarzalnosc) {
                writer.write("Ocena " + e.getKey() + " wystąpiła " + e.getValue() + " razy\n");
            }
        } catch (IOException e) {
            System.err.println("Błąd zapisu: " + e.getMessage());
        }

        System.out.println("Dane zapisano do pliku: oceny_posortowane.txt");
    }

    // === Zadanie 1.3: Odczyt i obliczenia na danych z pliku ===
    public static void zad3() {
        Map<String, Integer> przedmiotOcena = wczytajZPliku("oceny.txt");
        if (przedmiotOcena.isEmpty()) {
            System.out.println("Brak danych w pliku.");
            return;
        }

        double srednia = przedmiotOcena.values().stream()
                .mapToInt(Integer::intValue)
                .average()
                .orElse(0.0);

        Map.Entry<String, Integer> max = przedmiotOcena.entrySet().stream()
                .max(Map.Entry.comparingByValue())
                .orElse(null);

        Map.Entry<String, Integer> min = przedmiotOcena.entrySet().stream()
                .min(Map.Entry.comparingByValue())
                .orElse(null);

        System.out.println("Średnia ocen: " + srednia);
        if (max != null) System.out.println("Najlepszy przedmiot: " + max.getKey() + " (" + max.getValue() + ")");
        if (min != null) System.out.println("Najgorszy przedmiot: " + min.getKey() + " (" + min.getValue() + ")");
    }

    // === Funkcje pomocnicze ===
    private static void zapiszDoPliku(Map<String, Integer> map, String filename) {
        try (FileWriter writer = new FileWriter(filename)) {
            for (Map.Entry<String, Integer> e : map.entrySet()) {
                writer.write(e.getKey() + ";" + e.getValue() + "\n");
            }
        } catch (IOException e) {
            System.err.println("Błąd zapisu do pliku: " + e.getMessage());
        }
    }

    private static Map<String, Integer> wczytajZPliku(String filename) {
        Map<String, Integer> map = new LinkedHashMap<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String linia;
            while ((linia = reader.readLine()) != null) {
                if (!linia.contains(";")) continue;
                String[] parts = linia.split(";");
                if (parts.length == 2) {
                    map.put(parts[0], Integer.parseInt(parts[1]));
                }
            }
        } catch (IOException e) {
            System.err.println("Błąd odczytu pliku: " + e.getMessage());
        }
        return map;
    }

    public static void main(String[] args) {
        //zad1();
        zad2();
        //zad3();
    }
}
