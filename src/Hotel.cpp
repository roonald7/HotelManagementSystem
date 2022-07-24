#include "Hotel.h"
#include "utils.h"
#include "json_model.h"
#include <fmt/format.h>

Hotel::Hotel()
{
}

Hotel::~Hotel()
{
}

void Hotel::registerperson(const ns::Person &person)
{
    hotelDataBase.listOfRegisteredperson.push_back(person);
}

void Hotel::showRegisteredpersons()
{
    fmt::print("List of Registered person:\n");

    for(const auto& p : hotelDataBase.listOfRegisteredperson)
    {
        fmt::print("\tName: {}\n\tAddres: {}\n\tPhone Number: {}\n\n", p.name, p.address, p.phone);
    }
}

void Hotel::loadDataBase()
{
}