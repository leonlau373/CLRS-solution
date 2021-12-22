#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_vector(vector<int>& arr, int beg, int mid, int last);
vector<int> merge_sort(vector<int>& arr, int beg, int last);
int binarysearch(vector<int> arr, int num, int start, int finish);

bool two_numbers(vector<int> arr, int x)
{
    merge_sort(arr,0,arr.size());

    for(int i = 0; i < arr.size() - 1; i = i + 1)
    {
        if(binarysearch(arr,x - arr[i], 0, arr.size()-1 ) != -1 )
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    vector<int>arr{0,1,3,6,10,15,21,28,35};
    cout << two_numbers(arr, 21);
    return 0;
}
