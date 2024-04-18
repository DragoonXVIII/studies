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



using namespace std;
// +======================================================================PROPER FILE=========================================================================================+
/*struct RNS_number
{
    int modules[];
    int RNS[];
};*/

bool NWD_result = TRUE; //used by async NWD bool variable


int NWD(int a,int b) //standard NWD
{
    if(b==0)
    {
        return a;
    }
    return NWD(b,a%b);
}


void NWD_mt(int a, int b) //used by async NWD function
{
    if(b == 0)
        NWD_result = (a==1);
    else
        NWD_mt(b,a%b);
}


bool prime(int n)
{
    if (n<=1) return false;
    if (n<=3) return true;
    if ( n%2==0 || n%3==0 ) return false;
    for (int i = 5; i * i<=n;i+=6)
        {
            if ( n%i==0 ||n%(i+2)==0 )
            {
                return false;
            }
        }
    return true;
}


int modinv(int a,int m)
{
    int m0=m;
    int y=0, x=1;
    if(m==1)
        return 0;
    while (a>1)
    {
        int q=a/m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x<0)
        x+=m0;
    return x;
}


void c_NNtoRSN() // cout _ Natural Number to Residue Number System
{
    int number,nofmodules;

        cout<<"Podaj liczbe (pamietaj aby liczba miescila sie w 32 bitowym (Integer, max == 2,147,483,647) przedziale: ";
        if (!(cin >> number) || cin.fail())
        {
            cerr << "Blad: Niewlasciwa wartosc. Wprowadz odpowiednia wartosc zmiennej typu Integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); //'\n' wymagane dla ci¹g³oœci programu, bez przerywa pêtle main->while
            return;
        }


    //Test if number is in int range

    cout<<"Podaj liczbe modulow: ";
    cin>>nofmodules;

    int modules[nofmodules];

    cout<<"Podaj kolejne moduly, pamietaj ze moduly musza byc wzglednie pierwsze!"<<endl;
    for(int i=0;i<nofmodules;i++)
    {
        cout<<"Modul "<<i+1<<": ";
        cin>>modules[i];
    }

    //Test if all modules are coprime integers
    for(int i=0;i<nofmodules-1;i++)
    {
        for(int j=i+1;j<nofmodules;j++)
        {
            if( NWD(modules[i], modules[j]) != 1 )
            {
                cout << "Moduly nie sa wzglednie pierwsze." << endl;
                return;
            }
        }
    }

    int RNS[nofmodules];
    for(int i=0;i<nofmodules;i++)
    {
        RNS[i] = number%modules[i];
    }


    cout<<"Liczba: "<<number<<" w systemie RNS o podanych modulach wynosi: "<<endl;
    cout<<"(";
    for(int i=0;i<nofmodules;i++)
    {
        if(i==nofmodules-1)
            cout<<RNS[i];
        else
            cout<<RNS[i]<<", ";
    }
    cout<<")";

    cout<<" with MODULES [";
    for(int i=0;i<nofmodules;i++)
    {
        if(i==nofmodules-1)
            cout<<modules[i];
        else
            cout<<modules[i]<<", ";
    }
    cout<<"]"<<endl;

    return;
}


