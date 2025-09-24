#include <iostream>
#include <vector>
#include <array>
using namespace std;
int main(){
    int n, temp;
    cin >> n;
    vector<int> a;
    array<int, 4000> b = {0};

    for(int i = 0 ; i < n ; i++){
        // a.push_back(rand()%1001);
        cin >> temp;
        a.push_back(temp);
    }

    // 3 DICES

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                b[a[i]+a[j]+a[k]]++;
            }
        }
    }

    temp = 0;

    for(int i = 0 ; i < 4000 ; i++){
        if(b[i]>0) {
            temp++;
            // cout << "b["<<i<<"] is "<< b[i]<<endl;
        }
    }

    cout << temp;
}