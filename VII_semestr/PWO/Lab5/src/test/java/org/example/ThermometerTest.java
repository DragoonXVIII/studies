package org.example;

import static org.junit.jupiter.api.Assertions.*;

import org.example.Thermometer;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

class ThermometerTest {
    Thermometer thermometer;

    @BeforeEach
    void init() {
        thermometer = new Thermometer(0, 10);
        thermometer.setCurrentTemp(5);
    }

    @Test
    @DisplayName("Test exception for setCurrentTemp out of range")
    void setCurrentTempExceptionTesting() {
        Throwable exception =
                assertThrows(IllegalArgumentException.class, () ->
                        thermometer.setCurrentTemp(100));

        assertEquals("Temperature is outside of the defined range.",
                exception.getMessage(), "Exception message should match the temperature range error.");
    }

    @Test
    @DisplayName("Test exception for addDegrees exceeding maxTemp")
    void addDegreesExceptionTesting() {
        Throwable exception =
                assertThrows(IllegalStateException.class, () ->
                        thermometer.addDegrees(6));
        assertEquals("Cannot exceed max temperature.",
                exception.getMessage(), "Exception message should match the max temperature error.");
    }

    @Test
    @DisplayName("Test exception for subtractDegrees below minTemp")
    void subtractDegreesExceptionTesting() {
        Throwable exception =
                assertThrows(IllegalStateException.class, () ->
                        thermometer.subtractDegrees(6));
        assertEquals("Cannot go below min temperature.",
                exception.getMessage(), "Exception message should match the min temperature error.");
    }

    /*
    Thermometer thermometer;

    @BeforeEach
    void init() {
        // Tworzenie instancji termometru z zakresem np. od -10 do 50
        thermometer = new Thermometer(-10, 50);
        thermometer.setCurrentTemp(10); // Ustawienie początkowej temperatury
    }

    @Test
    @DisplayName("Test various assertions on Thermometer")
    void testThermometerAssertions() {
        // assertNotEquals
        assertNotEquals(0, thermometer.getCurrentTemp(),
                "Current temp should not be zero after initialization");

        thermometer.setCurrentTemp(-5);
        // assertTrue
        assertTrue(thermometer.isBelowZero(),
                "Temperature should be below zero (-5)");

        thermometer.addDegrees(10); // -5 + 10 = 5
        // assertFalse
        assertFalse(thermometer.isBelowZero(),
                "Temperature should not be below zero (5)");

        Thermometer instance = Thermometer.createInstance(0, 100);
        // assertNotNull
        assertNotNull(instance,
                "The created instance of Thermometer should not be null");

        // assertNull
        Thermometer nullInstance = null;
        assertNull(nullInstance,
                "The variable explicitly set to null should be null");
    }
    */
}

