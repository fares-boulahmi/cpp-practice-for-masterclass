#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// ============================================================================
// Problem 1: Easy - Bank Account Manager
// ============================================================================
// Create a BankAccount class that manages a simple bank account.
// The class should have:
//   - Private members: accountNumber (int), balance (double)
//   - Public member functions:
//       * Constructor to initialize account
//       * deposit(double amount) - adds amount to balance
//       * withdraw(double amount) - subtracts amount if sufficient balance
//       * getBalance() - returns current balance
//       * getAccountNumber() - returns account number
//
// Input Format: Various operations on bank account
// Output Format: Balance after operations or account info
//
// Example 1:
//   Account(101, 1000.0) -> deposit(500.0) -> getBalance()
//   Output: 1500.0
//
// Example 2:
//   Account(102, 500.0) -> withdraw(200.0) -> getBalance()
//   Output: 300.0
//
// Constraints:
//   - Initial balance >= 0
//   - Withdraw only if sufficient balance (return false if insufficient)
//   - Account numbers are positive integers

class BankAccount
{
    // TODO: Implement your solution here
    // Hint: Use private data members for accountNumber and balance
    // Hint: Implement constructor and public member functions
private:
    int accountNumber{rand()};
    double balance{};

public:
    BankAccount(int id, double balance_amount)
    {

    }
    double deposit(double amount)
    {
        return 0;
    };
    double withdraw(double amount)
    {

        return 0;
    };
    double getBalance()
    {
        return 1;
    };
    int getAccountNumber()
    {
        return 0;
    };
};

// ============================================================================
// Problem 2: Easy-Medium - Rectangle Calculator
// ============================================================================
// Create a Rectangle class that represents a rectangle shape.
// The class should have:
//   - Private members: length (double), width (double)
//   - Public member functions:
//       * Constructor to initialize dimensions
//       * getArea() - returns area (length * width)
//       * getPerimeter() - returns perimeter (2 * (length + width))
//       * isSquare() - returns true if length == width
//       * scale(double factor) - multiplies both dimensions by factor
//       * getLength() and getWidth() - return respective values
//
// Input Format: Rectangle dimensions and operations
// Output Format: Calculated values
//
// Example 1:
//   Rectangle(5.0, 3.0) -> getArea()
//   Output: 15.0
//
// Example 2:
//   Rectangle(4.0, 4.0) -> isSquare()
//   Output: true
//
// Example 3:
//   Rectangle(10.0, 5.0) -> scale(2.0) -> getArea()
//   Output: 200.0 (new dimensions: 20.0 x 10.0)
//
// Constraints:
//   - Length and width must be positive
//   - Scale factor must be positive

class Rectangle
{
    // TODO: Implement your solution here
    // Hint: Store length and width as private members
    // Hint: Implement mathematical calculations for area and perimeter
public:
    Rectangle(double len, double wid)
    {

    }
    //* getArea() - returns area (length * width)
    double getArea()
    {
        return 0;
    };
    //       * getPerimeter() - returns perimeter (2 * (length + width))
    double getPerimeter()
    {
        return 0;
    };
    //       * isSquare() - returns true if length == width
    bool isSquare()
    {

        return false;
    }
    //       * scale(double factor) - multiplies both dimensions by factor
    double scale(double factor)
    {

        return 0;
    };
    //       * getLength() and getWidth() - return respective values
    double getLength()
    {
        return 0;
    };
    double getWidth()
    {
        return 0;
    };

private:
    double length{};
    double width{};
};

// ============================================================================
// Problem 3: Medium - Student Grade Manager
// ============================================================================
// Create a Student class that manages student information and grades.
// The class should have:
//   - Private members: name (string), studentId (int), grades (vector<int>)
//   - Public member functions:
//       * Constructor to initialize name and id (empty grades initially)
//       * addGrade(int grade) - adds a grade to the vector
//       * getAverage() - returns average of all grades (return 0 if no grades)
//       * getHighestGrade() - returns highest grade (return -1 if no grades)
//       * getLowestGrade() - returns lowest grade (return -1 if no grades)
//       * getGradeCount() - returns number of grades
//       * getName() and getStudentId() - return respective values
//       * getLetterGrade() - returns 'A' (90-100), 'B' (80-89), 'C' (70-79),
//                            'D' (60-69), 'F' (<60) based on average
//
// Input Format: Student info and grade operations
// Output Format: Calculated statistics
//
// Example 1:
//   Student("Alice", 1001) -> addGrade(85) -> addGrade(90) -> addGrade(78) -> getAverage()
//   Output: 84.33... (approximately 84)
//
// Example 2:
//   Student("Bob", 1002) -> addGrade(95) -> addGrade(88) -> getLetterGrade()
//   Output: 'B' (average is 91.5, rounds to 91... wait: (95+88)/2 = 91.5, that's A!)
//   Output: 'A'
//
// Constraints:
//   - Grades are integers between 0 and 100
//   - Student ID is positive integer
//   - Name is non-empty string

