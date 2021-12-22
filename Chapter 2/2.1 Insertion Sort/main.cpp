#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> insertionSort (vector<T>& num)
{
    auto length = num.size();

    for(int index = 1; index < length ; index = index + 1)
    {
        int key = num[index];
        //Insert num[index] into the sorted sequence
        int i = index - 1;

        while(i > -1 && num[i] > key)
        {
            num[i + 1] = num[i];
            i = i - 1;
        }

        num[i + 1] = key;

        //Visualizing insertion sort
        for(int a = 0; a < length ; a = a + 1)
        {
            cout << num[a] << ' ';
        }

        cout << '\n';
    }

    return num;
}

int main()
{
    vector<int> arr{16,5,18,2,14,9,17,15,4,12,7,19,6,8,11,3,20,13,1,10};
    insertionSort(arr);

    cout << '\n';
    cout << "The final result of insertion sort is:"<<'\n';
    for(int i = 0; i < arr.size() ; i = i + 1)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
