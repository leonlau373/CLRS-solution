#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "header/heap_class.h"
#include "header/binary_structure.h"

using namespace std;

Heap::Heap(std::vector<int> heap, int heapsize) : m_heap{heap}, m_heapsize{heapsize}
{

}

void Heap::print_member()
{
    for(int i = 0; i < m_heapsize; i = i + 1)
    {
        cout << m_heap[i] << ' ';
    }
}

int Heap::get_heap_idx(int idx)
{
    assert(idx >= 0 && "You can't input value less than 0");
    return m_heap[idx];
}

void Heap::max_heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if(l < m_heapsize && m_heap[l] > m_heap[i])
    {
        largest = l;
    }
    else
    {

    }

    if(r < m_heapsize && m_heap[r] > m_heap[largest])
    {
        largest = r;
    }
    else
    {

    }

    if(largest != i)
    {
        swap(m_heap[i],m_heap[largest]);
        Heap::max_heapify(largest);
    }
    else
    {

    }
}

void Heap::build_max_heap()
{
    int heap_size = m_heapsize;
    for(int i = m_heapsize/2; i >= 0 ; i = i - 1)
    {
        Heap::max_heapify(i);
    }
}

void Heap::heapsort()
{
    Heap::build_max_heap();
    for(int i = m_heap.size(); i > 0; i = i - 1)
    {
        swap(m_heap[0], m_heap[i - 1]);
        m_heapsize = m_heapsize - 1;
        Heap::max_heapify(0);
    }
    m_heapsize = m_heap.size();
}

int Heap::maximum()
{
    return m_heap[0];
}

int Heap::extract_max()
{
    if(m_heapsize == 0)
    {
        assert(m_heapsize != 0 && "You can't extract from a heap with size = 0");
        return -1;
    }
    else
    {
        int max_value = m_heap[0];
        m_heap[0] = m_heap[m_heapsize - 1];
        m_heapsize = m_heapsize - 1;
        m_heap.pop_back();
        Heap::max_heapify(0);
        return max_value;
    }
}

void Heap::increase_key(int i, int key)
{
    if(key < m_heap[i])
    {
        assert(key >= m_heap[i] && "New key is smaller than current key");
    }
    else
    {
        m_heap[i] = key;
        while(i > 0 && m_heap[parent(i)] < m_heap[i])
        {
            swap(m_heap[i], m_heap[parent(i)]);
            i = parent(i);
        }
    }
}

void Heap::insert_key(int key)
{
    m_heapsize = m_heapsize + 1;
    m_heap.push_back(key);
    Heap::increase_key(m_heapsize - 1, key);
}
