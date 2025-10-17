#include <iostream>
#include <cstring>
using namespace std;

int main(){

	//Concatenation
    /*
	cout << endl;
	cout<< "strcat : " << endl;
	//doc : https://en.cppreference.com/w/cpp/string/byte/strcat
	
	char dest[50] = "Hello ";
    char src[50] = "World!";
    strcat(dest, src); // Some compilers (MSVC) think these functions are unsafe!
    cout << "dest : " << dest << endl; // Hello World
    strcat(dest, " Goodbye World!"); 
    cout << "dest : " << dest << endl; // Hello World Goodbye World!
    */


	//More concatenation
    /*
	cout << endl;
	cout << "More strcat : " << endl;
	
    char *dest1 = new char[30]{'F','i','r','e','l','o','r','d','\0'};
    char *source1 = 
        new char[30]{',','T','h','e',' ','P','h','e','n','i','x',' ','K','i','n','g','!','\0'};
		
	//NOTE TO SELF : 
			//Describe what's going to happen in strcat before you do the cat :
			//source is going to be appended to dest, and the process
			//will start by overriding the null character in dest
			
    cout << "strlen(dest1) :" << strlen(dest1) << endl;
    cout << "strlen(source1) : " << strlen(source1) << endl;
    
	cout << "Concatenating..." << endl;
    strcat(dest1,source1);
    
    cout << "strlen(dest1) :" << strlen(dest1) << endl;
    cout << "dest1 : " << dest1 << endl;
    */


    //strncat  : concatenates n characters from src to dest and
	//returns a pointer to the result string
    //signature : char *strncat( char *dest, const char *src, size_t count );
    /*
    cout << endl;
    cout << "strncat:" << endl;
    char dest2[50] { "Hello" };
    
    char source2[30] = {" There is a bird on my window"};
    
    //You can even use the returned pointer immediately for print out
    //This is a pattern you'll see a lot in C++ code out there.
    cout << strncat(dest2,source2,6) << endl;
    
    //Or you can do strncat separately and print dest2
    strncat(dest2,source2,6);
    cout << "The concatenated string is : " << dest2 << endl;
    */


    //strcpy - signature : char* strcpy( char* dest, const char* src );
    /*
    cout << endl;
	cout << "strcpy : " << endl;
    const char* source3 = "C++ is a multipurpose programming language.";
    char *dest3 = new char[strlen(source3) + 1];// +1 for the null character
													//Contains garbage data
													//Not initialized
													
    strcpy(dest3,source3);
    
    cout << "sizeof(dest3) : " << sizeof(dest3) << endl;
    cout << "strlen(dest3) : " << strlen(dest3) << endl;
    cout << "dest3 : " << dest3 << endl;
    */


    //strncpy : Copy n characters from src to dest -
    //signature : char *strncpy( char *dest, const char *src, size_t count );
	cout << endl;
    cout << "strncpy:" << endl;
    const char* source4 = "Hello";
    char dest4[] = {'a', 'b', 'c', 'd', 'e', 'f','\0'}; // Have to put the terminating
														//null char if we want to print
    
    cout << "dest4 : " << dest4 << endl;
    
	cout << "Copying..." << endl;
    strncpy(dest4,source4,5);
    
    cout << "dest4 : " << dest4 << endl;




 

    
    return 0;
}