class Student
{
    // TODO: Implement your solution here
    // Hint: Use a vector to store multiple grades
    // Hint: You'll need to iterate through the vector for calculations
};

// ============================================================================
// Problem 4: Hard - Shopping Cart System
// ============================================================================
// Create two classes: Item and ShoppingCart
//
// Item class should have:
//   - Private members: name (string), price (double), quantity (int)
//   - Public member functions:
//       * Constructor to initialize all members
//       * getTotalPrice() - returns price * quantity
//       * getName(), getPrice(), getQuantity() - getters
//       * setQuantity(int q) - updates quantity
//
// ShoppingCart class should have:
//   - Private members: items (vector<Item>), customerName (string)
//   - Public member functions:
//       * Constructor to initialize customer name (empty cart initially)
//       * addItem(Item item) - adds item to cart
//       * getTotalCost() - returns sum of all item total prices
//       * getItemCount() - returns total number of items (sum of quantities)
//       * getMostExpensiveItem() - returns name of item with highest price per unit
//       * applyDiscount(double percent) - reduces all item prices by percent
//       * removeItem(string itemName) - removes item by name (return true if found)
//       * getCustomerName() - returns customer name
//
// Input Format: Cart operations with items
// Output Format: Calculated totals and information
//
// Example 1:
//   Cart("John") -> add Item("Apple", 1.5, 3) -> add Item("Banana", 0.5, 5) -> getTotalCost()
//   Calculation: (1.5 * 3) + (0.5 * 5) = 4.5 + 2.5 = 7.0
//   Output: 7.0
//
// Example 2:
//   Cart("Mary") -> add Item("Laptop", 999.99, 1) -> add Item("Mouse", 25.50, 2)
//   -> applyDiscount(10.0) -> getTotalCost()
//   Calculation: After 10% discount:
//     Laptop: 999.99 * 0.9 = 899.991
//     Mouse: 25.50 * 0.9 = 22.95
//     Total: (899.991 * 1) + (22.95 * 2) = 899.991 + 45.9 = 945.891
//   Output: 945.891
//
// Constraints:
//   - Item prices are positive
//   - Quantities are positive integers
//   - Discount percent is between 0 and 100

class Item
{
    // TODO: Implement your solution here
    // Hint: Simple class with three data members
};

