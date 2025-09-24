#include <iostream>
using namespace std;

int eor(int x, int y, int z){
    return ((x+y)|(y-z)|((x*z)-(y*z)));
}

int main(){
    int a, b, c, min = 99999999;
    // rebel, cherish, drip
    cin >> a >> b >> c;
    int anstype, temp;

    //   1,   2,   3,   4,   5,   6
    // abc, bac, acb, bca, cab, cba

    temp = eor(a,b,c);
    if(temp < min){
        anstype = 1;
        min = temp;
    }

    temp = eor(b,a,c);
    if(temp < min){
        anstype = 2;
        min = temp;
    }

    temp = eor(a,c,b);
    if(temp < min){
        anstype = 3;
        min = temp;
    }

    temp = eor(b,c,a);
    if(temp < min){
        anstype = 4;
        min = temp;
    }

    temp = eor(c,a,b);
    if(temp < min){
        anstype = 5;
        min = temp;
    }

    temp = eor(c,b,a);
    if(temp < min){
        anstype = 6;
        min = temp;
    }

    //   1,   2,   3,   4,   5,   6
    // abc, bac, acb, bca, cab, cba
    // a: REBEL HEART, b: Cherish, c: DRIP

    if (anstype == 6) cout << "DRIP\nCherish\nREBEL HEART";
    if (anstype == 5) cout << "DRIP\nREBEL HEART\nCherish";
    if (anstype == 4) cout << "Cherish\nDRIP\nREBEL HEART";
    if (anstype == 3) cout << "REBEL HEART\nDRIP\nCherish";
    if (anstype == 2) cout << "Cherish\nREBEL HEART\nDRIP";
    if (anstype == 1) cout << "REBEL HEART\nCherish\nDRIP";

    return 0;

}