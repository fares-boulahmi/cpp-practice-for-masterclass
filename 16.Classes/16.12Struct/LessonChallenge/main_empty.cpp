#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Student Grade Calculator
// ============================================================================
// Description:
// Create a program that manages student information. Each student has a name,
// three test scores, and you need to calculate their average score.
//
// Input Format:
// - Student name (string)
// - Three integer test scores (0-100)
//
// Output Format:
// - Return the average score as a double (rounded to 2 decimal places in tests)
//
// Example 1:
// Input: name = "Alice", score1 = 85, score2 = 90, score3 = 78
// Output: 84.33
// Explanation: (85 + 90 + 78) / 3 = 253 / 3 = 84.333...
//
// Example 2:
// Input: name = "Bob", score1 = 100, score2 = 100, score3 = 100
// Output: 100.00
// Explanation: Perfect scores average to 100
//
// Constraints:
// - Name length: 1-50 characters
// - Each score: 0-100
//
// Hint: Define a Student struct with name and three score members.
// Calculate the sum and divide by 3.0 for floating-point division.

struct Student
{
    string name;
    int score1;
    int score2;
    int score3;
};

double problem1Solution(Student student)
{
    // TODO: Implement your solution here using struct
    // Hint: Add the three scores and divide by 3.0
}

// ============================================================================
// Problem 2: Easy 2 - Rectangle Area and Perimeter
// ============================================================================
// Description:
// Create a program that works with rectangles. Each rectangle has a width
// and height. Calculate BOTH the area and perimeter, and return them in a
// Result struct.
//
// Input Format:
// - Rectangle with width and height (positive integers)
//
// Output Format:
// - Result struct containing area and perimeter (both integers)
//
// Example 1:
// Input: width = 5, height = 3
// Output: area = 15, perimeter = 16
// Explanation:
//   Area = width × height = 5 × 3 = 15
//   Perimeter = 2 × (width + height) = 2 × (5 + 3) = 2 × 8 = 16
//
// Example 2:
// Input: width = 10, height = 10
// Output: area = 100, perimeter = 40
// Explanation: Square with side 10
//   Area = 10 × 10 = 100
//   Perimeter = 2 × (10 + 10) = 40
//
// Example 3:
// Input: width = 1, height = 1
// Output: area = 1, perimeter = 4
// Explanation: Smallest rectangle
//
// Constraints:
// - width: 1-1000
// - height: 1-1000
//
// Hint: Define Rectangle and Result structs. Use basic arithmetic operations.

struct Rectangle
{
    int width;
    int height;
};

struct Result
{
    int area;
    int perimeter;
};

Result problem2Solution(Rectangle rect)
{
    // TODO: Implement your solution here using struct
    // Hint: area = width * height, perimeter = 2 * (width + height)
}

// ============================================================================
// Problem 3: Medium - Find Closest Point to Origin
// ============================================================================
// Description:
// Given a vector of 2D points, find which point is closest to the origin (0,0).
// Distance from origin is calculated using: sqrt(x² + y²)
// However, you can compare squared distances to avoid floating-point: x² + y²
//
// Input Format:
// - Vector of Point structs, each with x and y coordinates (integers)
//
// Output Format:
// - Return the Point that is closest to origin
// - If multiple points have same distance, return the first one
//
// Example 1:
// Input: points = [(3,4), (1,1), (5,0)]
// Output: (1,1)
// Explanation:
//   Point (3,4): distance² = 3² + 4² = 9 + 16 = 25
//   Point (1,1): distance² = 1² + 1² = 1 + 1 = 2
//   Point (5,0): distance² = 5² + 0² = 25 + 0 = 25
//   Minimum is 2, so return (1,1)
//
// Example 2:
// Input: points = [(0,5), (3,4), (-3,-4)]
// Output: (0,5)
// Explanation:
//   Point (0,5): distance² = 0² + 5² = 0 + 25 = 25
//   Point (3,4): distance² = 3² + 4² = 9 + 16 = 25
//   Point (-3,-4): distance² = (-3)² + (-4)² = 9 + 16 = 25
//   All equal, return first: (0,5)
//
// Constraints:
// - Vector size: 1-1000
// - Coordinates: -1000 to 1000
// - At least one point always provided
//
// Hint: Loop through vector, calculate squared distance for each point,
// keep track of minimum distance and corresponding point.

