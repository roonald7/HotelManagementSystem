/*

	Title			: Hotel Management System
	Language		: C++
	Author			: Ronald Anderson Gomes de Castro
	Date Created	: 23/07/2022
	Last Modified	: 23/07/2022
*/
#include "Hotel.h"
#include <iostream>

using namespace std;

Hotel mock_hotel();

int main(int argc, char const *argv[])
{
	auto hotel = mock_hotel();

	return 0;
}

Hotel mock_hotel()
{
	Hotel ibis;

	// ibis.registerPerson(
	// 	{"Jullyanne", "Cassimiro", "Maracanaú", "859XXXX-XXXX"}
	// );

	// ibis.registerPerson(
	// 	{"Ronald", "Castro", "Maracanaú", "859XXXX-XXXX"}
	// );

	// ibis.registerGuest({ibis.getHotelDataBase().listOfRegisteredPerson[0], 1, 1, 0.1});
	// ibis.updateDataBase();

	ibis.showRegisteredPersons();

	return ibis;
}
