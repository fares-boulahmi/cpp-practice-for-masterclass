#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Student Grade Manager
// ============================================================================
// Description:
// Create a Student class that manages a student's name and grade.
// The grade must be between 0 and 100 (inclusive).
// If an invalid grade is set, keep the previous valid grade.
//
// Your task: Implement the Student class with:
// - Private members: name (string), grade (int)
// - Constructor that takes name and grade
// - Setter for grade (validate: 0-100)
// - Getter for grade
// - Getter for name
// - Method isPassing() that returns true if grade >= 60
//
// Input Format:
// - Student name (string)
// - Grade value (int)
//
// Output Format:
// - Return the grade value after validation
// - Return pass/fail status
//
// Example 1:
// Input: name="Alice", grade=85
// Output: grade=85, isPassing=true
//
// Example 2:
// Input: name="Bob", grade=150 (invalid)
// Output: grade remains at initial/previous value
//
// Constraints:
// - Grade must be 0-100
// - Name is non-empty string
// ============================================================================

class Student
{
    // TODO: Implement your solution here using Setters and Getters
    // Hint: Use a private member variable for grade and validate in setter
    // Hint: Constructor should initialize with valid values
    // Hint: Setter should check range before updating grade
};

// ============================================================================
// Problem 2: Easy 2 - Rectangle Dimension Manager
// ============================================================================
// Description:
// Create a Rectangle class that manages width and height.
// Both dimensions must be positive (> 0).
// If an invalid dimension is set, keep the previous valid dimension.
//
// Your task: Implement the Rectangle class with:
// - Private members: width (double), height (double)
// - Constructor that takes width and height
// - Setters for width and height (validate: > 0)
// - Getters for width and height
// - Method getArea() that returns width * height
// - Method getPerimeter() that returns 2 * (width + height)
//
// Input Format:
// - Width value (double)
// - Height value (double)
//
// Output Format:
// - Return area and perimeter calculations
//
// Example 1:
// Input: width=5.0, height=3.0
// Output: area=15.0, perimeter=16.0
//
// Example 2:
// Input: width=4.5, height=-2.0 (invalid height)
// Output: height remains at previous valid value
//
// Constraints:
// - Width and height must be > 0
// - Use double for precision
// ============================================================================

class Rectangle
{
    // TODO: Implement your solution here using Setters and Getters
    // Hint: Validate both width and height are positive in setters
    // Hint: Use double for decimal precision
    // Hint: Area = width * height, Perimeter = 2 * (width + height)
};

// ============================================================================
// Problem 3: Medium - Bank Account with Transaction Limits
// ============================================================================
// Description:
// Create a BankAccount class that manages account balance with transaction limits.
// The account has:
// - Balance (cannot be negative)
// - Daily withdrawal limit
// - Current daily withdrawals total
//
// Your task: Implement the BankAccount class with:
// - Private members: balance (double), dailyLimit (double), todayWithdrawn (double)
// - Constructor(initialBalance, dailyLimit)
// - deposit(amount) - adds to balance, returns true if successful
// - withdraw(amount) - removes from balance if valid, returns true if successful
// - Getter for balance
// - Method resetDailyLimit() - resets todayWithdrawn to 0
// - Withdrawal is valid only if:
//   * amount > 0
//   * amount <= balance
//   * todayWithdrawn + amount <= dailyLimit
//
// Input Format:
// - Initial balance (double)
// - Daily limit (double)
// - Transaction amounts (double)
//
// Output Format:
// - Return success/failure of transactions (bool)
// - Return current balance (double)
//
// Example 1:
// Input: balance=1000, dailyLimit=500, withdraw(300)
// Output: success=true, balance=700, todayWithdrawn=300
//
// Example 2:
// Input: balance=1000, dailyLimit=500, withdraw(300), withdraw(300)
// Output: first=true, second=false (exceeds daily limit)
//
// Constraints:
// - Balance cannot go negative
// - Daily withdrawal total cannot exceed dailyLimit
// - All amounts must be positive
// ============================================================================

class BankAccount
{
    // TODO: Implement your solution here using Setters and Getters
    // Hint: Track todayWithdrawn separately from balance
    // Hint: Check all three conditions before allowing withdrawal
    // Hint: Only update balance and todayWithdrawn if withdrawal succeeds
};

