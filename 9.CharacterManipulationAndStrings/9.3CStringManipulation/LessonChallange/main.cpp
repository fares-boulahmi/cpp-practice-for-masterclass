#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// ============================================================================
// Problem 1: Easy 1 - Count Vowels in C-String
// ============================================================================
// Given a C-string, count the total number of vowels (a, e, i, o, u).
// Count both uppercase and lowercase vowels.
//
// Input Format: A null-terminated C-string
// Output Format: Integer count of vowels
//
// Example 1:
//   Input: "Hello World"
//   Output: 3
//   Explanation: 'e', 'o', 'o' are vowels
//
// Example 2:
//   Input: "Programming"
//   Output: 3
//   Explanation: 'o', 'a', 'i' are vowels
//
// Constraints:
//   - String length: 0 to 1000 characters
//   - Contains only ASCII characters
//
int countVowels(const char* str) {
    // TODO: Implement your solution here using C-string manipulation
    // Hint: Iterate through the string using array indexing or pointer arithmetic
    // Check each character against vowels (both uppercase and lowercase)
    char vowels []{"eoiauEAIUO"};
    int result = 0;
    for (int i = 0; i < strlen(str); i++)
    {
      if (isalpha(str[i]))
      {
          /* code */
          if (strchr(vowels , str[i]) != nullptr)
          {
               result++;
          }
      }
      
     
    }
    
    return result;
}

// ============================================================================
// Problem 2: Easy 2 - Reverse C-String In-Place
// ============================================================================
// Reverse a C-string in-place without using additional arrays.
// Modify the original string directly.
//
// Input Format: A null-terminated C-string (modifiable)
// Output Format: The same string reversed (void function, modifies in-place)
//
// Example 1:
//   Input: "hello"
//   Output: "olleh"
//
// Example 2:
//   Input: "C++"
//   Output: "++C"
//
// Example 3:
//   Input: "a"
//   Output: "a"
//
// Constraints:
//   - String length: 0 to 1000 characters
//   - Must modify the string in-place (no extra arrays)
//
void reverseString(char* str) {
    // TODO: Implement your solution here using C-string manipulation
    // Hint: Use two pointers (one at start, one at end) and swap characters
    // Use strlen() to find the length, then work inward from both ends
    int total = strlen(str);
    char* rev = new char[strlen(str) + 1] {};
    for (int i = 0; i < total; i++)
    {
          rev[i] = str[total - i - 1];
    }
    for (int i = 0; i < total; i++)
    {
          str[i] = rev[i];
    }
    
}

// ============================================================================
// Problem 3: Medium - Remove Duplicate Characters
// ============================================================================
// Remove all duplicate characters from a C-string, keeping only the first
// occurrence of each character. Modify the string in-place.
//
// Input Format: A null-terminated C-string (modifiable)
// Output Format: The same string with duplicates removed (void function)
//
// Example 1:
//   Input: "programming"
//   Output: "progamin"
//   Explanation: First 'r' kept, second removed; first 'g' kept, second removed; 
//                first 'm' kept, second removed
//
// Example 2:
//   Input: "hello"
//   Output: "helo"
//   Explanation: First 'l' kept, second removed
//
// Example 3:
//   Input: "aabbcc"
//   Output: "abc"
//
// Constraints:
//   - String length: 0 to 1000 characters
//   - Case-sensitive (e.g., 'A' and 'a' are different)
//   - Must modify in-place
//
void removeDuplicates(char* str) {
    // TODO: Implement your solution here using C-string manipulation
    // Hint: For each character, check if it appeared earlier in the string
    // If it's the first occurrence, keep it; otherwise, shift remaining characters left
    // Use nested loops or track seen characters
    /* int total = strlen(str);
    char resutl [1000]{};
    for (int i = 0; i < total; i++)
    {
     if (strchr(resutl , str[i]) == nullptr)
     {
          strcat(resutl , str[i]);
     }
     
    }
    for (int i = 0; i < total; i++)
    {
          str[i] = resutl[i];
    } */
   cout << "the str in first appear " << str << endl;
   for (int  i = 0; i < strlen(str); i++)
   {
     for (int j = i + 1; j < strlen(str); j++)
     {
          if (str[i] == str[j])
          {
               cout << "get duplicated of " << str[i] << i << "in :" << str[j] << j  << endl;
               str[j] = str[j + 1] ;
               cout << "the j line after transfer is " << str[j] << endl;
          }
     }
     
   }
   cout << "the str is :" << str << endl;
   
    
}

