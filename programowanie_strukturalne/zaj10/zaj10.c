#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>
//#include <vector>



int minimal(int tablica[],size_t dlug)
{
    int minimum;

    for(int i = 0; i<dlug; i++)
    {
        if(i == 0)
            minimum = *(tablica+i);
        if(*(tablica+i)<minimum)
            minimum = *(tablica+i);
    }
    return minimum;
}

float srednia(int tablica1[],size_t dlug)
{

    int wynik = 0;
    int pom = 0;


    for(int j = 0; j < dlug; j++)
    {
    wynik += *(tablica1+j);
    pom++;

    }

    float wynik2;
    wynik2 = (float)wynik/(float)pom;

    return wynik2;
}

int ile_wyst(int tablica[],size_t dlug,int szukana)
{
    int pom = 0;
    for(int i=0;i<dlug;i++)
    {
        if(*(tablica+i)==szukana)
            pom++;
    }
    return pom;
}

void zad10_3()
{

    int N,M;
    float suma,srednia;

    printf("Podaj N: ");
    scanf("%d",&N);
    printf("Podaj M: ");
    scanf("%d",&M);

    float tab[N][M];

    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            printf("Podaj liczbe do wpisania w rzedzie: %d, kolumnie %d",i+1,j+1);
            scanf(" %f",&*(*(tab+i)+j));
            suma += *(*(tab+i)+j);
            srednia++;
        }
        printf("\n");
    }

    for(int x = 0; x<N; x++)
    {
        for(int y = 0; y<M; y++)
        {
            printf("%6.3f, ",*(*(tab+x)+y)); //*(*(tab+x)+y) tab[x][y])
        }
        printf("\n");
    }
    srednia = suma/srednia;
    printf("Suma to: %f, srednia to: %f.\n",suma,srednia);

    return;
}

//not used, im done with that shit xD
void wczytaj(int rows,int columns,int *a)
{
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<columns; j++)
        {
            printf("Podaj wartosc komorki o wspolrzednych %dx%d: \n",i,j);
            scanf("%d", &a[i*columns+j]);
        }
    }
    return;
}

void twoja_stara(float *a,int N)//nienawidze tablic wielowymiarowqych w C (dzięki)
{

    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            printf("\nPodaj element znajdujacy sie w %dx%d komorce: ",i,j);
            scanf("%f",(a+i*N+j)); //j*N_i ta? działa? a szkoda myślałem że dodatkowe 12 h posiedze jeszcze
        }
    }

    return;
}

 double iloczyn(float *a,int N)
 {
    double wynik = 1.0;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            if(j==i)
                wynik*=*(a+i*N+j);
        }
    }
    return wynik;
 }

 float suma(float *a, int N)
 {

    double wynik = 0.0;
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            if(j>i)
                wynik+=*(a+i*N+j);
        }
    }

    return wynik;

 }

void kopiuj_1(int tab1[],int tab2[],int N) // mimo że praca na indexach przy passowaniu tablic do zewnętrznych funkcji to tak naprawde to samo co wskazniki i dziala tylko przy jednowymiarowych to dla widza zrobimy
{
    for(int i = 0; i<N; i++)
        {
        tab2[i] = tab1[i];
        }
    return;
}

void kopiuj_2(int *tab1,int *tab3,int N)
{
    for(int i = 0; i<N; i++)
        {
        *(tab3+i) = *(tab1+i); //tab2[i] = tab1[i];//*(tab2+i) = *(tab1+i);
        }
    return;
}

bool czy_zdali(int *tab1, int n,int prog)
{
    for(int i = 0; i<n; i++)
    {
    if(*(tab1+i)>=prog)
        continue;
    else
        return false;
    }
}





