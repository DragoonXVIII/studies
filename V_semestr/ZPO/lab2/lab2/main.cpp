#include <iostream>
#include <vector>

#include "Figure.h"
#include "Square.h"
#include "Circle.h"

#include "employee.h"
#include "developer.h"
#include "teamleader.h"

#include "bufor.h"
#include "meanbufor.h"
#include "maxbufor.h"

using namespace std;

void whoWorkMoreThan5Years(Employee** employees, int size) {
    std::cout << "Employees with more than 5 years of experience:\n";
    for (int i = 0; i < size; ++i) {
        if (employees[i]->getExperience() > 5) {
            employees[i]->show();
        }
    }
}

int howManyEarnLessThanMeanSalary(Employee** employees, int size, int bonusValue) {
    double totalBonus = 0;
    std::vector<float> bonuses;

    // Oblicz sumę wszystkich premii
    for (int i = 0; i < size; ++i) {
        float bonus = employees[i]->calculateSalary(bonusValue);
        bonuses.push_back(bonus);
        totalBonus += bonus;
    }

    // Oblicz średnią
    double meanBonus = totalBonus / size;
    int count = 0;

    // Policz ilu pracowników ma niższą premię niż średnia
    for (int i = 0; i < size; ++i) {
        if (bonuses[i] < meanBonus) {
            count++;
        }
    }

    return count;
}

int main()
{
    //LAB 1 1/2

    /*Figure* f1=new Square(4);
    Figure* f2=new Circle(2);
    f1->calculateArea();
    f1->show();
    f2->calculateArea();
    f2->show();

    Figure *f3;
    Square s1(4);
    f3=&s1;
    f3->calculateArea();
    f3->show();
    */
    /*
    Figure* tab[3];
    tab[0]=new Square(4);
    tab[1]=new Square(2);
    tab[2]=new Circle(5);

    for(int i=0;i<3;i++)
    {
        tab[i]->calculateArea();
        tab[i]->calculatePerimeter();
        tab[i]->show();
        delete tab[i];
    }
    */
    //niedzialalo bo byl wczesniejszy kod ktory nie ywzglednial pol i obwodow a nowszy nie pojazywal wszystkiego xD

    //delete f1;
    //delete f2;


    //LAB 1 2/2
    /*
    Figure* tab[2];
    tab[0]=new Square(4);
    tab[1]=new Circle(2);
    for(int i=0;i<2;i++)
    {
        tab[i]->calculateArea();
        tab[i]->calculatePerimeter();
        tab[i]->show();
        delete tab[i];
    }
    */

    //LAB 2
    /*
    Developer dev("Kowalski", 30, 5, 8000);
    TeamLeader tl("Nowak", 40, 10, 12000);

    // Wyświetlanie informacji o Developerze i Team Leaderze
    dev.show();
    tl.show();

    // Obliczanie bonusów
    std::cout << "Developer bonus: " << dev.calculateBonus(10) << " PLN\n";
    std::cout << "Team Leader bonus: " << tl.calculateBonus(5) << " PLN\n";

    std::cout << "+==========================================================+";
    const int size = 4;
    Employee* employees[size] =
    {
        new Developer("Kowalski", 30, 6, 5000),
        new Developer("Nowak", 25, 3, 4500),
        new TeamLeader("Wiśniewski", 40, 10, 8000),
        new TeamLeader("Zieliński", 35, 7, 7500)
    };

    std::cout << "Test funkcji whoWorkMoreThan5Years:\n";
    whoWorkMoreThan5Years(employees, size);

    int bonusValue = 1000;
    std::cout << "\nTest funkcji howManyEarnLessThanMeanBonus:\n";
    int count = howManyEarnLessThanMeanSalary(employees, size, bonusValue);
    std::cout << "Liczba pracowników, którzy otrzymali premię niższą niż średnia: " << count << std::endl;

    for (int i = 0; i < size; ++i) {
        delete employees[i];
    }
    */


    // Funkcja main - test polimorficzny
    // Tworzymy dynamiczną tablicę wskaźników na obiekty klasy Bufor
    Bufor* buforArray[2];

    // Inicjalizujemy obiekty
    buforArray[0] = new MeanBufor(5);  // MeanBufor z 5 miejscami
    buforArray[1] = new MaxBufor(5);   // MaxBufor z 5 miejscami

    // Dodajemy elementy do obu buforów
    buforArray[0]->add(1);
    buforArray[0]->add(2);
    buforArray[0]->add(3);
    buforArray[0]->showTab();
    std::cout << "Średnia: " << buforArray[0]->calculate() << std::endl;

    buforArray[1]->add(10);
    buforArray[1]->add(20);
    buforArray[1]->add(5);
    buforArray[1]->showTab();
    std::cout << "Maksymalna wartość: " << buforArray[1]->calculate() << std::endl;

    // Próba przekroczenia rozmiaru MaxBufor
    buforArray[1]->add(30);
    buforArray[1]->add(40);
    buforArray[1]->add(50);  // Brak miejsca w MaxBufor!

    // Usuwanie obiektów
    for (int i = 0; i < 2; ++i) {
        delete buforArray[i];
    }

    return 0;
}
