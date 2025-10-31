#include <iostream>
#include <cstring>  // For strlen, strcpy functions
#include <string>

using namespace std;

// Problem 1: Easy 1 - Count Vowels in Character Array
// Given a character array (string), count how many vowels (a, e, i, o, u) it contains.
// Both uppercase and lowercase vowels should be counted.
// Input Format: A character array terminated by null character
// Output Format: Return the count of vowels as an integer
// 
// Example 1: "hello" -> 2 (e, o)
// Example 2: "PROGRAMMING" -> 2 (O, A)
// Example 3: "xyz" -> 0 (no vowels)
// Example 4: "AeIoU" -> 5 (all vowels)
//
// Constraints: 1 <= string length <= 100
int problem1Solution(char str[]) {
    // TODO: Implement your solution here using Arrays of characters
    // Hint: Loop through the character array and check each character against vowels
    string vowels {"aeiouAEIOU"};
    string word = str ;
    int vowels_numbers{};
    for (size_t i = 0; i < word.size(); i++)
    {
        for (size_t j = 0; j < vowels.size(); j++)
        {
            if (word[i] == vowels[j])
            {
                vowels_numbers++;
            }
            
        }
        
    }
    return vowels_numbers;
}

// Problem 2: Easy 2 - Reverse Character Array
// Given a character array, reverse it in-place (modify the original array).
// Input Format: A character array terminated by null character
// Output Format: The same array but reversed (void return type)
//
// Example 1: "hello" -> "olleh"
// Example 2: "abc" -> "cba"
// Example 3: "a" -> "a" (single character)
// Example 4: "12345" -> "54321"
//
// Constraints: 1 <= string length <= 100
void problem2Solution(char str[]) {
    // TODO: Implement your solution here using Arrays of characters
    // Hint: Use two pointers approach - one from start, one from end, swap characters
    string word = str;
    string revers_word {};
    for (int i = (word.size() - 1); i >= 0 ; i--)
    {
        revers_word.push_back(word[i]);
    }
    for (size_t i = 0; i < word.size(); i++)
    {
        str[i] = revers_word[i];
    }

}

// Problem 3: Medium - Count Character Frequency
// Given a character array and a target character, count how many times the target appears.
// The search should be case-sensitive.
// Input Format: A character array and a character to search for
// Output Format: Return the count as an integer
//
// Example 1: "hello", 'l' -> 2
// Example 2: "programming", 'r' -> 2  
// Example 3: "test", 'x' -> 0
// Example 4: "AAaa", 'A' -> 2 (case sensitive)
//
// Constraints: 1 <= string length <= 200, target is printable ASCII character
int problem3Solution(char str[], char target) {
    // TODO: Implement your solution here using Arrays of characters
    // Hint: Loop through array and compare each character with target
    string word = str;
    int numb {};
    for (size_t i = 0; i < word.size() ; i++)
    {
        if (word[i] == target)
        {
            numb++;
        }
        
    }
    
    return numb;
}

// Problem 4: Hard - Check if Character Array is Palindrome
// Given a character array, determine if it reads the same forwards and backwards.
// Consider only alphabetic characters and ignore case.
// Input Format: A character array that may contain spaces and punctuation
// Output Format: Return true if palindrome, false otherwise
//
// Example 1: "racecar" -> true
// Example 2: "A man a plan a canal Panama" -> true (ignoring spaces and case)
// Example 3: "hello" -> false
// Example 4: "Madam" -> true (ignoring case)
//
// Constraints: 1 <= string length <= 300
bool problem4Solution(char str[]) {
    // TODO: Implement your solution here using Arrays of characters
    // Hint: Use two pointers, skip non-alphabetic chars, convert to same case for comparison
    string word = str ;
    bool rev{true}; 
    for (size_t i = 0; i < word.size() ; i++)
    {
        if (!isalpha(word[i]))
        {
            word.erase(i , 1);
        }
        word[i] = (char)tolower(word[i]);
        
    }
    for (int i = 0; i < ((word.size() / 2)  ); i++)
    {
        if (word[i] != word[word.size() - 1 - i])
        {
            rev = false;
        }
        
    }    
    return rev;
}

