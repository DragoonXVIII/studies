#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>

//zad1
bool isFloatWithSign(const std::string& input)
{
    std::regex floatRegex("[+-]?\\d+\\.\\d+");
    return std::regex_search(input, floatRegex);
}

//zad2
bool isValidTime(const std::string& input)
{
    std::regex timeRegex(R"((([01]\d|2[0-3]):[0-5]\d(:[0-5]\d)?))");
    return std::regex_match(input, timeRegex);
}

//zad3
bool isStreetName(const std::string& input)
{
    std::regex streetRegex("[A-Za-zĄąĆćĘęŁłŃńÓóŚśŹźŻż\\s]+");
    return std::regex_match(input, streetRegex);
}

bool isPostalCode(const std::string& input)
{
    std::regex postalCodeRegex("\\d{2}-\\d{3}");
    return std::regex_match(input, postalCodeRegex);
}

bool isHouseNumber(const std::string& input)
{
    std::regex houseNumberRegex("\\d+[A-Za-z]?");
    return std::regex_match(input, houseNumberRegex);
}

bool isApartmentNumber(const std::string& input)
{
    std::regex apartmentNumberRegex("\\d+[A-Za-z]?");
    return std::regex_match(input, apartmentNumberRegex);
}

//zad4
bool isValidFirstName(const std::string& input) {
    std::regex firstNameRegex("[A-Za-z]+");
    return std::regex_match(input, firstNameRegex);
}

bool isValidLastName(const std::string& input)
{
    std::regex lastNameRegex("[A-Za-z]+(-[A-Za-z]+)?");
    return std::regex_match(input, lastNameRegex);
}

bool isValidAge(const std::string& input)
{
    std::regex ageRegex("[1-9]?[0-9]");
    return std::regex_match(input, ageRegex);
}

bool isValidPhoneNumber(const std::string& input)
{
    std::regex phoneRegex("[1-9][0-9]{8}");
    return std::regex_match(input, phoneRegex);
}

bool isValidEmail(const std::string& input)
{
    std::regex emailRegex("[A-Za-z][A-Za-z0-9._-]*@[A-Za-z0-9]+\\.[A-Za-z]+");
    return std::regex_match(input, emailRegex);
}

void saveToFile(const std::string& firstName, const std::string& lastName, const std::string& age, const std::string& phoneNumber, const std::string& email) {
    std::ofstream file;
    file.open("dane.txt", std::ios::app); // appendem otwarcie
    if (file.is_open()) {
        file << firstName << ";" << lastName << ";" << age << ";" << phoneNumber << ";" << email << std::endl;
        file.close();
        std::cout << "Dane zostaly zapisane do pliku." << std::endl;
    } else {
        std::cout << "Blad podczas otwierania pliku." << std::endl;
    }
}

//zad5
void displayUniqueDomains(const std::vector<std::string>& emails)
{
    std::set<std::string> uniqueDomains;
    std::regex domainRegex("@([A-Za-z0-9]+\\.[A-Za-z]+)");

    for (const auto& email : emails)
    {
        std::smatch match;
        if (std::regex_search(email, match, domainRegex))
        {
            uniqueDomains.insert(match[1]); // dodwania do uniqatow
        }
    }

    std::cout << "Unikatowe domeny:" << std::endl;
    for (const auto& domain : uniqueDomains)
    {
        std::cout << domain << std::endl;
    }
}

void displayEvenPhoneNumbers(const std::vector<std::string>& phoneNumbers)
{
    std::cout << "Numery telefonow konczace sie liczba parzysta:" << std::endl;
    for (const auto& phoneNumber : phoneNumbers)
    {
        if ((phoneNumber.back() - '0') % 2 == 0) //check parzystosc
        {
            std::cout << phoneNumber << std::endl;
        }
    }
}

void displayHyphenatedLastNames(const std::vector<std::string>& lastNames)
{
    std::cout << "Nazwiska laczone (z myslnikiem):" << std::endl;
    for (const auto& lastName : lastNames)
    {
        if (lastName.find('-') != std::string::npos) //o znowu npos, on jest smieszny jak w labie 9
        {
            std::cout << lastName << std::endl;
        }
    }
}

