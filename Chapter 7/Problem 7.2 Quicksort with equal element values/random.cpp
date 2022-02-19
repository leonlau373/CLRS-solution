#include <iostream>
#include <cstdlib> //srand, rand
#include <ctime> //time

using namespace std;

int random(int a, int b) //Assuming a < b
{
    //rand() % mod is between 0 to b - a
    if(a < b)
    {
        int mod = b - a + 1;

        //randomNum is between a to b
        int randomNum = rand() % mod + a;

        return randomNum;
    }

    else if (a > b)
    {
        return random(b,a);
    }

    else
    {
        return a;
    }

}
