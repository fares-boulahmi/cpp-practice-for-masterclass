#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Problem 1: Easy 1 - Simple Score Accumulator
// You are building a simple game score system. Given an initial score and a series of point changes,
// calculate the final score using compound assignment operators.
// Input: Initial score (int), number of changes (int), then that many score changes (can be positive or negative)
// Output: Final score after all changes
// 
// Example 1:
// Initial score: 100, Changes: 3, Values: [15, -10, 25]
// Operations: score += 15 (115), score -= 10 (105), score += 25 (130)
// Output: 130
//
// Example 2:
// Initial score: 50, Changes: 4, Values: [20, -5, 10, -15]
// Output: 60
//
// Constraints: -1000 ≤ initial score ≤ 1000, 1 ≤ number of changes ≤ 10, -100 ≤ each change ≤ 100
int problem1Solution(int initialScore, vector<int> changes) {
    // TODO: Implement your solution here using Compound Assignment Operators (+=, -=)
    // Hint: Start with the initial score and apply each change using += or -= based on sign
    int score = initialScore ;
    for (int i = 0 ; i < changes.size() ; i++) {
        score += changes[i];
    }
    return score;
}

// Problem 2: Easy 2 - Bank Account Interest Calculator
// A bank account earns compound interest. Given an initial balance, interest rate (as integer percentage),
// and number of years, calculate the final balance. Use compound assignment to update the balance each year.
// Also track how much total interest was earned using compound assignment.
// 
// Input: Initial balance (int), interest rate percentage (int), number of years (int)
// Output: Final balance (int) - use integer division, no decimals
//
// Example 1:
// Initial: 1000, Rate: 5%, Years: 3
// Year 1: balance += (balance * 5 / 100) → 1000 + 50 = 1050
// Year 2: balance += (balance * 5 / 100) → 1050 + 52 = 1102  
// Year 3: balance += (balance * 5 / 100) → 1102 + 55 = 1157
// Output: 1157
//
// Example 2:
// Initial: 2000, Rate: 10%, Years: 2
// Output: 2420
//
// Constraints: 100 ≤ initial balance ≤ 10000, 1 ≤ rate ≤ 20, 1 ≤ years ≤ 10
int problem2Solution(int initialBalance, int interestRate, int years) {
    // TODO: Implement your solution here using Compound Assignment Operators (*=, +=, /=)
    // Hint: For each year, calculate interest and add it to balance using compound assignment
    double balance = initialBalance ;
    for (int i = 0 ; i < years ; i++) {
        balance += ((balance * interestRate) / 100 );
    }
    int result  = static_cast<int>(balance) ;
    return result;
}

// Problem 3: Medium - Array Element Modifier
// Given an array of integers and a series of operations, modify the array elements using compound assignment.
// Operations are given as: position, operator_type, value
// operator_type: 1(+=), 2(-=), 3(*=), 4(/=), 5(%=)
// After all operations, return the sum of all elements in the array.
//
// Input: Array size (int), array elements, number of operations (int), 
//        then for each operation: position (0-indexed), operation_type, value
// Output: Sum of all array elements after all operations
//
// Example 1:
// Array: [10, 20, 30], Operations: 3
// Op1: position=1, type=1, value=5 → array[1] += 5 → [10, 25, 30]
// Op2: position=0, type=3, value=2 → array[0] *= 2 → [20, 25, 30]  
// Op3: position=2, type=2, value=10 → array[2] -= 10 → [20, 25, 20]
// Sum = 20 + 25 + 20 = 65
// Output: 65
//
// Example 2:
// Array: [100, 50], Operations: 2
// Op1: position=0, type=4, value=5 → [20, 50]
// Op2: position=1, type=5, value=7 → [20, 1]
// Output: 21
//
// Constraints: 1 ≤ array size ≤ 100, 1 ≤ elements ≤ 1000, 1 ≤ operations ≤ 50
// For division and modulo, value will never be 0
int problem3Solution(vector<int> arr, vector<vector<int>> operations) {
    // TODO: Implement your solution here using Compound Assignment Operators (+=, -=, *=, /=, %=)
    // Hint: For each operation, apply the compound assignment to the specified array position
    vector<int> value = arr;
    int result{} ;
    for( int i = 0 ; i < operations.size() ; i++ ) {
        if (operations[i][1] == 1) {
            value[operations[i][0]] += operations[i][2];
        } else if (operations[i][1] == 2) {
            value[operations[i][0]] -= operations[i][2];
        } else if (operations[i][1] == 3) {
            value[operations[i][0]] *= operations[i][2];
        }else if (operations[i][1] == 4) {
            value[operations[i][0]] /= operations[i][2];
        }else {
            value[operations[i][0]] %= operations[i][2];
        }
        // cout << "array place is : " << value[operations[i][0]] << endl;
    }
    for (int i = 0 ; i < value.size() ; i++ ) {
        result += value[i];
    }
    cout << "the result is "<< result << endl;
    return result;
}

