#include "dictionary.h"
// Metoda dodająca słowo i tłumaczenie do słownika

void Dictionary::addWord(const std::string& word, const std::string& translation) {
    // Sprawdzamy, czy słowo już istnieje w słowniku
    if (words.find(word) == words.end()) {
        words[word] = translation;
        std::cout << "Dodano: " << word << " -> " << translation << std::endl;
    } else {
        std::cout << "Słowo " << word << " już istnieje w słowniku." << std::endl;
    }
}

// Metoda usuwająca słowo ze słownika
void Dictionary::removeWord(const std::string& word)
{
    auto it = words.find(word);
    if (it != words.end()) {
        words.erase(it);
        std::cout << "Usunięto słowo: " << word << std::endl;
    } else {
        std::cout << "Słowo " << word << " nie istnieje w słowniku." << std::endl;
    }
}

// Metoda wyświetlająca zawartość słownika
void Dictionary::displayDictionary() const
{
    if (words.empty()) {
        std::cout << "Słownik jest pusty." << std::endl;
        return;
    }
    std::cout << "Zawartość słownika:" << std::endl;
    for (const auto& entry : words) {
        std::cout << entry.first << " -> " << entry.second << std::endl;
    }
}

// Metoda wyświetlająca tłumaczenie dla podanego słowa
void Dictionary::translate(const std::string& word)
{
    auto it = words.find(word);
    if (it != words.end()) {
        std::cout << "Tłumaczenie słowa '" << word << "': " << it->second << std::endl;
    } else {
        std::cout << "Brak tłumaczenia dla słowa: " << word << std::endl;
    }
}

// Metoda wyświetlająca zawartość słownika alfabetycznie od Z do A względem tłumaczenia
void Dictionary::displaySortedByTranslation() const {
    if (words.empty()) {
        std::cout << "Słownik jest pusty." << std::endl;
        return;
    }

    // Tworzymy wektor przechowujący pary słowo-tłumaczenie
    std::vector<std::pair<std::string, std::string>> sortedWords(words.begin(), words.end());

    // Sortujemy wektor alfabetycznie względem tłumaczenia (od Z do A)
    std::sort(sortedWords.begin(), sortedWords.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;  // Zmiana kolejności na malejąco
    });

    // Wyświetlamy posortowane elementy
    std::cout << "Słownik posortowany alfabetycznie względem tłumaczenia (od Z do A):" << std::endl;
    for (const auto& entry : sortedWords) {
        std::cout << entry.first << " -> " << entry.second << std::endl;
    }
}
