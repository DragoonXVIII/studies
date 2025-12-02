package org.example;

import static java.time.Duration.ofSeconds;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTimeout;
import static org.junit.jupiter.api.Assertions.assertTimeoutPreemptively;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

class LongOperationTest {

    private final LongOperationService service = new LongOperationService();

    @Test
    @DisplayName("Test timeout exceeded but task completes")
    void timeoutExceededWithResult() {
        String result = assertTimeout(ofSeconds(3), () -> {
            return service.longTask(2000);
        });
        assertEquals("Task Completed", result, "Result should be 'Task Completed'");
        assertTimeout(ofSeconds(7), () -> {
            service.longTask(2000);
        }, "The task should complete, even if it exceeds the timeout.");
    }

    @Test
    @DisplayName("Test preemptive timeout, task should be aborted")
    void timeoutExceededPreemptively() {
        assertTimeoutPreemptively(ofSeconds(1), () -> {
            service.longTask(5000);
            return "Should not reach here";
        }, "The task should be aborted after 1 second.");
    }
}
