#ifndef SORTING_H
#define SORTING_H

#include <iostream>

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
        static void sort(T[], int, std::string = "INSERTION", std::string = "ASC");

};


#endif