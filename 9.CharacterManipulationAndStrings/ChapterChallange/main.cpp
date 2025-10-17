#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

//=== SECTION A: INTEGRATION PROBLEMS ===

// Problem A1: Foundation Integration - Password Validator
// Combines: character validation, C-string traversal, simple logic
// Create a function that validates if a C-string password is valid
// A valid password must have:
// - At least 1 uppercase letter
// - At least 1 lowercase letter
// - At least 1 digit
// - At least 1 special character (!@#$%^&*)
// - Minimum length of 8 characters
// Examples:
// Input: "Pass123!" → Output: true (has upper, lower, digit, special, length ≥ 8)
// Input: "pass123!" → Output: false (no uppercase)
// Input: "PASS123!" → Output: false (no lowercase)
// Constraints: C-string input, length up to 100 characters
 struct Pass
    {
        bool digist{};
        bool upper{};
        bool lower{};
        bool special{};
        bool length{};
    };
bool problemA1Solution(const char* password) {
    // TODO: Validate password using character manipulation
    // Hint: Use isdigit(), isupper(), islower() to check character types
    // Track which conditions are met, check string length
    int total = 0;
   
    Pass pass;
    for (int i = 0; i < strlen(password); i++)
    {
        total++;
        if (isdigit(password[i]))
        {
            pass.digist = true;
        } else if (isupper(password[i]))
        {
            pass.upper = true;
        } else if (islower(password[i]))
        {
            pass.lower = true;
        } else if (!isalnum(password[i]))
        {
            pass.special = true;
        }
    }
    if (total >= 8) pass.length = true;
    if (pass.digist && pass.length && pass.lower && pass.upper && pass.special)
    {
        return true ;
    } else {
        return false ;
    }    
}

// Problem A2: Intermediate Synthesis - String Encryption
// Combines: character manipulation, C-string iteration, numerical operations, conditionals
// Create a function that encrypts a string using Caesar cipher with variable shift
// - Shift only alphabetic characters (preserve case)
// - Leave digits and special characters unchanged
// - If shift goes past 'z' or 'Z', wrap around to 'a' or 'A'
// Examples:
// Input: "Hello123!", shift=3 → Output: "Khoor123!" (H→K, e→h, l→o, l→o, o→r)
// Input: "xyz", shift=3 → Output: "abc" (x→a, y→b, z→c with wraparound)
// Constraints: string length up to 200, shift 1-25
string problemA2Solution(string text, int shift) {
    // TODO: Encrypt string using Caesar cipher
    // Hint: Use isalpha() to check letters, isupper()/islower() for case
    // Handle wraparound: if char exceeds 'z', wrap to 'a' using modulo
      string result{};
    for (int i = 0; i < text.size(); i++)
    {
        if (isalpha(text[i]))
        {
            // convert all to upper for fix change 
            char conv = toupper(text[i]);
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
            if (islower(text[i])) {
                result.push_back(tolower(conv));
            } else if (isupper(text[i])) {
                result.push_back(toupper(conv));

            }
        }
        else
        {
            result.push_back(text[i]);
        }
    }

    return result;
    return "halo";
}

// Problem A3: Advanced Integration - Palindrome Analyzer
// Combines: string comparison, character case conversion, pointers/iteration, validation
// Create a function that checks if a string is a palindrome (ignoring spaces/punctuation)
// Only consider alphanumeric characters, ignore case
// Return: true if palindrome, false otherwise
// Examples:
// Input: "A man, a plan, a canal: Panama" → Output: true
// Input: "race a car" → Output: false
// Input: "Was it a car or a cat I saw?" → Output: true
// Constraints: string length up to 500, may contain mixed characters
bool problemA3Solution(const string& s) {
    // TODO: Check palindrome by filtering and comparing characters
    // Hint: Extract only alphanumeric chars, convert to lowercase, compare forward/backward
    return false ;
}

// Problem A4: Complex Synthesis - Text Word Counter and Analyzer
// Combines: C-string parsing, string manipulation, dynamic memory, character classification
// Create a function that counts words and returns frequency of each word (case-insensitive)
// Words separated by spaces/punctuation (!"'(),.:;?-\n)
// Return a vector of pairs: {word, frequency} sorted by frequency descending
// Examples:
// Input: "The quick brown fox jumps over the lazy dog. The fox is quick!"
// Output: {{"the", 2}, {"fox", 2}, {"quick", 2}, {"is", 1}, ...}
// Constraints: text up to 1000 chars, words up to 50 chars each
vector<pair<string, int>> problemA4Solution(const char* text) {
    // TODO: Parse text, count word frequencies, return sorted results
    // Hint: Use character classification to identify word boundaries
    // Convert each word to lowercase for comparison
    // Sort by frequency using custom comparator
    vector <pair<string , int>> result ;
    return result ;
}

// Problem A5: Mastery Challenge - Email Validator with Pattern Matching
// Combines: All string concepts, regex-like pattern validation, edge cases
// Validate email format: localpart@domain.extension
// Rules:
// - LocalPart: 1-64 alphanumeric + ._%+- (cannot start/end with dot, no consecutive dots)
// - Domain: 1-63 alphanumeric + hyphen (cannot start/end with hyphen)
// - Extension: 2-6 letters only
// Examples:
// Input: "user.name+tag@example.co.uk" → Output: true
// Input: "invalid..email@test.com" → Output: false (consecutive dots)
// Input: "test@domain" → Output: false (no extension)
// Constraints: email length up to 254 characters, strict RFC compliance
bool problemA5Solution(const string& email) {
    // TODO: Validate email with comprehensive pattern matching
    // Hint: Split on @ symbol, validate each component separately
    // Use character classification and boundary checks
    // Check for invalid character sequences
    return false;
}

