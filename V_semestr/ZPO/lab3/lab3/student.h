#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <iostream>
using namespace std;

template <typename T>
class Student
{
    private:
        string name;
        int mark;
    public:
        Student(int mark, string name) : name(name), mark(mark) {};
        Student() {};
        void show()
        {
            cout << "imie: " << name << " ocena " << mark << endl;
        }
        void showMark()
        {
            cout << mark << endl;
        }
};

template<>
class Student<int>
{
    private:
        string name;
        int mark;
    public:
        Student(int mark, string name) : name(name), mark(mark) {};
        Student() {};
        void show()
        {
            cout << "imie: " << name << " ocena " << mark << endl;
        }
        void showMark()
        {
            cout << "Twoja ocena to: " << mark << endl;
        }
};

template<>
class Student<string>
{
    private:
        string name;
        int mark;
    public:
        Student(int mark, string name) : name(name), mark(mark) {};
        Student() {};
        void show()
        {
            cout << "imie: " << name << " ocena " << mark << endl;
        }
        int showMark()
        {
            string word[6] = {"jedynka", "dwojka", "trojka", "czworka", "piatka", "szostka"};
            cout << "Twoja ocena to: " << word[mark - 1] << endl;
            return mark;
        }
};

#endif // STUDENT_H_INCLUDED