void testProblem1() {
    cout << "Testing Problem 1 - Count Vowels..." << endl;
    
    // Test Case 1: "hello"
    // Manual calculation: h(no), e(yes-1), l(no), l(no), o(yes-2) = 2 vowels
    // Expected output: 2
    char test1[] = "hello";
    cout << "Test 1: " << (problem1Solution(test1) == 2 ? "PASS" : "FAIL") << " - Expected: 2" << endl;
    
    // Test Case 2: "PROGRAMMING" 
    // Manual calculation: P(no), R(no), O(yes-1), G(no), R(no), A(yes-2), M(no), M(no), I(yes-3), N(no), G(no) = 3 vowels
    // Expected output: 3
    char test2[] = "PROGRAMMING";
    cout << "Test 2: " << (problem1Solution(test2) == 3 ? "PASS" : "FAIL") << " - Expected: 3" << endl;
    
    // Test Case 3: "xyz"
    // Manual calculation: x(no), y(no), z(no) = 0 vowels
    // Expected output: 0
    char test3[] = "xyz";
    cout << "Test 3: " << (problem1Solution(test3) == 0 ? "PASS" : "FAIL") << " - Expected: 0" << endl;
    
    // Test Case 4: "AeIoU"
    // Manual calculation: A(yes-1), e(yes-2), I(yes-3), o(yes-4), U(yes-5) = 5 vowels
    // Expected output: 5
    char test4[] = "AeIoU";
    cout << "Test 4: " << (problem1Solution(test4) == 5 ? "PASS" : "FAIL") << " - Expected: 5" << endl;
    
    // Test Case 5: "bcdfg"
    // Manual calculation: b(no), c(no), d(no), f(no), g(no) = 0 vowels
    // Expected output: 0
    char test5[] = "bcdfg";
    cout << "Test 5: " << (problem1Solution(test5) == 0 ? "PASS" : "FAIL") << " - Expected: 0" << endl;
    
    // Test Case 6: "Education"
    // Manual calculation: E(yes-1), d(no), u(yes-2), c(no), a(yes-3), t(no), i(yes-4), o(yes-5), n(no) = 5 vowels
    // Expected output: 5
    char test6[] = "Education";
    cout << "Test 6: " << (problem1Solution(test6) == 5 ? "PASS" : "FAIL") << " - Expected: 5" << endl;
    
    // Test Case 7: "a"
    // Manual calculation: a(yes-1) = 1 vowel
    // Expected output: 1
    char test7[] = "a";
    cout << "Test 7: " << (problem1Solution(test7) == 1 ? "PASS" : "FAIL") << " - Expected: 1" << endl;
    
    // Test Case 8: "HELLO world"
    // Manual calculation: H(no), E(yes-1), L(no), L(no), O(yes-2), (space-no), w(no), o(yes-3), r(no), l(no), d(no) = 3 vowels
    // Expected output: 3
    char test8[] = "HELLO world";
    cout << "Test 8: " << (problem1Solution(test8) == 3 ? "PASS" : "FAIL") << " - Expected: 3" << endl;
    
    cout << endl;
}

