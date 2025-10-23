#include <string>
#include <cctype>
#include <cstring>
using namespace std;
int countVowels(const string& str) {
    // TODO: Implement your solution here
    // Hint: Loop through string and check each character
    // Convert to lowercase for case-insensitive comparison
   char vowels []{"eoiauEAIUO"};
    int result = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (strchr(vowels , str[i]) != nullptr)
        {
            result++;
        }
        
    }
    
    return result;
}

string reverseString(const string& str) {
    // TODO: Implement your solution here
    // Hint: Create new string and build it backwards
    // Or use two-pointer approach
    string reverse{};
    for (int i = 0; i < str.size(); i++)
    {
        reverse.push_back(str[str.size() - i - 1]);
    }
    
    return reverse;
}

bool isPalindrome(const string& str) {
    // TODO: Implement your solution here
    // Hint: Compare characters from both ends moving inward
    // Convert to lowercase for case-insensitive comparison
    string palind{};
    for (int i = 0; i < str.size(); i++)
    {
        if (isalpha(str[i]))
        {
            palind.push_back(tolower(str[i]));
        }
        
    }
    for (int i = 0; i < palind.size() / 2; i++)
    {
        if (palind[i] != palind[palind.size() - i - 1])
        {
            return false;
        }
        
    }
    
    
    return true;
}
