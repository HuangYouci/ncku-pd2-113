#include <iostream>
class GroupA {
    int id;
    std::string name;
    public:
        GroupA(int id, std::string name);
};
class GroupB : public GroupA {
    bool is_admin;
    public:
        GroupB(int id, std::string name);
        bool admin_check();
};
