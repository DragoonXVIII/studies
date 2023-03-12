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
        cout<<tab[i]<<", ";
    }
    cout<<endl;

    return;
}

void sortowanieBabelkowe(int* tab, int n, int tryb)
{
    if(!tryb)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n-i;j++)
            {
                if(tab[j-1]>tab[j])
                {
                    swap(tab[j-1], tab[j]);
                }
            }
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n-i;j++)
            {
                if(tab[j-1]<tab[j])
                {
                    swap(tab[j-1], tab[j]);
                }
            }
        }
    }

    return;
}

void sortowaniePrzezWybor(int* tab, int n, int tryb)
{
    int min_index;

    if(!tryb)
    {
        for(int i=0;i<n-1;i++)
        {
            min_index=i;
            for(int j=i;j<n;j++)
            {
                if(tab[j]<tab[min_index])
                    min_index=j;
            }
            swap(tab[i],tab[min_index]);
        }
    }
    else
    {
        for(int i=0;i<n-1;i++)
        {
            min_index=i;
            for(int j=i;j<n;j++)
            {
                if(tab[j]>tab[min_index])
                    min_index=j;
            }
            swap(tab[i],tab[min_index]);
        }
    }
    return;
}

void sortowaniePrzezWstawianie(int* tab, int n, int tryb)
{

    int pom, j;

    if(!tryb)
    {
        for(int i=1; i<n; i++)
        {

            pom = tab[i];
            j = i-1;

            while(j>=0 && tab[j]>pom)
            {
                tab[j+1] = tab[j];
                j--;
            }
            tab[j+1] = pom;
         }
    }
    else
    {
        for(int i=1; i<n; i++)
        {

            pom = tab[i];
            j = i-1;

            while(j>=0 && tab[j]<pom)
            {
                tab[j+1] = tab[j];
                j--;
            }
            tab[j+1] = pom;
         }
    }

    return;
}





int main()
{
    while(true)
    {
        //system("cls");
        cout<<"Wpisz numer wybranej opcji: "<<endl<<"1) zadanie 2.2"<<endl<<"2) zadanie 2.3"<<endl<<"3) zadanie 2.4 "<<endl<<"4) zadanie 2.5 "<<endl<<"5) wyjscie z programu"<<endl;  int x;
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
                wyswietl1D(tab,n);
                cout<<endl;
                sortowanieBabelkowe(tab,n,0);
                wyswietl1D(tab,n);
                cout<<endl;
                sortowanieBabelkowe(tab,n,1);
                wyswietl1D(tab,n);
                cout<<endl;
                usunTablice1D(tab);

                break;
            }

            case 2:
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
                cout<<endl;
                sortowaniePrzezWybor(tab,n,0);
                wyswietl1D(tab,n);
                cout<<endl;
                sortowaniePrzezWybor(tab,n,1);
                wyswietl1D(tab,n);
                cout<<endl;
                usunTablice1D(tab);

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
                cout<<endl;
                sortowaniePrzezWstawianie(tab,n,0);
                wyswietl1D(tab,n);
                cout<<endl;
                sortowaniePrzezWstawianie(tab,n,1);
                wyswietl1D(tab,n);
                cout<<endl;
                usunTablice1D(tab);

                break;
            }

            case 4:
            {
                cout<<"case inactive"<<endl;
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

    return 0;
}
