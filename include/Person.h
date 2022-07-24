#pragma once

#include <string>

using namespace std;

namespace ns
{

struct Person
{
    string name;
    string address;
    string phone;
    
    Person(string name, string address, string phone);
};
}