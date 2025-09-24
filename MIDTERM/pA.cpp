#include <iostream>
using namespace std;
int main(){
    int n, m, t = 0;
    int a[1000];
    cin >> n >> m;
    // n km, m try
    for (int i = 0 ; i < m ; i++){
        cin >> a[i];
        t += a[i];
        if (t >= n){
            cout << i+1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}