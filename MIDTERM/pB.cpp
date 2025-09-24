#include <iostream>
using namespace std;
int main(){
    int n, m, k;
    // n days, a_i course, m, k days cotinous
    cin >> n >> m >> k;
    int a[9999];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    
    int ans = 0, temp;
    for(int i = 0 ; i < n ; i++){
        temp = 0;
        for(int j = i ; j < n; j++){
            if (a[j] > m){
                break;
            }
            temp++;
        }
        if(temp >= k){
            ans++;
        }
    }
    cout << ans;
}