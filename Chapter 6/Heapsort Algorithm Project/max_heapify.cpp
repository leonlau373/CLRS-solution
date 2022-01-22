#include <vector>
#include <algorithm>
#include "header/binary_structure.h"
#include "header/max_heapify.h"

using namespace std;

void max_heapify(vector<int>& vec, int i, int heap_size)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if(l < heap_size && vec[l] > vec[i])
    {
        largest = l;
    }
    else
    {

    }

    if(r < heap_size && vec[r] > vec[largest])
    {
        largest = r;
    }
    else
    {

    }

    if(largest != i)
    {
        swap(vec[largest],vec[i]);
        max_heapify(vec,largest,heap_size);
    }
    else
    {

    }
}

void max_heapify_it(vector<int>& vec, int i)
{
    int largest = i; //The value to iterate

    while(largest < vec.size() )
    {
        int temp = largest; //Store value to iterate, for the sake of while loop
        int l = left(temp);
        int r = right(temp);

        if(l < vec.size() && vec[l] > vec[temp])
        {
            largest = l;
        }
        else
        {

        }

        if(r < vec.size() && vec[r] > vec[largest])
        {
            largest = r;
        }
        else
        {

        }

        if(largest != temp)
        {
            swap(vec[largest],vec[temp]);
        }
        else
        {
            break;
        }
    }
}
