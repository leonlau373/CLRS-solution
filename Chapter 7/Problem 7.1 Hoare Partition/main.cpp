#include <iostream>
#include <vector>
#include <algorithm>
#include "header/hoare_partition.h"

using namespace std;

int main()
{
    vector<int> arr{13,19,9,5,12,8,7,4,11,2,6,21};

    //output = 8, where arr[0...8] < 13, arr[9...11] >= 13
    hoare_quicksort(arr,0,arr.size() - 1);

    for(int i = 0; i < arr.size(); i = i + 1)
    {
        cout << arr[i] << ' ';
    }

    cout << '\n';

    return 0;
}
