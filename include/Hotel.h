#pragma once

#include "Guest.h"
#include <map>

struct HotelDataCtx
{
    std::map<int, Guest> listOfGuests;
    std::map<int, Person> listOfRegisteredPerson;
};

class Hotel
{
private:
    HotelDataCtx hotelDataBase;
    string pathDataRegisters = "./dataBase.json";
public:
    Hotel(string hotelName);
    ~Hotel();

    string hotelName;
    bool registerGuestByPersonId(const int &personId, const int &room_num);
    void registerPerson(const Person &person);
    void registerGuest(const int &room_num, const Guest &guest);
    void showRegisteredPersons();
    void showRoomsStatus();
    void loadDataBase();
    void updateDataBase();
    auto getHotelDataBase() const -> HotelDataCtx;
};
