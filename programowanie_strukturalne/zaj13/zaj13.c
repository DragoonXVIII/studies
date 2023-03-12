#include <stdio.h>
#include <stdlib.h>



struct pracownik
    {
        char imie[16];
        char nazwisko[16];
        int liczba_h;
        int stawka;
        float premia; //procenty

    };





int main()
{
    /*
    struct pracownik p1;

    int a;
    float b;

    gets(p1.imie);
    gets(p1.nazwisko);
    scanf("%d",&p1.liczba_h);
    scanf("%d",&p1.stawka);
    scanf("%f",&p1.premia);

    a = p1.stawka*p1.liczba_h;
    b = a*p1.premia/100;

    printf("\n wyplata to: %d premia to: %f \n",a,b);

    */

    int a;
    float b;

    int n;
    float x = 0.0;
    scanf("%d\n",&n);

    struct pracownik p[n];      // struct pracownik jako typ

    for(int i = 0; i<n; i++)
    {
        scanf("%s", &p[i].imie);
        //printf("\n");
        scanf("%s", &p[i].nazwisko);
        //printf("\n");
        scanf("%d", &p[i].liczba_h);
        scanf("%d", &p[i].stawka);
        scanf("%f", &p[i].premia);
        printf("\n");
    }

    for(int i = 0; i<n; i++)
    {
        printf("%s ", p[i].imie);
        printf("%s ", p[i].nazwisko);
        printf("%d ", p[i].liczba_h);
        printf("%d ", p[i].stawka);
        printf("%f ", p[i].premia);
        a = p[i].stawka*p[i].liczba_h;
        b = a*p[i].premia/100;
        printf("stawka za osobe: %f",a+b);
        x += a+b;
        printf("\n");
    }
    printf("%f",x);


    return 0;
}
