#include <bits/stdc++.h>
using namespace std;

char numToChar(int n){
    switch (n){
        case 9:
            return '9';
            break;
        case 8:
            return '8';
            break;
        case 7:
            return '7';
            break;
        case 6:
            return '6';
            break;
        case 5:
            return '5';
            break;
        case 4:
            return '4';
            break;
        case 3:
            return '3';
            break;
        case 2:
            return '2';
            break;
        case 1:
            return '1';
            break;
        case 0:
            return '0';
            break;
    }
    return '0';
}

string nTimes(string in, int times){
    // cout << "Enter is " << in << "*" << times << endl;
    string r = "";
    int t[in.size()] = {};
    // v
    // 54645654754
    for(int i = 0 ; i < in.size() ; i++){
        t[i] = (in[i]-'0')*times;
        // cout << "t[" << i << "] is " << t[i] << endl;
    }
    for(int i = 0 ; i < in.size() ; i++){
        int ttt = t[i];
        string ttc = "";
        while(ttt > 10){
            ttc.push_back(numToChar(ttt%10)); //246436
            ttt/=10;
        }
        for(int w = ttc.size()-1 ; w >= 0 ; w--){
            r.push_back(numToChar(ttc[w]));
        }
    }
    return r;
}

int main(){
    cout << nTimes("6", 100);
}