// ============================================================================
// Problem 4: Hard - Custom String Compression
// ============================================================================
// Implement a basic string compression using counts of repeated characters.
// If the compressed string is not smaller than the original, return the original.
// The compression format: character followed by count (e.g., "aaa" -> "a3")
// Only compress sequences of 2 or more repeated characters.
//
// Input Format: Original C-string (const, read-only)
// Output Format: New C-string with compressed format (write to provided buffer)
//
// Example 1:
//   Input: "aabcccccaaa"
//   Output: "a2bc5a3"
//   Explanation: "aa" -> "a2", "b" stays "b", "ccccc" -> "c5", "aaa" -> "a3"
//
// Example 2:
//   Input: "abcd"
//   Output: "abcd"
//   Explanation: No compression saves space, return original
//
// Example 3:
//   Input: "aabbcc"
//   Output: "a2b2c2"
//   Explanation: Each pair compresses to char + count
//
// Constraints:
//   - String length: 0 to 1000 characters
//   - Contains only alphabetic characters (a-z, A-Z)
//   - Result buffer is guaranteed to be large enough
//   - Return true if compression occurred, false if original returned
//
bool compressString(const char* original, char* compressed) {
    // TODO: Implement your solution here using C-string manipulation
    // Hint: Count consecutive characters, build compressed string
    // Compare lengths: if compressed >= original, copy original to compressed and return false
    // Use a write pointer to build the compressed string character by character
    // For counts > 9, you'll need to handle multi-digit numbers (convert int to string)
    return false;
}

// ============================================================================
// TEST FUNCTIONS WITH MANUALLY VERIFIED TEST CASES
// ============================================================================

void testProblem1() {
    cout << "\n=== Testing Problem 1: Count Vowels ===" << endl;
    
    // Test Case 1: Mixed case with vowels
    // Manual verification: "Hello World" -> H(no) e(YES) l(no) l(no) o(YES) space(no) W(no) o(YES) r(no) l(no) d(no)
    // Count: e, o, o = 3 vowels
    const char* test1 = "Hello World";
    int expected1 = 3;
    int result1 = countVowels(test1);
    cout << "Test 1 - \"Hello World\": " << (result1 == expected1 ? "PASS" : "FAIL") 
         << " (Expected: " << expected1 << ", Got: " << result1 << ")" << endl;
    
    // Test Case 2: Programming
    // Manual verification: P(no) r(no) o(YES) g(no) r(no) a(YES) m(no) m(no) i(YES) n(no) g(no)
    // Count: o, a, i = 3 vowels
    const char* test2 = "Programming";
    int expected2 = 3;
    int result2 = countVowels(test2);
    cout << "Test 2 - \"Programming\": " << (result2 == expected2 ? "PASS" : "FAIL")
         << " (Expected: " << expected2 << ", Got: " << result2 << ")" << endl;
    
    // Test Case 3: Empty string
    // Manual verification: "" -> 0 vowels
    const char* test3 = "";
    int expected3 = 0;
    int result3 = countVowels(test3);
    cout << "Test 3 - Empty string: " << (result3 == expected3 ? "PASS" : "FAIL")
         << " (Expected: " << expected3 << ", Got: " << result3 << ")" << endl;
    
    // Test Case 4: No vowels
    // Manual verification: "xyz" -> x(no) y(no) z(no) = 0 vowels
    const char* test4 = "xyz";
    int expected4 = 0;
    int result4 = countVowels(test4);
    cout << "Test 4 - \"xyz\": " << (result4 == expected4 ? "PASS" : "FAIL")
         << " (Expected: " << expected4 << ", Got: " << result4 << ")" << endl;
    
    // Test Case 5: All vowels
    // Manual verification: "aeiouAEIOU" -> a(YES) e(YES) i(YES) o(YES) u(YES) A(YES) E(YES) I(YES) O(YES) U(YES)
    // Count: 10 vowels
    const char* test5 = "aeiouAEIOU";
    int expected5 = 10;
    int result5 = countVowels(test5);
    cout << "Test 5 - \"aeiouAEIOU\": " << (result5 == expected5 ? "PASS" : "FAIL")
         << " (Expected: " << expected5 << ", Got: " << result5 << ")" << endl;
    
    // Test Case 6: Mixed with numbers and symbols
    // Manual verification: "C++ 2024!" -> C(no) +(no) +(no) space(no) 2(no) 0(no) 2(no) 4(no) !(no)
    // Count: 0 vowels
    const char* test6 = "C++ 2024!";
    int expected6 = 0;
    int result6 = countVowels(test6);
    cout << "Test 6 - \"C++ 2024!\": " << (result6 == expected6 ? "PASS" : "FAIL")
         << " (Expected: " << expected6 << ", Got: " << result6 << ")" << endl;
    
    // Test Case 7: Single vowel
    // Manual verification: "a" -> a(YES) = 1 vowel
    const char* test7 = "a";
    int expected7 = 1;
    int result7 = countVowels(test7);
    cout << "Test 7 - \"a\": " << (result7 == expected7 ? "PASS" : "FAIL")
         << " (Expected: " << expected7 << ", Got: " << result7 << ")" << endl;
    
    // Test Case 8: Uppercase only
    // Manual verification: "EDUCATION" -> E(YES) D(no) U(YES) C(no) A(YES) T(no) I(YES) O(YES) N(no)
    // Count: E, U, A, I, O = 5 vowels
    const char* test8 = "EDUCATION";
    int expected8 = 5;
    int result8 = countVowels(test8);
    cout << "Test 8 - \"EDUCATION\": " << (result8 == expected8 ? "PASS" : "FAIL")
         << " (Expected: " << expected8 << ", Got: " << result8 << ")" << endl;
}

