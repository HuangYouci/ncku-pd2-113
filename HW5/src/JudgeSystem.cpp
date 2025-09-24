#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <cctype>
#include <climits>
#include <thread>
#include "JudgeSystem.h"
#define red(text)    "\033[31m" text "\033[0m"
#define green(text)  "\033[32m" text "\033[0m"
#define yellow(text) "\033[33m" text "\033[0m"
#define blue(text)   "\033[34m" text "\033[0m"
#define magenta(text) "\033[35m" text "\033[0m"
#define cyan(text)   "\033[36m" text "\033[0m"
#define white(text)  "\033[37m" text "\033[0m"

void clearWindow() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    return;
}
JudgeSystem::JudgeSystem(std::string userPath, std::string problemPath, std::string msgPath, std::string version) {
    USER_DATA_PATH = userPath;
    PROBLEM_DATA_PATH = problemPath;
    LOGIN_MSG_PATH = msgPath;
    VERSION = version;
    status = "NOT READY";
}
void JudgeSystem::effectLoading(std::string content) {
    static const char* spinner[] = {"|", "/", "-", "\\"};
    for (int i = 0, j = 0; j < 20; j++) { 
        std::cout << "\033[33m" << content << "\033[0m" << spinner[i] << "\r";
        std::flush(std::cout);
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        i = ( i + 1 ) % 4;
    }
    return;
}
void JudgeSystem::loadData() {

    // Step1: Call AccountSystem::init with user data path
    AccountSystem::init(JudgeSystem::USER_DATA_PATH);
    JudgeSystem::effectLoading("Status - Loading user data...");
    std::cout << yellow("Status - Loading user data...") << green("OK!\n");

    // Step2: Call ProblemSystem::init with problem data path
    ProblemSystem::init(JudgeSystem::PROBLEM_DATA_PATH);
    JudgeSystem::effectLoading("Status - Loading problem data...");
    std::cout << yellow("Status - Loading problem data...") << green("OK!\n");

    // Step3: welcome the user
    try {
        std::ifstream inputFile("./msg/login.txt");
        if( !inputFile ) {
            throw std::runtime_error("Error: File does not exist - ./msg/login.tx");
        }

        std::string line;
        std::cout << "\033[36m";
        while (std::getline(inputFile, line)) {
            std::cout << line;
            std::cout << "\n";
        }
        inputFile.close(); 
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }

    return;
}
int JudgeSystem::mainPage() {

    if( JudgeSystem::status == "NOT READY" ) {
        loadData();
        JudgeSystem::status = "USER LOGIN";
        return 0;
    }
    if( JudgeSystem::status == "USER LOGIN" ) {
        std::pair<bool, std::string> user_info = AccountSystem::login();
        if( user_info.first == false ) return 0;
        JudgeSystem::status = "READY";
        return 0;
    }

    MainPage::mainpagePrint();
    int option = MainPage::operationCheck();
    clearWindow();
    switch (option) {
        case 1:
            std::cout << green("You are: ") << AccountSystem::getuserLogin() << "\n";
            break;
        case 2:
            std::cout << green("Judge Version: ") << VERSION << "\n";
            break;
        case 3:
        {
            std::cout << yellow("--- List of all problems ---\n");
            std::vector<Problem>* problems = this->list_problem(); // 呼叫 ProblemSystem 的 list_problem
            if (problems->empty()) {
                std::cout << red("No problems available.\n");
            } else {
                for (size_t i = 0; i < problems->size(); ++i) {
                    const Problem& p = (*problems)[i];
                    std::cout << green("Problem " << i + 1 << ": ")
                              << "Title: " << p.getTitle()
                              << ", Input: " << p.getInput()
                              << ", Output: " << p.getOutput()
                              << ", Magic: " << p.getMagicNumber() << "\n";
                }
            }
            std::cout << yellow("--------------------------\n");
            break;
        }
        case 4:
        {
            std::cout << yellow("--- Random problem selection ---\n");
            std::vector<Problem>* problems_rand = this->list_problem();
            if (problems_rand->empty()) {
                std::cout << red("No problems available for random selection.\n");
            } else {
                // 產生一個隨機索引
                int random_index = std::rand() % problems_rand->size();
                const Problem& p = (*problems_rand)[random_index];
                std::cout << green("Selected Problem: ")
                          << "Title: " << p.getTitle()
                          << ", Input: " << p.getInput()
                          << ", Output: " << p.getOutput()
                          << ", Magic: " << p.getMagicNumber() << "\n";
            }
            std::cout << yellow("--------------------------\n");
            break;
        }
        case 5:
            this->submitCode();
            break;
        case 6:
            if (AccountSystem::getuserLogin() == "admin") {
                this->newproblem_set(PROBLEM_DATA_PATH);
                std::cout << green("Admin: New problem added/updated successfully.\n");
            } else {
                std::cout << red("Permission denied. Only admin can add new problems.\n");
            }
            break;
        case 7:
            std::cout << yellow("Goodbye!\n");
            return 1;
        default:
            return 0;
    }

    return 0;
}