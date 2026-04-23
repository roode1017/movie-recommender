#include "user.h"
#include <iostream>


// 기본 생성자
User::User()
    : id(0) {}


// 3인자 생성자
User::User(int id, const std::string& name, const std::string& email)
    : id(id), name(name), email(email) {} //초기화 리스트 사용


int         User::getId()    const { return id; }
std::string User::getName()  const { return name; }
std::string User::getEmail() const { return email; }


void User::display() const {
    std::cout << id << ". " << name
              << " <" << email << ">"
              << std::endl;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << user.id << ". " << user.name
       << " <" << user.email << ">";
    return os;
}
