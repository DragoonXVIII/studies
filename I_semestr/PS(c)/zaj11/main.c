#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>


//OWN
#include "TabliceDyn.h"


int x,y,z,p,r;


int main()
{
    //11.4
    /*
    int n, m;
    printf("Podaj n: ");
    scanf("%d",&n);

    printf("Podaj m: ");
    scanf("%d",&m);

    float *tab = new_tab_1D(n);
    float *tab_2 = new_tab_2D(n, m);

    print_tab(tab,n,1);
    print_tab(tab_2,n,m);

    delete_tab(tab);
    delete_tab(tab_2);
    */

    //11.5
    /*
    int tabS[100];
    int *tabSp = tabS;
    int *tab_in_range_ptr;
    printf("podaj dolnma granice: ");
    scanf(" %d",&x);
    printf("podaj gorna granice: ");
    scanf(" %d",&y);

    losuj(tabSp,100,100,x,y); //wsk_tab, dlugosc_tab, limit_rand, dol_gra, gor_gra;
    //printf("\nxD\n");
    print_tab_d(tabSp,1,100);
    printf("\n+=====================================+\n");
    *tab_in_range_ptr = chosen_tab(tabSp,100,x,y);
    print_tab_d(*tab_in_range_ptr,1,z);//chosen_tab(tabSp,100,x,y)
    */

    //11.6
    int n, m;
    printf("Podaj n: ");
    scanf("%d",&n);

    printf("Podaj m: ");
    scanf("%d",&m);

    float *tab = new_tab_2D_f(n, m);

    print_tab(tab, n, m);

    //printf("EOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOE");

    f1(tab,1,p);

    delete_tab(tab);

    return 0;
}