class ShoppingCart
{
    // TODO: Implement your solution here
    // Hint: Store a vector of Item objects
    // Hint: Use loops to calculate totals and find items
};

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Bank Account Manager ===" << endl;

    // Test Case 1: Basic deposit
    // Initial: 1000.0, Deposit: 500.0
    // Expected: 1000.0 + 500.0 = 1500.0
    cout << "Test 1 (Basic Deposit): ";
    BankAccount acc1(101, 1000.0);
    acc1.deposit(500.0);
    cout << (acc1.getBalance() == 1500.0 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Basic withdrawal
    // Initial: 500.0, Withdraw: 200.0
    // Expected: 500.0 - 200.0 = 300.0
    cout << "Test 2 (Basic Withdrawal): ";
    BankAccount acc2(102, 500.0);
    acc2.withdraw(200.0);
    cout << (acc2.getBalance() == 300.0 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Multiple operations
    // Initial: 1000.0, Deposit: 250.0, Withdraw: 100.0, Deposit: 50.0
    // Expected: 1000.0 + 250.0 - 100.0 + 50.0 = 1200.0
    cout << "Test 3 (Multiple Operations): ";
    BankAccount acc3(103, 1000.0);
    acc3.deposit(250.0);
    acc3.withdraw(100.0);
    acc3.deposit(50.0);
    cout << (acc3.getBalance() == 1200.0 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Zero initial balance
    // Initial: 0.0, Deposit: 100.0
    // Expected: 0.0 + 100.0 = 100.0
    cout << "Test 4 (Zero Initial Balance): ";
    BankAccount acc4(104, 0.0);
    acc4.deposit(100.0);
    cout << (acc4.getBalance() == 100.0 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Exact balance withdrawal
    // Initial: 750.0, Withdraw: 750.0
    // Expected: 750.0 - 750.0 = 0.0
    cout << "Test 5 (Exact Balance Withdrawal): ";
    BankAccount acc5(105, 750.0);
    acc5.withdraw(750.0);
    cout << (acc5.getBalance() == 0.0 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Account number verification
    // Account: 999
    // Expected: 999
    cout << "Test 6 (Account Number): ";
    BankAccount acc6(999, 500.0);
    cout << (acc6.getAccountNumber() == 999 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Large amount operations
    // Initial: 10000.0, Deposit: 5000.0, Withdraw: 3000.0
    // Expected: 10000.0 + 5000.0 - 3000.0 = 12000.0
    cout << "Test 7 (Large Amounts): ";
    BankAccount acc7(107, 10000.0);
    acc7.deposit(5000.0);
    acc7.withdraw(3000.0);
    cout << (acc7.getBalance() == 12000.0 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Decimal precision
    // Initial: 100.50, Deposit: 50.75, Withdraw: 25.25
    // Expected: 100.50 + 50.75 - 25.25 = 126.0
    cout << "Test 8 (Decimal Precision): ";
    BankAccount acc8(108, 100.50);
    acc8.deposit(50.75);
    acc8.withdraw(25.25);
    cout << (acc8.getBalance() == 126.0 ? "PASS" : "FAIL") << endl;
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Rectangle Calculator ===" << endl;

    // Test Case 1: Basic area calculation
    // Dimensions: 5.0 x 3.0
    // Expected Area: 5.0 * 3.0 = 15.0
    cout << "Test 1 (Basic Area): ";
    Rectangle rect1(5.0, 3.0);
    cout << (rect1.getArea() == 15.0 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Perimeter calculation
    // Dimensions: 4.0 x 6.0
    // Expected Perimeter: 2 * (4.0 + 6.0) = 2 * 10.0 = 20.0
    cout << "Test 2 (Perimeter): ";
    Rectangle rect2(4.0, 6.0);
    cout << (rect2.getPerimeter() == 20.0 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Square detection (true)
    // Dimensions: 4.0 x 4.0
    // Expected: true
    cout << "Test 3 (Is Square - True): ";
    Rectangle rect3(4.0, 4.0);
    cout << (rect3.isSquare() == true ? "PASS" : "FAIL") << endl;

    // Test Case 4: Square detection (false)
    // Dimensions: 5.0 x 3.0
    // Expected: false
    cout << "Test 4 (Is Square - False): ";
    Rectangle rect4(5.0, 3.0);
    cout << (rect4.isSquare() == false ? "PASS" : "FAIL") << endl;

    // Test Case 5: Scale operation
    // Original: 10.0 x 5.0, Scale: 2.0
    // New dimensions: 20.0 x 10.0
    // Expected Area: 20.0 * 10.0 = 200.0
    cout << "Test 5 (Scale Area): ";
    Rectangle rect5(10.0, 5.0);
    rect5.scale(2.0);
    cout << (rect5.getArea() == 200.0 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Scale with decimals
    // Original: 8.0 x 4.0, Scale: 0.5
    // New dimensions: 4.0 x 2.0
    // Expected Perimeter: 2 * (4.0 + 2.0) = 2 * 6.0 = 12.0
    cout << "Test 6 (Scale Perimeter): ";
    Rectangle rect6(8.0, 4.0);
    rect6.scale(0.5);
    cout << (rect6.getPerimeter() == 12.0 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Unit square
    // Dimensions: 1.0 x 1.0
    // Expected Area: 1.0 * 1.0 = 1.0
    cout << "Test 7 (Unit Square Area): ";
    Rectangle rect7(1.0, 1.0);
    cout << (rect7.getArea() == 1.0 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Large rectangle
    // Dimensions: 100.0 x 50.0
    // Expected Perimeter: 2 * (100.0 + 50.0) = 2 * 150.0 = 300.0
    cout << "Test 8 (Large Rectangle Perimeter): ";
    Rectangle rect8(100.0, 50.0);
    cout << (rect8.getPerimeter() == 300.0 ? "PASS" : "FAIL") << endl;
}

/* void testProblem3()
{
    cout << "\n=== Testing Problem 3: Student Grade Manager ===" << endl;

    // Test Case 1: Average calculation with 3 grades
    // Grades: 85, 90, 78
    // Expected Average: (85 + 90 + 78) / 3 = 253 / 3 = 84.333...
    cout << "Test 1 (Average of 3 grades): ";
    Student student1("Alice", 1001);
    student1.addGrade(85);
    student1.addGrade(90);
    student1.addGrade(78);
    double avg1 = student1.getAverage();
    cout << (abs(avg1 - 84.333333) < 0.01 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Letter grade 'A'
    // Grades: 95, 88
    // Average: (95 + 88) / 2 = 183 / 2 = 91.5
    // Expected Letter: 'A' (90-100)
    cout << "Test 2 (Letter Grade A): ";
    Student student2("Bob", 1002);
    student2.addGrade(95);
    student2.addGrade(88);
    cout << (student2.getLetterGrade() == 'A' ? "PASS" : "FAIL") << endl;

    // Test Case 3: Highest grade
    // Grades: 70, 85, 92, 78
    // Expected Highest: 92
    cout << "Test 3 (Highest Grade): ";
    Student student3("Charlie", 1003);
    student3.addGrade(70);
    student3.addGrade(85);
    student3.addGrade(92);
    student3.addGrade(78);
    cout << (student3.getHighestGrade() == 92 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Lowest grade
    // Grades: 88, 75, 92, 81
    // Expected Lowest: 75
    cout << "Test 4 (Lowest Grade): ";
    Student student4("Diana", 1004);
    student4.addGrade(88);
    student4.addGrade(75);
    student4.addGrade(92);
    student4.addGrade(81);
    cout << (student4.getLowestGrade() == 75 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Letter grade 'B'
    // Grades: 82, 87, 85
    // Average: (82 + 87 + 85) / 3 = 254 / 3 = 84.666...
    // Expected Letter: 'B' (80-89)
    cout << "Test 5 (Letter Grade B): ";
    Student student5("Eve", 1005);
    student5.addGrade(82);
    student5.addGrade(87);
    student5.addGrade(85);
    cout << (student5.getLetterGrade() == 'B' ? "PASS" : "FAIL") << endl;

    // Test Case 6: Grade count
    // Grades: 90, 85, 88, 92, 87
    // Expected Count: 5
    cout << "Test 6 (Grade Count): ";
    Student student6("Frank", 1006);
    student6.addGrade(90);
    student6.addGrade(85);
    student6.addGrade(88);
    student6.addGrade(92);
    student6.addGrade(87);
    cout << (student6.getGradeCount() == 5 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Letter grade 'C'
    // Grades: 72, 78, 75
    // Average: (72 + 78 + 75) / 3 = 225 / 3 = 75.0
    // Expected Letter: 'C' (70-79)
    cout << "Test 7 (Letter Grade C): ";
    Student student7("Grace", 1007);
    student7.addGrade(72);
    student7.addGrade(78);
    student7.addGrade(75);
    cout << (student7.getLetterGrade() == 'C' ? "PASS" : "FAIL") << endl;

    // Test Case 8: Perfect scores
    // Grades: 100, 100, 100
    // Average: 100.0
    // Expected Letter: 'A'
    cout << "Test 8 (Perfect Scores): ";
    Student student8("Henry", 1008);
    student8.addGrade(100);
    student8.addGrade(100);
    student8.addGrade(100);
    cout << (student8.getAverage() == 100.0 && student8.getLetterGrade() == 'A' ? "PASS" : "FAIL") << endl;
} */

/* void testProblem4()
{
    cout << "\n=== Testing Problem 4: Shopping Cart System ===" << endl;

    // Test Case 1: Basic total cost
    // Items: Apple (1.5, 3), Banana (0.5, 5)
    // Expected: (1.5 * 3) + (0.5 * 5) = 4.5 + 2.5 = 7.0
    cout << "Test 1 (Basic Total Cost): ";
    ShoppingCart cart1("John");
    Item apple("Apple", 1.5, 3);
    Item banana("Banana", 0.5, 5);
    cart1.addItem(apple);
    cart1.addItem(banana);
    cout << (abs(cart1.getTotalCost() - 7.0) < 0.01 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Item count (total quantity)
    // Items: Apple (1.5, 3), Banana (0.5, 5)
    // Expected: 3 + 5 = 8
    cout << "Test 2 (Item Count): ";
    ShoppingCart cart2("Mary");
    Item apple2("Apple", 1.5, 3);
    Item banana2("Banana", 0.5, 5);
    cart2.addItem(apple2);
    cart2.addItem(banana2);
    cout << (cart2.getItemCount() == 8 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Discount application
    // Items: Laptop (999.99, 1), Mouse (25.50, 2)
    // After 10% discount:
    //   Laptop: 999.99 * 0.9 = 899.991
    //   Mouse: 25.50 * 0.9 = 22.95
    // Expected Total: (899.991 * 1) + (22.95 * 2) = 899.991 + 45.9 = 945.891
    cout << "Test 3 (Discount Application): ";
    ShoppingCart cart3("Peter");
    Item laptop("Laptop", 999.99, 1);
    Item mouse("Mouse", 25.50, 2);
    cart3.addItem(laptop);
    cart3.addItem(mouse);
    cart3.applyDiscount(10.0);
    cout << (abs(cart3.getTotalCost() - 945.891) < 0.01 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Most expensive item
    // Items: Bread (2.5, 2), Milk (3.0, 1), Cheese (5.5, 1)
    // Expected: "Cheese" (highest unit price is 5.5)
    cout << "Test 4 (Most Expensive Item): ";
    ShoppingCart cart4("Lisa");
    Item bread("Bread", 2.5, 2);
    Item milk("Milk", 3.0, 1);
    Item cheese("Cheese", 5.5, 1);
    cart4.addItem(bread);
    cart4.addItem(milk);
    cart4.addItem(cheese);
    cout << (cart4.getMostExpensiveItem() == "Cheese" ? "PASS" : "FAIL") << endl;

    // Test Case 5: Single item total
    // Item: Book (15.99, 4)
    // Expected: 15.99 * 4 = 63.96
    cout << "Test 5 (Single Item Total): ";
    ShoppingCart cart5("Tom");
    Item book("Book", 15.99, 4);
    cart5.addItem(book);
    cout << (abs(cart5.getTotalCost() - 63.96) < 0.01 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Multiple same-priced items
    // Items: Pen (1.0, 5), Pencil (1.0, 3), Eraser (1.0, 2)
    // Expected Total: (1.0 * 5) + (1.0 * 3) + (1.0 * 2) = 5 + 3 + 2 = 10.0
    cout << "Test 6 (Same-Priced Items): ";
    ShoppingCart cart6("Anna");
    Item pen("Pen", 1.0, 5);
    Item pencil("Pencil", 1.0, 3);
    Item eraser("Eraser", 1.0, 2);
    cart6.addItem(pen);
    cart6.addItem(pencil);
    cart6.addItem(eraser);
    cout << (abs(cart6.getTotalCost() - 10.0) < 0.01 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Large quantity
    // Item: Widget (0.25, 100)
    // Expected: 0.25 * 100 = 25.0
    cout << "Test 7 (Large Quantity): ";
    ShoppingCart cart7("Bob");
    Item widget("Widget", 0.25, 100);
    cart7.addItem(widget);
    cout << (abs(cart7.getTotalCost() - 25.0) < 0.01 ? "PASS" : "FAIL") << endl;

    // Test Case 8: Customer name verification
    // Customer: "Sarah"
    // Expected: "Sarah"
    cout << "Test 8 (Customer Name): ";
    ShoppingCart cart8("Sarah");
    cout << (cart8.getCustomerName() == "Sarah" ? "PASS" : "FAIL") << endl;
}
 */
// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main()
{
    int choice;
    cout << "==================================================" << endl;
    cout << "      C++ Classes Practice Problems" << endl;
    cout << "==================================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy): Bank Account Manager" << endl;
    cout << "2. Problem 2 (Easy-Medium): Rectangle Calculator" << endl;
    cout << "3. Problem 3 (Medium): Student Grade Manager" << endl;
    cout << "4. Problem 4 (Hard): Shopping Cart System" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "==================================================" << endl;
    cout << "Enter your choice: ";
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
        // testProblem3();
        break;
    case 4:
        // testProblem4();
        break;
    case 5:
        testProblem1();
        testProblem2();
        // testProblem3();
        // testProblem4();
        break;
    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}