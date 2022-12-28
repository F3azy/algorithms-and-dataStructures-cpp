#ifndef SORTING_H__
#define SORTING_H__

#include <iostream>

template <class T>
class Sorting {
    private:
        Sorting();

        static void swap(T& a, T& b);
        static void bubbleSort(T tab[], int size, std::string order);
        static void selectionSort(T tab[], int size, std::string order);

    public: 
        static void sort(T tab[], int size, std::string sort = "default", std::string order = "ASC");

};

/**
 * Sort numbers in an array with the chosen sorting algorithm.
 *
 * @param tab an array,
 * @param size size of the array,
 * @param sort choose sorting alorithm {"BUBBLE" - bubble sort,  }
 * @param order choose sorting order {default "ASC" - ascending order, "DESC" - descending order}
 */
template <class T>
void Sorting<T>::sort(T tab[], int size, std::string sort /*= "default"*/, std::string order /*= "ASC"*/) {

    if(size < 2) {
        std::cout << "The array size must be >= 2";
        exit(0);
    }

    int sortCase = 0;

    if(sort == "BUBBLE") sortCase = 1;
    else if(sort == "SELECTION") sortCase = 2;


    switch (sortCase)
    {
        case 1:
            Sorting<T>::bubbleSort(tab, size, order);
            break;
        case 2:
            Sorting<T>::selectionSort(tab, size, order);
            break;
        
        default:
            break;
    }
}

template <class T>
void Sorting<T>::swap(T& a, T& b) {
    T c(a);
    a = b;
    b = c;
}

template <class T>
void Sorting<T>::bubbleSort(T tab[], int size, std::string order) {
    for (int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - i - 1; j++)
        {
            if(order == "ASC") {
                if(tab[j] > tab[j+1]) Sorting<T>::swap(tab[j], tab[j+1]);
            }
            else if(order == "DESC") {
                if(tab[j] < tab[j+1]) Sorting<T>::swap(tab[j], tab[j+1]); 
            }
        } 
}

template <class T>
void Sorting<T>::selectionSort(T tab[], int size, std::string order) {

}


#endif