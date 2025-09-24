#include "UserInfo.hpp"
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_set>
#include <string>

bool Mansion::addUser(const UserInfo&, const std::string&) {
    return false;
}

int Mansion::printMagicNumber(int target){
    return 0;
}

int Mansion::printMagicNumber(){
    return 0;
}

UserInfo::UserInfo(std::string name, int id) : name(name), id(id) {}

bool UserManager::addUser(const UserInfo& user, const std::string& parent, const std::string& type) {
    if (type == "rongguo") {
        return RongGuoMansion::addUser(user, parent);
    } else if (type == "ningguo") {
        return NingGuoMansion::addUser(user, parent);
    }
    return false;
}

bool RongGuoMansion::addUser(const UserInfo& user, const std::string& parent) {
    if (parent == "root") {
        users.push_back(std::make_pair(user, UserInfo("", 0))); // UserInfo("", 0) 作為根節點的 parent 標記
        return true;
    } else {
        for (size_t i = 0; i < users.size(); ++i) {
            if (users[i].first.getName() == parent) {
                users.push_back(std::make_pair(user, users[i].first));
                return true;
            }
        }
        return false;
    }
}

bool NingGuoMansion::addUser(const UserInfo& user, const std::string& parent) {
    if (parent == "root") {
        users.push_back(std::make_pair(user, UserInfo("root", 0))); // UserInfo("", 0) 作為根節點的 parent 標記
        return true;
    } else {
        for (size_t i = 0; i < users.size(); ++i) {
            if (users[i].first.getName() == parent) {
                users.push_back(std::make_pair(user, users[i].first));
                return true;
            }
        }
        return false;
    }
}

int RongGuoMansion::printMagicNumber(int target) {
    std::vector<int> nums;
    for (size_t i = 0; i < users.size(); ++i) {
        nums.push_back(users[i].first.getId());
    }

    std::unordered_set<int> possibleSums;
    possibleSums.insert(0);

    for (size_t i = 0; i < nums.size(); ++i) {
        int current_num = nums[i];
        std::vector<int> currentSumsVec;
        for (int sum : possibleSums) {
            currentSumsVec.push_back(sum);
        }
        for (size_t j = 0; j < currentSumsVec.size(); ++j) {
             possibleSums.insert(currentSumsVec[j] + current_num);
        }
    }

    int minDiff = INT_MAX;
    int closestSum = -1;

    bool firstSum = true;

    for (int sum : possibleSums) {
        int diff = std::abs(sum - target);

        if (firstSum || diff < minDiff) {
            minDiff = diff;
            closestSum = sum;
            firstSum = false;
        } else if (diff == minDiff) {
            if (closestSum < sum){
                closestSum = sum;
                firstSum = false;
            }
        }
    }

     if(firstSum) return 0;

    return closestSum;
}

int RongGuoMansion::printMagicNumber() {
    return printMagicNumber(2025);
}

int NingGuoMansion::printMagicNumber(int target) {
    int num = 0;
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i].first.getId() <= target) {
            num++;
        }
    }
    return num;
}

int NingGuoMansion::printMagicNumber() {
    int num = 0;
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i].second.getName() == "root") {
            num++;
        }
    }
    return num;
}

std::string NingGuoMansion::printLCA(std::string name1, std::string name2) {
    auto findEntryByName = [&](const std::string& name) -> const std::pair<UserInfo, UserInfo>* {
        for (size_t i = 0; i < users.size(); ++i) {
            if (users[i].first.getName() == name) {
                return &users[i];
            }
        }
        return nullptr;
    };

    std::vector<std::string> path1, path2;

    const std::pair<UserInfo, UserInfo>* current_node = findEntryByName(name1);
    while (current_node != nullptr) {
        path1.push_back(current_node->first.getName());
        const UserInfo& parent_info = current_node->second;

        if (parent_info.getName() == "root") {
            break;
        }
        current_node = findEntryByName(parent_info.getName());
    }

    current_node = findEntryByName(name2);
    while (current_node != nullptr) {
        path2.push_back(current_node->first.getName());
        const UserInfo& parent_info = current_node->second;
        if (parent_info.getName() == "root") {
            break;
        }
        current_node = findEntryByName(parent_info.getName());
    }

    for (size_t i = 0; i < path1.size(); ++i) {
        const std::string& name_in_path1 = path1[i];
        for (size_t j = 0; j < path2.size(); ++j) {
            const std::string& name_in_path2 = path2[j];
            if (name_in_path1 == name_in_path2) {
                return name_in_path1;
            }
        }
    }
    return "root";
}
