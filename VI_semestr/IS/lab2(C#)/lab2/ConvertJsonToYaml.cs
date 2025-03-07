using System;
using System.Collections.Generic;
using System.IO;
using Newtonsoft.Json;
using YamlDotNet.Serialization;

public class ConvertJsonToYaml
{
    public static void RunBtoY(List<Dictionary<string, object>> data, string destinationFile)
    {
        Console.WriteLine("Let's convert JSON to YAML...");

        try
        {
            var serializer = new SerializerBuilder().Build();
            string yamlString = serializer.Serialize(data);

            File.WriteAllText(destinationFile, yamlString);
            Console.WriteLine("Conversion complete!");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Błąd konwersji: {ex.Message}");
        }
    }

    public static void RunJtoY(string jsonFile, string yamlFile)
    {
        Console.WriteLine("Converting JSON file to YAML file...");

        try
        {
            string jsonString = File.ReadAllText(jsonFile);
            var jsonData = JsonConvert.DeserializeObject<List<Dictionary<string, object>>>(jsonString);

            RunBtoY(jsonData, yamlFile);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Błąd konwersji pliku: {ex.Message}");
        }
    }
}
