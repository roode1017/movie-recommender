#include "user_manager.h"
#include <iostream>

void UserManager::addUser(const User& user) {
    users.push_back(user);
}

User* UserManager::findByName(const std::string& name) {
    for (User& u : users) {
        if (u.getName() == name)
            return &u;
    }
    return nullptr;
}

const User* UserManager::findById(int id) const {
    for (const User& u : users) {
        if (u.getId() == id)
            return &u;
    }
    return nullptr;
}

void UserManager::printAll() const {
    if (users.empty()) {
        std::cout << "  (등록된 사용자가 없습니다)\n";
        return;
    }
    for (const User& u : users)
        std::cout << "  " << u << "\n";
}

int UserManager::size() const {
    return static_cast<int>(users.size());
}
