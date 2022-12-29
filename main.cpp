#include <iostream>
#include "sorting.h"

int main()
{

    int tab[]={33,5,3,6,2,15,1,6,4,12,22};
    // int tab[] = {4, 2, 2, 8, 3, 3, 1};

    int size = sizeof(tab) / sizeof(int);
    
    for(int i=0;i<size;i++)  std::cout << tab[i] << " ";

    Sorting<int>::sort(tab, size, "COUNT", "ASC");

    std::cout << std::endl;

    for(int i=0;i<size;i++)  std::cout << tab[i] << " ";

    return 0;
}