// ============================================================================
// Problem 4: Hard - Temperature Monitor with Alert System
// ============================================================================
// Description:
// Create a TemperatureMonitor class that tracks temperature readings
// and maintains statistics with an alert system.
//
// Your task: Implement the TemperatureMonitor class with:
// - Private members:
//   * currentTemp (double)
//   * minTemp (double) - lowest recorded
//   * maxTemp (double) - highest recorded
//   * tempCount (int) - number of readings
//   * tempSum (double) - sum of all readings
//   * alertThreshold (double) - alert if temp exceeds this
// - Constructor(alertThreshold)
// - addReading(temp) - adds a new temperature reading
// - Getters for: currentTemp, minTemp, maxTemp, tempCount
// - getAverage() - returns average of all readings
// - isAlert() - returns true if currentTemp > alertThreshold
// - reset() - resets all statistics but keeps alertThreshold
//
// Input Format:
// - Alert threshold (double)
// - Temperature readings (double)
//
// Output Format:
// - Return current statistics and alert status
//
// Example 1:
// Input: threshold=100, readings=[75, 85, 95]
// Output: current=95, min=75, max=95, avg=85, alert=false, count=3
//
// Example 2:
// Input: threshold=100, readings=[75, 105, 95]
// Output: current=95, min=75, max=105, avg=91.67, alert=false, count=3
// Note: alert checks current temp (95), not max temp
//
// Constraints:
// - First reading initializes min and max
// - Average should handle division by zero case
// - Alert is based on current temperature only
// ============================================================================

