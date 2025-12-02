package org.example;

import org.junit.jupiter.api.BeforeEach;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

public class CalculatorTest2 {
    Calculator calculator;

    @BeforeEach
    void init() {
        calculator = new Calculator();
    }

    @ParameterizedTest
    @CsvSource({
            "2, 3, 6",      // 2 * 3 = 6
            "5, -1, -5",    // 5 * (-1) = -5
            "0, 10, 0",     // 0 * 10 = 0
            "1, 1, 1"       // 1 * 1 = 1
    })
    void testMultiplicationFromCsvSource(int a, int b, int expectedResult) {
        Calculator calculator = new Calculator();
        assertEquals(expectedResult, calculator.multiply(a, b),
                "Multiplication should work with CSV data");
    }

    /*
    @ParameterizedTest
    @CsvSource({ "foo, 1", "boo, 2" })
    void testMethod(String firstArgument, int secondArgument) {
        assertNotNull(firstArgument);
        assertEquals(2, secondArgument * 1);
    }
     */
}

