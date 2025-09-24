#include <bits/stdc++.h>

using namespace std;

struct pixmap {
    int a;
    int b;

    pixmap(int a, int b): a(a), b(b){

    }

    pixmap(){

    }
};

int main(){
    int n;
    cin >> n;
    pixmap walk[n] = {};
    for(int i = 0 ; i< n ;i++){
        char input1;
        char inputDismiss;
        int num;
        cin >> input1 >> inputDismiss >> num;
        if(input1 < 'I'){
            walk[i] = pixmap(input1-'A'+1, num);
        } else {
            walk[i] = pixmap(input1-'A', num);
        }
        // cout << "Entered " << input1 << "," << num << ", Recognized as " << (input1-'A'+1) << "," << (num) << endl;
    }
    int map[19][19] = {0};
    for(int i = 0 ; i < n ; i++){
        if(i!=0){
            map[walk[i].a-1][walk[i].b-1] = i;
        } else {
            map[walk[i].a-1][walk[i].b-1] = -1;
        }
    }
    for(int i = 18 ; i >= 0 ; i--){
        for(int j = 0 ; j < 19 ; j++){
            if (map[j][i] > 0){
                cout << map[j][i]+1;
            } else if (map[j][i] == -1) {
                cout << "1";
            } else {
                cout << '-';
            }
        }
        cout << endl;
    }
    return 0;
}