// Problem A6: Expert Application - Text Compression with Run-Length Encoding
// Combines: All chapter concepts + pointers + dynamic memory + optimization
// Create a function that compresses text using run-length encoding:
// - Replace sequences of identical characters with character + count
// - If count is 1, just output the character
// - Handle special cases: spaces, newlines, and mixed case
// Examples:
// Input: "aaabbbcaa" → Output: "a3b3c1a2" (or "a3b3ca2" if count=1 omitted)
// Input: "Hello World!!!" → Output: "He1llo1 1Wo1rld1!3"
// Input: "aabbbaaa" → Output: "a2b3a3"
// Return original if compressed version is not shorter
// Return a pair: {compressed_string, was_compressed}
// Constraints: input up to 10000 characters, optimize for memory
pair<string, bool> problemA6Solution(const char* text) {
    // TODO: Implement run-length encoding compression
    // Hint: Iterate through string, count consecutive identical characters
    // Compare original vs compressed size, return if actually smaller
    // Consider performance with large strings
    pair<string , bool> result;
    return result;
}

//=== SECTION B: KNOWLEDGE VALIDATION QUIZ ===

void knowledgeQuiz() {
    cout << "\n=== CHAPTER 10 KNOWLEDGE QUIZ ===" << endl;
    cout << "Answer each question and test your understanding:" << endl << endl;

    int correctAnswers = 0;

    // Question 1
    cout << "Q1: What is the difference between a C-string and std::string?" << endl;
    cout << "A) C-strings use null terminator, std::string does not" << endl;
    cout << "B) C-strings are arrays of chars, std::string is a class with member functions" << endl;
    cout << "C) Both are identical in memory layout" << endl;
    cout << "D) C-strings are faster in all operations" << endl;
    cout << "Your answer (A/B/C/D): ";
    char ans1;
    cin >> ans1;
    if (ans1 == 'B' || ans1 == 'b') {
        cout << "✓ CORRECT! C-strings are char arrays terminated with '\\0', std::string is a class" << endl;
        cout << "   that manages its own memory and provides methods like length(), substr(), etc." << endl;
        correctAnswers++;
    } else {
        cout << "✗ INCORRECT. Correct Answer: B" << endl;
        cout << "   C-strings require manual null termination and offer no built-in functionality." << endl;
        cout << "   std::string handles this automatically and provides many utility functions." << endl;
    }
    cout << endl;

    // Question 2
    cout << "Q2: What does strlen() return for the string \"Hello\"?" << endl;
    cout << "A) 6 (including null terminator)" << endl;
    cout << "B) 5 (not including null terminator)" << endl;
    cout << "C) 5 (including null terminator)" << endl;
    cout << "D) 0 (null terminator position)" << endl;
    cout << "Your answer (A/B/C/D): ";
    char ans2;
    cin >> ans2;
    if (ans2 == 'B' || ans2 == 'b') {
        cout << "✓ CORRECT! strlen() returns 5 - it counts characters BEFORE null terminator." << endl;
        cout << "   The actual memory occupied is 6 bytes (5 chars + '\\0')" << endl;
        correctAnswers++;
    } else {
        cout << "✗ INCORRECT. Correct Answer: B" << endl;
        cout << "   strlen() specifically does NOT count the null terminator." << endl;
    }
    cout << endl;

    // Question 3
    cout << "Q3: What is the output of this code?" << endl;
    cout << "   char str[] = \"Hello\";" << endl;
    cout << "   str[0] = 'J';" << endl;
    cout << "   cout << str;" << endl;
    cout << "A) Hello (unchanged)" << endl;
    cout << "B) Jello" << endl;
    cout << "C) Compiler error - cannot modify char array" << endl;
    cout << "D) Runtime error - violates const correctness" << endl;
    cout << "Your answer (A/B/C/D): ";
    char ans3;
    cin >> ans3;
    if (ans3 == 'B' || ans3 == 'b') {
        cout << "✓ CORRECT! Arrays declared with [] are mutable, so modification is allowed." << endl;
        cout << "   Only char* to string literals are read-only." << endl;
        correctAnswers++;
    } else {
        cout << "✗ INCORRECT. Correct Answer: B" << endl;
        cout << "   char str[] creates a modifiable array, unlike string literals." << endl;
    }
    cout << endl;

    // Question 4
    cout << "Q4: What is a potential issue with strcpy()?" << endl;
    cout << "A) It's deprecated but still safe" << endl;
    cout << "B) It can cause buffer overflow if source is longer than destination" << endl;
    cout << "C) It only works with const strings" << endl;
    cout << "D) It allocates memory automatically" << endl;
    cout << "Your answer (A/B/C/D): ";
    char ans4;
    cin >> ans4;
    if (ans4 == 'B' || ans4 == 'b') {
        cout << "✓ CORRECT! strcpy() doesn't check bounds - if source is too large," << endl;
        cout << "   it overwrites adjacent memory. Use strncpy() or std::string instead." << endl;
        correctAnswers++;
    } else {
        cout << "✗ INCORRECT. Correct Answer: B" << endl;
        cout << "   This is why strcpy() is considered unsafe in production code." << endl;
    }
    cout << endl;

    // Question 5
    cout << "Q5: How many bytes does \"Hello\" occupy in a char array?" << endl;
    cout << "A) 5 bytes" << endl;
    cout << "B) 6 bytes" << endl;
    cout << "C) Depends on the compiler" << endl;
    cout << "D) 4 bytes (only English chars)" << endl;
    cout << "Your answer (A/B/C/D): ";
    char ans5;
    cin >> ans5;
    if (ans5 == 'B' || ans5 == 'b') {
        cout << "✓ CORRECT! Each character takes 1 byte, plus 1 byte for '\\0' = 6 total." << endl;
        correctAnswers++;
    } else {
        cout << "✗ INCORRECT. Correct Answer: B" << endl;
        cout << "   Always account for null terminator when calculating C-string size." << endl;
    }
    cout << endl;

    // Question 6
    cout << "Q6: What does isdigit('5') return?" << endl;
    cout << "A) true (or non-zero)" << endl;
    cout << "B) false (or zero)" << endl;
    cout << "C) The ASCII value of '5'" << endl;
    cout << "D) Compilation error" << endl;
    cout << "Your answer (A/B/C/D): ";
    char ans6;
    cin >> ans6;
    if (ans6 == 'A' || ans6 == 'a') {
        cout << "✓ CORRECT! isdigit() returns non-zero (true) for digits 0-9." << endl;
        correctAnswers++;
    } else {
        cout << "✗ INCORRECT. Correct Answer: A" << endl;
        cout << "   Character classification functions return non-zero for match, 0 for no match." << endl;
    }
    cout << endl;

    // Question 7
    cout << "Q7: What is the result of tolower('A')?" << endl;
    cout << "A) 'A' (unchanged)" << endl;
    cout << "B) 'a'" << endl;
    cout << "C) 97 (the ASCII value)" << endl;
    cout << "D) It doesn't compile" << endl;
    cout << "Your answer (A/B/C/D): ";
    char ans7;
    cin >> ans7;
    if (ans7 == 'B' || ans7 == 'b') {
        cout << "✓ CORRECT! tolower() converts to lowercase character 'a'." << endl;
        correctAnswers++;
    } else {
        cout << "✗ INCORRECT. Correct Answer: B" << endl;
        cout << "   Though tolower() returns int, it's the ASCII value of the lowercase char." << endl;
    }
    cout << endl;

    // Question 8
    cout << "Q8: What happens if you access index beyond string length?" << endl;
    cout << "A) Automatic bounds checking prevents it" << endl;
    cout << "B) Undefined behavior - may crash or access random memory" << endl;
    cout << "C) Returns an empty character automatically" << endl;
    cout << "D) Throws an exception" << endl;
    cout << "Your answer (A/B/C/D): ";
    char ans8;
    cin >> ans8;
    if (ans8 == 'B' || ans8 == 'b') {
        cout << "✓ CORRECT! C-strings have no bounds checking - accessing beyond array" << endl;
        cout << "   causes undefined behavior. Always check indices!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ INCORRECT. Correct Answer: B" << endl;
        cout << "   This is a major source of security vulnerabilities (buffer overflow)." << endl;
    }
    cout << endl;

    // Question 9
    cout << "Q9: Compare efficiency: char arr[1000] vs string s(1000)" << endl;
    cout << "A) Arrays are always faster" << endl;
    cout << "B) Strings are always faster" << endl;
    cout << "C) Arrays have fixed overhead, strings have slight overhead but more features" << endl;
    cout << "D) They have identical performance" << endl;
    cout << "Your answer (A/B/C/D): ";
    char ans9;
    cin >> ans9;
    if (ans9 == 'C' || ans9 == 'c') {
        cout << "✓ CORRECT! Raw arrays are slightly faster but strings provide safety." << endl;
        cout << "   Modern compilers optimize both very similarly." << endl;
        correctAnswers++;
    } else {
        cout << "✗ INCORRECT. Correct Answer: C" << endl;
        cout << "   For most applications, use std::string - premature optimization is bad." << endl;
    }
    cout << endl;

    // Question 10
    cout << "Q10: What is strcat(\"Hello\", \" World\") supposed to do?" << endl;
    cout << "A) Create and return a new string \"Hello World\"" << endl;
    cout << "B) Concatenate and modify first argument in-place" << endl;
    cout << "C) Return true/false indicating success" << endl;
    cout << "D) It's not a valid C function" << endl;
    cout << "Your answer (A/B/C/D): ";
    char ans10;
    cin >> ans10;
    if (ans10 == 'B' || ans10 == 'b') {
        cout << "✓ CORRECT! strcat() modifies the first C-string in-place." << endl;
        cout << "   The first argument must have enough space - another buffer overflow risk!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ INCORRECT. Correct Answer: B" << endl;
        cout << "   This is why std::string += is safer - automatic resizing." << endl;
    }
    cout << endl;

    // Question 11
    cout << "Q11: What does s.find(\"ll\") return for s = \"Hello\"?" << endl;
    cout << "A) true" << endl;
    cout << "B) 2" << endl;
    cout << "C) 1" << endl;
    cout << "D) -1" << endl;
    cout << "Your answer (A/B/C/D): ";
    char ans11;
    cin >> ans11;
    if (ans11 == 'B' || ans11 == 'b') {
        cout << "✓ CORRECT! find() returns the starting index (0-based): H(0)e(1)l(2)l(3)o(4)" << endl;
        cout << "   The substring \"ll\" starts at index 2." << endl;
        correctAnswers++;
    } else {
        cout << "✗ INCORRECT. Correct Answer: B" << endl;
        cout << "   find() returns size_t (index), not boolean. Returns string::npos if not found." << endl;
    }
    cout << endl;

    // Question 12
    cout << "Q12: What is the difference between char* and string&?" << endl;
    cout << "A) They're the same thing" << endl;
    cout << "B) char* is C-string (pointer), string& is reference to std::string object" << endl;
    cout << "C) char* is always safer" << endl;
    cout << "D) string& is from older C++ standards" << endl;
    cout << "Your answer (A/B/C/D): ";
    char ans12;
    cin >> ans12;
    if (ans12 == 'B' || ans12 == 'b') {
        cout << "✓ CORRECT! They're fundamentally different: C-string (char array) vs" << endl;
        cout << "   std::string (class). References avoid copying large strings efficiently." << endl;
        correctAnswers++;
    } else {
        cout << "✗ INCORRECT. Correct Answer: B" << endl;
        cout << "   Understanding this distinction is crucial for modern C++ programming." << endl;
    }
    cout << endl;

    // Question 13
    cout << "Q13: What is undefined behavior?" << endl;
    cout << "A) An error the compiler will catch" << endl;
    cout << "B) Runtime behavior that is not defined by C++ standard - may crash/produce" << endl;
    cout << "   unpredictable results" << endl;
    cout << "C) A warning the compiler issues" << endl;
    cout << "D) Code that will never execute" << endl;
    cout << "Your answer (A/B/C/D): ";
    char ans13;
    cin >> ans13;
    if (ans13 == 'B' || ans13 == 'b') {
        cout << "✓ CORRECT! UB is the most dangerous category - compiler makes no promises." << endl;
        cout << "   Buffer overflow, null pointer dereference, etc. are UB." << endl;
        correctAnswers++;
    } else {
        cout << "✗ INCORRECT. Correct Answer: B" << endl;
        cout << "   Always be aware of potential UB in your code - use tools like sanitizers." << endl;
    }
    cout << endl;

    // Question 14
    cout << "Q14: When using C-string functions, what must you always check?" << endl;
    cout << "A) That the string is alphabetically sorted" << endl;
    cout << "B) That buffers are large enough and loops terminate correctly" << endl;
    cout << "C) That the string contains no digits" << endl;
    cout << "D) That the pointer points to an odd address" << endl;
    cout << "Your answer (A/B/C/D): ";
    char ans14;
    cin >> ans14;
    if (ans14 == 'B' || ans14 == 'b') {
        cout << "✓ CORRECT! Manual bounds checking is critical - the compiler won't do it!" << endl;
        correctAnswers++;
    } else {
        cout << "✗ INCORRECT. Correct Answer: B" << endl;
        cout << "   This is the #1 reason to prefer std::string in modern code." << endl;
    }
    cout << endl;

    // Question 15
    cout << "Q15: What is the relationship between Chapter 10 (Strings) and previous" << endl;
    cout << "    chapters (pointers, arrays, data types)?" << endl;
    cout << "A) No relationship - strings are an isolated topic" << endl;
    cout << "B) Strings build on pointers and arrays; C-strings are char* arrays," << endl;
    cout << "   character types from Ch3, pointer/memory concepts from Ch8" << endl;
    cout << "C) Strings replace arrays and pointers completely" << endl;
    cout << "D) Chapter 10 is independent and can be skipped" << endl;
    cout << "Your answer (A/B/C/D): ";
    char ans15;
    cin >> ans15;
    if (ans15 == 'B' || ans15 == 'b') {
        cout << "✓ CORRECT! String concepts integrate many previous chapters:" << endl;
        cout << "   - Arrays (Ch7): C-strings are char arrays" << endl;
        cout << "   - Pointers (Ch8): char* and memory management" << endl;
        cout << "   - Data types (Ch3): character types and their operations" << endl;
        cout << "   - Loops (Ch6): iterating through strings" << endl;
        correctAnswers++;
    } else {
        cout << "✗ INCORRECT. Correct Answer: B" << endl;
        cout << "   Mastery requires understanding how concepts interconnect!" << endl;
    }
    cout << endl;

    cout << "=== QUIZ COMPLETE ===" << endl;
    cout << "Your Score: " << correctAnswers << "/15" << endl;
    if (correctAnswers >= 13) cout << "Excellent - Chapter mastery achieved!" << endl;
    else if (correctAnswers >= 10) cout << "Good - Review tricky areas before advanced topics" << endl;
    else if (correctAnswers >= 7) cout << "Fair - Recommend reviewing core concepts" << endl;
    else cout << "Needs improvement - Review chapter material thoroughly" << endl;
    cout << endl;
}

