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

    int a,n;
    float x = 0.0,b;
    struct pracownik p[n]; // struct pracownik jako typ

    scanf("%d\n",&n);

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

    FILE *f;
    if((f=fopen("opd.txt","w")) == NULL)
        printf("blad");


    for(int i = 0; i<n; i++)
    {
        fprintf(f,"%s ", p[i].imie);
        fprintf(f,"%s ", p[i].nazwisko);
        fprintf(f,"%d ", p[i].liczba_h);
        fprintf(f,"%d ", p[i].stawka);
        fprintf(f,"%f ", p[i].premia);
        a = p[i].stawka*p[i].liczba_h;
        b = a*p[i].premia/100;
        printf("stawka za osobe: %f",a+b);
        x += a+b;
        fprintf(f,"\n");
    }
    printf("%f",x);

    fclose(f);

    return 0;
}
