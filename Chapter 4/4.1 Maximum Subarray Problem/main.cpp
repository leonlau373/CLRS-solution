#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> find_max_crossing_subarray(vector<int> arr, int low, int mid, int high)
{
    // What is this for?
    // I do this to find the maximum sum of all subarray in form of A[i...mid]

    int left_sum = -100000000;
    int sum = 0;
    int max_left_idx;

    for(int i = mid; i >= low; i = i - 1)
    {
        sum = sum + arr[i];

        if(sum > left_sum)
        {
            left_sum = sum;
            max_left_idx = i;
        }
    }

    //Find the maximum sum of all subarray in form of A[mid+1...j]

    int right_sum = -100000000;
    sum = 0;
    int max_right_idx;

    for(int j = mid + 1; j <= high; j = j + 1)
    {
        sum = sum + arr[j];

        if(sum > right_sum)
        {
            right_sum = sum;
            max_right_idx = j;
        }
    }

    vector<int> result {max_left_idx, max_right_idx, left_sum + right_sum};

    return result;
}

vector<int> find_max_subarray(vector<int> arr, int low, int high) //Using divide and conquer
{
    if(low == high)
    {
        vector<int> result {low,high,arr[low]};
        return result;
    }
    else
    {
        int mid = (low + high)/2;

        vector<int> arr_left = find_max_subarray(arr,low,mid);
        vector<int> arr_right = find_max_subarray(arr,mid+1,high);
        vector<int> arr_cross = find_max_crossing_subarray(arr,low,mid,high);

        if(arr_left[2] >= arr_right[2] && arr_left[2] >= arr_cross[2])
        {
            return arr_left;
        }
        else if(arr_right[2] >= arr_left[2] && arr_right[2] >= arr_cross[2])
        {
            return arr_right;
        }
        else
        {
            return arr_cross;
        }
    }
}

vector<int> find_max_subarray_bruteforce(vector<int> arr)
{
    int left;
    int right;
    int max_sum = -100000000;

    for(int i = 0; i < arr.size(); i = i + 1)
    {
        int sum = 0;

        for(int j = i; j < arr.size(); j = j + 1)
        {
            sum = sum + arr[j];

            if(sum > max_sum)
            {
                max_sum = sum;
                left    = i;
                right   = j;
            }
        }
    }

    vector<int> result{left,right,max_sum};
    return result;
}

vector<int> find_max_subarray_better_bruteforce(vector<int> arr)
{
    int max_sum = -100000000;
    int left = 0;
    int right = 0;
    int sum = 0;

    for(int j = 0; j < arr.size(); j = j + 1)
    {
        sum = sum + arr[j];

        if(max_sum < sum)
        {
            max_sum = sum;
            right = j;
        }

        int sumdiff = sum;

        for(int i = left; i < j; i = i + 1)
        {
            sumdiff = sumdiff - arr[i];

            if(max_sum < sumdiff)
            {
                max_sum = sumdiff;
                left = i + 1;

                sum = sumdiff;
            }
        }
    }

    vector<int> result{left,right,max_sum};
    return result;
}

vector<int> find_max_subarray_eff(vector<int> arr)
{
    int max_sum = -100000000;
    int sum = 0;
    int l = 0;
    int r = 0;
    int cur_left = 0;

    for(int i = 0; i < arr.size(); i = i + 1)
    {
        sum = sum + arr[i];

        if(sum > max_sum)
        {
            max_sum = sum;
            l = cur_left;
            r = i;
        }

        if(sum < 0)
        {
            sum = 0;
            cur_left = i + 1;
        }
    }

    vector<int> result{l,r,max_sum};
    return result;
}

int main()
{
    vector<int> arr {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    vector<int> arr2 {3,-5,9,-4,6,-5,-7,3};

    vector<int> result = find_max_subarray(arr, 0, arr.size());
    vector<int> result_bruteforce = find_max_subarray_bruteforce(arr);
    vector<int> result_better_bruteforce = find_max_subarray_better_bruteforce(arr);
    vector<int> result_eff = find_max_subarray_eff(arr);

    for(int i = 0; i <= 2; i = i + 1)
    {
        cout << result[i] << ' ';
    }

    cout << endl;

    for(int i = 0; i <= 2; i = i + 1)
    {
        cout << result_bruteforce[i] << ' ';
    }

    cout << endl;

    for(int i = 0; i <= 2; i = i + 1)
    {
        cout << result_better_bruteforce[i] << ' ';
    }

    cout << endl;

    for(int i = 0; i <= 2; i = i + 1)
    {
        cout << result_eff[i] << ' ';
    }

    return 0;
}
