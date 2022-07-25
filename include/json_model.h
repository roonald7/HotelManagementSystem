#pragma once

#include "Hotel.h"
#include <nlohmann/json.hpp>
#include <iomanip>

using json = nlohmann::json;
using namespace std;

namespace ns
{

    void to_json(json &j, const Person &p);
    void from_json(const json &j, Person &p);
    void to_json(json &j, const Guest &guest);
    void from_json(const json &j, Guest &guest);
    void to_json(json &j, const HotelDataCtx &hotelData);
    void from_json(const json &j, HotelDataCtx &hotelData);

}

void to_json(json &j, const Person &p)
{
    j = json{
        {"name", p.name},
        {"address", p.address},
        {"phone", p.phone}};
}

void from_json(const json &j, Person &p)
{
    j.at("name").get_to(p.name);
    j.at("address").get_to(p.address);
    j.at("phone").get_to(p.phone);
}

void to_json(json &j, const Guest &guest)
{
    j = json{
        {"person", guest.person},
        {"room_num", guest.room_num},
        {"days", guest.days},
        {"fare", guest.fare}
    };
}

void from_json(const json &j, Guest &guest)
{
    j.at("person").get_to(guest.person);
    j.at("room_num").get_to(guest.room_num);
    j.at("days").get_to(guest.days);
    j.at("fare").get_to(guest.fare);
}

void to_json(json &j, const HotelDataCtx &hotelData)
{
    j = json{
        {"guests", {hotelData.listOfGuests}},
        {"registeredPersons", {hotelData.listOfRegisteredperson}}
    };
}

void from_json(const json &j, HotelDataCtx &hotelData)
{
    j.at("guests").get_to(hotelData.listOfGuests);
    j.at("registeredPerson").get_to(hotelData.listOfRegisteredperson);
}