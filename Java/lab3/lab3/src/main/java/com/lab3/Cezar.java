package com.lab3;

import java.util.Scanner;

public class Cezar 
{
    public static String returnAsString()
    {
        System.out.println("Wpisz: ");
        Scanner scanner = new Scanner(System.in);
        String string = scanner.nextLine();
        scanner.close();
        return string;
    }
    public static String cypherCezar(String text)
    {
        char[] textTab = text.toCharArray();
    
        for(int c = 0; c < textTab.length; c++) 
        {
            char originalChar = textTab[c];
            char cypheredChar;
            if(originalChar >= 97 && originalChar <= 122)
            {
                if(originalChar == 'x' ||originalChar == 'y' ||originalChar == 'z')
                {
                    cypheredChar = (char)(originalChar - 26 + 3); 
                }
                else
                    cypheredChar = (char)(originalChar + 3); 

                textTab[c] = cypheredChar;
            }
        }
        return new String(textTab);
    }

    static String decypherCezar(String text)
    {
        char[] textTab = text.toCharArray();
    
        for(int c = 0; c < textTab.length; c++) 
        {
            char originalChar = textTab[c];
            char cypheredChar;
            if(originalChar >= 97 && originalChar <= 122)
            {
                if(originalChar == 'a' ||originalChar == 'b' ||originalChar == 'c')
                {
                    cypheredChar = (char)(originalChar + 26- 3); 
                }
                else
                    cypheredChar = (char)(originalChar - 3); 

                textTab[c] = cypheredChar;
            }
        }
        return new String(textTab);
    }
    public static boolean check(String text) 
    {
        String cleanedText = text;
        int length = cleanedText.length();
        for (int i = 0; i < length / 2; i++) 
        {
            if (cleanedText.charAt(i) != cleanedText.charAt(length - i - 1)) 
            {
                return false;
            }
        }
        return true;
    }

    /* static String cypherCezar(String text)
    {
         String cyphered;
        //char textTab[] = text.toCharArray();
        for(int c=0;c<text.length();c++)
        {
            textTab.charAt(c) = (char)(text.charAt(c)+3);
            char originalChar = text.charAt(c);
            char cypheredChar = (char)(originalChar + 3); // Szyfr Cezara z przesunięciem o 3 miejsca.
            textTab.setCharAt(c, cypheredChar);

            str = str.substring(0, index) + ch 
              + str.substring(index + 1); 
        }

        return cyphered;
    }*/

}
