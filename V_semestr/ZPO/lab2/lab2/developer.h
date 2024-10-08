#ifndef DEVELOPER_H
#define DEVELOPER_H
#include "employee.h"

class Developer : public Employee
{
    public:

        Developer(std::string s, int a, int e, double sal)
            : Employee(s, a, e, sal) {}

        int calculateSalary(int value) override;
        float calculateBonus(int value) const;

        Developer(): Employee() {}
        ~Developer() override;
};
#endif // DEVELOPER_H
