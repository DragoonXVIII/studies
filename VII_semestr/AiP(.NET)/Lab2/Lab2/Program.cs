using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Lab2
{
    class Program
    {
        static async Task Main()
        {
            UsdCourse.Current = await UsdCourse.GetUsdCourseAsync();

            //Zad 2.1
            List<Fruit> fruits = new List<Fruit>();
            for (int i = 0; i < 15; i++)
                fruits.Add(Fruit.Create());

            Console.WriteLine("Zad2.2");
            foreach (var fruit in fruits)
                Console.WriteLine(fruit);

            Console.WriteLine("\nZad2.3");
            Console.WriteLine("\nZad2.6");
            var sweetFruits = fruits
                .Where(f => f.IsSweet)
                .OrderByDescending(f => f.Price);

            foreach (var fruit in sweetFruits)
                Console.WriteLine(fruit);
        }
    }
}
