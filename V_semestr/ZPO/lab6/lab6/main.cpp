#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/fusion/include/for_each.hpp>
#include <boost/fusion/include/at.hpp>
#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/size.hpp>
//#include <boost/fusion/include/variant.hpp>
#include <boost/fusion/include/transform.hpp>
#include <boost/fusion/include/accumulate.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>
#include <typeinfo>

#include "person.h"
#include "contact.h"
#include "contacts.h"
#include "print.h"

using namespace boost::multi_index;
using namespace std;
namespace fusion = boost::fusion;

/*
using FusionVector = fusion::vector<bool, int, double, float, char>;
struct TypeCounter
{
    map<string, int> typeCount;
    // Operator () do zliczania
    template <typename T>
    void operator()(T)
    {
        const string typeName = typeid(T).name(); // Zbieramy nazwę typu
        typeCount[typeName]++;
    }
};
map<string, int> countTypes(const FusionVector& fusionVector)
{
    TypeCounter counter;
    fusion::for_each(fusionVector, counter);
    return counter.typeCount;
}*/

//using namespace boost::fusion;

/*template <typename T>
void count_types(T& vec, std::map<std::string, int>& type_count) {
    for_each(vec, [&](auto& elem) {
        std::string type_name = typeid(elem).name();
        type_count[type_name]++;
    });
}*/

typedef multi_index_container<Person,indexed_by<
hashed_non_unique<member<Person, string, &Person::name>>,
hashed_non_unique<member<Person, int, &Person::age>>
>> person_multi;

typedef person_multi::nth_index<0>::type name_type;

typedef person_multi::nth_index<1>::type age_type;

void AlaToAlicja(Person& x)
{
    if(x.name=="Ala")
        x.name="Alicja";
}

void UlaToUrszula(Person& x)
{
    x.name="Urszula";
}

typedef multi_index_container<Person,indexed_by<
ordered_non_unique<member<Person,string,&Person::name>>,
ordered_non_unique<member<Person,int,&Person::age>>,
random_access<> >> person_multi_2;
typedef person_multi_2::nth_index<0>::type name_type2;
typedef person_multi_2::nth_index<1>::type age_type2;

template <typename T>
void processVector(const vector<T>& vec)
{
    if (vec.empty())
    {
        cout << "Kontener jest pusty." << endl;
        return;
    }

    // Obliczanie średniej arytmetycznej
    T sum = std::accumulate(vec.begin(), vec.end(), static_cast<T>(0));
    T average = sum / static_cast<T>(vec.size());

    // Obliczanie mediany
    vector<T> sortedVec = vec; //T kopia wektora na posortowanie
    std::sort(sortedVec.begin(), sortedVec.end());
    T median;
    size_t size = sortedVec.size();
    if (size % 2 == 0)
    {
        median = (sortedVec[size / 2 - 1] + sortedVec[size / 2]) / static_cast<T>(2);
    }
    else //do liczenia miediany to 2 jak parzyste albo jedne jak nie cvhyba dlatego tak
    {

        median = sortedVec[size / 2];
    }

    // Wyświetlanie elementów mniejszych niż średnia
    cout << "Elementy mniejsze niz srednia (" << average << "): ";
    std::for_each(vec.begin(), vec.end(), [average](const T& element)
    {
        if (element < average)
        {
            cout << element << " ";
        }
    });
    cout << endl;

    // Wyświetlanie elementów między średnią a medianą
    cout << "Elementy miedzy srednia (" << average << ") a mediana (" << median << "): ";
    std::for_each(vec.begin(), vec.end(), [average, median](const T& element)
    {
        if (element > average && element < median)
        {
            cout << element << " ";
        }
    });
    cout << endl;

    // Wyświetlanie elementów dodatnich
    cout << "Elementy dodatnie: ";
    std::for_each(vec.begin(), vec.end(), [](const T& element)
    {
        if (element > 0)
        {
            cout << element << " ";
        }
    });
    cout << endl;
}

