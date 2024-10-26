#include "contacts.h"


bool Contacts::addContact(const Contact& contact)
{
    auto& phone_index = contacts.get<0>();
    auto it = phone_index.find(contact.phone);
    if(it != phone_index.end())
    {
        return false;  // Numer istniej, przerwij
    }
    contacts.insert(contact);
    return true;
}


bool Contacts::removeContact(const std::string& phone)
{
    auto& phone_index = contacts.get<0>();
    auto it = phone_index.find(phone);
    if(it != phone_index.end())
    {
        phone_index.erase(it);
        return true;
    }
    return false; // Kontakt nie ms
}

// Wyszukaj osoby na tej samej ulicy
std::vector<Contact> Contacts::findByStreet(const std::string& street)
{
    std::vector<Contact> result;
    auto& street_index = contacts.get<1>();
    for(auto it = street_index.lower_bound(street);
         it != street_index.upper_bound(street);
         ++it)
    {
        result.push_back(*it);
    }
    return result;
}


std::vector<Contact> Contacts::findByAgeRange(int minAge, int maxAge)
{
    std::vector<Contact> result;
    auto& age_index = contacts.get<2>();
    for(auto it = age_index.lower_bound(minAge);
         it != age_index.upper_bound(maxAge);
         ++it)
    {
        result.push_back(*it);
    }
    return result;
}

// Wyszukaj osobę po numerze telefonu
Contact* Contacts::findByPhone(const std::string& phone)
{
    auto& phone_index = contacts.get<0>();
    auto it = phone_index.find(phone);
    if(it != phone_index.end())
    {
        return const_cast<Contact*>(&(*it)); // wskaźnik do kontaktu
    }
    return nullptr; // Nie znaleziono
}

// Zmień nazwę ulicy dla wszystkich osób
void Contacts::changeStreetName(const std::string& oldStreet, const std::string& newStreet)
{
    auto& street_index = contacts.get<1>();
    for (auto it = street_index.lower_bound(oldStreet);
         it != street_index.upper_bound(oldStreet);
         ++it)
    {
        const_cast<std::string&>(it->street) = newStreet; // Modyfikacja ulicy
    }
}

// Policz pełnoletnich
int Contacts::countAdults() const
{
    return std::count_if(contacts.begin(), contacts.end(), [](const Contact& c) {
        return c.age >= 18;
    });
}

// Policz unikatowe nazwiska
int Contacts::countUniqueLastNames()
{
    std::set<std::string> lastNames;
    for (const auto& contact : contacts)
    {
        //imie i nazwisjko jedno pole -> dizelenie po spacji i git xd
        std::string lastName = contact.name.substr(contact.name.find_last_of(" ") + 1);
        lastNames.insert(lastName);
    }
    return lastNames.size();
}

void Contacts::showAllContacts() const
{
    for (const auto& contact : contacts)
    {
        contact.show();
    }
}