struct Point
{
    int x;
    int y;
};

Point problem3Solution(vector<Point> points)
{
    // TODO: Implement your solution here using struct
    // Hint: Calculate x*x + y*y for each point, track the minimum
}

// ============================================================================
// Problem 4: Hard - Book Library Management System
// ============================================================================
// Description:
// Create a library system that manages books and tracks which books are
// available. Each book has: title, author, year, and availability status.
// Implement a function that:
// 1. Finds all available books by a specific author
// 2. Returns them sorted by year (oldest first)
//
// Input Format:
// - Vector of Book structs
// - Author name to search for (exact match, case-sensitive)
//
// Output Format:
// - Vector of available books by that author, sorted by year (ascending)
//
// Example 1:
// Input:
//   Books = [
//     {"1984", "Orwell", 1949, true},
//     {"Animal Farm", "Orwell", 1945, true},
//     {"Brave New World", "Huxley", 1932, true},
//     {"Homage to Catalonia", "Orwell", 1938, false}
//   ]
//   Author = "Orwell"
// Output: [{"Animal Farm", "Orwell", 1945, true}, {"1984", "Orwell", 1949, true}]
// Explanation:
//   - "Homage to Catalonia" is NOT available (false), so excluded
//   - "Animal Farm" (1945) comes before "1984" (1949)
//
// Example 2:
// Input:
//   Books = [{"Book A", "Smith", 2000, false}, {"Book B", "Jones", 1995, true}]
//   Author = "Smith"
// Output: []
// Explanation: Smith's only book is not available
//
// Constraints:
// - Number of books: 0-1000
// - Title/Author length: 1-100 characters
// - Year: 1000-2024
// - Author search is case-sensitive exact match
//
// Hint: Use a loop to filter books by author and availability.
// Store matching books in a result vector. Use nested loops or
// simple sorting logic to arrange by year.

struct Book
{
    string title;
    string author;
    int year;
    bool isAvailable;
};

