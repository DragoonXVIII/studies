#include <iostream>
#include <fstream>
#include <math.h>
#include <cstring>
#include <string>
#include <sstream>


using namespace std;


 /* ifstream dane("studenci.csv");
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
    return;*/

struct student
{
    int index;
    int o1;
    int o2;
    int o3;
    float srednia;
};

struct pracownik
{
    int stanowisko;
    int m1; //m1*1/2 + m2*1/4 + m3*1/2 (srednia wazona) = wynik kwartalny
    int m2; //(jezeli wynik kwartalny > normy) to pracownikowi nalezy sie premia
    int m3;
    int norma;
    float premia;
    //jezeli:    (m1*1/2 + m2*1/4 + m3*1/2 > norma) to wtedy: premia =
};

void pobierz_dane(student *tab, int n)
{
    ifstream dane("oceny.txt");
    if(!dane.is_open())
    {
        cout<<"blad pliku"<<endl;
        exit(1);
    }

    string student;
    getline(dane,student); //po to zeby 1 linijka se poszla xd

    for(int i=0; i<n;i++)
    {
        getline(dane,student);

        size_t srednik1 = student.find(';');
        size_t srednik2 = student.find(';',srednik1+1);
        size_t srednik3 = student.find(';',srednik2+1);

        tab[i].index = stoi(student.substr(0,srednik1));
        tab[i].o1 = stoi(student.substr(srednik1+1,srednik2-srednik1-1));
        tab[i].o2 = stoi(student.substr(srednik2+1,srednik3-srednik2-1));
        tab[i].o3 = stoi(student.substr(srednik3+1,srednik2-srednik3-1));
        tab[i].srednia = tab[i].o1*0.3 + tab[i].o2*0.5 + tab[i].o3*0.2;
        if(tab[i].srednia<2.75)
        {
            tab[i].srednia = 2;
            cout<<"tst: "<<tab[i].srednia;
        }
        else if((tab[i].srednia - int(tab[i].srednia)) > 0.75)
        {
            tab[i].srednia = int(tab[i].srednia) + 1;
            cout<<"tst: "<<tab[i].srednia;
        }

        else if((tab[i].srednia - int(tab[i].srednia)) > 0.25)
        {
            tab[i].srednia = int(tab[i].srednia) + 0.5;
            cout<<"tst: "<<tab[i].srednia;
        }
        else
        {
            tab[i].srednia = int(tab[i].srednia);
            cout<<"tst: "<<tab[i].srednia;
        }


        cout<<"INDEX: "<<tab[i].index<<" o1: "<<tab[i].o1<<" o2: "<<tab[i].o2<<" o3: "<<tab[i].o3<<" SREDNIA: "<<tab[i].srednia<<endl;
        //studenci_tab[i] =

    }
    dane.close();
    return;
}


void pobierz_dane_2(pracownik *tab, int n)
{
    ifstream dane("wyniki.txt");
    if(!dane.is_open())
    {
        cout<<"blad pliku"<<endl;
        exit(1);
    }

    string pracownik;
    getline(dane,pracownik); //po to zeby 1 linijka se poszla xd

    for(int i=0; i<n;i++)
    {
        getline(dane,pracownik);

        size_t srednik1 = pracownik.find(';');
        size_t srednik2 = pracownik.find(';',srednik1+1);
        size_t srednik3 = pracownik.find(';',srednik2+1);
        size_t srednik4 = pracownik.find(';',srednik3+1);

        tab[i].stanowisko = stoi(pracownik.substr(0,srednik1));
        tab[i].m1 = stoi(pracownik.substr(srednik1+1,srednik2-srednik1-1));
        tab[i].m2 = stoi(pracownik.substr(srednik2+1,srednik3-srednik2-1));
        tab[i].m3 = stoi(pracownik.substr(srednik3+1,srednik2-srednik3-1));
        tab[i].norma = stoi(pracownik.substr(srednik4+1,srednik3-srednik4-1));
        if((tab[i].m1*0.25+tab[i].m2*0.5+tab[i].m3*0.25) > tab[i].norma)
            tab[i].premia = ((tab[i].m1*0.25+tab[i].m2*0.5+tab[i].m3*0.25) - tab[i].norma) * 24;
        else tab[i].premia = 0;


        cout<<"STANOWISKO: "<<tab[i].stanowisko<<" m1: "<<tab[i].m1<<" m2: "<<tab[i].m2<<" m3: "<<tab[i].m3<<" norma:"<<tab[i].norma<<" premia:"<<tab[i].premia<<endl;
    }
    dane.close();
    return;
}

void wyswietl(student *tab, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"INDEX: "<<tab[i].index<<" o1: "<<tab[i].o1<<" o2: "<<tab[i].o2<<" o3: "<<tab[i].o3<<" SREDNIA: "<<tab[i].srednia<<endl;
    }
    return;
}


void wyswietl_2(pracownik *tab, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"STANOWISKO: "<<tab[i].stanowisko<<" m1: "<<tab[i].m1<<" m2: "<<tab[i].m2<<" m3: "<<tab[i].m3<<" norma:"<<tab[i].norma<<" premia:"<<tab[i].premia<<endl;
    }
    return;
}


void sortowanie_wstawianie(student *tab, int n)
{
    int i = n-2,j;
    student temp;
    while(i>=0)
    {
        j=i;
        temp=tab[j];
        while(temp.srednia>tab[j+1].srednia && j<n-1)
        {
            tab[j]=tab[j+1];
            j+=1;
        }
        tab[j]=temp;
        i-=1;
    }
    return;
}


void sortowanie_wybieranie(pracownik *tab, int n)
{
    int i = n-1, ind, j;
    while(i>0)
    {
        ind = 0;
        j=1;
        while(j<=i)
        {
            if(tab[j].premia>tab[ind].premia)
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



int main()
{
    /*ifstream dane("oceny.txt");
    if(!dane.is_open())
    {
        cout<<"blad pliku"<<endl;
        exit(1);
    }

    string ilosc_studentow;
    int n;
    getline(dane,ilosc_studentow);
    n = stoi(ilosc_studentow);
    dane.close();

    cout<<"LICZBA SUTDENTOW: "<<n<<endl;
    student *studenci_tab;
    studenci_tab = new student[n];
    pobierz_dane(studenci_tab, n);
    sortowanie_wstawianie(studenci_tab, n);
    cout<<"+==========================================================+"<<endl;
    wyswietl(studenci_tab, n);*/

    ifstream dane("wyniki.txt");
    if(!dane.is_open())
    {
        cout<<"blad pliku"<<endl;
        exit(1);
    }

    string ilosc_pracownikow;
    int n;
    getline(dane,ilosc_pracownikow);
    n = stoi(ilosc_pracownikow);
    dane.close();

    cout<<"LICZBA pracownikow: "<<n<<endl;
    pracownik *pracownicy_tab;
    pracownicy_tab = new pracownik[n];
    pobierz_dane_2(pracownicy_tab, n);
    sortowanie_wybieranie(pracownicy_tab, n);
    cout<<"+==========================================================+"<<endl;
    wyswietl_2(pracownicy_tab, n);
    delete pracownicy_tab;


    //delete studenci_tab;
    return 0;
}
