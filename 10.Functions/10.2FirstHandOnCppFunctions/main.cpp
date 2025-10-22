#include <iostream>
using namespace std;
//Function that takes a single parameter, and doesn't 
//give back the result explicitly
void enter_bar(size_t age){ // Functions parameters
    if( age > 18){
        cout << "You're " << age << " years old. Please proceed." << endl;
    }else{
        cout << "Sorry, you're too young for this. No offense! " << endl;
    }
    return ;
}


//Function that takes multiple parameters and returns the result of the computation
int max( int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

//Function that doesnt' take parameters and returns nothing
void say_hello(){
    cout << "Hello there" << endl;
    return; // You could omit this return statement for functions returning void
}


//Function that takes no parameters and return something
int lucky_number(){
    return 99;
}


//Parameters passed this way are scoped localy in the function.
//Changes to them are not visible outside the function. What we
//have inside the function are actually COPIES of the arguments
//passed to the function.
double increment_multiply( double a ,double b){
	
	cout << "Inside function , before increment : " << endl;
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
    
    double result = ((++a)  * (++b));
    
	cout << "Inside function , after increment : " << endl;
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
    
    //Returning the result
    return result;
}



int main(){
    //Calling enter_bar
    /*
    //enter_bar(22); // Function arguments
    //enter_bar(15);

    for(size_t i{1} ; i < 20 ; ++i){
        enter_bar(i);
    }
    */

   //Calling max
   /*
   int x{22};
   int y{44};
   int result = max(100,20); // Arguments
   result = max(x,y);
   cout << "max : " << result << endl;
   */
  

  //Calling say_hello
  /*
  say_hello();
  */

    //Calling lucy_number
    /*
    int result{};
    result = lucky_number();
    cout << "result : " << result << endl;
    */

    double h{3.00};
    double i{4.00};
							
	cout << "Outside function , before increment : " << endl;
	cout << "h : " << h << endl;
	cout << "i : " << i << endl;
    
    double incr_mult_result = increment_multiply(h,i);
    
	cout << "Outside function , before increment : " << endl;
	cout << "h : " << h << endl;
	cout << "i : " << i << endl;




  
    return 0;
}