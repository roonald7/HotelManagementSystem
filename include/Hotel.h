#pragma once

#include "guest.h"
#include <vector>

struct HotelDataCtx
{
    vector<Guest> listOfGuests;
    vector<Person> listOfRegisteredperson;
};

class Hotel
{
private:
    HotelDataCtx hotelDataBase;
    string pathDataRegisters = "./data/dataBase.json";
public:
    Hotel();
    ~Hotel();

    void registerperson(const Person &person);
    void showRegisteredpersons();
    void loadDataBase();
    void updateDataBase();
};