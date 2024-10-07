#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED
#include"Person.h"
class Teacher: public Person
{
private:
    int experience;
    string title;
public:
    Teacher(string name1, string surname1, int age1,int
                                                         experience1, string title1);
    Teacher();
    void setTitle(string title1);


    int getExperience();
    bool is_Phd();
    void showInfoTeacher();
};
#endif // TEACHER_H_INCLUDED
