#include "dictionary.h"

void Dictionary::addWord(const std::string& word, const std::string& translation) {
    if (words.find(word) == words.end()) {
        words[word] = translation;
        std::cout << "Dodano: " << word << " -> " << translation << std::endl;
    } else {
        std::cout << "Słowo " << word << " już istnieje w słowniku." << std::endl;
    }
}

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

void Dictionary::translate(const std::string& word)
{
    auto it = words.find(word);
    if (it != words.end()) {
        std::cout << "Tłumaczenie słowa '" << word << "': " << it->second << std::endl;
    } else {
        std::cout << "Brak tłumaczenia dla słowa: " << word << std::endl;
    }
}

void Dictionary::displaySortedByTranslation() const {
    if (words.empty()) {
        std::cout << "Słownik jest pusty." << std::endl;
        return;
    }

    std::vector<std::pair<std::string, std::string>> sortedWords(words.begin(), words.end());

    std::sort(sortedWords.begin(), sortedWords.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;  // Zmiana kolenosi na malej
    });

    std::cout << "Słownik posortowany alfabetycznie względem tłumaczenia (od Z do A):" << std::endl;
    for (const auto& entry : sortedWords) {
        std::cout << entry.first << " -> " << entry.second << std::endl;
    }
}
