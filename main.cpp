#include <iostream>
#include "sorting.h"

int main()
{

    int tab[]={5,3,2,1,6,4};

    int size = sizeof(tab) / sizeof(int);
    
    for(int i=0;i<6;i++)  std::cout << tab[i] << " ";

    Sorting<int>::sort(tab, size, "BUBBLE", "DESC");

    std::cout << std::endl;

    for(int i=0;i<6;i++)  std::cout << tab[i] << " ";

    return 0;
}