#include <bits/stdc++.h>

using namespace std;

bool debug = false;

char numToChar(int n){
    switch (n){
        case 9:
            return '9';
            break;
        case 8:
            return '8';
            break;
        case 7:
            return '7';
            break;
        case 6:
            return '6';
            break;
        case 5:
            return '5';
            break;
        case 4:
            return '4';
            break;
        case 3:
            return '3';
            break;
        case 2:
            return '2';
            break;
        case 1:
            return '1';
            break;
        case 0:
            return '0';
            break;
    }
    return '0';
}

string snTimes(string input, int times){

    int isMinus = 0;
    if(input[0] == '-'){
        isMinus++;
        input[0] = '0';
    }
    if(times < 0){
        isMinus++;
        times = abs(times);
    }

    int cal[input.size()] = {};
    // vVvVv
    // 54645 * 9
    for(int i = 0 ; i < input.size() ; i++){
        cal[i] = ((input[i]-'0') * times);
    }

    if(debug){
        cout << "Entered: " << input << "*" << times << endl;
        for(int i = 0 ; i < input.size() ; i++){
            cout << "[" << cal[i] << "]";
        }
        cout << endl;
    }

    for(int i = input.size()-1 ; i > 0 ; i--){
        if(cal[i] > 10){
            cal[i-1] += cal[i]/10;
            cal[i] = cal[i]%10;
        }
    }

    if(debug){
        cout << "After Modify" << endl;
        for(int i = 0 ; i < input.size() ; i++){
            cout << "[" << cal[i] << "]";
        }
        cout << endl;
    }
    // return
    string r;
    if(isMinus%2==1){
        r.push_back('-');
    }
    for(int i = 0 ; i < input.size(); i++){
        if(cal[i]>=10){
            r.push_back(numToChar(cal[i]/10));
        }
        r.push_back(numToChar(cal[i]%10));
    }
    if(debug){
        cout << "Returned: " << r << endl;
    }
    return r;
}

string snAdd(string a, string b){
    // 12142345 -> 8
    //       13 -> 2

    bool aM = false;
    bool bM = false;

    if(a[0] == '-'){
        a[0] = '0';
        aM = true;
    }
    if(b[0] == '-'){
        b[0] = '0';
        bM = true;
    }

    int aLength = a.length();
    int bLength = b.length();

    int aCal[aLength] = {};
    int bCal[bLength] = {};
    int maxLength = max(aLength, bLength);

    if(debug){
        cout << "Entered a: " << a << ", b: " << b << endl;
        cout << "With aLength: " << aLength << ", bLength: " << bLength << ", max: " << maxLength << endl;
    }

    for(int i = 0 ; i < maxLength ; i++){
        aCal[i] = 0;
        bCal[i] = 0;
    }
    for(int i = maxLength-aLength, j = 0; i < maxLength; i++, j++){
        aCal[i] = a[j]-'0';
    }
    for(int i = maxLength-bLength, j = 0; i < maxLength ; i++, j++){
        bCal[i] = b[j]-'0';
    }

    if(debug){
        cout << "Entered: " << a << endl;
        for(int i = 0 ; i < maxLength ; i++){
            cout << "[" << aCal[i] << "]";
        }
        cout << endl;
    }

    if(debug){
        cout << "Entered: " << b << endl;
        for(int i = 0 ; i < maxLength ; i++){
            cout << "[" << bCal[i] << "]";
        }
        cout << endl;
    }

    int cal[maxLength] = {};

    // PLUS
    if (!aM && !bM){

        for(int i = 0 ; i < maxLength ; i++){
            cal[i] = aCal[i] + bCal[i];
        }

        if(debug){
            cout << endl << "Before Cal: " << endl;
            for(int i = 0 ; i < maxLength ; i++){
                cout << "[" << cal[i] << "]";
            }
            cout << endl;
        }

        for(int i = maxLength-1 ; i > 0 ; i--){
            if(cal[i] >= 10){
                cal[i-1] += cal[i]/10;
                cal[i] = cal[i]%10;
            }
        }

        if(debug){
            cout << "After Cal: " << endl;
            for(int i = 0 ; i < maxLength ; i++){
                cout << "[" << cal[i] << "]";
            }
            cout << endl;
        }

    }

    // return
    string r;
    for(int i = 0 ; i < maxLength; i++){
        if(cal[i]>=10){
            r.push_back(numToChar(cal[i]/10));
        }
        r.push_back(numToChar(cal[i]%10));
    }

    return r;
}

string process(string input){
    int rLocation = 0;
    int lLocationDiff = 0;
    int processType = 0; // f g h

    for(int i = 0 ; i < input.size() ; i++){
        if(input[i] == ')'){
            rLocation = i;
            break;
        }
    }

    if (debug){
        cout << "Input: " << input << ". rLocation: " << rLocation << endl;
    }

    // Check L Location and Type
    //          vvvvvvvV <- rLocation
    // lDiff is f(1,2,3)
    if(rLocation > 0){
        for(int i = rLocation-1; i > 0 ; i--){
            if(input[i] != '('){
                lLocationDiff++;
            } else {
                // Founded
                lLocationDiff += 2;
                if(input[i-1] == 'f'){
                    processType = 1;
                } else if (input[i-1] == 'g'){
                    processType = 2;
                } else {
                    processType = 3;
                }
                break;
            }
        }
    } else {
        return input;
    }

    if (debug){
        cout << "Input: " << input << ". lDiff: " << lLocationDiff << endl;
    }

    // Build Number
    string n[3] = {};
    int nCounter = 0;
    //   Start from here (rLocation - lLocationDiff +2)
    //   v
    // f(1,2,3)
    for(int i = rLocation - lLocationDiff + 2; i < rLocation ; i++){
        if(input[i] == ','){
            nCounter++;
            continue;
        }
        n[nCounter].push_back(input[i]);
    }

    if (debug){
        cout << "Input: " << input << ". n[0]: " << n[0] << endl;
        cout << "Input: " << input << ". n[1]: " << n[1] << endl;
        cout << "Input: " << input << ". n[2]: " << n[2] << endl;
    }

    // Compute
    // LEFT
    string left = "";
    for(int i = 0 ; i < rLocation - lLocationDiff ; i++){
        left.push_back(input[i]);
    }
    string right = "";
    for(int i = rLocation+1 ; i < input.size() ; i++){
        right.push_back(input[i]);
    }
    if (debug){
        cout << "Input: " << input << ". Left: " << left << endl;
        cout << "Input: " << input << ". Right: " << right << endl;
    }
    string answer = "";

    switch(processType){
        case 1: //f
        answer = snAdd(n[2], snAdd(snTimes(n[0], 10), snTimes(n[1], 9)));
        break;
        case 2: //h
        answer = snAdd("71", snTimes(n[0],8));
        break;
        case 3: //g
        answer = snAdd(snTimes(n[0],4),snTimes(n[1],-7));
        break;
    }

    return left+answer+right;
}

int main(){
    string input;
    cin >> input;

    string temp;
    while(true){
        temp = input;
        input = process(input);
        if(temp == input){
            cout << input << endl;
            return 0;
        }
    }
}