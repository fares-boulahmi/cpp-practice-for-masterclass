#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

// Problem 1: Easy 1 - Value Multiplier
// Description: Create a function that takes a multiplier value and a vector of integers.
// Return a new vector where each element is multiplied by the multiplier.
// You must use a lambda function with capture by value to accomplish this.
//
// Input Format:
// - int multiplier: the value to multiply each element by
// - vector<int> numbers: the input vector
//
// Output Format:
// - vector<int>: new vector with multiplied values
//
// Example 1:
// Input: multiplier = 3, numbers = {1, 2, 3}
// Output: {3, 6, 9}
// Explanation: Each element is multiplied by 3
//
// Example 2:
// Input: multiplier = 5, numbers = {2, 4}
// Output: {10, 20}
//
// Constraints:
// - 1 <= multiplier <= 100
// - 0 <= numbers.size() <= 1000
// - -1000 <= numbers[i] <= 1000
vector<int> problem1Solution(int multiplier, vector<int> numbers) {
    // TODO: Implement your solution here using capture lists
    // Hint: Create a lambda that captures the multiplier by value [multiplier]
    // and use it to transform each element in the vector
    auto mult = [multiplier](int number)->int {
        return multiplier * number;
    };
    vector<int> result{};
    for (size_t i = 0; i < numbers.size(); i++)
    {
        result.push_back(mult(numbers[i]));
    }
    return result;
    
}

// Problem 2: Easy 2 - Counter with Accumulator
// Description: Create a function that counts how many numbers in a vector
// are greater than a given threshold. The count should be accumulated using
// a lambda function with capture by reference.
//
// Input Format:
// - vector<int> numbers: the input vector
// - int threshold: the value to compare against
//
// Output Format:
// - int: count of numbers greater than threshold
//
// Example 1:
// Input: numbers = {1, 5, 3, 8, 2}, threshold = 3
// Output: 2
// Explanation: 5 and 8 are greater than 3
//
// Example 2:
// Input: numbers = {10, 20, 30}, threshold = 15
// Output: 2
// Explanation: 20 and 30 are greater than 15
//
// Constraints:
// - 0 <= numbers.size() <= 1000
// - -1000 <= numbers[i] <= 1000
// - -1000 <= threshold <= 1000
int problem2Solution(vector<int> numbers, int threshold) {
    // TODO: Implement your solution here using capture lists
    // Hint: Create a counter variable and a lambda that captures it by reference [&counter]
    // Use the lambda to iterate through the vector and increment the counter
    auto bigger = [threshold](vector<int> numbers)->int {
        int count{};
        for (size_t i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] > threshold) count ++;
        }
        return count;
    };
    
    return bigger(numbers);
}

// Problem 3: Medium - Custom Filter and Transform
// Description: Create a function that filters numbers based on a condition
// and transforms them. You need to:
// 1. Filter: Keep only numbers that are divisible by 'divisor'
// 2. Transform: Add 'offset' to each filtered number
// Use lambdas with multiple captures (both by value and reference).
//
// Input Format:
// - vector<int> numbers: the input vector
// - int divisor: keep only numbers divisible by this
// - int offset: add this to each filtered number
//
// Output Format:
// - vector<int>: filtered and transformed vector
//
// Example 1:
// Input: numbers = {10, 15, 20, 25, 30}, divisor = 5, offset = 2
// Output: {12, 17, 22, 27, 32}
// Explanation: All numbers divisible by 5, then add 2 to each
//
// Example 2:
// Input: numbers = {6, 9, 12, 15}, divisor = 3, offset = 10
// Output: {16, 19, 22, 25}
// Explanation: All are divisible by 3, then add 10
//
// Constraints:
// - 0 <= numbers.size() <= 1000
// - 1 <= divisor <= 100
// - -100 <= offset <= 100
// - -1000 <= numbers[i] <= 1000
vector<int> problem3Solution(vector<int> numbers, int divisor, int offset) {
    // TODO: Implement your solution here using capture lists
    // Hint: Create two lambdas - one for filtering (capture divisor by value)
    // and one for transforming (capture offset by value)
    // You can also capture the result vector by reference
    auto divisor_number = [divisor , numbers]()->vector<int> {
        vector<int>result{};
        for (size_t i = 0; i < numbers.size(); i++)
        {
            if ((numbers[i] % divisor) == 0)
            {
                result.push_back(numbers[i]);
            }
        }
        return result;
    };
    numbers = divisor_number();
    auto offset_number = [offset , &numbers]() {
        for (size_t i = 0; i < numbers.size(); i++)
        {
            numbers[i] = numbers[i] + offset;
        }
    };
    offset_number();
    return numbers;
}

