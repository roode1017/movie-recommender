#pragma once
#include <string>
#include <vector>
#include "user.h"
#include "manager.h"

class UserManager : public Manager {
private:
    std::vector<User> users;

public:
    void  addUser(const User& user);
    User* findByName(const std::string& name);
    void  printAll() const override;
    int   size() const;
};
