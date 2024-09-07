#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>

using namespace std;

int main(){
    map<string, string> testMap;

    testMap["test"] = "test the map";
    testMap["test1"] = "test the map111";
    testMap["oke"] = "test the map123";

    for(const auto& [key, val] : testMap){
        if(key == "oke"){
            cout << val;
        }
    }
}