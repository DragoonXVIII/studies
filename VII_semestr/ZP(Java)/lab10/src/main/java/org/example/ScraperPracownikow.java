package org.example;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import java.io.IOException;
import java.util.*;

//TODO: fix br w liście pracownikoiw
//TODO: filtr po dr itp w argumencie funkcji niech bedzie
//10.1
public class ScraperPracownikow {
    public static void run(String url) {
        try {
            Document doc = Jsoup.connect(url).get();
            Map<String, List<String>> zakladyInf = new LinkedHashMap<>();

            Elements headers = doc.select("article h3");

            for (Element header : headers) {
                String nazwaZakladu = header.text().trim();
                Element next = header.nextElementSibling();

                if (next != null && next.tagName().equals("p")) {
                    Elements links = next.select("a");
                    List<String> pracownicy = new ArrayList<>();

                    for (Element link : links) {
                        String osoba = link.text().trim();
                        if (!osoba.isEmpty()) {
                            String trailing = link.nextSibling() != null ? link.nextSibling().toString().trim() : "";
                            if (!trailing.isEmpty()) {
                                osoba += " " + trailing;
                            }
                            pracownicy.add(osoba);
                        }
                    }

                    if (!pracownicy.isEmpty()) {
                        Collections.sort(pracownicy, String.CASE_INSENSITIVE_ORDER);
                        zakladyInf.put(nazwaZakladu, pracownicy);
                    }
                }
            }

            // 10.2
            Map<String, List<String>> przefiltrowaneZaklady = new LinkedHashMap<>();
            for (Map.Entry<String, List<String>> entry : zakladyInf.entrySet()) {
                List<String> przefiltrowaniPracownicy = new ArrayList<>();
                for (String osoba : entry.getValue()) {
                    if (osoba.startsWith("dr ")) // dr hab to tez dr
                        przefiltrowaniPracownicy.add(osoba);
                    else if (osoba.startsWith("dr inż."))
                        przefiltrowaniPracownicy.add(osoba);
                }
                if (!przefiltrowaniPracownicy.isEmpty()) {
                    przefiltrowaneZaklady.put(entry.getKey(), przefiltrowaniPracownicy);
                }
            }

            int licznik = 1;
            for (Map.Entry<String, List<String>> entry : przefiltrowaneZaklady.entrySet()) {
                System.out.println(licznik++ + ". " + entry.getKey());
                List<String> pracownicy = entry.getValue();
                int licznikPracownikow = 1;
                for (String osoba : pracownicy) {
                    System.out.println("   " + licznikPracownikow++ + ") " + osoba);
                }
                System.out.println("   Razem: " + pracownicy.size() + " osób\n");
            }

        } catch (IOException e) {
            System.err.println("Błąd połączenia z " + url);
            e.printStackTrace();
        }
    }
}
