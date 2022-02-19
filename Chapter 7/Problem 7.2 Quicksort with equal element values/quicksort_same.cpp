#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <ctime>
#include "header/random.h"
#include "header/quicksort_same.h"

using namespace std;

pair<int,int> partition_same_quicksort(vector<int>& arr, int beg, int fin)
{
    int pivot = arr[fin];
    int left = beg - 1;
    int right = beg - 1;

    for(int i = beg; i < fin ; i = i + 1)
    {
        if(arr[i] < pivot)
        {
            left = left + 1;
            right = right + 1;
            if(left != right)
            {
                swap(arr[i], arr[left]);
                swap(arr[i], arr[right]);
            }
            else
            {
                swap(arr[i], arr[left]);
            }

        }
        else if(arr[i] == pivot)
        {
            right = right + 1;
            swap(arr[right], arr[i]);
        }
        else
        {

        }
    }
    swap(arr[right+1],arr[fin]);

    cout << left+1 << ' ' << right+1 << endl;

    pair<int,int> pair1{left+1,right+1};

    return pair1;
}

pair<int,int> randomized_partition_quicksort(vector<int>& arr, int beg, int fin)
{
    int i = random(beg,fin);
    swap(arr[i],arr[fin]);
    return partition_same_quicksort(arr,beg,fin);
}

void quicksort_same(vector<int>& arr, int beg, int fin)
{
    if(beg < fin)
    {
        pair<int,int> result{randomized_partition_quicksort(arr,beg,fin)};

        quicksort_same(arr,beg,result.first - 1);
        quicksort_same(arr,result.second + 1, fin);
    }
}
