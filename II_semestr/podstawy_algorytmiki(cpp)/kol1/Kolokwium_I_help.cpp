#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <time.h>



using namespace std;



void tabCreate(int *&tab, int n)
{
    tab = new int[n];
    return;
}

void tabFill(int *tab, int n)
{
    for(int i=0;i<n;i++)
        tab[i] = rand()%10-1+1;
    return;
}

void tabDelete(int *&tab)
{
    delete tab;
    return;
}


void tabShow(int *tab, int n)
{

    for(int i=0;i<n;i++)
        cout<<tab[i]<<", ";
    cout<<"\n";
    return;
}


void sortowanie_wstawianie(int *tab, int n)
{
    int i = n-2,j;
    int temp;
    while(i>=0)
    {
        j=i;
        temp=tab[j];
        while(temp>tab[j+1] && j<n-1)
        {
            tab[j]=tab[j+1];
            j+=1;
        }
        tab[j]=temp;
        i-=1;
    }
    return;
}


void sortowanie_wybieranie(int *tab, int n)
{
    int i = n-1, ind, j;
    while(i>0)
    {
        ind = 0;
        j=1;
        while(j<=i)
        {
            if(tab[j]>tab[ind])
            {
                ind = j;
            }
            j=j+1;
        }
        swap(tab[i],tab[ind]);
        i=i-1;
    }
    return;
}


void sortowanie_babelki(int *tab, int n)
{
    int i = n-1, j;
    while(i>0)
    {
        j=0;
        while(j<i)
        {
            if(tab[j]>tab[j+1])
                swap(tab[j],tab[j+1]);
            j+=1;
        }
        i-=1;
    }
    return;
}


void sortowanie_szybkosc(int *tab, int lewy, int prawy)
{
    int srodek = int((lewy+prawy)/2);
    int piwot = tab[srodek];
    tab[srodek] = tab[prawy];
    int granica = lewy;
    int i=lewy;
    while(i<prawy)
    {
        if(tab[i]<piwot)
        {
            swap(tab[granica],tab[i]);
            granica+=1;
        }
        i+=1;
    }
    tab[prawy] = tab[granica];
    tab[granica] = piwot;
    if(lewy<granica-1)
    {
        sortowanie_szybkosc(tab, lewy, granica-1);
    }
    if(granica+1<prawy)
    {
        sortowanie_szybkosc(tab, granica+1, prawy);
    }
    return;
}




int main()
{
    srand(time(NULL));
    int *tab, n = 10;
    tabCreate(tab,n);

    tabFill(tab,n);
    cout<<"RANDOM TAB\n";
    tabShow(tab,n);

    sortowanie_wstawianie(tab,n);
    cout<<"INSERT TAB\n";
    tabShow(tab,n);


    tabFill(tab,n);
    cout<<"RANDOM TAB\n";
    tabShow(tab,n);

    sortowanie_wybieranie(tab,n);
    cout<<"SELECT TAB\n";
    tabShow(tab,n);


    tabFill(tab,n);
    cout<<"RANDOM TAB\n";
    tabShow(tab,n);

    sortowanie_babelki(tab,n);
    cout<<"BUBBLE TAB\n";
    tabShow(tab,n);


    tabFill(tab,n);
    cout<<"RANDOM TAB\n";
    tabShow(tab,n);

    sortowanie_szybkosc(tab,0,n-1);
    cout<<"QUICK TAB\n";
    tabShow(tab,n);




    tabDelete(tab);
    return 0;
}


