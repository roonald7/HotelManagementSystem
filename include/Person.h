#pragma once

#include <string>

using namespace std;

struct Person
{
    string name;
    string surname;
    string address;
    string phone;
    
    Person();
    Person(string name, string address, string phone);
    Person(string name, string surname, string address, string phone);
    auto fullName() const -> std::string;
};
