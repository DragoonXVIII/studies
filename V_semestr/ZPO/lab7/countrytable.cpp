#include "countrytable.h"




CountryTable::CountryTable() {};

CountryTable::~CountryTable() {};

void CountryTable::sortPopulationAscending() {
    // Tworzymy listę par (kraj, populacja) z mapy
    QList<QPair<QString, int>> countryList = countries.toList();

    // Sortujemy listę według wartości (populacja) rosnąco
    std::sort(countryList.begin(), countryList.end(),
              [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
                  return a.second < b.second;
              });

    // Wyświetlamy posortowaną listę (opcjonalnie)
    for (const auto& country : countryList) {
        qDebug() << country.first << ": " << country.second;
    }
}

void CountryTable::sortPopulationDescending() {
    // Tworzymy listę par (kraj, populacja) z mapy
    QList<QPair<QString, int>> countryList = countries.toList();

    // Sortujemy listę według wartości (populacja) malejąco
    std::sort(countryList.begin(), countryList.end(),
              [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
                  return a.second > b.second;
              });

    // Wyświetlamy posortowaną listę (opcjonalnie)
    for (const auto& country : countryList) {
        qDebug() << country.first << ": " << country.second;
    }
}

void searchCountries(int range1, int range2) {
    // Sprawdzamy, który zakres jest dolny, a który górny, by uniknąć problemów
    int lowerBound = qMin(range1, range2);
    int upperBound = qMax(range1, range2);

    // Iterujemy przez mapę krajów
    for (auto it = countries.begin(); it != countries.end(); ++it) {
        int population = it.value();

        // Sprawdzamy, czy populacja kraju mieści się w zakresie
        if (population >= lowerBound && population <= upperBound) {
            qDebug() << it.key() << ": " << population;
        }
    }
}
