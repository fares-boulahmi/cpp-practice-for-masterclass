#include <iostream>
using namespace std;


int main(){

	int number1 {75};
    int number2 {60};
    bool result = (number1 < number2);//Expression yielding the condition
    
    /*
	
	cout << boolalpha << "result : " << result << endl; 
	
	cout << endl;
	cout << "free standing if statement" << endl;
   
    //if(result){
	if(result == true){
        cout << number1 << " is less than " << number2 << endl;
    }
    
    //if(!result){
	if(!(result == true)){
        cout << number1 << " is NOT less than " << number2 << endl;
    }

    */


   	//Using else
    /*
	cout << endl;
	cout << "using the else clause : " << endl;
	
	if(result == true){
        cout << number1 << " is less than " << number2 << endl;
    }else{
        cout << number1 << " is NOT less than " << number2 << endl;
    }
    */


	//Use expression as condition directly
    /*
	cout << endl;
	cout << "Using expression as condition : " << endl;
	
	if(number1 < number2){
        cout << number1 << " is less than " << number2 << endl;
    }else{
        cout << number1 << " is NOT less than " << number2 << endl;
    }
    */


	//Nesting if statements
	cout << endl;
	cout << "Nesting if statements" << endl;
	
    bool red = false;
    bool green {true};
    bool yellow {false};
    bool police_stop{true};
    
    /*
     *      If green : go
     *      If red, yellow : stop
     *      If green and police_stop : stop
     * */
     /*
     if(red){
         cout << "Stop" << endl;
     }
     if(yellow){
         cout << "Slow down" << endl;
     }
	 if(green){
		 cout << "Go" << endl;
	 }
     */

    /*
    cout << endl;
	 cout << "Police officer stops(verbose)" << endl;
	 if(green){
         if(police_stop){
             cout << "Stop" << endl;
         }
         else{
             cout << "Go" << endl;
         }

     }
     */


     cout << endl;
	 cout << "Police officer stops(less verbose)" << endl;
	 if(green && !police_stop){
         cout << "Go" << endl;
     }else{
         cout << "Stop" << endl;
     }


    

    return 0;
}