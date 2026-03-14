#include "DynamicArray.h"
#include <iostream>

int main()
{
    DynamicArray array;
    array.push_back(11);
    array.push_back(12);
    array.push_back(13);

    array.print();

    return 0;
}
