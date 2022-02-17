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

void hoare_quicksort(vector<int>& arr, int beg, int fin)
{
    /*
    We don't want j = fin, all the time, otherwise the algorithm won't end.
    But take note on hoare_partition, the first while loop iteration must make left = beg, since arr[left] < pivot is always FALSE in this case.
    Then we immediately decrement j = fin, at the very least.

    Case 1: the algo ends on first iteration of while loop
    ------ Then j = beg to make the algo end --> algorithm returns j

    Case 2: the algo continues to 2nd iteration
    ------ Then j must decrement further at least once, thus j != fin.
    */

    /*
    P(n) = subarray (array) of size n is sorted
    For induction on hoare_quicksort, the base case n = 1,2 clearly makes the array sorted (trivial / based on description above)
    Suppose P(k) is true for k < n

    This is the illustration on hoare_quicksort:
    -----------j------------------
    ...k.......x.......n-k........

    Then hoare_quicksort divides the array of size n to two subarrays of size k and size n - k
    But both subarrays are sorted, and every member in subarray 1 < every member in subarray 2.
    Thus the array must be sorted.
    */
    if(beg < fin)
    {
        int j = hoare_partition(arr,beg,fin);
        hoare_quicksort(arr,beg,j);
        hoare_quicksort(arr,j+1,fin);
    }
    else
    {

    }
}
