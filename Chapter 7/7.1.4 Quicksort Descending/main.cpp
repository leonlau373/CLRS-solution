#include <iostream>
#include <algorithm>
#include <vector>
#include "quicksort_descending.h"

using namespace std;

int main()
{
    vector<int> arr{13,19,9,5,12,8,7,4,21,2,6,11};

    quicksort_descend(arr,0,11);

    for(int i = 0; i <= 11; i = i + 1)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
