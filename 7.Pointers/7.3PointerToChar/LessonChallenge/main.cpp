#include <iostream>
#include <cstring>
using namespace std;

// Problem 1: Easy 1 - Character Finder
// Find the first occurrence of a target character in a string using pointer to char
// Input: A null-terminated string and a target character
// Output: Return pointer to the first occurrence, or nullptr if not found
// 
// Example 1: findChar("hello", 'l') should return pointer to first 'l' at index 2
// Example 2: findChar("world", 'z') should return nullptr (not found)
// Example 3: findChar("", 'a') should return nullptr (empty string)
//
// Constraints: 1 <= string length <= 100, printable ASCII characters
char* problem1Solution(const char* str, char target) {
    // TODO: Implement your solution here using pointer to char
    // Hint: Use pointer arithmetic to traverse the string and compare each character
}

// Problem 2: Easy 2 - String Length Calculator
// Calculate the length of a string using only pointer arithmetic (recreate strlen)
// Input: A null-terminated string
// Output: Return the length of the string as an integer
//
// Example 1: stringLength("hello") should return 5
// Example 2: stringLength("") should return 0
// Example 3: stringLength("a") should return 1
// Example 4: stringLength("C++") should return 3
//
// Constraints: 0 <= string length <= 1000, printable ASCII characters
int problem2Solution(const char* str) {
    // TODO: Implement your solution here using pointer to char
    // Hint: Start with a pointer copy and increment until you find the null terminator
}

// Problem 3: Medium - Reverse String In-Place
// Reverse a string in-place using two pointers (char pointers)
// Input: A null-terminated string (modifiable)
// Output: Modify the string in-place, no return value needed
//
// Example 1: reverseString("hello") should modify it to "olleh"
// Example 2: reverseString("ab") should modify it to "ba"
// Example 3: reverseString("a") should remain "a" (single character)
// Example 4: reverseString("") should remain "" (empty string)
//
// Constraints: 0 <= string length <= 500, printable ASCII characters
void problem3Solution(char* str) {
    // TODO: Implement your solution here using two char pointers
    // Hint: Use two pointers - one at start, one at end, swap characters and move inward
}

// Problem 4: Hard - First Non-Repeating Character
// Find the first non-repeating character in a string using pointer arithmetic
// Input: A null-terminated string
// Output: Return pointer to first non-repeating character, or nullptr if all repeat
//
// Example 1: firstNonRepeating("abccba") should return pointer to 'c' (wait, 'c' repeats...)
// Let me recalculate: "abccba" - 'a' appears twice, 'b' appears twice, 'c' appears twice
// Actually, let me use better example: "aabcc" - 'a':2, 'b':1, 'c':2, so return pointer to 'b'
//
// Example 1: firstNonRepeating("aabcc") should return pointer to 'b' at index 2
// Example 2: firstNonRepeating("abccba") should return nullptr (all characters repeat)
// Example 3: firstNonRepeating("a") should return pointer to 'a'
//
// Constraints: 1 <= string length <= 200, only lowercase letters a-z
char* problem4Solution(const char* str) {
    // TODO: Implement your solution here using pointer to char and arrays for counting
    // Hint: First pass to count character frequencies, second pass to find first with count=1
}

void testProblem1() {
    cout << "\n=== Testing Problem 1: Character Finder ===" << endl;
    
    // Test Case 1: Target found at beginning
    // "hello", target 'h' -> should return pointer to index 0
    const char* test1 = "hello";
    char* result1 = problem1Solution(test1, 'h');
    cout << "Test 1: " << (result1 == test1 ? "PASS" : "FAIL") << " - Find 'h' in \"hello\"" << endl;
    
    // Test Case 2: Target found in middle
    // "hello", target 'l' -> should return pointer to first 'l' at index 2
    char* result2 = problem1Solution(test1, 'l');
    cout << "Test 2: " << (result2 == test1 + 2 ? "PASS" : "FAIL") << " - Find first 'l' in \"hello\"" << endl;
    
    // Test Case 3: Target found at end
    // "hello", target 'o' -> should return pointer to index 4
    char* result3 = problem1Solution(test1, 'o');
    cout << "Test 3: " << (result3 == test1 + 4 ? "PASS" : "FAIL") << " - Find 'o' in \"hello\"" << endl;
    
    // Test Case 4: Target not found
    // "hello", target 'z' -> should return nullptr
    char* result4 = problem1Solution(test1, 'z');
    cout << "Test 4: " << (result4 == nullptr ? "PASS" : "FAIL") << " - Find 'z' in \"hello\" (not found)" << endl;
    
    // Test Case 5: Empty string
    // "", target 'a' -> should return nullptr
    const char* test5 = "";
    char* result5 = problem1Solution(test5, 'a');
    cout << "Test 5: " << (result5 == nullptr ? "PASS" : "FAIL") << " - Find 'a' in empty string" << endl;
    
    // Test Case 6: Single character match
    // "x", target 'x' -> should return pointer to index 0
    const char* test6 = "x";
    char* result6 = problem1Solution(test6, 'x');
    cout << "Test 6: " << (result6 == test6 ? "PASS" : "FAIL") << " - Find 'x' in \"x\"" << endl;
    
    // Test Case 7: Single character no match
    // "x", target 'y' -> should return nullptr
    char* result7 = problem1Solution(test6, 'y');
    cout << "Test 7: " << (result7 == nullptr ? "PASS" : "FAIL") << " - Find 'y' in \"x\" (not found)" << endl;
    
    // Test Case 8: Repeated character, find first
    // "ababa", target 'a' -> should return pointer to index 0
    const char* test8 = "ababa";
    char* result8 = problem1Solution(test8, 'a');
    cout << "Test 8: " << (result8 == test8 ? "PASS" : "FAIL") << " - Find first 'a' in \"ababa\"" << endl;
}

