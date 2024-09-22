#include <iostream>

void my_copy(int* source, int* destination, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(destination + i) = *(source + i);
        std::cout<<destination[i]<<" ";
    }
}
int main()
{
    const int size = 10;
    int source [size] = {10,25,34,94,15,  36, 100, 3, 8, 13};
    int destination[size]={};
    my_copy(source,destination,size);
    return 0;
}