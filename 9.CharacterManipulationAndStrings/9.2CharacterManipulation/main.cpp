#include <iostream>
using namespace std;

int main(){ 

    //Check if character is alphanumeric
    
    cout << endl;
    cout << "isalnum : "<<endl;
	
    cout << "C is alphanumeric : " << isalnum('C') << endl;
    cout << "^ is alphanumeric : " << !isalnum('m') << endl;
	
	//Can use this as a test condition
	char input_char {'*'};
	if(isalnum(input_char)){
		cout << input_char << " is alhpanumeric." << endl;
	}else{
		cout << input_char <<  " is not alphanumeric." << endl;
	}
   

    //Check if character is alphabetic
    /*
    cout << endl;
    cout << "isalpha : "<<endl;
    cout <<   "C is alphabetic : " << isalpha('e') << endl; // 1
    cout <<   "^ is alphabetic : " << isalpha('^') << endl; // 0
    cout <<   "7 is alphabetic : " << isalpha('7') << endl; // 0

    if(isalpha('e')){
        cout << 'e' << " is alphabetic" << endl;
    }else{
        cout << 'e' << " is NOT alphabetic" << endl;        
    }
    */

	//Check if a character is blank
    /*
    cout << endl;
    cout << "isblank : "<<endl;
    char message[] {"Hello there. How are you doing? The sun is shining."};
    cout << "message : " << message << endl;
    
    //Find and print blank index
    size_t blank_count{};
    for (size_t i{0} ; i < size(message); ++i){
        //cout << "Value : " << message[i] << endl;
        if(isblank(message[i])){
            cout << "Found a blank character at index : [" << i << "]" << endl;
            ++blank_count;
        }
    }
    cout << "In total we found " << blank_count << " blank characters."<< endl;
   */

	//Check if character is lowercase or uppercase
    /*
    cout << "islower and isupper : "<<endl;

    cout << endl;
    char thought[] {"The C++ Programming Language is one of the most used on the Planet"};
    size_t lowercase_count{};
    size_t upppercase_count{};
    
    //Print original string for ease of comparison on the terminal
    cout << "Original string  : " << thought << endl;
    
    for( auto character : thought){
        if(islower(character)){
            cout <<" " << character;
            ++lowercase_count;
        }
        if(isupper(character)){
            ++upppercase_count;
        }
    }
    cout << endl;
    cout << "Found " << lowercase_count << " lowercase characters and "
                <<upppercase_count << " uppercase characters."<<  endl;
    */


    //Check if a character is a digit
    /*
    cout << endl;
    cout << "isdigit : "<<endl;

    char statement[] {"Mr Hamilton owns 221 cows. That's a lot of cows! The kid exclamed."};
	cout << "statement : " << statement << endl;
    
    size_t digit_count{};
    
    for(auto character : statement){
        if(isdigit(character)){
            cout << "Found digit : " << character << endl;
            ++digit_count;
        }
    }
    cout << "Found " << digit_count << " digits in the statement string" << endl;
    */

    //Turning a character to lowercase using the tolower() function
    cout << endl;
    cout << "tolwer and toupper: " << endl;
    char original_str[] {"Home. The feeling of belonging"};
    char dest_str[size(original_str)];
    
    //Turn this to uppercase. Change the array in place
    for(size_t i{}; i < size(original_str) ; ++i){
        dest_str[i] = toupper(original_str[i]);
    }
    
    cout << "Original string : " << original_str << endl;
    cout << "Uppercase string : " << dest_str << endl;
    
    //Turn this to lowercase. Change the array in place
    for(size_t i{}; i < size(original_str) ; ++i){
        dest_str[i] = tolower(original_str[i]);
    }
    
    cout << "Lowercase string : " << dest_str << endl;
    return 0;
}