#ifndef COUNTRYTABLE_H
#define COUNTRYTABLE_H

#include <QMap>
#include <QList>
#include <QString>
#include <QDebug>
#include <QMessageBox>

#include <algorithm>

class CountryTable
{
private:
    QMap <QString, int> countries;

public:
    CountryTable();
    ~CountryTable();
    bool addCountry(QString name, int population);
    bool deleteCountry(QString name);
    QVector<QPair<QString, int>> sortPopulationAscending();
    QVector<QPair<QString, int>> sortPopulationDescending();
    QMap <QString, int> reload(int mode);
    QMap <QString, int> reload(int range1, int range2);


};

#endif // COUNTRYTABLE_H
