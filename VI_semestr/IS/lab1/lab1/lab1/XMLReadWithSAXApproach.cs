using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Xml;

public class XMLReadWithSAXApproach
{
    internal static void Read(string filepath)
    {
        XmlReaderSettings settings = new XmlReaderSettings();
        settings.IgnoreComments = true;
        settings.IgnoreProcessingInstructions = true;
        settings.IgnoreWhitespace = true;

        using (XmlReader reader = XmlReader.Create(filepath, settings))
        {
            int count = 0;
            string postac = "";
            string sc = "";

            Dictionary<string, int> producerCreamCount = new Dictionary<string, int>();
            Dictionary<string, int> producerTabletCount = new Dictionary<string, int>();

            reader.MoveToContent();

            while (reader.Read())
            {
                if (reader.NodeType == XmlNodeType.Element && reader.Name == "produktLeczniczy")
                {
                    postac = reader.GetAttribute("nazwaPostaciFarmaceutycznej");
                    sc = reader.GetAttribute("nazwaPowszechnieStosowana");
                    string producent = reader.GetAttribute("podmiotOdpowiedzialny");

                    if (postac == "Krem" && sc == "Mometasoni furoas")
                    {
                        count++;
                    }

                    if (!string.IsNullOrEmpty(producent))
                    {
                        if (postac == "Krem")
                        {
                            if (!producerCreamCount.ContainsKey(producent))
                                producerCreamCount[producent] = 0;
                            producerCreamCount[producent]++;
                        }
                        else if (postac == "Tabletka")
                        {
                            if (!producerTabletCount.ContainsKey(producent))
                                producerTabletCount[producent] = 0;
                            producerTabletCount[producent]++;
                        }
                    }
                }
            }

            Console.WriteLine("Liczba produktów leczniczych w postaci kremu, których jedyną substancją czynną jest Mometasoni furoas: {0}", count);
            Console.WriteLine("Producent z największą liczbą kremów: {0}", GetTopProducer(producerCreamCount));
            Console.WriteLine("Producent z największą liczbą tabletek: {0}", GetTopProducer(producerTabletCount));
            Console.WriteLine("Top 3 producenci kremów:");
            GetTopProducers(producerCreamCount, 3);
            Console.WriteLine("Top 3 producenci tabletek:");
            GetTopProducers(producerTabletCount, 3);
        }
    }

    private static void GetTopProducers(Dictionary<string, int> producerCounts, int count)
    {
        var topProducers = producerCounts.OrderByDescending(p => p.Value).Take(count);
        foreach (var producer in topProducers)
        {
            Console.WriteLine("{0}: {1}", producer.Key, producer.Value);
        }
    }

    private static string GetTopProducer(Dictionary<string, int> producerCounts)
    {
        string topProducer = "Brak danych";
        int maxCount = 0;

        foreach (var producer in producerCounts)
        {
            if (producer.Value > maxCount)
            {
                maxCount = producer.Value;
                topProducer = producer.Key;
            }
        }
        return topProducer;
    }
}
