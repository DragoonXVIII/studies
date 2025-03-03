using OxyPlot;
using OxyPlot.Wpf;
using System;
using System.Collections.Generic;
using System.IO;


namespace lab1
{
    class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            // zad 1.1
            string xmlpath = Path.Combine("Assets", "data.xml");
            // odczyt danych z wykorzystaniem DOM 
            Console.WriteLine("\n XML loaded by DOM Approach");
            XMLReadWithDOMApproach.Read(xmlpath);
            // zad 1.2
            //XMLReadWithDOMApproach.Read2_short(xmlpath);
            // zad 1.4
            XMLReadWithDOMApproach.Read3_short(xmlpath);    

            //odczyt danych z wykorzystaniem SAX 
            Console.WriteLine("\n XML loaded by SAX Approach");
            XMLReadWithSAXApproach.Read(xmlpath); 
            
            
            // odczyt danych z wykorzystaniem XPath i DOM 
            Console.WriteLine("\n XML loaded with XPath"); 
            XMLReadWithXLSTDOM.Read(xmlpath);

            Console.WriteLine("\n Advanced: ");
            //XMLReadWithXLSTDOM.IdentifyProductsWithActiveSubstances(xmlpath);

            Dictionary<int, int> substanceCountDictionary = XMLReadWithXLSTDOM.GenerateSubstanceCountDictionary(xmlpath);
            // Tworzenie wykresu
            PlotModel plotModel = XMLReadWithXLSTDOM.CreateSubstanceChart2(substanceCountDictionary);
            XMLReadWithXLSTDOM.SavePlotToFile(plotModel);
            XMLReadWithXLSTDOM.FindProduktWithMostActiveSubstances(xmlpath);
            Console.ReadLine();
        }
    }
}

