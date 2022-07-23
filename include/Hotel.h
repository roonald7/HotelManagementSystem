#pragma once

#include "Guest.h"
#include <vector>

class Hotel
{
private:
    std::vector<Guest> listOfGuests;
    std::vector<Person> listOfRegisteredPerson;
public:
    Hotel();
    ~Hotel();

    void registerPerson(const Person &person);
    void showRegisteredPersons();
    void updateDataBase();
};