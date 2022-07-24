#pragma once

#include "person.h"
#include <stdint.h>

namespace ns
{
struct Guest
{
    ns::Person person;
    uint16_t room_num;
    uint8_t days;
    float fare;

    Guest(ns::Person person, uint16_t room_num, uint8_t days, float fare);
};
}