// Problem 4: Hard - Statistics Calculator with Lambda Chain
// Description: Create a function that calculates multiple statistics on a vector
// of integers. You need to use multiple lambdas with different capture patterns:
// 1. Count how many numbers are in range [min_val, max_val]
// 2. Calculate the sum of numbers in that range
// 3. Return the average (sum/count) as a double
// If no numbers are in range, return 0.0
//
// Input Format:
// - vector<int> numbers: the input vector
// - int min_val: minimum value of range (inclusive)
// - int max_val: maximum value of range (inclusive)
//
// Output Format:
// - double: average of numbers in range, or 0.0 if none exist
//
// Example 1:
// Input: numbers = {1, 5, 3, 8, 2, 6}, min_val = 3, max_val = 6
// Output: 4.5
// Explanation: Numbers in range [3,6]: 5, 3, 6 → sum=14, count=3 → avg=4.666... ≈ 4.67
// Wait, let me recalculate: 5, 3, 6 → (5+3+6)/3 = 14/3 = 4.666...
//
// Example 2:
// Input: numbers = {10, 20, 30}, min_val = 15, max_val = 25
// Output: 20.0
// Explanation: Only 20 is in range [15,25]
//
// Constraints:
// - 0 <= numbers.size() <= 1000
// - -1000 <= numbers[i] <= 1000
// - min_val <= max_val
// - -1000 <= min_val, max_val <= 1000
double problem4Solution(vector<int> numbers, int min_val, int max_val) {
    // TODO: Implement your solution here using capture lists
    // Hint: Create lambdas that capture min_val and max_val by value,
    // and capture sum/count by reference. Chain the operations together.
    // Remember to handle division by zero!
    if (numbers.size() == 0) return 0;
    auto range_numbers = [numbers , min_val , max_val]()-> vector<int> {
        vector<int> result{};
        for (size_t i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] >= min_val && numbers[i] <= max_val) {
                result.push_back(numbers[i]);
            }
        }
        return result;  
    };
    
    numbers = range_numbers();
    if (numbers.size() == 0) return 0;
    auto sum_count = [numbers]()-> vector<double>{
        double sum{};
        double count{};
        for (size_t i = 0; i < numbers.size(); i++)
        {
            sum += numbers[i];
            count += 1;
        }
        return {sum , count};
    };
    double avr = sum_count()[0] / sum_count()[1];
    return  avr;
}

