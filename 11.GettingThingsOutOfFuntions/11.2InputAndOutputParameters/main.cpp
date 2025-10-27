#include <iostream>
#include <string>
using namespace std;
void max_str(const string& input1, const string input2,
			string& output)
{
	if(input1 > input2){
		output = input1;
	}else{
		output = input2;
	}
}

void max_int( int input1, int input2,int& output){
	if(input1 > input2){
		output = input1;
	}else{
		output = input2;
	}
}

void max_double( double input1, double input2,double* output){
	if(input1 > input2){
		*output = input1;
	}else{
		*output = input2;
	}
}


int main(){

    /*
	string out_str;
	string string1("Cassablanca");
	string string2("Bellevue");

	max_str(string1,string2,out_str);
	cout << "max_str : " << out_str << endl;
    */

   /*
    int out_int;
    int in1{45};
    int in2{723};
    max_int(in1,in2,out_int);
    cout << "max_int : " << out_int << endl;
    */

   double out_double;
   double in_double1{45.8};
   double in_double2{76.9};
   max_double(in_double1,in_double2,&out_double);
   cout << "max_double : " << out_double << endl;
   
    return 0;
}