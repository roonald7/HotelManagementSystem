#pragma once

#include "guest.h"
#include <vector>

namespace ns
{
struct HotelDataCtx
{
    vector<ns::Guest> listOfGuests;
    vector<ns::Person> listOfRegisteredperson;
};
}
class Hotel
{
private:
    ns::HotelDataCtx hotelDataBase;
    string pathDataRegisters = "/dataBase.json";
public:
    Hotel();
    ~Hotel();

    void registerperson(const ns::Person &person);
    void showRegisteredpersons();
    void loadDataBase();
};