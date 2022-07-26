#include "json_models.h"

void to_json(json &j, const Person &p)
{
    j = json{
        {"name", p.name},
        {"surname", p.surname},
        {"address", p.address},
        {"phone", p.phone}
    };
}

void from_json(const json &j, Person &p)
{
    j.at("name").get_to(p.name);
    j.at("surname").get_to(p.surname);
    j.at("address").get_to(p.address);
    j.at("phone").get_to(p.phone);
}

void to_json(json &j, const Guest &guest)
{
    j = json{
        {"person", guest.person},
        {"days", guest.days},
        {"fare", guest.fare}
    };
}

void from_json(const json &j, Guest &guest)
{
    j.at("person").get_to(guest.person);
    j.at("days").get_to(guest.days);
    j.at("fare").get_to(guest.fare);
}

void to_json(json &j, const HotelDataCtx &hotelData)
{
    j = json{
        {"guests", hotelData.listOfGuests},
        {"registeredPersons", hotelData.listOfRegisteredPerson}
    };
}

void from_json(const json &j, HotelDataCtx &hotelData)
{
    j.at("guests").get_to(hotelData.listOfGuests);
    j.at("registeredPersons").get_to(hotelData.listOfRegisteredPerson);
}