void testProblem2() {
    cout << "Testing Problem 2 - Reverse Character Array..." << endl;
    
    // Test Case 1: "hello"
    // Manual calculation: reverse of "hello" = "olleh"
    // Expected output: "olleh"
    char test1[] = "hello";
    problem2Solution(test1);
    cout << "Test 1: " << (strcmp(test1, "olleh") == 0 ? "PASS" : "FAIL") << " - Expected: olleh, Got: " << test1 << endl;
    
    // Test Case 2: "abc"
    // Manual calculation: reverse of "abc" = "cba"
    // Expected output: "cba"
    char test2[] = "abc";
    problem2Solution(test2);
    cout << "Test 2: " << (strcmp(test2, "cba") == 0 ? "PASS" : "FAIL") << " - Expected: cba, Got: " << test2 << endl;
    
    // Test Case 3: "a"
    // Manual calculation: reverse of "a" = "a" (single character remains same)
    // Expected output: "a"
    char test3[] = "a";
    problem2Solution(test3);
    cout << "Test 3: " << (strcmp(test3, "a") == 0 ? "PASS" : "FAIL") << " - Expected: a, Got: " << test3 << endl;
    
    // Test Case 4: "12345"
    // Manual calculation: reverse of "12345" = "54321"
    // Expected output: "54321"
    char test4[] = "12345";
    problem2Solution(test4);
    cout << "Test 4: " << (strcmp(test4, "54321") == 0 ? "PASS" : "FAIL") << " - Expected: 54321, Got: " << test4 << endl;
    
    // Test Case 5: "AB"
    // Manual calculation: reverse of "AB" = "BA"
    // Expected output: "BA"
    char test5[] = "AB";
    problem2Solution(test5);
    cout << "Test 5: " << (strcmp(test5, "BA") == 0 ? "PASS" : "FAIL") << " - Expected: BA, Got: " << test5 << endl;
    
    // Test Case 6: "racecar"
    // Manual calculation: reverse of "racecar" = "racecar" (palindrome)
    // Expected output: "racecar"
    char test6[] = "racecar";
    problem2Solution(test6);
    cout << "Test 6: " << (strcmp(test6, "racecar") == 0 ? "PASS" : "FAIL") << " - Expected: racecar, Got: " << test6 << endl;
    
    // Test Case 7: "programming"
    // Manual calculation: reverse of "programming" = "gnimmargorp"
    // Expected output: "gnimmargorp"
    char test7[] = "programming";
    problem2Solution(test7);
    cout << "Test 7: " << (strcmp(test7, "gnimmargorp") == 0 ? "PASS" : "FAIL") << " - Expected: gnimmargorp, Got: " << test7 << endl;
    
    // Test Case 8: "XY"
    // Manual calculation: reverse of "XY" = "YX"
    // Expected output: "YX"
    char test8[] = "XY";
    problem2Solution(test8);
    cout << "Test 8: " << (strcmp(test8, "YX") == 0 ? "PASS" : "FAIL") << " - Expected: YX, Got: " << test8 << endl;
    
    cout << endl;
}

void testProblem3() {
    cout << "Testing Problem 3 - Count Character Frequency..." << endl;
    
    // Test Case 1: "hello", target 'l'
    // Manual calculation: h(no), e(no), l(yes-1), l(yes-2), o(no) = 2 occurrences
    // Expected output: 2
    char test1[] = "hello";
    cout << "Test 1: " << (problem3Solution(test1, 'l') == 2 ? "PASS" : "FAIL") << " - Expected: 2" << endl;
    
    // Test Case 2: "programming", target 'r'
    // Manual calculation: p(no), r(yes-1), o(no), g(no), r(yes-2), a(no), m(no), m(no), i(no), n(no), g(no) = 2 occurrences
    // Expected output: 2
    char test2[] = "programming";
    cout << "Test 2: " << (problem3Solution(test2, 'r') == 2 ? "PASS" : "FAIL") << " - Expected: 2" << endl;
    
    // Test Case 3: "test", target 'x'
    // Manual calculation: t(no), e(no), s(no), t(no) = 0 occurrences
    // Expected output: 0
    char test3[] = "test";
    cout << "Test 3: " << (problem3Solution(test3, 'x') == 0 ? "PASS" : "FAIL") << " - Expected: 0" << endl;
    
    // Test Case 4: "AAaa", target 'A'
    // Manual calculation: A(yes-1), A(yes-2), a(no), a(no) = 2 occurrences (case sensitive)
    // Expected output: 2
    char test4[] = "AAaa";
    cout << "Test 4: " << (problem3Solution(test4, 'A') == 2 ? "PASS" : "FAIL") << " - Expected: 2" << endl;
    
    // Test Case 5: "banana", target 'a'
    // Manual calculation: b(no), a(yes-1), n(no), a(yes-2), n(no), a(yes-3) = 3 occurrences
    // Expected output: 3
    char test5[] = "banana";
    cout << "Test 5: " << (problem3Solution(test5, 'a') == 3 ? "PASS" : "FAIL") << " - Expected: 3" << endl;
    
    // Test Case 6: "mississippi", target 's'
    // Manual calculation: m(no), i(no), s(yes-1), s(yes-2), i(no), s(yes-3), s(yes-4), i(no), p(no), p(no), i(no) = 4 occurrences
    // Expected output: 4
    char test6[] = "mississippi";
    cout << "Test 6: " << (problem3Solution(test6, 's') == 4 ? "PASS" : "FAIL") << " - Expected: 4" << endl;
    
    // Test Case 7: "abcdef", target 'a'
    // Manual calculation: a(yes-1), b(no), c(no), d(no), e(no), f(no) = 1 occurrence
    // Expected output: 1
    char test7[] = "abcdef";
    cout << "Test 7: " << (problem3Solution(test7, 'a') == 1 ? "PASS" : "FAIL") << " - Expected: 1" << endl;
    
    // Test Case 8: "aaaa", target 'a'
    // Manual calculation: a(yes-1), a(yes-2), a(yes-3), a(yes-4) = 4 occurrences
    // Expected output: 4
    char test8[] = "aaaa";
    cout << "Test 8: " << (problem3Solution(test8, 'a') == 4 ? "PASS" : "FAIL") << " - Expected: 4" << endl;
    
    cout << endl;
}