vector<Book> problem4Solution(vector<Book> books, string author)
{
    // TODO: Implement your solution here using struct
    // Hint: Filter by author and isAvailable, then sort by year
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Student Grade Calculator ===" << endl;

    // Test Case 1: Normal case with decimal result
    // Calculation: (85 + 90 + 78) / 3 = 253 / 3 = 84.333...
    Student s1 = {"Alice", 85, 90, 78};
    double result1 = problem1Solution(s1);
    cout << "Test 1 - Normal grades: " << fixed << setprecision(2);
    cout << (abs(result1 - 84.33) < 0.01 ? "PASS" : "FAIL") << " (Expected: 84.33, Got: " << result1 << ")" << endl;

    // Test Case 2: Perfect scores
    // Calculation: (100 + 100 + 100) / 3 = 300 / 3 = 100.00
    Student s2 = {"Bob", 100, 100, 100};
    double result2 = problem1Solution(s2);
    cout << "Test 2 - Perfect scores: ";
    cout << (abs(result2 - 100.00) < 0.01 ? "PASS" : "FAIL") << " (Expected: 100.00, Got: " << result2 << ")" << endl;

    // Test Case 3: Zero scores
    // Calculation: (0 + 0 + 0) / 3 = 0 / 3 = 0.00
    Student s3 = {"Charlie", 0, 0, 0};
    double result3 = problem1Solution(s3);
    cout << "Test 3 - All zeros: ";
    cout << (abs(result3 - 0.00) < 0.01 ? "PASS" : "FAIL") << " (Expected: 0.00, Got: " << result3 << ")" << endl;

    // Test Case 4: Mixed scores
    // Calculation: (50 + 75 + 25) / 3 = 150 / 3 = 50.00
    Student s4 = {"Diana", 50, 75, 25};
    double result4 = problem1Solution(s4);
    cout << "Test 4 - Mixed scores: ";
    cout << (abs(result4 - 50.00) < 0.01 ? "PASS" : "FAIL") << " (Expected: 50.00, Got: " << result4 << ")" << endl;

    // Test Case 5: Close scores
    // Calculation: (88 + 89 + 87) / 3 = 264 / 3 = 88.00
    Student s5 = {"Eve", 88, 89, 87};
    double result5 = problem1Solution(s5);
    cout << "Test 5 - Close scores: ";
    cout << (abs(result5 - 88.00) < 0.01 ? "PASS" : "FAIL") << " (Expected: 88.00, Got: " << result5 << ")" << endl;

    // Test Case 6: Wide range
    // Calculation: (10 + 50 + 90) / 3 = 150 / 3 = 50.00
    Student s6 = {"Frank", 10, 50, 90};
    double result6 = problem1Solution(s6);
    cout << "Test 6 - Wide range: ";
    cout << (abs(result6 - 50.00) < 0.01 ? "PASS" : "FAIL") << " (Expected: 50.00, Got: " << result6 << ")" << endl;

    // Test Case 7: Decimal result
    // Calculation: (70 + 80 + 85) / 3 = 235 / 3 = 78.333...
    Student s7 = {"Grace", 70, 80, 85};
    double result7 = problem1Solution(s7);
    cout << "Test 7 - Another decimal: ";
    cout << (abs(result7 - 78.33) < 0.01 ? "PASS" : "FAIL") << " (Expected: 78.33, Got: " << result7 << ")" << endl;

    // Test Case 8: All same scores
    // Calculation: (75 + 75 + 75) / 3 = 225 / 3 = 75.00
    Student s8 = {"Henry", 75, 75, 75};
    double result8 = problem1Solution(s8);
    cout << "Test 8 - All same: ";
    cout << (abs(result8 - 75.00) < 0.01 ? "PASS" : "FAIL") << " (Expected: 75.00, Got: " << result8 << ")" << endl;
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Rectangle Area and Perimeter ===" << endl;

    // Test Case 1: Normal rectangle
    // Area = 5 * 3 = 15
    // Perimeter = 2 * (5 + 3) = 2 * 8 = 16
    Rectangle r1 = {5, 3};
    Result res1 = problem2Solution(r1);
    cout << "Test 1 - 5x3 rectangle: ";
    cout << (res1.area == 15 && res1.perimeter == 16 ? "PASS" : "FAIL");
    cout << " (Expected: area=15, perimeter=16; Got: area=" << res1.area << ", perimeter=" << res1.perimeter << ")" << endl;

    // Test Case 2: Square
    // Area = 10 * 10 = 100
    // Perimeter = 2 * (10 + 10) = 2 * 20 = 40
    Rectangle r2 = {10, 10};
    Result res2 = problem2Solution(r2);
    cout << "Test 2 - 10x10 square: ";
    cout << (res2.area == 100 && res2.perimeter == 40 ? "PASS" : "FAIL");
    cout << " (Expected: area=100, perimeter=40; Got: area=" << res2.area << ", perimeter=" << res2.perimeter << ")" << endl;

    // Test Case 3: Minimum size
    // Area = 1 * 1 = 1
    // Perimeter = 2 * (1 + 1) = 2 * 2 = 4
    Rectangle r3 = {1, 1};
    Result res3 = problem2Solution(r3);
    cout << "Test 3 - 1x1 minimum: ";
    cout << (res3.area == 1 && res3.perimeter == 4 ? "PASS" : "FAIL");
    cout << " (Expected: area=1, perimeter=4; Got: area=" << res3.area << ", perimeter=" << res3.perimeter << ")" << endl;

    // Test Case 4: Very wide rectangle
    // Area = 100 * 1 = 100
    // Perimeter = 2 * (100 + 1) = 2 * 101 = 202
    Rectangle r4 = {100, 1};
    Result res4 = problem2Solution(r4);
    cout << "Test 4 - 100x1 wide: ";
    cout << (res4.area == 100 && res4.perimeter == 202 ? "PASS" : "FAIL");
    cout << " (Expected: area=100, perimeter=202; Got: area=" << res4.area << ", perimeter=" << res4.perimeter << ")" << endl;

    // Test Case 5: Very tall rectangle
    // Area = 1 * 50 = 50
    // Perimeter = 2 * (1 + 50) = 2 * 51 = 102
    Rectangle r5 = {1, 50};
    Result res5 = problem2Solution(r5);
    cout << "Test 5 - 1x50 tall: ";
    cout << (res5.area == 50 && res5.perimeter == 102 ? "PASS" : "FAIL");
    cout << " (Expected: area=50, perimeter=102; Got: area=" << res5.area << ", perimeter=" << res5.perimeter << ")" << endl;

    // Test Case 6: Medium rectangle
    // Area = 7 * 4 = 28
    // Perimeter = 2 * (7 + 4) = 2 * 11 = 22
    Rectangle r6 = {7, 4};
    Result res6 = problem2Solution(r6);
    cout << "Test 6 - 7x4 medium: ";
    cout << (res6.area == 28 && res6.perimeter == 22 ? "PASS" : "FAIL");
    cout << " (Expected: area=28, perimeter=22; Got: area=" << res6.area << ", perimeter=" << res6.perimeter << ")" << endl;

    // Test Case 7: Larger square
    // Area = 20 * 20 = 400
    // Perimeter = 2 * (20 + 20) = 2 * 40 = 80
    Rectangle r7 = {20, 20};
    Result res7 = problem2Solution(r7);
    cout << "Test 7 - 20x20 square: ";
    cout << (res7.area == 400 && res7.perimeter == 80 ? "PASS" : "FAIL");
    cout << " (Expected: area=400, perimeter=80; Got: area=" << res7.area << ", perimeter=" << res7.perimeter << ")" << endl;

    // Test Case 8: Different dimensions
    // Area = 15 * 8 = 120
    // Perimeter = 2 * (15 + 8) = 2 * 23 = 46
    Rectangle r8 = {15, 8};
    Result res8 = problem2Solution(r8);
    cout << "Test 8 - 15x8 rectangle: ";
    cout << (res8.area == 120 && res8.perimeter == 46 ? "PASS" : "FAIL");
    cout << " (Expected: area=120, perimeter=46; Got: area=" << res8.area << ", perimeter=" << res8.perimeter << ")" << endl;
}

