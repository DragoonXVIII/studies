#include "bufferfile.h"

#include <iostream>
#include <fstream>
#include <string>

#include "bufferfile.h"

using namespace std;


BufferFile::BufferFile(const string& path) : filePath(path)
{
    cout << "Konstruktor klasy BufferFile" << endl;
}

BufferFile::~BufferFile()
{
    cout << "Destruktor klasy BufferFile" << endl;
}

void BufferFile::add(int a)
{
    ofstream file(filePath, ios::app);
    if (file.is_open())
    {
        file << a << endl;
        file.close();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku: " << filePath << endl;
    }
}

void BufferFile::write()
{
    ifstream file(filePath);
    if (!file.is_open())
    {
        cout << "Nie mozna otworzyc pliku: " << filePath << endl;
        return;
    }
    cout << "Elementy w BufferFile: ";
    int number;
    while (file >> number)
    {
        cout << number << " ";
    }
    cout << endl;
    file.close();
}