// Problem 4: Hard - Complex Number Calculator Simulator
// Simulate a calculator that performs operations on a running total. The calculator starts at 0.
// Given a series of commands, each containing an operation type and a value, calculate the final result.
// Operation types: 1(+=), 2(-=), 3(*=), 4(/=), 5(%=), 6(^= power using repeated multiplication)
// Special rule: If the result becomes negative after any operation, apply the absolute value.
// Special rule: If result becomes 0 after division or modulo, reset to 1.
// Track the number of operations that resulted in the special rules being applied.
//
// Input: Number of commands (int), then for each command: operation_type, value
// Output: Final result and count of special rule applications (return as: result * 1000 + count)
//
// Example 1:
// Commands: 4
// Cmd1: type=1, value=50 → total += 50 → total = 50
// Cmd2: type=3, value=2 → total *= 2 → total = 100  
// Cmd3: type=2, value=150 → total -= 150 → total = -50 → abs(-50) = 50 (special rule: count++)
// Cmd4: type=4, value=25 → total /= 25 → total = 2
// Final result: 2, Special rule count: 1
// Output: 2 * 1000 + 1 = 2001
//
// Example 2:
// Commands: 3  
// Cmd1: type=1, value=10 → total = 10
// Cmd2: type=4, value=20 → total /= 20 → total = 0 → reset to 1 (special rule: count++)
// Cmd3: type=6, value=3 → total ^= 3 → total = 1*1*1 = 1
// Output: 1 * 1000 + 1 = 1001
//
// Constraints: 1 ≤ commands ≤ 20, 1 ≤ values ≤ 100, for power operation: 1 ≤ power ≤ 5
int problem4Solution(vector<vector<int>> commands) {
        // if (value < 0 ) {
        //     return (value * value)^-2 ;
        // } else {

        //     return value;
        // }
        int result {};
        int special_rule{};
        for (int i = 0 ; i < commands.size() ; i++) {
            if (commands[i][0] == 1 ) {
                result += commands[i][1];
            } else if (commands[i][0] == 2 ) {
                result -= commands[i][1];
            } else if (commands[i][0] == 3 )  {
                result *= commands[i][1];
            } else if (commands[i][0] == 4 )  {
                result /= commands[i][1];
                if (result == 0){
                    result++;
                    special_rule++;
                } 
            } else if (commands[i][0] == 5 ) {
                result %= commands[i][1];
                if (result == 0){
                    result++;
                    special_rule++;
                } 
            } else {
                result = pow(result , commands[i][1]);
                
            }
             if (result < 0 ) {
                result =  abs(result) ;
                special_rule++;
            }  


        }
    // TODO: Implement your solution here using Compound Assignment Operators
    // Hint: Use a loop for power operation, check for special conditions after each operation
    return result * 1000 + special_rule;
}

