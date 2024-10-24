#ifndef FILES_H
#define FILES_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

// Klasa Student
class Student {
public:
    string firstName;
    string lastName;
    char gender; // 'K' for female, 'M' for male
    double grade;
    string email;

    Student(const string& fName, const string& lName, char gen, double grd, const string& mail)
        : firstName(fName), lastName(lName), gender(gen), grade(grd), email(mail) {}
};

// Klasa Files do zarządzania listą studentów i operacjami na plikach
class Files {
private:
    vector<Student> students; // Lista studentów

    bool isValidName(const string& name) {
        return !name.empty() && all_of(name.begin(), name.end(), [](unsigned char c) {
            return isalpha(c);
        }) && isupper(name[0]); // Sprawdza, czy pierwsza litera jest wielka
    }

    bool isValidGender(char gender) {
        return gender == 'K' || gender == 'M';
    }

    bool isValidEmail(const string& email) {
        return email.find('@') != string::npos; // Sprawdza, czy email zawiera '@'
    }

public:
    // Wczytanie danych z pliku CSV
    void loadFromFile(const string& filePath)
    {
        ifstream file(filePath);
        if (!file.is_open())
        {
            cerr << "Nie można otworzyć pliku: " << filePath << endl;
            return;
        }

        string line;
        getline(file, line); // Pomijamy nagłówek
        while (getline(file, line)) {
            stringstream ss(line);
            string firstName, lastName, email;
            char gender;
            double grade;

            getline(ss, firstName, ';');
            getline(ss, lastName, ';');
            ss >> gender;
            ss.ignore(1); // Ignoruj średnik
            ss >> grade;
            ss.ignore(1); // Ignoruj średnik
            getline(ss, email);

            students.emplace_back(firstName, lastName, gender, grade, email);
        }
        file.close();
    }

    // Wyświetlenie książki adresowej
    void displayStudents() {
        cout << left << setw(20) << "Imię"
             << setw(20) << "Nazwisko"
             << setw(10) << "Płeć"
             << setw(10) << "Ocena"
             << setw(30) << "Email" << endl;

        for (const auto& student : students) {
            cout << left << setw(20) << student.firstName
                 << setw(20) << student.lastName
                 << setw(10) << student.gender
                 << setw(10) << student.grade
                 << setw(30) << student.email << endl;
        }
    }

    // Dodanie nowego studenta
    void addStudent() {
        string firstName, lastName, email;
        char gender;
        double grade;

        cout << "Podaj imię: ";
        cin >> firstName;
        cout << "Podaj nazwisko: ";
        cin >> lastName;
        cout << "Podaj płeć (K/M): ";
        cin >> gender;
        cout << "Podaj ocenę: ";
        cin >> grade;
        cout << "Podaj email: ";
        cin >> email;

        // Walidacja danych
        if (!isValidName(firstName) || !isValidName(lastName) ||
            !isValidGender(gender) || !isValidEmail(email)) {
            cout << "Błędne dane. Spróbuj ponownie." << endl;
            return;
        }

        students.emplace_back(firstName, lastName, gender, grade, email);
        cout << "Student dodany pomyślnie." << endl;
    }

    // Zapis do pliku CSV
    void saveToCSV(const string& filePath) {
        ofstream file(filePath, ios::app); // Otwiera plik do dopisywania
        if (!file.is_open()) {
            cerr << "Nie można otworzyć pliku " << filePath << endl;
            return;
        }

        for (const auto& student : students) {
            file << student.firstName << ';'
                 << student.lastName << ';'
                 << student.gender << ';'
                 << student.grade << ';'
                 << student.email << '\n';
        }
        file.close();
    }

    // Tworzenie plików k.csv i m.csv
    void createGenderFiles() {
        ofstream femaleFile("k.csv");
        ofstream maleFile("m.csv");

        femaleFile << "Imię;Nazwisko;Płeć;Ocena;Email\n";
        maleFile << "Imię;Nazwisko;Płeć;Ocena;Email\n";

        for (const auto& student : students) {
            if (student.gender == 'K') {
                femaleFile << student.firstName << ';'
                           << student.lastName << ';'
                           << student.gender << ';'
                           << student.grade << ';'
                           << student.email << '\n';
            } else {
                maleFile << student.firstName << ';'
                         << student.lastName << ';'
                         << student.gender << ';'
                         << student.grade << ';'
                         << student.email << '\n';
            }
        }
        femaleFile.close();
        maleFile.close();
        cout << "Pliki k.csv oraz m.csv zostały utworzone." << endl;
    }

    // Wyszukiwanie studentów po nazwisku
    void searchByLastName(const string& lastNameToSearch) {
        bool found = false;
        for (const auto& student : students) {
            if (student.lastName == lastNameToSearch) {
                cout << student.firstName << " " << student.lastName << " "
                     << student.gender << " " << student.grade << " " << student.email << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Nie znaleziono studentów o nazwisku: " << lastNameToSearch << endl;
        }
    }

    // Wyświetlanie X pierwszych studentów
    void displayFirstXStudents(int x) {
        if (x > students.size()) {
            cout << "Jest mniej studentów niż podana liczba." << endl;
            return;
        }

        for (int i = 0; i < x; i++) {
            cout << students[i].firstName << " " << students[i].lastName << " "
                 << students[i].gender << " " << students[i].grade << " " << students[i].email << endl;
        }
    }

    // Sortowanie studentów względem oceny
    void sortStudentsByGrade() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.grade < b.grade;
        });
        cout << "Studenci zostali posortowani względem oceny rosnąco." << endl;
    }
};

// Główna funkcja programu

#endif // FILES_H
