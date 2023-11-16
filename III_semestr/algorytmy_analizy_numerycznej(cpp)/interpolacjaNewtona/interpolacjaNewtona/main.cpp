#include <iostream>
#include <vector>



using namespace std;



//obliczanie ilorazów różnicowych
double iloraz_roznicowy(vector<double>& x, vector<double>& y, int i, int j)
{
    if (i == j)
    {
        return y[i];
    }
    return (iloraz_roznicowy(x, y, i + 1, j) - iloraz_roznicowy(x, y, i, j - 1)) / (x[j] - x[i]);
}


//konstrukcjaa pełnego wzoru
string interpolacja_newtona(vector<double>& x, vector<double>& y)
{
    int n = x.size();
    string result = "";

    for (int i = 0; i < n; i++)
    {
        result += to_string(iloraz_roznicowy(x, y, 0, i));
        for (int j = 0; j < i; j++)
        {
            result += " * (x - " + to_string(x[j]) + ")";
        }
        if (i < n - 1)
        {
            result += " + ";
        }
    }

    return result;
}


double newton_interpolation(vector<double>& x, vector<double>& y, double point)
{
    double result = 0.0;
    int n = x.size();
    for(int i = 0; i < n; i++)
    {
        cout << "f[";
        for (int j = 0; j <= i; j++)
        {
            cout << x[j];
            if (j < i)
            {
                cout << ", ";
            }
        }
        cout << "] = " << iloraz_roznicowy(x, y, 0, i) << endl;

        double term = iloraz_roznicowy(x, y, 0, i);
        for (int j = 0; j < i; j++)
        {
            term *= (point - x[j]);
        }
        result += term;
    }
    cout<< "Wynik w zadanym punkcie: ";
    return result;
}



int main()
{
    //wczytywanie
    int wiezly;
    cout << "Podaj liczbe wezlow: ";
    cin >> wiezly;

    vector<double> x(wiezly);
    vector<double> y(wiezly);

    // wczytaj wzely i punkt szukany
    for (int i = 0; i < wiezly; i++)
    {
        cout << "Podaj x[" << i << "]: ";
        cin >> x[i];
        cout << "Podaj y[" << i << "]: ";
        cin >> y[i];
    }
    cout << "Podaj punkt, ktorego wartosci funkcji szukasz: " << endl;
    double szukana;
    cin >> szukana;



    //sprawdzanie
    for(int c = 0; c < wiezly; c++)
    {
        if(c != 0)
        {
            if(x[c] <= x[c - 1])
            {
                if (x[c] < x[c - 1])
                    cout << "error: ciag nieposortowany" << endl;
                else
                    cout << "error: ciag posiada powtorzenia" << endl;
                return 0;
            }
        }
    }

    if(szukana >= x[0] && szukana <= x[wiezly - 1])
    {
        cout << "Dane wprowadzone prawidlowo." << endl;
    }
    else
    {
        cout << "error: szukany x jest poza zasiegiem wezlow interpolacyjnych" << endl;
        return 0;
    }



    // maghia
    string wynik = interpolacja_newtona(x, y);
    cout<< newton_interpolation(x,y,szukana)<< endl;
    cout<< "Interpolacja_newtona: W(x) = "<< wynik<< endl;

    return 0;
}
