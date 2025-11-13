#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// ==================== PROBLEM 1: EASY - Student Grade Calculator ====================
// Description: You are given a pointer to a struct containing student information.
// Use arrow pointer notation (->) to access and calculate the student's average grade.
// 
// Input: Pointer to Student struct with 3 test scores
// Output: Return the average of the three test scores (as integer, truncated)
// 
// Example 1:
//   Input: Student with scores {85, 90, 88}
//   Output: 87 (because (85+90+88)/3 = 263/3 = 87.666... truncated to 87)
//
// Example 2:
//   Input: Student with scores {100, 95, 90}
//   Output: 95 (because (100+95+90)/3 = 285/3 = 95)
//
// Constraints: 
//   - Scores are between 0 and 100
//   - Return integer average (truncated, not rounded)

struct Student {
    string name;
    int score1;
    int score2;
    int score3;
};

int problem1Solution(Student* student) {
    // TODO: Implement your solution here using arrow pointer call notation (->)
    // Hint: Use student->score1, student->score2, student->score3 to access the scores
    // Calculate the sum and divide by 3, returning the integer result
}

// ==================== PROBLEM 2: EASY-MEDIUM - Rectangle Area Calculator ====================
// Description: You have a pointer to a Rectangle struct. Calculate and UPDATE the area
// of the rectangle using arrow pointer notation. Then return the calculated area.
//
// Input: Pointer to Rectangle struct with length and width
// Output: Return the area (also store it in the area member of the struct)
//
// Example 1:
//   Input: Rectangle with length=5, width=4
//   Output: 20 (5 * 4 = 20)
//
// Example 2:
//   Input: Rectangle with length=7, width=3
//   Output: 21 (7 * 3 = 21)
//
// Constraints:
//   - Length and width are positive integers (1-1000)
//   - Must UPDATE the area field in the struct using ->

struct Rectangle {
    int length;
    int width;
    int area;
};

int problem2Solution(Rectangle* rect) {
    // TODO: Implement your solution here using arrow pointer call notation (->)
    // Hint: Calculate area = length * width, store it in rect->area, and return it
}

// ==================== PROBLEM 3: MEDIUM - Bank Account Transaction Processor ====================
// Description: You are given a pointer to a BankAccount struct. Process a transaction
// (deposit or withdrawal) and update the balance. Return true if transaction successful,
// false if withdrawal would make balance negative.
//
// Input: 
//   - Pointer to BankAccount struct
//   - transactionAmount: positive for deposit, negative for withdrawal
// Output: Return true if successful, false if insufficient funds
//
// Example 1:
//   Input: Account with balance=1000, transactionAmount=500
//   Output: true, new balance=1500 (deposit successful)
//
// Example 2:
//   Input: Account with balance=1000, transactionAmount=-500
//   Output: true, new balance=500 (withdrawal successful)
//
// Example 3:
//   Input: Account with balance=1000, transactionAmount=-1500
//   Output: false, balance remains 1000 (insufficient funds)
//
// Constraints:
//   - Initial balance >= 0
//   - Balance cannot go negative
//   - Must update balance using ->

struct BankAccount {
    string accountNumber;
    double balance;
    string ownerName;
};

bool problem3Solution(BankAccount* account, double transactionAmount) {
    // TODO: Implement your solution here using arrow pointer call notation (->)
    // Hint: Check if balance + transactionAmount >= 0 before updating
    // If valid, update account->balance and return true, else return false
}

// ==================== PROBLEM 4: HARD - Linked List Node Value Sum ====================
// Description: You are given a pointer to the head of a singly linked list.
// Calculate the sum of all node values in the list using arrow pointer notation.
// You must traverse the list using pointers.
//
// Input: Pointer to head Node of a linked list
// Output: Sum of all values in the linked list
//
// Example 1:
//   Input: 5 -> 3 -> 8 -> NULL
//   Output: 16 (5+3+8=16)
//
// Example 2:
//   Input: 10 -> NULL
//   Output: 10
//
// Example 3:
//   Input: NULL (empty list)
//   Output: 0
//
// Constraints:
//   - List can be empty (NULL)
//   - Values can be negative
//   - Must use -> to traverse the list

