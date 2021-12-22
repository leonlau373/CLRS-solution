#include <iostream>
#include <vector>

using namespace std;

int binarysearch(vector<int> arr, int num, int start, int finish)
{
    int mid = (start + finish)/2;

    if(num < arr[mid] && start <= finish)
    {
        return binarysearch(arr,num,start,mid-1);
    }
    else if(num > arr[mid] && start <= finish)
    {
        return binarysearch(arr,num,mid+1,finish);
    }
    else if(num == arr[mid])
    {
        return mid;
    }
    else if(start > finish)
    {
        return -1;
    }
}

int main()
{
    vector<int> a{1,3,6,10,15,21,28,36,45,55,66,78,91,105,120};
    cout << binarysearch(a,120,0,14);

    return 0;
}