//=== MANDATORY COMPLETE TEST FUNCTIONS ===

void testProblemA1() {
    cout << "\nTesting Problem A1 - Foundation Integration (Password Validator)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Valid password with all requirements
    // Manual calculation: "Pass123!"
    // P = uppercase ✓, a,s,s = lowercase ✓, 1,2,3 = digits ✓, ! = special ✓, length = 8 ✓
    // Expected: true
    total++;
    const char* pwd1 = "Pass123!";
    bool result1 = problemA1Solution(pwd1);
    if (result1 == true) {
        cout << "Test 1 (Valid password): PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: true, Got: " << (result1 ? "true" : "false") << endl;
    }

    // Test Case 2: Missing uppercase
    // Manual: "pass123!" - no uppercase letter
    // Expected: false
    total++;
    const char* pwd2 = "pass123!";
    bool result2 = problemA1Solution(pwd2);
    if (result2 == false) {
        cout << "Test 2 (Missing uppercase): PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: false, Got: " << (result2 ? "true" : "false") << endl;
    }

    // Test Case 3: Missing lowercase
    // Manual: "PASS123!" - no lowercase letter
    // Expected: false
    total++;
    const char* pwd3 = "PASS123!";
    bool result3 = problemA1Solution(pwd3);
    if (result3 == false) {
        cout << "Test 3 (Missing lowercase): PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: false, Got: " << (result3 ? "true" : "false") << endl;
    }

    // Test Case 4: Missing digit
    // Manual: "PassWord!" - no digits
    // Expected: false
    total++;
    const char* pwd4 = "PassWord!";
    bool result4 = problemA1Solution(pwd4);
    if (result4 == false) {
        cout << "Test 4 (Missing digit): PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: false, Got: " << (result4 ? "true" : "false") << endl;
    }

    // Test Case 5: Missing special character
    // Manual: "Pass1234" - no special character (!@#$%^&*)
    // Expected: false
    total++;
    const char* pwd5 = "Pass1234";
    bool result5 = problemA1Solution(pwd5);
    if (result5 == false) {
        cout << "Test 5 (Missing special): PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: false, Got: " << (result5 ? "true" : "false") << endl;
    }

    // Test Case 6: Too short
    // Manual: "Pass1!" - length = 6 < 8
    // Expected: false
    total++;
    const char* pwd6 = "Pass1!";
    bool result6 = problemA1Solution(pwd6);
    if (result6 == false) {
        cout << "Test 6 (Too short): PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: false, Got: " << (result6 ? "true" : "false") << endl;
    }

    // Test Case 7: Valid with different special chars
    // Manual: "MyPass@99" - M=upper, y,a,s,s=lower, 9,9=digits, @=special, len=9≥8
    // Expected: true
    total++;
    const char* pwd7 = "MyPass@99";
    bool result7 = problemA1Solution(pwd7);
    if (result7 == true) {
        cout << "Test 7 (Different special char): PASS" << endl;
        passed++;
    } else {
        cout << "Test 7: FAIL - Expected: true, Got: " << (result7 ? "true" : "false") << endl;
    }

    cout << "Problem A1 Results: " << passed << "/" << total << " tests passed" << endl;
}