struct Node {
    int value;
    Node* next;
};

int problem4Solution(Node* head) {
    // TODO: Implement your solution here using arrow pointer call notation (->)
    // Hint: Use a while loop - while(current != nullptr)
    // Access current->value and move to next using current = current->next
}

// ==================== TEST FUNCTIONS ====================

void testProblem1() {
    cout << "\n========== Testing Problem 1: Student Grade Calculator ==========" << endl;
    
    // Test Case 1: Normal case - mixed scores
    // Calculation: (85 + 90 + 88) / 3 = 263 / 3 = 87.666... = 87 (truncated)
    Student s1 = {"Alice", 85, 90, 88};
    cout << "Test 1 (Alice: 85,90,88): " << (problem1Solution(&s1) == 87 ? "PASS" : "FAIL") 
         << " (Expected: 87)" << endl;
    
    // Test Case 2: All perfect scores
    // Calculation: (100 + 100 + 100) / 3 = 300 / 3 = 100
    Student s2 = {"Bob", 100, 100, 100};
    cout << "Test 2 (Bob: 100,100,100): " << (problem1Solution(&s2) == 100 ? "PASS" : "FAIL") 
         << " (Expected: 100)" << endl;
    
    // Test Case 3: Low scores
    // Calculation: (60 + 65 + 70) / 3 = 195 / 3 = 65
    Student s3 = {"Charlie", 60, 65, 70};
    cout << "Test 3 (Charlie: 60,65,70): " << (problem1Solution(&s3) == 65 ? "PASS" : "FAIL") 
         << " (Expected: 65)" << endl;
    
    // Test Case 4: Edge case - all zeros
    // Calculation: (0 + 0 + 0) / 3 = 0 / 3 = 0
    Student s4 = {"David", 0, 0, 0};
    cout << "Test 4 (David: 0,0,0): " << (problem1Solution(&s4) == 0 ? "PASS" : "FAIL") 
         << " (Expected: 0)" << endl;
    
    // Test Case 5: Truncation test
    // Calculation: (75 + 80 + 85) / 3 = 240 / 3 = 80
    Student s5 = {"Eve", 75, 80, 85};
    cout << "Test 5 (Eve: 75,80,85): " << (problem1Solution(&s5) == 80 ? "PASS" : "FAIL") 
         << " (Expected: 80)" << endl;
    
    // Test Case 6: Another truncation case
    // Calculation: (88 + 89 + 90) / 3 = 267 / 3 = 89
    Student s6 = {"Frank", 88, 89, 90};
    cout << "Test 6 (Frank: 88,89,90): " << (problem1Solution(&s6) == 89 ? "PASS" : "FAIL") 
         << " (Expected: 89)" << endl;
    
    // Test Case 7: High variance
    // Calculation: (50 + 100 + 75) / 3 = 225 / 3 = 75
    Student s7 = {"Grace", 50, 100, 75};
    cout << "Test 7 (Grace: 50,100,75): " << (problem1Solution(&s7) == 75 ? "PASS" : "FAIL") 
         << " (Expected: 75)" << endl;
    
    // Test Case 8: Decimal truncation
    // Calculation: (91 + 92 + 94) / 3 = 277 / 3 = 92.333... = 92 (truncated)
    Student s8 = {"Henry", 91, 92, 94};
    cout << "Test 8 (Henry: 91,92,94): " << (problem1Solution(&s8) == 92 ? "PASS" : "FAIL") 
         << " (Expected: 92)" << endl;
}

