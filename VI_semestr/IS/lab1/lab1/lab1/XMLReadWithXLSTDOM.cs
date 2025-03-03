using System.Xml.XPath;
using System.Xml;
using System;
using System.Collections.Generic;
using System.Linq;
using OxyPlot;
using OxyPlot.Series;
using OxyPlot.Axes;
using OxyPlot.SkiaSharp;
using OxyPlot.Series;
using System.IO;
using System.Xml.Linq;



namespace lab1
{
    internal class XMLReadWithXLSTDOM
    {
        internal static void Read(string filepath)
        {
            XPathDocument document = new XPathDocument(filepath);
            XPathNavigator navigator = document.CreateNavigator();
            XmlNamespaceManager manager = new XmlNamespaceManager(navigator.NameTable);
            manager.AddNamespace("x", "http://rejestrymedyczne.ezdrowie.gov.pl/rpl/eksport-danych-v1.0");

            XPathExpression query = navigator.Compile("/x:produktyLecznicze/x:produktLeczniczy[@nazwaPostaciFarmaceutycznej = 'Krem' and @nazwaPowszechnieStosowana = 'Mometasoni furoas']");
            query.SetContext(manager);
            int count = navigator.Select(query).Count;
            Console.WriteLine("Liczba produktów leczniczych w postaci kremu, których jedyną substancją czynną jest Mometasoni furoas: {0}", count);

            GetTopProducers(navigator, manager);

        }