void testProblemA2() {
    cout << "\nTesting Problem A2 - Intermediate Synthesis (Caesar Cipher)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Basic encryption with shift 3
    // Manual: "Hello" with shift=3
    // H(ASCII 72) + 3 = K(75), e(101) + 3 = h(104), l + 3 = o, l + 3 = o, o + 3 = r
    // Expected: "Khoor"
    total++;
    string result1 = problemA2Solution("Hello", 3);
    if (result1 == "Khoor") {
        cout << "Test 1 (Basic encryption): PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: \"Khoor\", Got: \"" << result1 << "\"" << endl;
    }

    // Test Case 2: Wraparound from z to a
    // Manual: "xyz" with shift=3
    // x + 3 = a (24 + 3 = 27, mod 26 = 1 = 'a'), y + 3 = b, z + 3 = c
    // Expected: "abc"
    total++;
    string result2 = problemA2Solution("xyz", 3);
    if (result2 == "abc") {
        cout << "Test 2 (Lowercase wraparound): PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: \"abc\", Got: \"" << result2 << "\"" << endl;
    }

    // Test Case 3: Uppercase wraparound
    // Manual: "XYZ" with shift=3
    // X + 3 = A, Y + 3 = B, Z + 3 = C
    // Expected: "ABC"
    total++;
    string result3 = problemA2Solution("XYZ", 3);
    if (result3 == "ABC") {
        cout << "Test 3 (Uppercase wraparound): PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: \"ABC\", Got: \"" << result3 << "\"" << endl;
    }

    // Test Case 4: Mixed content - preserve digits and special chars
    // Manual: "Hello123!" with shift=3
    // "Khoor" + "123" + "!" = "Khoor123!"
    // Expected: "Khoor123!"
    total++;
    string result4 = problemA2Solution("Hello123!", 3);
    if (result4 == "Khoor123!") {
        cout << "Test 4 (Mixed content): PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: \"Khoor123!\", Got: \"" << result4 << "\"" << endl;
    }

    // Test Case 5: Shift of 1
    // Manual: "abc" with shift=1
    // a + 1 = b, b + 1 = c, c + 1 = d
    // Expected: "bcd"
    total++;
    string result5 = problemA2Solution("abc", 1);
    if (result5 == "bcd") {
        cout << "Test 5 (Shift of 1): PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: \"bcd\", Got: \"" << result5 << "\"" << endl;
    }

    // Test Case 6: Large shift (wrapping multiple times)
    // Manual: "abc" with shift=26 (full cycle, should return to same)
    // Expected: "abc"
    total++;
    string result6 = problemA2Solution("abc", 26);
    if (result6 == "abc") {
        cout << "Test 6 (Full rotation): PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: \"abc\", Got: \"" << result6 << "\"" << endl;
    }

    cout << "Problem A2 Results: " << passed << "/" << total << " tests passed" << endl;
}

