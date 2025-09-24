#include "pA.hpp"
#include <iostream>
using namespace std;

ExpectoPatronum::ExpectoPatronum() {
    string input = "";
    int total = 0;
    while(getline(cin, input)){
        if(input == ""){
            break;
        }
        total += 1;
    }
    num = total;
    return;
}