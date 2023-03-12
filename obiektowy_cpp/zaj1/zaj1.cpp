#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <ctype.h>
#include <algorithm>
#include <string>
#include <conio.h>
#include <vector>
#include <locale.h>
#include <thread>
#include <future>
#include <chrono>
#include <iomanip>


namespace kolega1
{
    char imie[] = "Bolek";
    int wiek = 20;
}

namespace kolega2
{
    char imie[] = "Lolek";
    int wiek = 21;
}



using namespace std;
using namespace kolega1;


int main()
{

    cout<<"Hello World"<<endl;
    cout<<imie<<wiek<<endl;
    cout<<kolega2::imie<<kolega2::wiek<<endl;

    int a;
    float b;
    double c;
    char d;
    char e[20];

    scanf("%d %f %lf %c %s",&a,&b,&c,&d,e);
    printf("%d, %0.3f, %lf, %c, %s\n",a,b,c,d,e);

    cin>>a>>b>>c>>d>>e;
    cout<<a<<", "<<setprecision(3)<<b<<", "<<c<<", "<<d<<", "<<e;

    return 0;
}
