using System;
using System.Collections.Generic;
using System.Linq;

namespace api
{
    public class Censor
    {
        /// <summary>
        /// Lista słów, które mają zostać ocenzurowane w tekście
        /// </summary>
        public List<string> Blacklist { get; set; } = new List<string>();

        /// <summary>
        /// Funkcja cenzurująca pojedyncze słowo.
        /// </summary>
        /// <param name="word">Słowo nieocenzurowane</param>
        /// <returns>Słowo ocenzurowane</returns>
        public string CensorWord(string word)
        {
            if (string.IsNullOrWhiteSpace(word)) return word;

            bool isBlacklisted = Blacklist.Any(b => string.Equals(b, word, StringComparison.OrdinalIgnoreCase));

            if (isBlacklisted && word.Length > 0)
            {
                return word[0] + new string('*', word.Length - 1);
            }

            return word;
        }

        /// <summary>
        /// Funkcja cenzurująca cały tekst, który może się składać z wielu słów.
        /// </summary>
        /// <param name="text">Tekst nieocenzurowany</param>
        /// <returns>Tekst ocenzurowany</returns>
        public string CensorText(string text)
        {
            if (string.IsNullOrWhiteSpace(text)) return text;
            var words = text.Split(' ', StringSplitOptions.RemoveEmptyEntries);
            var censoredWords = words.Select(word => CensorWord(word));
            return string.Join(' ', censoredWords);
        }
    }
}
