#include <iostream>
#include <vector>
#include <chrono> // Add at the top
using namespace std;

/*
this function really miss on general term 
     the function goal :
          Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers. Then print the respective minimum and maximum values as a single line of two space-separated long integers.

     Explanation :
          The numbers are 1, 2, 3, 4, and 5. Calculate the following sums using four of the five integers:

          Sum everything except 1, the sum is 2 + 3 + 4 + 5 = 14.

          Sum everything except 2, the sum is 1 + 3 + 4 + 5 = 13.

          Sum everything except 3, the sum is 1 + 2 + 4 + 5 = 12.

          Sum everything except 4, the sum is 1 + 2 + 3 + 5 = 11.

          Sum everything except 5, the sum is 1 + 2 + 3 + 4 = 10.

          Hints: Beware of integer overflow! Use a 64-bit integer to store the sums.
*/
void minMaxArry(vector<int> arr)
{
     // vector is mean you will use array <> what the array will accept 
    vector<int> calcArr;
    for (int i = 0; i < arr.size(); i++)
    {
        int some = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (j != i)
            {
                some += arr[j];
            }
        }
        calcArr.push_back(some);
    }
    int minNumber = calcArr[0];
    int maxNumber = calcArr[0];
    for (int i = 1; i < calcArr.size(); i++)
    {
        if (minNumber > calcArr[i])
        {
            minNumber = calcArr[i];
        }
        else if (maxNumber < calcArr[i])
        {
            maxNumber = calcArr[i];
        }
    }
    cout << minNumber << " " << maxNumber << endl;
}
/*
this function to take array and find the largest number how many time repeated 
*/
void birthdayCakeCandles(vector<int> candles)
{
    int tallest = 0;
    int numberTallest = 0;

    for (int i = 0; i < candles.size(); i++)
    {
        if (candles[i] > tallest)
        {
            tallest = candles[i];
        }
    }
    for (int i = 0; i < candles.size(); i++)
    {
        if (candles[i] == tallest)
        {
            numberTallest += 1;
        }
    }
    cout << numberTallest << endl;
}

int main()
{
     // this the start of counting time to calc how much take it 
    auto start = std::chrono::high_resolution_clock::now();

    cout << "candles" << endl;
    cout << "The function result is:" << endl;
    birthdayCakeCandles({1, 2, 3, 4, 4});
    cout << "The expected result is: 2" << endl
         << endl;


    cout << "Test 1" << endl;
    cout << "The function result is:" << endl;
    minMaxArry({5, 5, 5, 5, 5});
    cout << "The expected result is: min sum = 20, max sum = 20" << endl
         << endl;

    cout << "Test 2" << endl;
    cout << "The function result is:" << endl;
    minMaxArry({1, 2, 3, 4, 5});
    cout << "The expected result is: min sum = 10, max sum = 14" << endl
         << endl;

    auto end = std::chrono::high_resolution_clock::now(); // End timer
    std::chrono::duration<double> duration = end - start;
    cout << "Total execution time: " << duration.count() << " seconds" << endl;
     /*
     the end of calcule the time and the return of it in terminal 
     */

    return 0;
}
