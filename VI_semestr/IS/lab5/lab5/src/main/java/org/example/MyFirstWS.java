package org.example;

import javax.jws.WebService;
import java.time.Duration;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

@WebService(endpointInterface =
        "com.soapsoapsoap.MyFirstSOAPInterface")

public class MyFirstWS implements MyFirstSOAPInterface{

    public String getHelloWorldAsString(String nazwa) {
        String message = "Witaj "+nazwa+"!";
        return message;
    }
    public long getDaysBetweenDates(String date1, String
            date2) {

        long numberOfDays=0;
        DateTimeFormatter dtf =
                DateTimeFormatter.ofPattern("dd MM yyyy");

        try {
            LocalDateTime tempdate1 = LocalDate.parse(date1,
                    dtf).atStartOfDay();
            LocalDateTime tempdate2 = LocalDate.parse(date2,
                    dtf).atStartOfDay();
            numberOfDays = Duration.between(tempdate1,
                    tempdate2).toDays();

        } catch (Exception e) {
            e.printStackTrace();
        }

        return numberOfDays;
    }
}