void testProblemA3() {
    cout << "\nTesting Problem A3 - Advanced Integration (Palindrome Analyzer)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Simple palindrome
    // Manual: "racecar" - r,a,c,e,c,a,r reads same forwards and backwards
    // Expected: true
    total++;
    bool result1 = problemA3Solution("racecar");
    if (result1 == true) {
        cout << "Test 1 (Simple palindrome): PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: true, Got: " << (result1 ? "true" : "false") << endl;
    }

    // Test Case 2: Not a palindrome
    // Manual: "race a car" - filter to "raceacar" - r,a,c,e != r,a,c backwards
    // Expected: false
    total++;
    bool result2 = problemA3Solution("race a car");
    if (result2 == false) {
        cout << "Test 2 (Not palindrome): PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: false, Got: " << (result2 ? "true" : "false") << endl;
    }

    // Test Case 3: Palindrome with spaces and punctuation
    // Manual: "A man, a plan, a canal: Panama"
    // Filter: "amanaplanacanalpanama" (lowercase, no spaces/punctuation)
    // Reverse: "amanaplanacanalpanama" - SAME!
    // Expected: true
    total++;
    bool result3 = problemA3Solution("A man, a plan, a canal: Panama");
    if (result3 == true) {
        cout << "Test 3 (Complex palindrome with punctuation): PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: true, Got: " << (result3 ? "true" : "false") << endl;
    }

    // Test Case 4: Case-insensitive check
    // Manual: "Madam" - lowercase = "madam" - m,a,d,a,m (palindrome)
    // Expected: true
    total++;
    bool result4 = problemA3Solution("Madam");
    if (result4 == true) {
        cout << "Test 4 (Case insensitive): PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: true, Got: " << (result4 ? "true" : "false") << endl;
    }

    // Test Case 5: Single character
    // Manual: "a" - single char is always palindrome
    // Expected: true
    total++;
    bool result5 = problemA3Solution("a");
    if (result5 == true) {
        cout << "Test 5 (Single character): PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: true, Got: " << (result5 ? "true" : "false") << endl;
    }

    // Test Case 6: Only special characters
    // Manual: "!@#!@#" - no alphanumeric, filtered = empty string (or treated as palindrome)
    // Expected: true (empty string is palindrome)
    total++;
    bool result6 = problemA3Solution("!@#!@#");
    if (result6 == true) {
        cout << "Test 6 (Only special chars): PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: true, Got: " << (result6 ? "true" : "false") << endl;
    }

    // Test Case 7: Numbers included
    // Manual: "12321" - palindrome with digits
    // Expected: true
    total++;
    bool result7 = problemA3Solution("12321");
    if (result7 == true) {
        cout << "Test 7 (Palindrome with numbers): PASS" << endl;
        passed++;
    } else {
        cout << "Test 7: FAIL - Expected: true, Got: " << (result7 ? "true" : "false") << endl;
    }

    cout << "Problem A3 Results: " << passed << "/" << total << " tests passed" << endl;
}

