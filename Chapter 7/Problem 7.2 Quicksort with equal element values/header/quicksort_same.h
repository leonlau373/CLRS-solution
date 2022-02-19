#ifndef QUICKSORT_SAME_H_INCLUDED
#define QUICKSORT_SAME_H_INCLUDED
using namespace std;

pair<int,int> partition_same_quicksort(vector<int>& arr, int beg, int fin);
pair<int,int> randomized_partition_quicksort(vector<int>& arr, int beg, int fin);
void quicksort_same(vector<int>& arr, int beg, int fin);

#endif // QUICKSORT_SAME_H_INCLUDED
