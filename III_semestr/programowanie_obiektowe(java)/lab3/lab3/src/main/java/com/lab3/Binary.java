package com.lab3;

public class Binary 
{
    public static String intToBinaryString(int liczba)
    {
        String binarnie;
        binarnie = Integer.toBinaryString(liczba);
        return binarnie;
    }

    public static int zeroSequence(String binarnaLiczba)
    {
        int iloscSekwencji = 0;
        int aktualnaSekwencjaZer = 0;
        boolean wSekwencji = false;
                                                                                    //10101 01010 1010010110
        for(int c = 0; c < binarnaLiczba.length(); c++)
         {
            char znak = binarnaLiczba.charAt(c);
            
            if(znak == '0') 
            {
                if(wSekwencji)
                    aktualnaSekwencjaZer++;
            }   
            else if(znak == '1')
            {
                if(wSekwencji && aktualnaSekwencjaZer > 0) 
                {
                    iloscSekwencji++;
                    aktualnaSekwencjaZer = 0;
                }
                wSekwencji = true;
            } 
            else 
                wSekwencji = false;
        }
        if(iloscSekwencji == 0)
            return 0;
        return iloscSekwencji;
    }
}

/*
Napisz aplikację zawierającą metody:
 pobierającą argument wejściowy typu int i zwracającą ciąg znaków – binarną 
reprezentację podanej liczby,
 pobierającą argument wejściowy klasy String – liczbę w reprezentacji binarnej oraz 
zwracający całkowitą liczbę sekwencji zer w postaci łańcucha znaków. Należy 
założyć, że dany łańcuch znaków składa się wyłącznie cyfry 0 i 1. W przypadku braku 
sekwencji zer należy zwrócić komunikat. Sekwencję zer należy rozumieć jako ciąg zer 
oddzielony obustronnie jedynkami. Przykładowo liczba 556 -> 1000101100 posiada 
dwie sekwencje zer z czego najdłuższa posiada trzy zera i metoda powinna zwrócić 
wartość „3”. Ostatnie dwa zera nie są brane pod uwagę, ponieważ nie są obustronnie 
oddzielone jedynkami.
Wykorzystując powyższe metody wyświetl zadaną liczbę, jej reprezentację binarną 
oraz największą sekwencję zer (o ile istnieje). W klasie Integer znajdziesz interesującą 
metodę.
*/