class TemperatureMonitor
{
    // TODO: Implement your solution here using Setters and Getters
    // Hint: Update min/max only when adding readings
    // Hint: Keep running sum for efficient average calculation
    // Hint: Handle the first reading specially for min/max initialization
    // Hint: isAlert() compares currentTemp with alertThreshold
};

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Student Grade Manager ===" << endl;

    // Test Case 1: Valid grade in middle range
    // Student: "Alice", Grade: 85
    // Expected: grade=85, isPassing=true
    {
        Student s("Alice", 85);
        cout << "Test 1: " << (s.getGrade() == 85 && s.isPassing() == true ? "PASS" : "FAIL")
             << " (Valid grade 85, should be passing)" << endl;
    }

    // Test Case 2: Boundary - minimum passing grade
    // Student: "Bob", Grade: 60
    // Expected: grade=60, isPassing=true (60 is passing)
    {
        Student s("Bob", 60);
        cout << "Test 2: " << (s.getGrade() == 60 && s.isPassing() == true ? "PASS" : "FAIL")
             << " (Grade 60, boundary passing)" << endl;
    }

    // Test Case 3: Failing grade
    // Student: "Charlie", Grade: 45
    // Expected: grade=45, isPassing=false
    {
        Student s("Charlie", 45);
        cout << "Test 3: " << (s.getGrade() == 45 && s.isPassing() == false ? "PASS" : "FAIL")
             << " (Grade 45, should be failing)" << endl;
    }

    // Test Case 4: Perfect score
    // Student: "Diana", Grade: 100
    // Expected: grade=100, isPassing=true
    {
        Student s("Diana", 100);
        cout << "Test 4: " << (s.getGrade() == 100 && s.isPassing() == true ? "PASS" : "FAIL")
             << " (Grade 100, perfect score)" << endl;
    }

    // Test Case 5: Minimum valid grade
    // Student: "Eve", Grade: 0
    // Expected: grade=0, isPassing=false
    {
        Student s("Eve", 0);
        cout << "Test 5: " << (s.getGrade() == 0 && s.isPassing() == false ? "PASS" : "FAIL")
             << " (Grade 0, minimum valid)" << endl;
    }

    // Test Case 6: Try to set invalid high grade
    // Student: "Frank", initial Grade: 75, try to set: 150
    // Expected: grade remains 75, isPassing=true
    {
        Student s("Frank", 75);
        s.setGrade(150); // Invalid, should not change
        cout << "Test 6: " << (s.getGrade() == 75 && s.isPassing() == true ? "PASS" : "FAIL")
             << " (Invalid grade 150, should keep 75)" << endl;
    }

    // Test Case 7: Try to set invalid negative grade
    // Student: "Grace", initial Grade: 80, try to set: -10
    // Expected: grade remains 80, isPassing=true
    {
        Student s("Grace", 80);
        s.setGrade(-10); // Invalid, should not change
        cout << "Test 7: " << (s.getGrade() == 80 && s.isPassing() == true ? "PASS" : "FAIL")
             << " (Invalid grade -10, should keep 80)" << endl;
    }

    // Test Case 8: Boundary - just below passing
    // Student: "Henry", Grade: 59
    // Expected: grade=59, isPassing=false
    {
        Student s("Henry", 59);
        cout << "Test 8: " << (s.getGrade() == 59 && s.isPassing() == false ? "PASS" : "FAIL")
             << " (Grade 59, boundary failing)" << endl;
    }
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Rectangle Dimension Manager ===" << endl;

    // Test Case 1: Normal rectangle
    // Width: 5.0, Height: 3.0
    // Area calculation: 5.0 * 3.0 = 15.0
    // Perimeter calculation: 2 * (5.0 + 3.0) = 2 * 8.0 = 16.0
    {
        Rectangle r(5.0, 3.0);
        cout << "Test 1: " << (r.getArea() == 15.0 && r.getPerimeter() == 16.0 ? "PASS" : "FAIL")
             << " (5x3 rectangle)" << endl;
    }

    // Test Case 2: Square
    // Width: 4.0, Height: 4.0
    // Area calculation: 4.0 * 4.0 = 16.0
    // Perimeter calculation: 2 * (4.0 + 4.0) = 2 * 8.0 = 16.0
    {
        Rectangle r(4.0, 4.0);
        cout << "Test 2: " << (r.getArea() == 16.0 && r.getPerimeter() == 16.0 ? "PASS" : "FAIL")
             << " (4x4 square)" << endl;
    }

    // Test Case 3: Decimal dimensions
    // Width: 4.5, Height: 2.5
    // Area calculation: 4.5 * 2.5 = 11.25
    // Perimeter calculation: 2 * (4.5 + 2.5) = 2 * 7.0 = 14.0
    {
        Rectangle r(4.5, 2.5);
        cout << "Test 3: " << (r.getArea() == 11.25 && r.getPerimeter() == 14.0 ? "PASS" : "FAIL")
             << " (4.5x2.5 with decimals)" << endl;
    }

    // Test Case 4: Try to set invalid negative width
    // Initial: 10.0 x 5.0, try to set width to -3.0
    // Width should remain 10.0
    // Area: 10.0 * 5.0 = 50.0
    // Perimeter: 2 * (10.0 + 5.0) = 30.0
    {
        Rectangle r(10.0, 5.0);
        r.setWidth(-3.0); // Invalid, should not change
        cout << "Test 4: " << (r.getWidth() == 10.0 && r.getArea() == 50.0 ? "PASS" : "FAIL")
             << " (Invalid negative width)" << endl;
    }

    // Test Case 5: Try to set invalid zero height
    // Initial: 8.0 x 6.0, try to set height to 0.0
    // Height should remain 6.0
    // Area: 8.0 * 6.0 = 48.0
    // Perimeter: 2 * (8.0 + 6.0) = 28.0
    {
        Rectangle r(8.0, 6.0);
        r.setHeight(0.0); // Invalid, should not change
        cout << "Test 5: " << (r.getHeight() == 6.0 && r.getArea() == 48.0 ? "PASS" : "FAIL")
             << " (Invalid zero height)" << endl;
    }

    // Test Case 6: Very small valid dimensions
    // Width: 0.1, Height: 0.2
    // Area calculation: 0.1 * 0.2 = 0.02
    // Perimeter calculation: 2 * (0.1 + 0.2) = 2 * 0.3 = 0.6
    {
        Rectangle r(0.1, 0.2);
        cout << "Test 6: " << (abs(r.getArea() - 0.02) < 0.0001 && abs(r.getPerimeter() - 0.6) < 0.0001 ? "PASS" : "FAIL")
             << " (Very small dimensions)" << endl;
    }

    // Test Case 7: Update valid dimensions
    // Initial: 5.0 x 3.0, change to 7.0 x 4.0
    // New Area: 7.0 * 4.0 = 28.0
    // New Perimeter: 2 * (7.0 + 4.0) = 22.0
    {
        Rectangle r(5.0, 3.0);
        r.setWidth(7.0);
        r.setHeight(4.0);
        cout << "Test 7: " << (r.getArea() == 28.0 && r.getPerimeter() == 22.0 ? "PASS" : "FAIL")
             << " (Update to valid dimensions)" << endl;
    }

    // Test Case 8: Large dimensions
    // Width: 1000.5, Height: 500.25
    // Area calculation: 1000.5 * 500.25 = 500,750.125
    // Perimeter calculation: 2 * (1000.5 + 500.25) = 2 * 1500.75 = 3001.5
    {
        Rectangle r(1000.5, 500.25);
        cout << "Test 8: " << (abs(r.getArea() - 500750.125) < 0.001 && abs(r.getPerimeter() - 3001.5) < 0.001 ? "PASS" : "FAIL")
             << " (Large dimensions)" << endl;
    }
}

