#include "utils_io.h"
#include "json_models.h"
#include <fmt/format.h>

Hotel::Hotel(std::string hotelName)
    : hotelName(hotelName)
{
    loadDataBase();
}

Hotel::~Hotel()
{
}

void Hotel::registerPerson(const Person &person)
{
    hotelDataBase.listOfRegisteredPerson[hotelDataBase.listOfRegisteredPerson.size() + 1] = person;
}

void Hotel::registerGuest(const int &room_num, const Guest &guest)
{
    hotelDataBase.listOfGuests[room_num] = guest;
}

void Hotel::showRegisteredPersons()
{
    fmt::print("List of Registered person:\n");

    for(const auto& [id, p] : hotelDataBase.listOfRegisteredPerson)
    {
        fmt::print("\tId: {}\n\tName: {}\n\tAddres: {}\n\tPhone Number: {}\n\n", id, p.fullName(), p.address, p.phone);
    }
}

void Hotel::showRoomsStatus()
{
    for(const auto &[room, guest] : hotelDataBase.listOfGuests)
    {
        fmt::print("\tRoom Number: {}\n\tGuest: {}\n\n", room, guest.person.fullName());
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
}

void Hotel::updateDataBase()
{
    nlohmann::json j = hotelDataBase;

    write_json(j, pathDataRegisters);
}
