#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "header/heap_class.h"

using namespace std;

int main()
{
    int heap_size{};
    vector<int> heap{};

    cout << "Enter the heap size: " << '\n';
    cin >> heap_size;

    for(int i = 0; i < heap_size; i = i + 1)
    {
        cout << "Enter member #" << i + 1 << '\n';
        int num;
        cin >> num;
        heap.push_back(num);
    }

    Heap h1{heap, heap_size};

    h1.build_max_heap();

    cout << "Here is your heap: ";
    h1.print_member();
    cout << '\n';

    int instructions{};

    while(1)
    {
        cout << '\n';
        cout << "Type 1 for finding the maximum: \n";
        cout << "Type 2 for extract the maximum: \n";
        cout << "Type 3 for increase one of the value: \n";
        cout << "Type 4 for insert a value and put in to heap: \n";
        cout << "Type 0 to exit this program: \n";
        cin >> instructions;

        if(instructions == 1)
        {
            cout << "The maximum is: " << h1.maximum();
            cout << '\n';
        }

        else if(instructions == 2)
        {
            cout << "You have extracted this value: " << h1.extract_max();
            cout << '\n' << "Now this is your heap: ";
            h1.print_member();
            cout << '\n';
        }
        else if(instructions == 3)
        {
            int index{};
            int new_key{};
            cout << "Enter the index you want to replace: ";
            cin >> index;
            cout << "Your old value is: " << h1.get_heap_idx(index - 1);
            cout << '\n' << "Enter a new value, make sure it's bigger than your old value: ";
            cin >> new_key;
            h1.increase_key(index - 1,new_key);
            cout << "Your new heap is: ";
            h1.print_member();
            cout << '\n';
        }
        else if(instructions == 4)
        {
            int new_key{};
            cout << "Enter the new value: ";
            cin >> new_key;
            h1.insert_key(new_key);
            cout << "Your new heap is: ";
            h1.print_member();
            cout << '\n';
        }
        else
        {
            cout << "You have exited this program: ";
            break;
        }
    }

    return 0;
}
