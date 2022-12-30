#ifndef DYNAMICARRAY_H__
#define DYNAMICARRAY_H

#include <iostream>

template <class  T>
class dynamicArray {
    private:
        T* array;
        unsigned int arraySize;
        unsigned int arrayOccupied;

        void increaseArraySize();
    public:
        dynamicArray();
        dynamicArray(int);
        ~dynamicArray();
        int getSize();
        int getOccupied();
        void push(T);
        void pop();
        bool empty();
        void clearAll();
        T& operator[](int);
        template<typename U>
        friend std::ostream& operator<<(std::ostream&, const dynamicArray<U>&);
};

template <class T>
dynamicArray<T>::dynamicArray()
{
    this->arraySize = 1;
    this->arrayOccupied = 0;
    this->array = new T[this->arraySize];
}

template <class T>
dynamicArray<T>::dynamicArray(int size)
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
dynamicArray<T>::~dynamicArray()
{
    delete[] this->array;
}

template <class T>
int dynamicArray<T>::getSize()
{
    return arraySize;
}

template <class T>
int dynamicArray<T>::getOccupied()
{
    return arrayOccupied;
}

template <class T>
void dynamicArray<T>::increaseArraySize()
{
    T* temp = new T[arraySize+1];

    for (int i = 0; i < arraySize; i++) temp[i] = array[i];

    array = temp;
    arraySize++;
}

template <class T>
void dynamicArray<T>::push(T item)
{
    if(arrayOccupied == arraySize) increaseArraySize();

    array[arrayOccupied] = item;

    arrayOccupied++;
}

template <class T>
void dynamicArray<T>::pop()
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
bool dynamicArray<T>::empty()
{
    return !(arrayOccupied > 0);
}

template <class T>
void dynamicArray<T>::clearAll()
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
T& dynamicArray<T>::operator[](int i)
{
    if (i >= arraySize) {
        std::cout << "\nArray index out of bound\n";
        exit(0);
    }

    return array[i];
}

template <class T>
std::ostream& operator<<(std::ostream &os, const dynamicArray<T> &dt)
{
    for (int i = 0; i < dt.arrayOccupied; i++)
    {
        os << dt.array[i] << " ";
    }

    return os;
}


#endif