#include <iostream>
#include "Adding.h"
#include "Student.h"
#include "array.h"

using namespace std;

template <typename T>
void showAll(T* tab[], int n)
{
    for(int i=0;i<n;i++)
        tab[i]->show();
}

template <typename T>
T findMin(T arr[], int size)
{
    if (size <= 0)
    {
        throw invalid_argument("Tablica musi zawierać co najmniej jeden element.");
    }

    T minElement = arr[0]; //pierwszy minimalny i petla przez calosc

    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < minElement)
        {
            minElement = arr[i];
        }
    }

    return minElement;
}

void zad1()
{
    Adding<int> a1(5);
    a1.add(6);
    a1.show();

    Adding<string> a2("Pro");
    a2.add("gramowanie");
    a2.show();

    Student<float> s(5,"Ala");
    s.showMark();
    Student<int> s1(5,"Ala");
    s1.showMark();
    Student<string> s2(5,"Ala");
    s2.showMark();

    Adding<int>* arrAdd[3];
    for(int i=0;i<3;i++)
    {
        arrAdd[i]=new Adding<int>(i);
    }
    showAll(arrAdd,3);
    Student<string>* arrStu[3];
    for(int i=0;i<3;i++)
    {
        arrStu[i]=new Student<string>(i+2,"Ala");
    }
    showAll(arrStu,3);
    for(int i=0; i<3; i++)
        delete arrAdd[i];
    for(int i=0; i<3; i++)
        delete arrStu[i];

    return;
}

void zad2()
{
    //int
    int arrInt[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);
    cout << "Minimalny element w tablicy int: " << findMin(arrInt, sizeInt) << endl;
    //float
    double arrDouble[] = {3.14, 2.71, 1.41, 0.577, 1.618};
    int sizeDouble = sizeof(arrDouble) / sizeof(arrDouble[0]);
    cout << "Minimalny element w tablicy double: " << findMin(arrDouble, sizeDouble) << endl;
    return;
}

void zad3()
{
    Array<int> intArray(5);
    intArray.addEl(10);
    intArray.addEl(3);
    intArray.addEl(7);
    intArray.addEl(1);
    intArray.addEl(5);

    cout << "Zawartosc tablicy int przed sortowaniem: ";
    intArray.showArray();
    intArray.sortAscending();
    cout << "Zawartosc tablicy int po sortowaniu: ";
    intArray.showArray();
    cout << "Maksymalny element w tablicy int: " << intArray.getMaxEl() << endl;


    // Testowanie specjalizacji dla typu string
    Array<string> stringArray(3);
    stringArray.addEl("Alaska");
    stringArray.addEl("Kot");
    stringArray.addEl("Programowanie");

    cout<<"\nZawartosc tablicy string przed sortowaniem: ";
    stringArray.showArray();
    stringArray.sortAscending();
    cout<<"Zawartosc tablicy string po sortowaniu: ";
    stringArray.showArray();
    cout<<"Najdluzszy napis w tablicy string: " << stringArray.getMaxEl()<<endl;

    cout<<"Proba przepelnienia tablicy:"<<endl;
    try
    {
        stringArray.addEl("Przepelniony");

    } catch (overflow_error) {
        cout<<"Blad: overflow_error"<<endl;
    }
    cout<<"Proba odczytania pamieci poza zasiegiem:"<<endl;
    try
    {
        string test = stringArray.getNEl(4);
        cout<<test<<endl;
    } catch (out_of_range)
    {
        cout<<"Blad: out_of_range"<<endl;
    }
}

int main()
{
    zad1();

    //zad2();

    //zad3();

    return 0;
}
