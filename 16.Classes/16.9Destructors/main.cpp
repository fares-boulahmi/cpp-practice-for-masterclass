#include <iostream>
#include <string_view>
using namespace std;

class Dog{
    public : 
        Dog() = default;
        Dog(string_view name_param, string_view breed_param, int  age_param);
        ~Dog();

    private : 
        string name;
        string breed;
        int * p_age{nullptr};
};
Dog::Dog(string_view name_param, string_view breed_param, int  age_param){
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    cout << "Dog constructor called for " << name << endl;
}

Dog::~Dog(){
    delete p_age;
    cout << "Dog destructor called for : " << name << endl;
}

void some_func(){
    Dog* p_dog = new Dog("Fluffy","Shepherd",2);

    delete p_dog;// Causes for the destructor of Dog to be called
}



int main(){ 

    some_func();
    

    cout << "Done!" << endl;
    return 0;
}