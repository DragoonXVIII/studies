#include "city.h"

/*
    private:
        std::vector <Citizen> citizens;
        std::string cityName;
    public:
        City(std::string cityName): cityName(cityName){};
        void addCitizen(Citizen citizen);
        void deleteCitizen(std::string name, std::string surname);
        void show_citizens();
        void show_city();
        int men();
        int women();
        int city_citizens();
        int adults();
        void postal_codes(); //std::multimap<std::string, std::string> postal_codes;
*/
void City::show_city() const
{
    std::cout<<this->cityName<<std::endl;
    return;
}

void City::addCitizen(Citizen citizen)
{

    this->citizens.push_back(citizen);

    return;
}

void City::deleteCitizen(std::string name, std::string surname)
{
    this->citizens.erase(std::remove_if(this->citizens.begin(), this->citizens.end(), [name, surname](const Citizen& c)
    {
        return c.getName() == name && c.getSurname() == surname;
    }),
                         citizens.end()
                         );
    return;
}

void City::show_citizens() const
{
    std::cout<<this->citizens.size()<<std::endl;
    if (!citizens.empty()) {
        for (const auto& citizen : citizens) {
            citizen.show();
        }
    } else {
        std::cout << "Wektor jest pusty!" << std::endl;
    }
    /*
    for(const auto& citizen : citizens)
    {
        citizen.show();
    }*/
    return;
}

int City::getMen() const
{
    int numberOfMen = 0;
    char value = 'm';
    for (const auto& citizen : this->citizens)
    {
        if (citizen.getSex() == value)
        {
            numberOfMen++;
        }
    }
    return numberOfMen;
}

int City::getWomen() const
{
    int numberOfWomen = 0;
    char value = 'f';
    for (const auto& citizen : this->citizens)
    {
        if (citizen.getSex() == value)
        {
            numberOfWomen++;
        }
    }
    return numberOfWomen;
}

int City::getCityCitizens() const
{
    return citizens.size();
}

int City::getAdults() const
{
    int numberAdults = 0;
    int value = 18;
    for (const auto& citizen : this->citizens)
    {
        if (citizen.getAge() >= value)
        {
            numberAdults++;
        }
    }
    return numberAdults;;
}

void City::postal_codes() const
{
    std::multimap<std::string, std::string> postal_codes;

    for(const auto& citizen : this->citizens)
    {
        postal_codes.insert({citizen.getName(), citizen.getSurname()});
    }

    std::cout << "Zestawienie adresów i liczby osób mieszkających pod nimi:\n";


    std::string lastAddress = "";
    for (auto it = postal_codes.begin(); it != postal_codes.end(); )
    {
        std::string currentAddress = it->first;

        int count = postal_codes.count(currentAddress);

        std::cout << currentAddress << ": " << count << " osoby" << std::endl;
        it = postal_codes.upper_bound(currentAddress);
    }

    return;
}

int City::uniquePostalCodes() const
{
    std::set <std::string> tmp;
    for(int i=0; i<this->getCityCitizens(); i++)
    {
        tmp.insert(this->citizens.at(i).getPostalCode());
    }
    //std::cout<<"Miasto: "; this->show_city();
    //std::cout<<"Liczba kodow: "<<tmp.size()<<"\n";
    return tmp.size();
}
