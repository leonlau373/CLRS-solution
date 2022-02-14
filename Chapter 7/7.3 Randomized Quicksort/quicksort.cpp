#include <iostream>
#include <algorithm>
#include <vector>
#include "quicksort.h"

using namespace std;

int partition_quick(vector<int>& arr, int beg, int fin)
{
    //0 <= beg < fin <= arr[n-1]

    int pivot = arr[fin];
    int i = beg - 1;

    for(int j = beg; j < fin; j = j + 1)
    {
        if(arr[j] <= pivot)
        {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[fin]);

    return i + 1;
}

void quicksort(vector<int>& arr, int beg, int fin)
{
    if(beg < fin)
    {
        int q = partition_quick(arr, beg, fin);

        quicksort(arr,beg,q-1);
        quicksort(arr,q+1,fin);

        for(int i = 0; i < arr.size(); i = i + 1)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
}
