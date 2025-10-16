#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// Problem 1: Easy 1 - Character Case Counter
//
// Problem Description:
// Given a string, count how many uppercase letters, lowercase letters,
// digits, and spaces are present in the string.
//
// Input Format:
// A single line containing a string (may include spaces)
//
// Output Format:
// Four integers: uppercase_count lowercase_count digit_count space_count
//
// Examples:
// Input: "Hello World 123"
// Output: 2 8 3 2
// Explanation: H,W are uppercase(2), e,l,l,o,o,r,l,d are lowercase(8), 1,2,3 are digits(3), 2 spaces
//
// Input: "ABC"
// Output: 3 0 0 0
//
// Constraints:
// - String length: 0 to 1000 characters
// - Only printable ASCII characters
void problem1Solution(const string &str, int &upper, int &lower, int &digit, int &space)
{
    // TODO: Implement your solution here using Character Manipulation
    // Hint: Use isupper(), islower(), isdigit(), isspace() functions from <cctype>
    // Loop through each character and check its type
    for (int i = 0; i < str.size(); i++)
    {
        if (isupper(str[i]))
            upper++;
        if (islower(str[i]))
            lower++;
        if (isdigit(str[i]))
            digit++;
        if (isspace(str[i]))
            space++;
    }
}

// Problem 2: Easy 2 - Toggle Case
//
// Problem Description:
// Given a string, toggle the case of all alphabetic characters.
// Uppercase letters become lowercase and vice versa.
// Non-alphabetic characters remain unchanged.
//
// Input Format:
// A single line containing a string
//
// Output Format:
// The string with toggled cases
//
// Examples:
// Input: "Hello World"
// Output: "hELLO wORLD"
//
// Input: "C++ Programming 101"
// Output: "c++ pROGRAMMING 101"
//
// Input: "12345"
// Output: "12345"
//
// Constraints:
// - String length: 0 to 1000 characters
// - Only printable ASCII characters
string problem2Solution(const string &str)
{
    // TODO: Implement your solution here using Character Manipulation
    // Hint: Use isupper(), islower(), toupper(), tolower() functions
    // Create a new string and process each character
    string result{};
    for (int i = 0; i < str.size(); i++)
    {
        if (isalpha(str[i]))
        {
            if (isupper(str[i]))
            {
                result.push_back(tolower(str[i]));
            }
            else if (islower(str[i]))
            {
                result.push_back(toupper(str[i]));
            }
        }
        else
        {
            result.push_back(str[i]);
        }
    }

    return result;
}

// Problem 3: Medium - Remove Non-Alphanumeric and Convert
//
// Problem Description:
// Given a string, remove all characters that are not letters or digits,
// convert all remaining letters to lowercase, and return the result.
// This is useful for normalizing strings for comparison (like palindrome checking).
//
// Input Format:
// A single line containing a string
//
// Output Format:
// The cleaned and lowercase string
//
// Examples:
// Input: "Hello, World!"
// Output: "helloworld"
//
// Input: "A1B2-C3"
// Output: "a1b2c3"
//
// Input: "!@#$%"
// Output: ""
//
// Constraints:
// - String length: 0 to 1000 characters
// - Only printable ASCII characters
string problem3Solution(const string &str)
{
    // TODO: Implement your solution here using Character Manipulation
    // Hint: Use isalnum() to check if character is alphanumeric, tolower() to convert
    // Build a new string containing only valid characters
    string result{};
    for (int i = 0; i < str.size(); i++)
    {
        if (isalnum(str[i]))
        {
            if (isupper(str[i]))
            {
                result.push_back(tolower(str[i]));
            }
            else
            {
                result.push_back(str[i]);
            }
        }
    }
    char l = 'j';
    return result;
}