void c_NNtoRSNmt() // cout _ Natural Number to Residue Number System multithread (nie do koñca ale niech bêdzie xD) (async)
{

   /* WNIOSEK: Jeœli iloœæ modu³ów jest niska, ró¿nica w czasie wykonania mo¿e byæ nieznaczna, a nawet mo¿e byæ wiêcej czasu potrzebnego na tworzenie i zarz¹dzanie w¹tkami. */


    int number,nofmodules;

    //Test if number is in int range
    cout<<"Podaj liczbe (pamietaj aby liczba miescila sie w 32 bitowym (Integer, max == 2,147,483,647) przedziale: ";
    if (!(cin >> number) || cin.fail())
    {
        cerr << "Blad: Niewlasciwa wartosc. Wprowadz odpowiednia wartoœsc zmiennej typu Integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //'\n' wymagane dla ci¹g³oœci programu, bez przerywa pêtle main->while
        return;
    }



    cout<<"Podaj liczbe modulow: ";
    cin>>nofmodules;

    int modules[nofmodules];

    cout<<"Podaj kolejne moduly, pamietaj ze moduly musza byc wzglednie pierwsze!"<<endl;
    for(int i=0;i<nofmodules;i++)
    {
        cout<<"Modul "<<i+1<<": ";
        cin>>modules[i];
    }

    //Test if all modules are coprime integers using multithread (nie do koñca ale niech bêdzie xD) (async)

    vector <future<void>> NWD_futures;
    for(int i=0;i< nofmodules-1;i++)
    {
        for(int j = i + 1; j < nofmodules; j++)
        {
            NWD_futures.push_back(async(launch::async, NWD_mt, modules[i], modules[j]));
        }
    }

    for(auto &f:NWD_futures)
    {
        f.get();
    }



    if (!NWD_result)
    {
        cout << "Moduly nie sa wzglednie pierwsze." << endl;
        return;
    }

    /*
    int RNS[nofmodules];
    for(int i=0;i<nofmodules;i++)
    {
        RNS[i] = number%modules[i];
    }
    */


    auto modulo = [](int a, int b){return a%b;};

    vector <future<int>> RNS_futures;
    for(int i=0;i<nofmodules;i++)
    {
        RNS_futures.push_back(async(launch::async, modulo, number, modules[i]));
    }


    int RNS[nofmodules];
    for(int i=0;i<nofmodules;i++)
    {
        RNS[i] = RNS_futures[i].get();
    }


    cout<<"Liczba: "<<number<<" w systemie RNS o podanych modulach wynosi: "<<endl;
    cout<<"(";
    for(int i=0;i<nofmodules;i++)
    {
        if(i==nofmodules-1)
            cout<<RNS[i];
        else
            cout<<RNS[i]<<", ";
    }
    cout<<")";

    cout<<" with MODULES [";
    for(int i=0;i<nofmodules;i++)
    {
        if(i==nofmodules-1)
            cout<<modules[i];
        else
            cout<<modules[i]<<", ";
    }
    cout<<"]"<<endl;

    return;
}


int *NNtoRSN(int *modules,int nofmodules,int number) // Natural Number to Residue Number System
{

    //Test if all modules are coprime integers
    for(int i=0;i<nofmodules-1;i++)
    {
        for(int j=i+1;j<nofmodules;j++)
        {
            if( NWD(modules[i], modules[j]) != 1 )
            {
                cout << "Moduly nie sa wzglednie pierwsze." << endl;
                return  NULL;
            }
        }
    }

    int *ptr_RNS = (int*) malloc(nofmodules *sizeof(int));

    if(ptr_RNS==NULL)
    {
        cout<<("memory error\n");
        return NULL;
    }

    for(int i=0;i<nofmodules;i++)
    {
        ptr_RNS[i] = number%modules[i];
    }

    return ptr_RNS;
}


int *NNtoRSNmt(int *modules,int nofmodules,int number) // Natural Number to Residue Number System multithread (nie do koñca ale niech bêdzie xD) (async)
{
    //Test if all modules are coprime integers

    vector <future<void>> NWD_futures;
    for(int i=0;i< nofmodules-1;i++)
    {
        for(int j = i + 1; j < nofmodules; j++)
        {
            NWD_futures.push_back(async(launch::async, NWD_mt, modules[i], modules[j]));
        }
    }

    for(auto &f:NWD_futures)
    {
        f.get();
    }

    if (!NWD_result)
    {
        cout << "Moduly nie sa wzglednie pierwsze." << endl;
        return NULL;
    }

    //main purpouse of function

    auto modulo = [](int a, int b){return a%b;};
    vector <future<int>> RNS_futures;
    for(int i=0;i<nofmodules;i++)
    {
        RNS_futures.push_back(async(launch::async, modulo, number, modules[i]));
    }

    int *ptr_RNS = (int*) malloc(nofmodules *sizeof(int));
    for(int i=0;i<nofmodules;i++)
    {
        ptr_RNS[i] = RNS_futures[i].get();
    }

    return ptr_RNS;
}


