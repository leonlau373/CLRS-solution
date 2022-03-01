#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "random.h"
#include "bucket_sort.h"

using namespace std;

int main()
{
    srand(time(0));

    vector<double> arr{};

    for(int i = 0; i < 25; i = i + 1)
    {
        double x = random(0,1000) / 1000;
        arr.push_back(x);
    }

    vector<double> sorted_arr = bucket_sort(arr);

    for(int i = 0; i < sorted_arr.size(); i = i + 1)
    {
        cout << sorted_arr[i] << ' ';
    }
    return 0;
}