// Problem 4: Hard - Caesar Cipher Encoder
//
// Problem Description:
// Implement a Caesar Cipher encoder that shifts alphabetic characters by a given amount.
// - Only alphabetic characters (a-z, A-Z) should be shifted
// - Uppercase letters stay uppercase, lowercase stay lowercase
// - The shift wraps around (z+1 = a, Z+1 = A)
// - Non-alphabetic characters remain unchanged
//
// Input Format:
// A string and an integer shift value (can be positive or negative)
//
// Output Format:
// The encoded string
//
// Examples:
// Input: "Hello", shift = 3
// Output: "Khoor"
// Explanation: H(+3)->K, e(+3)->h, l(+3)->o, l(+3)->o, o(+3)->r
//
// Input: "xyz", shift = 2
// Output: "zab"
// Explanation: x(+2)->z, y(+2)->a (wraps), z(+2)->b (wraps)
//
// Input: "ABC", shift = -1
// Output: "ZBC"
// Explanation: A(-1)->Z (wraps), B(-1)->A, C(-1)->B
//
// Constraints:
// - String length: 0 to 1000 characters
// - Shift value: -10000 to 10000
// - Only printable ASCII characters
string problem4Solution(const string &str, int shift)
{
    // TODO: Implement your solution here using Character Manipulation
    // Hint: For each letter, determine if it's upper/lower, then shift within that range
    // Use modulo (%) to handle wrapping. Be careful with negative shifts!
    // Formula idea: new_char = ((old_char - base + shift) % 26 + 26) % 26 + base
    // where base is 'a' for lowercase or 'A' for uppercase
    string result{};
    for (int i = 0; i < str.size(); i++)
    {
        if (isalpha(str[i]))
        {
            // convert all to upper for fix change 
            char conv = toupper(str[i]);
            if (shift > 26 ) shift = shift - 26;
            if (shift < -26 ) shift = shift + 26;
            //  check if for outrage the Z or under A in ASCII table then wraps if it or leave with shift if not 
            if ((conv + shift ) > 90)
            {
                conv = (conv + shift) - 26;
            } else if ((conv + shift ) < 65)
            {
                conv = (conv + shift) + 26;
            } else {
                conv = conv + shift;
            }
            // return to original chape with the shift
            if (islower(str[i])) {
                result.push_back(tolower(conv));
            } else if (isupper(str[i])) {
                result.push_back(toupper(conv));

            }
        }
        else
        {
            result.push_back(str[i]);
        }
    }

    return result;
}

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Character Case Counter ===" << endl;

    // Test Case 1: Mixed characters
    // Manual verification: "Hello World 123"
    // H,W = 2 uppercase | h,e,l,l,o,o,r,l,d = 8 lowercase | 1,2,3 = 3 digits | 2 spaces
    {
        string input = "Hello World 123";
        int upper = 0, lower = 0, digit = 0, space = 0;
        problem1Solution(input, upper, lower, digit, space);
        cout << "Test 1: " << (upper == 2 && lower == 8 && digit == 3 && space == 2 ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: " << upper << " " << lower << " " << digit << " " << space
             << " | Expected: 2 8 3 2" << endl;
    }

    // Test Case 2: All uppercase
    // Manual verification: "ABC"
    // A,B,C = 3 uppercase | 0 lowercase | 0 digits | 0 spaces
    {
        string input = "ABC";
        int upper = 0, lower = 0, digit = 0, space = 0;
        problem1Solution(input, upper, lower, digit, space);
        cout << "Test 2: " << (upper == 3 && lower == 0 && digit == 0 && space == 0 ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: " << upper << " " << lower << " " << digit << " " << space
             << " | Expected: 3 0 0 0" << endl;
    }

    // Test Case 3: All lowercase
    // Manual verification: "xyz"
    // 0 uppercase | x,y,z = 3 lowercase | 0 digits | 0 spaces
    {
        string input = "xyz";
        int upper = 0, lower = 0, digit = 0, space = 0;
        problem1Solution(input, upper, lower, digit, space);
        cout << "Test 3: " << (upper == 0 && lower == 3 && digit == 0 && space == 0 ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: " << upper << " " << lower << " " << digit << " " << space
             << " | Expected: 0 3 0 0" << endl;
    }

    // Test Case 4: Only digits
    // Manual verification: "98765"
    // 0 uppercase | 0 lowercase | 9,8,7,6,5 = 5 digits | 0 spaces
    {
        string input = "98765";
        int upper = 0, lower = 0, digit = 0, space = 0;
        problem1Solution(input, upper, lower, digit, space);
        cout << "Test 4: " << (upper == 0 && lower == 0 && digit == 5 && space == 0 ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: " << upper << " " << lower << " " << digit << " " << space
             << " | Expected: 0 0 5 0" << endl;
    }

    // Test Case 5: Empty string
    // Manual verification: ""
    // 0 of everything
    {
        string input = "";
        int upper = 0, lower = 0, digit = 0, space = 0;
        problem1Solution(input, upper, lower, digit, space);
        cout << "Test 5: " << (upper == 0 && lower == 0 && digit == 0 && space == 0 ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: " << upper << " " << lower << " " << digit << " " << space
             << " | Expected: 0 0 0 0" << endl;
    }

    // Test Case 6: Only spaces
    // Manual verification: "     " (5 spaces)
    // 0 uppercase | 0 lowercase | 0 digits | 5 spaces
    {
        string input = "     ";
        int upper = 0, lower = 0, digit = 0, space = 0;
        problem1Solution(input, upper, lower, digit, space);
        cout << "Test 6: " << (upper == 0 && lower == 0 && digit == 0 && space == 5 ? "PASS" : "FAIL")
             << " | Input: \"     \" | Got: " << upper << " " << lower << " " << digit << " " << space
             << " | Expected: 0 0 0 5" << endl;
    }

    // Test Case 7: Complex mix
    // Manual verification: "C++ 2024 Rocks!"
    // C,R = 2 uppercase | o,c,k,s = 4 lowercase | 2,0,2,4 = 4 digits | 2 spaces
    {
        string input = "C++ 2024 Rocks!";
        int upper = 0, lower = 0, digit = 0, space = 0;
        problem1Solution(input, upper, lower, digit, space);
        cout << "Test 7: " << (upper == 2 && lower == 4 && digit == 4 && space == 2 ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: " << upper << " " << lower << " " << digit << " " << space
             << " | Expected: 2 4 4 2" << endl;
    }

    // Test Case 8: Single character tests
    // Manual verification: "A"
    // A = 1 uppercase | 0 lowercase | 0 digits | 0 spaces
    {
        string input = "A";
        int upper = 0, lower = 0, digit = 0, space = 0;
        problem1Solution(input, upper, lower, digit, space);
        cout << "Test 8: " << (upper == 1 && lower == 0 && digit == 0 && space == 0 ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: " << upper << " " << lower << " " << digit << " " << space
             << " | Expected: 1 0 0 0" << endl;
    }
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Toggle Case ===" << endl;

    // Test Case 1: Mixed case with space
    // Manual verification: "Hello World"
    // H->h, e->E, l->L, l->L, o->O, space, W->w, o->O, r->R, l->L, d->D
    // Result: "hELLO wORLD"
    {
        string input = "Hello World";
        string result = problem2Solution(input);
        string expected = "hELLO wORLD";
        cout << "Test 1: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 2: With digits and special chars
    // Manual verification: "C++ Programming 101"
    // C->c, +->+, +->+, space, P->p, r->R, o->O, g->G, r->R, a->A, m->M, m->M, i->I, n->N, g->G, space, 1->1, 0->0, 1->1
    // Result: "c++ pROGRAMMING 101"
    {
        string input = "C++ Programming 101";
        string result = problem2Solution(input);
        string expected = "c++ pROGRAMMING 101";
        cout << "Test 2: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 3: Only digits
    // Manual verification: "12345"
    // All digits remain: "12345"
    {
        string input = "12345";
        string result = problem2Solution(input);
        string expected = "12345";
        cout << "Test 3: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 4: All uppercase
    // Manual verification: "ABCXYZ"
    // A->a, B->b, C->c, X->x, Y->y, Z->z
    // Result: "abcxyz"
    {
        string input = "ABCXYZ";
        string result = problem2Solution(input);
        string expected = "abcxyz";
        cout << "Test 4: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 5: All lowercase
    // Manual verification: "abcxyz"
    // a->A, b->B, c->C, x->X, y->Y, z->Z
    // Result: "ABCXYZ"
    {
        string input = "abcxyz";
        string result = problem2Solution(input);
        string expected = "ABCXYZ";
        cout << "Test 5: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 6: Empty string
    // Manual verification: "" -> ""
    {
        string input = "";
        string result = problem2Solution(input);
        string expected = "";
        cout << "Test 6: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"\" | Got: \"" << result << "\" | Expected: \"\"" << endl;
    }

    // Test Case 7: Special characters only
    // Manual verification: "!@#$%^&*()"
    // All remain the same: "!@#$%^&*()"
    {
        string input = "!@#$%^&*()";
        string result = problem2Solution(input);
        string expected = "!@#$%^&*()";
        cout << "Test 7: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 8: Already toggled pattern
    // Manual verification: "aBcDeF"
    // a->A, B->b, c->C, D->d, e->E, F->f
    // Result: "AbCdEf"
    {
        string input = "aBcDeF";
        string result = problem2Solution(input);
        string expected = "AbCdEf";
        cout << "Test 8: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }
}

void testProblem3()
{
    cout << "\n=== Testing Problem 3: Remove Non-Alphanumeric and Convert ===" << endl;

    // Test Case 1: With punctuation
    // Manual verification: "Hello, World!"
    // Keep: H,e,l,l,o,W,o,r,l,d -> Convert to lower: h,e,l,l,o,w,o,r,l,d
    // Result: "helloworld"
    {
        string input = "Hello, World!";
        string result = problem3Solution(input);
        string expected = "helloworld";
        cout << "Test 1: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 2: With hyphens and digits
    // Manual verification: "A1B2-C3"
    // Keep: A,1,B,2,C,3 -> Convert letters to lower: a,1,b,2,c,3
    // Result: "a1b2c3"
    {
        string input = "A1B2-C3";
        string result = problem3Solution(input);
        string expected = "a1b2c3";
        cout << "Test 2: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 3: Only special characters
    // Manual verification: "!@#$%"
    // Keep: nothing
    // Result: ""
    {
        string input = "!@#$%";
        string result = problem3Solution(input);
        string expected = "";
        cout << "Test 3: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 4: Already clean and lowercase
    // Manual verification: "abc123"
    // Keep: a,b,c,1,2,3 -> Already lower: a,b,c,1,2,3
    // Result: "abc123"
    {
        string input = "abc123";
        string result = problem3Solution(input);
        string expected = "abc123";
        cout << "Test 4: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 5: Empty string
    // Manual verification: "" -> ""
    {
        string input = "";
        string result = problem3Solution(input);
        string expected = "";
        cout << "Test 5: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"\" | Got: \"" << result << "\" | Expected: \"\"" << endl;
    }

    // Test Case 6: Complex sentence
    // Manual verification: "C++ is Fun! 2024."
    // Keep: C,i,s,F,u,n,2,0,2,4 -> Convert: c,i,s,f,u,n,2,0,2,4
    // Result: "cisfun2024"
    {
        string input = "C++ is Fun! 2024.";
        string result = problem3Solution(input);
        string expected = "cisfun2024";
        cout << "Test 6: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 7: Only digits
    // Manual verification: "9876543210"
    // Keep: all digits (they are alphanumeric)
    // Result: "9876543210"
    {
        string input = "9876543210";
        string result = problem3Solution(input);
        string expected = "9876543210";
        cout << "Test 7: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 8: Spaces and tabs
    // Manual verification: "A B C   D"
    // Keep: A,B,C,D -> Convert: a,b,c,d
    // Result: "abcd"
    {
        string input = "A B C   D";
        string result = problem3Solution(input);
        string expected = "abcd";
        cout << "Test 8: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\" | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }
}

void testProblem4()
{
    cout << "\n=== Testing Problem 4: Caesar Cipher Encoder ===" << endl;

    // Test Case 1: Basic positive shift
    // Manual verification: "Hello", shift = 3
    // H(72) is uppercase, position 7 (H-A=7), (7+3)%26=10 -> K
    // e(101) is lowercase, position 4 (e-a=4), (4+3)%26=7 -> h
    // l(108) is lowercase, position 11 (l-a=11), (11+3)%26=14 -> o
    // l(108) is lowercase, position 11 (l-a=11), (11+3)%26=14 -> o
    // o(111) is lowercase, position 14 (o-a=14), (14+3)%26=17 -> r
    // Result: "Khoor"
    {
        string input = "Hello";
        int shift = 3;
        string result = problem4Solution(input, shift);
        string expected = "Khoor";
        cout << "Test 1: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\", shift=" << shift << " | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 2: Wrap around lowercase
    // Manual verification: "xyz", shift = 2
    // x position 23, (23+2)%26=25 -> z
    // y position 24, (24+2)%26=0 -> a (wraps)
    // z position 25, (25+2)%26=1 -> b (wraps)
    // Result: "zab"
    {
        string input = "xyz";
        int shift = 2;
        string result = problem4Solution(input, shift);
        string expected = "zab";
        cout << "Test 2: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\", shift=" << shift << " | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 3: Negative shift with wrap
    // Manual verification: "ABC", shift = -1
    // A position 0, (0-1+26)%26=25 -> Z (wraps)
    // B position 1, (1-1+26)%26=0 -> A
    // C position 2, (2-1+26)%26=1 -> B
    // Result: "ZAB"
    {
        string input = "ABC";
        int shift = -1;
        string result = problem4Solution(input, shift);
        string expected = "ZAB";
        cout << "Test 3: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\", shift=" << shift << " | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 4: No shift (shift = 0)
    // Manual verification: "Test123", shift = 0
    // No change: "Test123"
    {
        string input = "Test123";
        int shift = 0;
        string result = problem4Solution(input, shift);
        string expected = "Test123";
        cout << "Test 4: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\", shift=" << shift << " | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 5: Non-alphabetic characters
    // Manual verification: "Hello, World!", shift = 5
    // H(7) -> (7+5)%26=12 -> M
    // e(4) -> (4+5)%26=9 -> j
    // l(11) -> (11+5)%26=16 -> q
    // l(11) -> (11+5)%26=16 -> q
    // o(14) -> (14+5)%26=19 -> t
    // , stays ,
    // space stays space
    // W(22) -> (22+5)%26=1 -> B
    // o(14) -> (14+5)%26=19 -> t
    // r(17) -> (17+5)%26=22 -> w
    // l(11) -> (11+5)%26=16 -> q
    // d(3) -> (3+5)%26=8 -> i
    // ! stays !
    // Result: "Mjqqt, Btwqi!"
    {
        string input = "Hello, World!";
        int shift = 5;
        string result = problem4Solution(input, shift);
        string expected = "Mjqqt, Btwqi!";
        cout << "Test 5: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\", shift=" << shift << " | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 6: Large positive shift
    // Manual verification: "ABC", shift = 27 (equivalent to shift = 1 since 27%26=1)
    // A(0) -> (0+27)%26=1 -> B
    // B(1) -> (1+27)%26=2 -> C
    // C(2) -> (2+27)%26=3 -> D
    // Result: "BCD"
    {
        string input = "ABC";
        int shift = 27;
        string result = problem4Solution(input, shift);
        string expected = "BCD";
        cout << "Test 6: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\", shift=" << shift << " | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 7: Large negative shift
    // Manual verification: "abc", shift = -27 (equivalent to shift = -1 since -27%26=-1)
    // a(0) -> (0-27+26*2)%26=(0-27+52)%26=25 -> z
    // b(1) -> (1-27+26*2)%26=(1-27+52)%26=0 -> a
    // c(2) -> (2-27+26*2)%26=(2-27+52)%26=1 -> b
    // Result: "zab"
    {
        string input = "abc";
        int shift = -27;
        string result = problem4Solution(input, shift);
        string expected = "zab";
        cout << "Test 7: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"" << input << "\", shift=" << shift << " | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }

    // Test Case 8: Empty string
    // Manual verification: "", shift = 5
    // Result: ""
    {
        string input = "";
        int shift = 5;
        string result = problem4Solution(input, shift);
        string expected = "";
        cout << "Test 8: " << (result == expected ? "PASS" : "FAIL")
             << " | Input: \"\", shift=" << shift << " | Got: \"" << result << "\" | Expected: \"" << expected << "\"" << endl;
    }
}

int main()
{
    int choice;
    cout << "==============================================\n";
    cout << "  Character Manipulation Practice Problems\n";
    cout << "==============================================\n";
    cout << "Choose a problem to test (1-4) or 5 to test all:\n"
         << endl;
    cout << "1. Problem 1 (Easy) - Character Case Counter" << endl;
    cout << "2. Problem 2 (Easy) - Toggle Case" << endl;
    cout << "3. Problem 3 (Medium) - Remove Non-Alphanumeric" << endl;
    cout << "4. Problem 4 (Hard) - Caesar Cipher Encoder" << endl;
    cout << "5. Test All Problems" << endl;
    cout << "\nEnter your choice: ";
    cin >> choice;
    cin.ignore(); // Clear newline from input buffer

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