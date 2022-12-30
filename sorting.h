#ifndef SORTING_H__
#define SORTING_H__

#include <iostream>
#include <type_traits>

template <class T>
class Sorting {
    private:
        Sorting();

        static void swap(T&, T&);
        static void bubbleSort(T[], int, std::string);
        static void selectionSort(T[], int, std::string);
        static void insertionSort(T[], int, std::string);
        static void merge(T[], int, int, int, std::string);
        static void mergeSort(T[], int, int, std::string);
        static int partition(T[], int, int, std::string);
        static void quickSort(T[], int, int, std::string);
        static void countingSort(T[], int, std::string);

    public: 
        static void sort(T[], int, std::string = "default", std::string = "ASC");

};

/**
 * Sort numbers in an array with the chosen sorting algorithm.
 *
 * @param tab an array,
 * @param size size of the array,
 * @param sort choose sorting alorithm {"BUBBLE" - bubble sort,  "SELECTION" - selection sort, "INSERTION" - insertion sort, "MERGE" - merge sort, "QUICK" - quick sort, "COUNT" -  counting sort}
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
    else if(sort == "QUICK") sortCase = 5;
        else if(sort == "COUNT") sortCase = 6;


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
        case 5:
            Sorting<T>::quickSort(tab, 0, size-1, order);
            break;
        case 6:
            if(typeid(tab) != typeid(int*)) {
                std::cout << std::endl << "Array type must be of type int for counting sort\n";
                return;
            }
            else Sorting<T>::countingSort(tab, size, order);
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
void Sorting<T>::merge(T tab[], int p, int q, int r, std::string order) {
    int size1 = q - p + 1;
    int size2 = r - q;

    T L[size1], M[size2];

    for (int i = 0; i < size1; i++) L[i] = tab[p+i];

    for (int j = 0; j < size2; j++) M[j] = tab[q+1+j];
    

    int i, j, k;
    i=0;
    j=0;
    k=p;

    while(i < size1 && j < size2) {
        if(order == "ASC") {
            if (L[i] <= M[j]) {
                tab[k] = L[i];
                i++;
            } else {
                tab[k] = M[j];
                j++;
            }
        }
        else if(order == "DESC") {
            if (L[i] >= M[j]) {
                tab[k] = L[i];
                i++;
            } else {
                tab[k] = M[j];
                j++;
            }
        }

        k++;
    }

    while (i < size1) {
        tab[k] = L[i];
        i++;
        k++;
    }

    while (j < size2) {
        tab[k] = M[j];
        j++;
        k++;
    }
}

template <class T>
void Sorting<T>::mergeSort(T tab[], int l, int r, std::string order) {
    if(l < r) {
        int q = l + (r - l) / 2;
        Sorting<T>::mergeSort(tab, l, q, order);
        Sorting<T>::mergeSort(tab, q + 1, r, order);
        
        Sorting<T>::merge(tab, l, q, r, order);
    }
}

template <class T>
int Sorting<T>::partition(T tab[], int l, int r, std::string order) {
    int pivotIdx = r;

    int storeIdx = l - 1;

    for (int i = l; i < r; i++)
    {
        if(order == "ASC") {
            if(tab[i] <= tab[pivotIdx]) {
                storeIdx++;
                Sorting<T>::swap(tab[i], tab[storeIdx]);
            }
        }
        else if(order == "DESC") {
            if(tab[i] >= tab[pivotIdx]) {
                storeIdx++;
                Sorting<T>::swap(tab[i], tab[storeIdx]);
            }
        }
    }

    Sorting<T>::swap(tab[r], tab[storeIdx + 1]);
    
    return storeIdx + 1;
}

template <class T>
void Sorting<T>::quickSort(T tab[], int l, int r, std::string order) {
    if(l < r) {
        int pivotIdx = Sorting<T>::partition(tab, l, r, order);
        Sorting<T>::quickSort(tab, l, pivotIdx - 1, order);
        Sorting<T>::quickSort(tab, pivotIdx + 1, r, order);
    }
}

template <class T>
void Sorting<T>::countingSort(T tab[], int size, std::string order) {
    int max = tab[0];
    int min = tab[0];

    for (int i = 1; i < size; i++) {
        if(max < tab[i]) max = tab[i];
        if(min > tab[i]) min = tab[i];
    }

    int range = max - min + 1;

    int* count = new int[range];

    for (int i = 0; i < range; i++) count[i] = 0;
    for (int i = 0; i < size; i++)  count[tab[i] - min]++;
    
    for(int i = 1; i < range ; i++) count[i]+=count[i-1];

    int* temp = new int[size];
    for (int i = 0; i < size; i++)  temp[i] = tab[i];
    
    for(int i = size - 1; i >= 0; i--) {
        temp[count[tab[i] - min] - 1] = tab[i];
        count[tab[i] - min]--;
    }

    if(order == "ASC") {
        for (int i = 0; i < size; i++)  tab[i] = temp[i];
    }
    else if(order == "DESC") {
        for (int i = size - 1; i >= 0; i--)  tab[size - 1 - i] = temp[i];
    }
}

#endif