void testProblem1() {
    cout << "\n=== Testing Problem 1: Value Multiplier ===" << endl;
    
    // Test Case 1: Basic multiplication by 3
    // Input: multiplier=3, numbers={1, 2, 3}
    // Calculation: 1*3=3, 2*3=6, 3*3=9
    // Expected: {3, 6, 9}
    {
        vector<int> result = problem1Solution(3, {1, 2, 3});
        vector<int> expected = {3, 6, 9};
        cout << "Test 1: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 2: Multiplication by 5
    // Input: multiplier=5, numbers={2, 4}
    // Calculation: 2*5=10, 4*5=20
    // Expected: {10, 20}
    {
        vector<int> result = problem1Solution(5, {2, 4});
        vector<int> expected = {10, 20};
        cout << "Test 2: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 3: Empty vector
    // Input: multiplier=7, numbers={}
    // Expected: {}
    {
        vector<int> result = problem1Solution(7, {});
        vector<int> expected = {};
        cout << "Test 3: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 4: Negative numbers
    // Input: multiplier=2, numbers={-3, -5, 4}
    // Calculation: -3*2=-6, -5*2=-10, 4*2=8
    // Expected: {-6, -10, 8}
    {
        vector<int> result = problem1Solution(2, {-3, -5, 4});
        vector<int> expected = {-6, -10, 8};
        cout << "Test 4: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 5: Multiply by 1
    // Input: multiplier=1, numbers={10, 20, 30}
    // Calculation: 10*1=10, 20*1=20, 30*1=30
    // Expected: {10, 20, 30}
    {
        vector<int> result = problem1Solution(1, {10, 20, 30});
        vector<int> expected = {10, 20, 30};
        cout << "Test 5: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 6: Multiply by 10
    // Input: multiplier=10, numbers={1, 5, 9}
    // Calculation: 1*10=10, 5*10=50, 9*10=90
    // Expected: {10, 50, 90}
    {
        vector<int> result = problem1Solution(10, {1, 5, 9});
        vector<int> expected = {10, 50, 90};
        cout << "Test 6: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 7: Large numbers
    // Input: multiplier=100, numbers={10, 5}
    // Calculation: 10*100=1000, 5*100=500
    // Expected: {1000, 500}
    {
        vector<int> result = problem1Solution(100, {10, 5});
        vector<int> expected = {1000, 500};
        cout << "Test 7: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 8: Single element with zero
    // Input: multiplier=5, numbers={0}
    // Calculation: 0*5=0
    // Expected: {0}
    {
        vector<int> result = problem1Solution(5, {0});
        vector<int> expected = {0};
        cout << "Test 8: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
}

void testProblem2() {
    cout << "\n=== Testing Problem 2: Counter with Accumulator ===" << endl;
    
    // Test Case 1: Basic counting
    // Input: numbers={1, 5, 3, 8, 2}, threshold=3
    // Calculation: 1>3? No, 5>3? Yes(1), 3>3? No, 8>3? Yes(2), 2>3? No
    // Expected: 2
    {
        int result = problem2Solution({1, 5, 3, 8, 2}, 3);
        cout << "Test 1: " << (result == 2 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 2: Multiple matches
    // Input: numbers={10, 20, 30}, threshold=15
    // Calculation: 10>15? No, 20>15? Yes(1), 30>15? Yes(2)
    // Expected: 2
    {
        int result = problem2Solution({10, 20, 30}, 15);
        cout << "Test 2: " << (result == 2 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 3: No matches
    // Input: numbers={1, 2, 3}, threshold=10
    // Calculation: All numbers <= 10
    // Expected: 0
    {
        int result = problem2Solution({1, 2, 3}, 10);
        cout << "Test 3: " << (result == 0 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 4: All match
    // Input: numbers={5, 10, 15}, threshold=2
    // Calculation: 5>2? Yes(1), 10>2? Yes(2), 15>2? Yes(3)
    // Expected: 3
    {
        int result = problem2Solution({5, 10, 15}, 2);
        cout << "Test 4: " << (result == 3 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 5: Empty vector
    // Input: numbers={}, threshold=5
    // Expected: 0
    {
        int result = problem2Solution({}, 5);
        cout << "Test 5: " << (result == 0 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 6: Negative threshold
    // Input: numbers={-5, -2, 3, 7}, threshold=-3
    // Calculation: -5>-3? No, -2>-3? Yes(1), 3>-3? Yes(2), 7>-3? Yes(3)
    // Expected: 3
    {
        int result = problem2Solution({-5, -2, 3, 7}, -3);
        cout << "Test 6: " << (result == 3 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 7: Single element greater
    // Input: numbers={100}, threshold=50
    // Calculation: 100>50? Yes(1)
    // Expected: 1
    {
        int result = problem2Solution({100}, 50);
        cout << "Test 7: " << (result == 1 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 8: Equal to threshold (should not count)
    // Input: numbers={5, 5, 5}, threshold=5
    // Calculation: 5>5? No, 5>5? No, 5>5? No
    // Expected: 0
    {
        int result = problem2Solution({5, 5, 5}, 5);
        cout << "Test 8: " << (result == 0 ? "PASS" : "FAIL") << endl;
    }
}

void testProblem3() {
    cout << "\n=== Testing Problem 3: Custom Filter and Transform ===" << endl;
    
    // Test Case 1: Basic filter and transform
    // Input: numbers={10, 15, 20, 25, 30}, divisor=5, offset=2
    // Filter: 10%5=0✓, 15%5=0✓, 20%5=0✓, 25%5=0✓, 30%5=0✓ → all pass
    // Transform: 10+2=12, 15+2=17, 20+2=22, 25+2=27, 30+2=32
    // Expected: {12, 17, 22, 27, 32}
    {
        vector<int> result = problem3Solution({10, 15, 20, 25, 30}, 5, 2);
        vector<int> expected = {12, 17, 22, 27, 32};
        cout << "Test 1: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 2: Filter some out
    // Input: numbers={6, 9, 12, 15}, divisor=3, offset=10
    // Filter: 6%3=0✓, 9%3=0✓, 12%3=0✓, 15%3=0✓ → all pass
    // Transform: 6+10=16, 9+10=19, 12+10=22, 15+10=25
    // Expected: {16, 19, 22, 25}
    {
        vector<int> result = problem3Solution({6, 9, 12, 15}, 3, 10);
        vector<int> expected = {16, 19, 22, 25};
        cout << "Test 2: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 3: Some filtered out
    // Input: numbers={1, 2, 3, 4, 5, 6}, divisor=2, offset=1
    // Filter: 1%2=1✗, 2%2=0✓, 3%2=1✗, 4%2=0✓, 5%2=1✗, 6%2=0✓
    // Keep: {2, 4, 6}
    // Transform: 2+1=3, 4+1=5, 6+1=7
    // Expected: {3, 5, 7}
    {
        vector<int> result = problem3Solution({1, 2, 3, 4, 5, 6}, 2, 1);
        vector<int> expected = {3, 5, 7};
        cout << "Test 3: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 4: No numbers pass filter
    // Input: numbers={1, 3, 5, 7}, divisor=2, offset=5
    // Filter: All odd numbers, none divisible by 2
    // Expected: {}
    {
        vector<int> result = problem3Solution({1, 3, 5, 7}, 2, 5);
        vector<int> expected = {};
        cout << "Test 4: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 5: Negative offset
    // Input: numbers={10, 20, 30}, divisor=10, offset=-5
    // Filter: 10%10=0✓, 20%10=0✓, 30%10=0✓
    // Transform: 10-5=5, 20-5=15, 30-5=25
    // Expected: {5, 15, 25}
    {
        vector<int> result = problem3Solution({10, 20, 30}, 10, -5);
        vector<int> expected = {5, 15, 25};
        cout << "Test 5: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 6: Empty vector
    // Input: numbers={}, divisor=5, offset=3
    // Expected: {}
    {
        vector<int> result = problem3Solution({}, 5, 3);
        vector<int> expected = {};
        cout << "Test 6: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 7: Divisor of 1
    // Input: numbers={5, 10, 15}, divisor=1, offset=0
    // Filter: All divisible by 1
    // Transform: No change (offset=0)
    // Expected: {5, 10, 15}
    {
        vector<int> result = problem3Solution({5, 10, 15}, 1, 0);
        vector<int> expected = {5, 10, 15};
        cout << "Test 7: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 8: Negative numbers
    // Input: numbers={-12, -10, -8, -6}, divisor=4, offset=3
    // Filter: -12%4=0✓, -10%4≠0✗, -8%4=0✓, -6%4≠0✗
    // Keep: {-12, -8}
    // Transform: -12+3=-9, -8+3=-5
    // Expected: {-9, -5}
    {
        vector<int> result = problem3Solution({-12, -10, -8, -6}, 4, 3);
        vector<int> expected = {-9, -5};
        cout << "Test 8: " << (result == expected ? "PASS" : "FAIL") << endl;
    }
}

void testProblem4() {
    cout << "\n=== Testing Problem 4: Statistics Calculator ===" << endl;
    
    // Test Case 1: Basic average
    // Input: numbers={1, 5, 3, 8, 2, 6}, min_val=3, max_val=6
    // Filter: 1<3✗, 5 in[3,6]✓, 3 in[3,6]✓, 8>6✗, 2<3✗, 6 in[3,6]✓
    // In range: {5, 3, 6}
    // Sum: 5+3+6=14, Count: 3
    // Average: 14/3 = 4.666...
    // Expected: 4.666... (approximately)
    {
        double result = problem4Solution({1, 5, 3, 8, 2, 6}, 3, 6);
        double expected = 14.0 / 3.0; // 4.666...
        cout << "Test 1: " << (abs(result - expected) < 0.01 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 2: Single number in range
    // Input: numbers={10, 20, 30}, min_val=15, max_val=25
    // Filter: 10<15✗, 20 in[15,25]✓, 30>25✗
    // In range: {20}
    // Sum: 20, Count: 1
    // Average: 20/1 = 20.0
    // Expected: 20.0
    {
        double result = problem4Solution({10, 20, 30}, 15, 25);
        cout << "Test 2: " << (abs(result - 20.0) < 0.01 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 3: No numbers in range
    // Input: numbers={1, 2, 3}, min_val=10, max_val=20
    // Filter: All < 10
    // Count: 0
    // Expected: 0.0 (avoid division by zero)
    {
        double result = problem4Solution({1, 2, 3}, 10, 20);
        cout << "Test 3: " << (result == 0.0 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 4: All numbers in range
    // Input: numbers={5, 10, 15, 20}, min_val=1, max_val=25
    // All in range
    // Sum: 5+10+15+20=50, Count: 4
    // Average: 50/4 = 12.5
    // Expected: 12.5
    {
        double result = problem4Solution({5, 10, 15, 20}, 1, 25);
        cout << "Test 4: " << (abs(result - 12.5) < 0.01 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 5: Negative numbers
    // Input: numbers={-10, -5, 0, 5, 10}, min_val=-7, max_val=7
    // Filter: -10<-7✗, -5 in[-7,7]✓, 0 in[-7,7]✓, 5 in[-7,7]✓, 10>7✗
    // In range: {-5, 0, 5}
    // Sum: -5+0+5=0, Count: 3
    // Average: 0/3 = 0.0
    // Expected: 0.0
    {
        double result = problem4Solution({-10, -5, 0, 5, 10}, -7, 7);
        cout << "Test 5: " << (abs(result - 0.0) < 0.01 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 6: Empty vector
    // Input: numbers={}, min_val=1, max_val=10
    // Expected: 0.0
    {
        double result = problem4Solution({}, 1, 10);
        cout << "Test 6: " << (result == 0.0 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 7: Range boundaries inclusive
    // Input: numbers={5, 10, 15}, min_val=5, max_val=15
    // All in range (boundaries inclusive)
    // Sum: 5+10+15=30, Count: 3
    // Average: 30/3 = 10.0
    // Expected: 10.0
    {
        double result = problem4Solution({5, 10, 15}, 5, 15);
        cout << "Test 7: " << (abs(result - 10.0) < 0.01 ? "PASS" : "FAIL") << endl;
    }
    
    // Test Case 8: Large numbers
    // Input: numbers={100, 200, 300, 400}, min_val=150, max_val=350
    // Filter: 100<150✗, 200 in[150,350]✓, 300 in[150,350]✓, 400>350✗
    // In range: {200, 300}
    // Sum: 200+300=500, Count: 2
    // Average: 500/2 = 250.0
    // Expected: 250.0
    {
        double result = problem4Solution({100, 200, 300, 400}, 150, 350);
        cout << "Test 8: " << (abs(result - 250.0) < 0.01 ? "PASS" : "FAIL") << endl;
    }
}

int main() {
    int choice;
    cout << "===== Lambda Capture Lists Practice Problems =====" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Value Multiplier" << endl;
    cout << "2. Problem 2 (Easy) - Counter with Accumulator" << endl;
    cout << "3. Problem 3 (Medium) - Custom Filter and Transform" << endl;
    cout << "4. Problem 4 (Hard) - Statistics Calculator" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1: testProblem1(); break;
        case 2: testProblem2(); break;
        case 3: testProblem3(); break;
        case 4: testProblem4(); break;
        case 5:
            testProblem1();
            testProblem2();
            testProblem3();
            testProblem4();
            break;
        default: cout << "Invalid choice!" << endl;
    }

    return 0;
}