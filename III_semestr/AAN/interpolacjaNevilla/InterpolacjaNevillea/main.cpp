#include <iostream>
#include <vector>

using namespace std;

double nevillesMethod(int n, vector<double>& x, vector<double>& y, double p)
{
    vector<vector<double>> Q(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i)
    {
        Q[i][0] = y[i];
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            Q[i][j] = ((p - x[i - j]) * Q[i][j - 1] - (p - x[i]) * Q[i - 1][j - 1]) / (x[i] - x[i - j]);
        }
    }

    return Q[n - 1][n - 1];
}

int main()
{
    int n;
    cout << "Podaj liczbe wezlow: ";
    cin >> n;

    vector<double> x(n), y(n);

    cout << "Podaj wartosci wezlow:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "y[" << i << "]: ";
        cin >> y[i];
    }

    double p;
    cout << "Podaj punkt p: ";
    cin >> p;



    for(int c = 0; c < n; c++)
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

    if(p >= x[0] && p <= x[n - 1])
    {
        cout << "Dane wprowadzone prawidlowo." << endl;
    }
    else
    {
        cout << "error: szukany x jest poza zasiegiem wezlow interpolacyjnych" << endl;
        return 0;
    }



    double result = nevillesMethod(n, x, y, p);

    cout << "Przyblizona wartosc funkcji w punkcie p: " << result << endl;

    return 0;
}
