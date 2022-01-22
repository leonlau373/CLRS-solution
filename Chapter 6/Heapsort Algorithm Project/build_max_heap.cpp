#include <vector>
#include "header/max_heapify.h"

using namespace std;

void build_max_heap(vector<int>& vec)
{
    const int heap_size = vec.size();
    for(int i = heap_size/2; i >= 0 ; i = i - 1)
    {
        max_heapify(vec,i,heap_size);
    }
}
