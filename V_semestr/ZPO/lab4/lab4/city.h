#ifndef CITY_H
#define CITY_H
#include "citizen.h"
#include <vector>
#include <map>
#include <algorithm>
#include <set>

class City
{
    private:
        std::vector<Citizen> citizens;
        std::string cityName;
    public:
        City(std::string cityName): cityName(cityName){};
        void addCitizen(Citizen citizen);
        void deleteCitizen(std::string name, std::string surname);
        void show_citizens() const;
        void show_city() const;
        int getMen() const;
        int getWomen() const;
        int getCityCitizens() const;
        int getAdults() const;
        void postal_codes() const; //std::multimap<std::string, std::string> postal_codes;
        int uniquePostalCodes() const;
};

#endif // CITY_H