void testProblem3()
{
    cout << "\n=== Testing Problem 3: Find Closest Point to Origin ===" << endl;

    // Test Case 1: Clear closest point
    // (3,4): 3² + 4² = 9 + 16 = 25
    // (1,1): 1² + 1² = 1 + 1 = 2 ← minimum
    // (5,0): 5² + 0² = 25 + 0 = 25
    vector<Point> points1 = {{3, 4}, {1, 1}, {5, 0}};
    Point res1 = problem3Solution(points1);
    cout << "Test 1 - Clear winner: ";
    cout << (res1.x == 1 && res1.y == 1 ? "PASS" : "FAIL");
    cout << " (Expected: (1,1), Got: (" << res1.x << "," << res1.y << "))" << endl;

    // Test Case 2: All equal distance (return first)
    // (0,5): 0² + 5² = 0 + 25 = 25 ← first, return this
    // (3,4): 3² + 4² = 9 + 16 = 25
    // (-3,-4): (-3)² + (-4)² = 9 + 16 = 25
    vector<Point> points2 = {{0, 5}, {3, 4}, {-3, -4}};
    Point res2 = problem3Solution(points2);
    cout << "Test 2 - All equal: ";
    cout << (res2.x == 0 && res2.y == 5 ? "PASS" : "FAIL");
    cout << " (Expected: (0,5), Got: (" << res2.x << "," << res2.y << "))" << endl;

    // Test Case 3: Single point
    // (7,24): 7² + 24² = 49 + 576 = 625
    vector<Point> points3 = {{7, 24}};
    Point res3 = problem3Solution(points3);
    cout << "Test 3 - Single point: ";
    cout << (res3.x == 7 && res3.y == 24 ? "PASS" : "FAIL");
    cout << " (Expected: (7,24), Got: (" << res3.x << "," << res3.y << "))" << endl;

    // Test Case 4: Negative coordinates
    // (-1,-1): (-1)² + (-1)² = 1 + 1 = 2 ← minimum
    // (2,2): 2² + 2² = 4 + 4 = 8
    // (-3,0): (-3)² + 0² = 9 + 0 = 9
    vector<Point> points4 = {{-1, -1}, {2, 2}, {-3, 0}};
    Point res4 = problem3Solution(points4);
    cout << "Test 4 - Negative coords: ";
    cout << (res4.x == -1 && res4.y == -1 ? "PASS" : "FAIL");
    cout << " (Expected: (-1,-1), Got: (" << res4.x << "," << res4.y << "))" << endl;

    // Test Case 5: Point on axis
    // (0,3): 0² + 3² = 0 + 9 = 9
    // (4,0): 4² + 0² = 16 + 0 = 16
    // (2,2): 2² + 2² = 4 + 4 = 8 ← minimum
    vector<Point> points5 = {{0, 3}, {4, 0}, {2, 2}};
    Point res5 = problem3Solution(points5);
    cout << "Test 5 - On axis: ";
    cout << (res5.x == 2 && res5.y == 2 ? "PASS" : "FAIL");
    cout << " (Expected: (2,2), Got: (" << res5.x << "," << res5.y << "))" << endl;

    // Test Case 6: Large coordinates
    // (100,100): 100² + 100² = 10000 + 10000 = 20000
    // (50,50): 50² + 50² = 2500 + 2500 = 5000 ← minimum
    // (150,0): 150² + 0² = 22500 + 0 = 22500
    vector<Point> points6 = {{100, 100}, {50, 50}, {150, 0}};
    Point res6 = problem3Solution(points6);
    cout << "Test 6 - Large coords: ";
    cout << (res6.x == 50 && res6.y == 50 ? "PASS" : "FAIL");
    cout << " (Expected: (50,50), Got: (" << res6.x << "," << res6.y << "))" << endl;

    // Test Case 7: Zero in coordinates
    // (0,0): 0² + 0² = 0 + 0 = 0 ← minimum (origin itself!)
    // (1,1): 1² + 1² = 1 + 1 = 2
    // (5,5): 5² + 5² = 25 + 25 = 50
    vector<Point> points7 = {{0, 0}, {1, 1}, {5, 5}};
    Point res7 = problem3Solution(points7);
    cout << "Test 7 - Origin included: ";
    cout << (res7.x == 0 && res7.y == 0 ? "PASS" : "FAIL");
    cout << " (Expected: (0,0), Got: (" << res7.x << "," << res7.y << "))" << endl;

    // Test Case 8: Mixed positive/negative
    // (6,8): 6² + 8² = 36 + 64 = 100
    // (-6,8): (-6)² + 8² = 36 + 64 = 100
    // (0,9): 0² + 9² = 0 + 81 = 81 ← minimum
    vector<Point> points8 = {{6, 8}, {-6, 8}, {0, 9}};
    Point res8 = problem3Solution(points8);
    cout << "Test 8 - Mixed signs: ";
    cout << (res8.x == 0 && res8.y == 9 ? "PASS" : "FAIL");
    cout << " (Expected: (0,9), Got: (" << res8.x << "," << res8.y << "))" << endl;
}

