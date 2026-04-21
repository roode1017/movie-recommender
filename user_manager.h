#pragma once
#include <string>
#include <vector>
#include "user.h"

class UserManager {
private:
    std::vector<User> users;

public:
    void addUser(const User& user);
    User* findByName(const std::string& name);
    void printAll() const;
    int size() const;
};
