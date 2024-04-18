#ifndef LSM_H
#define LSM_H


#include <QObject>
#include <QVariantList>
#include <QtCharts>
#include <QDebug>


#include <math.h>



class LSM : public QObject
{
    Q_OBJECT

public:

    explicit LSM(QObject *parent = nullptr);
    ~LSM();

protected:

    QList<QPointF> points;     //List that stores points values
    //QVariantList pointDataList;
    int formulaChoice;          //Integer that store formula choice - which formula should be used to calculate least square method
    QString formula;            //QString that store formula data
    double helpvar;             //Integer that store additional value used in power exponential and fractional function like power level or like that
    QString helpvarS;

    QString fLinear();          //method that calculate LSM with linear function from loaded points
    QString fPower();           //method that calculate LSM with power function from loaded points
    QString fExponential();     //method that calculate LSM with exponential function from loaded points
    QString fFractional();      //method that calculate LSM with fractional function from loaded points x

protected:

    void setFormula(int formulaChoice);             //method that complete function formula that is displayed

signals:

    void setChart(const QVariantList& data, QString formula, double minXR, double maxXR, double minYR, double maxYR);           //signal that sets Char

public slots:

    void getData(QString data, int formulaChoice, QString helpvarS);  //slot that is loading data from user

};

#endif // LSM_H
