#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{

    std::unordered_map<std::string, int> mp = {
        {"apple", 10},
        {"banana", 20}};

    mp["orange"] = 30;
    mp.size();
    // mp.erase("banana");
    std::string key = "banana";
    auto it = mp.find(key);
    if (it != mp.end())
    {
        std::cout << "Found " << mp.find(key)->first << " = " << mp["orange"] << std::endl;
    }
    else
    {
        std::cout << "Not found\n";
    }


    vector<int> arr = {4, 3, 5}; 
    


    return 0;
}
