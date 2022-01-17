#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int random(int a, int b) //Assuming a < b
{
    //rand() % mod is between 0 to b - a
    int mod = b - a + 1;

    //randomNum is between a to b
    int randomNum = rand() % mod + a;

    return randomNum;
}

vector<int> random_shuffle_vector(vector<int>& v)
{
    int n = v.size();

    //We randomized using swap method
    for(int i = 0; i < n; i = i + 1)
    {
        swap(v[i],v[random(i,n-1)]);
    }

    return v;
}

int main()
{
    srand ( time(NULL) );

    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    random_shuffle_vector(v);

    for(int i = 0; i < v.size(); i = i + 1)
    {
        cout << v[i] << ' ';
    }
    return 0;
}