int RNStoNN(vector <vector <int>> RNS_and_modules,int nofmodules) //Residue Number System to Natural Number
{
    int helpvar;
    int multofmodules_1[nofmodules],multofmodules[nofmodules];

    for(int i=0;i<nofmodules;i++)
        multofmodules[i]=1;

    for(int i=0;i<nofmodules;i++)
    {
        for(int j=0;j<nofmodules;j++)
        {
            if(j==i)
                continue;
            //RNS_and_modules+nofmodules+i;
            multofmodules[i]*=RNS_and_modules[1][j];
            helpvar = RNS_and_modules[1][j]%RNS_and_modules[1][i];
            multofmodules_1[i]*=helpvar;
        }
    }

    int k[nofmodules];
    int amodules_mult=1;
    long bufor=0;

    //dopiero tu mozna cos probowac optymalizowac
    for(int i = 0;i<nofmodules;i++)
    {

        k[i] = modinv(multofmodules[i],RNS_and_modules[1][i]);
        amodules_mult *= RNS_and_modules[1][i];
        bufor+=(k[i]*multofmodules[i]*RNS_and_modules[0][i]);
    }

    int number = bufor%amodules_mult;
    return number;
}

int RNStoNNmt(vector <vector <int>> RNS_and_modules,int nofmodules) //Residue Number System to Natural Number multithread
{
    int helpvar;
    int multofmodules_1[nofmodules],multofmodules[nofmodules];

    for(int i=0;i<nofmodules;i++)
        multofmodules[i]=1;

    for(int i=0;i<nofmodules;i++)
    {
        for(int j=0;j<nofmodules;j++)
        {
            if(j==i)
                continue;
            //RNS_and_modules+nofmodules+i;
            multofmodules[i]*=RNS_and_modules[1][j];
            helpvar = RNS_and_modules[1][j]%RNS_and_modules[1][i];
            multofmodules_1[i]*=helpvar;
        }
    }

    int k[nofmodules];
    int amodules_mult=1;
    long bufor=0;

    //dopiero tu mozna cos probowac optymalizowac
    /*
    for(int i = 0;i<nofmodules;i++)
    {

        k[i] = modinv(multofmodules[i],RNS_and_modules[1][i]);
        amodules_mult *= RNS_and_modules[1][i];
        bufor+=(k[i]*multofmodules[i]*RNS_and_modules[0][i]);
    }
    */

    vector<future<void>> futures;

    for(int j=0;j<nofmodules;j++)
    {
        futures.push_back(async(launch::async,
            [&k, &amodules_mult, &bufor, &multofmodules, &RNS_and_modules,&nofmodules]()
            {
                for (int i = 0; i < nofmodules; i++)
                {
                    k[i] = modinv(multofmodules[i], RNS_and_modules[1][i]);
                    amodules_mult *= RNS_and_modules[1][i];
                    bufor += (k[i] * multofmodules[i] * RNS_and_modules[0][i]);
                }
            }));
    }

    for (auto &fut : futures)
        fut.get();

    int number = bufor%amodules_mult;
    return number;
}


vector <vector<int>> v_NNtoRNS(int number,int nofmodules)    // funcja typu vector zwracajaca vector RNS i modulow w argumentach majaca liczbe i ilosc modulow, program sam d
{                                                                                       // w drugą stronę funkcja typu int zwracajaca liczbe w argumentach vector z rns i modulami
                                                                                    //dodawanie odejmowanie bedzie turno proste wtedy z wikipedii, potem mnozenie i nwm jak z dzieleniem :/, do zamiany w drugą strone mozna uzyc poprzedniej funkcji.
    vector <vector <int>> RNS_and_modules(2, vector<int>(nofmodules));
    int help=2,i=0;

    while(i<nofmodules)
    {
        if(prime(help))
        {
            RNS_and_modules[1][i]=help;
            i++;
        }
        help++;
    }



    for(int i=0;i<nofmodules;i++)
        {
            RNS_and_modules[0][i]=number%RNS_and_modules[1][i];
        }


        for(int i=0;i<nofmodules;i++)
        {
            cout<<"RNS: "<<RNS_and_modules[0][i]<<"modul: "<<RNS_and_modules[1][i]<<endl;
        }

return RNS_and_modules;
}

