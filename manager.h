#pragma once

class Manager {
public:
    virtual ~Manager() = default;
    virtual void printAll() const = 0;
};
