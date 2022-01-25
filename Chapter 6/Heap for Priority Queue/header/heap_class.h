#ifndef HEAP_CLASS_H_INCLUDED
#define HEAP_CLASS_H_INCLUDED

class Heap
{
private:
    std::vector<int> m_heap{};
    int m_heapsize{};

public:
    Heap(std::vector<int> heap, int heapsize);

    int get_heap_idx(int idx);

    void print_member();

    void max_heapify(int i);

    void build_max_heap();

    void heapsort();

    int maximum();

    int extract_max();

    void increase_key(int i, int key);

    void insert_key(int key);

    void delete_key(int idx);
};

#endif // HEAP_CLASS_H_INCLUDED
