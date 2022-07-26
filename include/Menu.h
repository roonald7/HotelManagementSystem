#pragma once

#include "Hotel.h"
#include <fmt/format.h>

struct Menu
{
    Menu(Hotel hotel)
        : hotel(hotel)
    {
        fmt::print("Welcome to {}!\n", hotel.hotelName);
    }

    Hotel hotel;
};
