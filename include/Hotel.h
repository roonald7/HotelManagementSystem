#pragma once

#include "guest.h"
#include <vector>

struct HotelDataCtx
{
    vector<Guest> listOfGuests;
    vector<Person> listOfRegisteredPerson;
};

class Hotel
{
private:
    HotelDataCtx hotelDataBase;
    string pathDataRegisters = "./dataBase.json";
public:
    Hotel();
    ~Hotel();

    void registerPerson(const Person &person);
    void registerGuest(const Guest &guest);
    void showRegisteredPersons();
    void loadDataBase();
    void updateDataBase();
    auto getHotelDataBase() const -> HotelDataCtx;
};
