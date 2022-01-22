#include <iostream>
#include <vector>
#include <algorithm>
#include "header/binary_structure.h"
#include "header/max_heapify.h"
#include "header/build_max_heap.h"

using namespace std;

void heapsort(vector<int>& arr)
{
    build_max_heap(arr);

    /*
    for(int i = 0; i < arr.size(); i = i + 1)
    {
        cout << arr[i] << ' ';
    }

    cout << endl;
    */

    int heap_size = arr.size();
    for(int i = arr.size() - 1; i > 0; i = i - 1)
    {
        swap(arr[0], arr[i]);
        heap_size = heap_size - 1;
        max_heapify(arr,0,heap_size);
    }
}
int main()
{
    vector<int> arr{5,13,2,25,7,17,20,8,4};
    heapsort(arr);

    for(int i = 0; i < arr.size(); i = i + 1)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}
