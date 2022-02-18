#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

pair<int,int> partition_quicksort(vector<int>& arr, int beg, int fin)
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
            swap(arr[i], arr[left]);
            swap(arr[i], arr[right]);
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

int main()
{
    vector<int> arr{5,4,8,3,11,8,6,13,8,15,18,7,8,2,8};

    partition_quicksort(arr,0,arr.size() - 1);

    for(int i = 0; i < arr.size(); i = i + 1)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}
