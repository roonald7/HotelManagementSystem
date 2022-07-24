#pragma once

#include "Hotel.h"
#include <nlohmann/json.hpp>
#include <iomanip>

using json = nlohmann::json;
using namespace std;

namespace ns
{

    void to_json(json &j, const ns::Person &p);
    void from_json(const json &j, ns::Person &p);
    void to_json(json &j, const ns::Guest &guest);
    void from_json(const json &j, ns::Guest &guest);
    void to_json(json &j, const HotelDataCtx &hotelData);
    void from_json(const json &j, HotelDataCtx &hotelData);

}

void ns::to_json(json &j, const ns::Person &p)
{
    j = json{
        {"name", p.name},
        {"address", p.address},
        {"phone", p.phone}};
}

void ns::from_json(const json &j, ns::Person &p)
{
    j.at("name").get_to(p.name);
    j.at("address").get_to(p.address);
    j.at("phone").get_to(p.phone);
}

void ns::to_json(json &j, const ns::Guest &guest)
{
    j = json{
        {"person", guest.person},
        {"room_num", guest.room_num},
        {"days", guest.days},
        {"fare", guest.fare}
    };
}

void ns::from_json(const json &j, ns::Guest &guest)
{
    j.at("person").get_to(guest.person);
    j.at("room_num").get_to(guest.room_num);
    j.at("days").get_to(guest.days);
    j.at("fare").get_to(guest.fare);
}

void ns::to_json(json &j, const ns::HotelDataCtx &hotelData)
{
    j = json{
        {"guests", {hotelData.listOfGuests}},
        {"registeredPersons", {hotelData.listOfRegisteredperson}}
    };
}

void ns::from_json(const json &j, ns::HotelDataCtx &hotelData)
{
    // j.at("guests").get_to(hotelData.listOfGuests);
    // j.at("registeredPerson").get_to(hotelData.listOfRegisteredperson);
}