#include "array.h"

template <typename T>
Array<T>::Array()
{
    this->maxSize = 10;
    this->array = new T[10];
    this->firstAvail = 0;
}

template <typename T>
Array<T>::Array(int maxSize)
{
    this->maxSize = maxSize;
    this->array = new T[maxSize];
    this->firstAvail = 0;
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->array;
}

template <typename T>
void Array<T>::sortAscending()
{
    std::sort(this->array, this->array + firstAvail);
}

template <typename T>
void Array<T>::showArray()
{
    for(int i=0; i<this->firstAvail; i++)
    {
        std::cout<<this->array[i]<<", ";
    }
    std::cout<<std::endl;
}

template <typename T>
void Array<T>::addEl(T el)
{
    if(this->firstAvail > this->maxSize-1)
    {
        throw std::overflow_error("Tablica jest pelna.");
        return;
    }
    else
    {
        this->array[firstAvail] = el;
        this->firstAvail++;
    }
}

template <typename T>
T Array<T>::getMaxEl() const
{
    if(this->firstAvail == 0)
        throw std::runtime_error("Tablica jest pusta.");
    T maxEl = this->array[0];
    for(int i=0; i<this->firstAvail; i++)
    {
        if(maxEl < this->array[i])
            maxEl = this->array[i];
    }

    return maxEl;
}

template <typename T>
T Array<T>::getNEl(int n) const
{
    if (n >= this->firstAvail || n < 0)
            throw std::out_of_range("Niepoprawny indeks.");
    return this->array[n];
}





Array<std::string>::Array()
{
    this->maxSize = 10;
    this->array = new std::string[10];
    this->firstAvail = 0;
}

Array<std::string>::Array(int maxSize)
{
    this->maxSize = maxSize;
    this->array = new std::string[maxSize];
    this->firstAvail = 0;
}

Array<std::string>::~Array()
{
    delete[] this->array;
}

void Array<std::string>::sortAscending()
{
    sort(this->array, this->array + this->firstAvail, [](const std::string& a, const std::string& b)
    {
        return a.length() < b.length();
    });
}

void Array<std::string>::showArray()
{
    for(int i=0; i<this->firstAvail; i++)
    {
        std::cout<<this->array[i]<<", ";
    }
    std::cout<<std::endl;
}

void Array<std::string>::addEl(std::string el)
{
    if(this->firstAvail > this->maxSize-1)
    {
        throw std::overflow_error("Tablica jest pelna.");
        return;
    }
    else
    {
        this->array[firstAvail] = el;
        this->firstAvail++;
    }
}

std::string Array<std::string>::getMaxEl() const
{
    if(this->firstAvail == 0)
        throw std::runtime_error("Tablica jest pusta.");
    std::string maxEl = this->array[0];
    for(int i=0; i<this->firstAvail; i++)
    {
        if(maxEl.size() < this->array[i].size())
            maxEl = this->array[i];
    }

    return maxEl;
}

std::string Array<std::string>::getNEl(int n) const
{
    if (n >= this->firstAvail || n < 0) // dodano sprawdzenie zakresu
            throw std::out_of_range("Niepoprawny indeks.");
    return this->array[n];
}

template class Array<int>;
template class Array<std::string>;


/*
template <typename T>
class Array
{
    private:
        int maxSize;
        int firstAvail;
        T *array;   //pole do przechowywania tablicy o typie T*,
    public:
        Array(); //bezargumentowy, 10 maxSize
        Array(int maxSize): maxSize(maxSize){}; //argumentowy, przydzieli pamiec;
        ~Array(); //zwolni pamiec

        void sortAscending();
        void showArray();
        void addEl();

        T getMaxEl() const;
        T getNEl(int n) const;
};

template <>
class Array<std::string>
{
    private:
        int maxSize;
        int firstAvail;
        std::string *array;   //pole do przechowywania tablicy o typie T*,
    public:
        Array(); //bezargumentowy, 10 maxSize
        Array(int maxSize): maxSize(maxSize){}; //argumentowy, przydzieli pamiec;
        ~Array(); //zwolni pamiec

        void sortAscending();
        void showArray();
        void addEl();

        std::string getMaxEl() const;
        std::string getNEl(int n) const;
};
*/
