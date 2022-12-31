#ifndef DYNAMICARRAY_H__
#define DYNAMICARRAY_H__

#include <iostream>
#include "Searching.h"
#include "Sorting.h"

template <class  T>
class DynamicArray {
    private:
        T* array;
        unsigned int arraySize;
        unsigned int arrayOccupied;

        void increaseArraySize();
    public:
        DynamicArray();
        DynamicArray(int);
        ~DynamicArray();
        T* getArray();
        int getSize();
        int getOccupied();
        void push(T);
        void pop();
        bool empty();
        void clear();
        int indexOf(int);
        int* allIndexOf(int);
        int allIndexOfCount(int);
        void sort(std::string = "ASC");
        T& operator[](int);
        template<typename U>
        friend std::ostream& operator<<(std::ostream&, const DynamicArray<U>&);
};

template <class T>
DynamicArray<T>::DynamicArray()
{
    this->arraySize = 1;
    this->arrayOccupied = 0;
    this->array = new T[this->arraySize];
}

template <class T>
DynamicArray<T>::DynamicArray(int size)
{
    if(size > 0) {
        this->arraySize = size;
        this->arrayOccupied = 0;
        this->array = new T[this->arraySize];   
    }
    else {
        std::cout << "\nArray size not valid, must be > 0 (created array with array size 1)\n";
        this->arraySize = 1;
        this->arrayOccupied = 0;
        this->array = new T[this->arraySize];
    }
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
    delete[] this->array;
}

template <class T>
T* DynamicArray<T>::getArray()
{
    return array;
}

template <class T>
int DynamicArray<T>::getSize()
{
    return arraySize;
}

template <class T>
int DynamicArray<T>::getOccupied()
{
    return arrayOccupied;
}

template <class T>
void DynamicArray<T>::increaseArraySize()
{
    T* temp = new T[arraySize+1];

    for (int i = 0; i < arraySize; i++) temp[i] = array[i];

    array = temp;
    arraySize++;
}

template <class T>
void DynamicArray<T>::push(T item)
{
    if(arrayOccupied == arraySize) increaseArraySize();

    array[arrayOccupied] = item;

    arrayOccupied++;
}

template <class T>
void DynamicArray<T>::pop()
{
    if(arraySize > 0 && arrayOccupied > 0)
    {
        T* temp = new T[arraySize-1];

        for (int i = 0; i < arraySize-1; i++) temp[i] = array[i];

        delete [] array;

        array = temp;
        arraySize--;
        arrayOccupied--;
    }
    else
        std::cout << "\nThere is nothing in the array to pop out\n";
}

template <class T>
bool DynamicArray<T>::empty()
{
    return !(arrayOccupied > 0);
}

template <class T>
void DynamicArray<T>::clear()
{
    if(arraySize != 0)
    {
        delete [] array;
        arraySize = 1;
        arrayOccupied = 0;
        array = new T[arraySize];
    }
}

template <class T>
int DynamicArray<T>::indexOf(int value) {
    return Searching<T>::search(array, arrayOccupied, value);
}

template <class T>
int* DynamicArray<T>::allIndexOf(int value) {
    return Searching<T>::searchAll(array, arrayOccupied, value);
}

template <class T>
int DynamicArray<T>::allIndexOfCount(int value) {
    return Searching<T>::searchCount(array, arrayOccupied, value);
}

template <class T>
void DynamicArray<T>::sort(std::string order) {
    Sorting<T>::sort(array, arrayOccupied, "MERGE", order);
}

template <class T>
T& DynamicArray<T>::operator[](int i)
{
    if (i >= arraySize) {
        std::cout << "\nArray index out of bound\n";
        exit(0);
    }

    return array[i];
}

template <class T>
std::ostream& operator<<(std::ostream &os, const DynamicArray<T> &dt)
{
    for (int i = 0; i < dt.arrayOccupied; i++)
    {
        os << dt.array[i] << " ";
    }

    return os;
}


#endif