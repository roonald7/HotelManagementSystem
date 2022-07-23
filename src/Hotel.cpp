#include "Hotel.h"
#include <fmt/format.h>

Hotel::Hotel()
{
}

Hotel::~Hotel()
{
}

void Hotel::registerPerson(const Person &person)
{
    listOfRegisteredPerson.push_back(person);
}

void Hotel::showRegisteredPersons()
{
    fmt::print("List of Registered Person:\n");

    for(const auto& p : listOfRegisteredPerson)
    {
        fmt::print("\tName: {}\n\tAddres: {}\n\tPhone Number: {}\n\n", p.name, p.address, p.phone);
    }
}