package org.example;

public class Thermometer {

    int minTemp;
    int maxTemp;
    int currentTemp;

    public Thermometer(int minTemp, int maxTemp){
        this.minTemp = minTemp;
        this.maxTemp = maxTemp;
        this.currentTemp = 0;
    }

    public static Thermometer createInstance(int minTemp, int maxTemp) {
        return new Thermometer(minTemp, maxTemp);
    }

    public int getCurrentTemp(){
        return currentTemp;
    }

    public void setCurrentTemp(int currentTemp){
        if (currentTemp < minTemp || currentTemp > maxTemp) {
            throw new IllegalArgumentException("Temperature is outside of the defined range.");
        }
        this.currentTemp = currentTemp;
    }

    public int addDegrees(int degrees){
        int newTemp = currentTemp + degrees;
        if (newTemp > maxTemp) {
            throw new IllegalStateException("Cannot exceed max temperature.");
        }
        currentTemp = newTemp;
        return currentTemp;
    }

    public int subtractDegrees(int degrees){
        int newTemp = currentTemp - degrees;
        if (newTemp < minTemp) {
            throw new IllegalStateException("Cannot go below min temperature.");
        }
        currentTemp = newTemp;
        return currentTemp;
    }

    public boolean isBelowZero(){
        return currentTemp<0?true:false;
    }


    // =========================


}