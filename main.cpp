#include <iostream>
#include "sorting.h"

int main()
{

    int tab[]={33,5,3,2,15,1,6,4,12};

    int size = sizeof(tab) / sizeof(int);
    
    for(int i=0;i<size;i++)  std::cout << tab[i] << " ";

    Sorting<int>::sort(tab, size, "INSERTION", "DESC");

    std::cout << std::endl;

    for(int i=0;i<size;i++)  std::cout << tab[i] << " ";

    return 0;
}