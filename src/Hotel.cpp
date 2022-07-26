#include "utils_io.h"
#include "json_models.h"
#include <fmt/format.h>

Hotel::Hotel()
{
    loadDataBase();
}

Hotel::~Hotel()
{
}

void Hotel::registerPerson(const Person &person)
{
    hotelDataBase.listOfRegisteredPerson.push_back(person);
}

void Hotel::registerGuest(const Guest &guest)
{
    hotelDataBase.listOfGuests.push_back(guest);
}

void Hotel::showRegisteredPersons()
{
    fmt::print("List of Registered person:\n");

    for(const auto& p : hotelDataBase.listOfRegisteredPerson)
    {
        fmt::print("\tName: {} {}\n\tAddres: {}\n\tPhone Number: {}\n\n", p.name, p.surname, p.address, p.phone);
    }
}

auto Hotel::getHotelDataBase() const -> HotelDataCtx
{
    return hotelDataBase;
}

void Hotel::loadDataBase()
{
    try
    {
        auto json_ = nlohmann::json::parse(get_file_content(pathDataRegisters));

        hotelDataBase = json_.get<HotelDataCtx>();
    }
    catch(const std::exception& e)
    {
        fmt::print("{}\n", e.what());
        fmt::print("There's no available data base. An empty data will be created!\n");
        updateDataBase();
    }
    
    

    // hotelDataBase = json_.get<HotelDataCtx>();
}

void Hotel::updateDataBase()
{
    nlohmann::json j = hotelDataBase;

    write_json(j, pathDataRegisters);
}
