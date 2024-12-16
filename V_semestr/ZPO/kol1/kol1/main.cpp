#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "product.h"

using namespace std;

//modyfikacja funkcji której użyłem do realizacji lab12
void sortEvenOdd(vector<int>& vec)
{
    stable_sort(vec.begin(), vec.end(), [](int a, int b)
    {
        return (a % 2 != 0) && (b % 2 == 0); // parzyste pod nieparzystymi
    });
}

//równiez modyfikacja funkcji
void sort1(vector<int>& vec)
{
    stable_sort(vec.begin(), vec.end(), [](int a, int b)
    {
        return (a > 0) && (b <= 0);
    });
    //std::reverse(vec.begin(), vec.end());
}



double policzMediane(vector<int> &vec)
{
    int size = vec.size();
    sort(vec.begin(), vec.end());
    if (size % 2 == 0)
        return (vec[size / 2 - 1] + vec[size / 2]) / 2.0;
    else
        return vec[size / 2];
}

//Definiuje funkcję o nazwie odpowiadającej Twojemu imieniu (np. jan), która:
void Jakub()
{
    //Tworzy listę o nazwie odpowiadającej Twojemu nazwisku (np. kowalski).
    vector<int> michalski;

    //Losuje dodatnią liczbę całkowitą n z przedziału <4,24>, a następnie n liczb z przedziału <-101,101>.
    srand(time(0));
    int n=rand()%21+4;
    for (int i=0; i<n; i++)
    {
        michalski.push_back(rand()%203 - 101);
    }

    //Segreguje liczby tak, aby na początku listy były elementy dodatnie lub równe 0, a na końcu ujemne.
    vector<int> sort1_michalski = michalski;
    sort1(sort1_michalski);

    cout<< "Lista michalski: ";
    for(int x:michalski)
        cout<< x<< " ";
    cout<< endl;

    cout<< "Lista michalski (sort1): ";
    for(int x:sort1_michalski)
        cout<< x<< " ";
    cout<< endl;

    //Oblicza średnią wartość wylosowanych liczb oraz medianę i je wyświetla.
    double srednia = accumulate(michalski.begin(),michalski.end(),0.0) / michalski.size();
    double mediana = policzMediane(sort1_michalski);

    //Ma drugą listę zawierającą te same liczby, ale z podziałem: na początku elementy nieparzyste, a na końcu parzyste.
    vector<int> sort2_michalski = michalski;
    sortEvenOdd(sort2_michalski);

    //Ma trzecią listę z posortowaną listą malejąco.
    vector<int> sort3_michalski = michalski;
    sort(sort3_michalski.rbegin(), sort3_michalski.rend());

    //Ma sprecyzowany numer albumu, a następnie sumuje liczby numeru albumu.
    string numer_albumu = "99630";
    int suma_albumu = 0;
    for(char digit:numer_albumu)
    {
        suma_albumu += digit-'0';
    }

    //Wyświetla zawartość wszystkich list, średnią i medianę z listy kowalski (pierwszej listy) oraz licznik, ile liczb jest mniejszych od sumy liczb albumu.
    int mniejsze_niz_suma = count_if(michalski.begin(), michalski.end(), [suma_albumu](int x)
    {
        return x < suma_albumu;
    });

    cout<< "Srednia: " << srednia<< endl;
    cout<< "Mediana: " << mediana<< endl;

    cout<< "Lista michalski (sort2): ";
    for(int x:sort2_michalski)
        cout << x<< " ";
    cout<< endl;

    cout<< "Lista michalski (sort3): ";
    for(int x:sort3_michalski)
        cout << x<< " ";
    cout<< endl;

    cout<< "Numer albumu: "<< numer_albumu<< endl;
    cout<< "Suma cyfr numeru albumu: "<< suma_albumu<< endl;

    cout<< "Licznik elementow mniejszych od sumy cyfr albumu: "<< mniejsze_niz_suma<< endl;
}

