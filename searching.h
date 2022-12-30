#ifndef SEARCHING_H_
#define SEARCHING_H_

#include <iostream>
#include "dynamicArray.h"

template <class T>
class Searching {
    private:
        Searching();

        static int linearSearch(T[], int, int);
        static int binarySearch(T[], int, int);

        static int* linearSearchAll(T[], int, int);
        static int* binarySearchAll(T[], int, int);

        static int linearSearchAllCount(T[], int, int);
        static int binarySearchAllCount(T[], int, int);

    public: 
        static int search(T[], int, int, std::string = "LINEAR");
        static int* searchAll(T[], int, int, std::string = "LINEAR");
        static int searchCount(T[], int, int, std::string = "LINEAR");

};

/**
 * Return the index of the searched value in the given array with the chosen searching algorithm.
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

/**
 * Return the indexs of the searched value in the given array with the chosen searching algorithm.
 *
 * @param tab an array,
 * @param size size of the array,
 * @param value searched value,
 * @param search choose searching alorithm {default "LINEAR" - linear sort,  "BIN" - binary sort}
 */
template <class T>
int* Searching<T>::searchAll(T tab[], int size, int value, std::string search /*= "LINEAR"*/) {

    if(size < 0) {
        std::cout << "The array size must be >= 1";
        exit(0);
    }

    int searchCase = 0;

    if(search == "BIN") searchCase = 1;

    switch (searchCase)
    {
        case 1:
            return Searching<T>::binarySearchAll(tab, size, value);
            break;
        
        default:
            return Searching<T>::linearSearchAll(tab, size, value);
            break;
    }
}

template <class T>
int* Searching<T>::linearSearchAll(T tab[], int size, int value) {
    dynamicArray<int> idx;

    for (int i = 0; i < size; i++)
        if(tab[i] == value) 
            idx.push(i);
    
    if(idx.empty()) return nullptr;
    else {
        int* temp = new int[idx.getOccupied()];
        for (int i = 0; i < idx.getOccupied(); i++) temp[i] = idx[i];

        return temp;
    }
}

template <class T>
int* Searching<T>::binarySearchAll(T tab[], int size, int value) {
    return nullptr;
}

/**
 * Return the count of how many times the value was found in the array.
 *
 * @param tab an array,
 * @param size size of the array,
 * @param value searched value,
 * @param search choose searching alorithm {default "LINEAR" - linear sort,  "BIN" - binary sort}
 */
template <class T>
int Searching<T>::searchCount(T tab[], int size, int value, std::string search /*= "LINEAR"*/) {

    if(size < 0) {
        std::cout << "The array size must be >= 1";
        exit(0);
    }

    int searchCase = 0;

    if(search == "BIN") searchCase = 1;

    switch (searchCase)
    {
        case 1:
            return Searching<T>::binarySearchAllCount(tab, size, value);
            break;
        
        default:
            return Searching<T>::linearSearchAllCount(tab, size, value);
            break;
    }
}

template <class T>
int Searching<T>::linearSearchAllCount(T tab[], int size, int value) {
    int count = 0;

    for (int i = 0; i < size; i++)
        if(tab[i] == value) 
            count++;
    
    if(count != 0) return count;
    else return -1;
}

template <class T>
int Searching<T>::binarySearchAllCount(T tab[], int size, int value) {
    return -1;
}

#endif