#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "pC.hpp"
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<Reservation*> reservations;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<string> v;
        string temp;
        while( ss >> temp ) {
            v.push_back(temp);
        }
        
        if( v.size() == 4 ) {
            reservations.push_back(new VIPReservation(v[0], stoi(v[1]), v[2], v[3]));
        }
        else {
            reservations.push_back(new StandardReservation(v[0], stoi(v[1]), v[2]));
        }
    }
    
    sort(reservations.begin(), reservations.end(), cmp);
    for(int i = 0; i < reservations.size(); i++) {
        cout << reservations[i]->getDetails() << "\n";
    }
}
