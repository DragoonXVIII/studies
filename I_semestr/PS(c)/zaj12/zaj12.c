#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


void zad12_4_imie_nazwisko()
{
    char tekst [80];
    char after_tekst[80];

    char spacja = {' '};

    int dlugosc,helpvar,lp;



    printf("Podaj tekst: ");
    gets(tekst);

    printf("do lewej: 1; do prawej: 0; podaj: ");
    scanf("%d",&lp);

    dlugosc = strlen(tekst);
    helpvar = (80 - dlugosc);

    printf("%d, ",dlugosc);
    printf("%d, ",helpvar);
    printf("\n");

    if(lp)
    {
        for(int i = 0; i<helpvar; i++)
        {
            after_tekst[i] = tekst[i];
        }
        for(int k = 0; k < (80 - helpvar); k++)
        {
            after_tekst[helpvar+ k] = spacja;
        }
    }
    else
    {

        for(int i = 0; i < (80 - dlugosc); i++)
        {
            after_tekst[i] = spacja;
        }
        int k = -1;
        for(k; k < helpvar; k++)
        {
            after_tekst[(80 - dlugosc) +k] = tekst[k+1];
        }
    }

    after_tekst[80] = '\0';


    fputs(after_tekst, stdout);


    return;
}

void zad12_4_wiersz() //turbo glupie rozwiazanie xDDDDDDDDDDDDDDDDDDDDDDDDDDDD
{
    char tekst_1[80] = {"Stoi na stacji lokomotywa,"};
    char tekst_2[80] = {"Ciê¿ka, ogromna i pot z niej sp³ywa:"};
    char tekst_3[80] = {"T³usta oliwa."};
    char tekst_4[80] = {"Stoi i sapie, dyszy i dmucha,"};
    char tekst_5[80] = {"¯ar z rozgrzanego jej brzucha bucha: "};
    char tekst_6[80] = {"Buch - jak gor¹co!"};
    char tekst_7[80] = {"Uch - jak gor¹co!"};

    char after_tekst[80];
    char spacja = {' '};

    //int dlugosci[7] = {26,36,13,29,37,18,17};
    int dlugosc,helpvar,lp,x;

    printf("do lewej: 1; do prawej: 0; podaj: ");
    scanf("%d",&lp);


    /*
    dlugosc = strlen(tekst_1);
    helpvar = (80 - dlugosc);

    printf("%d, ",dlugosc);
    printf("%d, ",helpvar);
    printf("\n");
    */




    dlugosc = strlen(tekst_1);
    helpvar = (80 - dlugosc);
    if(lp)
    {
        for(int i = 0; i<helpvar; i++)
        {
            after_tekst[i] = tekst_1[i];
        }
        for(int k = 0; k < (80 - helpvar); k++)
        {
            after_tekst[helpvar+ k] = spacja;
        }
    }
    else
    {

        for(int i = 0; i < (80 - dlugosc); i++)
        {
            after_tekst[i] = spacja;
        }
        int k = -1;
        for(k; k < helpvar; k++)
        {
            after_tekst[(80 - dlugosc) +k] = tekst_1[k+1];
        }
    }
    fputs(after_tekst, stdout);
    printf("\n");



    dlugosc = strlen(tekst_2);
    helpvar = (80 - dlugosc);
    if(lp)
    {
        for(int i = 0; i<helpvar; i++)
        {
            after_tekst[i] = tekst_2[i];
        }
        for(int k = 0; k < (80 - helpvar); k++)
        {
            after_tekst[helpvar+ k] = spacja;
        }
    }
    else
    {

        for(int i = 0; i < (80 - dlugosc); i++)
        {
            after_tekst[i] = spacja;
        }
        int k = -1;
        for(k; k < helpvar; k++)
        {
            after_tekst[(80 - dlugosc) +k] = tekst_2[k+1];
        }
    }
    fputs(after_tekst, stdout);
    printf("\n");



    dlugosc = strlen(tekst_3);
    helpvar = (80 - dlugosc);
    if(lp)
    {
        for(int i = 0; i<helpvar; i++)
        {
            after_tekst[i] = tekst_3[i];
        }
        for(int k = 0; k < (80 - helpvar); k++)
        {
            after_tekst[helpvar+ k] = spacja;
        }
    }
    else
    {

        for(int i = 0; i < (80 - dlugosc); i++)
        {
            after_tekst[i] = spacja;
        }
        int k = -1;
        for(k; k < helpvar; k++)
        {
            after_tekst[(80 - dlugosc) +k] = tekst_3[k+1];
        }
    }
    fputs(after_tekst, stdout);
    printf("\n");



    dlugosc = strlen(tekst_4);
    helpvar = (80 - dlugosc);
    if(lp)
    {
        for(int i = 0; i<helpvar; i++)
        {
            after_tekst[i] = tekst_4[i];
        }
        for(int k = 0; k < (80 - helpvar); k++)
        {
            after_tekst[helpvar+ k] = spacja;
        }
    }
    else
    {

        for(int i = 0; i < (80 - dlugosc); i++)
        {
            after_tekst[i] = spacja;
        }
        int k = -1;
        for(k; k < helpvar; k++)
        {
            after_tekst[(80 - dlugosc) +k] = tekst_4[k+1];
        }
    }
    fputs(after_tekst, stdout);
    printf("\n");



    dlugosc = strlen(tekst_5);
    helpvar = (80 - dlugosc);
    if(lp)
    {
        for(int i = 0; i<helpvar; i++)
        {
            after_tekst[i] = tekst_5[i];
        }
        for(int k = 0; k < (80 - helpvar); k++)
        {
            after_tekst[helpvar+ k] = spacja;
        }
    }
    else
    {

        for(int i = 0; i < (80 - dlugosc); i++)
        {
            after_tekst[i] = spacja;
        }
        int k = -1;
        for(k; k < helpvar; k++)
        {
            after_tekst[(80 - dlugosc) +k] = tekst_5[k+1];
        }
    }
   fputs(after_tekst, stdout);
   printf("\n");




    dlugosc = strlen(tekst_6);
    helpvar = (80 - dlugosc);
    if(lp)
    {
        for(int i = 0; i<helpvar; i++)
        {
            after_tekst[i] = tekst_6[i];
        }
        for(int k = 0; k < (80 - helpvar); k++)
        {
            after_tekst[helpvar+ k] = spacja;
        }
    }
    else
    {

        for(int i = 0; i < (80 - dlugosc); i++)
        {
            after_tekst[i] = spacja;
        }
        int k = -1;
        for(k; k < helpvar; k++)
        {
            after_tekst[(80 - dlugosc) +k] = tekst_6[k+1];
        }
    }
    fputs(after_tekst, stdout);
    printf("\n");



    dlugosc = strlen(tekst_7);
    helpvar = (80 - dlugosc);
    if(lp)
    {
        for(int i = 0; i<helpvar; i++)
        {
            after_tekst[i] = tekst_7[i];
        }
        for(int k = 0; k < (80 - helpvar); k++)
        {
            after_tekst[helpvar+ k] = spacja;
        }
    }
    else
    {

        for(int i = 0; i < (80 - dlugosc); i++)
        {
            after_tekst[i] = spacja;
        }
        int k = -1;
        for(k; k < helpvar; k++)
        {
            after_tekst[(80 - dlugosc) +k] = tekst_7[k+1];
        }
    }
    fputs(after_tekst, stdout);
    printf("\n");



    return;
}

