#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <ctype.h>
#include <algorithm>
#include <string>
#include <conio.h>
#include <vector>
#include <locale.h>
#include <thread>
#include <future>
#include <chrono>



using namespace std;



bool prime(int n)
{
    if (n<=1) return false;
    if (n<=3) return true;
    if ( n%2==0 || n%3==0 ) return false;
    for (int i = 5; i * i<=n;i+=6)
        {
            if ( n%i==0 ||n%(i+2)==0 )
            {
                return false;
            }
        }
    return true;
}

void przydzielPamiec1D(int *&tab, int n)
{

    tab = new int[n];
    return;
}

void wypelnijTablice1D(int *tab, int n, int a, int b) //n dluGosc
{
    srand(time(0));

    for(int i=0;i<n;i++)
    {
        tab[i] = rand()%(b-a+1)+a;
    }

    return;
}

void usunTablice1D(int *&tab)
{

    delete[] tab;
    return;
}

void wyswietl1D(int* tab, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<endl;
    }

    return;
}



int main()
{
    while(true)
    {
        cout<<"Wpisz numer wybranej opcji: "<<endl<<"1) zadanie 1.2"<<endl<<"2) zadanie 1.3"<<endl<<"3) zadanie 1.4 "<<endl<<"4) zadanie 1.5 "<<endl<<"5) wyjscie z programu"<<endl;  int x;
        cin>>x;
        switch(x)
        {
            case 1:
            {
                int *tab;
                int a,b,n;
                cout<<"Podaj a: ";
                cin>>a;
                cout<<"Podaj b: ";
                cin>>b;
                cout<<"Podaj n: ";
                cin>>n;

                przydzielPamiec1D(tab,n);
                wypelnijTablice1D(tab,n,a,b);

                int s = sizeof(tab) / sizeof(tab[0]);
                int x = *min_element(tab, tab + s);
                cout<<x<<endl;
                if(prime(x))
                    cout<<"pierwsza"<<endl;
                else
                    cout<<"nie pierwsza"<<endl;

                break;
            }

            case 2:
            {
                int *tab;
                int n;
                int tab_wyst[9][2] = {1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0}; //[9][2]

                cout<<"Podaj n: ";
                cin>>n;
                przydzielPamiec1D(tab,n);
                wypelnijTablice1D(tab,n,0,9);

                for(int i=0;i<n;i++)
                {
                    for(int k=0;k<9;k++)
                    {
                        if(tab[i]==tab_wyst[k][0])
                        {
                            tab_wyst[k][1]++;
                            break;
                        }
                    }
                }

                for(int j=0;j<9;j++)
                {
                    cout<<tab_wyst[j][0]<<": "<<tab_wyst[j][1]<<endl;
                }

                break;
            }

            case 3:
            {
                int *tab;
                int a,b,n;
                cout<<"Podaj a: ";
                cin>>a;
                cout<<"Podaj b: ";
                cin>>b;
                cout<<"Podaj n: ";
                cin>>n;

                przydzielPamiec1D(tab,n);
                wypelnijTablice1D(tab,n,a,b);
                wyswietl1D(tab,n);

                //int tab_wyst[b-a][2];
                //int s = sizeof(tab) / sizeof(tab[0]);

                int max_ele = *max_element(tab, tab + n);

                int suma = 0;

                /*for(int i=0;i<n;i++)
                {
                    if(tab[i]==max_ele)
                    {
                        suma+=max_ele;
                    }
                }*/
                cout<<"+====+"<<endl;
                string liczba = to_string(max_ele);
                cout<<max_ele<<endl;
                for(int i=0;i<liczba.length();i++)
                {
                    suma+=liczba[i];
                    cout<<liczba[i]<<endl;
                }
                cout<<liczba<<" to max, suma cyfr max wynosi: "<<suma<<endl;

                break;
            }

            case 4:
            {
                //cout<<"inactive case"<<endl;
                int *tab;
                int a,b,n;
                cout<<"Podaj a: ";
                cin>>a;
                cout<<"Podaj b: ";
                cin>>b;
                cout<<"Podaj n: ";
                cin>>n;

                przydzielPamiec1D(tab,n);
                wypelnijTablice1D(tab,n,a,b);
                //wyswietl1D(tab,n);


                break;
            }

            case 5:
            {
                return 0;
            }

            default:
                cout<<"error: index out of range/n";
                break;
        }

    }


    /*
    przydzielPamiec1D(tab,n);
    wypelnijTablice1D(tab,n,a,b);
    wyswietl1D(tab,n);
    usunTablice1D(tab);
    */
    return 0;
}
