#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool debug = false;

string toString(long long int i){
    long long int ii = i;
    long long int c = 0;
    string str;
    // cout << "Entered: " << i << endl;
    if(ii < 0){
        ii = abs(ii);
    }
    while(ii > 0){
        // cout << "ii is " << ii << endl;
    switch (ii%10){
        case 9:
            str.push_back('9');
            break;
        case 8:
            str.push_back('8');
            break;
        case 7:
            str.push_back('7');
            break;
        case 6:
            str.push_back('6');
            break;
        case 5:
            str.push_back('5');
            break;
        case 4:
            str.push_back('4');
            break;
        case 3:
            str.push_back('3');
            break;
        case 2:
            str.push_back('2');
            break;
        case 1:
            str.push_back('1');
            break;
        case 0:
            str.push_back('0');
            break;
    }
        ii /= 10;
        // cout << "ii isww " << ii << endl;
    }
    string strr = "";
    if(i < 0){
        strr.push_back('-');
    }
    for(long long int i = str.size()-1 ; i >=0 ; i--){
        strr.push_back(str[i]);
    }
    // cout << "Returned " << i << " to " << strr << endl; 
    return strr;
}

string simpfy(string in){
    long long int type = 0; //f,g,h
    long long int n[3] = {};
    long long int nC = 0;
    long long int wC = 0;
    long long int wL = 0;
    long long int answer = 0;
    bool caled = false;
    bool minus = false;
    for(long long int i = 0 ; i < in.size(); i++){
        if (debug) {
            cout << "Current running: in[" << i << "] is " << in[i] << endl;
            long long int tempDebug;
            cout << "Enter Any Number: ";
            cin >> tempDebug;
        }
        if(in[i] == 'f'){
            wC = 0;
            nC = 0;
            n[0] = 0;
            n[1] = 0;
            n[2] = 0;
            minus = false;
            type = 1;
        } else if (in[i] == 'g'){
            wC = 0;
            nC = 0;
            n[0] = 0;
            n[1] = 0;
            n[2] = 0;
            minus = false;
            type = 2;
        } else if (in[i] == 'h'){
            wC = 0;
            nC = 0;
            n[0] = 0;
            n[1] = 0;
            n[2] = 0;
            minus = false;
            type = 3;
        } else if (in[i] == '('){
            wC++;
            if (debug) {
                cout << "Starting Count WC: " << wC << endl;
            }
        } else if (in[i] == ')'){
            wL = i;
            wC++;
            caled = true;
            if (debug) {
                cout << "Start Cal, wC is " << wC << " wL is " << wL << endl;
            }
            if(type == 1){
                answer = 10*n[0] + 9*n[1] + n[2];
            } else if (type == 2){
                answer = 8*n[0] + 71;
            } else if (type == 3){
                answer = 4*n[0] - 7*n[1];
            }
            if (debug) {
                cout << "Breaked with answer: " << answer << endl;
            }
            // cout << "Breaked with answer: " << answer << endl;
            if(minus){
                answer = -answer;
            }
            break;
            // end, cal
        } else if (in[i] == ','){
            if(minus){
                n[nC] = -n[nC];
                minus = false;
            }
            wC++;
            nC++;
            if (debug) {
                cout << "wC: " << wC << "nC: " << nC << endl;
            }
        } else if (in[i] == '-'){
            wC++;
            minus = true;
        } else {
            // number
            wC++;
            n[nC] *= 10;
            n[nC] += in[i]-'0';

            if (debug) {
                cout << "n[" << nC << "] is now" << n[nC] << "and wC is " << wC << endl;
            }
        }
    }

    if (!caled){
        return in;
    }
    // cout << "wL: " << wL << ", wC: " << wC << endl;
    string r = "";
    for(long long int i = 0 ; i < in.size() ; i++){
        // cout << "i[" << i << "] is (" << in[i] << ") with " << r << endl;
        if (i == wL){
            // cout << "IS THE WORD LOCATION!" << endl;
            // cout << "Appended "  << toString(answer) << endl;
            r.append(toString(answer));
            // cout << "r Now: " << r << endl;
            continue;
        } else if(i >= wL-wC && i < wL){
            // cout << "IS THE WORD RANGE!" << endl;
            continue;
        }
        // cout << "Added " << in[i] << endl;
        r += in[i];
        // cout << "r Now: " << r << endl;
    }


    return r;
}

int main(){
    string in;
    cin >> in;

    string bin;
    string bout;
    bin = in;
    bout = in;
    while(true){
        bout = simpfy(bin);
            // cout << "NOW:" << bout << endl;
        if(bout == bin){
            cout << bout << endl;
            return 0;
        } else {
            bin = bout;
        }
    }
}