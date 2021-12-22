#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_vector(vector<int>& arr, int beg, int mid, int last)
{
    int n1 = mid - beg + 1;
    int n2 = last - mid;

    vector<int> left;
    vector<int> right;

    for(int i = 0; i < n1; i = i + 1)
    {
        left.push_back(arr[beg + i]);
    }

    /*
    for(int i = 0; i <= n1; i = i + 1)
    {
        cout << left[i] << ' ';
    }
    cout << endl;
    */

    for(int i = 0; i < n2; i = i + 1)
    {
        right.push_back(arr[mid + i + 1]);
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
        if(left[x] <= right[y] && x != n1)
        {
            arr[k] = left[x];
            x = x + 1;
        }
        else if(left[x] > right[y] && y != n2)
        {
            arr[k] = right[y];
            y = y + 1;
        }
        else if(x == n1)
        {
            arr[k] = right[y];
            y = y + 1;
        }
        else if(y == n2)
        {
            arr[k] = left[x];
            x = x + 1;
        }
        else
        {

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
    vector<int> arr_sort{6,3,1,8,5,4,7,2};
    merge_sort(arr_sort,0,7);

    for(int i = 0; i < arr_sort.size() ; i = i + 1)
    {
        cout << arr_sort[i] << ' ';
    }

    return 0;
}
