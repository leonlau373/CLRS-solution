#include <iostream>
#include <cmath> //log
#include <cstdlib> //srand, rand
#include <ctime> //time
#include <vector>

using namespace std;

int random(int a, int b) //Expected input a < b , a and b is a non-negative integer.
{
    if(a == 0 && b == 1)
    {
        return rand()%2;
    }
    else
    {
        //Example, if a = 5 , b = 38, we expect the vector size to be log2(34) = 6
        //Thus we will make a vector of binary representation that has size 6, we want to guess from 0 to 63
        //Add the binary representation by a, if vector + a is in between a and b, then we're done, otherwise, continue doing this over and over.
        const size_t vec_size = ceil(log2(b - a + 1));
        //Binary representation
        int binary_rand = 0;

        do
        {
            //Resetting the value of binary_rand
            binary_rand = 0;

            vector<int> binary{};
            for(int i = 0; i < vec_size; i = i + 1)
            {
                binary.push_back(random(0,1));
            }

            //Counting the binary representation of the vector, from 2^(size-1) to 2^0
            for(int i = 0; i < vec_size; i = i + 1)
            {
                binary_rand = binary_rand + binary[i] * pow(2,vec_size - i - 1);
            }

            for(int i = 0; i < vec_size; i = i + 1)
            {
                cout << binary[i] << ' ';
            }
            cout << endl;
        }
        //If we don't find binary_rand + a within range, then we repeat!
        while(binary_rand + a > b);

        return binary_rand + a;

    }
}

int main()
{
    srand(time(0));

    cout << random(5,48);


    return 0;
}
