#include <iostream>
#include <algorithm>
#include <vector>
#include "header/hoare_partition.h"

using namespace std;

int hoare_partition(vector<int>& arr, int beg, int fin)
{
    int pivot = arr[beg];
    int left = beg - 1;
    int right = fin + 1;

    while(true)
    {
        do
        {
            left = left + 1;
        }
        while(arr[left] < pivot);

        do
        {
            right = right - 1;
        }
        while(arr[right] > pivot);

        if(left < right)
        {
            swap(arr[left],arr[right]);
            for(int i = 0; i < arr.size(); i = i + 1)
            {
                cout << arr[i] << ' ';
            }
            cout << '\n';
        }
        else
        {
            return right;
        }
    }
}