void testProblemA4() {
    cout << "\nTesting Problem A4 - Complex Synthesis (Word Counter & Analyzer)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Simple word frequency
    // Manual: "the cat and the dog and the bird"
    // Words: the(3), and(2), cat(1), dog(1), bird(1)
    // Sorted by frequency descending: {the,3}, {and,2}, then others
    total++;
    vector<pair<string, int>> result1 = problemA4Solution("the cat and the dog and the bird");
    bool test1Pass = false;
    if (result1.size() >= 2 && result1[0].first == "the" && result1[0].second == 3 && 
        result1[1].first == "and" && result1[1].second == 2) {
        test1Pass = true;
        cout << "Test 1 (Basic frequency): PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected top: {the,3}, {and,2}, Got: ";
        if (!result1.empty()) cout << "{" << result1[0].first << "," << result1[0].second << "}" << endl;
        else cout << "empty" << endl;
    }

    // Test Case 2: Case insensitivity
    // Manual: "Hello hello HELLO" - all should be treated as "hello"
    // Expected: {hello, 3}
    total++;
    vector<pair<string, int>> result2 = problemA4Solution("Hello hello HELLO");
    if (!result2.empty() && result2[0].first == "hello" && result2[0].second == 3) {
        cout << "Test 2 (Case insensitivity): PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected {hello,3}, Got: ";
        if (!result2.empty()) cout << "{" << result2[0].first << "," << result2[0].second << "}" << endl;
        else cout << "empty" << endl;
    }

    // Test Case 3: Punctuation handling
    // Manual: "Hello, world! Hello." - punctuation removed
    // Words: hello(2), world(1)
    // Expected: {hello,2}, {world,1}
    total++;
    vector<pair<string, int>> result3 = problemA4Solution("Hello, world! Hello.");
    if (result3.size() >= 2 && result3[0].first == "hello" && result3[0].second == 2 &&
        result3[1].first == "world" && result3[1].second == 1) {
        cout << "Test 3 (Punctuation removal): PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected {hello,2}, {world,1}" << endl;
    }

    // Test Case 4: Empty string
    // Manual: "" - no words
    // Expected: empty vector
    total++;
    vector<pair<string, int>> result4 = problemA4Solution("");
    if (result4.empty()) {
        cout << "Test 4 (Empty input): PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected empty, Got: " << result4.size() << " entries" << endl;
    }

    // Test Case 5: Single word
    // Manual: "hello" - one word, frequency 1
    // Expected: {hello, 1}
    total++;
    vector<pair<string, int>> result5 = problemA4Solution("hello");
    if (!result5.empty() && result5[0].first == "hello" && result5[0].second == 1) {
        cout << "Test 5 (Single word): PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected {hello,1}" << endl;
    }

    // Test Case 6: Multiple spaces/special chars between words
    // Manual: "word...word--word" - all should be "word"
    // Expected: {word, 3}
    total++;
    vector<pair<string, int>> result6 = problemA4Solution("word...word--word");
    if (!result6.empty() && result6[0].first == "word" && result6[0].second == 3) {
        cout << "Test 6 (Multiple delimiters): PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected {word,3}" << endl;
    }

    cout << "Problem A4 Results: " << passed << "/" << total << " tests passed" << endl;
}

