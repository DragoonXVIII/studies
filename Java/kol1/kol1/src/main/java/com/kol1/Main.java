package com.kol1;

public class Main 
{
    public static void main(String[] args) 
    {   
        //ZADANIE 1
        /*
        //System.out.println("Hello world!");
        System.out.println("Podaj łancuch znaków: ");
        String str = System.console().readLine();
        System.out.println("Podany łańcuch znaków ma " + str.length() + " znaków.");
        System.out.println("Imię i nazwisko: " + "Imię" + " " + "nazwisko");
        */

        //ZADANIE 2
        /*
        Truck t1 = new Truck();
        System.out.println(t1.ileMiejsc());
        System.out.println("Imię i nazwisko: " + "Imię" + " " + "nazwisko");
        */

        //ZADANIE 3
        
        System.out.println("Podaj wymiary tablicy dwuwymiarowej: ");
        int a = Integer.parseInt(System.console().readLine());
        int b = Integer.parseInt(System.console().readLine());
        int[][] tab = new int[a][b];
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                tab[i][j] = (int)(Math.random()*41+10);
            }
        }
        
        int max1 = 0;
        int max2 = 0;
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                if(tab[i][j] > max1)
                {
                    max1 = tab[i][j];
                }
            }
        }
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                if(tab[i][j] > max2 && tab[i][j] < max1)
                {
                    max2 = tab[i][j];
                }
            }
        }

        System.out.println("Największy element tablicy: " + max1);
        System.out.println("Drugi największy element tablicy: " + max2);
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                System.out.print(tab[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("Imię i nazwisko: " + "Imię" + " " + "nazwisko");
    }
}