void testProblem2() {
    cout << "\n=== Testing Problem 2: String Length Calculator ===" << endl;
    
    // Test Case 1: Normal string
    // "hello" -> length = 5 (h-e-l-l-o)
    int result1 = problem2Solution("hello");
    cout << "Test 1: " << (result1 == 5 ? "PASS" : "FAIL") << " - Length of \"hello\" should be 5" << endl;
    
    // Test Case 2: Empty string
    // "" -> length = 0
    int result2 = problem2Solution("");
    cout << "Test 2: " << (result2 == 0 ? "PASS" : "FAIL") << " - Length of empty string should be 0" << endl;
    
    // Test Case 3: Single character
    // "a" -> length = 1
    int result3 = problem2Solution("a");
    cout << "Test 3: " << (result3 == 1 ? "PASS" : "FAIL") << " - Length of \"a\" should be 1" << endl;
    
    // Test Case 4: String with spaces
    // "hi there" -> length = 8 (h-i-space-t-h-e-r-e)
    int result4 = problem2Solution("hi there");
    cout << "Test 4: " << (result4 == 8 ? "PASS" : "FAIL") << " - Length of \"hi there\" should be 8" << endl;
    
    // Test Case 5: String with numbers
    // "123" -> length = 3
    int result5 = problem2Solution("123");
    cout << "Test 5: " << (result5 == 3 ? "PASS" : "FAIL") << " - Length of \"123\" should be 3" << endl;
    
    // Test Case 6: Longer string
    // "programming" -> length = 11 (p-r-o-g-r-a-m-m-i-n-g)
    int result6 = problem2Solution("programming");
    cout << "Test 6: " << (result6 == 11 ? "PASS" : "FAIL") << " - Length of \"programming\" should be 11" << endl;
    
    // Test Case 7: Special characters
    // "C++" -> length = 3 (C-+-+)
    int result7 = problem2Solution("C++");
    cout << "Test 7: " << (result7 == 3 ? "PASS" : "FAIL") << " - Length of \"C++\" should be 3" << endl;
    
    // Test Case 8: String with punctuation
    // "Hello, World!" -> length = 13 (H-e-l-l-o-,-space-W-o-r-l-d-!)
    int result8 = problem2Solution("Hello, World!");
    cout << "Test 8: " << (result8 == 13 ? "PASS" : "FAIL") << " - Length of \"Hello, World!\" should be 13" << endl;
}

void testProblem3() {
    cout << "\n=== Testing Problem 3: Reverse String In-Place ===" << endl;
    
    // Test Case 1: Normal string
    // "hello" -> "olleh"
    char test1[] = "hello";
    problem3Solution(test1);
    cout << "Test 1: " << (strcmp(test1, "olleh") == 0 ? "PASS" : "FAIL") << " - Reverse \"hello\" to \"olleh\"" << endl;
    
    // Test Case 2: Even length string
    // "abcd" -> "dcba"
    char test2[] = "abcd";
    problem3Solution(test2);
    cout << "Test 2: " << (strcmp(test2, "dcba") == 0 ? "PASS" : "FAIL") << " - Reverse \"abcd\" to \"dcba\"" << endl;
    
    // Test Case 3: Single character
    // "a" -> "a" (no change)
    char test3[] = "a";
    problem3Solution(test3);
    cout << "Test 3: " << (strcmp(test3, "a") == 0 ? "PASS" : "FAIL") << " - Reverse \"a\" should remain \"a\"" << endl;
    
    // Test Case 4: Two characters
    // "ab" -> "ba"
    char test4[] = "ab";
    problem3Solution(test4);
    cout << "Test 4: " << (strcmp(test4, "ba") == 0 ? "PASS" : "FAIL") << " - Reverse \"ab\" to \"ba\"" << endl;
    
    // Test Case 5: Empty string
    // "" -> "" (no change)
    char test5[] = "";
    problem3Solution(test5);
    cout << "Test 5: " << (strcmp(test5, "") == 0 ? "PASS" : "FAIL") << " - Empty string should remain empty" << endl;
    
    // Test Case 6: Palindrome
    // "aba" -> "aba" (no visible change but algorithm should work)
    char test6[] = "aba";
    problem3Solution(test6);
    cout << "Test 6: " << (strcmp(test6, "aba") == 0 ? "PASS" : "FAIL") << " - Reverse palindrome \"aba\"" << endl;
    
    // Test Case 7: Longer string
    // "programming" -> "gnimmargorP"
    char test7[] = "programming";
    problem3Solution(test7);
    cout << "Test 7: " << (strcmp(test7, "gnimmargorP") == 0 ? "PASS" : "FAIL") << " - Reverse \"programming\"" << endl;
    
    // Test Case 8: String with numbers
    // "12345" -> "54321"
    char test8[] = "12345";
    problem3Solution(test8);
    cout << "Test 8: " << (strcmp(test8, "54321") == 0 ? "PASS" : "FAIL") << " - Reverse \"12345\" to \"54321\"" << endl;
}