void delete_tab(int *tab)
{
    free(tab);
    tab = 0;

    return;
}



int main()
{

    setlocale(LC_ALL,"");

    while(true)
    {
        int action;
        cout<<"Co chcesz zrobic?"<<endl;
        cout<<endl<<"   +=== Konwersje ===+"<<endl;
        cout<<"1. Konwersja z liczby naturalnej na liczbe w RNS;"<<endl;
        cout<<"2. Konwersja z liczby naturalnej na liczbe w RNS przy uzyciu wielowatkowosci;"<<endl;
        cout<<"3. Porownanie czasowe powyzszych konwersji;"<<endl;
        cout<<"4. Konwersja z liczby w RNS na naturalna;"<<endl;
        cout<<"5. Konwersja z liczby w RNS na naturalna przy uzyciu wielowatkowosci;"<<endl;
        cout<<"6. Porownanie czasowe powyzszych konwersji;"<<endl;
        cout<<endl<<"   +=== Dzialania na liczbach RNS ===+"<<endl;
        cout<<"7. Dodawanie liczb z uzyciem RNS;"<<endl;
        cout<<"8. Odejmowanie liczb z uzyciem RNS;"<<endl;
        cout<<"9. Mnozenie liczb z uzyciem RNS;"<<endl;
        cout<<"10. Dzielenie liczb z uzyciem RNS;"<<endl;
        cout<<endl<<"   +=== Porownanie dzialan na liczbach RNS ===+"<<endl;
        cout<<"11.  Porownanie dodawania zwyklego i z uzyciem RNS;"<<endl;
        cout<<"12. Porownanie odejmowania zwyklego i z uzyciem RNS;"<<endl;
        cout<<"13. Porownanie mnozenia zwyklego i z uzyciem RNS;"<<endl;
        cout<<"14. Porownanie dzielenia zwyklego i z uzyciem RNS;"<<endl;
        cout<<"15. Zakoncz dzialanie programu;"<<endl;
        cout<<"99 test"<<endl;
        cout<<endl<<"Podaj odpowiednia liczbe aby przejsc do modulu. ";

        cin>>action;
        switch(action)
        {
        case 1: //1. Konwersja z liczby naturalnej na liczbe w RNS;
            c_NNtoRSN();
            break;

        case 2: //
            c_NNtoRSNmt();
            break;

        case 3:  //
            {
                //main
                auto start = chrono::high_resolution_clock::now();
                auto stop = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

                int number,nofmodules;

                //Test if number is in int range
                cout<<"Podaj liczbe (pamietaj aby liczba miescila sie w 32 bitowym (Integer, max == 2,147,483,647) przedziale: ";
                if (!(cin >> number) || cin.fail())
                {
                    cerr << "Blad: Niewlasciwa wartosc. Wprowadz odpowiednia wartosc zmiennej typu Integer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n'); //'\n' wymagane dla ci¹g³oœci programu, bez przerywa pêtle main->while
                    break;
                }

                cout<<"Podaj liczbe modulow: ";
                cin>>nofmodules;

                int modules[nofmodules];
                cout<<"Podaj kolejne moduly, pamietaj ze moduly musza byc wzglednie pierwsze!"<<endl;
                for(int i=0;i<nofmodules;i++)
                {
                    cout<<"Modul "<<i+1<<": ";
                    cin>>modules[i];
                }

                //Non optimized (I think so)
                int *ptr_modules = modules;

                start = chrono::high_resolution_clock::now();
                int *ptr_RNS = NNtoRSN(ptr_modules,nofmodules,number);
                stop = chrono::high_resolution_clock::now();
                duration = chrono::duration_cast<chrono::microseconds>(stop - start);

                if(ptr_RNS == 0)
                {
                    cout<<("memory error\n");
                    break;
                }

                    //Print
                    cout<<"+=== Zwykły RNS ===+"<<endl;
                    cout<<"Liczba: "<<number<<" w systemie RNS o podanych modulach wynosi: "<<endl;
                    cout<<"(";
                    for(int i=0;i<nofmodules;i++)
                    {
                        if(i==nofmodules-1)
                            cout<<ptr_RNS[i];
                        else
                            cout<<ptr_RNS[i]<<", ";
                    }
                    cout<<")";

                    cout<<" with MODULES [";
                    for(int i=0;i<nofmodules;i++)
                    {
                        if(i==nofmodules-1)
                            cout<<modules[i];
                        else
                            cout<<modules[i]<<", ";
                    }
                    cout<<"]"<<endl;
                    cout<<"Czas w ktorym wykonywala sie funkcja: "<<duration.count()<<" mikrosekund."<<endl;
                    delete_tab(ptr_RNS);


                //Optimized (I hope xD)

                start = chrono::high_resolution_clock::now();
                int *ptr_RNS_mt = NNtoRSNmt(ptr_modules,nofmodules,number);
                stop = chrono::high_resolution_clock::now();
                duration = chrono::duration_cast<chrono::microseconds>(stop - start);

                    //Print
                    cout<<"+=== Zoptymalizowany RNS ===+"<<endl;
                    cout<<"Liczba: "<<number<<" w systemie RNS o podanych modu³ach wynosi: "<<endl;
                    cout<<"(";
                    for(int i=0;i<nofmodules;i++)
                    {
                        if(i==nofmodules-1)
                            cout<<ptr_RNS_mt[i];
                        else
                            cout<<ptr_RNS_mt[i]<<", ";
                    }
                    cout<<")";

                    cout<<" with MODULES [";
                    for(int i=0;i<nofmodules;i++)
                    {
                        if(i==nofmodules-1)
                            cout<<modules[i];
                        else
                            cout<<modules[i]<<", ";
                    }
                    cout<<"]"<<endl;
                    cout<<"Czas w ktorym wykonywala sie funkcja: "<<duration.count()<<" mikrosekund"<<endl;

                delete_tab(ptr_RNS_mt);
                break;
            }

        case 4:  //
            {
                 //brak sprawdzania czy moduly i elementy sa poprawne

                int nofmodules;
                cout<<"Podaj ilosc modulow oraz elementow liczby RNS (jest to ta sama liczba, ilosc modulow jest rowna liczbie elementow potrzebnych do zapisu w RNS)"<<endl;
                cin>>nofmodules;

                int modules[nofmodules], RNS[nofmodules], multofmodules[nofmodules];
                for(int i=0;i<nofmodules;i++)
                {
                cout<<"Podaj "<<i+1<<" element liczby w RNS: ";
                cin>>RNS[i];
                }
                for(int i=0;i<nofmodules;i++)
                {
                cout<<"Podaj "<<i+1<<" modul liczby w RNS: ";
                cin>>modules[i];//15 , 16 ,17
                multofmodules[i] = 1;
                }

                //test if all modules are coprime integers
                bool coprime = true;
                for(int i=0;i<nofmodules-1;i++)
                {
                    for(int j=i+1;j<nofmodules;j++)
                    {
                        if( NWD(modules[i], modules[j]) != 1 )
                        {
                            cout<<"Moduly nie sa wzglednie pierwsze."<<endl;
                            coprime = false;
                            break;
                        }
                    }
                    if(!coprime) break;
                }
                if(!coprime) break;

                //optimized (use laws of arithmetic of remainders)
                int helpvar;
                int multofmodules_1[nofmodules];
                for(int i=0;i<nofmodules;i++)
                {
                    for(int j=0;j<nofmodules;j++)
                    {
                        if(j==i)
                            continue;
                        multofmodules[i]*=modules[j];
                        helpvar = modules[j]%modules[i];
                        multofmodules_1[i]*=helpvar;
                    }
                }

                int k[nofmodules];
                int amodules_mult=1;
                long bufor=0;

                //dopiero tu mozna cos probowac optymalizowac
                for(int i = 0;i<nofmodules;i++)
                {
                    k[i] = modinv(multofmodules[i],modules[i]);
                    amodules_mult *= modules[i];
                    bufor+=(k[i]*multofmodules[i]*RNS[i]);
                }

                int number = bufor%amodules_mult;

                cout<<"Podana przez ciebie liczba w systemie RNS:"<<endl;
                cout<<"(";
                for(int i=0;i<nofmodules;i++)
                {
                    if(i==nofmodules-1)
                        cout<<RNS[i];
                    else
                        cout<<RNS[i]<<", ";
                }
                cout<<")";
                cout<<" with MODULES [";
                for(int i=0;i<nofmodules;i++)
                {
                    if(i==nofmodules-1)
                        cout<<modules[i];
                    else
                        cout<<modules[i]<<", ";
                }
                cout<<"]"<<endl<<"w systemie dziesietnym wynosi: "<<number<<"."<<endl;

                break;
            }

        case 5: //
            {
                //main

                int nofmodules;
                cout<<"Podaj ilosc modulow oraz elementow liczby RNS (jest to ta sama liczba, ilosc modulow jest rowna liczbie elementow potrzebnych do zapisu w RNS)"<<endl;
                cin>>nofmodules;

                int modules[nofmodules], RNS[nofmodules], multofmodules[nofmodules];

                for(int i=0;i<nofmodules;i++)
                {
                cout<<"Podaj "<<i+1<<" element liczby w RNS: ";
                cin>>RNS[i];
                }
                cout<<"Podaj kolejne moduly, pamietaj ze moduly musza byc wzglednie pierwsze!"<<endl;
                for(int i=0;i<nofmodules;i++)
                {
                    cout<<"Modul "<<i+1<<": ";
                    cin>>modules[i];
                }

                //test if all modules are coprime integers
                bool coprime = true;
                for(int i=0;i<nofmodules-1;i++)
                {
                    for(int j=i+1;j<nofmodules;j++)
                    {
                        if( NWD(modules[i], modules[j]) != 1 )
                        {
                            cout<<"Moduly nie sa wzglednie pierwsze."<<endl;
                            coprime = false;
                            break;
                        }
                    }
                    if(!coprime) break;
                }
                if(!coprime) break;

                vector <vector <int>> RNS_and_modules(2);
                for(int i=0;i<nofmodules;i++)
                {
                RNS_and_modules[0].push_back(RNS[i]);
                RNS_and_modules[1].push_back(modules[i]);
                }

                int number = RNStoNN(RNS_and_modules,nofmodules);

                cout<<"Podana przez ciebie liczba w RNS w systemie dziesietnym wynosi: "<<number<<endl;
                break;
            }

        case 6: //do dopracowania!!
            {
                //main
                auto start = chrono::high_resolution_clock::now();
                auto stop = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

                int nofmodules;
                cout<<"Podaj ilosc modulow oraz elementow liczby RNS:"<<endl<<"(jest to ta sama liczba, ilosc modulow jest rowna liczbie elementow potrzebnych do zapisu w RNS)"<<endl;
                cin>>nofmodules;

                int modules[nofmodules], RNS[nofmodules], multofmodules[nofmodules];

                for(int i=0;i<nofmodules;i++)
                {
                cout<<"Podaj "<<i+1<<" element liczby w RNS: ";
                cin>>RNS[i];
                }
                cout<<"Podaj kolejne moduly, pamietaj ze moduly musza byc wzglednie pierwsze!"<<endl;
                for(int i=0;i<nofmodules;i++)
                {
                    cout<<"Modul "<<i+1<<": ";
                    cin>>modules[i];
                }

                //test if all modules are coprime integers
                bool coprime = true;
                for(int i=0;i<nofmodules-1;i++)
                {
                    for(int j=i+1;j<nofmodules;j++)
                    {
                        if( NWD(modules[i], modules[j]) != 1 )
                        {
                            cout<<"Moduly nie sa wzglednie pierwsze."<<endl;
                            coprime = false;
                            break;
                        }
                    }
                    if(!coprime) break;
                }
                if(!coprime) break;

                vector <vector <int>> RNS_and_modules(2);
                for(int i=0;i<nofmodules;i++)
                {
                RNS_and_modules[0].push_back(RNS[i]);
                RNS_and_modules[1].push_back(modules[i]);
                }

                start = chrono::high_resolution_clock::now();
                int number = RNStoNN(RNS_and_modules,nofmodules);
                stop = chrono::high_resolution_clock::now();
                duration = chrono::duration_cast<chrono::microseconds>(stop - start);

                cout<<"Podana przez ciebie liczba w RNS w systemie dziesietnym wynosi: "<<number<<endl;
                cout<<"Obliczenia bez uzycia funkcji async trwaly: "<<duration.count()<<endl;

                start = chrono::high_resolution_clock::now();
                number = RNStoNNmt(RNS_and_modules,nofmodules);
                stop = chrono::high_resolution_clock::now();
                duration = chrono::duration_cast<chrono::microseconds>(stop - start);

                cout<<"Podana przez ciebie liczba w RNS w systemie dziesietnym wynosi: "<<number<<endl;
                cout<<"Obliczenia z uzyciem funkcji async trwaly: "<<duration.count()<<endl;


                //





                break;
            }

        case 7: //
            {
                int liczba_1, liczba_2, wynik, nofmodules;

                cout<<"Podaj 1 liczbe: ";
                cin>>liczba_1;

                cout<<"Podaj 2 liczbe: ";
                cin>>liczba_2;

                cout<<"Podaj oczekiwana ilosc modulow: ";
                cin>>nofmodules;
                cout<<"Komputer sam utworzy moduly z kolejnych liczb pierwszych."<<endl;

                vector <vector <int>> RNS_and_modules_1(2,vector <int>(nofmodules));
                vector <vector <int>> RNS_and_modules_2(2,vector <int>(nofmodules));
                vector <vector <int>> RNS_and_modules_wynik(2,vector <int>(nofmodules));

                RNS_and_modules_1 = v_NNtoRNS(liczba_1,nofmodules);
                RNS_and_modules_2 = v_NNtoRNS(liczba_2,nofmodules);

                for(int i=0;i<nofmodules;i++)
                {
                    /*if(RNS_and_modules_1[1][i]==(RNS_and_modules_1[0][i]+RNS_and_modules_2[0][i]))
                        RNS_and_modules_1[0][i]=1;
                    else
                        RNS_and_modules_wynik[0][i] = (RNS_and_modules_1[0][i]+RNS_and_modules_2[0][i])%RNS_and_modules_1[1][i];*/
                    RNS_and_modules_wynik[0][i] = (RNS_and_modules_1[0][i]+RNS_and_modules_2[0][i])%RNS_and_modules_1[1][i];
                    RNS_and_modules_wynik[1][i] = RNS_and_modules_1[1][i];
                    //if(RNS_and_modules_wynik[0][i]==0)
                    //    RNS_and_modules_wynik[0][i]=1;
                    cout<<"wynik RNS: "<<RNS_and_modules_wynik[0][i]<<"wynik modulo: "<<RNS_and_modules_wynik[1][i]<<endl;
                }



                //cout<<"test_1"<<endl;

                wynik = RNStoNN(RNS_and_modules_wynik,nofmodules);
                cout<<"Wynik tego dodawania to: "<<wynik<<endl;
                break;
            }

        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            return 0;
        case 99:
            {



                break;
            }

        }
        NWD_result = TRUE;
        system("pause");
        system("cls");
    }
    return 0;
}





    /*int modul;
    bool ok == true;

    cout<<"Podaj moduly przy pomocy ktorych chcesz przedstawic liczbe(10) jako liczbe(RNS): "<<endl;
    while(ok)
    {
        cin>>modul;
        if(modul == NULL)
            ok == false;

        moduly.push_back(modul);
        modul = NULL;
    */