void testProblem2() {
    cout << "\n========== Testing Problem 2: Rectangle Area Calculator ==========" << endl;
    
    // Test Case 1: Normal rectangle
    // Calculation: 5 * 4 = 20
    Rectangle r1 = {5, 4, 0};
    int result1 = problem2Solution(&r1);
    cout << "Test 1 (5x4): " << (result1 == 20 && r1.area == 20 ? "PASS" : "FAIL") 
         << " (Expected: 20, Got: " << result1 << ", Stored: " << r1.area << ")" << endl;
    
    // Test Case 2: Square
    // Calculation: 10 * 10 = 100
    Rectangle r2 = {10, 10, 0};
    int result2 = problem2Solution(&r2);
    cout << "Test 2 (10x10): " << (result2 == 100 && r2.area == 100 ? "PASS" : "FAIL") 
         << " (Expected: 100, Got: " << result2 << ", Stored: " << r2.area << ")" << endl;
    
    // Test Case 3: Long rectangle
    // Calculation: 15 * 3 = 45
    Rectangle r3 = {15, 3, 0};
    int result3 = problem2Solution(&r3);
    cout << "Test 3 (15x3): " << (result3 == 45 && r3.area == 45 ? "PASS" : "FAIL") 
         << " (Expected: 45, Got: " << result3 << ", Stored: " << r3.area << ")" << endl;
    
    // Test Case 4: Unit square
    // Calculation: 1 * 1 = 1
    Rectangle r4 = {1, 1, 0};
    int result4 = problem2Solution(&r4);
    cout << "Test 4 (1x1): " << (result4 == 1 && r4.area == 1 ? "PASS" : "FAIL") 
         << " (Expected: 1, Got: " << result4 << ", Stored: " << r4.area << ")" << endl;
    
    // Test Case 5: Large rectangle
    // Calculation: 100 * 50 = 5000
    Rectangle r5 = {100, 50, 0};
    int result5 = problem2Solution(&r5);
    cout << "Test 5 (100x50): " << (result5 == 5000 && r5.area == 5000 ? "PASS" : "FAIL") 
         << " (Expected: 5000, Got: " << result5 << ", Stored: " << r5.area << ")" << endl;
    
    // Test Case 6: Thin rectangle
    // Calculation: 20 * 2 = 40
    Rectangle r6 = {20, 2, 0};
    int result6 = problem2Solution(&r6);
    cout << "Test 6 (20x2): " << (result6 == 40 && r6.area == 40 ? "PASS" : "FAIL") 
         << " (Expected: 40, Got: " << result6 << ", Stored: " << r6.area << ")" << endl;
    
    // Test Case 7: Another square
    // Calculation: 7 * 7 = 49
    Rectangle r7 = {7, 7, 0};
    int result7 = problem2Solution(&r7);
    cout << "Test 7 (7x7): " << (result7 == 49 && r7.area == 49 ? "PASS" : "FAIL") 
         << " (Expected: 49, Got: " << result7 << ", Stored: " << r7.area << ")" << endl;
    
    // Test Case 8: Wide rectangle
    // Calculation: 8 * 12 = 96
    Rectangle r8 = {8, 12, 0};
    int result8 = problem2Solution(&r8);
    cout << "Test 8 (8x12): " << (result8 == 96 && r8.area == 96 ? "PASS" : "FAIL") 
         << " (Expected: 96, Got: " << result8 << ", Stored: " << r8.area << ")" << endl;
}

