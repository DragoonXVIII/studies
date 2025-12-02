package org.example;

public class LongOperationService  {
    public String longTask(long sleepTime) throws InterruptedException {
        Thread.sleep(sleepTime);
        return "Task Completed";
    }
}
