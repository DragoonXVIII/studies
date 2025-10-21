using System;
using System.Net.Http;
using System.Threading.Tasks;
using System.Xml.Linq;
using System.Linq;

namespace Lab2
{
    public class UsdCourse
    {
        public static float Current = 0;

        public async static Task<float> GetUsdCourseAsync()
        {
            using var wc = new HttpClient();
            var response = await wc.GetAsync("https://api.nbp.pl/api/exchangerates/tables/a/?format=xml");
            if (!response.IsSuccessStatusCode)
                throw new InvalidOperationException();

            var xml = await response.Content.ReadAsStringAsync();
            XDocument doc = XDocument.Parse(xml);

            var midUsdValue = doc.Descendants("Rate")
                .Where(rate => (string)rate.Element("Code") == "USD")
                .Select(rate => (string)rate.Element("Mid"))
                .FirstOrDefault();

            if (midUsdValue == null)
                throw new InvalidOperationException();

            return Convert.ToSingle(midUsdValue, System.Globalization.CultureInfo.InvariantCulture);
        }
    }
}
