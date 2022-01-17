#include <vector>
#include "find.h"

using namespace std;

bool find_vector(vector<int> arr, int x)
{
    const int arr_size = arr.size();
    for(int i = 0; i < arr_size; i = i + 1)
    {
        if(arr[i] == x)
        {
            return 1;
        }
    }

    return 0;
}
