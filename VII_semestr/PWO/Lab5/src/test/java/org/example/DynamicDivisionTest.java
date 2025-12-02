package org.example;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.DynamicTest.dynamicTest;

import java.util.Arrays;
import java.util.stream.Stream;

import org.junit.jupiter.api.DynamicTest;
import org.junit.jupiter.api.TestFactory;

class DynamicDivisionTest {

    @TestFactory
    Stream<DynamicTest> testDifferentDivisions() {
        Calculator calculator = new Calculator();

        int[][] regularDivisions = new int[][]{{10, 2, 5}, {9, 3, 3}, {15, 5, 3}};
        Stream<DynamicTest> regularTests = Arrays.stream(regularDivisions)
                .map(entry -> {
                    int val1 = entry[0];
                    int val2 = entry[1];
                    int result = entry[2];
                    return dynamicTest(val1 + " / " + val2 + " = " + result,
                            () -> assertEquals(result, calculator.divide(val1, val2),
                                    "Division should be correct"));
                });

        int[][] exceptionDivisions = new int[][]{{10, 0}, {5, 0}, {0, 0}};
        Stream<DynamicTest> exceptionTests = Arrays.stream(exceptionDivisions)
                .map(entry -> {
                    int val1 = entry[0];
                    int val2 = entry[1];
                    return dynamicTest(val1 + " / " + val2 + " throws Exception",
                            () -> assertThrows(IllegalArgumentException.class,
                                    () -> calculator.divide(val1, val2),
                                    "Division by zero should throw IllegalArgumentException"));
                });

        return Stream.concat(regularTests, exceptionTests);
    }
}
