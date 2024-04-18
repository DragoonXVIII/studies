#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define STUDENT "student"
#define SREDNIA 4.5
/*

*/

int main()
    {
//zad 3.3
/*
    setlocale(LC_ALL,"");

    char imie[20]; //deklaracja tablic znaków o nazwach imie, nazwisko, plec, o 20 miejscach na znaki
    char nazwisko[20];
    char plec[20];

    scanf("%s",imie); //wczytaj z terminalu tablice imie, nazwisko, plec;
    scanf("%s",nazwisko);
    scanf("%s",plec);

    printf("\n");

    printf("%s\n",imie);//wyœwietl w konsoli tablice imie nazwisko plec oraz predefiniowane wartosci STUDENT oraz SR
    printf("%s\n",nazwisko);
    printf("%s\n",plec);
    printf("%s\n",STUDENT);
    printf("%f\n ",SREDNIA);
*/
// 3.4
/*
    int a,b,c,h,r,ppp,op; //deklaracja zmiennych typu integer o podanych nazwach
    float pb,ob,pi=3.14,ppw,ow;//deklaracja zmiennych typu float o podanych nazwach

    scanf("%d",&a); //wczytaj z terminalu wartosci zmiennych
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&h);
    scanf("%d",&r);

    ppp = a*b*2+a*c*2+b*c*2; //obliczenia na zmiennych
    op = a*b*c;
    ppw = 2*pi*r*h;
    ow = pi*(pow(r,2))*h;

    printf("%d\n",ppp); //wyœwietl w terminalu wartosci zmiennych
    printf("%d\n",op);
    printf("%f\n",ppw);
    printf("%f\n",ow);
*/
//3.5
/*
    int x,y;    //deklaracja zmiennych int
    float srednia_arytmetyczna,srednia_geometryczna; //deklaracja zmiennych float

    scanf("%d",&x); //wczytaj z terminalu wartosci zmiennych
    scanf("%d",&y);

    srednia_arytmetyczna = (x+y)/2.0; //obliczenia na zmiennych
    srednia_geometryczna = sqrt(x*y);

    printf("%f",srednia_arytmetyczna); //wyœwietl w terminalu wartosci zmiennych
    printf("%f",srednia_geometryczna);
*/
//3.6
/*
    int pom0,pom; //deklaracja zmiennych int float oraz long
    float pom2;
    long int pom3;

    printf(" 1 - mile na km \n 2 - km na mile \n 3 - konie mech na waty \n 4 - km/h na m/s \n 5 - F to C\n"); //wyswietl komunikat informujacy o mozliwych do wybrania opcjach

    scanf("%d",&pom0); //wczytaj zmiennia pom0 odpowiedzialna za wybranie odpowiedniej opcji
    scanf("%d",&pom); //wczytaj zmienna pom bedaca wartoscia na podstawie ktorej wykonywane beda dalsze obliczenia

    switch(pom0) //instrukcja wyboru odpowiedniego case'a jesli pom0 ma  wartosci 1 to case 1, jezeli 5 to case 5;
    {
    case 1: //mila = 0,625 km
        pom2 = pom*0.625;
        printf("%f",pom2);
        break;

    case 2:
        pom2 = pom*1.6;
        printf("%f",pom2);
        break;

    case 3:
        pom3 = pom*735;
        printf("%ld",pom3);
        break;

    case 4:
        pom2 = pom*0.28;
        printf("%f",pom2);
        break;

    case 5:
        pom2 = (pom-32)*5/9;
        printf("%f",pom2);
        break;
    }
*/
//3.7

    int wiekl,wiekm,czas,ile_lat,ile_mies; //deklaracja zmiennych int

    scanf("%d",&wiekl); //wczytanie wartosci zmiennych
    scanf("%d",&wiekm);
    scanf("%d",&czas); //miesiace!

    ile_lat = czas/12;  //operacje na zmiennych
    ile_mies = czas%12;

    ile_lat+=wiekl;
    ile_mies+=wiekm;

    if(ile_mies>=12)
    {
    ile_mies-=12;
    ile_lat++;
    }

    printf("%d\n",ile_lat); //wypisz zmienne
    printf("%d\n",ile_mies);


    return 0;
    }

