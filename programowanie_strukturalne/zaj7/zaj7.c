#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>



void szlaczek(int i, char j);

void srednia_liczb_parzystych(int a);

void lista_plac();

void czy_ciag_2();

float suma_szeregu(float kat, int n);

float sumaszer(float kat1, int n1)
{
    float xx = 1.0, x = kat1, sin1 = 0.00;
    for(int n = 1; n<=n1; n++)
    {
        xx *= x*x/2*n*((2*n)+1)*(-1);
        sin1 += xx;
    }
    return sin1;
}



int main()
{
    setlocale(LC_ALL,"");
    //7.2
    /*
    int x;
    char y;

    printf("Podaj dlugosc szlaczka: \n");
    scanf("%d",&x);
    printf("Podaj znak szlaczka: \n");
    scanf(" %c",&y); //podczas skanowania jednego chara warto walnac sb spacje przed % bo sie wywala inaczej (C kekw)

    szlaczek(x,y);
    */
    //7.3
    /*
    int n;
    printf("Podaj n: ");
    scanf("%d",&n);

    srednia_liczb_parzystych(n);
    */
    //7.4

    //lista_plac();

    //7.5

    //czy_ciag_2();

    float x;
    int k;

    printf("Podaj ilosc skladnikow sumy: ");
    scanf("%d",&k);

    printf("\nPodaj kat: ");
    scanf("%f",&x);

    printf("Wartosc dla podanych argumentow wynosi: %f\n",suma_szeregu(x,k)); //wymaga dopracowania (nie działa najlepiej XD)
    printf("Wartosc dla podanych argumentow wynosi: %f\n",sumaszer(x,k));    //teoretycznie dziala ale wsm czy poprawnie, jak rozmawialem z A. Gregosiewiczem zapewniał mnie o matematycznej poprawnosci, ale czy implementacja jest git to no chmmm (nwm)
                                                                            //btw Taylora to nie lubie jak cos, szczegolnie jego ciagu szeregu czy innego obiektyu matematycznego jak cos nie warto
    return 0;
}



void szlaczek(int i, char j)
{
    for(i;i>=1;i--)
    {
        printf("%c",j);
    }

    return; //not necessary, just for clear review of the code;
}

void srednia_liczb_parzystych(int a)
{
    int pom = 0, pom_1 = 0;

    for(int i = a;i>=1;i--)
    {

        printf("Podaj kolejna z n liczb: ");
        scanf("%d",&a);
        if(a%2==0)
        {
            pom+=a;
            pom_1++;
        }
    }

    printf("%f",(float)pom/pom_1); //(float) castuje dzielenie wartosci int gdzie wartosc po przecinku jest kasowana do floata dzieki czemu nie usuwamy tej czesci po przecinku (tak bardzo mniej wiêcej XD)

return;
}

void lista_plac()
{

    float nplaca(float placa)
    {
        if(placa<=5000)
            return placa+=placa*0.1;
        else return placa+=placa*0.05;
    }

    int n;

    printf("Podaj ilosc pracownikow: ");
    scanf("%d",&n);

    float place[n];

    for(int j=0;j<=n-1;j++)
    {
        printf("Podaj %d place: ",j+1);
        scanf("%f",&place[j]);
        place[j] = nplaca(place[j]);

        //printf("%f",place[j]); //DEBUG
    }

    //printf("+=== %d ===+",sizeof(place)); //DEBUG

    for(int i=0; i<=((sizeof(place)/sizeof(place[0]))-1);i++) //(sizeof(place)/sizeof(place[0]) wazna rzecz, zeby uzyskac rozmiat tablicy w c trzeba podzielic sizeof tablicy (ile bajtow zajmuje w pamieci) przez sizeof jednego elementu, wtedy otrzymamy ilosc elementow XD
    {
        printf("%d. placa wynosi teraz: %f\n",i+1,place[i]);
    }



    return;
}

void czy_ciag_2()
{
    int n, roznica;

    printf("Podaj n liczb: \n");
    scanf("%d",&n);
    if(n<3)
    {
        printf("to nie ciąg");
        return;
    }
    int tab[n];

    for(int i=0;i<n;i++)
    {
        printf("%d",i);
        printf("Podaj %d liczbe: \n",(i+1));
        scanf("%d",&tab[i]);
    }

    for(int j=0;j<n;j++)
    {
        if(j>0)
        {
            if(j>1)
            {
                //printf("poprzednia roznica: %d \n",roznica);
                if(roznica != tab[j] - tab[j-1])
                {
                    printf("nie jest xD");
                    return;
                }
            }
            roznica = tab[j] - tab[j-1];
            //printf("aktualna roznica: %d \n",roznica);
        }
    }
    printf("jest XD");
}

float suma_szeregu(float kat, int n) //wymaga dopracowania XD (kiedyś sie zrobi) (23.11.12)
{
    int silnia(int a)
    {
        int pom = 1;
        for(int j = 1; j<=a; j++)
            {
                pom*=j;
            }
    }

    float wynik = 0.0;
    int pomm,b;

    for(int i = 0; i <= n; i++)
    {
        b = (2*i)+1;
        pomm = silnia(b);
        wynik += pow(-1,i)/pomm*(pow(kat,(2*(i+1)) ));
    }

    return wynik;
}



/*void czy_ciag()
{
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
        return;
    }

    void quick_sort(int *tab, int lewy, int prawy)
    {

        if(prawy<=lewy)
           return;

        int i = lewy-1,
            j = prawy+1,
        pivot = tab[(lewy+prawy)/2];

            while(true)
        {
            while(pivot>tab[i++]);

            while(pivot<tab[i--]);

            if(i<=j)
                swap(&tab[i],&tab[j]);
            else
                break;

        }

        if(j>lewy)
            quick_sort(tab,lewy, j);
        if(i<prawy)
            quick_sort(tab,prawy,i);

        return;
    }

    int n;

  	printf("Ile liczb będziesz chciał posortować? ");
  	scanf("%d",&n);
  	int tab[n];
  	for(int i=0;i<n;i++)
    	scanf("%d",&tab[i]);

  	quick_sort(tab,0, n-1);

  	for(int i=0;i<n;i++)
        printf("%d",tab[i]);

    return;
}*/
