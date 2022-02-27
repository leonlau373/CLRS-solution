#include <iostream>
#include <vector>
#include <algorithm>
#include "counting_sort.h"

using namespace std;

void counting_sort(vector<int>& arr_a, vector<int>& arr_b, int maximum)
{
    //arr_a and arr_b has the same size, with arr_b all members are 0
    vector<int> arr_c{};
    for(int i = 0; i <= maximum; i = i + 1)
    {
        arr_c.push_back(0);
    }

    for(int j = 0; j < arr_a.size(); j = j + 1)
    {
        arr_c[arr_a[j]] = arr_c[arr_a[j]] + 1;
    }

    for(int i = 1; i <= maximum; i = i + 1)
    {
        arr_c[i] = arr_c[i] + arr_c[i - 1];
    }

    for(int j = 0; j < arr_a.size(); j = j + 1)
    {
        arr_b[arr_c[arr_a[j]]] = arr_a[j];
        arr_c[arr_a[j]] = arr_c[arr_a[j]] - 1;
    }
}
