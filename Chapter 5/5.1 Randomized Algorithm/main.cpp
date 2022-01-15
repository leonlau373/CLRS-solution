#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand ( unsigned ( std::time(0) ) );
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};

    //built in random generator, randomized array "vec" to a random permutation of "vec".
    std::random_shuffle( vec.begin(), vec.end() );

    //showing the result
    for(int i = 0; i < vec.size(); i = i + 1)
    {
        std::cout << vec[i] << ' ';
    }

    return 0;
}
