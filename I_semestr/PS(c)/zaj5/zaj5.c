#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>



float funkcja1(a)
{

    float b;

    if(a==8)
    {
        b = 1 - sin(a);
        return b;
    }

    else if(a==4||a==6||a==7)
    {
        return b = sqrt(pow(a,2)+1);
    }

    else if(a==1||a==2||a==3||a==0)
    {
        return b = (1+cos(a))/2;
    }
    return 0.123456; //debug

}

float funkcja2(a)
{
    float b;
    switch(a)
    {

    case 0:
        b = (1+cos(a))/2;
        break;

    case 1:
        b = (1+cos(a))/2;
        break;

    case 2:
        b = (1+cos(a))/2;
        break;

    case 3:
        b = (1+cos(a))/2;
        break;

    case 4:
        b = sqrt(pow(a,2)+1);
        break;

    case 6:
        b = sqrt(pow(a,2)+1);
        break;

    case 7:
        b = sqrt(pow(a,2)+1);
        break;

    case 8:
        b = 1 - sin(a);
        break;

    }
    return b;
}

bool czy_nalezy(float x, float y)
{
    if((x<=1&&y<=1)&&(x>=-1&&y>=-1))
        return true;
    else return false;
}

float pierwiastki()
{
    float a,b,c,delta,x0,x1,x2;

    printf("podaj a");
    scanf("%f",&a);
    printf("podaj a");
    scanf("%f",&b);
    printf("podaj a");
    scanf("%f",&c);

    delta = pow(b,2) - 4*a*c;
    //printf("%f\n",delta);

    if(delta<0)
    {
        printf("delta<0");
        return 0;
    }
    else if(delta==0)
    {
        x0 = (b*(-1))/(2*a);
        printf("%f",x0);
        return 0.5;
    }
    else if(delta>0)
    {
        x1 = ((-1)*b-sqrt(pow(b,2)-4*a*c))/(2*a);
        x2 = ((-1)*b+sqrt(pow(b,2)-4*a*c))/(2*a);

        printf("%f",x1);
        printf("%f",x2);
        return 1;
    }
    return 0.12345;
}

void pole_trojkata()
{
    float a,b,c;
    printf("podaj a");
    scanf("%f",&a);
    printf("podaj b");
    scanf("%f",&b);
    printf("podaj c");
    scanf("%f",&c);

    if(a+b>c&&a+c>b&&b+c>a)
    {
        float p = (a+b+c)/2;
        float P = sqrt(p*(p-a)*(p-b)*(p-c));
        printf("%f",P);

        return;
    }
    else
    {
        printf("nie ma takiego trojkata(boki)");
        return;
    }
    return;
}

void miesiac()
{
    int nr;
    scanf("%d",&nr);


    if(nr==2)
        printf("28 or 29\n");
    else if(nr==4||nr==6||nr==9||nr==11)
        printf("30\n");
    else //if(nr==1||nr==3||nr==5||nr==7||nr==8||nr==10||nr==12)
        printf("31\n");

    if(nr==1||nr==2||nr==3)
        printf("1 kwartal");

    else if(nr==4||nr==5||nr==6)
        printf("2 kwartal");

    else if(nr==7||nr==8||nr==9)
        printf("3 kwartal");

    else if(nr==10||nr==11||nr==12)
        printf("4 kwartal");

    return;
}


int main()
{
    /*
    int a;
    scanf("%d",&a);
    printf("%f\n",funkcja1(a));
    printf("%f\n",funkcja2(a));
    */

    /*
    float x,y;
    scanf("%f""%f",&x,&y);
    printf("%d",czy_nalezy(x,y));
    printf("%s",czy_nalezy(x,y) ? "true" : "false"); // ciekawe!
    */

    /*
    pierwiastki();
    */

    /*
    pole_trojkata();
    */

    /*
    miesiac();
    */

    return 0;
}
