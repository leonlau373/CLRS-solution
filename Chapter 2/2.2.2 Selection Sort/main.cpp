#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> selectionSort(vector<T>& arr)
{
    for(int i = 0; i < arr.size() - 1 ; i = i + 1)
    {
        int minimum = arr[i];
        int min_index = i;


        for(int j = i + 1; j < arr.size(); j = j + 1)
        {
            if(arr[j] < minimum)
            {
                minimum = arr[j];
                min_index = j;
            }
        }
        //Swapping both values
        int temp = arr[i];
        arr[i] = minimum;
        arr[min_index] = temp;

        //Visualizing selection sort
        for(int a = 0; a < arr.size(); a = a + 1)
        {
            cout << arr[a] << ' ';
        }
        cout << endl;
    }

    return arr;
}

int main()
{
    vector<int> arr{11,24,8,5,13,21,19,1,6,9,14,2,0};
    selectionSort(arr);

    for(int i = 0; i < arr.size(); i = i + 1)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
