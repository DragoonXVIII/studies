#include "lsm.h"

//skończyć inne funkcje 1/4 i dodac po 100 punktów zeby wykresy byly w miare dokladne no i ten matme doliczyc

LSM::LSM(QObject *parent)
    : QObject{parent}
{

}

LSM::~LSM()
{
    //delete points;
}


void LSM::getData(QString data, int formulaChoice, QString helpvarS)
{
    this->helpvar = helpvarS.toDouble();
    qDebug()<<"helpvarS: "<<helpvarS;
    qDebug()<<"helpvar: "<<helpvar;
    if(data.endsWith(';'))
    {
        data.chop(1);
    }

    points = {};

    QStringList dataList = data.split('\n');
    foreach(QString dataElement, dataList)
    {
        //qDebug()<< dataElement;
        QStringList dataCoordinates = dataElement.split(';');
        if(dataCoordinates.size() == 2)
        {
            bool xOk, yOk;
            double x = dataCoordinates[0].toDouble(&xOk);
            double y = dataCoordinates[1].toDouble(&yOk);
            if (xOk && yOk)
            {
                points.append(QPointF(x, y));
            }
            else
            {
                qWarning() << "Nie można przekonwertować współrzędnych:" << dataElement;
            }
        }
        else
        {
            qWarning() << "Nieprawidłowy format współrzędnych:" << dataElement;
        }
    }

    // Wyświetl listę punktów
    /*qDebug() << "\nLista punktów:" << points;
    for(int i =0;i<this->points.count();i++)
    {
        qDebug()<< i+1<< "."<< this->points.at(i);
    }*/

    switch(formulaChoice)
    {
    case 0:
        fLinear();
        break;

    case 1:
        fPower();
        break;

    case 2:
        fExponential();
        break;

    case 3:
        fFractional();
        break;
    }
    this->formulaChoice = formulaChoice;
}

QString LSM::fLinear()
{
    //rownanie;
    /*
    { n*a0 + xS*a1 = yS
    { xS*a0 + xkS*a1= xyIS
    *  n - liczba punktow;
      xS - suma x-ow;
      yS - suma y-ow;
    xyIS - suma iloczynow x-ow oraz odpowiadajacych im y-ow;
     xkS - suma kwadratow x-ow;
    */
    int n = points.count();
    double xS=0, yS=0, xyIS=0, xkS=0;
    for(int i=0;i<n;i++)
    {
        xS+=points.at(i).x();
        yS+=points.at(i).y();
        xyIS+=(points.at(i).x()*points.at(i).y());
        xkS+=points.at(i).x()*points.at(i).x();
    }
    //POMOCNICZY OUTPUT
    //cout<< xS <<endl;
    //cout<< yS <<endl;
    //cout<< xyIS <<endl;
    //cout<< xkS <<endl;

    //wyznaczniki;
    double W,Wa0,Wa1;
    W = (n*xkS) - (xS*xS);
    Wa0 = (yS*xkS) - (xyIS*xS);
    Wa1 = (n*xyIS) - (xS*yS);

    double a0 = Wa0/W;
    double a1 = Wa1/W;

    //creating formula
    this->formula = QString("%1 * x + %2").arg(QString::number(a1),QString::number(a0));
    qDebug()<< "formula: " <<this->formula;

    //trying to create 100 points that will create function chart, points should be between minX and maxX
    //sortowanie rosnace
    std::sort(points.begin(), points.end(), [](const QPointF& p1, const QPointF& p2) {
        return p1.x() < p2.x();
    });

    double minX = points.begin()->x();
    double maxX = std::prev(points.end())->x();
    double step = (maxX - minX) / 99.0; // Wylicz krok między punktami

    QVariantList pointDataList;
    double minXR; //for range purpouse to enable nice scaling chart with function always centered
    double maxXR;
    double minYR;
    double maxYR;

    for(int i=0;i<100;i++)
    {
        double x = minX + step*i;
        double y = a1*x+a0; //funcja rozna w roznych funkcjach
        QPointF point = QPointF(x,y);
        pointDataList.append(QVariant::fromValue(point));
        qDebug()<<"xd: " <<point;
        if(i == 0)
        {
            minXR = x;
            minYR = y;
            maxYR = y;
        }
        if(i == 99)
        {
            maxXR = x;
        }
        if(y<minYR)
        {
            minYR = y;
        }
        if(y>maxYR)
        {
            maxYR = y;
        }
    }
    qDebug()<< "minX: "<< minXR<< "maxX"<< maxXR <<"\n";
    qDebug()<< "minY: "<< minYR<< "maxY"<< maxYR <<"\n";

    double rangeX = abs(maxXR - minXR);
    double rangeY = abs(maxYR - minYR);
    minXR -= rangeX/10;
    maxXR += rangeX/10;
    minYR -= rangeY/10;
    maxYR += rangeY/10;

    //emitowac ma z innymi punktami jak cos (100 punktow ma byc na wykresie)
    emit setChart(pointDataList,this->formula,minXR,maxXR,minYR,maxYR);
    return this->formula;
}

