#include <iostream>
#include <vector>
#include <algorithm>
#include "counting_sort.h"

using namespace std;

int main()
{
    vector<int> a{6,0,2,0,1,3,4,6,1,3,2};
    vector<int> b{0,0,0,0,0,0,0,0,0,0,0};

    counting_sort(a,b,6);

    for(int i = 0; i < b.size(); i = i + 1)
    {
        cout << b[i] << ' ';
    }
    return 0;
}
