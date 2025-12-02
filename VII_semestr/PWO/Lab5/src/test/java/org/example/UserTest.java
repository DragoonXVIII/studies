package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertAll;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;

public class UserTest {

    @Test
    void groupedUserAssertions() {
        User user = new User("Paweł", "Kowalski");

        assertAll("User Name Check",
                () -> assertEquals("Paweł", user.getFirstName(), "First name should be Paweł"),
                () -> assertNotEquals("Nowak", user.getLastName(), "Last name should not be Nowak")
        );
    }

    @Test
    void groupedUserAssertions2() {
        User user = new User("Jan", "Paweł");

        assertAll("User Name Check (Surname)",
                () -> assertNotEquals("Paweł", user.getFirstName(), "First name should not be Paweł"),
                () -> assertEquals("Paweł", user.getLastName(), "Last name should be Paweł")
        );
    }
}

