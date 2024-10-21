#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class Dictionary
{
private:
    std::map<std::string, std::string> words;

public:
    // Konstruktor bezargumentowy
    Dictionary(){};

    // Metoda dodająca słowo i tłumaczenie do słownika
    void addWord(const std::string& word, const std::string& translation);
    // Metoda usuwająca słowo ze słownika
    void removeWord(const std::string& word);
    // Metoda wyświetlająca zawartość słownika
    void displayDictionary() const;
    // Metoda wyświetlająca tłumaczenie dla podanego słowa
    void translate(const std::string& word);
    // Metoda wyświetlająca zawartość słownika alfabetycznie od Z do A względem tłumaczenia
    void displaySortedByTranslation() const;
};

