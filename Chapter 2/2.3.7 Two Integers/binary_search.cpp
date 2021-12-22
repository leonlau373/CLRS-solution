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
