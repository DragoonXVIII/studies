#include <iostream>
#include <fstream>
#include <string>


using namespace std;


struct student
{
    string imie;
    string nazwisko;
    int punkty;
};


void sortowanieQuickSort(student* tab, int n, int tryb)
{

    if (n < 2)
        return;

    int pivot = tab[n/2].punkty; //wartosc pivotu jest ustawiana na srodkowy indeks tabeli structow studentow od pola punkty.
    int i=0, j=n-1;

    while(i<=j)
    {
        if(tryb==1)// sortowanie rosn¹ce
        {
            while(tab[i].punkty < pivot)
                i++;

            while(tab[j].punkty > pivot)
                j--;
        }
        else //sortowanie malej¹ce
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

        if(i <= j)
        {
            swap(tab[i],tab[j]);
            i++;
            j--;
        }
    }

    sortowanieQuickSort(tab, j + 1, tryb);
    sortowanieQuickSort(tab + i, n - i, tryb);

}


void wczytajStudentow(student*& tab, int n) //zczytanie z pliku studentow
{
    tab = new student[n];

    ifstream plik("studenci.csv");
    if(!plik.is_open())
    {
        cout<<"Nie udalo sie otworzyc pliku."<<endl;
        exit(1);
    }

    string linia;
    getline(plik, linia);  // pomijamy pierwsz¹ linijkê

    int i = 0;
    while(getline(plik, linia))
    {
        string imie, nazwisko, punkty_str;
        int punkty;

        size_t pozycja1 = linia.find(';'); //arg 1: co szukamy, arg 2: gdzie zaczac szukac
        size_t pozycja2 = linia.find(';', pozycja1 + 1);

        imie = linia.substr(0, pozycja1);
        nazwisko = linia.substr(pozycja1 + 1, pozycja2 - pozycja1 - 1);
        punkty_str = linia.substr(pozycja2 + 1);

        punkty = stoi(punkty_str);

        tab[i].imie = imie;
        tab[i].nazwisko = nazwisko;
        tab[i].punkty = punkty;

        i++;
    }

    plik.close();
}


void usunTabliceStudentow(student*& tab)
{
    delete[] tab;
    tab = nullptr;
}


void wyswietlStudentow(student* tab, int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<tab[i].imie<<" ";
        cout<<tab[i].nazwisko<<" ";
        cout<<tab[i].punkty<<endl;
    }
}



int main()
{
    int n;
    /*cout<<"Podaj liczbe studentow: ";
    cin>>n;
    */

    ifstream plik("studenci.csv");
    if(!plik.is_open())
    {
        cout<<"Nie udalo sie otworzyc pliku."<<endl;
        exit(1);
    }

    string hlpvar;
    getline(plik, hlpvar);
    hlpvar.substr(0,1);
    n = stoi(hlpvar);

    plik.close();

    student* tab;

    wczytajStudentow(tab,n);
    wyswietlStudentow(tab,n);
    sortowanieQuickSort(tab,n,1);
    wyswietlStudentow(tab,n);

}
