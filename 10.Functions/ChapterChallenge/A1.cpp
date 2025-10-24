#include <string>
using namespace std;

// Problem A1: Foundation Integration - Memory Safe String Processor
// CONCEPTS: Function Declaration/Definition, Pass by Value, Pass by Pointer
//
// Create a function that processes C-strings and std::strings safely.
// The function should count vowels in a string, modify the original string
// to uppercase (only for C-strings passed by pointer), and return the vowel count.
//
// Examples:
// Input: "hello" (C-string) -> Output: 2, string becomes "HELLO"
// Input: "programming" (std::string) -> Output: 3, original unchanged
// Input: "" (empty) -> Output: 0
// Input: "AEIOU" -> Output: 5
//
// Requirements:
// - Create separate functions for C-string and std::string processing
// - C-string version modifies original via pointer
// - std::string version uses pass by value (no modification)
// - Handle null pointers safely
// - Count both uppercase and lowercase vowels
//
// Constraints:
// - String length: 0-1000 characters
// - Only consider A, E, I, O, U as vowels (case insensitive)
int processStringPointer(char* str) {
    return 0;
};
int processStringValue(string str) {
    return 0;
};