int main()
{

    //10.2
    /*

    int N = 5, iN = N,maxN,sumaN = 0,ilerazyN = 0,szukanyN,
        n,     in    ,maxn,suman = 0,ilerazyn = 0,szukanyn;


    printf("Podaj n: ");
    scanf("%d",&n);

    int tab1[N], tab2[n];



    //N
    printf("Podaj element szukany w tej tablicy: ");
    scanf("%d",&szukanyN);

    for(int i = 0; i<N; i++)
    {
        printf("\npodaj %d element tablicy o stalej dlugosci",(i+1));
        scanf("%d",&tab1[i]);

        if(i == 0)
        maxN = tab1[i];

        if(tab1[i]>maxN)
            maxN = tab1[i];

        sumaN += tab1[i];

        if(tab1[i]==szukanyN)
            ilerazyN++;
    }

    printf("\n=========TAB=========\n");
    for(int iN = 0; iN<N; iN++)
    {
        printf("%d, ",tab1[iN]);
    }
    printf("\n=========TAB=========\n");
    printf("maxymalny element to: %d\n",maxN);
    printf("suma to: %d\n",sumaN);
    printf("ilosc wystapien szukanego elementu to: %d\n",ilerazyN);

    printf("\n===================\n");




    //n
    printf("Podaj elemnet szukany w tej tablicy: ");
    scanf("%d",&szukanyn);

    for(int j = 0; j<n; j++)
    {
        printf("\npodaj %d element tablicy o zmiennej dlugosci",(j+1));
        scanf(" %d",&tab2[j]);

        if(j == 0)
        maxn = tab2[j];

        if(tab2[j]>maxn)
            maxn= tab2[j];

        suman += tab2[j];

        if(tab2[j]==szukanyn)
            ilerazyn++;
    }



    printf("\n=========TAB=========\n");
    for(int jn = 0; jn<n; jn++)
    {
        printf("%d, ",tab2[jn]);
    }
    printf("\n=========TAB=========\n");
    printf("maxymalny element to: %d\n",maxn);
    printf("suma to: %d\n",suman);
    printf("ilosc wystapien szukanego elementu to: %d\n",ilerazyn);

    printf("\n===================\n");
    */

    //10.3

    /*
    time_t t;

    srand((unsigned) time(&t));

    int n,a,b;

    printf("podaj n: ");
    scanf("%d",&n);

    printf("podaj b(szukana): ");
    scanf("%d",&b);

    int tab3[5] = {5,2,3,4,1},
        tab4[4] = {9,7,8,6},
        tab5[n];

    for(int i = 0; i<n; i++)
    {
        *(tab5 + i) = rand()%9;
        printf("%d\n",tab5[i]);
    }

    size_t t3 = sizeof(tab3) / sizeof(tab3[0]);
    size_t t4 = sizeof(tab4) / sizeof(tab4[0]);
    size_t t5 = sizeof(tab5) / sizeof(tab5[0]);

    printf("minimum z tablicy3 to: %d\n",minimal(tab3,t3));
    printf("minimum z tablicy4 to: %d\n",minimal(tab4,t4));
    printf("minimum z tablicy5 to: %d\n",minimal(tab5,t5));

    printf("srednia z tablicy3 to: %f\n",srednia(tab3,t3));
    printf("srednia z tablicy4 to: %f\n",srednia(tab4,t4));
    printf("srednia z tablicy5 to: %f\n",srednia(tab5,t5));

    printf("ilosc wystapien elementu z tablicy3 to: %d\n",ile_wyst(tab3,t3,b));
    printf("ilosc wystapien elementu z tablicy4 to: %d\n",ile_wyst(tab4,t4,b));
    printf("ilosc wystapien elementu z tablicy5 to: %d\n",ile_wyst(tab5,t5,b));

    */
    //10.3 cd
    //zad10_3();

    //10.4


    /* //(not used)
    //size_t = sizeof(tab[])/sizeof(tab[0]); tu nie zadzia³a, nie tedy droga
    int N;
    printf("podaj N: ");
    scanf("%d",&N);


    int *arr = malloc(N * N * sizeof(int));
    for(int i = 0; i < N * N; i++) {
           arr[i] = i;
       }

    wczytaj(arr,N,N);

    free(arr);
    */ //(not used)


    //10.4 właściwie
    /*
    int N;
    printf("podaj N: ");
    scanf("%d",&N);

    float tab[N][N];

    float *arr = tab;

    twoja_stara(arr,N);


    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            printf("%3.6f, ",tab[i][j]);
        }
        printf("\n");
    }

    printf("Iloczyn przekatnej wynosi: %lf\n",iloczyn(arr,N));
    printf("Suma ponad przekatna wynosi: %lf\n",suma(arr,N));
    */
    //10.5
    /*
    int N;
    printf("podaj N: ");
    scanf("%d",&N);

    int arr_1[N],   arr_2[N],    arr_3[N];
    int *a1 = arr_1, *a2 = arr_2, *a3 = arr_3;

    for(int i = 0; i<N; i++)
        {
            arr_1[i] = i;
            printf("%d\n",arr_1[i]);
        }

    kopiuj_1(arr_1,arr_2,N);  //indexy to wskaźniki wiec to nie ma sensu robi sie tak samo, bo indexy dzialaja tylko w 1 wymiarowaych tablicach lol, jakbym zrobil 2D arr to by sie cala narracja sypnela (cii),
    kopiuj_2(a1,a3,N);        //wskaźniki


    for(int j = 0; j<N; j++)
        {   printf("+===%d===+\n",j+1);
            printf("%d \n",arr_1[j]);
            printf("%d \n",arr_2[j]);
            printf("%d \n",arr_3[j]);
        }

    */
    //10.6
    /* nwm po co te dyrektywy preprocesora moze cos na wykladach bylo sensownego z nimi, zasadniczo useless w tym momencie (korzystania z pliku naglowkowego stdbool) xd
    int N,prog;
    printf("podaj N: ");
    scanf("%d",&N);

    int arr_1[N];
    int *a1 = arr_1;

    for(int i = 0; i<N; i++)
        {
            printf("\nPodaj %d wynik: ",i);
            scanf("%d",&arr_1[i]);
        }
    printf("\nPodaj wynik od ktorego (<=) studenci zaliczali egzamin");
    scanf("%d",&prog);

    if(czy_zdali(arr_1,N,prog))
        printf("yes");
    else
        printf("no");
    */

    return 0;
}
