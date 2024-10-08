#ifndef TEAMLEADER_H
#define TEAMLEADER_H
#include "employee.h"

class TeamLeader : public Employee
{
    public:

        TeamLeader(std::string s, int a, int e, double sal)
            : Employee(s, a, e, sal) {}

        void show() const override;
        float calculateBonus(int value) const;
        int calculateSalary(int value) override;
        TeamLeader(): Employee() {};
        ~TeamLeader() override;
};

#endif // TEAMLEADER_H

