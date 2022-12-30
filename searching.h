#ifndef SEARCHING_H_
#define SEARCHING_H_

#include <iostream>

template <class T>
class Searching {
    private:
        Searching();

        static int linearSearch(T tab[], int size, int value);
        static int binarySearch(T tab[], int size, int value);

    public: 
        static int search(T tab[], int size, int value, std::string search = "LINEAR");

};

/**
 * Search the index/indexes of the searched value in the given array with the chosen searching algorithm.
 *
 * @param tab an array,
 * @param size size of the array,
 * @param value searched value,
 * @param search choose searching alorithm {default "LINEAR" - linear sort,  "BIN" - binary sort}
 */
template <class T>
int Searching<T>::search(T tab[], int size, int value, std::string search /*= "LINEAR"*/) {

    if(size < 0) {
        std::cout << "The array size must be >= 1";
        exit(0);
    }

    int searchCase = 0;

    if(search == "BIN") searchCase = 1;

    switch (searchCase)
    {
        case 1:
            return Searching<T>::binarySearch(tab, size, value);
            break;
        
        default:
            return Searching<T>::linearSearch(tab, size, value);
            break;
    }
}

template <class T>
int Searching<T>::linearSearch(T tab[], int size, int value) {
    for (int i = 0; i < size; i++)
        if(tab[i] == value) 
            return i;
    
    return -1;
}

template <class T>
int Searching<T>::binarySearch(T tab[], int size, int value) {
    return -1;
}

#endif