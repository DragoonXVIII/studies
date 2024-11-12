#include <iostream>
#include <set>
#include <algorithm>
#include <map>

#include "dictionary.h"

using namespace std;

void show( set <int> s)
{
    set<int>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr<<" ";
    }
    cout<<endl;
}

void showMap( map<string, int> m)
{
    cout<<endl<<"m: "<<endl;
    map<string, int>::iterator it;
    for(it=m.begin(); it!=m.end(); ++it)
    {
        cout << it->first <<"  "<<it->second<<endl;
    }
    cout<<endl;
}

map<string, int>::iterator
searchByValue(map<string, int>&  m, int val)
{
    map<string, int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
        if(it->second == val)
            break;
    return it;
}

std::pair<int, int> findDuplicateAndSum(const std::vector<int>& vec)
{
    std::set<int> uniqueElements;
    int duplicate = -1;
    int sumUnique = 0;

    for (const int& num : vec)
    {
        if(uniqueElements.find(num) != uniqueElements.end())    //Iterator do elementu num w zbiorze, jeśli został znaleziony.
        {                                                        //uniqueElements.end(), jeśli num nie został znaleziony.
            duplicate = num;
        }
        else
        {
            uniqueElements.insert(num);
            sumUnique += num;
        }
    }
    if(duplicate != -1)
        sumUnique -= duplicate;
    return std::make_pair(duplicate, sumUnique);
}

template <typename T>
void displaySymmetricDifference(const std::set<T>& set1, const std::set<T>& set2)
{
    std::set<T> result;
    std::set_symmetric_difference(
                set1.begin(), set1.end(),
                set2.begin(), set2.end(),
                std::inserter(result, result.begin())
                );

    std::cout << "Elementy tylko w jednym z zbiorow:\n";
    for (const auto& elem : result)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

char findAddedCharacter(const std::string& str1, const std::string& str2)
{
    std::map<char, int> charCount;

    for (char ch : str1)
    {
        charCount[ch]++;
    }

    for (char ch : str2)
    {
        charCount[ch]++;
    }

    for (const auto& entry : charCount)
    {
        if (entry.second % 2 != 0) //no bo jak jesty nieparzyscie tzn ze on sie nie powtorzyl mozw byc 3:3 (czyli 6) ale nie 4:3
        {
            return entry.first;
        }
    }

    return '\0';
}

void zad0()
{
    set <int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(3);
    show(s);
    s.erase(s.begin(), s.find(2));
    show(s);
    s.erase(2);
    cout<<s.count(2)<<endl;


    set <int> s1={1,2,3,7};
    set<int>s2={-2,4,1,7,6};
    cout<<"s1: ";
    show(s1);
    cout<<"s2: ";
    show(s2);
    set<int>sUnion,sIntersec,sDiffer;

    set_union(s1.begin(),s1.end(),s2.begin(),s2.end(), insert_iterator(sUnion,sUnion.begin()));
    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(), insert_iterator(sIntersec,sIntersec.begin()));
    set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(), insert_iterator(sDiffer,sDiffer.begin()));
    cout<<"sUnion: ";
    show(sUnion);
    cout<<"sIntersec: ";
    show(sIntersec);
    cout<<"sDiffer: ";
    show(sDiffer);

    set<int> s3={3,8};

    pair <set<int>::iterator, bool> res;

    res=s3.insert(6);
    cout<<"Dodany element: "<<*(res.first)<<endl;
    cout<<"Czy element dodany? "<<res.second<<endl;
    show(s3);

    map<string,int> m;

    m.insert(pair<string,int>("Kowalski",4500));
    m.insert(make_pair("Nowak",2000));
    m["Adamek"]=3000;
    showMap(m);
    int salary=m.find("Kowalski")->second;
    cout<<"Zarobki Kowalskiego: "<<salary<<endl;
    m.erase("Adamek");
    showMap(m);
    cout<< "Czy jest Kowalski? "<<m.count("Kowalski")<<endl;

    map<string, int>::iterator it = searchByValue(m, 2000);
    if(it != m.end())
        cout<<"Element znaleziony: "<<it->first<<" "<<
              it->second<<endl;
    else
        cout<<"Brak elementu"<<endl;

    return;
}

void zad1()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);
    std::pair<int, int> s1 = findDuplicateAndSum(v1);
    std::cout<<s1.first<<", "<<s1.second<<std::endl;
}

void zad2()
{
    std::set<int> set1 = {1, 2, 3, 4, 5};
    std::set<int> set2 = {4, 5, 6, 7, 8};

    displaySymmetricDifference(set1, set2); 

    return;
}

void zad3()
{
    std::string str1 = "W main nalezy przetestowac funkcje";
    std::string str2 = "W main nalezy, funkcje przetestowac";

    char addedChar = findAddedCharacter(str1, str2); 

    if (addedChar != '\0') {
        std::cout << "Dodany znak: " << addedChar << std::endl;
    } else {
        std::cout << "Nie znaleziono dodanego znaku." << std::endl;
    }
    return;
}

void zad4()
{
    Dictionary dict;

    // Dod
    dict.addWord("kot", "cat");
    dict.addWord("pies", "dog");
    dict.addWord("dom", "house");

    // show
    dict.displayDictionary();

    // show trans
    dict.translate("kot");

    // del
    dict.removeWord("kot");

    // show
    dict.displayDictionary();

    //show sorted
    dict.displaySortedByTranslation();
    return;
}

int main()
{

    //zad0();

    //zad1();

    //zad2();

    //zad3();

    zad4();

    return 0;

}
