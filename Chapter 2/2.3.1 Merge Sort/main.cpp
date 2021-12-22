#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_vector(vector<int>& arr, int beg, int mid, int last)
{
    int n1 = mid - beg + 1;
    int n2 = last - mid;

    vector<int> left;
    vector<int> right;

    for(int i = 0; i <= n1; i = i + 1)
    {
        if(i < n1)
        {
            left.push_back(arr[beg + i]);
        }
        else
        {
            left.push_back(1000000);
        }
    }

    /*
    for(int i = 0; i <= n1; i = i + 1)
    {
        cout << left[i] << ' ';
    }
    cout << endl;
    */

    for(int i = 0; i <= n2; i = i + 1)
    {
        if(i < n2)
        {
            right.push_back(arr[mid + i + 1]);
        }
        else
        {
            right.push_back(1000000);
        }
    }

    /*
    for(int i = 0; i <= n2; i = i + 1)
    {
        cout << right[i] << ' ';
    }
    cout << endl;
    */

    int x = 0;
    int y = 0;

    for(int k = beg; k <= last; k = k + 1)
    {
        if(left[x] <= right[y])
        {
            arr[k] = left[x];
            x = x + 1;
        }
        else //left[x] > right[y]
        {
            arr[k] = right[y];
            y = y + 1;
        }
    }

    return arr;
}

vector<int> merge_sort(vector<int>& arr, int beg, int last)
{
    if(beg < last)
    {
        int mid = (beg + last)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,last);
        merge_vector(arr,beg,mid,last);

        //Visualizing merge sort algorithm
        for(int i = 0; i < arr.size(); i = i + 1)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    else
    {

    }
    return arr;
}

int main()
{
    vector<int> arr_sort{5,1,8,2,6,4,7,3};
    merge_sort(arr_sort,0,7);

    for(int i = 0; i <=7 ; i = i + 1)
    {
        cout << arr_sort[i] << ' ';
    }

    return 0;
}
