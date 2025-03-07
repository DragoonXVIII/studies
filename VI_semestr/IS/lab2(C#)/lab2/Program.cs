using System;
using System.Collections.Generic;
using System.IO;
using YamlDotNet.Serialization;
using YamlDotNet.Serialization.NamingConventions;

class Config
{
    public Dictionary<string, string> Paths { get; set; }
    public SerializationConfig Serialization { get; set; }
}

class SerializationConfig
{
    public string Source { get; set; }
    public List<string> Operations { get; set; }
    public List<string> Order { get; set; }
}

class Program
{
    static void Main()
    {
        Console.WriteLine("Hey, it's me - C#!");

        var config = LoadConfig("Assets/advanced_config.yaml");
        Console.WriteLine("Config loaded!");

        Console.WriteLine($"Source Folder: {config.Paths["source_folder"]}");
        Console.WriteLine($"JSON Source File: {config.Paths["json_source_file"]}");

        string sourceFilePath = Path.Combine(config.Paths["source_folder"], config.Paths["json_source_file"]);
        Console.WriteLine($"Ścieżka pliku źródłowego: {sourceFilePath}");

        string outputJsonPath = Path.Combine(config.Paths["source_folder"], config.Paths["json_destination_file"]);
        Console.WriteLine($"Ścieżka pliku JSON: {outputJsonPath}");

        string outputYamlPath = Path.Combine(config.Paths["source_folder"], config.Paths["yaml_destination_file"]);
        Console.WriteLine($"Ścieżka pliku YAML: {outputYamlPath}");

        DeserializeJson deserializer = new DeserializeJson(sourceFilePath);

        if (config.Serialization != null && config.Serialization.Operations != null)
        {
            if (config.Serialization.Operations.Contains("convert_json_to_yaml"))
                Console.WriteLine("Konwersja JSON -> YAML");
            else
                Console.WriteLine("Konwersja JSON -> YAML nie jest wymagana.");
        }
        else
        {
            Console.WriteLine("Nie znaleziono operacji.");
        }

        if (config.Serialization.Operations.Contains("serialize_json"))
            SerializeJson.Run(deserializer.Data, outputJsonPath);

        if (config.Serialization.Operations.Contains("convert_json_to_yaml"))
            ConvertJsonToYaml.RunBtoY(deserializer.Data, outputYamlPath);
    }

    static Config LoadConfig(string path)
    {
        string yamlText = File.ReadAllText(path);

        var deserializer = new DeserializerBuilder()
            .WithNamingConvention(CamelCaseNamingConvention.Instance)
            .Build();

        var config = deserializer.Deserialize<Config>(yamlText);

        return config;
    }
}