void testProblem4() {
    cout << "\n=== Testing Problem 4: First Non-Repeating Character ===" << endl;
    
    // Test Case 1: First non-repeating in middle
    // "aabcc" -> character counts: a:2, b:1, c:2
    // First pass through string: 'a' (count=2, skip), 'a' (count=2, skip), 'b' (count=1, FOUND!)
    // Should return pointer to 'b' at index 2
    const char* test1 = "aabcc";
    char* result1 = problem4Solution(test1);
    cout << "Test 1: " << (result1 == test1 + 2 ? "PASS" : "FAIL") << " - First non-repeating in \"aabcc\" is 'b' at index 2" << endl;
    
    // Test Case 2: All characters repeat
    // "abccba" -> character counts: a:2, b:2, c:2
    // No character has count=1, should return nullptr
    const char* test2 = "abccba";
    char* result2 = problem4Solution(test2);
    cout << "Test 2: " << (result2 == nullptr ? "PASS" : "FAIL") << " - All characters repeat in \"abccba\"" << endl;
    
    // Test Case 3: Single character
    // "a" -> character count: a:1
    // Should return pointer to 'a' at index 0
    const char* test3 = "a";
    char* result3 = problem4Solution(test3);
    cout << "Test 3: " << (result3 == test3 ? "PASS" : "FAIL") << " - Single character \"a\" is non-repeating" << endl;
    
    // Test Case 4: First character is non-repeating
    // "abccb" -> character counts: a:1, b:2, c:2
    // First pass: 'a' (count=1, FOUND!)
    // Should return pointer to 'a' at index 0
    const char* test4 = "abccb";
    char* result4 = problem4Solution(test4);
    cout << "Test 4: " << (result4 == test4 ? "PASS" : "FAIL") << " - First character 'a' is non-repeating in \"abccb\"" << endl;
    
    // Test Case 5: Last character is first non-repeating
    // "aabbcd" -> character counts: a:2, b:2, c:1, d:1
    // First pass: 'a' (count=2, skip), 'a' (count=2, skip), 'b' (count=2, skip), 'b' (count=2, skip), 'c' (count=1, FOUND!)
    // Should return pointer to 'c' at index 4
    const char* test5 = "aabbcd";
    char* result5 = problem4Solution(test5);
    cout << "Test 5: " << (result5 == test5 + 4 ? "PASS" : "FAIL") << " - First non-repeating 'c' at index 4 in \"aabbcd\"" << endl;
    
    // Test Case 6: Complex case
    // "abacabad" -> character counts: a:4, b:2, c:1, d:1
    // First pass: 'a' (count=4, skip), 'b' (count=2, skip), 'a' (count=4, skip), 'c' (count=1, FOUND!)
    // Should return pointer to 'c' at index 3
    const char* test6 = "abacabad";
    char* result6 = problem4Solution(test6);
    cout << "Test 6: " << (result6 == test6 + 3 ? "PASS" : "FAIL") << " - First non-repeating 'c' at index 3 in \"abacabad\"" << endl;
    
    // Test Case 7: All same characters
    // "aaaa" -> character count: a:4
    // No character has count=1, should return nullptr
    const char* test7 = "aaaa";
    char* result7 = problem4Solution(test7);
    cout << "Test 7: " << (result7 == nullptr ? "PASS" : "FAIL") << " - All same characters \"aaaa\"" << endl;
    
    // Test Case 8: Alternating pattern
    // "ababab" -> character counts: a:3, b:3
    // No character has count=1, should return nullptr  
    const char* test8 = "ababab";
    char* result8 = problem4Solution(test8);
    cout << "Test 8: " << (result8 == nullptr ? "PASS" : "FAIL") << " - Alternating pattern \"ababab\", all repeat" << endl;
}

int main() {
    int choice;
    cout << "=== Pointer to Char Practice Problems ===" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Character Finder" << endl;
    cout << "2. Problem 2 (Easy) - String Length Calculator" << endl;  
    cout << "3. Problem 3 (Medium) - Reverse String In-Place" << endl;
    cout << "4. Problem 4 (Hard) - First Non-Repeating Character" << endl;
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