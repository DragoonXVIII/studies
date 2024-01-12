package lab9.com;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class SzyfrCezara 
{
    public static char[] polskiAlfabetMale = {'a', 'ą', 'b', 'c', 'ć', 'd', 'e', 'ę', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'ł', 'm', 'n', 'ń', 'o', 'ó', 'p', 'r', 's', 'ś', 't', 'u', 'v', 'w', 'y', 'z', 'ź', 'ż'};
    public static char[] polskiAlfabetDuze = {'A', 'Ą', 'B', 'C', 'Ć', 'D', 'E', 'Ę', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'Ł', 'M', 'N', 'Ń', 'O', 'Ó', 'P', 'R', 'S', 'Ś', 'T', 'U', 'V', 'W', 'Y', 'Z', 'Ź', 'Ż'};
    public static char[] cezarAlfabetMale = {'d', 'e', 'ę', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'ł', 'm', 'n', 'ń', 'o', 'ó', 'p', 'r', 's', 'ś', 't', 'u', 'v', 'w', 'y', 'z', 'ź', 'ż', 'a', 'ą', 'b', 'c', 'ć'};
    public static char[] cezarAlfabetDuze = {'D', 'E', 'Ę', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'Ł', 'M', 'N', 'Ń', 'O', 'Ó', 'P', 'R', 'S', 'Ś', 'T', 'U', 'V', 'W', 'Y', 'Z', 'Ź', 'Ż', 'A', 'Ą', 'B', 'C', 'Ć'};

    public static void main(String[] args) 
    {
        cypher();
        decypher();
    }

    public static void cypher()
    {
        try
        {
            BufferedReader reader = new BufferedReader(new FileReader("cypher.txt"));
            String linia;
            StringBuilder tekstWejsciowy = new StringBuilder();
            while((linia = reader.readLine()) != null) 
            {
                tekstWejsciowy.append(linia).append("\n");
            }
            for(int i = 0; i < tekstWejsciowy.length(); i++)
            {
                for(int j = 0; j < polskiAlfabetMale.length; j++)
                {
                    if(tekstWejsciowy.charAt(i) == polskiAlfabetMale[j])
                    {
                        if(j < polskiAlfabetMale.length - 3)
                        {
                            tekstWejsciowy.setCharAt(i, polskiAlfabetMale[j + 3]);
                            break;
                        }
                        else
                        {
                            tekstWejsciowy.setCharAt(i, polskiAlfabetMale[j - polskiAlfabetMale.length + 3]);
                            break;
                        }
                    }
                    else if(tekstWejsciowy.charAt(i) == polskiAlfabetDuze[j])
                    {
                        if(j < polskiAlfabetDuze.length - 3)
                        {
                            tekstWejsciowy.setCharAt(i, polskiAlfabetDuze[j + 3]);
                            break;
                        }
                        else
                        {
                            tekstWejsciowy.setCharAt(i, polskiAlfabetDuze[j - polskiAlfabetDuze.length + 3]);
                            break;
                        }
                    }
                }
            }
            try
            {
                BufferedWriter writer = new BufferedWriter(new FileWriter("zaszyfrowane.txt"));
                writer.write(tekstWejsciowy.toString());
                writer.close();
            }
            catch(IOException e)
            {
                e.printStackTrace();
            }
            reader.close();
        }
        catch (IOException e) 
        {
            e.printStackTrace();
        }
    }

    public static void decypher() {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("zaszyfrowane.txt"));
            String linia;
            StringBuilder tekstZaszyfrowany = new StringBuilder();
            while ((linia = reader.readLine()) != null) {
                tekstZaszyfrowany.append(linia).append("\n");
            }
    
            for (int i = 0; i < tekstZaszyfrowany.length(); i++) {
                for (int j = 0; j < polskiAlfabetMale.length; j++) {
                    if (tekstZaszyfrowany.charAt(i) == polskiAlfabetMale[j]) {
                        if (j >= 3) {
                            tekstZaszyfrowany.setCharAt(i, polskiAlfabetMale[j - 3]);
                            break;
                        } else {
                            tekstZaszyfrowany.setCharAt(i, polskiAlfabetMale[j + polskiAlfabetMale.length - 3]);
                            break;
                        }
                    } else if (tekstZaszyfrowany.charAt(i) == polskiAlfabetDuze[j]) {
                        if (j >= 3) {
                            tekstZaszyfrowany.setCharAt(i, polskiAlfabetDuze[j - 3]);
                            break;
                        } else {
                            tekstZaszyfrowany.setCharAt(i, polskiAlfabetDuze[j + polskiAlfabetDuze.length - 3]);
                            break;
                        }
                    }
                }
            }
    
            try {
                BufferedWriter writer = new BufferedWriter(new FileWriter("odszyfrowane.txt"));
                writer.write(tekstZaszyfrowany.toString());
                writer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
}
