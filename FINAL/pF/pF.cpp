#include <bits/stdc++.h>
using namespace std;

bool st(string a, string b){
    if(a.length() > b.length()){
        // cout << "A longer thaan b";
        return true;
    } else if (a.length() < b.length()){
        // cout << "B longer than a";
        return false;
    } else {
        for(int i = 0 ; i < a.length() ; i++){
            if(a[i]>b[i]){
                return true;
            }else{
                return false;
            }
        }
        return a>b;
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> p;
    for(int i = 0 ; i < n ; i++){
        string a;
        cin >> a;
        p.push_back(a);
    }
    sort(p.begin(), p.end(), st);
    for(int i = 0 ; i < n ; i++){
        cout << p[i] << endl;
    }
    return 0;
}