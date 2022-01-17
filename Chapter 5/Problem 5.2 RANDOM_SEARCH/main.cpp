#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "find.h"
#include "random.h"

using namespace std;

int random_search(vector<int> arr, int x)
{
    vector<int> index;
    int size_count = 0;
    const int arr_size = arr.size();

    while(size_count != arr_size)
    {
        int y = random(0,arr_size - 1);
        if(arr[y] == x)
        {
            return y;
        }
        else if(find_vector(index,y) == 0)
        {
            index.push_back(y);
            size_count = size_count + 1;
        }
        else
        {

        }
    }

    return -1;
}

int main()
{
    vector<int> arr{1,4,7,6,12,14,22,19,18,13};
    cout << random_search(arr, 15);

    return 0;
}
