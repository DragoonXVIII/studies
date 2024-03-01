#include <iostream>
#include <math.h>



using namespace std;



int main()
{
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
    /*
     *  { n*a0 + xS*a1 = yS
     *  { xS*a0 + xkS*a1= xyIS
     *  n - liczba punktow;
     *  xS - suma x-ow;
     *  yS - suma y-ow;
     *  xyIS - suma iloczynow x-ow oraz odpowiadajacych im y-ow;
     *  xkS - suma kwadratow x-ow;
     */

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

    return 0;
}

//najpierw switch z wyborem wzoru potem popros o dane i dopiero na koncu jak beda obliczene a1 a2 to sklejaj bo w zaleznosci od wzoru roznie sie skleja;