/*map<string, int> countTypes(const vector<boost::fusion::vector<int, double, float, bool, char>>& fusionVector)
{
    map<string, int> typeCount;

    // Funkcja pomocnicza do zliczania typów
    auto countType = [&typeCount](const auto& element)
    {
        const string typeName = typeid(element).name(); // Zbieramy nazwę typu
        typeCount[typeName]++; // Zwiększamy licznik dla danego typu
    };

    // Iterujemy przez elementy wektora
    for (const auto& elem : fusionVector)
    {
        boost::fusion::for_each(elem, countType);
    }

    return typeCount;
}*/

#include <boost/bind.hpp>
#include <iostream>
#include<vector>
using namespace std;
void firstArgMod(int& x, int y)
{

    x=x+y;
}
void printF(int x)
{

    cout<<x<<" ";
}
void contatination(int i1,int i2)
{

    cout << i1 << i2<< endl;;
}
class Operation
{
    public:

        int operator()(int a, int b)
        {
            return a - b;
        }


        int operator()(char a)
        {
            return (int)a-32;
        }
};
int addition(int a, int b)
{

    return a + b;
}

void zad1()
{
    /*
    person_multi persons;
    persons.insert({"Ala", 40});
    persons.insert({"Piotr", 10});
    persons.insert({"Ola", 18});
    persons.insert({"Ala", 46});
    persons.insert({"Ula", 46});

    cout<< "Liczba osob o imieniu Ala: "<<persons.count("Ala")<< endl;
    cout<<"Liczba osob o imieniu Ala: " <<persons.get<0>().count("Ala")<<endl;
    age_type &age_index = persons.get<1>();
    cout<< "Liczba osob z wiekiem 18 lat: "<<age_index.count(18)<< endl;

    for(age_type::iterator it=persons.get<1>().begin();
        it != persons.get<1>().end(); ++it) it->show();

    auto &age_indexx = persons.get<1>();
    auto it = age_indexx.find(46);
    cout<<"Znaleziona osoba, ktora ma 46 lat "<<it->name<<endl;

    auto &name_indexx = persons.get<0>();
    auto itt = name_indexx.find("Ula");
    name_indexx.modify(itt, boost::bind(UlaToUrszula,_1));

    cout<<"Przed modyfikacja: "<<endl;
    vector<name_type::iterator> elements;

    for(name_type::iterator it=persons.get<0>().begin(); it  != persons.get<0>().end(); ++it)
    {
        it->show();
        elements.push_back(it);
    }

    for(int i = 0; i<elements.size();i++)
        name_indexx.modify(elements[i], boost::bind(AlaToAlicja,_1));

    cout << "Po modyfikacji"<<endl;
    for(name_type::iterator it=persons.get<0>().begin();
        it != persons.get<0>().end(); ++it)
    {
        it->show();
    }

    person_multi_2 persons2;
    persons2.get<2>().push_back({"Ala", 40});
    persons2.get<2>().push_back({"Ala", 45});
    persons2.get<2>().push_back({"Piotr", 10});
    persons2.get<2>().push_back({"Ola", 18});


    persons2.get<2>().push_back({"Aga", 46});
    persons2.get<2>().push_back({"Ula", 46});
    auto &name_indexx2 = persons2.get<0>();
    auto iterStart = name_indexx2.equal_range("Ala");
    auto iterStop = name_indexx2.equal_range("Piotr");
    cout <<"przedzial od Ala do Piotr - wersja 1"<<endl;

    for(name_type2::iterator it=iterStart.first; it != iterStop.second; ++it)
        it->show();
    auto from = name_indexx2.lower_bound("Ala");
    auto to = name_indexx2.upper_bound("Piotr");
    cout <<"przedzial od Ala do Piotr - wersja 2"<<endl;
    for (auto it=from; it != to; ++it)
        it->show();

    auto &rand_indexx = persons2.get<2>();
    cout << rand_indexx[0].name <<endl;
    */
    boost::fusion::vector<int, string, bool, double> vec{10, "C++", true, 3.14};
    cout << "Trzeci element w vec:"
         <<boost::fusion::at<boost::mpl::int_<2>>(vec) <<endl;
    auto vec2 = push_back(vec, 'M');
    auto vec3 = push_back(vec, 'N');

    cout <<"Liczba elementow w wvec: "<< size(vec) <<endl;
    cout << "Liczba elementow w vec2: "<<size(vec2) <<endl;
    //cout << "Pierwszy element w vec2: "<<front(vec2) <<endl;
    //cout << "Ostatni element w vec2: "<<back(vec2) <<endl;
    cout<<"Cala zawartosc vec2: "<<endl;
    boost::fusion::for_each(vec2,Print());

    auto itvStart = begin(vec);
    auto itvStop = end(vec);
    cout<<"Pierwszy element: "<<*itvStart<<endl;
    cout<<"Drugi element: "<<*next(itvStart)<<endl;
    cout<<"Trzeci element: "
       <<*advance<boost::mpl::int_<2>>(itvStart)<<endl;

    /*cout<<"vec: "<<endl;
    vector<int> vec= {1,2,3,4,5};
    vector<int>::iterator iter1 = vec.begin();
    vector<int>::iterator iter2 = vec.end();
    for_each(iter1, iter2, boost::bind(printF, _1));
    cout<<endl<<"vec - kazdy element zwiekszony o 5: ";
    for_each(iter1, iter2, boost::bind(firstArgMod, _1, 5));
    for_each(iter1, iter2, boost::bind(printF, _1));
    int count=std::count_if(vec.begin(), vec.end(),
    boost::bind(std::logical_and<bool>(),
    boost::bind(std::greater<int>(),_1,8),
    boost::bind(std::less_equal<int>(),_1,10)));

    cout << endl<<"vec - 8<Elementy<=10  "<<count <<endl;

    cout<<addition(1,2)<<endl;
    int res=boost::bind(addition,_1,_2)(1,2);
    cout<<res<<endl;

    int i1=1,i2=2;
    boost::bind(contatination,_2,_1)(i1,i2);

    Operation ff;
    int x = 1024;
    cout<<"Funktor: "<<bind<int>(ff, _1, _1)(x)<<endl;
    char y='a';
    cout<<"Funktor: "<<bind<char>(ff, _1)(y)<<endl;*/

}

