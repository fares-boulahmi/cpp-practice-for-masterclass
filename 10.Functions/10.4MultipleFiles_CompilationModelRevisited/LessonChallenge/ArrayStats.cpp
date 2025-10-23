#include <vector>
#include <climits>
using namespace std;

int calculateSum(const vector<int> &arr)
{
    // TODO: Implement your solution here
    // Hint: Loop through array and accumulate sum
    int result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        result += arr[i];
    }

    return result;
}

double calculateAverage(const vector<int> &arr)
{
    // TODO: Implement your solution here
    // Hint: Use calculateSum and divide by size
    // Remember to cast to double for proper division
    double avr = 0.0;
    for (int i = 0; i < arr.size(); i++)
    {
        avr += arr[i];
    }
    double size = arr.size();
    avr = avr / size;

    return avr;
}

int findRange(const vector<int> &arr)
{
    // TODO: Implement your solution here
    // Hint: Find max and min elements, then subtract
    int max = INT_MIN;
    int min = INT_MAX;
    int result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    result = max - min;
    return result;
}

int countAboveAverage(const vector<int> &arr)
{
    // TODO: Implement your solution here
    // Hint: First calculate average using calculateAverage
    // Then count elements greater than average
    double avr = calculateAverage(arr);
    int result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > avr)
        {
            result++;
        }
        
    }
    
    return result;
}
