#include <iostream>
#include <vector>
#include <algorithm>
#include "header/hoare_partition.h"

using namespace std;

int main()
{
    vector<int> arr{13,19,9,5,12,8,7,4,11,2,6,21};

    cout << hoare_partition(arr,0,11);

    return 0;
}
