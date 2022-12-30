#include <iostream>
#include "sorting.h"
#include "searching.h"

int main()
{

    int tab[]={33,5,3,-6,6,2,15,-11,1,6,4,12,22};
    // int tab[] = {4, 2, 2, 8, 3, 3, 1};

    int size = sizeof(tab) / sizeof(tab[0]);
    
    std::cout << Searching<int>::search(tab, size, 33);

    // for(int i=0;i<size;i++)  std::cout << tab[i] << " ";

    // std::cout << std::endl;

    // Sorting<int>::sort(tab, size, "COUNT", "DESC");

    // std::cout << std::endl;

    // for(int i=0;i<size;i++)  std::cout << tab[i] << " ";

    return 0;
}