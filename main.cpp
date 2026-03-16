#include "DynamicArray.h"
#include <iostream>

int main()
{
    DynamicArray array;
    array.push_back(11);
    array.push_back(12);
    array.push_back(13);
    array.insert(1,0);
    array.insert(12,1);


    array.print();
    array.remove(1);
    array.print();

    return 0;
}


