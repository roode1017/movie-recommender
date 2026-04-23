#pragma once
#include <string>
#include <iostream>

class User {
private:
    int         id;     // 사용자 ID
    std::string name;   // 이름
    std::string email;  // 이메일

public:
    User();
    User(int id, const std::string& name, const std::string& email);

    int         getId()    const;
    std::string getName()  const;
    std::string getEmail() const;

    void display() const;

    friend std::ostream& operator<<(std::ostream& os, const User& user);
};