void displayFirstNameStatistics(const std::vector<std::string>& firstNames)
{
    std::map<std::string, int> nameCount;

    for (const auto& firstName : firstNames)
    {
        nameCount[firstName]++; // zliczanie imioan
    }

    std::cout << "Statystyka imion:" << std::endl;
    for (const auto& pair : nameCount)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

/*void displayPersonsData(const std::vector<std::string>& firstNames,
                        const std::vector<std::string>& lastNames,
                        const std::vector<std::string>& phoneNumbers,
                        const std::vector<std::string>& emails)
    {
    std::cout << "Dane osobowe:" << std::endl;

    for (size_t i = 0; i < firstNames.size(); ++i) {
        std::cout << firstNames[i] << "; "
                  << lastNames[i] << "; "
                  << phoneNumbers[i] << "; "
                  << emails[i] << std::endl;
    }
}*/

//zad
void zad1()
{
    // Testowanie
    std::string test1 = "+6.789";
    std::string test2 = "-7.234";
    std::string test3 = "fvagfag+123.456fafafaw";
    std::string test4 = "-123";
    std::string test5 = "abc";
    std::string test6 = "aa+AA123a.45a6aaAa";

    std::cout << test1 << ": " << isFloatWithSign(test1) << std::endl;
    std::cout << test2 << ": " << isFloatWithSign(test2) << std::endl;
    std::cout << test3 << ": " << isFloatWithSign(test3) << std::endl;
    std::cout << test4 << ": " << isFloatWithSign(test4) << std::endl;
    std::cout << test5 << ": " << isFloatWithSign(test5) << std::endl;
    std::cout << test6 << ": " << isFloatWithSign(test6) << std::endl;

    return;
}

void zad2()
{

    std::string test1 = "12:34";
    std::string test2 = "23:59:59";
    std::string test3 = "00:00";
    std::string test4 = "25:00";  // Niepoprawne godziny
    std::string test5 = "12:60";  // Niepoprawne minuty
    std::string test6 = "23:45:60";  // Niepoprawne sekundy
    std::string test7 = "09:07"; //
    std::string test8 = "fasfas09:07s";     //dla tych przykladow match nie dziala ofc, ale search tez nie zadziala bo ma downa
    std::string test9 = "fasfas0sges9:07s"; //(aka akceptuje 23:45:60: 1 (60 sie nie zalicza ale on szuka i znajduje wtedy same 23:45)

    std::cout << test1 << ": " << isValidTime(test1) << std::endl;
    std::cout << test2 << ": " << isValidTime(test2) << std::endl;
    std::cout << test3 << ": " << isValidTime(test3) << std::endl;
    std::cout << test4 << ": " << isValidTime(test4) << std::endl;
    std::cout << test5 << ": " << isValidTime(test5) << std::endl;
    std::cout << test6 << ": " << isValidTime(test6) << std::endl;
    std::cout << test7 << ": " << isValidTime(test7) << std::endl;
    std::cout << test8 << ": " << isValidTime(test8) << std::endl;
    std::cout << test9 << ": " << isValidTime(test9) << std::endl;
    return;
}

void zad3()
{
    std::string streetTest1 = "Marszałkowska";
    std::string streetTest2 = "St John";
    std::string streetTest3 = "123street";  // Błędny - nie może zawierać cyfr

    std::string postalCodeTest1 = "01-234";
    std::string postalCodeTest2 = "12345";  // Błędny

    std::string houseNumberTest1 = "28";
    std::string houseNumberTest2 = "28B";
    std::string houseNumberTest3 = "28BB";  // Błędny - tylko jedna litera

    std::string apartmentNumberTest1 = "12";
    std::string apartmentNumberTest2 = "12A";

    // Testowanie nazwy ulicy
    std::cout << "Street Test 1: " << isStreetName(streetTest1) << std::endl;
    std::cout << "Street Test 2: " << isStreetName(streetTest2) << std::endl;
    std::cout << "Street Test 3: " << isStreetName(streetTest3) << std::endl;

    // Testowanie kodu pocztowego
    std::cout << "Postal Code Test 1: " << isPostalCode(postalCodeTest1) << std::endl;
    std::cout << "Postal Code Test 2: " << isPostalCode(postalCodeTest2) << std::endl;

    // Testowanie numeru domu
    std::cout << "House Number Test 1: " << isHouseNumber(houseNumberTest1) << std::endl;
    std::cout << "House Number Test 2: " << isHouseNumber(houseNumberTest2) << std::endl;
    std::cout << "House Number Test 3: " << isHouseNumber(houseNumberTest3) << std::endl;

    // Testowanie numeru mieszkania
    std::cout << "Apartment Number Test 1: " << isApartmentNumber(apartmentNumberTest1) << std::endl;
    std::cout << "Apartment Number Test 2: " << isApartmentNumber(apartmentNumberTest2) << std::endl;

    return;
}

void zad4()
{
    std::string firstName, lastName, age, phoneNumber, email;

    std::cout << "Podaj imie: ";
    std::cin>>firstName;
    if(!isValidFirstName(firstName))
    {
        std::cout << "Nieprawidlowe imie!" << std::endl;
        return;
    }

    std::cout << "Podaj nazwisko: ";
    std::cin>>lastName;
    if (!isValidLastName(lastName))
    {
        std::cout << "Nieprawidlowe nazwisko!" << std::endl;
        return;
    }

    std::cout << "Podaj wiek: ";
    std::cin>>age;
    if (!isValidAge(age))
    {
        std::cout << "Nieprawidlowy wiek!" << std::endl;
        return;
    }

    std::cout << "Podaj numer telefonu (9 cyfr): ";
    std::cin>>phoneNumber;
    if (!isValidPhoneNumber(phoneNumber))
    {
        std::cout << "Nieprawidlowy numer telefonu!" << std::endl;
        return;
    }

    std::cout << "Podaj adres email: ";
    std::cin>>email;
    if (!isValidEmail(email))
    {
        std::cout << "Nieprawidlowy adres email!" << std::endl;
        return;
    }

    saveToFile(firstName, lastName, age, phoneNumber, email);
    return;
}

void zad5()
{
    std::ifstream file("dane.txt");
    if (!file.is_open())
    {
        std::cout << "Nie można otworzyc pliku!" << std::endl;
        return;
    }

    std::vector<std::string> firstNames;
    std::vector<std::string> lastNames;
    std::vector<std::string> phoneNumbers;
    std::vector<std::string> emails;
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string firstName, lastName, age, phoneNumber, email;

        std::getline(ss, firstName, ';');
        std::getline(ss, lastName, ';');
        std::getline(ss, age, ';');
        std::getline(ss, phoneNumber, ';');
        std::getline(ss, email, ';');

        firstNames.push_back(firstName);
        lastNames.push_back(lastName);
        phoneNumbers.push_back(phoneNumber);
        emails.push_back(email);
    }
    file.close();
    //displayPersonsData(firstNames, lastNames, phoneNumbers, emails);
    displayUniqueDomains(emails);
    displayEvenPhoneNumbers(phoneNumbers);
    displayHyphenatedLastNames(lastNames);
    displayFirstNameStatistics(firstNames);

    return;
}

int main()
{

    while(true)
    {
        int choice;
        std::cout<<"Wybierz: "<<std::endl;
        std::cout<<"Zadanie 10.1. Liczba zmiennoprzecinkowa."<<std::endl
                <<"Zadanie 10.2. Godzina."<<std::endl
                <<"Zadanie 10.3. Adres zamieszkania."<<std::endl
                <<"Zadanie 10.4. Kartoteka."<<std::endl
                <<"Zadanie 10.5. Statystyka."<<std::endl;
        std::cin>>choice;
        switch(choice)
        {
        case 1:
            zad1();
            break;

        case 2:
            zad2();
            break;

        case 3:
            zad3();
            break;

        case 4:
            zad4();
            break;

        case 5:
            zad5();
            break;
        }
    }

    return 0;
}