void testProblemA5() {
    cout << "\nTesting Problem A5 - Mastery Challenge (Email Validator)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Valid simple email
    // Manual: "user@example.com"
    // LocalPart: "user" (valid alphanumeric), Domain: "example" (valid), Extension: "com" (valid)
    // Expected: true
    total++;
    bool result1 = problemA5Solution("user@example.com");
    if (result1 == true) {
        cout << "Test 1 (Valid simple email): PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected: true, Got: " << (result1 ? "true" : "false") << endl;
    }

    // Test Case 2: Valid complex email with dots and plus
    // Manual: "user.name+tag@example.co.uk"
    // LocalPart: "user.name+tag" (dots allowed, plus allowed, not at start/end)
    // Domain: "example" (valid), Extension: "co.uk" - WAIT, only single extension allowed
    // This may fail - depends on interpretation. Assuming single extension "uk"
    total++;
    bool result2 = problemA5Solution("user.name+tag@example.uk");
    if (result2 == true) {
        cout << "Test 2 (Valid with special chars in local): PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected: true, Got: " << (result2 ? "true" : "false") << endl;
    }

    // Test Case 3: Consecutive dots (invalid)
    // Manual: "user..name@example.com" - consecutive dots in local part
    // Expected: false
    total++;
    bool result3 = problemA5Solution("user..name@example.com");
    if (result3 == false) {
        cout << "Test 3 (Consecutive dots): PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected: false, Got: " << (result3 ? "true" : "false") << endl;
    }

    // Test Case 4: Missing extension
    // Manual: "user@domain" - no extension
    // Expected: false
    total++;
    bool result4 = problemA5Solution("user@domain");
    if (result4 == false) {
        cout << "Test 4 (Missing extension): PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected: false, Got: " << (result4 ? "true" : "false") << endl;
    }

    // Test Case 5: No @ symbol
    // Manual: "userdomain.com" - missing @
    // Expected: false
    total++;
    bool result5 = problemA5Solution("userdomain.com");
    if (result5 == false) {
        cout << "Test 5 (No @ symbol): PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected: false, Got: " << (result5 ? "true" : "false") << endl;
    }

    // Test Case 6: Extension with numbers (invalid)
    // Manual: "user@domain.c0m" - extension has digit
    // Expected: false
    total++;
    bool result6 = problemA5Solution("user@domain.c0m");
    if (result6 == false) {
        cout << "Test 6 (Digit in extension): PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected: false, Got: " << (result6 ? "true" : "false") << endl;
    }

    // Test Case 7: Very long valid email (max local part 64, domain 63, extension 6)
    // Manual: "a@b.co" - minimum valid
    // Expected: true
    total++;
    bool result7 = problemA5Solution("a@b.co");
    if (result7 == true) {
        cout << "Test 7 (Minimal valid): PASS" << endl;
        passed++;
    } else {
        cout << "Test 7: FAIL - Expected: true, Got: " << (result7 ? "true" : "false") << endl;
    }

    cout << "Problem A5 Results: " << passed << "/" << total << " tests passed" << endl;
}

