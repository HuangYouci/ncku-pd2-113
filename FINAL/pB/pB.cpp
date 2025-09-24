#include <iostream>
#include "pB.hpp"
using namespace std;
GroupB::GroupB(int id, std::string name) : GroupA(id, name) {
    id = id;
    name = name;
    int total = 0;
    for(int i = 0 ; i < name.length(); i++){
        total += name[i];
    }
    // cout << "Total is " << total << ", id: " << id << endl;
    if (total < id){
        is_admin = true;
    } else {
        is_admin = false;
    }
};

bool GroupB::admin_check() {
    return is_admin;
}

GroupA::GroupA(int id, std::string name){
    id = id;
    name = name;
};