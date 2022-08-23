#include "services/utilsHotelsServices.h"

namespace ragc
{
    auto make_person(const PersonProto& person) -> Person
    {
        return Person(person.name(), person.surname(), person.address(), person.phone());
    }

    void write_guest_to_proto(const Guest& guest, GuestProto* proto)
    {   
        write_person_to_proto(guest.person, proto->mutable_person());
        proto->set_days(guest.days);
        proto->set_fare(guest.fare);
    }

    void write_person_to_proto(const Person& person, PersonProto* proto)
    {
        proto->set_name(person.name);
        proto->set_surname(person.surname);
        proto->set_address(person.address);
        proto->set_phone(person.phone);
    }

}