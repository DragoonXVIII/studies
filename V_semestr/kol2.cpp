/*
ZADANIE 3.

Utwórz klasę Student, która zawiera:
imię (std::string),
numer indeksu (std::string).

Napisz program, który tworzy dynamiczną tablicę obiektów Student przy użyciu inteligentnych wskaźników
 (std::shared_ptr) i uzupełnia dane studentów na podstawie wejścia od użytkownika
- program powinien zapytać się ilu użytkownik ma studentów, a następnie przyjąć podaną liczbę danych.
Wyświetl listę studentów w formacie:
Imię: [imię], Numer indeksu: [indeks]

Punkty obowiązkowe do wykonania:
- Zaimplementuj konstruktor parametryczny w klasie Student
- Użyj pętli do dodawania obiektów do tablicy
*/

#include <iostream>
#include <memory>
#include <vector>

class Student {
public:
	std::string imie;
	std::string numer_indeksu;

	Student(const std::string& imie, const std::string& numer_indeksu)
		: imie(imie), numer_indeksu(numer_indeksu) {}
};

int main() {
	int liczba_studentow;
	std::cout << "Podaj liczbe studentow: ";
	std::cin >> liczba_studentow;

	std::vector<std::shared_ptr<Student>> studenci;
	for (int i = 0; i < liczba_studentow; ++i) {
		std::string imie, numer_indeksu;
		std::cout << "Podaj imie studenta: ";
		std::cin >> imie;
		std::cout << "Podaj numer indeksu studenta: ";
		std::cin >> numer_indeksu;
		studenci.push_back(std::make_shared<Student>(imie, numer_indeksu));
	}

	std::cout << "Lista studentow:\n";
	for (const auto& student : studenci) {
		std::cout << "Imie: " << student->imie << ", Numer indeksu: " << student->numer_indeksu << '\n';
	}

	return 0;
}