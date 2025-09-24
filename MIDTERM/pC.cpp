#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    cin >> str;
    int length = str.length();
    for(int i = 0 ; i < length/2 ; i++){
        if (str[i] != str[length-i-1]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}