#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TabliceDyn.h"

int x,y,z = 0;

int p = 0,r = 0; //p dod, r uj;


//Tutaj definiujesz funkcje do wykorzystania w mainie, do poprawnego dzia³ania potrzebny plik TabliceDyn.h

// rand
void losuj(int *tab, int n, int b, int c, int d) //wsk_tab, dlugosc_tab, limit_rand, dol_gra, gor_gra;
{
    srand( time( NULL ) );

    for(int i = 0; i<n; i++)
    {
        *(tab+i) = rand()%b;
        //printf("%d, ",*(tab+i));


        if( *(tab+i) >= c && *(tab+i) <= d )//if( (tab[0+i] >= c) &&  (tab[0+i] <= d) );//if( *(tab+i) >= c && *(tab+i) <= d );
        {
            //printf("liczba: %d jest wieksza od %d oraz mniejsza od %d \n",*(tab+i),c,d);
            //printf("XDDDD, ");
            z++;
        }
    }

    //printf("XDDDD 'z' = %d ",z);

    return;
}

// rand - check
int *chosen_tab(int *tab, int n, int a, int b)// wsk_tab, dlugosc_tab, przedzial_a, przedzial_b
{
    if(z == 0)
    {
        printf("memory error\n");
        exit(EXIT_FAILURE);
    }

    int *tab_in_range = (int*) malloc(z *sizeof(int));
    //printf("\nxDxXDXD %d \n",z);

    if(tab_in_range==NULL)
    {
        printf("memory error\n");
        exit(EXIT_FAILURE);
    }


    int pom = 0;
    for(int i = 0; i<n; i++)
    {
        if( *(tab+i)>= x && *(tab+i) <= y)
        {
            *(tab_in_range+pom) = *(tab+i);
            //printf("tab_in_range: %d, \n", *(tab_in_range+z));
            pom++;
        }
    }

return tab_in_range;
}

// 1 - dimension
float *new_tab_1D(int n)
{

    float *tab = (float*) malloc(n *sizeof(float));

    if(tab==NULL)
    {
        printf("memory error\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i<n; i++)
    {
        printf("Podaj %d liczbe w tabeli: ", i+1);
        scanf("%f", tab+i);
    }

return tab;
}

//2 - dimnesions
float *new_tab_2D(int n,int m)
{

    float *tab = (float*) malloc(n*m *sizeof(float));

    if(tab==NULL)
    {
        printf("memory error\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i<n; i++) //wiersze
    {
        for(int j = 0; j<m; j++)//kolumny
        {
            printf("\nPodaj wartosc dla komorki: %dx%d \n",i+1,j+1);
            scanf("%f",(tab+j+(i*m)));
        }
        printf("\n");
    }

return tab;
}

// PRINT
void print_tab(float *tab, int m, int n)
{
    for(int i = 0; i<n; i++) //wiersze
    {
        for(int j = 0; j<m; j++)//kolumny
        {
            printf("%f, ",*(tab+j+i*m));
        }
        //printf("\n");
    }

    return;
}

void print_tab_d(int *tab, int m, int n)
{
    for(int i = 0; i<n; i++) //wiersze
    {
        for(int j = 0; j<m; j++)//kolumny
        {
            printf("%d, ",*(tab+j+i*m));
        }
        //printf("\n");
    }

    return;
}

// DELETE
void delete_tab(float *tab)
{
    free(tab);
    tab = 0;

    return;
}

// ZAD 11.6
float *new_tab_2D_f(int n,int m)
{

    float *tab = (float*) malloc(n*m *sizeof(float));

    if(tab==NULL)
    {
        printf("memory error\n");
        exit(EXIT_FAILURE);
    }


    for(int i = 0; i<n; i++) //wiersze
    {
        for(int j = 0; j<m; j++)//kolumny
        {
            printf("\nPodaj wartosc dla komorki: %dx%d \n",i+1,j+1);
            scanf("%f",(tab+j+(i*m)));
            if(*(tab+j+(i*m)) == 0.0)
                continue;
            if(*(tab+j+(i*m)) > 0.0)
                p++;
       else if(*(tab+j+(i*m)) < 0.0)
                r++;

            printf("\n%d\n",p);
            printf("%d\n",r);
        }
        //printf("\n");

    }

return tab;
}

void f1(float *tab, int n, int m)
{

    float *tab_p = (float*) malloc(p* sizeof(float));

    if(tab_p==NULL)
    {
        printf("memory error\n");
        exit(EXIT_FAILURE);
    }

    int pom_p = 0;

    for(int i = 0; i<n; i++) //wiersze
    {
        for(int j = 0; j<m; j++)//kolumny
        {
            if( *(tab+j+(i*m)) <= 0.0)
                continue;
            if( *(tab+j+(i*m)) > 0.0 )
            {
                //printf("debug %f debug\n",(tab_p+pom_p));
                tab_p[pom_p] = *(tab+j+(i*m));
                pom_p++;

                //printf("\n%d\n",p);
                //printf("%d\n",r);
            }

        }

        //printf("\n");
    }


    printf("\n+=== NEW ===+\n");
    print_tab(tab_p,p,1);

    delete_tab(tab_p);

    return;// tab_p;
}

void f2(int *tab,int n,int  m)
{




    return;
}