void zad2()
{
    Contacts phoneBook;

    phoneBook.addContact(Contact("Jan Kowalski", 25, "123456789", "kowalska"));
    phoneBook.addContact(Contact("Anna Nowak", 30, "987654321", "zlota"));
    phoneBook.addContact(Contact("Piotr Wisniewski", 20, "123123123", "kowalska"));
    phoneBook.addContact(Contact("Zbigniew Wisniewski", 17, "111222333", "kowalska"));

    std::cout << "Zawartosc ksiazki teleadresowej:" << std::endl;
    phoneBook.showAllContacts();

    phoneBook.removeContact("123456789");

    std::cout << "Po usunieciu kontaktu:" << std::endl;
    phoneBook.showAllContacts();

    auto contactsOnStreet = phoneBook.findByStreet("kowalska");
    std::cout << "Kontakty na ulicy Warszawa:" << std::endl;
    for (const auto& contact : contactsOnStreet)
    {
        std::cout << contact.name << std::endl;
    }

    auto contactsByAge = phoneBook.findByAgeRange(19,26);
    std::cout << "Kontakty w przedziale 19-26: " << std::endl;
    for (const auto& contact : contactsByAge)
    {
        std::cout << contact.name << std::endl;
    }

    Contact *c1 = phoneBook.findByPhone("123123123");
    std::cout << "Kontakt o numerze 123123123: " << std::endl;
    c1->show();

    std::cout << "Zmiana nazwy ulicy: przed" << std::endl;
    phoneBook.showAllContacts();
    phoneBook.changeStreetName("kowalska","kamienna");
    std::cout << "Zmiana nazwy ulicy: po" << std::endl;
    phoneBook.showAllContacts();

    std::cout << "Uzytkownicy pelnoletni: " << phoneBook.countAdults()<< std::endl;
    std::cout << "Unikatowe nazwiska: " << phoneBook.countUniqueLastNames()<< std::endl;
}

