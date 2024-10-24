#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

// Funkcja zwracająca długość najkrótszego napisu, średnią długość napisu oraz najdłuższy napis
tuple<size_t, double, string> analyzeStrings(const vector<string>& strings)
{
    if (strings.empty())
    {
        return {0, 0.0, ""}; // Zwracamy wartości domyślne, gdy kontener jest pusty
    }

    // Najkrótszy napis
    auto minLengthIt = min_element(strings.begin(), strings.end(),
                                    [](const string& a, const string& b)
    {
                                        return a.length() < b.length();
                                    });

    // Najdłuższy napis
    auto maxLengthIt = max_element(strings.begin(), strings.end(),
                                    [](const string& a, const string& b)
    {
                                        return a.length() < b.length();
                                    });

    // Średnia długość napisów
    double averageLength = 0.0;
    for (const auto& str : strings)
    {
        averageLength += str.length();
    }
    averageLength /= strings.size();

    // Zwracamy krotkę z długością najkrótszego napisu, średnią długością oraz najdłuższym napisem
    return {minLengthIt->length(), averageLength, maxLengthIt->c_str()};
}

int main()
 {
    vector<string> strings = {"hello", "world", "C++", "programming", "lambda"};

    // Analizujemy napisy
    auto [minLength, avgLength, maxLengthStr] = analyzeStrings(strings);

    // Wyświetlamy wyniki
    cout << "Długość najkrótszego napisu: " << minLength << endl;
    cout << "Średnia długość napisu: " << avgLength << endl;
    cout << "Najdłuższy napis: " << maxLengthStr << endl;

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Car {
private:
    string model;
    int productionYear;
    double engineCapacity;

public:
    // Konstruktor inicjalizujący
    Car(const string& model, int productionYear, double engineCapacity)
        : model(model), productionYear(productionYear), engineCapacity(engineCapacity) {}

    // Gettery
    string getModel() const { return model; }
    int getProductionYear() const { return productionYear; }
    double getEngineCapacity() const { return engineCapacity; }

    // Settery
    void setModel(const string& model) { this->model = model; }
    void setProductionYear(int year) { productionYear = year; }
    void setEngineCapacity(double capacity) { engineCapacity = capacity; }

    // Metoda wyświetlająca informacje o samochodzie
    void display() const {
        cout << "Model: " << model
             << ", Rok produkcji: " << productionYear
             << ", Pojemność silnika: " << engineCapacity << " L" << endl;
    }
};

int main()
{
    vector<Car> cars;

    // Dodawanie samochodów do kontenera
    cars.emplace_back("Toyota Corolla", 2015, 1.6);
    cars.emplace_back("Ford Fiesta", 2018, 1.0);
    cars.emplace_back("Honda Civic", 2012, 1.8);
    cars.emplace_back("BMW 320i", 2020, 2.0);
    cars.emplace_back("Audi A4", 2019, 2.0);

    // Sortowanie rosnąco według roku produkcji
    sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
        return a.getProductionYear() < b.getProductionYear();
    });

    cout << "Samochody posortowane rosnąco według roku produkcji:" << endl;
    for (size_t i = 0; i < cars.size(); ++i) {
        cout << (i + 1) << ". ";
        cars[i].display();
    }

    // Sortowanie malejąco według pojemności silnika
    sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
        return a.getEngineCapacity() > b.getEngineCapacity();
    });

    cout << "\nSamochody posortowane malejąco według pojemności silnika:" << endl;
    for (size_t i = 0; i < cars.size(); ++i) {
        cout << (i + 1) << ". ";
        cars[i].display();
    }

    return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // dla std::accumulate

using namespace std;

// Funkcja do wyświetlania elementów wektora
void displayVector(const vector<int>& vec) {
    for (const auto& elem : vec) {
        cout << elem << "|";
    }
    cout << endl;
}

// Funkcja do obliczania średniej arytmetycznej
double calculateAverage(const vector<int>& vec) {
    if (vec.empty()) return 0.0;
    return static_cast<double>(accumulate(vec.begin(), vec.end(), 0)) / vec.size();
}

// Funkcja do liczenia elementów parzystych
int countEvenNumbers(const vector<int>& vec) {
    return count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
}

// Funkcja do usuwania elementów ujemnych
void removeNegativeNumbers(vector<int>& vec) {
    vec.erase(remove_if(vec.begin(), vec.end(), [](int x) { return x < 0; }), vec.end());
}

// Funkcja do sortowania elementów (parzyste na początku)
void sortEvenOdd(vector<int>& vec) {
    stable_sort(vec.begin(), vec.end(), [](int a, int b) {
        return (a % 2 == 0) && (b % 2 != 0); // parzyste przed nieparzystymi
    });
}

// Funkcja do negowania wartości elementów
void negateValues(vector<int>& vec) {
    transform(vec.begin(), vec.end(), vec.begin(), [](int x) { return -x; });
}

// Funkcja do liczenia elementów mniejszych niż dany argument
int countLessThan(const vector<int>& vec, int threshold) {
    return count_if(vec.begin(), vec.end(), [threshold](int x) { return x < threshold; });
}

int main() {
    // Tworzenie i wypełnianie wektora
    vector<int> numbers = {10, -5, 3, 6, 8, -1, 2, 7, 4, -9};

    cout << "Wektory: ";
    displayVector(numbers);

    // Obliczanie średniej arytmetycznej
    double average = calculateAverage(numbers);
    cout << "Średnia arytmetyczna: " << average << endl;

    // Liczenie parzystych
    int evenCount = countEvenNumbers(numbers);
    cout << "Liczba elementów parzystych: " << evenCount << endl;

    // Usuwanie elementów ujemnych
    removeNegativeNumbers(numbers);
    cout << "Wektor po usunięciu ujemnych: ";
    displayVector(numbers);

    // Sortowanie parzystych i nieparzystych
    sortEvenOdd(numbers);
    cout << "Wektor po posortowaniu parzystych i nieparzystych: ";
    displayVector(numbers);

    // Negowanie wartości elementów
    negateValues(numbers);
    cout << "Wektor po negacji wartości: ";
    displayVector(numbers);

    // Liczenie elementów mniejszych niż podany argument
    int threshold;
    cout << "Podaj wartość progową: ";
    cin >> threshold;
    int countLess = countLessThan(numbers, threshold);
    cout << "Liczba elementów mniejszych niż " << threshold << ": " << countLess << endl;

    return 0;
}
*/
