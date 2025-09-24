#include <bits/stdc++.h>
using namespace std;

void easy(long long int u, long long int d){
    long long int l = 0;
    // 15/6
    while(u >= d){
        l++;
        u -= d;
    }
    // 3/6
    bool check = true;
    while(check){
        check = false;
        for(long long int i = 2 ; i <= u ; i++){
            if((u%i == 0)&(d%i==0)){
                check = true;
                u /= i;
                d /= i;
            }
        }
    }
    // Only 1
    if ( l > 0 && u > 0){
        cout << l << " " << u << "/" << d;
    } else if ( l == 0 && u > 0){
        cout << u << "/" << d;
    } else if ( l > 0 && u == 0){
        cout << l;
    }
    return;
}

int main(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<string> a, b;
    string temp;
    bool timetoB = false;
    char fuhow;
    while( ss >> temp ) {
        if (timetoB){
            b.push_back(temp);
        } else {
            if(temp == "+" || temp == "-" || temp == "*" || temp == "/"){
                fuhow = temp[0];
                timetoB = true;
                continue;
            }
            a.push_back(temp);
        }
    }
    // cout << "A:";
    // for(long long int i = 0 ; i < a.size() ; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl << "B:";
    // for(long long int i = 0 ; i < b.size() ; i++){
    //     cout << b[i] << " ";
    // }

    long long int aLF = 0;
    long long int aUP = 0;
    long long int aDW = 0;
    long long int bLF = 0;
    long long int bUP = 0;
    long long int bDW = 0;
    if(a.size() == 2){
        // LF
        for(long long int i = 0 ; i < a[0].size() ; i++){
            aLF *= 10;
            aLF += a[0][i] - '0';
        }
        // UP
        bool px = false;
        for(long long int i = 0 ; i < a[1].size() ; i++){
            if (px){
                aDW *= 10;
                aDW += a[1][i] - '0';
            } else {
                if(a[1][i] == '/'){
                    px = true;
                    continue;
                }
                aUP *= 10;
                aUP += a[1][i] - '0';
            }
        }
    } else {
        bool px = false;
        for(long long int i = 0 ; i < a[0].size() ; i++){
            if (px){
                aDW *= 10;
                aDW += a[0][i] - '0';
            } else {
                if(a[0][i] == '/'){
                    px = true;
                    continue;
                }
                aUP *= 10;
                aUP += a[0][i] - '0';
            }
        }
    }

    if(b.size() == 2){
        // LF
        for(long long int i = 0 ; i < b[0].size() ; i++){
            bLF *= 10;
            bLF += b[0][i] - '0';
        }
        // UP
        bool px = false;
        for(long long int i = 0 ; i < b[1].size() ; i++){
            if (px){
                bDW *= 10;
                bDW += b[1][i] - '0';
            } else {
                if(b[1][i] == '/'){
                    px = true;
                    continue;
                }
                bUP *= 10;
                bUP += b[1][i] - '0';
            }
        }
    } else {
        bool px = false;
        for(long long int i = 0 ; i < b[0].size() ; i++){
            if (px){
                bDW *= 10;
                bDW += b[0][i] - '0';
            } else {
                if(b[0][i] == '/'){
                    px = true;
                    continue;
                }
                bUP *= 10;
                bUP += b[0][i] - '0';
            }
        }
    }

    // cout << "A: " << aLF << " and " << aUP << "/" << aDW << endl;
    // cout << "B: " << bLF << " and " << bUP << "/" << bDW << endl;

    if(aLF > 0){
        cout << "A is a Mixed Fraction." << endl;
    } else if (aUP >= aDW) {
        cout << "A is a Improper Fraction." << endl;
    } else {
        cout << "A is a Proper Fraction." << endl;
    }

    if(bLF > 0){
        cout << "B is a Mixed Fraction." << endl;
    } else if (bUP >= bDW) {
        cout << "B is a Improper Fraction." << endl;
    } else {
        cout << "B is a Proper Fraction." << endl;
    }

    easy(aLF*aDW+aUP, aDW);
    cout << " " << fuhow << " ";
    easy(bLF*bDW+bUP, bDW);
    cout << endl;

    long long int resultUP = 0;
    long long int resultDW = 0;

    if (fuhow == '+'){
        // LEFT PLUS
        aUP += aLF*aDW;
        bUP += bLF*bDW;
        aLF = 0;
        bLF = 0;
        // TONGFEN
        resultDW = aDW*bDW;
        aUP *= bDW;
        bUP *= aDW;
        // PLUS
        resultUP = aUP+bUP;
    } else if (fuhow == '-'){
         // LEFT PLUS
        aUP += aLF*aDW;
        bUP += bLF*bDW;
        aLF = 0;
        bLF = 0;
        // TONGFEN
        resultDW = aDW*bDW;
        aUP *= bDW;
        bUP *= aDW;
        // PLUS
        resultUP = aUP-bUP;
    } else if (fuhow == '*'){
        aUP += aLF*aDW;
        bUP += bLF*bDW;

        resultDW = aDW * bDW;
        resultUP = aUP * bUP;
    } else if (fuhow == '/'){

        aUP += aLF*aDW;
        bUP += bLF*bDW;

        // cout << ": " << bUP << "/" << bDW << endl;

        long long int te;
        te = bUP;
        bUP = bDW;
        bDW = te;

        // cout << "! " << aUP << "/" << aDW << endl;
        // cout << ": " << bUP << "/" << bDW << endl;

        resultDW = aDW * bDW;
        resultUP = aUP * bUP;

        // cout << ":" << resultUP << "/" << resultDW << endl;
    }
    easy(resultUP, resultDW);
    cout << endl;
    return 0;
}