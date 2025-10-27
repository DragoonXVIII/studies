using Xunit;

namespace Lab2.Test
{
    public class UnitTest1
    {
        [Fact]
        public void Fruit_ProperFormat_ShouldStartWithFruit()
        {
            var fruit = new Fruit { Name = "Apple" };
            var result = fruit.ToString();

            Assert.StartsWith("Fruit", result);
        }

        [Fact]  //wy¿yny angielskiego (thank you from the mountain)
        public void Fruit_ProperFormat_ShouldMatchExpectedFormat()
        {
            var fruit = new Fruit
            {
                Name = "Apple",
                IsSweet = true,
                Price = 5.50
            };
            UsdCourse.Current = 2.0f;

            var expected = $"Fruit: Name=Apple, S³odki=Tak, Cena={fruit.Price.ToString("C2")}, Cena w USD={(fruit.UsdPrice).ToString("C2", System.Globalization.CultureInfo.GetCultureInfo("en-US"))}";
            var result = fruit.ToString();

            Assert.Equal(expected, result);
        }

        [Fact]
        public void FruitCreate_ShouldGenerateMoreThanOneUniqueName()
        {
            var names = new HashSet<string>();
            for (int i = 0; i < 20; i++)
            {
                var fruit = Fruit.Create();
                names.Add(fruit.Name);
            }
            Assert.True(names.Count > 1);
        }
    }

}