void zad3()
{
    vector<int> numbers = {5, -2, 9, 0, 4, 8, -1, 7, 3};
    processVector(numbers);
}

struct TypeCounter
{
    std::map<std::string, int> typeCount;

    // Operator funkcyjny do zliczania typów
    template <typename T>
    void operator()(const T& t) {
        std::string typeName = typeid(T).name();  // Poprawne przypisanie typu do stringa

        // Debug: Wyświetlanie typu aktualnego elementu
        std::cout << "Przetwarzam element typu: " << typeName << std::endl;

        // Zliczanie typów
        if(typeCount.find(typeName) == typeCount.end()) {
            typeCount[typeName] = 1;  // Jeżeli nie istnieje, dodajemy nowy typ
        } else {
            typeCount[typeName]++;  // Jeżeli istnieje, zwiększamy licznik
        }

        // Debug: Wyświetlanie mapy po każdym kroku
        std::cout << "Mapa po zliczeniu typu: " << typeName << std::endl;
        for(const auto& pair : typeCount) {
            std::cout << "Typ: " << pair.first << ", Liczba wystąpień: " << pair.second << std::endl;
        }
        std::cout << "-----------------------------" << std::endl;
    }
};
// Funkcja do zliczania typów w kontenerze Fusion
    template <typename FusionVector>
    std::map<std::string, int> countTypes(const FusionVector& fusionVector) {
        TypeCounter counter;

        // Zastosowanie for_each do zliczenia typów w kontenerze Fusion
        boost::fusion::for_each(fusionVector, counter);

        // Debug: Wyświetlanie zliczonych typów i ich liczby
        std::cout << "Zliczone typy i liczby wystąpień:" << std::endl;
        for(const auto& pair : counter.typeCount)
        {
            std::cout << "Typ: " << pair.first << ", Liczba wystąpień: " << pair.second << std::endl;
        }

        // Zwracamy zliczone typy jako mapa
        return counter.typeCount;
    }


void zad4()
{
    /*vector<boost::fusion::vector<int, double, float, bool, char>> fusionVector =
    {
        boost::fusion::vector<int, double, float, bool, char>(1, 7.8, 3.14f, true, 'a'),
        boost::fusion::vector<int, double, float, bool, char>(2, 3.0, 1.2f, false, 'b'),
        boost::fusion::vector<int, double, float, bool, char>(3, 4.5, 2.1f, true, 'c'),
    };

    // Wywołanie funkcji i wyświetlenie wyników
    map<string, int> result = countTypes(fusionVector);

    for (const auto& pair : result)
    {
        cout << "Typ: " << pair.first << ", Liczba wystapien: " << pair.second << endl;
    }*/
    fusion::vector<int, string, bool, double> vec{10, "C++", true, 3.14};

        // Dodanie elementów do kontenera Fusion
    auto vec2 = fusion::push_back(vec, 'M');
    auto vec3 = fusion::push_back(vec2, 'N');
    cout<<"test1"<<endl;
    // Zliczanie typów w vec3
    map<string, int> result = countTypes(vec3);

    // Wyświetlenie liczby wystąpień typów
    for(const auto& pair : result)
    {
        std::cout<<"Typ: "<< pair.first<<", Liczba wystąpień: "<<pair.second <<std::endl;
    }
    cout<<"test1"<<endl;
}

int main()
{

    //zad1();

    //zad2();

    //zad3();

    zad4();

    return 0;
}
