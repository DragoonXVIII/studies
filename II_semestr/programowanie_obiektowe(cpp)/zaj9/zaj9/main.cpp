
#include "ttime.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;


    Ttime lot1(8, 30); // Czas przelotu Chicago - Paryż
    Ttime lot2(2, 0);  // Czas przelotu Paryż - Warszawa
    Ttime oczekiwanie(1, 30); // Czas oczekiwania na lotnisku w Paryżu

    Ttime czas_podrozy = lot1 + lot2 + oczekiwanie;
    std::cout << "Calkowity czas podrozy: " << czas_podrozy << std::endl;

    Ttime czas_przelotu_paryz_warszawa_powrot = lot2 * 2;
    Ttime czas_podrozy_londyn_warszawa = Ttime(5, 0) + czas_przelotu_paryz_warszawa_powrot + oczekiwanie;

    if (czas_podrozy_londyn_warszawa == czas_podrozy)
    {
        std::cout << "Czasy podrozy sa takie same." << std::endl;
    } else
    {
        std::cout << "Czasy podrozy sie roznia." << std::endl;
    }

    return 0;
}
