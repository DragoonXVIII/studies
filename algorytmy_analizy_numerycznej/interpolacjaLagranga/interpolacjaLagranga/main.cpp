/*#include <iostream>
#include <string>
#include <sstream>
using namespace std;

double interpolacjaLagranga(int n, int x_tab[], int y_tab[], int x)
{
    double wynik = 0.0;
    for (int i = 0; i < n; i++)
    {
        double temp = y_tab[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                temp *= (x - x_tab[j]) / (x_tab[i] - x_tab[j]);
            }
        }
        wynik += temp;
    }
    return wynik;
}

void printPolynomial(int n, int x_tab[], int y_tab[])
{
    cout << "W(x) = ";
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            cout << " + ";
        }
        cout << y_tab[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i) {
                cout << " * (x - " << x_tab[j] << ") / (" << x_tab[i] <<" - " << x_tab[j] << ")";
            }
        }
    }
    cout << endl;
}

int main()
{
    cout << "Podaj ilosc wezlow: " << endl;
    int n;
    cin >> n;
    int x_tab[n], y_tab[n];

    for (int c = 0; c < n; c++)
    {
        cout << "Podaj x" << c + 1 << ": ";
        cin >> x_tab[c];
    }

    for (int c = 0; c < n; c++)
    {
        cout << "Podaj y" << c + 1 << ": ";
        cin >> y_tab[c];
    }

    cout << "Podaj punkt, ktorego wartosci funkcji szukasz: " << endl;
    int x;
    cin >> x;

    for (int c = 0; c < n; c++)
    {
        if (c != 0)
        {
            if (x_tab[c] <= x_tab[c - 1])
            {
                if (x_tab[c] < x_tab[c - 1])
                    cout << "error: ciag nieposortowany" << endl;
                else
                    cout << "error: ciag posiada powtorzenia" << endl;
                return 0;
            }
        }
    }

    if (x >= x_tab[0] && x <= x_tab[n - 1])
    {
        cout << "Dane wprowadzone prawidlowo." << endl;
        double interpolatedValue = interpolacjaLagranga(n, x_tab, y_tab, x);
        cout << "Wartosc funkcji w punkcie x=" << x << " to " << interpolatedValue << endl;
        printPolynomial(n, x_tab, y_tab); // Wyświetlamy wzór Lagrange'a
    }
    else
    {
        cout << "error: szukany x jest poza zasiegiem wezlow interpolacyjnych" << endl;
        return 0;
    }

    return 0;
}

*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Funkcja do obliczania wielomianu interpolacyjnego Lagrange'a
double lagrangeInterpolation(const vector<double>& x, const vector<double>& y, double xi) {
    double result = 0.0;
    for (int i = 0; i < x.size(); i++) {
        double term = y[i];
        string termString = to_string(y[i]); // Inicjalizacja wzoru od wartości funkcji
        for (int j = 0; j < x.size(); j++) {
            if (j != i) {
                term *= (xi - x[j]) / (x[i] - x[j]);
                termString += " * (x - " + to_string(x[j]) + ") / (" + to_string(x[i]) + " - " + to_string(x[j]) + ")";
            }
        }
        result += term;
        cout << "Termin " << i << ": " << termString << endl; // Wyświetlanie wzoru danego terminu
    }
    return result;
}

int main() {
    int n;
    cout << "Podaj liczbe wezlow: ";
    cin >> n;

    vector<double> x(n);
    vector<double> y(n);

    cout << "Podaj wartosci wezlow:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Podaj wartosci funkcji w tych wezlow:\n";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    // Sprawdzenie warunku interpolacji (unikalność węzłów)
    bool uniqueNodes = true;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (x[i] == x[j]) {
                uniqueNodes = false;
                break;
            }
        }
    }

    if (!uniqueNodes) {
        cout << "Warunek interpolacji nie jest spelniony - wezly nie sa unikalne." << endl;
    } else {
        // Podaj punkt, dla którego chcesz obliczyć wartość interpolowaną
        double xi;
        cout << "Podaj punkt, dla ktorego chcesz obliczyc wartosc interpolowana: ";
        cin >> xi;

        double interpolatedValue = lagrangeInterpolation(x, y, xi);
        cout << "Wynik interpolacji w punkcie " << xi << " to " << interpolatedValue << endl;
    }

    return 0;
}
//*/
