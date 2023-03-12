#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>


void srednia_while()
{
    float srednia = 0.0;

    int n,pom,pom2;

    printf("podaj n:");
    scanf("%d",&n);

    pom = n;
    pom2 = n;

    while(pom!=0)
    {
        n=0;
        printf("podaj kolejna liczbe");
        scanf("%d",&n);
        srednia+=n;
        pom--;
    }

    srednia/=pom2;
    printf("%f",srednia);

    return;
}

void srednia_do_while()
{
    float srednia = 0.0;

    int n,pom,pom2;
    printf("podaj n:\n");
    printf("uwaga, nie wprowadzaj 0");
    scanf("%d",&n);

    pom = n;
    pom2 = n;

    do
    {
        n = 0;
        printf("podaj kolejna liczbe");
        scanf("%d",&n);
        srednia+=n;
        pom--;
    }while(pom!=0);

    srednia/=pom2;
    printf("%f",srednia);

    return;
}

void srednia_parz_nieparz()
{

    bool pom = 1;
    float pom1,ppom,npom;
    float sredp,sredn;

    while(pom)
    {
        printf("\nPodaj liczbe: ");
        scanf("%f",&pom1);
        if(pom1==0)
            pom = false;
        else
        {
            if((int)pom1%2==0) //castowanie(rzutowanie) zmienniej pom1 typu float do int, tylko na potrzeby tego warunku
            {
                ppom+=pom1;
                sredp++;
            }
            else
            {
                npom+=pom1;
                sredn++;
            }
        }
    }

    ppom/=sredp;
    npom/=sredn;

    printf("Srednia liczb parzystych to: %f\n",ppom);
    printf("Srednia liczb nieparzystych to: %f\n",npom);

return;
}

void ile_litery_x_oraz_ile_cyfr()
{

    char zdanie[216];
    char znak;

    int pom = 0, pom2 = 0;

    printf("Wprowadz zdanie zakoñczone kropk¹: \n(UWAGA! Maksymalna d³ugoœæ ci¹gu znaków to: 216)\n");
    scanf("%s", &zdanie);
    printf("WprowadŸ poszukiwany znak: ");
    scanf("%s", &znak);

    for(int i=0;i<=215;i++)
    {
        if((char)zdanie[i]==(char)'.')
            break;
        if((char)zdanie[i]==(char)znak)
            pom++;
        if((int)zdanie[i]>=48&&(int)zdanie[i]<=57)
            pom2++;

    }

    printf("Wystapienia poszukiwanego znaku: %d",pom);
    printf("Wystapienia cyfr: %d",pom2);

    return;
}

void maks()
{
    bool pom = true;
    float pom1, maxpom = FLT_MIN; //FLT_MIN to wartosc predefiniowana z pliku naglowkowego biblioteki standardowej float.h

    printf("Podawaj liczby, znakiem koñcz¹cym bêdzie: \"-1\".\n");

    while(pom)
    {
        printf("Podaj liczbe: ");
        scanf("%f",&pom1);
        printf("\n");

        if(pom1==(float)(-1))
            pom = false;
        else
        {
           if(pom1>=FLT_MIN)
           maxpom = pom1;
        }
    }
    printf("Najwieksza z podanych liczb to: %f",maxpom);

    return;
}



int main()
{

    setlocale(LC_ALL,"");
    /*
    srednia_while();

    srednia_do_while();
    */

    /*
    srednia_parz_nieparz();
    */

    /*
    ile_litery_x_oraz_ile_cyfr();
    */

    /*
    maks();
    */

    //6.6 zrobione wczesniej na przykladzie 4(?)/5(?) zadania xD



    return 0;
}
