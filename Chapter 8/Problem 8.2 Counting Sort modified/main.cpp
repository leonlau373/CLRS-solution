#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void counting_sort(vector<int>& arr, int maximum)
{
    vector<int> c{};

    //Initializing all 0's
    for(int j = 0; j <= maximum; j = j + 1)
    {
        c.push_back(0);
    }

    const int n = arr.size();

    //Counting how many key numbered x are there in array c.
    for(int i = 0; i < n; i = i + 1)
    {
        c[arr[i]] = c[arr[i]] + 1;
    }

    int counter = 1;

    //Remake how to sort the keys, in the same array.
    for(int i = 0; i < n; i = i + 1)
    {
        if(c[counter] != 0)
        {
            arr[i] = counter;
            c[counter] = c[counter] - 1;
        }
        else
        {
            counter = counter + 1;
            i = i - 1; // We don't want to "increment" i if this happens, just continue the counter if this happens.
        }
    }
}

//Comment: I don't think this solution works, since this only work if the "key" is the only information we have, and so we are safe to rewrite the array a.
//Otherwise, I need to find another solution that only use O(k) storage (used for array c), that doesn't delete the information behind the "key"
//For example: if the data is a pair <int, string>, and the first part acts as a key, then we lost the "string" data behind it, because of how the algorithm works.

int main()
{
    vector<int> arr{1,2,3,4,3,2,1,2,3,4,3,2,1,2,3,4};

    counting_sort(arr, 4);

    for(int i = 0; i < arr.size() ; i = i + 1)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
