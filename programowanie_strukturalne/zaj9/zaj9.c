#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>
//#include <vector>



void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void suma_roznica(int *a, int *b)
{
    int temp = *a;
    *a -= *b;
    *b += temp;
    return;
}

bool iloczyn_1_100(int *a)
{
    int n;

    printf("Ile liczb zamierzasz wpisac? ");
    scanf("%d",&n);

    int tab[n];
    bool temp = false;

    for(int i=0;i<n;i++)
    {
        printf("\nPodaj kolejna (%d) liczbe: ",(i+1));
        scanf("%d",&tab[i]);
        if(tab[i]>=0&&100>=tab[i])
            temp = true;
    }

    if(!temp)
    return false;

    *a = 1;

    for(int j=0;j<(sizeof(tab)/sizeof(tab[j]));j++) // sizeof(tab)/sizeof(tab[0] wielkosc calej tablicy w B / wielkosc jednego elementu w B = ilosc elementow
    {
        if(tab[j]>=0&&100>=tab[j])
            *a *= tab[j];
    }

    printf("iloczyn: %d \n",*a);

    return true;
}

void dekompozycja()
{
    float a,c;
    printf("Podaj liczbe: ");
    scanf("%f",&a);
    int b = (int)a;
    c = a - b;

    printf(" int: %d float: %f",b,c);
    return;
}

void ile_0_ile_dod()
{

    int licz0 = 0, licz_dod = 0,strc;
    float liczba;
    char liczba_s[16], cpom[] = "ok";
    bool pom = true;

    printf("podawaj liczby, zakoñcz wpisaniem (ok)");

    while(true)
    {
        printf("\n podaj kolejna liczbe: ");
        scanf(" %s", liczba_s);

            //printf("%s",liczba_s);
        strc = strcmp(liczba_s, cpom); //strcpm to funkcja sprawdzajaca rownosc dwoch lancuchow znakowych
            //printf("%d",strc);

        if(strc == 0)
        {
            //printf("schluss\n"); //debug
            printf("0: %d, dod: %d",licz0,licz_dod);
            return;
        }
        else
            liczba = atof(liczba_s);
        if(liczba == 0.0)
            licz0++;
        if(liczba > 0.0)
            licz_dod++;

    }

    return;
}



int main()
{
    //zad9.2

    /*
    int a, b;
    printf("podaj a: ");
    scanf("%d",&a);

    printf("podaj b: ");
    scanf("%d",&b);

    printf("a: %d oraz b: %d \n",a,b);

    swap(&a,&b);

    printf("a: %d oraz b: %d \n",a,b);

    */
    //9.3
    /*
    int a, b;
    printf("podaj a: ");
    scanf("%d",&a);

    printf("podaj b: ");
    scanf("%d",&b);

    printf("a: %d oraz b: %d \n",a,b);

    suma_roznica(&a,&b);

    printf("suma: %d oraz roznica: %d \n",b,a);
    */
    //9.4
    /*
    int wynik = 1;
    printf("a: %d\n", a);

    if(!iloczyn_1_100(&wynik))
        printf("Brak liczb spelniajacych warunek 1-100. \n");
    */
    //9.5
    //dekompozycja();
    //.9.6
    //ile_0_ile_dod();



    return 0;
}
