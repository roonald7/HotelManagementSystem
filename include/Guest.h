#pragma once

#include "person.h"
#include <stdint.h>

struct Guest
{
    Person person;
    uint8_t days;
    float fare;

    Guest();
    Guest(Person person, uint8_t days, float fare);
};

