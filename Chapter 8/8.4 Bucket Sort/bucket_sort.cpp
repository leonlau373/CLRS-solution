#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "bucket_sort.h"

using namespace std;

vector<double> bucket_sort(vector<double> arr)
{
    int n = arr.size();

    vector< vector<double> > b; //b as a bucket, consisting of lists.

    for(int i = 0; i < n; i = i + 1)
    {
        vector<double> x{}; //initialize an empty array
        b.push_back(x); //Put the empty array into b
    }

    //Putting the member in arr to the right bucket, using floor function
    for(int i = 0; i < n; i = i + 1)
    {
        b[floor(n*arr[i])].push_back(arr[i]);
    }

    //Sort each bucket, in theory we use insertion sort, but for our ease, just use compiler sort.
    for(int i = 0; i < n; i = i + 1)
    {
        sort(b[i].begin(), b[i].end());
    }

    vector<double> sorted_list{};

    //Concatenating every list in each bucket from b[0] to b[n-1]
    for(int i = 0; i < n; i = i + 1)
    {
        for(int j = 0; j < b[i].size(); j = j + 1)
        {
            sorted_list.push_back(b[i][j]);
        }
    }

    return sorted_list;
}