int main()
{
    Jakub();
    /*
    Product JakubMichalskiProduct("Telefon", 1999.99, 10, "123456");
    JakubMichalskiProduct.info();

    //Przykład użycia swojego imienia i nazwiska w kodzie za pomocą konstruktora bezargumentowego:
    //w przykładzie brak ustawienia pola Numer Albumu w związku z czym również nie ustawiałem, i jest taki jaki ustawiony w konstruktorze bezargumentowym cyt: "żeby się wszystko ładnie wyświetlało w konsoli"
    Product JanNowakProdukt;
    JanNowakProdukt.setName("Laptop");
    JanNowakProdukt.setPrice(3999.99);
    JanNowakProdukt.setQuantity(5);
    JanNowakProdukt.info();
    */

    return 0;
}


/*
ZADANIE 1.

Stwórz klasę Product, która będzie reprezentowała produkt w sklepie. Dodaj pole studentID (numer albumu, typu string) w klasie Product i ustaw jego wartość na Twój numer albumu w konstruktorze argumentowym.

Klasa powinna zawierać:

Pola prywatne:
name (nazwa produktu, typu string),
price (cena produktu, typu float),
quantity (ilość produktu, typu int),
studentID (Twój numer albumu, typu string).

Konstruktory:
Bezargumentowy ustawiający wartości domyślne: "undefined", 0.0 i 0.
Argumentowy inicjalizujący wszystkie pola, w tym studentID.

Metody publiczne:
setName, setPrice, setQuantity – ustawiające odpowiednie pola,
getName, getPrice, getQuantity – zwracające odpowiednie pola,
info() – wyświetlającą informacje o produkcie w formacie:
Produkt: <nazwa>, Cena: <cena>, Ilość: <ilość>, Numer albumu: <studentID>

W funkcji main:
Utwórz obiekt klasy Product za pomocą konstruktora argumentowego. Nazwij zmienną swoim imieniem i nazwiskiem (np. JanKowalskiProdukt).
Utwórz obiekt klasy Product za pomocą konstruktora bezargumentowego, a następnie ustaw jego pola przy użyciu metod.
Wyświetl informacje o obu obiektach.

Przykład użycia swojego imienia i nazwiska w kodzie za pomocą konstruktora argumentowego:

Product JanKowalskiProdukt("Telefon", 1999.99, 10, "123456");
JanKowalskiProdukt.info();

Przykład użycia swojego imienia i nazwiska w kodzie za pomocą konstruktora bezargumentowego:

Product JanNowakProdukt;
JanNowakProdukt.setName("Laptop");
JanNowakProdukt.setPrice(3999.99);
JanNowakProdukt.setQuantity(5);
JanNowakProdukt.info();

Przykład widoku konsoli:

Produkt: Telefon, Cena: 1999.99, Ilość: 10, Numer albumu: 123456
Produkt: Laptop, Cena: 3999.99, Ilość: 5, Numer albumu: 123456
*/

/*
ZADANIE 2.
Napisz program, który:
Tworzy listę o nazwie odpowiadającej Twojemu nazwisku (np. kowalski).
Definiuje funkcję o nazwie odpowiadającej Twojemu imieniu (np. jan), która:
Losuje dodatnią liczbę całkowitą n z przedziału <4,24>, a następnie n liczb z przedziału <-101,101>.
Segreguje liczby tak, aby na początku listy były elementy dodatnie lub równe 0, a na końcu ujemne.
Oblicza średnią wartość wylosowanych liczb oraz medianę i je wyświetla.
Ma drugą listę zawierającą te same liczby, ale z podziałem: na początku elementy nieparzyste, a na końcu parzyste.
Ma trzecią listę z posortowaną listą malejąco.
Ma sprecyzowany numer albumu, a następnie sumuje liczby numeru albumu.
Wyświetla zawartość wszystkich list, średnią i medianę
z listy kowalski (pierwszej listy) oraz licznik,
 ile liczb jest mniejszych od sumy liczb albumu.
*/
