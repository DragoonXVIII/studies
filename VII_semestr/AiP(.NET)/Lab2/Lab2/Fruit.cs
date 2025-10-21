using System;
using System.Globalization;

namespace Lab2
{
    public class Fruit
    {
        public string Name { get; set; }
        public bool IsSweet { get; set; }
        public double Price { get; set; }

        public static Fruit Create()
        {
            Random r = new Random();
            string[] names = new string[] { "Apple", "Banana", "Cherry", "Durian", "Edelberry", "Grape", "Jackfruit" };
            return new Fruit
            {
                Name = names[r.Next(names.Length)],
                IsSweet = r.NextDouble() > 0.5,
                Price = r.NextDouble() * 10
            };
        }

        //Zad 2.
        public double UsdPrice => UsdCourse.Current == 0 ? 0 : Price / UsdCourse.Current;

        public override string ToString()
        {
            string pln = Price.ToString("C2");
            string usd = UsdPrice.ToString("C2", CultureInfo.GetCultureInfo("en-US"));
            return $"Fruit: Name={Name}, Słodki={(IsSweet ? "Tak" : "Nie")}, Cena={pln}, Cena w USD={usd}";
        }
    }
}
