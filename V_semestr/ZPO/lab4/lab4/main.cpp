#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>

#include "even.h"
#include "compare.h"
#include "city.h"
#include "set"

int sumaCyfr(int liczba)
{
    liczba = std::abs(liczba);
    int suma = 0;
    while (liczba > 0)
    {
        suma += liczba % 10;
        liczba /= 10;
    }
    return suma;
}
int liczbaCyfr(int liczba)
{
    if (liczba == 0) return 1;
    liczba = std::abs(liczba);
    int licznik = 0;
    while (liczba > 0)
    {
        licznik++;
        liczba /= 10;
    }
    return licznik;
}

template <typename T>
void show(T &con)
{
    for(typename T::iterator it=con.begin( );
        it!=con.end( ); it++)
        std::cout<<*it<<" ";
    std::cout<<std::endl;
}
void print(int& el)
{
    std::cout<<el<<"***";
}
void add10(int &el)
{
    el=el+10;
}
bool isEven(int x)
{
    if(x%2 == 0)
        return true;
    else
        return false;
}
void showMark(Student &s)
{
    cout<<s.getMark()<<" ";
}

void showCities(const std::vector<City>& cities)
{
    for (const auto& city : cities)
    {
        std::cout << "City: ";
        city.show_city();
        std::cout << "Population: " << city.getCityCitizens() << std::endl;
    }
}

void sort_cities(std::vector<City> &cities)
{
    std::sort(cities.begin(), cities.end(),[](const City& a, const City& b)
    {
        return a.getCityCitizens() < b.getCityCitizens();
    });
}

void the_most( std::vector<City>& cities, int mode) {
    if (cities.empty())
    {
        std::cout << "No cities to search." << std::endl;
        return;
    }
    if (mode == 1)
    {
        std::cout<<"MODE 1"<<std::endl;
        City tmp = cities.at(0);
        for(int i=1; i<cities.size(); i++)
        {
            if(cities.at(i).uniquePostalCodes()>tmp.uniquePostalCodes())
                tmp = cities.at(i);
        }
        tmp.show_city();
    }
    else if (mode == 2)
    {
        sort_cities(cities);
        std::cout<<"MODE 2"<<std::endl;
        cities.at(0).show_city();
        std::cout<<"Liczba mieszkancow: "<<cities.at(0).getCityCitizens();
    }
    else
    {
        std::cout << "Invalid mode selected." << std::endl;
    }
}


void statistic(const std::vector<City>& cities) {
    for (const auto& city : cities) {
        int maleCount = city.getMen();
        int femaleCount = city.getWomen();
        int adultCount = city.getAdults();

        std::cout << "City: "; city.show_city();
        std::cout << "Total Citizens: " << city.getCityCitizens() << std::endl;
        std::cout << "Males: " << maleCount << ", Females: " << femaleCount << std::endl;
        std::cout << "Adults: " << adultCount << std::endl;
        std::cout << "----------------------------" << std::endl;
    }
}