void testProblem3() {
    cout << "\n========== Testing Problem 3: Bank Account Transaction Processor ==========" << endl;
    
    // Test Case 1: Valid deposit
    // Initial: 1000, Transaction: +500, Expected: 1500, Result: true
    BankAccount acc1 = {"ACC001", 1000.0, "Alice"};
    bool result1 = problem3Solution(&acc1, 500.0);
    cout << "Test 1 (Deposit +500): " << (result1 == true && acc1.balance == 1500.0 ? "PASS" : "FAIL")
         << " (Expected: true, balance=1500, Got: " << result1 << ", balance=" << acc1.balance << ")" << endl;
    
    // Test Case 2: Valid withdrawal
    // Initial: 1000, Transaction: -500, Expected: 500, Result: true
    BankAccount acc2 = {"ACC002", 1000.0, "Bob"};
    bool result2 = problem3Solution(&acc2, -500.0);
    cout << "Test 2 (Withdrawal -500): " << (result2 == true && acc2.balance == 500.0 ? "PASS" : "FAIL")
         << " (Expected: true, balance=500, Got: " << result2 << ", balance=" << acc2.balance << ")" << endl;
    
    // Test Case 3: Insufficient funds
    // Initial: 1000, Transaction: -1500, Expected: 1000 (unchanged), Result: false
    BankAccount acc3 = {"ACC003", 1000.0, "Charlie"};
    bool result3 = problem3Solution(&acc3, -1500.0);
    cout << "Test 3 (Insufficient -1500): " << (result3 == false && acc3.balance == 1000.0 ? "PASS" : "FAIL")
         << " (Expected: false, balance=1000, Got: " << result3 << ", balance=" << acc3.balance << ")" << endl;
    
    // Test Case 4: Exact withdrawal (balance to zero)
    // Initial: 500, Transaction: -500, Expected: 0, Result: true
    BankAccount acc4 = {"ACC004", 500.0, "David"};
    bool result4 = problem3Solution(&acc4, -500.0);
    cout << "Test 4 (Exact withdrawal -500): " << (result4 == true && acc4.balance == 0.0 ? "PASS" : "FAIL")
         << " (Expected: true, balance=0, Got: " << result4 << ", balance=" << acc4.balance << ")" << endl;
    
    // Test Case 5: Small deposit
    // Initial: 100, Transaction: +25, Expected: 125, Result: true
    BankAccount acc5 = {"ACC005", 100.0, "Eve"};
    bool result5 = problem3Solution(&acc5, 25.0);
    cout << "Test 5 (Small deposit +25): " << (result5 == true && acc5.balance == 125.0 ? "PASS" : "FAIL")
         << " (Expected: true, balance=125, Got: " << result5 << ", balance=" << acc5.balance << ")" << endl;
    
    // Test Case 6: Zero balance, attempt withdrawal
    // Initial: 0, Transaction: -100, Expected: 0 (unchanged), Result: false
    BankAccount acc6 = {"ACC006", 0.0, "Frank"};
    bool result6 = problem3Solution(&acc6, -100.0);
    cout << "Test 6 (Zero balance, withdraw -100): " << (result6 == false && acc6.balance == 0.0 ? "PASS" : "FAIL")
         << " (Expected: false, balance=0, Got: " << result6 << ", balance=" << acc6.balance << ")" << endl;
    
    // Test Case 7: Large deposit
    // Initial: 5000, Transaction: +10000, Expected: 15000, Result: true
    BankAccount acc7 = {"ACC007", 5000.0, "Grace"};
    bool result7 = problem3Solution(&acc7, 10000.0);
    cout << "Test 7 (Large deposit +10000): " << (result7 == true && acc7.balance == 15000.0 ? "PASS" : "FAIL")
         << " (Expected: true, balance=15000, Got: " << result7 << ", balance=" << acc7.balance << ")" << endl;
    
    // Test Case 8: Borderline insufficient (off by 0.01)
    // Initial: 100, Transaction: -100.01, Expected: 100 (unchanged), Result: false
    BankAccount acc8 = {"ACC008", 100.0, "Henry"};
    bool result8 = problem3Solution(&acc8, -100.01);
    cout << "Test 8 (Borderline -100.01): " << (result8 == false && acc8.balance == 100.0 ? "PASS" : "FAIL")
         << " (Expected: false, balance=100, Got: " << result8 << ", balance=" << acc8.balance << ")" << endl;
}

