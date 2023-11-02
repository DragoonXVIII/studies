#include <iostream>



using namespace std;



struct wielomianFundamentalny
{

};



int main()
{
    cout<< "Podaj ilosc wezlow: "<< endl;

    int n;
    cin>>n;
    int x_tab[n],y_tab[n];

    for(int c=0; c<n; c++)
    {
        cout<< "Podaj x" <<c+1 << ": ";
        cin>>x_tab[c];
    }

    for(int c=0; c<n; c++)
    {
        cout<< "Podaj y" <<c+1 << ": ";
        cin>>y_tab[c];
    }

    cout<< "Podaj punkt ktorego wartosci funkcji szukasz"<< endl;
    int x;
    cin>>x;

    for(int c=0; c<n; c++)
    {
        if(c!=0)
        {
            if(x_tab[c]<=x_tab[c-1])
            {
                if(x_tab[c]<x_tab[c-1])
                    cout<< "error: ciag nieposortowany"<< endl;
                else
                    cout<< "error: ciag posiada powtorzenia"<< endl;
                return 0;
            }
        }
    }

    if(x>=x_tab[0] && x<=x_tab[n-1])
    {
        //cout<< "X:"<< x<< ", Xmin: "<< x_tab[0]<< ", Xmax: "<< x_tab[n-1]<< endl;
        cout<< "Dane wprowadzone prawidlowo." <<endl;
    }
    else
    {
        cout<< "error: szukany x jest poza zasiegiem wezlow interpolacyjnych"<< endl;
        return 0;
    }

    wielomianFundamentalny wezly[n];


    return 0;
}
