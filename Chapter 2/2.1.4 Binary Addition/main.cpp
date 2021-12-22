#include <iostream>
#include <vector>

using namespace std;

vector<int> binary_addition(vector<int> A, vector<int> B)
{
    vector<int> sum{0};
    auto n = A.size();
    sum.resize(n + 1);

    int carry = 0;
    for(int j = n - 1; j >= 0; j = j - 1)
    {
        sum[j+1] =(A[j] + B[j] + carry)%2;
        carry = (A[j] + B[j])/2;
    }

    sum[0] = carry;
    return sum;
}

int main()
{
    vector<int> A{1,1,0,0,1,1,1,0,1,1,0,1,0,1,1};
    vector<int> B{1,0,1,1,1,0,1,1,1,0,0,1,1,0,1};
    vector<int> sum = binary_addition(A,B);
    for(int i = 0; i < sum.size(); i = i + 1)
    {
        cout << sum[i];
    }

    return 0;
}
