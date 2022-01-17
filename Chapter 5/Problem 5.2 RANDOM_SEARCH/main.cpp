#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "find.h"
#include "random.h"

using namespace std;

int random_search(vector<int> arr, int x)
{
    vector<int> index; //Tracking of which index has been checked or not
    int size_count = 0;
    const int arr_size = arr.size();

    while(size_count != arr_size)
    {
        int y = random(0,arr_size - 1); //Finding the number randomly
        if(arr[y] == x)
        {
            return y;
        }
        //If we can't find that number in that index --> put this in index array, to keep track which one has been tracked
        else if(find_vector(index,y) == 0)
        {
            index.push_back(y);
            size_count = size_count + 1;
        }
        else
        {

        }
    }

    return -1;
}

int main()
{
    srand(time(0));
    vector<int> squared;
    for(int i = 0; i < 101; i = i + 1)
    {
        squared.push_back((i)*(i));
    }

    cout << random_search(squared, 4903);

    return 0;
}