void testProblemA6() {
    cout << "\nTesting Problem A6 - Expert Application (Run-Length Encoding)..." << endl;
    int passed = 0, total = 0;

    // Test Case 1: Simple repetition
    // Manual: "aaabbbcaa"
    // Encoding: a appears 3 times, b appears 3 times, c appears 1 time, a appears 2 times
    // Compressed: "a3b3c1a2" (or "a3b3ca2" if 1s omitted)
    // Original: 9 bytes, Compressed: 8 bytes (including 1s) - should compress
    // Expected: {"a3b3c1a2", true} or similar
    total++;
    pair<string, bool> result1 = problemA6Solution("aaabbbcaa");
    if (result1.second == true && result1.first.length() <= 8) {
        cout << "Test 1 (Compressible): PASS" << endl;
        passed++;
    } else {
        cout << "Test 1: FAIL - Expected compression, Got: {\"" << result1.first << "\", " 
             << (result1.second ? "true" : "false") << "}" << endl;
    }

    // Test Case 2: No repetition - longer when compressed
    // Manual: "abcdefgh"
    // Encoding: "a1b1c1d1e1f1g1h1" (16 chars vs 8 original)
    // Should NOT compress
    // Expected: {"abcdefgh", false}
    total++;
    pair<string, bool> result2 = problemA6Solution("abcdefgh");
    if (result2.second == false) {
        cout << "Test 2 (Non-compressible): PASS" << endl;
        passed++;
    } else {
        cout << "Test 2: FAIL - Expected no compression, Got: {\"" << result2.first << "\", " 
             << (result2.second ? "true" : "false") << "}" << endl;
    }

    // Test Case 3: All same character
    // Manual: "aaaaa"
    // Encoding: "a5" (2 chars vs 5 original) - compresses
    // Expected: {"a5", true}
    total++;
    pair<string, bool> result3 = problemA6Solution("aaaaa");
    if (result3.second == true && result3.first == "a5") {
        cout << "Test 3 (All same char): PASS" << endl;
        passed++;
    } else {
        cout << "Test 3: FAIL - Expected {\"a5\", true}, Got: {\"" << result3.first << "\", " 
             << (result3.second ? "true" : "false") << "}" << endl;
    }

    // Test Case 4: Empty string
    // Manual: ""
    // Encoding: "" (both same size)
    // Expected: {"", false}
    total++;
    pair<string, bool> result4 = problemA6Solution("");
    if (result4.second == false || result4.first == "") {
        cout << "Test 4 (Empty string): PASS" << endl;
        passed++;
    } else {
        cout << "Test 4: FAIL - Expected empty/no compression" << endl;
    }

    // Test Case 5: Single character
    // Manual: "a"
    // Encoding: "a1" (2 chars vs 1 original) - doesn't compress
    // Expected: {"a", false}
    total++;
    pair<string, bool> result5 = problemA6Solution("a");
    if (result5.second == false) {
        cout << "Test 5 (Single character): PASS" << endl;
        passed++;
    } else {
        cout << "Test 5: FAIL - Expected no compression for single char" << endl;
    }

    // Test Case 6: Large run-length values
    // Manual: "aaaaaaaaaa" (10 a's)
    // Encoding: "a10" (3 chars vs 10 original) - compresses
    // Expected: {"a10", true}
    total++;
    pair<string, bool> result6 = problemA6Solution("aaaaaaaaaa");
    if (result6.second == true) {
        cout << "Test 6 (Large run-length): PASS" << endl;
        passed++;
    } else {
        cout << "Test 6: FAIL - Expected compression for repeated chars" << endl;
    }

    cout << "Problem A6 Results: " << passed << "/" << total << " tests passed" << endl;
}

void runAllTests() {
    cout << "\n" << string(60, '=') << endl;
    cout << "=== RUNNING ALL INTEGRATION PROBLEM TESTS ===" << endl;
    cout << string(60, '=') << endl;
    testProblemA1();
    testProblemA2();
    testProblemA3();
    testProblemA4();
    testProblemA5();
    testProblemA6();
    cout << string(60, '=') << endl;
    cout << "=== ALL TESTS COMPLETE ===" << endl;
    cout << string(60, '=') << endl;
}

int main() {
    cout << string(70, '=') << endl;
    cout << "    CHAPTER 10: COMPREHENSIVE CHARACTER & STRING ASSESSMENT" << endl;
    cout << string(70, '=') << endl << endl;

    cout << "This assessment covers:" << endl;
    cout << "- Character manipulation functions (isdigit, isupper, tolower, etc.)" << endl;
    cout << "- C-string operations (strcpy, strlen, strcat, etc.)" << endl;
    cout << "- std::string class and member functions" << endl;
    cout << "- String iteration, searching, and comparison" << endl;
    cout << "- Integration with previous chapters (pointers, arrays, memory)" << endl << endl;

    cout << "Choose your assessment mode:" << endl << endl;

    cout << "INTEGRATION PROBLEMS:" << endl;
    cout << "1. Problem A1 - Foundation Integration (Easy)" << endl;
    cout << "   Password Validator combining character checks and string validation" << endl;
    cout << "2. Problem A2 - Intermediate Synthesis (Easy-Medium)" << endl;
    cout << "   Caesar Cipher combining character manipulation and string iteration" << endl;
    cout << "3. Problem A3 - Advanced Integration (Medium)" << endl;
    cout << "   Palindrome Analyzer combining filtering, case conversion, and comparison" << endl;
    cout << "4. Problem A4 - Complex Synthesis (Medium-Hard)" << endl;
    cout << "   Word Counter combining parsing, hashing, and sorting" << endl;
    cout << "5. Problem A5 - Mastery Challenge (Hard)" << endl;
    cout << "   Email Validator combining pattern matching and boundary checking" << endl;
    cout << "6. Problem A6 - Expert Application (Very Hard)" << endl;
    cout << "   Run-Length Encoding combining compression and optimization" << endl;
    cout << "7. Test All Integration Problems" << endl << endl;

    cout << "KNOWLEDGE VALIDATION:" << endl;
    cout << "8. Chapter Knowledge Quiz (15 questions)" << endl << endl;

    cout << "COMPREHENSIVE ASSESSMENT:" << endl;
    cout << "9. Full Chapter Assessment (All problems + Quiz)" << endl << endl;

    int choice;
    cout << "Enter your choice (1-9): ";
    cin >> choice;
    cin.ignore();

    switch(choice) {
        case 1: testProblemA1(); break;
        case 2: testProblemA2(); break;
        case 3: testProblemA3(); break;
        case 4: testProblemA4(); break;
        case 5: testProblemA5(); break;
        case 6: testProblemA6(); break;
        case 7: runAllTests(); break;
        case 8: knowledgeQuiz(); break;
        case 9:
            runAllTests();
            knowledgeQuiz();
            break;
        default: cout << "Invalid choice! Please enter 1-9." << endl;
    }

    cout << endl;
    return 0;
}