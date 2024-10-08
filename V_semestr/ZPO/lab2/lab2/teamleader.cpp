#include "teamleader.h"

void TeamLeader::show() const
{
    std::cout << "Team Leader: " << surname << ", Age: " << age
              << ", Experience: " << experience << " years, Salary: " << salary << " PLN\n"
              << "Jestem Team Leader z " << experience << " letnim doświadczeniem\n";
}

float TeamLeader::calculateBonus(int value) const
{
    return value * (1 + salary + experience);
}

int TeamLeader::calculateSalary(int value)
{
    return value * (1 + salary + experience);
}

TeamLeader::~TeamLeader()
{
    std::cout << "TeamLeader destructor called\n";
}
