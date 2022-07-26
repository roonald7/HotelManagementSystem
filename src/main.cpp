/*

	Title			: Hotel Management System
	Language		: C++
	Author			: Ronald Anderson Gomes de Castro
	Date Created	: 23/07/2022
	Last Modified	: 23/07/2022
*/
#include "Menu.h"
#include <iostream>

using namespace std;

Hotel mock_hotel();

int main(int argc, char const *argv[])
{
	auto hotel = mock_hotel();
	
	auto menu = Menu(hotel);

	return 0;
}

Hotel mock_hotel()
{
	Hotel ibis("Ibis Maracanaú");

	return ibis;
}
