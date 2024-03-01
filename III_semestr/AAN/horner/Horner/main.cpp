#include <iostream>
#include <vector>

using namespace std;

// Funkcja obliczająca wartość wielomianu i-tego stopnia w punkcie x
double horner(const vector<double>& wspolczynniki, int stopien, double x)
{
    double wynik = wspolczynniki[stopien];
    for (int i = stopien - 1; i >= 0; i--)
    {
        wynik = wynik * x + wspolczynniki[i];
    }
    return wynik;
}

// Funkcja obliczająca pochodną i-tego stopnia wielomianu w punkcie x
double pochodna(const vector<double>& wspolczynniki, int stopien, double x, int stopienPochodnej)
{
    if (stopienPochodnej > stopien)
    {
        return 0.0; // Pochodna stopnia wyższego niż stopień wielomianu wynosi 0
    }
    if (stopienPochodnej == 0)
    {
        return horner(wspolczynniki, stopien, x); // Pochodna zerowego stopnia to sam wielomian
    }

    vector<double> wspolczynnikiPochodnej(stopien - stopienPochodnej + 1);
    for (int i = 0; i < stopien - stopienPochodnej + 1; i++) {
        wspolczynnikiPochodnej[i] = wspolczynniki[i + stopienPochodnej] * 1.0; // Obliczanie nowych współczynników pochodnej
        for (int j = 1; j <= stopienPochodnej; j++) {
            wspolczynnikiPochodnej[i] *= (i + stopienPochodnej - j + 1);
        }
    }

    return horner(wspolczynnikiPochodnej, stopien - stopienPochodnej, x);
}

int main()
{
    int stopien;
    cout << "Podaj stopien wielomianu: ";
    cin >> stopien;

    vector<double> wspolczynniki(stopien + 1);
    cout << "Podaj wspolczynniki wielomianu od najwyzszej potegi do stalej: ";
    for (int i = stopien; i >= 0; i--)
    {
        cin >> wspolczynniki[i];
    }

    double x;
    cout << "Podaj punkt, w którym obliczysz wartosc wielomianu i jego pochodnych: ";
    cin >> x;

    double wartosc = horner(wspolczynniki, stopien, x);
    cout << "Wartosc wielomianu w punkcie " << x << " wynosi: " << wartosc << endl;

    int stopienPochodnej;
    cout << "Podaj stopień pochodnej, którą chcesz obliczyć: ";
    cin >> stopienPochodnej;

    double wartoscPochodnej = pochodna(wspolczynniki, stopien, x, stopienPochodnej);
    cout << "Wartość " << stopienPochodnej << "-stopniowej pochodnej w punkcie " << x << " wynosi: " << wartoscPochodnej << endl;

    return 0;
}
