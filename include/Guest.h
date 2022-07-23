#pragma once

#include "Person.h"
#include <stdint.h>

struct Guest
{
    Person person;
    uint16_t room_num;
    uint8_t days;
    float fare;

    Guest(Person person, uint16_t room_num, uint8_t days, float fare);
    ~Guest();
};

Guest::Guest(Person person, uint16_t room_num, uint8_t days, float fare)
    : person(person), room_num(room_num), days(days), fare(fare)
{
}

Guest::~Guest()
{
}
