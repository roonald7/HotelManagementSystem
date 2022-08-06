#pragma once

#include "Hotel.h"
#include <nlohmann/json.hpp>
#include <iomanip>

using json = nlohmann::json;
using namespace std;

void to_json(json &j, const Person &p);
void from_json(const json &j, Person &p);
void to_json(json &j, const Guest &guest);
void from_json(const json &j, Guest &guest);
void to_json(json &j, const HotelDataCtx &hotelData);
void from_json(const json &j, HotelDataCtx &hotelData);