void testProblem3()
{
    cout << "\n=== Testing Problem 3: Bank Account with Transaction Limits ===" << endl;

    // Test Case 1: Simple valid withdrawal
    // Initial: balance=1000, dailyLimit=500
    // Withdraw: 300
    // Expected: success=true, balance=700
    {
        BankAccount acc(1000.0, 500.0);
        bool success = acc.withdraw(300.0);
        cout << "Test 1: " << (success == true && acc.getBalance() == 700.0 ? "PASS" : "FAIL")
             << " (Withdraw 300 from 1000)" << endl;
    }

    // Test Case 2: Multiple withdrawals within limit
    // Initial: balance=1000, dailyLimit=500
    // Withdraw: 200, then 250
    // Expected: both succeed, final balance=550
    // Calculation: 1000 - 200 = 800, then 800 - 250 = 550
    // Daily total: 200 + 250 = 450 (within 500 limit)
    {
        BankAccount acc(1000.0, 500.0);
        bool w1 = acc.withdraw(200.0);
        bool w2 = acc.withdraw(250.0);
        cout << "Test 2: " << (w1 == true && w2 == true && acc.getBalance() == 550.0 ? "PASS" : "FAIL")
             << " (Two withdrawals: 200 + 250)" << endl;
    }

    // Test Case 3: Exceed daily limit
    // Initial: balance=1000, dailyLimit=500
    // Withdraw: 300, then 300 (total would be 600)
    // Expected: first succeeds, second fails, balance=700
    {
        BankAccount acc(1000.0, 500.0);
        bool w1 = acc.withdraw(300.0);
        bool w2 = acc.withdraw(300.0); // This should fail (300+300=600 > 500)
        cout << "Test 3: " << (w1 == true && w2 == false && acc.getBalance() == 700.0 ? "PASS" : "FAIL")
             << " (Second withdrawal exceeds daily limit)" << endl;
    }

    // Test Case 4: Insufficient balance
    // Initial: balance=500, dailyLimit=1000
    // Withdraw: 600
    // Expected: fail, balance remains 500
    {
        BankAccount acc(500.0, 1000.0);
        bool success = acc.withdraw(600.0);
        cout << "Test 4: " << (success == false && acc.getBalance() == 500.0 ? "PASS" : "FAIL")
             << " (Insufficient balance)" << endl;
    }

    // Test Case 5: Deposit then withdraw
    // Initial: balance=500, dailyLimit=300
    // Deposit: 400 (balance becomes 900)
    // Withdraw: 250
    // Expected: both succeed, final balance=650
    // Calculation: 500 + 400 = 900, then 900 - 250 = 650
    {
        BankAccount acc(500.0, 300.0);
        bool d1 = acc.deposit(400.0);
        bool w1 = acc.withdraw(250.0);
        cout << "Test 5: " << (d1 == true && w1 == true && acc.getBalance() == 650.0 ? "PASS" : "FAIL")
             << " (Deposit 400, withdraw 250)" << endl;
    }

    // Test Case 6: Reset daily limit
    // Initial: balance=1000, dailyLimit=400
    // Withdraw: 400 (limit reached)
    // Try withdraw: 100 (should fail)
    // Reset daily limit
    // Withdraw: 100 (should succeed now)
    // Final balance: 1000 - 400 - 100 = 500
    {
        BankAccount acc(1000.0, 400.0);
        bool w1 = acc.withdraw(400.0); // Success, daily total = 400
        bool w2 = acc.withdraw(100.0); // Fail, would exceed limit
        acc.resetDailyLimit();
        bool w3 = acc.withdraw(100.0); // Success after reset
        cout << "Test 6: " << (w1 == true && w2 == false && w3 == true && acc.getBalance() == 500.0 ? "PASS" : "FAIL")
             << " (Reset daily limit test)" << endl;
    }

    // Test Case 7: Exact daily limit
    // Initial: balance=1000, dailyLimit=500
    // Withdraw: 500 (exactly the limit)
    // Expected: success, balance=500
    {
        BankAccount acc(1000.0, 500.0);
        bool success = acc.withdraw(500.0);
        cout << "Test 7: " << (success == true && acc.getBalance() == 500.0 ? "PASS" : "FAIL")
             << " (Withdraw exactly daily limit)" << endl;
    }

    // Test Case 8: Multiple deposits
    // Initial: balance=100, dailyLimit=500
    // Deposit: 200, 300, 150
    // Expected: all succeed, final balance = 100 + 200 + 300 + 150 = 750
    {
        BankAccount acc(100.0, 500.0);
        bool d1 = acc.deposit(200.0);
        bool d2 = acc.deposit(300.0);
        bool d3 = acc.deposit(150.0);
        cout << "Test 8: " << (d1 && d2 && d3 && acc.getBalance() == 750.0 ? "PASS" : "FAIL")
             << " (Multiple deposits)" << endl;
    }
}

