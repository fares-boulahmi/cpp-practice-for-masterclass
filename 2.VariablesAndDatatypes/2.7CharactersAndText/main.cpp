#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

void basicCharDemo() {
    cout << "=== Basic Char Demo ===" << endl;
    char character1 {'a'};
    char character2 {'r'};
    char character3 {'r'};
    char character4 {'o'};
    char character5 {'w'};
    
    cout << "Displaying characters one by one:" << endl;
    cout << character1 << endl;
    cout << character2 << endl;
    cout << character3 << endl;
    cout << character4 << endl;
    cout << character5 << endl;
    
    cout << "\nAs a word: " << character1 << character2 << character3 
         << character4 << character5 << endl;
    
    // One byte in memory : 2^8 = 256 different values (0 ~ 255)
    cout << "\nASCII value demonstration:" << endl;
    char value = 65; // ASCII character code for 'A'
    cout << "value : " << value << endl; // A
    cout << "value(int) : " << static_cast<int>(value) << endl;
    cout << "sizeof(char) : " << sizeof(char) << " byte" << endl;
}

void interactiveCharInput() {
    cout << "\n=== Interactive Char Input ===" << endl;
    char userChar;
    
    cout << "Enter a single character: ";
    cin >> userChar;
    
    cout << "You entered: '" << userChar << "'" << endl;
    cout << "ASCII value: " << static_cast<int>(userChar) << endl;
    cout << "Is uppercase? " << (isupper(userChar) ? "Yes" : "No") << endl;
    cout << "Is lowercase? " << (islower(userChar) ? "Yes" : "No") << endl;
    cout << "Is digit? " << (isdigit(userChar) ? "Yes" : "No") << endl;
    cout << "Is alphabetic? " << (isalpha(userChar) ? "Yes" : "No") << endl;
    
    if (isalpha(userChar)) {
        cout << "Uppercase version: " << static_cast<char>(toupper(userChar)) << endl;
        cout << "Lowercase version: " << static_cast<char>(tolower(userChar)) << endl;
    }
}

void charArrayDemo() {
    cout << "\n=== Char Array Demo ===" << endl;
    const int SIZE = 10;
    char charArray[SIZE];
    
    cout << "Enter " << SIZE << " characters (separated by spaces): ";
    for (int i = 0; i < SIZE; i++) {
        cin >> charArray[i];
    }
    
    cout << "You entered: ";
    for (int i = 0; i < SIZE; i++) {
        cout << charArray[i] << " ";
    }
    cout << endl;
    
    cout << "ASCII values: ";
    for (int i = 0; i < SIZE; i++) {
        cout << static_cast<int>(charArray[i]) << " ";
    }
    cout << endl;
    
    // Count different types
    int letters = 0, digits = 0, others = 0;
    for (int i = 0; i < SIZE; i++) {
        if (isalpha(charArray[i])) letters++;
        else if (isdigit(charArray[i])) digits++;
        else others++;
    }
    
    cout << "Statistics:" << endl;
    cout << "Letters: " << letters << endl;
    cout << "Digits: " << digits << endl;
    cout << "Others: " << others << endl;
}

void wordBuilding() {
    cout << "\n=== Word Building Exercise ===" << endl;
    int wordLength;
    
    cout << "How many characters for your word? ";
    cin >> wordLength;
    
    if (wordLength <= 0 || wordLength > 50) {
        cout << "Invalid length! Using default of 5." << endl;
        wordLength = 5;
    }
    
    vector<char> word(wordLength);
    
    cout << "Enter " << wordLength << " characters to build your word:" << endl;
    for (int i = 0; i < wordLength; i++) {
        cout << "Character " << (i + 1) << ": ";
        cin >> word[i];
    }
    
    cout << "\nYour word: ";
    for (char c : word) {
        cout << c;
    }
    cout << endl;
    
    cout << "ASCII breakdown: ";
    for (char c : word) {
        cout << static_cast<int>(c) << " ";
    }
    cout << endl;
}

void asciiExplorer() {
    cout << "\n=== ASCII Explorer ===" << endl;
    int asciiValue;
    
    cout << "Enter an ASCII value (0-127): ";
    cin >> asciiValue;
    
    if (asciiValue < 0 || asciiValue > 127) {
        cout << "Value out of range! Using 65 (A)" << endl;
        asciiValue = 65;
    }
    
    char character = static_cast<char>(asciiValue);
    
    cout << "ASCII " << asciiValue << " represents: ";
    if (asciiValue >= 32 && asciiValue <= 126) {
        cout << "'" << character << "'" << endl;
    } else {
        cout << "Non-printable character" << endl;
    }
    
    // Show some context
    cout << "Nearby characters:" << endl;
    for (int i = asciiValue - 2; i <= asciiValue + 2; i++) {
        if (i >= 32 && i <= 126) {
            cout << "ASCII " << i << ": '" << static_cast<char>(i) << "'" << endl;
        }
    }
}

void charArithmetic() {
    cout << "\n=== Character Arithmetic ===" << endl;
    char startChar;
    int offset;
    
    cout << "Enter a character: ";
    cin >> startChar;
    cout << "Enter an offset (+/-): ";
    cin >> offset;
    
    char resultChar = startChar + offset;
    
    cout << "'" << startChar << "' (ASCII " << static_cast<int>(startChar) << ")";
    cout << " + " << offset << " = ";
    cout << "'" << resultChar << "' (ASCII " << static_cast<int>(resultChar) << ")" << endl;
    
    // Alphabet shifting example
    if (isalpha(startChar)) {
        cout << "\nAlphabet examples:" << endl;
        for (int i = 1; i <= 5; i++) {
            char shifted = startChar + i;
            if (isalpha(shifted)) {
                cout << "'" << startChar << "' + " << i << " = '" << shifted << "'" << endl;
            }
        }
    }
}

void displayMenu() {
    cout << "\n======= Character Learning Menu =======" << endl;
    cout << "1. Basic char demonstration" << endl;
    cout << "2. Interactive char input" << endl;
    cout << "3. Character array demo" << endl;
    cout << "4. Word building exercise" << endl;
    cout << "5. ASCII explorer" << endl;
    cout << "6. Character arithmetic" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    bool continueProgram = true;
    
    cout << "Welcome to the Interactive Character Learning Program!" << endl;
    cout << "This program will help you understand chars in C++" << endl;
    
    while (continueProgram) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                basicCharDemo();
                break;
            case 2:
                interactiveCharInput();
                break;
            case 3:
                charArrayDemo();
                break;
            case 4:
                wordBuilding();
                break;
            case 5:
                asciiExplorer();
                break;
            case 6:
                charArithmetic();
                break;
            case 0:
                continueProgram = false;
                cout << "Thanks for learning about characters!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
        
        if (continueProgram) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }
    
    return 0;
}