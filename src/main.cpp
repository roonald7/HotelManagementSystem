/*

	Title			: ragc::Hotel Management System
	Language		: C++
	Author			: Ronald Anderson Gomes de Castro
	Date Created	: 23/07/2022
	Last Modified	: 23/07/2022
*/
#include "Hotel.h"
#include <iostream>

using namespace std;

Hotel mockHotel();

int main(int argc, char const *argv[])
{
	auto hotel = mockHotel();

	hotel.showRegisteredPersons();

	return 0;
}

Hotel mockHotel()
{
	Hotel ibis("Ibis Maracanaú");

	return ibis;
}
