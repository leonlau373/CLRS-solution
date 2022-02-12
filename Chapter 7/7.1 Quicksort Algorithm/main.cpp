#include <iostream>
#include <algorithm>
#include <vector>
#include "quicksort.h"

using namespace std;

int main()
{
    vector<int> arr{14,7,19,2,15,13,10,3,6,22,11,1,8,9};

    quicksort(arr,0,arr.size() - 1);

    for(int i = 0; i < arr.size(); i = i + 1)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}