void testProblem4()
{
    cout << "\n=== Testing Problem 4: Temperature Monitor with Alert System ===" << endl;

    // Test Case 1: Basic readings without alert
    // Threshold: 100, Readings: 75, 85, 95
    // Min: 75, Max: 95, Current: 95
    // Average: (75 + 85 + 95) / 3 = 255 / 3 = 85.0
    // Alert: 95 <= 100, so false
    {
        TemperatureMonitor tm(100.0);
        tm.addReading(75.0);
        tm.addReading(85.0);
        tm.addReading(95.0);
        cout << "Test 1: " << (tm.getCurrentTemp() == 95.0 && tm.getMinTemp() == 75.0 && tm.getMaxTemp() == 95.0 && abs(tm.getAverage() - 85.0) < 0.01 && tm.isAlert() == false && tm.getTempCount() == 3 ? "PASS" : "FAIL")
             << " (Basic readings: 75, 85, 95)" << endl;
    }

    // Test Case 2: Reading triggers alert
    // Threshold: 100, Readings: 75, 105
    // Current: 105, Alert: 105 > 100, so true
    // Min: 75, Max: 105
    // Average: (75 + 105) / 2 = 180 / 2 = 90.0
    {
        TemperatureMonitor tm(100.0);
        tm.addReading(75.0);
        tm.addReading(105.0);
        cout << "Test 2: " << (tm.getCurrentTemp() == 105.0 && tm.isAlert() == true && tm.getMaxTemp() == 105.0 && abs(tm.getAverage() - 90.0) < 0.01 ? "PASS" : "FAIL")
             << " (Reading 105 triggers alert)" << endl;
    }

    // Test Case 3: Alert then no alert
    // Threshold: 100, Readings: 105, 95
    // After first: alert=true (105 > 100)
    // After second: alert=false (95 <= 100)
    // Min: 95, Max: 105, Current: 95
    // Average: (105 + 95) / 2 = 200 / 2 = 100.0
    {
        TemperatureMonitor tm(100.0);
        tm.addReading(105.0);
        tm.addReading(95.0);
        cout << "Test 3: " << (tm.getCurrentTemp() == 95.0 && tm.isAlert() == false && tm.getMaxTemp() == 105.0 && abs(tm.getAverage() - 100.0) < 0.01 ? "PASS" : "FAIL")
             << " (Alert cleared by lower reading)" << endl;
    }

    // Test Case 4: Single reading
    // Threshold: 80, Reading: 75
    // Min: 75, Max: 75, Current: 75
    // Average: 75 / 1 = 75.0
    // Alert: 75 <= 80, so false
    {
        TemperatureMonitor tm(80.0);
        tm.addReading(75.0);
        cout << "Test 4: " << (tm.getCurrentTemp() == 75.0 && tm.getMinTemp() == 75.0 && tm.getMaxTemp() == 75.0 && tm.getAverage() == 75.0 && tm.getTempCount() == 1 ? "PASS" : "FAIL")
             << " (Single reading)" << endl;
    }

    // Test Case 5: Exact threshold boundary
    // Threshold: 100, Reading: 100
    // Alert: 100 <= 100, so false (not greater than)
    {
        TemperatureMonitor tm(100.0);
        tm.addReading(100.0);
        cout << "Test 5: " << (tm.getCurrentTemp() == 100.0 && tm.isAlert() == false ? "PASS" : "FAIL")
             << " (Exact threshold, no alert)" << endl;
    }

    // Test Case 6: Reset statistics
    // Threshold: 100
    // Initial readings: 80, 90, 85 (avg = 85, count = 3)
    // Reset, then add: 70
    // After reset: count=1, current=70, min=70, max=70, avg=70
    {
        TemperatureMonitor tm(100.0);
        tm.addReading(80.0);
        tm.addReading(90.0);
        tm.addReading(85.0);
        tm.reset();
        tm.addReading(70.0);
        cout << "Test 6: " << (tm.getTempCount() == 1 && tm.getCurrentTemp() == 70.0 && tm.getMinTemp() == 70.0 && tm.getMaxTemp() == 70.0 && tm.getAverage() == 70.0 ? "PASS" : "FAIL")
             << " (Reset then new reading)" << endl;
    }

    // Test Case 7: Negative temperatures
    // Threshold: 0, Readings: -10, -5, -15, -8
    // Min: -15, Max: -5, Current: -8
    // Average: (-10 + -5 + -15 + -8) / 4 = -38 / 4 = -9.5
    // Alert: -8 <= 0, so false
    {
        TemperatureMonitor tm(0.0);
        tm.addReading(-10.0);
        tm.addReading(-5.0);
        tm.addReading(-15.0);
        tm.addReading(-8.0);
        cout << "Test 7: " << (tm.getMinTemp() == -15.0 && tm.getMaxTemp() == -5.0 && abs(tm.getAverage() - (-9.5)) < 0.01 && tm.isAlert() == false ? "PASS" : "FAIL")
             << " (Negative temperatures)" << endl;
    }

    // Test Case 8: Many readings
    // Threshold: 90, Readings: 70, 75, 80, 85, 95, 88
    // Min: 70, Max: 95, Current: 88
    // Sum: 70 + 75 + 80 + 85 + 95 + 88 = 493
    // Average: 493 / 6 = 82.166...
    // Alert: 88 <= 90, so false
    {
        TemperatureMonitor tm(90.0);
        tm.addReading(70.0);
        tm.addReading(75.0);
        tm.addReading(80.0);
        tm.addReading(85.0);
        tm.addReading(95.0);
        tm.addReading(88.0);
        cout << "Test 8: " << (tm.getCurrentTemp() == 88.0 && tm.getMinTemp() == 70.0 && tm.getMaxTemp() == 95.0 && abs(tm.getAverage() - 82.1667) < 0.01 && tm.getTempCount() == 6 && tm.isAlert() == false ? "PASS" : "FAIL")
             << " (Multiple readings with statistics)" << endl;
    }
}

int main()
{
    int choice;
    cout << "====================================" << endl;
    cout << "C++ Setters and Getters Practice" << endl;
    cout << "====================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Student Grade Manager" << endl;
    cout << "2. Problem 2 (Easy) - Rectangle Dimension Manager" << endl;
    cout << "3. Problem 3 (Medium) - Bank Account with Transaction Limits" << endl;
    cout << "4. Problem 4 (Hard) - Temperature Monitor with Alert System" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        testProblem1();
        break;
    case 2:
        testProblem2();
        break;
    case 3:
        testProblem3();
        break;
    case 4:
        testProblem4();
        break;
    case 5:
        testProblem1();
        testProblem2();
        testProblem3();
        testProblem4();
        break;
    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}