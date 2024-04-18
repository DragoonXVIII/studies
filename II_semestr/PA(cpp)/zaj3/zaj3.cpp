#include <iostream>
#include <string>
#include <fstream>



using namespace std;



int N;


struct student
{
    string imie;
    string nazwisko;
    int punkty;
};



void wczytajTabliceStudentow(student *&tab)
{
    ifstream dane("studenci.csv");
    if(!dane.is_open())
    {
        cout<<"blad pliku"<<endl;
        exit(1);
    }

    string wiersz,imie,nazwisko,punkty;
    getline(dane,wiersz);
    int n = stoi(wiersz.substr(0,2)); //?????
    N = n;

    tab = new student[n];



    for(int i=0;i<14;i++)
    {
        getline(dane,wiersz);

        size_t srednik1 = wiersz.find(';');
        size_t srednik2 = wiersz.find(';',srednik1+1);

        tab[i].imie = wiersz.substr(0,srednik1);
        tab[i].nazwisko = wiersz.substr(srednik1+1,srednik2-srednik1-1); //srednik2-srednik1-1
        tab[i].punkty = stoi(wiersz.substr(srednik2+1));
    }

    dane.close();
    return;
}


void sortujTabliceStudentow(student *tab,int n, int tryb)
{

    if(n<2)
        return;

    int pivot = tab[n/2].punkty;
    int i=0,j=n-1;

    while(i<j)
    {

        if(tryb==1)
        {
            while(tab[i].punkty<pivot || (tab[i].punkty==pivot)&&(i<n/2))
            {
                i++;
            }
            while(tab[j].punkty>pivot || (tab[j].punkty==pivot)&&(j>n/2))
            {
                j--;
            }
        }
        else
        {
            while(tab[i].punkty > pivot)
            {
                i++;
            }
            while(tab[j].punkty < pivot)
            {
                j--;
            }
        }

        if(i<=j)
        {
            swap(tab[i],tab[j]);
            i++;
            j--;
        }

    }

    sortujTabliceStudentow(tab, j+1, tryb);
    sortujTabliceStudentow(tab+i, n-i, tryb);

    return;
}


void wyswietlStudentow(student *tab)
{
    for(int i=0;i<N;i++)
    {
        cout<<i+1<<". ";
        cout<<tab[i].imie<<" ";
        cout<<tab[i].nazwisko<<" ";
        cout<<tab[i].punkty<<endl;
    }
    return;
}


void usunTabliceStudentow(student *&tab)
{
    delete[] tab;
    return;
}



int main()
{
    student *tab;
    wczytajTabliceStudentow(tab);
    wyswietlStudentow(tab);

    //wyswietl sort1
    cout<<"+=== Sort1 ===+"<<endl;
    sortujTabliceStudentow(tab, N, 1);
    wyswietlStudentow(tab);

    //wyswietl sort0
    cout<<"+=== Sort0 ===+"<<endl;
    sortujTabliceStudentow(tab, N, 0);
    wyswietlStudentow(tab);


    usunTabliceStudentow(tab);


    return 0;
}
