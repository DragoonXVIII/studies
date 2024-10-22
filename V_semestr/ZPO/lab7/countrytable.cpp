#include "countrytable.h"




CountryTable::CountryTable() {};

CountryTable::~CountryTable() {};

QVector<QPair<QString, int>> CountryTable::sortPopulationAscending()
{
    QVector<QPair<QString, int>> sortedCountries;
    // z qmap do qvector
    for (auto it = countries.begin(); it != countries.end(); ++it)
    {
        sortedCountries.append(qMakePair(it.key(), it.value()));
    }

    std::sort(sortedCountries.begin(), sortedCountries.end(),
              [](const QPair<QString, int> &a, const QPair<QString, int> &b)
    {
        return a.second < b.second;
    });

    return sortedCountries;
}

QVector<QPair<QString, int>> CountryTable::sortPopulationDescending()
{
    QVector<QPair<QString, int>> sortedCountries;
    // z qmap do qvector
    for (auto it = countries.begin(); it != countries.end(); ++it)
    {
        sortedCountries.append(qMakePair(it.key(), it.value()));
    }

    std::sort(sortedCountries.begin(), sortedCountries.end(),
              [](const QPair<QString, int> &a, const QPair<QString, int> &b)
    {
        return a.second > b.second;
    });

    return sortedCountries;
}

bool CountryTable::addCountry(QString name, int population)
{
    if (countries.contains(name))
    {
        return false;
    }

    countries.insert(name, population);
    return true;
}

bool CountryTable::deleteCountry(QString name)
{
    if (!countries.contains(name))
    {
        return false;
    }
    countries.remove(name);
    return true;
}

QMap <QString, int> CountryTable::reload(int mode)
{
    switch(mode)
    {
    case 0:         //just for adding or deleting;
        return this->countries;

    case 1:         //for sortingAscending
        sortPopulationAscending();
        return this->countries;

    case 2:         //for sortingDescending
        sortPopulationDescending();
        return this->countries;
    }
    return this->countries;
}

QMap <QString, int> CountryTable::reload(int range1, int range2)
{
    QMap<QString, int> countries2 = this->countries;
    int lowerBound = qMin(range1, range2);
    int upperBound = qMax(range1, range2);

    for (auto it = countries2.begin(); it != countries2.end(); )
    {
        int population = it.value();
        if (population < lowerBound || population > upperBound)
        {
            it = countries2.erase(it);
        }
        else
        {
            ++it;
        }
    }

    return countries2;  // zwraca przefiltrowaną mapę
}