void testProblem4() {
    cout << "Testing Problem 4 - Check if Palindrome..." << endl;
    
    // Test Case 1: "racecar"
    // Manual calculation: all alphabetic, r-a-c-e-c-a-r, forward=racecar, backward=racecar = true
    // Expected output: true
    char test1[] = "racecar";
    cout << "Test 1: " << (problem4Solution(test1) == true ? "PASS" : "FAIL") << " - Expected: true" << endl;
    
    // Test Case 2: "A man a plan a canal Panama"
    // Manual calculation: extract alphabetic only: "AmanaplanacanalPanama", lowercase: "amanaplanacanalpanama"
    // Forward: amanaplanacanalpanama, Backward: amanaplanacanalpanama = true
    // Expected output: true
    char test2[] = "A man a plan a canal Panama";
    cout << "Test 2: " << (problem4Solution(test2) == true ? "PASS" : "FAIL") << " - Expected: true" << endl;
    
    // Test Case 3: "hello"
    // Manual calculation: all alphabetic, h-e-l-l-o, forward=hello, backward=olleh = false
    // Expected output: false
    char test3[] = "hello";
    cout << "Test 3: " << (problem4Solution(test3) == false ? "PASS" : "FAIL") << " - Expected: false" << endl;
    
    // Test Case 4: "Madam"
    // Manual calculation: all alphabetic, convert to lowercase: m-a-d-a-m, forward=madam, backward=madam = true
    // Expected output: true
    char test4[] = "Madam";
    cout << "Test 4: " << (problem4Solution(test4) == true ? "PASS" : "FAIL") << " - Expected: true" << endl;
    
    // Test Case 5: "race a car"
    // Manual calculation: extract alphabetic: "raceacar", forward=raceacar, backward=racaecar = false
    // Expected output: false  
    char test5[] = "race a car";
    cout << "Test 5: " << (problem4Solution(test5) == false ? "PASS" : "FAIL") << " - Expected: false" << endl;
    
    // Test Case 6: "Was it a car or a cat I saw?"
    // Manual calculation: extract alphabetic: "WasitacaroracatIsaw", lowercase: "wasitacaroracatisaw"
    // Forward: wasitacaroracatisaw, Backward: wasitacaroracatisaw = true
    // Expected output: true
    char test6[] = "Was it a car or a cat I saw?";
    cout << "Test 6: " << (problem4Solution(test6) == true ? "PASS" : "FAIL") << " - Expected: true" << endl;
    
    // Test Case 7: "a"
    // Manual calculation: single character, a = a = true
    // Expected output: true
    char test7[] = "a";
    cout << "Test 7: " << (problem4Solution(test7) == true ? "PASS" : "FAIL") << " - Expected: true" << endl;
    
    // Test Case 8: "ab"
    // Manual calculation: a-b, forward=ab, backward=ba = false
    // Expected output: false
    char test8[] = "ab";
    cout << "Test 8: " << (problem4Solution(test8) == false ? "PASS" : "FAIL") << " - Expected: false" << endl;
    
    cout << endl;
}

int main() {
    int choice;
    cout << "=== Arrays of Characters Practice Problems ===" << endl;
    cout << "Choose a problem to test (1-4) or 5 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Count Vowels" << endl;
    cout << "2. Problem 2 (Easy-Advanced) - Reverse Array" << endl;
    cout << "3. Problem 3 (Medium) - Character Frequency" << endl;
    cout << "4. Problem 4 (Hard) - Palindrome Check" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;

    switch(choice) {
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
            cout << "Invalid choice! Please enter 1-5." << endl;
    }

    return 0;
}