        private static void GetTopProducers(XPathNavigator navigator, XmlNamespaceManager manager)
        {
            Dictionary<string, int> producerCreamCount = new Dictionary<string, int>();
            Dictionary<string, int> producerTabletCount = new Dictionary<string, int>();

            XPathNodeIterator nodes = navigator.Select("/x:produktyLecznicze/x:produktLeczniczy", manager);
            while (nodes.MoveNext())
            {
                string postac = nodes.Current.GetAttribute("nazwaPostaciFarmaceutycznej", "");
                string producent = nodes.Current.GetAttribute("podmiotOdpowiedzialny", "");

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

            Console.WriteLine("Producent z największą liczbą kremów: {0}", GetTopProducer(producerCreamCount));
            Console.WriteLine("Producent z największą liczbą tabletek: {0}", GetTopProducer(producerTabletCount));
            Console.WriteLine("Top 3 producentów z największą liczbą kremów: ");
            GetTopProducers(producerCreamCount, 3);
            Console.WriteLine("Top 3 producentów z największą liczbą tabletek: ");
            GetTopProducers(producerTabletCount, 3);
        }

        private static string GetTopProducer(Dictionary<string, int> producerCounts)
        {
            return producerCounts.OrderByDescending(p => p.Value).FirstOrDefault().Key ?? "Brak danych";
        }

        private static void GetTopProducers(Dictionary<string, int> producerCounts, int count)
        {
            var topProducers = producerCounts.OrderByDescending(p => p.Value).Take(count);
            foreach (var producer in topProducers)
            {
                Console.WriteLine("{0}: {1}", producer.Key, producer.Value);
            }
        }

        internal static void IdentifyProductsWithActiveSubstances(string xmlFilePath)
        {
            // Ładujemy dokument XML
            XmlDocument doc = new XmlDocument();
            doc.Load(xmlFilePath);

            // Ustawienie managera przestrzeni nazw
            XmlNamespaceManager nsManager = new XmlNamespaceManager(doc.NameTable);
            nsManager.AddNamespace("ns", "http://rejestrymedyczne.ezdrowie.gov.pl/rpl/eksport-danych-v1.0");

            // Zapytanie XPath: wybieramy produkty, które mają co najmniej jeden element substancjaCzynna
            string xpath = "/ns:produktyLecznicze/ns:produktLeczniczy[count(ns:substancjeCzynne/ns:substancjaCzynna) > 0]";
            XmlNodeList productNodes = doc.SelectNodes(xpath, nsManager);
            Console.WriteLine($"Znaleziono {productNodes.Count} produktów posiadających substancje czynne:\n");

            foreach (XmlNode product in productNodes)
            {
                // Pobieramy nazwę produktu
                string productName = product.Attributes["nazwaProduktu"]?.Value ?? "Nieznany produkt";
                Console.WriteLine("Produkt: " + productName);

                // Pobieramy wszystkie substancje czynne w danym produkcie
                XmlNodeList substNodes = product.SelectNodes("ns:substancjeCzynne/ns:substancjaCzynna", nsManager);
                Console.WriteLine($"Liczba substancji czynnych: {substNodes.Count}");
                Console.WriteLine("Substancje czynne:");
                foreach (XmlNode subst in substNodes)
                {
                    string substName = subst.Attributes["nazwaSubstancji"]?.Value ?? "Nieznana substancja";
                    Console.WriteLine(" - " + substName);
                }
                Console.WriteLine();
            }
        }

        //zad 1.5
        internal static Dictionary<int, int> GenerateSubstanceCountDictionary(string xmlFilePath)
        {
            XmlDocument doc = new XmlDocument();
            doc.Load(xmlFilePath);
            XmlNamespaceManager nsManager = new XmlNamespaceManager(doc.NameTable);
            nsManager.AddNamespace("ns", "http://rejestrymedyczne.ezdrowie.gov.pl/rpl/eksport-danych-v1.0");

            Dictionary<int, int> substanceCountDictionary = new Dictionary<int, int>();

            XmlNodeList productNodes = doc.SelectNodes("/ns:produktyLecznicze/ns:produktLeczniczy", nsManager);

            foreach (XmlNode product in productNodes)
            {
                XmlNodeList substances = product.SelectNodes("ns:substancjeCzynne/ns:substancjaCzynna", nsManager);
                int substanceCount = substances.Count;

                if (substanceCountDictionary.ContainsKey(substanceCount))
                {
                    substanceCountDictionary[substanceCount]++;
                }
                else
                {
                    substanceCountDictionary[substanceCount] = 1;
                }
            }

            return substanceCountDictionary;
        }

        //wykres outdated? (aka jestem upo i nazwy kategori na wykresie nie byly iloscia substancji tylko jakims losowym inc++ xd)
        internal static PlotModel CreateSubstanceChart(Dictionary<int, int> substanceCountDictionary)
        {
            var model = new PlotModel { 
                Title = "Wykres liczby produktów leczniczych w zależności od liczby substancji czynnych",
                Background = OxyColors.White
            };
            var barSeries = new BarSeries
            {
                ItemsSource = new List<BarItem>(), 
                LabelPlacement = LabelPlacement.Outside,
                LabelFormatString = "{0}"
            };

            List<BarItem> items = new List<BarItem>();

            foreach (var item in substanceCountDictionary)
            {
                items.Add(new BarItem { Value = item.Value });
            }

            barSeries.ItemsSource = items; 
            model.Series.Add(barSeries);

            var categoryAxis = new CategoryAxis { Position = AxisPosition.Left };
            for (int i = 0; i <= 50; i++) 
            {
                categoryAxis.Labels.Add(i.ToString());
            }
            model.Axes.Add(categoryAxis);

            /*model.Axes.Add(new CategoryAxis { Position = AxisPosition.Left });
            model.Axes.Add(new LinearAxis
            {
                Position = AxisPosition.Bottom,
                Minimum = 0, 
                Maximum = 50 
            });*/

            return model;
        }

        internal static PlotModel CreateSubstanceChart2(Dictionary<int, int> substanceCountDictionary)
        {
            var model = new PlotModel
            {
                Title = "Wykres liczby produktów leczniczych w zależności od liczby substancji czynnych",
                Background = OxyColors.White 
            };

            var barSeries = new BarSeries
            {
                ItemsSource = new List<BarItem>(), 
                LabelPlacement = LabelPlacement.Outside,
                LabelFormatString = "{0}",
            };

            // ItemsSource -> Lista
            List<BarItem> items = new List<BarItem>();

            foreach (var item in substanceCountDictionary)
            {
                items.Add(new BarItem { Value = item.Value });
            }

            barSeries.ItemsSource = items; // Lista -> ItemsSource
            model.Series.Add(barSeries);

        
            var categoryAxis = new CategoryAxis { Position = AxisPosition.Left };

            foreach (var key in substanceCountDictionary.Keys)
            {
                categoryAxis.Labels.Add(key.ToString());
            }

            model.Axes.Add(categoryAxis);

            model.Axes.Add(new LinearAxis
            {
                Position = AxisPosition.Bottom,
                Minimum = 0
            });

            return model;
        }


        // does work, tylko trzeba SkiaSharp a nie zwykly elozelo
        // doesnt work xddd (ioexception)

        internal static void SavePlotToFile(PlotModel plotModel)
        {
            var pngExporter = new OxyPlot.SkiaSharp.PngExporter { Width = 2560, Height = 1440};
            using (var stream = File.Create("chart.png"))
            {
                pngExporter.Export(plotModel, stream);
            }
            Console.WriteLine("Wykres zapisano do: chart.png");
        }

        //test
        internal static void FindProduktWithMostActiveSubstances(string xmlFilePath)
        {
            XDocument doc = XDocument.Load(xmlFilePath);

            // Ustalamy przestrzeń nazw (namespace), jeśli jest w pliku XML
            XNamespace ns = "http://rejestrymedyczne.ezdrowie.gov.pl/rpl/eksport-danych-v1.0";

            // Szukamy wszystkich leków i ich substancji czynnych
            var produkty = from p in doc.Descendants(ns + "produktLeczniczy")
                           let substancje = p.Descendants(ns + "substancjeCzynne").Descendants(ns + "substancjaCzynna")
                           select new
                           {
                               NazwaProduktu = p.Attribute("nazwaProduktu")?.Value,
                               RodzajPreparatu = p.Attribute("rodzajPreparatu")?.Value,
                               NazwaPowszechnieStosowana = p.Attribute("nazwaPowszechnieStosowana")?.Value,
                               Moc = p.Attribute("moc")?.Value,
                               NazwaPostaciFarmaceutycznej = p.Attribute("nazwaPostaciFarmaceutycznej")?.Value,
                               SubstancjeCzynne = substancje.Select(s => s.Attribute("nazwaSubstancji")?.Value).ToList()
                           };

            // Znajdź lek z największą liczbą substancji czynnych
            var lekZNajwiecejSubstancji = produkty.OrderByDescending(p => p.SubstancjeCzynne.Count()).FirstOrDefault();

            if (lekZNajwiecejSubstancji != null)
            {
                Console.WriteLine($"Lek o największej liczbie substancji czynnych: {lekZNajwiecejSubstancji.NazwaProduktu}");
                Console.WriteLine($"Liczba substancji czynnych: {lekZNajwiecejSubstancji.SubstancjeCzynne.Count}");
                Console.WriteLine($"Rodzaj Preparatu: {lekZNajwiecejSubstancji.RodzajPreparatu}");
                Console.WriteLine($"Nazwa Powszechnie Stosowana: {lekZNajwiecejSubstancji.NazwaPowszechnieStosowana}");
                Console.WriteLine($"Moc: {lekZNajwiecejSubstancji.Moc}");
                Console.WriteLine($"Nazwa Postaci Farmaceutycznej: {lekZNajwiecejSubstancji.NazwaPostaciFarmaceutycznej}");
            }
            else
            {
                Console.WriteLine("Nie znaleziono żadnego leku.");
            }
        }

    }
}
