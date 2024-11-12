#include "files.h"

bool Files::isValidName(const string& name)
{
    return !name.empty() && all_of(name.begin(), name.end(), [](unsigned char c)
    {
        return isalpha(c);
    }) && isupper(name[0]);
}

bool Files::isValidGender(char gender)
{
    return gender == 'K' || gender == 'M';
}

bool Files::isValidEmail(const string& email)
{
    return email.find('@') != string::npos;
}

void Files::loadFromFile(const string& filePath)
{
    ifstream file(filePath);
    if(!file.is_open())
    {
        cerr << "Nie mozna otworzyc pliku: " << filePath << endl;
        return;
    }

    string line;
    getline(file, line); // naglowki sa useles,dzk
    while(getline(file, line))
    {
        stringstream ss(line);
        string firstName, lastName, email;
        char gender;
        double grade;

        getline(ss, firstName, ';');
        getline(ss, lastName, ';');
        ss >> gender;
        ss.ignore(1); //na sredniki co by nie wczytac
        ss >> grade;
        ss.ignore(1); // -||-
        getline(ss, email);

        students.emplace_back(firstName, lastName, gender, grade, email);
    }
    file.close();
}

void Files::displayStudents()
{
    cout << left << setw(20) << "Imie"
         << setw(20) << "Nazwisko"
         << setw(10) << "Plec"
         << setw(10) << "Ocena"
         << setw(30) << "Email" << endl;

    for(const auto& student : students)
    {
        cout << left << setw(20) << student.firstName
             << setw(20) << student.lastName
             << setw(10) << student.gender
             << setw(10) << student.grade
             << setw(30) << student.email << endl;
    }
}

void Files::addStudent()
{
    string firstName, lastName, email;
    char gender;
    double grade;

    cout << "Podaj imie: ";
    cin >> firstName;
    cout << "Podaj nazwisko: ";
    cin >> lastName;
    cout << "Podaj plec (K/M): ";
    cin >> gender;
    cout << "Podaj ocene: ";
    cin >> grade;
    cout << "Podaj email: ";
    cin >> email;

    // walidowanie danych
    if(!isValidName(firstName) || !isValidName(lastName) ||
        !isValidGender(gender) || !isValidEmail(email))
    {
        cout << "Bledne dane. Sprobuj ponownie." << endl;
        return;
    }

    students.emplace_back(firstName, lastName, gender, grade, email);
    cout << "Student dodany pomyslnie." << endl;
}

void Files::saveToCSV(const string& filePath)
{
    ofstream file(filePath, ios::app);
    if(!file.is_open()) {
        cerr << "Nie mozna otworzyc pliku " << filePath << endl;
        return;
    }

    for(const auto& student : students)
    {
        file << student.firstName << ';'
             << student.lastName << ';'
             << student.gender << ';'
             << student.grade << ';'
             << student.email << '\n';
    }
    file.close();
}

void Files::createGenderFiles()
{
    ofstream femaleFile("k.csv");
    ofstream maleFile("m.csv");

    femaleFile << "Imie;Nazwisko;Plec;Ocena;Email\n";
    maleFile << "Imie;Nazwisko;Plec;Ocena;Email\n";

    for(const auto& student : students)
    {
        if(student.gender == 'K')
        {
            femaleFile << student.firstName << ';'
                       << student.lastName << ';'
                       << student.gender << ';'
                       << student.grade << ';'
                       << student.email << '\n';
        }
        else
        {
            maleFile << student.firstName << ';'
                     << student.lastName << ';'
                     << student.gender << ';'
                     << student.grade << ';'
                     << student.email << '\n';
        }
    }
    femaleFile.close();
    maleFile.close();
    cout << "Pliki k.csv oraz m.csv zostaly utworzone." << endl;
}

void Files::searchByLastName(const string& lastNameToSearch)
{
    bool found = false;
    for(const auto& student : students)
    {
        if(student.lastName == lastNameToSearch)
        {
            cout << student.firstName << " " << student.lastName << " "
                 << student.gender << " " << student.grade << " " << student.email << endl;
            found = true;
        }
    }
    if(!found)
    {
        cout << "Nie znaleziono studentow o nazwisku: " << lastNameToSearch << endl;
    }
}

void Files::displayFirstXStudents(int x)
{
    if(x > students.size())
    {
        cout << "Jest mniej studentow niż podana liczba." << endl;
        return;
    }

    for(int i=0; i<x; i++)
    {
        cout << students[i].firstName << " " << students[i].lastName << " "
             << students[i].gender << " " << students[i].grade << " " << students[i].email << endl;
    }
}

void Files::sortStudentsByGrade()
{
    sort(students.begin(), students.end(), [](const Student& a, const Student& b)
    {
        return a.grade < b.grade;
    });
    cout << "Studenci zostali posortowani wzgledem oceny rosnaco." << endl;
}
