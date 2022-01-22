#include <vector>
#include <algorithm>
#include "header/binary_structure.h"
#include "header/min_heapify.h"

using namespace std;

void min_heapify(vector<int>& vec, int i)
{
    int l = left(i);
    int r = right(i);
    const int vec_size = vec.size();
    int smallest = i;

    if(l < vec_size && vec[l] < vec[i])
    {
        smallest = l;
    }
    else
    {

    }

    if(r < vec_size && vec[r] < vec[smallest])
    {
        smallest = r;
    }
    else
    {

    }

    if(smallest != i)
    {
        swap(vec[smallest],vec[i]);
        min_heapify(vec,smallest);
    }
    else
    {

    }
}