void testProblem4() {
    cout << "\n========== Testing Problem 4: Linked List Node Value Sum ==========" << endl;
    
    // Test Case 1: Normal list: 5 -> 3 -> 8 -> NULL
    // Calculation: 5 + 3 + 8 = 16
    Node n1_3 = {8, nullptr};
    Node n1_2 = {3, &n1_3};
    Node n1_1 = {5, &n1_2};
    cout << "Test 1 (5->3->8): " << (problem4Solution(&n1_1) == 16 ? "PASS" : "FAIL")
         << " (Expected: 16)" << endl;
    
    // Test Case 2: Single node: 10 -> NULL
    // Calculation: 10
    Node n2_1 = {10, nullptr};
    cout << "Test 2 (10): " << (problem4Solution(&n2_1) == 10 ? "PASS" : "FAIL")
         << " (Expected: 10)" << endl;
    
    // Test Case 3: Empty list: NULL
    // Calculation: 0
    cout << "Test 3 (empty list): " << (problem4Solution(nullptr) == 0 ? "PASS" : "FAIL")
         << " (Expected: 0)" << endl;
    
    // Test Case 4: Negative values: -5 -> 10 -> -3 -> NULL
    // Calculation: -5 + 10 + (-3) = 2
    Node n4_3 = {-3, nullptr};
    Node n4_2 = {10, &n4_3};
    Node n4_1 = {-5, &n4_2};
    cout << "Test 4 (-5->10->-3): " << (problem4Solution(&n4_1) == 2 ? "PASS" : "FAIL")
         << " (Expected: 2)" << endl;
    
    // Test Case 5: All zeros: 0 -> 0 -> 0 -> NULL
    // Calculation: 0 + 0 + 0 = 0
    Node n5_3 = {0, nullptr};
    Node n5_2 = {0, &n5_3};
    Node n5_1 = {0, &n5_2};
    cout << "Test 5 (0->0->0): " << (problem4Solution(&n5_1) == 0 ? "PASS" : "FAIL")
         << " (Expected: 0)" << endl;
    
    // Test Case 6: Large values: 100 -> 200 -> 300 -> NULL
    // Calculation: 100 + 200 + 300 = 600
    Node n6_3 = {300, nullptr};
    Node n6_2 = {200, &n6_3};
    Node n6_1 = {100, &n6_2};
    cout << "Test 6 (100->200->300): " << (problem4Solution(&n6_1) == 600 ? "PASS" : "FAIL")
         << " (Expected: 600)" << endl;
    
    // Test Case 7: All negative: -1 -> -2 -> -3 -> -4 -> NULL
    // Calculation: -1 + (-2) + (-3) + (-4) = -10
    Node n7_4 = {-4, nullptr};
    Node n7_3 = {-3, &n7_4};
    Node n7_2 = {-2, &n7_3};
    Node n7_1 = {-1, &n7_2};
    cout << "Test 7 (-1->-2->-3->-4): " << (problem4Solution(&n7_1) == -10 ? "PASS" : "FAIL")
         << " (Expected: -10)" << endl;
    
    // Test Case 8: Long list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    // Calculation: 1 + 2 + 3 + 4 + 5 = 15
    Node n8_5 = {5, nullptr};
    Node n8_4 = {4, &n8_5};
    Node n8_3 = {3, &n8_4};
    Node n8_2 = {2, &n8_3};
    Node n8_1 = {1, &n8_2};
    cout << "Test 8 (1->2->3->4->5): " << (problem4Solution(&n8_1) == 15 ? "PASS" : "FAIL")
         << " (Expected: 15)" << endl;
}

// ==================== MAIN FUNCTION ====================

int main() {
    int choice;
    cout << "==============================================================" << endl;
    cout << "   Arrow Pointer Call Notation (->) Practice Problems" << endl;
    cout << "==============================================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Student Grade Calculator" << endl;
    cout << "2. Problem 2 (Easy-Medium) - Rectangle Area Calculator" << endl;
    cout << "3. Problem 3 (Medium) - Bank Account Transaction Processor" << endl;
    cout << "4. Problem 4 (Hard) - Linked List Node Value Sum" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "==============================================================" << endl;
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
        default: 
            cout << "Invalid choice! Please enter 1-5." << endl;
    }

    return 0;
}