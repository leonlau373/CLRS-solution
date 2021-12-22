#include <iostream>
#include <vector>

using namespace std;

int linear_search(vector<int> arr, int value)
{
    for(int i = 0; i < arr.size(); i = i + 1)
    {
        if(arr[i] == value)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr{2,5,11,6,8,14,19,3};
    cout << linear_search(arr, 14) << ' ' << linear_search(arr, 1);
    return 0;
}
