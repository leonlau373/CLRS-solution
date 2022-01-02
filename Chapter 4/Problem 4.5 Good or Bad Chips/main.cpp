#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

void print_arr(vector<int>& arr)
{
    size_t number = arr.size();

    for(size_t i = 0; i < number; i = i + 1)
    {
        cout << arr[i] << ' ';
    }

    cout << endl;
}

void test(vector<int>& arr, int num1, int num2)
{
    int arr_size = arr.size();

    if(arr[num1 - 1] == 1)
    {
        if(arr[num2 - 1] == 1)
        {
            cout << "Chip " << num1 << " verdict:" << '\n';
            cout << "Chip " << num2 << " is good" << '\n';
        }
        else
        {
            cout << "Chip " << num1 << " verdict:" << '\n';
            cout << "Chip " << num2 << " is bad" << '\n';
        }
    }
    else //arr[num1 - 1] == 0, or they tell lies.
    {
        if(arr[num2 - 1] == 1)
        {
            cout << "Chip " << num1 << " verdict:" << '\n';
            cout << "Chip " << num2 << " is bad" << '\n';
        }
        else
        {
            cout << "Chip " << num1 << " verdict:" << '\n';
            cout << "Chip " << num2 << " is good" << '\n';
        }
    }
}

//This function is to make a condition if we have guessed a previous number or not.
bool find_member(vector<int>& arr, int num)
{
    for(int i = 0; i < arr.size(); i = i + 1)
    {
        if(arr[i] == num)
        {
            return 1;
        }
    }

    return 0;
}

int counting(vector<int>& arr, int num)
{
    int counter = 0;

    for(int i = 0; i < arr.size(); i = i + 1)
    {
        if(arr[i] == num)
        {
            counter = counter + 1;
        }
    }

    return counter;
}

int main()
{
    /*Initialize random seed: */
    srand(time(NULL));

    int chipsNum{16};

    cout << "Welcome to the game, guess which chips is good or bad." << '\n';
    cout << "There is 16 chips, and you want to identify which chip is good and which chip is bad." << '\n';
    cout << "In each turn, you can either guess the good chips (press 0) or perform a test (press 1)" << '\n';
    cout << "If you decide to guess, and you guess wrong, the game will immediately end." << '\n';
    cout << "If you perform a test, you can choose two chips and the chip will tell each other if the other chip is good or bad" <<'\n';
    cout << "A good chip will always tell the truth about the other chips, while a bad chip will tell a lie." << '\n';
    cout << "Example:" << '\n';
    cout << "Suppose chip A is good, and chip B is bad, then if you perform a test on chip A and chip B, then ";
    cout << "chip A will say [Chip B is bad], while chip B will say [Chip A is bad]." << '\n';
    cout << "You know there is 9 good chips and 7 bad chips." << '\n';
    cout << "Good luck and have fun to identify those good chips!" << '\n' << '\n';

    vector<int> motherboard; //This is a list of good / bad chips
    vector<int> guessedNum{}; //This is a list of already guessed good chips.

    //If chip = 1 --> good
    //If chip = 0 --> bad
    for(int i = 0; i < chipsNum; i = i + 1)
    {
        int chip = rand() % 2;
        motherboard.push_back(chip);
    }

    //This condition to ensure there's 17 good chips, and 15 bad chips
    while( counting(motherboard,0) >= counting(motherboard,1) || counting(motherboard,1) - counting(motherboard,0) >= 3 )
    {
        for(int i = 0; i < chipsNum; i = i + 1)
        {
            motherboard[i] = rand() % 2;
        }
    }

    int guessed = 0;

    int guess_or_test = 0;

    //The whole game starts here
    while( guessed < counting(motherboard,1) )
    {
        cout << "Type [1] if you want to guess or type [2] if you want to test: ";
        cin >> guess_or_test;
        cout << '\n';

        if(guess_or_test == 1)
        {
            int guess = 0;
            cout << "Guess the good chip: ";
            cin >> guess;
            cout << '\n';

            if(motherboard[guess - 1] == 1 && !find_member(guessedNum, guess))
            {
                guessed = guessed + 1;
                guessedNum.push_back(guess);
                cout << "Guessed number: ";
                print_arr(guessedNum);
                cout << "You guessed the number correctly!" << '\n' << '\n';
            }
            else if( find_member(guessedNum, guess) )
            {
                cout << "Try to guess another number, you have guessed these numbers: ";
                print_arr(guessedNum);
            }
            else
            {
                cout << "Sorry you guessed the wrong chip :( " << '\n' << '\n';
                break;
            }
        }
        else if(guess_or_test == 2)
        {
            int test1 = 0;
            int test2 = 0;
            cout << "Choose two DISTINCT chips to test" << '\n';
            cout << "Which chips do you want to test(Enter number 1 - 16): " << '\n';

            do
            {
                cout << "Chip A: ";
                cin >> test1;

                cout << "Chip B: ";
                cin >> test2;

                cout << '\n';
            }
            while(test1 == test2 || test1 < 1 || test1 >= 17 || test2 < 1 || test2 >> 17);

            test(motherboard, test1, test2);
            test(motherboard, test2, test1);

            cout << '\n';

        }
        else
        {
            cout << "You can't input this number." << '\n';
        }
    }

    if(guessed == counting(motherboard, 1) )
    {
        cout << "Congratulations, you win the game!" << '\n';
        cout << "Here is the array: ";
        print_arr(motherboard);
    }
    else
    {
        cout << "Sorry, you lose the game" << '\n';
        cout << "Here is the array: ";
        print_arr(motherboard);
    }

    return 0;
}
