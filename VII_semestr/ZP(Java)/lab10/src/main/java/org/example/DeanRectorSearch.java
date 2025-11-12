package org.example;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import javax.net.ssl.*;
import java.io.IOException;
import java.security.SecureRandom;
import java.security.cert.X509Certificate;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.*;

public class DeanRectorSearch {

    private static class NewsItem {
        LocalDate date;
        String title;
        String url;
        String content;

        public NewsItem(LocalDate date, String title, String url, String content) {
            this.date = date;
            this.title = title;
            this.url = url;
            this.content = content;
        }
    }

    private static void disableCertificateValidation() {
        try {
            TrustManager[] trustAllCerts = new TrustManager[]{
                    new X509TrustManager() {
                        public X509Certificate[] getAcceptedIssuers() { return null; }
                        public void checkClientTrusted(X509Certificate[] certs, String authType) {}
                        public void checkServerTrusted(X509Certificate[] certs, String authType) {}
                    }
            };
            SSLContext sc = SSLContext.getInstance("SSL");
            sc.init(null, trustAllCerts, new SecureRandom());
            HttpsURLConnection.setDefaultSSLSocketFactory(sc.getSocketFactory());
            HttpsURLConnection.setDefaultHostnameVerifier((hostname, session) -> true);
        } catch (Exception ignored) {}
    }

    public static void run(String searchUrl) {
        disableCertificateValidation();

        List<NewsItem> items = new ArrayList<>();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");

        try {
            Document doc = Jsoup.connect(searchUrl).get();
            Elements headers = doc.select("h4 > a.title");

            for (Element link : headers) {
                String url = link.absUrl("href");
                String title = link.text().replaceAll("\\s+", " ").trim();

                // Pobieramy datę z <small> wewnątrz linku
                Element dateEl = link.selectFirst("small");
                LocalDate date = null;
                if (dateEl != null) {
                    try {
                        date = LocalDate.parse(dateEl.text().trim(), formatter);
                    } catch (Exception ignored) {}
                }

                // Pobieramy treść strony
                String content = "";
                try {
                    Document article = Jsoup.connect(url).get();
                    Element div = article.selectFirst("div.content-white");
                    if (div != null) {
                        content = div.text().trim();
                    }
                } catch (IOException e) {
                    System.err.println("Błąd pobierania treści: " + url);
                }

                items.add(new NewsItem(date, title, url, content));
            }

        } catch (IOException e) {
            System.err.println("Błąd połączenia z " + searchUrl);
            e.printStackTrace();
            return;
        }

        items.sort(Comparator.comparing(i -> i.date));

        // widok szybki
        System.out.println("=== Lista znalezonych ogłoszeń ===");
        for (NewsItem item : items) {
            System.out.printf("%s - %s%n",
                    item.date != null ? item.date : "brak daty",
                    item.title);
        }

        // widok z tresciom
        System.out.println("\n=== Szczegóły ===");
        for (NewsItem item : items) {
            System.out.println(item.date != null ? item.date : "brak daty");
            System.out.println(item.title);
            System.out.println(item.content);
            System.out.println();
        }
    }
}
