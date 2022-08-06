#include <person.h>

Person::Person()
{
}

Person::Person(string name, string address, string phone)
    : name(name), address(address), phone(phone)
{
}

Person::Person(string name, string surname, string address, string phone)
    : name(name), surname(surname), address(address), phone(phone)
{
}

auto Person::fullName() const -> std::string
{
    return name + " " + surname;
}
