#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#define STUDENT "student"
#define SREDNIA 4.5

//bledy w tekscie nie maja znaczenia jak cos, kwestia ze zle kodowanie raz ustawilem, nie chce mi sie poprawiac

void dane_studenta() //fukncja typu void - nie zwraca argumentu,
{
    char imie[20];
    char nazwisko[20];
    char plec[20];

    scanf("%s",imie);
    scanf("%s",nazwisko);
    scanf("%s",plec);

    printf("%s",imie);
    printf("%s",nazwisko);
    printf("%s",plec);
    printf("%s",STUDENT);
    printf("%f",SREDNIA);

    return;
}

void objetosc_i_pole_powierzchni() // funcja void sluzaca za "menu" do wykorzystania pozostalych funkcji
{
    int index;
    printf("Aby policzy�:\n - pole powierzchni sze�cianu / prostopad�o�cianu wprowad� \"1\" \n - obj�to�� sze�cianu / prostopad�o�cianu wprowad� \"2\" \n - pole powierzchni walca wprowad� \"3\" \n - obj�to�� walca wprowad� \"4\" \n oraz zatwierd� klikaj�c ENTER\n");
    scanf("%d",&index);
    switch(index)
    {

    case 1:
        fppp();
        break;

    case 2:
        fop();
        break;

    case 3:
        ppw();
        break;

    case 4:
        ow();
        break;

    }

    return;
}

    void fppp()//pole powierzchni sze�cianu / prostopad�o�cianu
{
    int a,b,c,ppp;

    printf("Podaj a:\n");
    scanf("%d",&a);
    printf("Podaj b:\n");
    scanf("%d",&b);
    printf("Podaj c:\n");
    scanf("%d",&c);;

    ppp = a*b*2+a*c*2+b*c*2;

    printf("%d\n",ppp);
    return;
}

    void fop()//obj�to�� sze�cianu / prostopad�o�cianu
{
    int a,b,c,op;

    printf("Podaj a:\n");
    scanf("%d",&a);
    printf("Podaj b:\n");
    scanf("%d",&b);
    printf("Podaj c:\n");
    scanf("%d",&c);

    op = a*b*c;

    printf("%d\n",op);
    return;
}

    void ppw()//pole powierzchni walca
{
    int r,h;
    float pi=3.14,ppw;

    printf("Podaj h:\n");
    scanf("%d",&h);
    printf("Podaj r:\n");
    scanf("%d",&r);

    ppw = 2*pi*r*h;

    printf("%f\n",ppw);
    return;
}

    void ow()//obj�to�� walca
{
    int r,h;
    float pi=3.14,ow;

    printf("Podaj h:\n");
    scanf("%d",&h);
    printf("Podaj r:\n");
    scanf("%d",&r);

    ow = pi*(pow(r,2))*h;

    printf("%f\n",ow);
    return;
}

void srednia_ary()//�rednia arytmetyczna
{
    int x,y;

    scanf("%d",&x);
    scanf("%d",&y);

    float srednia_arytmetyczna = ((float)x+(float)y)/2.0;

    printf("%f\n",srednia_arytmetyczna);
    return;
}

void srednia_geo()//�rednia geometryczna
{
    int x,y;

    scanf("%d",&x);
    scanf("%d",&y);

    float srednia_geometryczna = sqrt(x*y);

    printf("%f\n",srednia_geometryczna);
    return;
}

void przeliczanie_wielkosci_fizycznych() // ponownie funcja void sluzaca za "menu" do wykorzystania pozostalych funkcji
{
    int index;
    printf("Aby skorzysta� z funkcji przeliczaj�cych:\n - z mil na kilometry, wprowad� \"1\" \n - z kilometr�w na mile, wprowad� \"2\" \n - z koni mechanicznych [KM] na waty [W], wprowad� \"3\" \n - z kilometr�w na godzin� [km/h] na metry na sekund� [m/s], wprowad� \"4\" \n - ze stopni Fahrenheita [oF] na stopnie Celsjusza [oC], wprowad� \"5\" \n oraz zatwierd� klikaj�c ENTER\n");
    scanf("%d",&index);
    switch(index)
    {

    case 1:
        miletokm();
        break;

    case 2:
        kmtomile();
        break;

    case 3:
        KMtoW();
        break;

    case 4:
        kmhtoms();
        break;

    case 5:
        FtoC();
        break;

    }
    return;
}

    void miletokm()//mile na km
{
    int pom;
    float pom2;

    scanf("%d",&pom);

    pom2 = pom*0.625;

    printf("%f",pom2);

    return;
}

    void kmtomile()//km na mile
{
    int pom;
    float pom2;

    scanf("%d",&pom);

    pom2 = pom*1.6;

    printf("%f",pom2);
    return;
}

    void KMtoW()// konie miechaniczne na waty
{
    int pom;
    long pom3;

    scanf("%d",&pom);

    pom3 = pom*735;

    printf("%ld",pom3);

    return;
}

    void kmhtoms()// km/h na m/s
{
    int pom;
    float pom2;

    scanf("%d",&pom);

    pom2 = pom*0.28;

    printf("%f",pom2);
    return;
}

    void FtoC()//farenheit'y do celsjuszy
{
    int pom;
    float pom2;

    scanf("%d",&pom);

    pom2 = (pom-32)*5/9;

    printf("%f",pom2);
    return;
}

void wiek_w_przyszlosci()//wiek za x miesiecy
{
    int wiekl,wiekm,czas,ile_lat,ile_mies;

    scanf("%d",&wiekl);
    scanf("%d",&wiekm);
    scanf("%d",&czas); //w miesiacach!

    ile_lat = czas/12;
    ile_mies = czas%12;

    ile_lat+=wiekl;
    ile_mies+=wiekm;

    if(ile_mies>=12)
    {
    ile_mies-=12;
    ile_lat++;
    }

    printf("%d\n",ile_lat);
    printf("%d\n",ile_mies);
    return;
}



//system("cls"); funkcja odpowiedzialna za czyszczenie zawartosci konsoli z wyswietlonych juz obiektow.

int main()
{
    setlocale(LC_ALL,"");

    bool koniec = false;
    int pom;
    while(!koniec)
    {
        int index;

        printf("Aby skorzysta� z konkretnych modu��w wpisz odpowiedni� liczb� i zatwierd� klikaj�c ENTER\n");
        printf("1 - modu� dane studenta\n");
        printf("2 - modu� obliczania obj�to�ci i pola powierzchni bry�\n");
        printf("3 - modu� obliczania �redniej arytmetycznej dw�ch liczb ca�kowitych\n");
        printf("4 - modu� obliczania �redniej geometrycznej dw�ch liczb ca�kowitych\n");
        printf("5 - modu� przeliczania wielko�ci fizycznych\n");
        printf("6 - modu� kalkulowania wieku w przysz�o��i\n");
        //printf("n - /n");

        scanf("%d",&index);
        switch(index)
        {
        case 1:
            system("cls");
            dane_studenta();
            break;

        case 2:
            system("cls");
            objetosc_i_pole_powierzchni();
            break;

        case 3:
            system("cls");
            srednia_ary();
            break;

        case 4:
            system("cls");
            srednia_geo();
            break;

        case 5:
            system("cls");
            przeliczanie_wielkosci_fizycznych();
            break;

        case 6:
            system("cls");
            wiek_w_przyszlosci();
            break;

        }

    printf("Czy chcesz ponownie skorzysta� z programu?\n 1 - TAK \n 2 - NIE\n");

    if(scanf("%d",&pom)!=1)
        koniec = false;

    system("cls");
    }


return 0;
}


