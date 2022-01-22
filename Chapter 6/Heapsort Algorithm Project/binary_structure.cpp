#include "header/binary_structure.h"

int parent(int i)
{
    return i/2 - 1;
}

int left (int i)
{
    return 2*i + 1;
}

int right (int i)
{
    return 2*i + 2;
}