void testProblem2() {
    cout << "\n=== Testing Problem 2: Reverse String ===" << endl;
    
    // Test Case 1: Standard word
    // Manual verification: "hello" -> "olleh"
    // h e l l o (indices 0 1 2 3 4)
    // Swap: h<->o, e<->l, l stays = o l l e h
    char test1[] = "hello";
    reverseString(test1);
    cout << "Test 1 - \"hello\" reversed: " << (strcmp(test1, "olleh") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"olleh\", Got: \"" << test1 << "\")" << endl;
    
    // Test Case 2: Short string
    // Manual verification: "C++" -> "++C"
    // C + + (indices 0 1 2)
    // Swap: C<->+, + stays = + + C
    char test2[] = "C++";
    reverseString(test2);
    cout << "Test 2 - \"C++\" reversed: " << (strcmp(test2, "++C") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"++C\", Got: \"" << test2 << "\")" << endl;
    
    // Test Case 3: Single character
    // Manual verification: "a" -> "a" (no change)
    char test3[] = "a";
    reverseString(test3);
    cout << "Test 3 - \"a\" reversed: " << (strcmp(test3, "a") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"a\", Got: \"" << test3 << "\")" << endl;
    
    // Test Case 4: Empty string
    // Manual verification: "" -> "" (no change)
    char test4[] = "";
    reverseString(test4);
    cout << "Test 4 - Empty string reversed: " << (strcmp(test4, "") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"\", Got: \"" << test4 << "\")" << endl;
    
    // Test Case 5: Even length
    // Manual verification: "abcd" -> "dcba"
    // a b c d (indices 0 1 2 3)
    // Swap: a<->d, b<->c = d c b a
    char test5[] = "abcd";
    reverseString(test5);
    cout << "Test 5 - \"abcd\" reversed: " << (strcmp(test5, "dcba") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"dcba\", Got: \"" << test5 << "\")" << endl;
    
    // Test Case 6: Odd length
    // Manual verification: "abc" -> "cba"
    // a b c (indices 0 1 2)
    // Swap: a<->c, b stays = c b a
    char test6[] = "abc";
    reverseString(test6);
    cout << "Test 6 - \"abc\" reversed: " << (strcmp(test6, "cba") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"cba\", Got: \"" << test6 << "\")" << endl;
    
    // Test Case 7: With spaces
    // Manual verification: "a b" -> "b a"
    // a space b (indices 0 1 2)
    // Swap: a<->b, space stays = b space a
    char test7[] = "a b";
    reverseString(test7);
    cout << "Test 7 - \"a b\" reversed: " << (strcmp(test7, "b a") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"b a\", Got: \"" << test7 << "\")" << endl;
    
    // Test Case 8: Palindrome
    // Manual verification: "racecar" -> "racecar" (same)
    // r a c e c a r (indices 0 1 2 3 4 5 6)
    // Swap: r<->r, a<->a, c<->c, e stays = r a c e c a r
    char test8[] = "racecar";
    reverseString(test8);
    cout << "Test 8 - \"racecar\" reversed: " << (strcmp(test8, "racecar") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"racecar\", Got: \"" << test8 << "\")" << endl;
}

void testProblem3() {
    cout << "\n=== Testing Problem 3: Remove Duplicates ===" << endl;
    
    // Test Case 1: Standard case
    // Manual verification: "programming"
    // p(first,keep) r(first,keep) o(first,keep) g(first,keep) r(duplicate of index 1,remove)
    // a(first,keep) m(first,keep) m(duplicate of index 6,remove) i(first,keep) n(first,keep) g(duplicate of index 3,remove)
    // Result: "progamin"
    char test1[] = "programming";
    removeDuplicates(test1);
    cout << "Test 1 - \"programming\": " << (strcmp(test1, "progamin") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"progamin\", Got: \"" << test1 << "\")" << endl;
    
    // Test Case 2: Adjacent duplicates
    // Manual verification: "hello"
    // h(first,keep) e(first,keep) l(first,keep) l(duplicate,remove) o(first,keep)
    // Result: "helo"
    char test2[] = "hello";
    removeDuplicates(test2);
    cout << "Test 2 - \"hello\": " << (strcmp(test2, "helo") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"helo\", Got: \"" << test2 << "\")" << endl;
    
    // Test Case 3: All duplicates
    // Manual verification: "aabbcc"
    // a(first,keep) a(duplicate,remove) b(first,keep) b(duplicate,remove) c(first,keep) c(duplicate,remove)
    // Result: "abc"
    char test3[] = "aabbcc";
    removeDuplicates(test3);
    cout << "Test 3 - \"aabbcc\": " << (strcmp(test3, "abc") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"abc\", Got: \"" << test3 << "\")" << endl;
    
    // Test Case 4: No duplicates
    // Manual verification: "abcd"
    // a(first,keep) b(first,keep) c(first,keep) d(first,keep)
    // Result: "abcd" (unchanged)
    char test4[] = "abcd";
    removeDuplicates(test4);
    cout << "Test 4 - \"abcd\": " << (strcmp(test4, "abcd") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"abcd\", Got: \"" << test4 << "\")" << endl;
    
    // Test Case 5: Empty string
    // Manual verification: "" -> "" (no change)
    char test5[] = "";
    removeDuplicates(test5);
    cout << "Test 5 - Empty string: " << (strcmp(test5, "") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"\", Got: \"" << test5 << "\")" << endl;
    
    // Test Case 6: Single character
    // Manual verification: "a" -> "a" (no duplicates)
    char test6[] = "a";
    removeDuplicates(test6);
    cout << "Test 6 - \"a\": " << (strcmp(test6, "a") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"a\", Got: \"" << test6 << "\")" << endl;
    
    // Test Case 7: All same character
    // Manual verification: "aaaa"
    // a(first,keep) a(duplicate,remove) a(duplicate,remove) a(duplicate,remove)
    // Result: "a"
    char test7[] = "aaaa";
    removeDuplicates(test7);
    cout << "Test 7 - \"aaaa\": " << (strcmp(test7, "a") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"a\", Got: \"" << test7 << "\")" << endl;
    
    // Test Case 8: Case sensitive
    // Manual verification: "AaBbAa"
    // A(first,keep) a(first,keep) B(first,keep) b(first,keep) A(duplicate of index 0,remove) a(duplicate of index 1,remove)
    // Result: "AaBb"
    char test8[] = "AaBbAa";
    removeDuplicates(test8);
    cout << "Test 8 - \"AaBbAa\": " << (strcmp(test8, "AaBb") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"AaBb\", Got: \"" << test8 << "\")" << endl;
}

void testProblem4() {
    cout << "\n=== Testing Problem 4: String Compression ===" << endl;
    
    // Test Case 1: Mixed compression
    // Manual verification: "aabcccccaaa"
    // aa -> a2 (2 chars -> 2 chars)
    // b -> b (1 char stays 1 char)
    // ccccc -> c5 (5 chars -> 2 chars)
    // aaa -> a3 (3 chars -> 2 chars)
    // Compressed: "a2bc5a3" (8 chars) vs Original: "aabcccccaaa" (11 chars)
    // 8 < 11, so use compressed
    char result1[100];
    bool compressed1 = compressString("aabcccccaaa", result1);
    cout << "Test 1 - \"aabcccccaaa\": " << (compressed1 && strcmp(result1, "a2bc5a3") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"a2bc5a3\", Got: \"" << result1 << "\", Compressed: " << (compressed1 ? "true" : "false") << ")" << endl;
    
    // Test Case 2: No compression benefit
    // Manual verification: "abcd"
    // a -> a (1 char)
    // b -> b (1 char)
    // c -> c (1 char)
    // d -> d (1 char)
    // Compressed would be: "abcd" (4 chars) vs Original: "abcd" (4 chars)
    // 4 >= 4, so return original
    char result2[100];
    bool compressed2 = compressString("abcd", result2);
    cout << "Test 2 - \"abcd\": " << (!compressed2 && strcmp(result2, "abcd") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"abcd\", Got: \"" << result2 << "\", Compressed: " << (compressed2 ? "true" : "false") << ")" << endl;
    
    // Test Case 3: All pairs
    // Manual verification: "aabbcc"
    // aa -> a2 (2 chars -> 2 chars)
    // bb -> b2 (2 chars -> 2 chars)
    // cc -> c2 (2 chars -> 2 chars)
    // Compressed: "a2b2c2" (6 chars) vs Original: "aabbcc" (6 chars)
    // 6 >= 6, so return original
    char result3[100];
    bool compressed3 = compressString("aabbcc", result3);
    cout << "Test 3 - \"aabbcc\": " << (!compressed3 && strcmp(result3, "aabbcc") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"aabbcc\", Got: \"" << result3 << "\", Compressed: " << (compressed3 ? "true" : "false") << ")" << endl;
    
    // Test Case 4: Long run
    // Manual verification: "aaaaaaaaaa" (10 a's)
    // aaaaaaaaaa -> a10 (10 chars -> 3 chars)
    // Compressed: "a10" (3 chars) vs Original: "aaaaaaaaaa" (10 chars)
    // 3 < 10, so use compressed
    char result4[100];
    bool compressed4 = compressString("aaaaaaaaaa", result4);
    cout << "Test 4 - \"aaaaaaaaaa\": " << (compressed4 && strcmp(result4, "a10") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"a10\", Got: \"" << result4 << "\", Compressed: " << (compressed4 ? "true" : "false") << ")" << endl;
    
    // Test Case 5: Empty string
    // Manual verification: "" -> "" (0 chars)
    // Compressed: "" (0 chars) vs Original: "" (0 chars)
    // 0 >= 0, so return original (though both are same)
    char result5[100];
    bool compressed5 = compressString("", result5);
    cout << "Test 5 - Empty string: " << (strcmp(result5, "") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"\", Got: \"" << result5 << "\", Compressed: " << (compressed5 ? "true" : "false") << ")" << endl;
    
    // Test Case 6: Single character
    // Manual verification: "a"
    // a -> a (1 char stays 1 char)
    // Compressed: "a" (1 char) vs Original: "a" (1 char)
    // 1 >= 1, so return original
    char result6[100];
    bool compressed6 = compressString("a", result6);
    cout << "Test 6 - \"a\": " << (!compressed6 && strcmp(result6, "a") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"a\", Got: \"" << result6 << "\", Compressed: " << (compressed6 ? "true" : "false") << ")" << endl;
    
    // Test Case 7: Multiple groups
    // Manual verification: "aaabbbccc"
    // aaa -> a3 (3 chars -> 2 chars)
    // bbb -> b3 (3 chars -> 2 chars)
    // ccc -> c3 (3 chars -> 2 chars)
    // Compressed: "a3b3c3" (6 chars) vs Original: "aaabbbccc" (9 chars)
    // 6 < 9, so use compressed
    char result7[100];
    bool compressed7 = compressString("aaabbbccc", result7);
    cout << "Test 7 - \"aaabbbccc\": " << (compressed7 && strcmp(result7, "a3b3c3") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"a3b3c3\", Got: \"" << result7 << "\", Compressed: " << (compressed7 ? "true" : "false") << ")" << endl;
    
    // Test Case 8: Mixed case letters
    // Manual verification: "AAaaBBbb"
    // AA -> A2 (2 chars -> 2 chars)
    // aa -> a2 (2 chars -> 2 chars)
    // BB -> B2 (2 chars -> 2 chars)
    // bb -> b2 (2 chars -> 2 chars)
    // Compressed: "A2a2B2b2" (8 chars) vs Original: "AAaaBBbb" (8 chars)
    // 8 >= 8, so return original
    char result8[100];
    bool compressed8 = compressString("AAaaBBbb", result8);
    cout << "Test 8 - \"AAaaBBbb\": " << (!compressed8 && strcmp(result8, "AAaaBBbb") == 0 ? "PASS" : "FAIL")
         << " (Expected: \"AAaaBBbb\", Got: \"" << result8 << "\", Compressed: " << (compressed8 ? "true" : "false") << ")" << endl;
}

int main() {
    int choice;
    cout << "==============================================\n";
    cout << "  C-String Manipulation Practice Problems\n";
    cout << "==============================================\n";
    cout << "Choose a problem to test (1-4) or 5 to test all:\n";
    cout << "1. Problem 1 (Easy) - Count Vowels\n";
    cout << "2. Problem 2 (Easy) - Reverse String\n";
    cout << "3. Problem 3 (Medium) - Remove Duplicates\n";
    cout << "4. Problem 4 (Hard) - String Compression\n";
    cout << "5. Test All Problems\n";
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