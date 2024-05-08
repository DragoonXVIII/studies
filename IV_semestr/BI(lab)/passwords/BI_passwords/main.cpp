//ZADANIE 1 - HASLA
/*
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

void generate_combinations(std::ofstream& file, std::string str, int length)
{
    if(length == 0)
    {
        file << str << std::endl;
        return;
    }

    for(char i = 'a'; i <= 'z'; i++)
    {
        generate_combinations(file, str + i, length - 1);
    }
}

void generate_combinationsaZ(std::ofstream& file, std::string str, int length)
{
    if(length == 0)
    {
        file << str << std::endl;
        return;
    }

    for(char i = 'a'; i <= 'z'; i++)
    {
        generate_combinationsaZ(file, str + i, length - 1);
    }

    for(char i = 'A'; i <= 'Z'; i++)
    {
        generate_combinationsaZ(file, str + i, length - 1);
    }
}

void generate_combinations_elo(std::ofstream& file, std::string str, int length)
{
    if(length == 0)
    {
        file << str << std::endl;
        return;
    }

    for(char i = 33; i <= 126; i++)
    {
        generate_combinations_elo(file, str + i, length - 1);
    }
}

int main()
{
    std::cout<<"Sprawozdanie:"<<std::endl;

    std::string name3az = "passwords_3_az.txt";
    std::ofstream file3az(name3az);
    auto start = std::chrono::high_resolution_clock::now();
    generate_combinations(file3az, "", 3);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    file3az.close();
    std::cout << "generowanie hasel: 3 znaki, a-z czas: " << duration.count() << " sekund" << std::endl;

    std::string name4az = "passwords_4_az.txt";
    std::ofstream file4az(name4az);
    start = std::chrono::high_resolution_clock::now();
    generate_combinations(file4az, "", 4);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    file4az.close();
    std::cout << "generowanie hasel: 4 znaki, a-z czas: " << duration.count() << " sekund" << std::endl;

    std::string name5az = "passwords_5_az.txt";
    std::ofstream file5az(name5az);
    start = std::chrono::high_resolution_clock::now();
    generate_combinations(file5az, "", 5);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    file5az.close();
    std::cout << "generowanie hasel: 5 znakow, a-z czas: " << duration.count() << " sekund" << std::endl;

    std::string name6az = "passwords_6_az.txt";
    std::ofstream file6az(name6az);
    start = std::chrono::high_resolution_clock::now();
    generate_combinations(file6az, "", 6);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    file6az.close();
    std::cout << "generowanie hasel: 6 znakow, a-z czas: " << duration.count() << " sekund" << std::endl;

    std::cout<<"zakonczono zadanie 1"<<std::endl;



    std::string name3aZ = "passwords_3_aZ.txt";
    std::ofstream file3aZ(name3aZ);
    start = std::chrono::high_resolution_clock::now();
    generate_combinationsaZ(file3aZ, "", 3);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    file3aZ.close();
    std::cout << "generowanie hasel: 3 znaki, a-Z czas: " << duration.count() << " sekund" << std::endl;
    std::cout<<"zakonczono 3aZ"<<std::endl;

    std::string name4aZ = "passwords_4_aZ.txt";
    std::ofstream file4aZ(name4aZ);
    start = std::chrono::high_resolution_clock::now();
    generate_combinationsaZ(file4aZ, "", 4);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    file4aZ.close();
    std::cout << "generowanie hasel: 4 znaki, a-Z czas: " << duration.count() << " sekund" << std::endl;

    std::string name5aZ = "passwords_5_aZ.txt";
    std::ofstream file5aZ(name5aZ);
    start = std::chrono::high_resolution_clock::now();
    generate_combinationsaZ(file5aZ, "", 5);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    file5aZ.close();
    std::cout << "generowanie hasel: 5 znakow, a-Z czas: " << duration.count() << " sekund" << std::endl;

    std::string name6aZ = "passwords_6_aZ.txt";
    std::ofstream file6aZ(name6aZ);
    start = std::chrono::high_resolution_clock::now();
    generate_combinationsaZ(file6aZ, "", 6);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    file6aZ.close();
    std::cout << "generowanie hasel: 6 znakow, a-Z czas: " << duration.count() << " sekund" << std::endl;

    std::cout<<"zakonczono zadanie 2"<<std::endl;



    auto start = std::chrono::high_resolution_clock::now();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::string name3 = "passwords_3_elo.txt";
    std::ofstream file3(name3);
    start = std::chrono::high_resolution_clock::now();
    generate_combinations_elo(file3, "", 3);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    file3.close();
    std::cout << "generowanie hasel: 3 znaki,  !-~  czas: " << duration.count() << " sekund" << std::endl;

    std::string name4 = "passwords_4_elo.txt";
    std::ofstream file4(name4);
    start = std::chrono::high_resolution_clock::now();
    generate_combinations_elo(file4, "", 4);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    file4.close();
    std::cout << "generowanie hasel: 4 znaki, !-~ czas: " << duration.count() << " sekund" << std::endl;

    std::string name5 = "passwords_5_elo.txt";
    std::ofstream file5(name5);
    start = std::chrono::high_resolution_clock::now();
    generate_combinations_elo(file5, "", 5);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    file5.close();
    std::cout << "generowanie hasel: 5 znakow, !-~  czas: " << duration.count() << " sekund" << std::endl;

    std::string name6 = "passwords_6_elo.txt";
    std::ofstream file6(name6);
    start = std::chrono::high_resolution_clock::now();
    generate_combinations_elo(file6, "", 6);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    file6.close();
    std::cout << "generowanie hasel: 6 znakow, !-~  czas: " << duration.count() << " sekund" << std::endl;

    std::cout<<"zakonczono zadanie 1"<<std::endl;


    return 0;
}
*/