void zad12_5()
{
    char a[100] = "Biblioteka";
    char b[] = "string.h";
    char c[] = "pozwala";
    char d[] = "na";
    char e[] = "zastosowanie";
    char f[] = "funkcji";
    char g[] = "do";
    char h[] = "lancuchow";
    char i[] = "znakowych.";
    char j[] = " ";
    char k[] = {'\n'};

    strcat(a,j);
    strcat(a,b);
    strcat(a,j);
    strcat(a,c);
    strcat(a,j);
    strcat(a,d);
    strcat(a,j);
    strcat(a,e);
    strcat(a,j);
    strcat(a,f);
    strcat(a,j);
    strcat(a,g);
    strcat(a,j);
    strcat(a,h);
    strcat(a,j);
    strcat(a,i);
    strcat(a,j);
    strcat(a,k);

    fputs(a,stdout);

    int dlugosc = strlen(a);
    printf("A dlugosc tego napisu to: %d",dlugosc);

}

void zad12_6()
{

    char tekst[80];
    gets(tekst);
    int dlugosc = strlen(tekst);
    int a;

    for(int i = 0; i<dlugosc; i++)
    {
        if( (int)tekst[i] >= 97  &&  (int)tekst[i] <= 122)
            {
                a = tekst[i];
                tekst[i] = a - 32;
            }
    }

    fputs(tekst,stdout);

    //65 - 90 caps // 97 - 122 normal //roznica 32
    return;
}



int main()
{
    setlocale(LC_ALL,"");
    /*
    char tekst [80];
    char after_tekst[80];

    char spacja = {' '};

    int dlugosc,helpvar;



    printf("Podaj tekst: ");
    gets(tekst);

    dlugosc = strlen(tekst);
    helpvar = (80 - dlugosc)/2;

    printf("%d, ",dlugosc);
    printf("%d, ",helpvar);
    printf("\n");





    for(int i = 0; i<helpvar; i++)
    {
        after_tekst[i] = spacja;
    }

    for(int j = 0; j<helpvar; j++)
    {
        after_tekst[helpvar + j] = tekst[j];
    }

    int k = 0;
    if(dlugosc + helpvar + helpvar != 80)
            k = -1;

    for(k; k<helpvar; k++)
    {

        after_tekst[80 - helpvar + k] = spacja;
    }

    after_tekst[80] = '\0';


    fputs(after_tekst, stdout);
    */

    //zad12_4_imie_nazwisko();
    //zad12_4_wiersz();
    //zad12_5();
    //zad12_6();





    return 0;
}