QString LSM::fPower()
{
    //rownanie;
    /*
    { n*a0 + xS*a1 = yS
    { xS*a0 + xkS*a1= xyIS
    *  n - liczba punktow;
      xS - suma x-ow;
      yS - suma y-ow;
    xyIS - suma iloczynow x-ow oraz odpowiadajacych im y-ow;
     xkS - suma kwadratow x-ow;
    */
    /*
    double power = 1.0 / 2.0;  // Assuming you want square root, adjust as needed
    int n = points.count();

    for (QPointF& point : points)
    {
        point.setX(pow(point.x(), power));
    }

    double xS = 0, yS = 0, xyIS = 0, xkS = 0;

    for (const QPointF& point : points)
    {
        xS += point.x();
        yS += point.y();
        xyIS += (point.x() * point.y());
        xkS += (point.x() * point.x());
    }

    double W = (n * xkS) - (xS * xS);
    double Wa0 = (yS * xkS) - (xyIS * xS);
    double Wa1 = (n * xyIS) - (xS * yS);

    double a0 = Wa0 / W;
    double a1 = Wa1 / W;

    this->formula = QString("%1 * x^(%3) + %2").arg(QString::number(a1), QString::number(a0), QString::number(power));
    qDebug() << "formula: " << this->formula;
    */
    int n = points.count();
    for(int i=0;i<n;i++)
    {
        points.replace(i, QPointF(pow(points.at(i).x(), helpvar),points.at(i).y()));
    }

    double xS=0, yS=0, xyIS=0, xkS=0;
    for(int i=0;i<n;i++)
    {
        xS+=points.at(i).x();
        yS+=points.at(i).y();
        xyIS+=(points.at(i).x()*points.at(i).y());
        xkS+=points.at(i).x()*points.at(i).x();
    }
    //POMOCNICZY OUTPUT
    //cout<< xS <<endl;
    //cout<< yS <<endl;
    //cout<< xyIS <<endl;
    //cout<< xkS <<endl;

    //wyznaczniki;
    double W,Wa0,Wa1;
    W = (n*xkS) - (xS*xS);
    Wa0 = (yS*xkS) - (xyIS*xS);
    Wa1 = (n*xyIS) - (xS*yS);

    double a0 = Wa0/W;
    double a1 = Wa1/W;

    //creating formula
    this->formula = QString("%1 * x^(%2) + %3").arg(QString::number(a1),QString::number(helpvar), QString::number(a0));
    qDebug()<< "formula: " <<this->formula;


    //trying to create 100 points that will create function chart, points should be between minX and maxX
    //sortowanie rosnace
    std::sort(points.begin(), points.end(), [](const QPointF& p1, const QPointF& p2) {
        return p1.x() < p2.x();
    });

    double minX = points.begin()->x();
    double maxX = std::prev(points.end())->x();
    double step = (maxX - minX) / 99.0; // Wylicz krok między punktami

    QVariantList pointDataList;
    double minXR; //for range purpouse to enable nice scaling chart with function always centered
    double maxXR;
    double minYR;
    double maxYR;

    for(int i=0;i<100;i++)
    {
        double x = minX + step*i;
        double y = a1*pow(x, helpvar)+a0; //funcja rozna w roznych funkcjach
        QPointF point = QPointF(x,y);
        pointDataList.append(QVariant::fromValue(point));
        qDebug()<<"xd: " <<point;
        if(i == 0)
        {
            minXR = x;
            minYR = y;
            maxYR = y;
        }
        if(i == 99)
        {
            maxXR = x;
        }
        if(y<minYR)
        {
            minYR = y;
        }
        if(y>maxYR)
        {
            maxYR = y;
        }
    }
    qDebug()<< "minX: "<< minXR<< "maxX"<< maxXR <<"\n";
    qDebug()<< "minY: "<< minYR<< "maxY"<< maxYR <<"\n";

    double rangeX = abs(maxXR - minXR);
    double rangeY = abs(maxYR - minYR);
    minXR -= rangeX/10;
    maxXR += rangeX/10;
    minYR -= rangeY/10;
    maxYR += rangeY/10;

    //emitowac ma z innymi punktami jak cos (100 punktow ma byc na wykresie)
    emit setChart(pointDataList,this->formula,minXR,maxXR,minYR,maxYR);
    return this->formula;
}

