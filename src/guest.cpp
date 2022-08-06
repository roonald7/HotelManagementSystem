#include "guest.h"
 
Guest::Guest()
{
}

Guest::Guest(Person person, uint8_t days, float fare)
    : person(person), days(days), fare(fare)
{
}
