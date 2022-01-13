#include <iostream>
#include <cstdlib> //srand, rand
#include <ctime> //time

using namespace std;

int random(int a, int b) //Assuming a < b
{
    //rand() % mod is between 0 to b - a
    int mod = b - a + 1;

    //randomNum is between a to b
    int randomNum = rand() % mod + a;

    return randomNum;
}
int main()
{
    srand(time(0));

    cout << random(10,100);
    return 0;
}
