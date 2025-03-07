using System;
using System.Collections.Generic;
using System.IO;
using Newtonsoft.Json;

public class DeserializeJson
{
    public List<Dictionary<string, object>> Data { get; private set; }

    public DeserializeJson(string filename)
    {
        Console.WriteLine("Let's deserialize something!");
        try
        {
            string jsonContent = File.ReadAllText(filename);
            var jsonData = JsonConvert.DeserializeObject<Dictionary<string, List<Dictionary<string, object>>>>(jsonContent);

            if (jsonData != null && jsonData.ContainsKey("baza teleadresowa jst"))
            {
                Data = jsonData["baza teleadresowa jst"];
            }
            else
            {
                throw new Exception("Invalid JSON format: missing 'baza teleadresowa jst' key.");
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error reading JSON: " + ex.Message);
            Data = new List<Dictionary<string, object>>();
        }
    }
}

