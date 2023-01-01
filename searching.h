#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>

template <class T>
class Searching {
    private:
        Searching();

        static int linearSearch(T[], int, T);
        static int binarySearch(T[], int, int, T, std::string = "ITERATIVE");
        static int binaryIterative(T[], int, int, T);
        static int binaryRecursive(T[], int, int, T);

        static int* linearSearchAll(T[], int, T);
        static int* binarySearchAll(T[], int, T);

        static int linearSearchAllCount(T[], int, T);
        static int binarySearchAllCount(T[], int, T);

    public: 
        static int find(T[], int, T, std::string = "LINEAR");
        static int* findAll(T[], int, T, std::string = "LINEAR");
        static int findCount(T[], int, T, std::string = "LINEAR");

};

#endif