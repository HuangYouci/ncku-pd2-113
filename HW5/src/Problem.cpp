#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Problem.h"
#define red(text)    "\033[31m" text "\033[0m"
#define green(text)  "\033[32m" text "\033[0m"
#define yellow(text) "\033[33m" text "\033[0m"
#define blue(text)   "\033[34m" text "\033[0m"
#define magenta(text) "\033[35m" text "\033[0m"
#define cyan(text)   "\033[36m" text "\033[0m"
#define white(text)  "\033[37m" text "\033[0m"

Problem::Problem(std::string title, std::string input, std::string output, int magic_num) {
    problem_title = title;
    input_path = input;
    output_path = output;
    magic_number = magic_num;
}

void ProblemSystem::adding_problem(Problem new_problem) {
    this->problem_list.push_back(new_problem);
}

void ProblemSystem::init(std::string &PROBLEM_DATA_PATH) {
    std::ifstream file(PROBLEM_DATA_PATH);
    if (!file.is_open() ){
        std::cerr << "Error\n";
        std::cerr << "Please check your csv file in " << PROBLEM_DATA_PATH << "\n";
        exit(1);
    }

    std::string readline;
    while (getline(file, readline)){
        std::string title, input_path, output_path, magic_num;
        std::stringstream ss(readline);

        getline(ss, title, ',');
        getline(ss, input_path, ',');
        getline(ss, output_path, ',');
        getline(ss, magic_num);
        
        Problem new_problem(title, input_path, output_path, stoi(magic_num));
        ProblemSystem::adding_problem(new_problem);

        try { // update problem data
            std::ofstream info_out(PROBLEM_DATA_PATH);
            if( !info_out ) {
                throw std::runtime_error("Error: File does not exist - " + PROBLEM_DATA_PATH);
            }

            for( Problem problem : problem_list ) {
                info_out << problem.getTitle() << "," << problem.getInput() << "," << problem.getOutput() << "," << problem.getMagicNumber() << "\n";
            }

            info_out.close();
        }
        catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << "\n";
        }
    }
}
std::vector<Problem>* ProblemSystem::list_problem() {
    return &(this->problem_list);
}
void ProblemSystem::newproblem_set(std::string PROBLEM_DATA_PATH) {
    std::string new_title, new_input_path, new_output_path;
    int new_magic_number;
    std::cout << yellow("Please input the problem name: ");
    std::getline(std::cin, new_title);
    std::cout << "Ok! your problem name(title) is " << new_title << "\n";

    std::cout << yellow("Please input the input path(testcase): ");
    std::cin >> new_input_path;
    std::cout << "Ok! your input path is " << new_input_path << "\n";

    std::cout << yellow("Please input the output path(testcase): ");
    std::cin >> new_output_path;
    std::cout << "Ok! your output path is " << new_output_path << "\n";

    std::cout << yellow("Please input the magic number (for this problem): ");
    std::cin >> new_magic_number;

    Problem new_problem(new_title, new_input_path, new_output_path, new_magic_number);

    this->problem_list.push_back(new_problem);

}

void ProblemSystem::submitCode() {
    std::string problem_id;
    std::string user_code_path;

    std::cout << yellow("Please input the problem ID: ");
    std::getline(std::cin, problem_id);

    std::cout << yellow("Please input your code name: ");
    std::getline(std::cin, user_code_path);

    Problem *target_problem = nullptr;
    for (Problem &p : problem_list) {
        if (p.getTitle() == problem_id) {
            target_problem = &p;
            break;
        }
    }

    if (target_problem == nullptr) {
        std::cerr << red("Error: Problem with ID '" << problem_id << "' not found.\n");
        std::cout << "Judge result: Problem Not Found\n";
        exit(1);
    }

    const std::string executable_name = "user_executable";
    const std::string user_output_file = "user_output.txt";

    // 2. 編譯使用者程式
    std::cout << cyan("Compiling user code...\n");
    std::string compile_command = "g++ " + user_code_path + " -o " + executable_name;
    int compile_result = system(compile_command.c_str());

    if (compile_result != 0) {
        std::cout << red("Judge result: Compiler Error\n");
        exit(1);
    }
    std::cout << green("Compilation successful.\n");

    // 3. 讀取該題目的輸入，並丟給該使用者的程式，拿取輸出結果
    std::cout << cyan("Running user code...\n");
    // 修正點 1: 將輸入路徑拼接上 "input.txt"
    std::string run_command = "./" + executable_name + " < " + target_problem->getInput() + "/input.txt" + " > " + user_output_file;
    int run_result = system(run_command.c_str());

    if (run_result != 0) {
        std::cerr << yellow("Warning: User program exited with non-zero status. It might have crashed or returned an error.\n");
        // 這裡可以選擇性地判斷為 Runtime Error，而不是繼續比較
        // std::cout << red("Judge result: Runtime Error\n");
        // std::remove(executable_name.c_str());
        // std::remove(user_output_file.c_str());
        // exit(1);
    }

    // 4. 檢查輸出結果與該題正確答案是否一致
    std::cout << cyan("Comparing outputs...\n");
    std::ifstream user_output_stream(user_output_file);
    // 修正點 2: 將輸出路徑拼接上 "output.txt"
    std::ifstream correct_output_stream(target_problem->getOutput() + "/output.txt");

    if (!user_output_stream.is_open()) {
        std::cerr << red("Error: Could not open user output file: ") << user_output_file << "\n";
        std::cout << "Judge result: Internal Error (User output not found)\n";
        std::remove(executable_name.c_str());
        exit(1);
    }
    if (!correct_output_stream.is_open()) {
        // 修正錯誤訊息，顯示完整的正確答案檔案路徑
        std::cerr << red("Error: Could not open correct output file: ") << (target_problem->getOutput() + "/output.txt") << "\n";
        std::cout << "Judge result: Internal Error (Correct output not found)\n";
        std::remove(executable_name.c_str());
        std::remove(user_output_file.c_str());
        exit(1);
    }

    std::string user_line, correct_line;
    bool accepted = true;

    auto rtrim = [](std::string s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), s.end());
        return s;
    };

    while (std::getline(user_output_stream, user_line) && std::getline(correct_output_stream, correct_line)) {
        if (rtrim(user_line) != rtrim(correct_line)) {
            accepted = false;
            break;
        }
    }

    // 檢查是否有檔案未讀完，即行數不匹配
    if (std::getline(user_output_stream, user_line) || std::getline(correct_output_stream, correct_line)) {
        accepted = false; // 行數不匹配
    }

    user_output_stream.close();
    correct_output_stream.close();

    if (accepted) {
        std::cout << green("Judge result: Accepted\n");
    } else {
        std::cout << red("Judge result: Wrong Answer\n");
    }

    std::remove(executable_name.c_str());
    std::remove(user_output_file.c_str());

    exit(0);
}