void testProblem4()
{
    cout << "\n=== Testing Problem 4: Book Library Management ===" << endl;

    // Test Case 1: Multiple books, some unavailable
    // Orwell books: Animal Farm (1945, available), Homage (1938, NOT available), 1984 (1949, available)
    // Expected: Animal Farm (1945) then 1984 (1949) - sorted by year
    vector<Book> books1 = {
        {"1984", "Orwell", 1949, true},
        {"Animal Farm", "Orwell", 1945, true},
        {"Brave New World", "Huxley", 1932, true},
        {"Homage to Catalonia", "Orwell", 1938, false}};
    vector<Book> res1 = problem4Solution(books1, "Orwell");
    cout << "Test 1 - Filter and sort: ";
    bool pass1 = (res1.size() == 2 &&
                  res1[0].title == "Animal Farm" && res1[0].year == 1945 &&
                  res1[1].title == "1984" && res1[1].year == 1949);
    cout << (pass1 ? "PASS" : "FAIL");
    cout << " (Expected: 2 books [Animal Farm(1945), 1984(1949)], Got: " << res1.size() << " books)" << endl;

    // Test Case 2: No available books by author
    // Smith has 1 book but it's not available
    vector<Book> books2 = {
        {"Book A", "Smith", 2000, false},
        {"Book B", "Jones", 1995, true}};
    vector<Book> res2 = problem4Solution(books2, "Smith");
    cout << "Test 2 - No available: ";
    cout << (res2.size() == 0 ? "PASS" : "FAIL");
    cout << " (Expected: 0 books, Got: " << res2.size() << " books)" << endl;

    // Test Case 3: Author not found
    // No books by "Unknown"
    vector<Book> books3 = {
        {"Book X", "Author1", 2000, true},
        {"Book Y", "Author2", 2005, true}};
    vector<Book> res3 = problem4Solution(books3, "Unknown");
    cout << "Test 3 - Author not found: ";
    cout << (res3.size() == 0 ? "PASS" : "FAIL");
    cout << " (Expected: 0 books, Got: " << res3.size() << " books)" << endl;

    // Test Case 4: All books available, need sorting
    // Johnson: Book C (2010), Book A (2005), Book B (2008)
    // Expected sorted: Book A (2005), Book B (2008), Book C (2010)
    vector<Book> books4 = {
        {"Book C", "Johnson", 2010, true},
        {"Book A", "Johnson", 2005, true},
        {"Book B", "Johnson", 2008, true}};
    vector<Book> res4 = problem4Solution(books4, "Johnson");
    cout << "Test 4 - Sort order: ";
    bool pass4 = (res4.size() == 3 &&
                  res4[0].title == "Book A" && res4[0].year == 2005 &&
                  res4[1].title == "Book B" && res4[1].year == 2008 &&
                  res4[2].title == "Book C" && res4[2].year == 2010);
    cout << (pass4 ? "PASS" : "FAIL");
    cout << " (Expected: 3 books in order 2005,2008,2010)" << endl;

    // Test Case 5: Single available book
    // Williams has 1 available book
    vector<Book> books5 = {
        {"Solo Book", "Williams", 2020, true},
        {"Other Book", "Other", 2015, true}};
    vector<Book> res5 = problem4Solution(books5, "Williams");
    cout << "Test 5 - Single book: ";
    bool pass5 = (res5.size() == 1 && res5[0].title == "Solo Book");
    cout << (pass5 ? "PASS" : "FAIL");
    cout << " (Expected: 1 book [Solo Book], Got: " << res5.size() << " books)" << endl;

    // Test Case 6: Case sensitivity check
    // "orwell" (lowercase) should NOT match "Orwell" (uppercase)
    vector<Book> books6 = {
        {"1984", "Orwell", 1949, true},
        {"Animal Farm", "Orwell", 1945, true}};
    vector<Book> res6 = problem4Solution(books6, "orwell");
    cout << "Test 6 - Case sensitive: ";
    cout << (res6.size() == 0 ? "PASS" : "FAIL");
    cout << " (Expected: 0 books (case mismatch), Got: " << res6.size() << " books)" << endl;

    // Test Case 7: Empty library
    vector<Book> books7 = {};
    vector<Book> res7 = problem4Solution(books7, "Anyone");
    cout << "Test 7 - Empty library: ";
    cout << (res7.size() == 0 ? "PASS" : "FAIL");
    cout << " (Expected: 0 books, Got: " << res7.size() << " books)" << endl;

    // Test Case 8: Same year books
    // Brown: Book X (2000), Book Y (2000), Book Z (2001)
    // When years are same, order doesn't matter (just maintain stability)
    vector<Book> books8 = {
        {"Book Z", "Brown", 2001, true},
        {"Book X", "Brown", 2000, true},
        {"Book Y", "Brown", 2000, true}};
    vector<Book> res8 = problem4Solution(books8, "Brown");
    cout << "Test 8 - Same year books: ";
    bool pass8 = (res8.size() == 3 &&
                  res8[0].year == 2000 &&
                  res8[1].year == 2000 &&
                  res8[2].year == 2001);
    cout << (pass8 ? "PASS" : "FAIL");
    cout << " (Expected: 3 books, years [2000, 2000, 2001])" << endl;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main()
{
    int choice;
    cout << "======================================" << endl;
    cout << "  C++ Struct Practice Problems" << endl;
    cout << "======================================" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Student Grade Calculator" << endl;
    cout << "2. Problem 2 (Easy) - Rectangle Area and Perimeter" << endl;
    cout << "3. Problem 3 (Medium) - Find Closest Point to Origin" << endl;
    cout << "4. Problem 4 (Hard) - Book Library Management" << endl;
    cout << "5. Test All Problems" << endl;
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
        cout << "\n=== All Tests Complete ===" << endl;
        break;
    default:
        cout << "Invalid choice! Please select 1-5." << endl;
    }

    return 0;
}