void zad1()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    std::cout<<"Operator[]"<<std::endl;
    for(int i=0; i<vec.size(); i++)
    {
        std::cout<<vec[i]<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"At"<<std::endl;
    for(int i=0; i<vec.size(); i++)
    {
        std::cout<<vec.at(i)<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Iterator: "<<std::endl;
    std::vector <int>::iterator it;

    for(it=vec.begin(); it != vec.end(); it++ )
    {
        std::cout <<*it<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"begin() "<< *vec.begin()<<" front() "<<vec.front()<<std::endl;
    std::cout<<"end() "<< *(vec.end()-1)<<" back() "<<vec.back()<<std::endl;

    show(vec);
    vec.pop_back();
    show(vec);
    vec.erase(vec.begin()+1,vec.begin()+2);
    show(vec);
    vec.insert(vec.begin()+1,100);
    show(vec);
    vec.clear();
    show(vec);

    std::vector<float>vec2(5,8.2);
    show(vec2);
    vec2.push_back(3.1);
    show(vec2);


    std::vector<int>num={3,6,3,8,9,1,3};
    show(num);
    sort(num.begin(),num.end());
    show(num);
    std::cout<<"binary search"<<std::endl;
    std::cout<<binary_search(num.begin(),num.end(),3)<<std::endl;
    std::cout<<"count"<<std::endl;
    std::cout<<count(num.begin(),num.end(),3)<<std::endl;
    std::cout<<"reverse"<<std::endl;
    reverse(num.begin(),num.begin()+4);
    show(num);
    std::cout<<"random_shuffle"<<std::endl;
    random_shuffle(num.begin(),num.end());
    show(num);
    std::cout<<"max element"<<std::endl;
    std::cout<<*max_element(num.begin(),num.end())<<std::endl;
    std::cout<<"merge"<<std::endl;
    std::vector<int>num2(4,6);
    std::vector<int>res(num.size()+num2.size());
    sort(num.begin(),num.end());

    merge(num.begin(),num.end(),num2.begin(),
          num2.end(),res.begin());
    show(res);

    for_each(num.begin(),num.end(),print);
    for_each(num.begin(),num.end(),add10);
    std::cout<<std::endl;
    for_each(num.begin(),num.end(),print);
    std::cout<<std::endl;
    std::cout<<count_if(num.begin(),num.end(),isEven);
    std::vector<int> num3={2, -6, 7, 3, 0, 8, -9, -2};
    for_each(num3.begin(),num3.end(),print);
    int howMany=count_if(num3.begin( ), num3.end( ), bind2nd(std::greater<int>( ),0));
    std::cout<<std::endl<<"wersja1: wartosc > 0  "<<howMany<<std::endl;

    std::greater<int> f;
    howMany=count_if(num3.begin( ), num3.end( ), bind2nd(f,0));
    std::cout<<"wersja2: wartosc > 0  "<<howMany<<std::endl;
    std::cout<<"Przed sortowaniem"<<std::endl;
    for_each(num3.begin(),num3.end(),print);
    sort(num3.begin( ), num3.end( ), std::greater<int>());
    std::cout<<std::endl<<"Po sortowaniu"<<std::endl;
    for_each(num3.begin(),num3.end(),print);
    std::cout<<std::endl;

    for_each(num.begin(),num.end(),print);
    std::cout<<std::endl;
    std::cout<<count_if(num.begin(),num.end(),isEven)<<std::endl;
    std::cout<<count_if(num.begin(),num.end(),Even(2))<<std::endl;

    vector<Student>st;
    st.push_back(Student(1,"Ala"));
    st.push_back(Student(5,"Ola"));
    st.push_back(Student(2,"Piotr"));
    for_each(st.begin(),st.end(),showMark);
    cout<<endl;
    sort(st.begin(),st.end(),Compare());
    for_each(st.begin(),st.end(),showMark);




    return;
}

void zad2()
{
    std::srand(std::time(nullptr));
    int n = std::rand() % 20 + 1;
    std::cout << "Wylosowana liczba n: " << n << std::endl;

    std::vector<int> liczby;

    for (int i = 0; i < n; ++i)
    {
        int liczba = std::rand() % 201 - 100;
        if (liczba >= 0)
        {
            liczby.insert(liczby.begin(), liczba);
        } else
        {
            liczby.push_back(liczba);
        }
    }

    std::cout << "Zawartosc listy: ";
    for (int liczba : liczby)
    {
        std::cout << liczba << " ";
    }
    std::cout << std::endl;

    return;
}

void zad3()
{
    /*
    City Lublin("Lublin");
    // 200 2m 1f 2a
    Lublin.addCitizen(Citizen("Jan","Kowalksi",30,'m',"20-200"));//dom 1
    Lublin.addCitizen(Citizen("Janina","Kowalksa",29,'f',"20-200"));//dom 1
    Lublin.addCitizen(Citizen("Jas","Kowalksi",8,'m',"20-200"));//dom 1
    Lublin.addCitizen(Citizen("Krzysztof","Rozpara",22,'m',"20-300"));//dom 2
    Lublin.addCitizen(Citizen("Katarzyna","Cimoszewicz",21,'f',"20-300"));//dom 2
    Lublin.addCitizen(Citizen("Kacper","Starachowski",20,'m',"20-400"));//dom 3

    Lublin.show_city();
    Lublin.show_citizens();

    std::cout<<"\n\n\n";

    std::cout<<"Mieszkancy: "<<Lublin.getCityCitizens()<<std::endl;
    std::cout<<"M: "<<Lublin.getMen()<<" W: "<<Lublin.getWomen()<<" A: "<<Lublin.getAdults()<<std::endl;

    Lublin.deleteCitizen("Jas","Kowalksi");
    Lublin.deleteCitizen("Kacper","Starachowski");

    //Lublin.show_city();
    //Lublin.show_citizens();
    std::cout<<"Mieszkancy: "<<Lublin.getCityCitizens()<<std::endl;
    std::cout<<"M: "<<Lublin.getMen()<<" W: "<<Lublin.getWomen()<<" A: "<<Lublin.getAdults()<<std::endl;
    */
    vector <City> cities;
    cities.push_back(City("Lublin")); //2
    cities.push_back(City("Krakow")); //1
    cities.push_back(City("Warszawa")); //0
    cities.at(0).addCitizen(Citizen("Jan","Kowalksi",30,'m',"20-200"));
    cities.at(0).addCitizen(Citizen("Jan","Kowalksi",2,'f',"20-200"));
    cities.at(0).addCitizen(Citizen("Jan","Kowalksi",30,'m',"20-200"));
    cities.at(2).addCitizen(Citizen("Jan","Kowalksi",10,'f',"20-200"));
    cities.at(2).addCitizen(Citizen("Jan","Kowalksi",30,'m',"20-200"));
    cities.at(1).addCitizen(Citizen("Jan","Kowalksi",30,'m',"20-300"));
    showCities(cities);

    the_most(cities, 1);
    the_most(cities, 2);

    sort_cities(cities);
    showCities(cities);

    statistic(cities);

    return;
}

void zad4()
{
    std::vector<int> liczby = {123, 4567, 890, 5, -99, 102, 76};

    std::sort(liczby.begin(), liczby.end(), [](int a, int b) {
        return sumaCyfr(a) < sumaCyfr(b);
    });
    std::cout << "Posortowane wedlug sumy cyfr (rosnaco): ";
    std::for_each(liczby.begin(), liczby.end(), [](int n) {
        std::cout << n << " ";
    });
    std::cout << std::endl;

    std::sort(liczby.begin(), liczby.end(), [](int a, int b)
    {
        return liczbaCyfr(a) > liczbaCyfr(b);
    });
    std::cout << "Posortowane wedlug liczby cyfr (malejaco): ";
    std::for_each(liczby.begin(), liczby.end(), [](int n)
    {
        std::cout << n << " ";
    });
    std::cout << std::endl;
    return;
}

int main()
{

    //zad1();

    //zad2();

    //zad3();

    zad4();

    return 0;
}
