#include <string>
#include<vector>
using namespace std;
enum TextOperation { UPPERCASE, LOWERCASE, REVERSE, ENCRYPT };

string processText(const string& text, TextOperation op, int param);
string toUpperCase(const string& text);
string toLowerCase(const string& text);
string reverseText(const string& text);
string encryptCaesar(const string& text, int shift);
string chainOperations(const string& text, const vector<TextOperation>& ops, const vector<int>& params);
