#include "guest.h"

ns::Guest::Guest(ns::Person person, uint16_t room_num, uint8_t days, float fare)
    : person(person), room_num(room_num), days(days), fare(fare)
{
}