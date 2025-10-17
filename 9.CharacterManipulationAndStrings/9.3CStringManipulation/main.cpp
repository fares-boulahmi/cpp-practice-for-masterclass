#include <iostream>
#include <cstring>
using namespace std;

int main(){

    /*
	//strlen : Find the length of a string
    // real arrays and those decayed into pointers
    const char message1 [] {"The sky is blue."};
	
	//Array decays into pointer when we use const char*
	const char* message2 {"The sky is blue."};
    cout << "message1 : " << message1 << endl;
	
	//strlen ignores null character
    cout << "strlen(message1) : " << strlen(message1) << endl;
	
	// Includes the null character
    cout << "sizeof(message1) : " << sizeof(message1) << endl;
	
	//strlen still works with decayed arrays
	cout << "strlen(message2) : " << strlen(message2) << endl;
	
	//Prints size of pointer
    cout << "sizeof(message2) : " << sizeof(message2) << endl;
    */


   //strcmp - signature : int strcmp( const char *lhs, const char *rhs );
    //Returns negative value if lhs appears before rhs in lexicographical order,
    //Zero if lhs and rhs compare equal.
    //and Positive value if lhs appears after rhs in lexicographical order. 
    /*
    cout << endl;
    cout << "strcmp : " << endl;
    const char* string_data1{ "Alabama" };
    const char* string_data2{ "Blabama" };

    char string_data3[]{ "Alabama" };
    char string_data4[]{ "Blabama" };

    //Print out the comparison
    cout << "strcmp (" << string_data1 << "," << string_data2 << ") : "
        << strcmp(string_data1, string_data2) << endl;

    cout << "strcmp (" << string_data3 << "," << string_data4 << ") : "
        << strcmp(string_data3, string_data4) << endl;


    string_data1 = "Alabama";
    string_data2 = "Alabamb";

    //string_data3 = "Alabama";
    //string_data4 = "Alabamb";

    //Print out the comparison
    cout << "strcmp (" << string_data1 << "," << string_data2 << ") : "
        << strcmp(string_data1, string_data2) << endl;


        string_data1 = "Alacama";
    string_data2 = "Alabama";

    //Print out the comparison
    cout << "strcmp (" << string_data1 << "," << string_data2 << ") : "
        << strcmp(string_data1, string_data2) << endl;

    string_data1 = "India";
    string_data2 = "France";

    //Print out the comparison
    cout << "strcmp (" << string_data1 << "," << string_data2 << ") : "
        << strcmp(string_data1, string_data2) << endl;

    string_data1 = "Kigali";
    string_data2 = "Kigali";

    //Print out the comparison
    cout << "strcmp (" << string_data1 << "," << string_data2 << ") : "
        << strcmp(string_data1, string_data2) << endl;
    */


	//strncmp : int strncmp( const char *lhs, const char *rhs, size_t count );
	//Compares n characters in the strings
	//Returns : Negative value if lhs appears before rhs in lexicographical order.
    //Zero if lhs and rhs compare equal, or if count is zero.
    //Positive value if lhs appears after rhs in lexicographical order. 
    /*
    //Print out the comparison

    const char* string_data1{ "Alabama" };
    const char* string_data2{ "Blabama" };
    size_t n{3};
    cout << endl;
    cout << "strncmp : " << endl;
    cout << "strncmp (" << string_data1 << "," << string_data2 << "," << n << ") : " 
              << strncmp(string_data1,string_data2,n) << endl;
              
    string_data1 = "aaaia";
    string_data2 = "aaance";
    
    cout << "strncmp (" << string_data1 << "," << string_data2 << "," << n << ") : " 
              << strncmp(string_data1,string_data2,n) << endl;
              
              
    n = 5;
    
    cout << "strncmp (" << string_data1 << "," << string_data2 << "," << n << ") : " 
              << strncmp(string_data1,string_data2,n) << endl;
              
    string_data1 = "aaaoa";
    string_data2 = "aaance";
    
    
    cout << "strncmp (" << string_data1 << "," << string_data2 << "," << n << ") : " 
              << strncmp(string_data1,string_data2,n) << endl;
    */



    //Find the first occurrence of a character 
	//CODE STOLEN FROM THE DOCS : 
    /*
    cout << endl;
    cout << "strchr : " << endl;
	//doc : https://en.cppreference.com/w/cpp/string/byte/strchr
    
	//we use strchr to find all the characters one by one.

	const char * const str { "Try not. Do, or do not. There is no try."};
    //Can make this a const pointer to prevent users from making it point somewhere else
	char target = 'T';
	const char *result = str;
	size_t iterations{};
	
 
	while ((result = strchr(result, target)) != nullptr) {
		cout << "Found '" << target
				<< "' starting at '" << result << "'\n";
 
		// Increment result, otherwise we'll find target at the same location
		++result;
		++iterations;
	}
	cout << "iterations : " << iterations << endl;
    */


    //A lesser version that will loop 25 times
   /*  
	//Find the first occurrence of a character 
	//CODE STOLEN FROM THE DOCS : 
	cout << endl;
	cout << "strchr : " << endl;
	//doc : https://en.cppreference.com/w/cpp/string/byte/strchr

	//we use strchr to find all the characters one by one.

	const char* str{ "Try not. Do, or do not. There is no try." };
	char target = 'T';
	const char* result{ nullptr };
	size_t iterations{};
    // cout << "the str is : " << str << endl;
    // ++str;
    // cout << "the str after increase is : " << str << endl;

	while ((result = strchr(str, target)) != nullptr) {
		cout << "Found '" << target
			<< "' starting at '" << result << "'\n";
        // str = result; // this the correct line will make work as expected 

		// Increment result, otherwise we'll find target at the same location
		++str; // Making the pointer point to the next character
		++iterations;
	}

    // the iteration was 25 the reason is 
    // the second start search from ry not ..
    // third from y not ..
    // we increase the original pointer of char to search one by one not moved to after the char found 
	cout << "iterations : " << iterations << endl;
    */


	//Find last occurence
	//CODE STOLEN FROM THE DOCS : 
    cout << endl;
    cout << "strrchr : " << endl;
	//doc : https://en.cppreference.com/w/cpp/string/byte/strrchr
	
    char input[] = "/home/user/hello.cpp";
    char* output = strrchr(input, '/');
    if(output)
        cout << output+1 << endl; //+1 because we want to start printing past 
                                            // the character found by strrchr.
   
    return 0;
}