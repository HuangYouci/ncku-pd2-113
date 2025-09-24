#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>
#include "AccountSystem.h"
#define red(text)    "\033[31m" text "\033[0m"
#define green(text)  "\033[32m" text "\033[0m"
#define yellow(text) "\033[33m" text "\033[0m"
#define blue(text)   "\033[34m" text "\033[0m"
#define magenta(text) "\033[35m" text "\033[0m"
#define cyan(text)   "\033[36m" text "\033[0m"
#define white(text)  "\033[37m" text "\033[0m"

User* AccountSystem::search(std::string name) {
    for(size_t i=0;i<user_list.size();i++) {
        if (user_list[i].getUsername() == name){
            return &user_list[i];
        }
    }
    return nullptr;
}

void AccountSystem::init(std::string USER_DATA_PATH) {

    AccountSystem::USER_DATA_PATH = USER_DATA_PATH;

    try {

        std::ifstream file(USER_DATA_PATH); // 開啟檔案
        if( !file ) {
            throw std::runtime_error("Error: File does not exist - " + USER_DATA_PATH);
        }

        // TODO: Loading user data from USER_DATA_PATH and call adding_user (from AccountSystem) function to insert data
        // Hints: stringstream

        std::string read_line;
        while( getline(file, read_line) ) {
            std::string username, password;
            
            std::stringstream spilt(read_line);
            std::getline(spilt, username, ',');
            std::getline(spilt, password);
            
            AccountSystem::adding_user(username, password);
        }
        file.close();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }
}

void AccountSystem::sign_up() {
    std::string username, password, confirmPassword;
    int confirmTimes = 0;
    std::cout << cyan("You are now creating new user.") << std::endl;
    std::cout << yellow("Please enter your username: ");
    std::getline(std::cin, username);
    std::cout << yellow("Please enter your password: ");
    std::getline(std::cin, password);
    std::cout << yellow("Please confirm your password: ");
    std::getline(std::cin, confirmPassword);
    while(confirmPassword != password){
        if (confirmTimes > 1) {
            std::cout << red("Still not match, try another password.") << std::endl;
            std::cout << yellow("Please enter your password: ");
            std::getline(std::cin, password);
            confirmTimes = 0;
        }
        std::cout << red("Confirm password and password not match.") << std::endl;
        std::cout << yellow("Please confirm your password: ");
        std::getline(std::cin, confirmPassword);
        confirmTimes++;
    }
    std::cout << yellow("User added!") << std::endl;
    adding_user(username, password);
    userdataUpdate();
    return;
}

std::pair<bool, std::string> AccountSystem::login() {
    std::string username, password;
    int isPasswordCorrect = 0;
    std::cout << cyan("To sign up, type -1 in username field.") << std::endl;

    while(true){
        std::cout << yellow("User Name: ");
        std::getline(std::cin, username);

        if (username == "-1") {
            sign_up();
            continue;
        }

        User* user = AccountSystem::search(username);
        if (user == nullptr) {
            std::cout << red("Can not found user with that name, please try again.") << std::endl;
            continue;
        }

        while(true){
            std::cout << yellow("Password: ");
            std::getline(std::cin, password);
            if (user->getPassword() == password) {
                login_user = username;
                return std::make_pair(true, username);
            } else {
                isPasswordCorrect++;
                if (isPasswordCorrect > 2){
                    std::cout << red("Too many wrong attempts!") << std::endl;
                    isPasswordCorrect = 0;
                    break;
                } else {
                    std::cout << red("Wrong Password, please try again.") << std::endl;
                }
            }
        }
    }
}

void AccountSystem::adding_user(std::string username, std::string password) {
    User new_user(username, password);
    user_list.push_back(new_user);
    AccountSystem::userdataUpdate();
    return;
}

std::string AccountSystem::getuserLogin() {
    return login_user;
}

void AccountSystem::userdataUpdate() {
    try {
        std::ofstream info_out(AccountSystem::USER_DATA_PATH);
        if (!info_out) {
            throw std::runtime_error("Error: File does not exist - " + USER_DATA_PATH);
        }

        for (size_t i = 0; i < user_list.size(); i++) {
            info_out << user_list[i].getUsername() << "," << user_list[i].getPassword() << "\n";
        }

        info_out.close();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }
}