QString LSM::fExponential() //not working rn
{
    //rownanie;
    /*
    { n*a0 + xS*a1 = yS
    { xS*a0 + xkS*a1= xyIS
    *  n - liczba punktow;
      xS - suma x-ow;
      yS - suma y-ow;
    xyIS - suma iloczynow x-ow oraz odpowiadajacych im y-ow;
     xkS - suma kwadratow x-ow;
    */
    int n = points.count();
    for(int i=0;i<n;i++)
    {
        points.replace(i, QPointF(points.at(i).x(),log(points.at(i).y())));
    }

    double xS=0, yS=0, xyIS=0, xkS=0;
    for(int i=0;i<n;i++)
    {
        xS+=points.at(i).x();
        yS+=points.at(i).y();
        xyIS+=(points.at(i).x()*points.at(i).y());
        xkS+=points.at(i).x()*points.at(i).x();
    }
    //POMOCNICZY OUTPUT
    //cout<< xS <<endl;
    //cout<< yS <<endl;
    //cout<< xyIS <<endl;
    //cout<< xkS <<endl;

    //wyznaczniki;
    double W,Wa0,Wa1;
    W = (n*xkS) - (xS*xS);
    Wa0 = (yS*xkS) - (xyIS*xS);
    Wa1 = (n*xyIS) - (xS*yS);

    double a0 = Wa0/W;
    double a1 = Wa1/W;

    //creating formula
    this->formula = QString("%1 * %2^x + %2").arg(QString::number(a0), QString::number(a1));
    qDebug()<< "formula: " <<this->formula;


    //trying to create 100 points that will create function chart, points should be between minX and maxX
    //sortowanie rosnace
    std::sort(points.begin(), points.end(), [](const QPointF& p1, const QPointF& p2) {
        return p1.x() < p2.x();
    });

    double minX = points.begin()->x();
    double maxX = std::prev(points.end())->x();
    double step = (maxX - minX) / 99.0; // Wylicz krok między punktami

    QVariantList pointDataList;
    double minXR; //for range purpouse to enable nice scaling chart with function always centered
    double maxXR;
    double minYR;
    double maxYR;

    for(int i=0;i<100;i++)
    {
        double x = minX + step*i;
        double y = log(a0*pow(a1,x)); //funcja rozna w roznych funkcjach
        QPointF point = QPointF(x,y);
        pointDataList.append(QVariant::fromValue(point));
        qDebug()<<"xd: " <<point;
        if(i == 0)
        {
            minXR = x;
            minYR = y;
            maxYR = y;
        }
        if(i == 99)
        {
            maxXR = x;
        }
        if(y<minYR)
        {
            minYR = y;
        }
        if(y>maxYR)
        {
            maxYR = y;
        }
    }
    qDebug()<< "minX: "<< minXR<< "maxX"<< maxXR <<"\n";
    qDebug()<< "minY: "<< minYR<< "maxY"<< maxYR <<"\n";

    double rangeX = abs(maxXR - minXR);
    double rangeY = abs(maxYR - minYR);
    minXR -= rangeX/10;
    maxXR += rangeX/10;
    minYR -= rangeY/10;
    maxYR += rangeY/10;

    //emitowac ma z innymi punktami jak cos (100 punktow ma byc na wykresie)
    emit setChart(pointDataList,this->formula,minXR,maxXR,minYR,maxYR);
    return this->formula;
    return this->formula;
}

