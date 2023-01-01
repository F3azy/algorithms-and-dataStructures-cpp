#include "Searching.h"
#include <iostream>
#include "DynamicArray.h"

/**
 * Return the index of the searched value in the given array with the chosen searching algorithm.
 *
 * @param tab an array,
 * @param size size of the array,
 * @param value searched value,
 * @param search choose searching alorithm {default "LINEAR" - linear sort,  "BIN" - binary sort}
 */
template <class T>
int Searching<T>::find(T tab[], int size, T value, std::string search /*= "LINEAR"*/) {

    if(size < 0) {
        std::cout << "The array size must be >= 1";
        exit(0);
    }

    int searchCase = 0;

    if(search == "BIN") searchCase = 1;

    switch (searchCase)
    {
        case 1:
            return Searching<T>::binarySearch(tab, 0, size - 1, value);
            break;
        
        default:
            return Searching<T>::linearSearch(tab, size, value);
            break;
    }
}

template <class T>
int Searching<T>::linearSearch(T tab[], int size, T value) {
    for (int i = 0; i < size; i++)
        if(tab[i] == value) 
            return i;
    
    return -1;
}

template <class T>
int Searching<T>::binarySearch(T tab[], int l, int r, T value, std::string  method /*= "LINEAR"*/) {

    int methodCase = 0;

    if(method == "RECURSIVE") methodCase = 1;

    switch (methodCase)
    {
        case 1:
            return Searching<T>::binaryRecursive(tab, l, r, value);
            break;
        
        default:
            return Searching<T>::binaryIterative(tab, l, r, value);
            break;
    }

    return -1;
}

template <class T>
int Searching<T>::binaryIterative(T tab[], int l, int r, T value) {
    do
    {
        int mid = (l+r)/2; 

        if(tab[mid] == value) return mid;
        else if(tab[mid] > value) r = mid - 1;
        else l = mid + 1;

    } while (l <= r);

    return -1;
}

template <class T>
int Searching<T>::binaryRecursive(T tab[], int l, int r, T value) {
    if(l<=r) {
        int mid = (l+r)/2;

        if(tab[mid] == value) return mid;
        else if(tab[mid] > value) return Searching<T>::binaryRecursive(tab, l, mid - 1, value);
        else return Searching<T>::binaryRecursive(tab, mid + 1, r, value);
    }

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
int* Searching<T>::findAll(T tab[], int size, T value, std::string search /*= "LINEAR"*/) {

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
int* Searching<T>::linearSearchAll(T tab[], int size, T value) {
    DynamicArray<int> idx;

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
int* Searching<T>::binarySearchAll(T tab[], int size, T value) {
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
int Searching<T>::findCount(T tab[], int size, T value, std::string search /*= "LINEAR"*/) {

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
int Searching<T>::linearSearchAllCount(T tab[], int size, T value) {
    int count = 0;

    for (int i = 0; i < size; i++)
        if(tab[i] == value) 
            count++;
    
    if(count != 0) return count;
    else return -1;
}

template <class T>
int Searching<T>::binarySearchAllCount(T tab[], int size, T value) {
    return -1;
}
