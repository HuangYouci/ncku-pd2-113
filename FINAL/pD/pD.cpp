#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; // n students, m knowledges
    cin >> n >> m;
    int h[m] = {};
    int a[n][m] = {};
    for(int i = 0 ; i < m ; i++){
        cin >> h[i];
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++){
        int upperTotal = 0; 
        int downerLeft = 0;
        int downerRight = 0;
        for(int j = 0 ; j < m ; j++){
            upperTotal += (h[j]*a[i][j]);
            downerLeft += (h[j]*h[j]);
            downerRight += (a[i][j]*a[i][j]);
        }
        long double answer = 0;
        answer = (upperTotal/(sqrt(downerLeft)*sqrt(downerRight)));
        answer*=100;
        int answerDisplay = answer;
        cout << answerDisplay/100 << "." << answerDisplay%100 << endl;
    }
    return 0;
}