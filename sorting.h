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
        static void insertionSort(T tab[], int size, std::string order);
        static void merge(T tab[], int p, int q, int r);
        static void mergeSort(T tab[], int p, int r, std::string order);

    public: 
        static void sort(T tab[], int size, std::string sort = "default", std::string order = "ASC");

};

/**
 * Sort numbers in an array with the chosen sorting algorithm.
 *
 * @param tab an array,
 * @param size size of the array,
 * @param sort choose sorting alorithm {"BUBBLE" - bubble sort,  "SELECTION" - selection sort, "INSERTION" - insertion sort, "MERGE" - merge sort}
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
    else if(sort == "INSERTION") sortCase = 3;
    else if(sort == "MERGE") sortCase = 4;


    switch (sortCase)
    {
        case 1:
            Sorting<T>::bubbleSort(tab, size, order);
            break;
        case 2:
            Sorting<T>::selectionSort(tab, size, order);
            break;
        case 3:
            Sorting<T>::insertionSort(tab, size, order);
            break;
        case 4:
            Sorting<T>::mergeSort(tab, 0, size-1, order);
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
    for (int i = 0; i < size - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < size; j++) {
            if(order == "ASC") {
                if(tab[idx] > tab[j]) idx = j;
            }
            else if(order == "DESC") {
                if(tab[idx] < tab[j]) idx = j; 
            }
        }
        Sorting<T>::swap(tab[idx], tab[i]);
    }  
}

template <class T>
void Sorting<T>::insertionSort(T tab[], int size, std::string order) {
    for (int i = 1; i < size; i++) {
        int key = i;
        for (int j = i; j > 0; j--)
        {
            if(order == "ASC") {
                if(tab[key] < tab[j - 1]) {
                    Sorting<T>::swap(tab[key], tab[j-1]);
                    key = j - 1;
                }
                else break;
            }
            else if(order == "DESC") {
                if(tab[key] > tab[j - 1]) {
                    Sorting<T>::swap(tab[key], tab[j-1]);
                    key = j - 1;
                }
                else break;
            }
        }  
    }
}

template <class T>
void Sorting<T>::merge(T tab[], int p, int q, int r) {
    int size1 = q - p + 1;
    int size2 = r - q;

    T L[size1], M[size2];

    for (int i = 0; i < size1; i++)
        L[i] = tab[p+1];
    for (int i = 0; i < size2; i++)
        M[i] = tab[q+1+j];
    

    int i=j=0, k=p;

    while(i < size1 && j < size2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = M[j];
        j++;
        k++;
    }

}

template <class T>
void Sorting<T>::mergeSort(T tab[], int p, int r, std::string order) {
    int q;
    if(order == "ASC") {
        if(p > r) {
            q = (p+r) / 2;
            mergeSort(tab, p, q);
            mergeSort(tab, q + 1, r);
            merge(tab, p, q, r);
        }
    }
    else if(order == "DESC") {
        if(p < r) {
            q = (p+r) / 2;
            mergeSort(tab, p, q);
            mergeSort(tab, q + 1, r);
            merge(tab, p, q, r);
        } 
    }
}


#endif