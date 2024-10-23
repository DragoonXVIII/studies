#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

#include "contact.h"

using namespace boost::multi_index;

class Contacts
{
    public:
        typedef multi_index_container<
        Contact,
        indexed_by<
        hashed_unique<member<Contact, std::string, &Contact::phone>>,  // Unikatowy numer telefonu
        ordered_non_unique<member<Contact, std::string, &Contact::street>>, // Ulica
        ordered_non_unique<member<Contact, int, &Contact::age>>             // Wiek
        >
        > contact_multi;

    private:
        contact_multi contacts;

    public:
        //Contacts() = default;
        // Dodaj nowy kontakt
        bool addContact(const Contact& contact);

        // Usuń kontakt po numerze telefonu
        bool removeContact(const std::string& phone);
        // Wyszukaj osoby na tej samej ulicy
        std::vector<Contact> findByStreet(const std::string& street);

        // Wyszukaj osoby w przedziale wiekowym
        std::vector<Contact> findByAgeRange(int minAge, int maxAge);

        // Wyszukaj osobę po numerze telefonu
        Contact* findByPhone(const std::string& phone);

        // Zmień nazwę ulicy dla wszystkich osób
        void changeStreetName(const std::string& oldStreet, const std::string& newStreet);

        // Policz pełnoletnich
        int countAdults() const;

        // Policz unikatowe nazwiska
        int countUniqueLastNames();
        // Wyświetl wszystkie kontakty
        void showAllContacts() const;
};
