#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <ctime>
#include "header/quicksort_same.h"

using namespace std;

int main()
{
    srand(time(0));
    vector<int> arr{5,4,8,3,11,8,6,13,8,15,18,9,9,2,9};

    quicksort_same(arr,0,arr.size() - 1);

    for(int i = 0; i < arr.size(); i = i + 1)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}
