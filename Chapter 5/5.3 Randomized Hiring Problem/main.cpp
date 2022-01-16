#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int random_hiring_problem(vector<int>& vec)
{
    random_shuffle( vec.begin(), vec.end() );

    int best = vec[0];
    int hiring_count = 1;
    int vec_size = vec.size();

    cout << "People hired: " << best << ' ';

    for(int i = 1; i < vec_size; i = i + 1)
    {
        if(vec[i] > best)
        {
            best = vec[i];
            hiring_count = hiring_count + 1;
            cout << best << ' ';
        }
    }

    cout << '\n';

    return hiring_count;
}

int main()
{
    srand ( unsigned ( time(NULL) ) );
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};

    //showing the result
    cout << "Initial array is: ";
    for(int i = 0; i < vec.size(); i = i + 1)
    {
        cout << vec[i] << ' ';
    }

    cout << '\n';

    int hiring_count = random_hiring_problem(vec);

    cout << "Final array is: ";
    for(int i = 0; i < vec.size(); i = i + 1)
    {
        cout << vec[i] << ' ';
    }
    cout << '\n';
    cout << "We hire: ";
    cout << hiring_count << " people(s)";

    return 0;
}