QString LSM::fFractional()
{
    int n = points.count();
    for(int i=0;i<n;i++)
    {
        points.replace(i, QPointF(helpvar/points.at(i).x(),points.at(i).y()));
    }

    double xS=0, yS=0, xyIS=0, xkS=0;
    for(int i=0;i<n;i++)
    {
        xS+=points.at(i).x();
        yS+=points.at(i).y();
        xyIS+=(points.at(i).x()*points.at(i).y());
        xkS+=points.at(i).x()*points.at(i).x();
    }
    //POMOCNICZY OUTPUT
    //cout<< xS <<endl;
    //cout<< yS <<endl;
    //cout<< xyIS <<endl;
    //cout<< xkS <<endl;

    //wyznaczniki;
    double W,Wa0,Wa1;
    W = (n*xkS) - (xS*xS);
    Wa0 = (yS*xkS) - (xyIS*xS);
    Wa1 = (n*xyIS) - (xS*yS);

    double a0 = Wa0/W;
    double a1 = Wa1/W;

    //creating formula
    this->formula = QString("%1 * (%2)/x + %3").arg(QString::number(a1),QString::number(helpvar), QString::number(a0));
    qDebug()<< "formula: " <<this->formula;


    //trying to create 100 points that will create function chart, points should be between minX and maxX
    //sortowanie rosnace
    std::sort(points.begin(), points.end(), [](const QPointF& p1, const QPointF& p2) {
        return p1.x() < p2.x();
    });

    double minX = points.begin()->x();
    double maxX = std::prev(points.end())->x();
    double step = (maxX - minX) / 99.0; // Wylicz krok między punktami

    QVariantList pointDataList;
    double minXR; //for range purpouse to enable nice scaling chart with function always centered
    double maxXR;
    double minYR;
    double maxYR;

    for(int i=0;i<100;i++)
    {
        double x = minX + step*i;
        double y = a1*helpvar/x+ a0; //funcja rozna w roznych funkcjach
        QPointF point = QPointF(x,y);
        pointDataList.append(QVariant::fromValue(point));
        qDebug()<<"xd: " <<point;
        if(i == 0)
        {
            minXR = x;
            minYR = y;
            maxYR = y;
        }
        if(i == 99)
        {
            maxXR = x;
        }
        if(y<minYR)
        {
            minYR = y;
        }
        if(y>maxYR)
        {
            maxYR = y;
        }
    }
    qDebug()<< "minX: "<< minXR<< "maxX"<< maxXR <<"\n";
    qDebug()<< "minY: "<< minYR<< "maxY"<< maxYR <<"\n";

    double rangeX = abs(maxXR - minXR);
    double rangeY = abs(maxYR - minYR);
    minXR -= rangeX/10;
    maxXR += rangeX/10;
    minYR -= rangeY/10;
    maxYR += rangeY/10;

    //emitowac ma z innymi punktami jak cos (100 punktow ma byc na wykresie)
    emit setChart(pointDataList,this->formula,minXR,maxXR,minYR,maxYR);
    return this->formula;
    return this-> formula;
}

