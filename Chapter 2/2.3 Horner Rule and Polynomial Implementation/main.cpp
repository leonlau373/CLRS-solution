#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int polynomial_evaluation (vector<int> arr, int x)
{
    int value = 0;

    for(int i = 0; i < arr.size(); i = i + 1)
    {
        value = value + pow(x,i) * arr[i];
    }

    return value;
}

int polynomial_horner(vector<int> arr, int x)
{
    int value = 0;
    for(int i = arr.size() - 1; i >= 0 ; i = i - 1)
    {
        value = arr[i] + x*value;
    }

    return value;
}

int main()
{
    vector<int> arr{1,2,3,4,5};
    cout << polynomial_evaluation(arr, 3);
    cout << endl;
    cout << polynomial_horner(arr, 3);
    return 0;
}
