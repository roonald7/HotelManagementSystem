#pragma once

#include <string>

using namespace std;

struct Person
{
    string name;
    string address;
    string phone;
    
    Person(string name, string address, string phone);
    ~Person();
};

Person::Person(string name, string address, string phone)
    : name(name), address(address), phone(phone)
{
}

Person::~Person()
{
}
