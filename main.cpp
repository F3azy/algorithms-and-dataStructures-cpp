#include <iostream>
#include "algo.h"


int main()
{

    int tab[]={33,6,5,6,3,-6,6,2,15,6,-11,1,6,4,12,6,22};
    // int tab[] = {4, 2, 2, 8, 3, 3, 1};

    int size = sizeof(tab) / sizeof(tab[0]);

    int* idx = Searching<int>::findAll(tab, size, 6);

    int size2 = Searching<int>::findCount(tab, size, 6);
    
    for(int i=0;i<size2;i++)  std::cout << idx[i] << " ";

    std::cout << std::endl;

    for(int i=0;i<size;i++)  std::cout << tab[i] << " ";

    // std::cout << std::endl;

    // DynamicArray<int> array;

    // for(int i=0;i<size;i++) array.push(tab[i]);

    // std::cout << array << std::endl;

    // array.sort();

    // std::cout << array << std::endl;

    // Sorting<int>::sort(tab, size, "SELECTION");

    // std::cout << Searching<int>::find(tab, size, -11, "BIN");

    // std::cout << std::endl;

    // for(int i=0;i<size;i++)  std::cout << tab[i] << " ";


    return 0;
}