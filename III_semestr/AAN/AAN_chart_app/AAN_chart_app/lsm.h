#ifndef LSM_H
#define LSM_H


#include <QObject>
#include <QDebug>


#include <math.h>



class LSM : public QObject
{
    Q_OBJECT
public:
    explicit LSM(QObject *parent = nullptr);

protected:
    double *points;
    QString formula;

    QString fLinear();
    QString fPower();
    QString fExponential();
    QString fFractional();

signals:
    void setChart(); //jako abstract obowiązkowy do zaimplementowania w kazdej klasie potomnej

public slots:
    void getData(QString data, int formulaChoice); // jako funkcja domyślna w kazdym obiekcie matki, automatycznie procesujaca dane;



};

#endif // LSM_H
