using System;
using System.Collections.Generic;
using System.IO;
using Newtonsoft.Json;

public class SerializeJson
{
    public static void Run(List<Dictionary<string, object>> data, string destinationFile)
    {
        Console.WriteLine("Let's serialize something...");

        try
        {
            string jsonString = JsonConvert.SerializeObject(data, Formatting.Indented);
            File.WriteAllText(destinationFile, jsonString);
            Console.WriteLine("Serialization complete!");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Błąd serializacji: {ex.Message}");
        }
    }
}
