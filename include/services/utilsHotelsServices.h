#pragma once

#include "Person.h"
#include "Guest.h"
#include "hotel/guest.pb.h"

namespace ragc
{
    void write_guest_to_proto(const Guest&, GuestProto*);
    void write_person_to_proto(const Person&, PersonProto*);
}