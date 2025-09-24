#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Product {
    string name;
    int price;
    int count;
};

struct Record {
    string date;
    vector<Product> products;
};

struct User {
    string name;
    string birthday;
    vector<Record> records;
};

int main() {
    string command, pram1, pram2, pram4;
    int pram3;
    vector<User> user;
    while(cin >> command){
        if ( command.find("register") == 0 ){
            cin >> pram1 >> pram2;
            User tempUser;
            tempUser.name = pram1;
            tempUser.birthday = pram2;
            user.push_back(tempUser);
        } else if ( command.find("update") == 0 ){
            cin >> pram1 >> pram2;
            for(int i = 0; i < user.size() ; i++){
                if ( user[i].name == pram1 ) {
                    user[i].birthday = pram2;
                    break;
                }
            }
        } else if ( command.find ("search") == 0 ){
            cin >> pram1;
            bool notfound = true;
            for(int i = 0; i < user.size() ; i++){
                if ( user[i].name == pram1) {
                    cout << user[i].name << " " << user[i].birthday << endl;
                    notfound = false;
                    break;
                }
            }
            if (notfound) {
                cout << "USER NOT FOUND" << endl;
            }
        } else if ( command.find ("buy") == 0 ){
            cin >> pram1 >> pram2; // 1 Date, 2 Name
            cin >> pram3; // 3 Count
            Record tempRecord;
            tempRecord.date = pram1;
            bool notfound = true;
            for(int i = 0; i < user.size() ; i++){
                if ( user[i].name == pram2) {
                    for(int j = 0 ; j < pram3 ; j++){
                        Product tempProduct;
                        cin >> tempProduct.name >> tempProduct.price >> tempProduct.count;
                        tempRecord.products.push_back(tempProduct);
                    }
                    user[i].records.push_back(tempRecord);
                    notfound = false;
                    break;
                }
            }
            if (notfound) { cout << "USER NOT FOUND" << endl; }
        } else if ( command.find ("detail") == 0 ){
            cin >> pram1 >> pram3; // Name and Index
            for(int i = 0; i < user.size() ; i++){
                if ( user[i].name == pram1) { // Find User(user[i])
                    int totalCost = 0;
                    for(int j = 0 ; j < user[i].records[pram3].products.size() ; j++){
                        totalCost += user[i].records[pram3].products[j].price * user[i].records[pram3].products[j].count;
                    }
                    cout << user[i].records[pram3].date << " " << totalCost << endl;
                    for(int j = 0 ; j < user[i].records[pram3].products.size() ; j++){
                        cout << user[i].records[pram3].products[j].name << " " << user[i].records[pram3].products[j].price << " " << user[i].records[pram3].products[j].count << " " << user[i].records[pram3].products[j].price * user[i].records[pram3].products[j].count << endl;
                    }
                    break;
                }
            }
        } else if ( command.find ("summary") == 0 ){
            cin >> pram1;
            int totalCost = 0;
            bool notfound = true;
            for(int i = 0; i < user.size() ; i++){
                if ( user[i].name == pram1) { // find user
                    for(int j = 0 ; j < user[i].records.size() ; j++){ // records
                        for(int k = 0 ; k < user[i].records[j].products.size(); k++){
                            totalCost += user[i].records[j].products[k].count * user[i].records[j].products[k].price;
                        }
                    }
                    cout << user[i].records.size() << " " << totalCost << endl;
                    notfound = false;
                    break;
                }
            }
            if ( notfound ) { cout << "USER NOT FOUND" << endl; }
        }
    }
    return 0;
}