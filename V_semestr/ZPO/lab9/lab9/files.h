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

#include "student.h"

using namespace std;

class Files
{
private:
    vector<Student> students;
    bool isValidName(const string& name);
    bool isValidGender(char gender);
    bool isValidEmail(const string& email);

public:
    void loadFromFile(const string& filePath);
    void displayStudents();
    void addStudent();
    void saveToCSV(const string& filePath);
    void createGenderFiles();
    void searchByLastName(const string& lastNameToSearch);
    void displayFirstXStudents(int x);
    void sortStudentsByGrade();
};

#endif // FILES_H
