#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


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
    cout<<n<<endl;
    tab = new student[n];



    for(int i=0;i<n;i++)
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


void wczytajTabliceStudentowZaj(student *&tab)
{

    string sciezka,linia;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;
    sciezka="studenci.csv";
    plik.open(sciezka);
    plik >> liczbaStudentow;
    //cout<<liczbaStudentow;
    tab = new student[liczbaStudentow];
    for(int i = 0; i < 2; i++)
        plik >> sredniki;

    string intstring;
    for(int i=0; i<liczbaStudentow; i++)
    {
        plik>>linia;
        //cout<<linia<<endl;
        istringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        //cout<<tab[i].imie;
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, intstring);
        tab[i].punkty = stoi(intstring);
        //cout<<tab[i].punkty<<endl;
    }

    plik.close();

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


void podzielStudentow_dwa(student *tab, int n)
{
    int j=n-1;
    int i=0;
    while(i<j)
    {
        while(tab[i].punkty <= 10 && i<j)  //tab[j].punkty>10 && tab[j].punkty<=10
            i++;

        while(tab[j].punkty >10 && j>i)
            j--;

        if (i<j) {
           // swap(tab[j],tab[i]);
           student r=tab[i];
           tab[i]=tab[j];
           tab[j]=r;
            i++;
            j--;
        }
    }

    return;
}


void podzielStudentow_trzy(student* tab, int n) // xmod3=0, xmod3=1, xmod3=2;
{
    int i=0, j=n-1;

    while(i<j)
    {
        while(i<j && tab[i].punkty%3!=0)
            i++;

        while(i<j && tab[j].punkty%3==0)
            j--;

        if(i<j)
            swap(tab[i], tab[j]);
    }

    j=i-1, i=0 ;

    //cout<<i<<" "<<j<<endl;

    while(i<j)
    {
        while(i<j && tab[i].punkty%3!=2)
            i++;

        while(i<j && tab[j].punkty%3==2) //tab[j].punkty%3==0 ||
            j--;

        if (i<j)
            swap(tab[i], tab[j]);
    }

    return;
}


void wyswietlStudentow(student *tab,int n)
{
    for(int i=0;i<n;i++)
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

    string sciezka;
    int liczbaStudentow;
    ifstream plik;
    sciezka="studenci.csv";
    plik.open(sciezka);
    plik >> liczbaStudentow;
    //cout<<liczbaStudentow;
    plik.close();

    student *tab;
    wczytajTabliceStudentowZaj(tab);
    //wczytajTabliceStudentow(tab);
    wyswietlStudentow(tab,liczbaStudentow);
/*
    //wyswietl sort1
    cout<<"+=== Sort1 ===+"<<endl;
    sortujTabliceStudentow(tab, N, 1);
    wyswietlStudentow(tab);

    //wyswietl sort0
    cout<<"+=== Sort0 ===+"<<endl;
    sortujTabliceStudentow(tab, N, 0);
    wyswietlStudentow(tab);*/

    //wyswietl podziel2

    cout<<"+=== Podziel2 ===+"<<endl;
//    podzielStudentow_dwa(tab,liczbaStudentow);
    wyswietlStudentow(tab,liczbaStudentow);
/*
    //wyswietl podziel3
    cout<<"+=== Podziel3 ===+"<<endl;
    podzielStudentow_trzy(tab,liczbaStudentow);
    wyswietlStudentow(tab,liczbaStudentow);
*/
    usunTabliceStudentow(tab);

    return 0;
}

//3.1
//3.2
