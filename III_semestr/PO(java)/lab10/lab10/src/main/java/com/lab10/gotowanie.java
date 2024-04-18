package com.lab10;

public class gotowanie 
{
    public static void main(String[] args) 
    {
        automatNalesnikowy pancakeMachine = new automatNalesnikowy();
        kucharz cook = new kucharz(pancakeMachine);

        // Uruchomienie wątku do obsługi procesu produkcyjnego
        Thread cookThread = new Thread(cook);
        cookThread.start();

        // Symulacja produkcji naleśników
        for (int i = 1; i <= 10; i++) 
        {
            try 
            {
                String pancake = "Naleśnik " + i;
                pancakeMachine.getPancakeQueue().put(pancake);
                System.out.println("Dodano naleśnik do kolejki: " + pancake);
                Thread.sleep(1000);
            } 
            catch (InterruptedException e) 
            {
                e.printStackTrace();
            }
        }

        // Zatrzymanie wątku po zakończeniu produkcji
        cookThread.interrupt();
    }
}
