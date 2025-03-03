using System.Xml;
using System;
using System.Collections.Generic;
using System.Linq;

namespace lab1
{
    internal class XMLReadWithDOMApproach
    {
        internal static void Read(string filepath)
        {
            XmlDocument doc = new XmlDocument();
            doc.Load(filepath);
            string postac;
            string sc;
            int count = 0;
            var drugs = doc.GetElementsByTagName("produktLeczniczy");

            Dictionary<string, int> producerCreamCount = new Dictionary<string, int>();
            Dictionary<string, int> producerTabletCount = new Dictionary<string, int>();

            foreach (XmlNode d in drugs)
            {
                postac = d.Attributes.GetNamedItem("nazwaPostaciFarmaceutycznej")?.Value;
                sc = d.Attributes.GetNamedItem("nazwaPowszechnieStosowana")?.Value;
                string producent = d.Attributes.GetNamedItem("podmiotOdpowiedzialny")?.Value;

                if (postac != null && sc != null)
                {
                    if (postac == "Krem" && sc == "Mometasoni furoas")
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
            Console.WriteLine("Liczba produktów leczniczych w postaci kremu, których jedyną substancją czynną jest Mometasoni furoas {0}", count);
            Console.WriteLine("Producent z największą liczbą kremów: {0}", GetTopProducer(producerCreamCount));
            Console.WriteLine("Producent z największą liczbą tabletek: {0}", GetTopProducer(producerTabletCount));
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

        internal static void Read2(string filepath)
        {
            XmlDocument doc = new XmlDocument();
            doc.Load(filepath);

            var drugForms = new Dictionary<string, HashSet<string>>();
            int multiFormDrugCount = 0;
            int lineNumber = 1;

            var drugs = doc.GetElementsByTagName("produktLeczniczy");
            foreach (XmlNode d in drugs)
            {
                var postacAttr = d.Attributes.GetNamedItem("nazwaPostaciFarmaceutycznej");
                var scAttr = d.Attributes.GetNamedItem("nazwaPowszechnieStosowana");

                if (postacAttr != null && scAttr != null)
                {
                    string postac = postacAttr.Value;
                    string sc = scAttr.Value;

                    if (!drugForms.ContainsKey(sc))
                    {
                        drugForms[sc] = new HashSet<string>();
                    }

                    drugForms[sc].Add(postac);
                }
            }

            foreach (var entry in drugForms)
            {
                if (entry.Value.Count > 1)
                {
                    Console.WriteLine($"{lineNumber}. Nazwa powszechna: {entry.Key}, Liczba różnych postaci: {entry.Value.Count}");
                    multiFormDrugCount++;
                    lineNumber++;
                }
            }

            Console.WriteLine($"Liczba leków o więcej niż jednej różnej postaci: {multiFormDrugCount}");
        }

        internal static void Read2_short(string filepath)
        {
            XmlDocument doc = new XmlDocument();
            doc.Load(filepath);

            var drugForms = new Dictionary<string, HashSet<string>>();
            int multiFormDrugCount = 0;

            var drugs = doc.GetElementsByTagName("produktLeczniczy");
            foreach (XmlNode d in drugs)
            {
                var postacAttr = d.Attributes.GetNamedItem("nazwaPostaciFarmaceutycznej");
                var scAttr = d.Attributes.GetNamedItem("nazwaPowszechnieStosowana");

                if (postacAttr != null && scAttr != null)
                {
                    string postac = postacAttr.Value;
                    string sc = scAttr.Value;

                    if (!drugForms.ContainsKey(sc))
                    {
                        drugForms[sc] = new HashSet<string>();
                    }

                    drugForms[sc].Add(postac);
                }
            }

            foreach (var entry in drugForms)
            {
                if (entry.Value.Count > 1)
                {
                    multiFormDrugCount++;
                }
            }

            Console.WriteLine($"Liczba leków o więcej niż jednej różnej postaci: {multiFormDrugCount}");
        
        }

        // after modifiation zad 1.4.2
        internal static void Read3_short(string filepath)
        {
            XmlDocument doc = new XmlDocument();
            doc.Load(filepath);
            string postac;
            string producent;

            Dictionary<string, int> producerCreamCount = new Dictionary<string, int>();
            Dictionary<string, int> producerTabletCount = new Dictionary<string, int>();
            Dictionary<string, HashSet<string>> drugForms = new Dictionary<string, HashSet<string>>();
            int multiFormDrugCount = 0;

            var drugs = doc.GetElementsByTagName("produktLeczniczy");

            foreach (XmlNode d in drugs)
            {
                postac = d.Attributes?["nazwaPostaciFarmaceutycznej"]?.Value;
                producent = d.Attributes?["podmiotOdpowiedzialny"]?.Value;
                string sc = d.Attributes?["nazwaPowszechnieStosowana"]?.Value;

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

                if (!string.IsNullOrEmpty(sc) && !string.IsNullOrEmpty(postac))
                {
                    if (!drugForms.ContainsKey(sc))
                    {
                        drugForms[sc] = new HashSet<string>();
                    }
                    drugForms[sc].Add(postac);
                }
            }

            foreach (var entry in drugForms)
            {
                if (entry.Value.Count > 1)
                {
                    multiFormDrugCount++;
                }
            }

            Console.WriteLine("Top 3 producenci kremów:");
            ListTopProducers(producerCreamCount);
            Console.WriteLine("Top 3 producenci tabletek:");
            ListTopProducers(producerTabletCount);
            Console.WriteLine($"Liczba leków o więcej niż jednej różnej postaci: {multiFormDrugCount}");
        }

        private static void ListTopProducers(Dictionary<string, int> producerCounts)
        {
            var topProducers = producerCounts.OrderByDescending(p => p.Value).Take(3);
            foreach (var producer in topProducers)
            {
                Console.WriteLine("{0}: {1}", producer.Key, producer.Value);
            }
        }


        //DEBUG
        private static void PrintNodes(XmlNode node, int indent)
        {
            if (node == null) return;

            string indentString = new string(' ', indent * 2);
            Console.WriteLine($"{indentString}Node: {node.Name}, Value: {node.Value}");

            if (node.Attributes != null)
            {
                foreach (XmlAttribute attr in node.Attributes)
                {
                    Console.WriteLine($"{indentString}  Attribute: {attr.Name}, Value: {attr.Value}");
                }
            }

            foreach (XmlNode child in node.ChildNodes)
            {
                PrintNodes(child, indent + 1);
            }
        }
    }
}
