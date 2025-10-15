#include <iostream>
#include <vector>
#include <chrono> // Add at the top
using namespace std;

void minMaxArry(vector<int> arr)
{
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

    cout << "Test 3" << endl;
    cout << "The function result is:" << endl;
    minMaxArry({1, 1, 1, 1, 1000});
    cout << "The expected result is: min sum = 4, max sum = 1003" << endl
         << endl;

    cout << "Test 4" << endl;
    cout << "The function result is:" << endl;
    minMaxArry({-1000, 5, 5, 5, 5});
    cout << "The expected result is: min sum = 20, max sum = -980" << endl
         << endl;

    cout << "Test 5" << endl;
    cout << "The function result is:" << endl;
    minMaxArry({-5, -4, -3, -2, -1});
    cout << "The expected result is: min sum = -14, max sum = -10" << endl
         << endl;

    cout << "Test 6" << endl;
    cout << "The function result is:" << endl;
    minMaxArry({0, 0, 0, 0, 100});
    cout << "The expected result is: min sum = 0, max sum = 100" << endl
         << endl;

    cout << "Test 7" << endl;
    cout << "The function result is:" << endl;
    minMaxArry({0, -1, -2, -3, -4});
    cout << "The expected result is: min sum = -9, max sum = -6" << endl
         << endl;

    cout << "Test 8" << endl;
    cout << "The function result is:" << endl;
    minMaxArry({100, 200, 300, 400, 500});
    cout << "The expected result is: min sum = 1000, max sum = 1400" << endl
         << endl;

    cout << "Test 9" << endl;
    cout << "The function result is:" << endl;
    minMaxArry({1, 1, 2, 3, 4});
    cout << "The expected result is: min sum = 10, max sum = 11" << endl
         << endl;

    cout << "Test 10" << endl;
    cout << "The function result is:" << endl;
    minMaxArry({5, 6, 7, 8, 8});
    cout << "The expected result is: min sum = 26, max sum = 29" << endl
         << endl;

    cout << "Test 11" << endl;
    cout << "The function result is:" << endl;
    minMaxArry({0, 0, 0, 0, 0});
    cout << "The expected result is: min sum = 0, max sum = 0" << endl
         << endl;

    cout << "Test 12" << endl;
    cout << "The function result is:" << endl;
    minMaxArry({1, 1, 1, 100, 100});
    cout << "The expected result is: min sum = 103, max sum = 303" << endl
         << endl;

    cout << "Test 13" << endl;
    cout << "The function result is:" << endl;
    minMaxArry({-10000, 0, 5000, 10000, 15000});
    cout << "The expected result is: min sum = 20000, max sum = 30000" << endl
         << endl;

    auto end = std::chrono::high_resolution_clock::now(); // End timer
    std::chrono::duration<double> duration = end - start;
    cout << "Total execution time: " << duration.count() << " seconds" << endl;

    return 0;
}