void LSM::setFormula(int formulaChoice) //deprecieated
{

}

/*
//wczytywanie;
int n;
cout<< "Podaj ilosc wezlow: ";
cout<< "* pamietaj aby w przypadku wybrania opcji 4 podawac stopnie poteg liczby Eulera!\n";
cin>> n;

double points[n][2]; //([x][y])*n;

for(int i=0; i<n; i++)
{
    cout<< "Podaj x["<< i<< "]";
    cin>> points[i][0];
    cout<< "Podaj y["<< i<< "]";
    cin>> points[i][1];
}


//przygotowanie danych - wybor rownania;
int wybor, pomocnicza;
cout<< "Dostepne rownania: \n";
cout<< "1. a*x + b;\n"; //wym         //DONE
cout<< "2. a*sqrt(x) + b;\n";         //DONE
cout<< "3. a*x^n + b\n";              //DONE
cout<< "4. b * a^x;\n"; //wym         //
cout<< "5. a * n/x + b;\n"; //wym     //DONE
cout<< "Wybierz rownianie: ";
cin>>wybor;

switch(wybor)
{
case 1:
    //nie trzeba nic przeksztalcac;
    break;

case 2:
    //pierwiastek przy x oznacza pierwiastkowanie samego x;
    cout<<"Podaj stopien pierwiastka: ";
    cin>>pomocnicza;
    for(int i=0;i<n;i++)
    {
        points[i][0] = pow(points[i][0], 1.0/pomocnicza);
    }
    break;

case 3:
    //potega przy x oznacza potegowanie x;
    cout<<"Podaj wykladnik: ";
    cin>>pomocnicza;
    for(int i=0;i<n;i++)
    {
        points[i][0] = pow(points[i][0],pomocnicza);
    }
    break;

case 4:
    //nietrzeba nic robic bo mamy podane punkty wiec git;
    break;

case 5:
    cout<<"Podaj licznik: ";
    cin>>pomocnicza;
    for(int i=0;i<n;i++)
    {
        points[i][0] = pomocnicza/points[i][0];
    }
    break;

default:
    cout<<"Nieprawidlowy wybor!";
    return 0;
}


//rownanie;

     *  { n*a0 + xS*a1 = yS
     *  { xS*a0 + xkS*a1= xyIS
     *  n - liczba punktow;
     *  xS - suma x-ow;
     *  yS - suma y-ow;
     *  xyIS - suma iloczynow x-ow oraz odpowiadajacych im y-ow;
     *  xkS - suma kwadratow x-ow;
     */

/*
double xS=0, yS=0, xyIS=0, xkS=0;
for(int i=0;i<n;i++)
{
    xS+=points[i][0];
    yS+=points[i][1];
    xyIS+=(points[i][0]*points[i][1]);
    xkS+=points[i][0]*points[i][0];
}
//POMOCNICZY OUTPUT
//cout<< xS <<endl;
//cout<< yS <<endl;
//cout<< xyIS <<endl;
//cout<< xkS <<endl;


//wyznaczniki;
double W,Wa0,Wa1;
W = (n*xkS) - (xS*xS);
Wa0 = (yS*xkS) - (xyIS*xS);
Wa1 = (n*xyIS) - (xS*yS);

double a0 = Wa0/W;
double a1 = Wa1/W;


//wynik;
string wzor;
switch(wybor)
{
case 1:
    wzor = "x";
    break;

case 2:
    wzor = "sqrt(x)";
    break;

case 3:
    wzor = &"x^"[pomocnicza];
    break;

case 4:
    wzor = "x^";
    break;

case 5:
    wzor = pomocnicza;
    wzor.append("/x");
    break;
}

cout<< endl;
cout<< "Wzor funkcji: ";
cout<< a1 <<wzor <<"+ " <<a0;
*/
