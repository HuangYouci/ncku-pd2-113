#include <iostream>
#include <vector>
#include "pB.hpp"
using namespace std;

int main() {
    int q;
    cin >> q;
    vector<GroupB> groups;
    while(q--) {
        int id;
        string name;
        cin >> id >> name;
        GroupB new_people(id, name);
        groups.push_back(new_people);
    }    

    for(int i=0;i<groups.size();i++) {
        if( groups[i].admin_check() == true) cout << 1 << "\n";
        else cout << 0 << "\n";
    }

    return 0;
}

