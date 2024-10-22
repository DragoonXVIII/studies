#ifndef COUNTRYTABLE_H
#define COUNTRYTABLE_H

#include <QMap>
#include <QList>
#include <QString>
#include <QDebug>

#include <algorithm>

class CountryTable
{
private:
    QMap <QString, int> countries;

public:
    CountryTable();
    ~CountryTable();
    bool addCountry();
    bool deleteCountry();
    void searchCountries(int range1, int range2);
    void sortPopulationAscending();
    void sortPopulationDescending();
    void reloadTable();
};

#endif // COUNTRYTABLE_H
