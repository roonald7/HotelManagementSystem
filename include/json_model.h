#pragma once

#include "Guest.h"
#include "Person.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void to_json(json &j, const Person &p)
{
    j = json();
    j["name"] = p.name;
    j["address"] = p.address;
    j["phone"] = p.phone;
}

void from_json(const json &j, Person &p)
{
    j.at("name").get_to(p.name);
    j.at("address").get_to(p.address);
    j.at("phone").get_to(p.phone);
}