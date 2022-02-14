#include <iostream>
#include <algorithm>
#include <vector>
#include "random_quicksort.h"
#include "quicksort.h"
#include "random.h"

using namespace std;

int randomized_partition(vector<int>& arr, int beg, int fin)
{
    int i = random(beg,fin);
    swap(arr[i],arr[fin]);

    return partition_quick(arr,beg,fin);
}

void randomized_quicksort(vector<int>& arr, int beg, int fin)
{
    if(beg < fin)
    {
        int q = randomized_partition(arr,beg,fin);
        randomized_quicksort(arr,beg,q-1);
        randomized_quicksort(arr,q+1,fin);
    }
}
