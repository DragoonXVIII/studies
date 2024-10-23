#include "contact.h"

void Contact::show() const
{
    std::cout << "Name: " << name << ", Age: " << age
              << ", Phone: " << phone << ", Street: " << street << std::endl;
}