void testProblem1() {
    cout << "Testing Problem 1 - Simple Score Accumulator..." << endl;
    
    // Test Case 1: Basic positive and negative changes
    vector<int> changes1 = {15, -10, 25};
    cout << "Test 1: " << (problem1Solution(100, changes1) == 130 ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: Multiple small changes
    vector<int> changes2 = {20, -5, 10, -15};
    cout << "Test 2: " << (problem1Solution(50, changes2) == 60 ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: All positive changes
    vector<int> changes3 = {10, 20, 30};
    cout << "Test 3: " << (problem1Solution(0, changes3) == 60 ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: All negative changes
    vector<int> changes4 = {-10, -20, -5};
    cout << "Test 4: " << (problem1Solution(100, changes4) == 65 ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: Single change
    vector<int> changes5 = {50};
    cout << "Test 5: " << (problem1Solution(-20, changes5) == 30 ? "PASS" : "FAIL") << endl;
    
    // Test Case 6: Large numbers
    vector<int> changes6 = {100, -50, 25, -25};
    cout << "Test 6: " << (problem1Solution(500, changes6) == 550 ? "PASS" : "FAIL") << endl;
    
    // Test Case 7: Zero initial score
    vector<int> changes7 = {-10, 20, -5};
    cout << "Test 7: " << (problem1Solution(0, changes7) == 5 ? "PASS" : "FAIL") << endl;
    
    // Test Case 8: Result becomes negative
    vector<int> changes8 = {-200};
    cout << "Test 8: " << (problem1Solution(50, changes8) == -150 ? "PASS" : "FAIL") << endl;
}

void testProblem2() {
    cout << "Testing Problem 2 - Bank Account Interest Calculator..." << endl;
    
    // Test Case 1: Basic compound interest
    cout << "Test 1: " << (problem2Solution(1000, 5, 3) == 1157 ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: Higher interest rate
    cout << "Test 2: " << (problem2Solution(2000, 10, 2) == 2420 ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: Single year
    cout << "Test 3: " << (problem2Solution(500, 8, 1) == 540 ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: Low interest rate
    cout << "Test 4: " << (problem2Solution(1000, 1, 5) == 1051 ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: Small initial amount
    cout << "Test 5: " << (problem2Solution(100, 15, 2) == 132 ? "PASS" : "FAIL") << endl;
    
    // Test Case 6: Zero interest growth check
    cout << "Test 6: " << (problem2Solution(300, 3, 4) == 337 ? "PASS" : "FAIL") << endl;
    
    // Test Case 7: Higher years
    cout << "Test 7: " << (problem2Solution(1500, 6, 5) == 2007 ? "PASS" : "FAIL") << endl;
    
    // Test Case 8: Maximum values
    cout << "Test 8: " << (problem2Solution(10000, 20, 3) == 17280 ? "PASS" : "FAIL") << endl;
}

void testProblem3() {
    cout << "Testing Problem 3 - Array Element Modifier..." << endl;
    
    // Test Case 1: Basic operations
    vector<int> arr1 = {10, 20, 30};
    vector<vector<int>> ops1 = {{1, 1, 5}, {0, 3, 2}, {2, 2, 10}};
    cout << "Test 1: " << (problem3Solution(arr1, ops1) == 65 ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: Division and modulo
    vector<int> arr2 = {100, 50};
    vector<vector<int>> ops2 = {{0, 4, 5}, {1, 5, 7}};
    cout << "Test 2: " << (problem3Solution(arr2, ops2) == 21 ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: Only additions
    vector<int> arr3 = {1, 2, 3, 4};
    vector<vector<int>> ops3 = {{0, 1, 10}, {1, 1, 20}, {2, 1, 30}, {3, 1, 40}};
    cout << "Test 3: " << (problem3Solution(arr3, ops3) == 110 ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: Only multiplications
    vector<int> arr4 = {5, 10};
    vector<vector<int>> ops4 = {{0, 3, 3}, {1, 3, 2}};
    cout << "Test 4: " << (problem3Solution(arr4, ops4) == 35 ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: Mixed operations on single element
    vector<int> arr5 = {100};
    vector<vector<int>> ops5 = {{0, 1, 50}, {0, 2, 25}, {0, 3, 5}};
    cout << "Test 5: " << (problem3Solution(arr5, ops5) == 625 ? "PASS" : "FAIL") << endl;
    
    // Test Case 6: Large array
    vector<int> arr6 = {1, 1, 1, 1, 1};
    vector<vector<int>> ops6 = {{0, 3, 10}, {2, 3, 20}, {4, 3, 5}};
    cout << "Test 6: " << (problem3Solution(arr6, ops6) == 37 ? "PASS" : "FAIL") << endl;
    
    // Test Case 7: Subtractions making negatives
    vector<int> arr7 = {50, 30};
    vector<vector<int>> ops7 = {{0, 2, 60}, {1, 2, 40}};
    cout << "Test 7: " << (problem3Solution(arr7, ops7) == -20 ? "PASS" : "FAIL") << endl;
    
    // Test Case 8: Complex modulo operations
    vector<int> arr8 = {17, 23, 19};
    vector<vector<int>> ops8 = {{0, 5, 5}, {1, 5, 7}, {2, 5, 6}};
    cout << "Test 8: " << (problem3Solution(arr8, ops8) == 5 ? "PASS" : "FAIL") << endl;
}

void testProblem4() {
    cout << "Testing Problem 4 - Complex Number Calculator Simulator..." << endl;
    
    // Test Case 1: Basic operations with one special rule
    vector<vector<int>> cmds1 = {{1, 50}, {3, 2}, {2, 150}, {4, 25}};
    cout << "Test 1: " << (problem4Solution(cmds1) == 2001 ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: Division resulting in zero
    vector<vector<int>> cmds2 = {{1, 10}, {4, 20}, {6, 3}};
    cout << "Test 2: " << (problem4Solution(cmds2) == 1001 ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: No special rules triggered
    vector<vector<int>> cmds3 = {{1, 20}, {3, 3}, {2, 10}};
    cout << "Test 3: " << (problem4Solution(cmds3) == 50000 ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: Multiple special rules
    vector<vector<int>> cmds4 = {{1, 5}, {2, 10}, {1, 3}, {4, 10}};
    cout << "Test 4: " << (problem4Solution(cmds4) == 1002 ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: Power operations
    vector<vector<int>> cmds5 = {{1, 3}, {6, 4}};
    cout << "Test 5: " << (problem4Solution(cmds5) == 81000 ? "PASS" : "FAIL") << endl;
    
    // Test Case 6: Modulo resulting in zero
    vector<vector<int>> cmds6 = {{1, 15}, {5, 5}};
    cout << "Test 6: " << (problem4Solution(cmds6) == 1001 ? "PASS" : "FAIL") << endl;
    
    // Test Case 7: Complex sequence
    vector<vector<int>> cmds7 = {{1, 100}, {4, 10}, {3, 5}, {2, 60}};
    cout << "Test 7: " << (problem4Solution(cmds7) == 10001 ? "PASS" : "FAIL") << endl;
    
    // Test Case 8: Single operation
    vector<vector<int>> cmds8 = {{6, 2}};
    cout << "Test 8: " << (problem4Solution(cmds8) == 0 ? "PASS" : "FAIL") << endl;
}

int main() {
    int choice;
    cout << "=== Compound Assignment Operators Practice ===" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Simple Score Accumulator" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Bank Account Interest Calculator" << endl;
    cout << "3. Problem 3 (Medium) - Array Element Modifier" << endl;
    cout << "4. Problem 4 (Hard) - Complex Number Calculator Simulator" << endl;
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
            cout << endl;
            testProblem2();
            cout << endl;
            testProblem3();
            cout << endl;
            testProblem4();
            break;
        default: cout << "Invalid choice!" << endl;
    }

    return 0;
}