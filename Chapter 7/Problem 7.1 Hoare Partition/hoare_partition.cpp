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
    On the edge case, where fin - beg = 1:
    --> This is consider to be edge case, because when we have a subarray of size 2
    --> we don't want in our quicksort algorithm, j returns to fin
    --> If j returns to fin , the algorithm won't ever end
    For simplicity, let we have an array of size 2, with a1 and a2 as the member:
    Assume we have array A = {a1,a2}

    Case 1: a1 < a2
    ------ Then hoare_partition first have left = -1 , right = 2, pivot = a1
    ------ The first do-while loop will make left = 0 (since a1 < pivot is false)
    ------ The second do-while loop will make right = 0 (since a2 > pivot is true, and a1 > pivot is false)
    ------ Then hoare_partition just returns 0 , which is what we want.

    Case 2: a1 > a2
    ------ Then hoare_partition first have left = -1. right = 2, pivot = a1
    ------ First do-while loop will make left = 0 (a1 < pivot is false)
    ------ Second do-while loop will make right = 1 (since a2 > pivot is false)
    ------ Swap a1 and a2 --> A = {a2,a1}
    ------ Do this again will make right = 0 --> returns 0, which is what we want.
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