//ZADANIE 2 - PESELE

// Funkcja do obliczania cyfry kontrolnej numeru PESEL
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// Funkcja obliczająca cyfrę kontrolną na podstawie ciągu PESEL
int control_number(const std::string& pesel) {
    int weights[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int sum = 0;

    for (int i = 0; i < 10; ++i) {
        sum += (pesel[i] - '0') * weights[i];
    }

    int remainder = sum % 10;
    int control_number = (10 - remainder) % 10;

    return control_number;
}

// Funkcja generująca wszystkie możliwe numery PESEL
void generate_pesel(std::ofstream& file) {
    for (int RR = 0; RR <= 99; ++RR) {
        for (int MM = 1; MM <= 12; ++MM) {
            for (int DD = 1; DD <= 31; ++DD) {
                for (int PPPP = 0; PPPP <= 9999; ++PPPP) {
                    // Formatowanie liczby PPPP na 4 cyfry
                    std::string PPPP_str = std::to_string(PPPP);
                    std::string formatted_PPPP = std::string(4 - PPPP_str.length(), '0') + PPPP_str;

                    // Obliczenie cyfry kontrolnej
                    std::string pesel = std::to_string(RR) + std::to_string(MM) + std::to_string(DD) + formatted_PPPP;
                    int control = control_number(pesel);

                    // Zapisanie numeru PESEL do pliku
                    file << std::setw(2) << std::setfill('0') << RR
                         << std::setw(2) << std::setfill('0') << MM
                         << std::setw(2) << std::setfill('0') << DD
                         << formatted_PPPP << control << std::endl;
                }
            }
        }
    }
}

int main() {
    std::ofstream outputFile("pesel_numbers.txt"); // Otwieramy plik wynikowy

    if (outputFile.is_open()) {
        generate_pesel(outputFile); // Generujemy numery PESEL i zapisujemy do pliku
        outputFile.close(); // Zamykamy plik
        std::cout << "Wszystkie możliwe numery PESEL zostały wygenerowane i zapisane do pliku 'pesel_numbers.txt'." << std::endl;
    } else {
        std::cerr << "Błąd podczas otwierania pliku wynikowego." << std::endl;
        return 1;
    }

    return 0;
}


//ZADANIE 3 - SZPIEG
/*





*/
