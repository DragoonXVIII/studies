#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact
{
public:
    std::string name;
    int age;
    std::string phone;
    std::string street;

    Contact(std::string n, int a, std::string p, std::string s)
        : name(n), age(a), phone(p), street(s) {}

    void show() const;

};

#endif // CONTACT_H
