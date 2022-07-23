/*

	Title			: Hotel Management System
	Language		: C++
	Author			: Ronald Anderson Gomes de Castro
	Date Created	: 23/07/2022
	Last Modified	: 23/07/2022
*/
#include "Hotel.h"
#include "json_model.h"
#include "utils.h"
#include <iostream>

using namespace std;

// MARK:- Interface Functions Here =>

void intro()
{
	cout << "\n\n\t            ";
	cout << "     C++ Project On Hotel Management System";
	cout << "\n\n\t\t\t\t     MADE BY";
	cout << "\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout << "||\t\t\t\t\t\t\t\t\t      ||\n";
	cout << "||\t\t\t\t\t\t\t\t\t      ||\n";
	cout << "||\t\t\t\tRonald Anderson\t\t\t\t      ||\n";
	cout << "||\t\t\t\t\t\t\t\t\t      ||\n";
	cout << "||\t\t\t\t\t  \t\t\t\t      ||\n";
	cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
}

Hotel mock_hotel();

int main(int argc, char const *argv[])
{
	string dataPath = "./hotel_data.json";

	auto hotel = mock_hotel();
	
	return 0;
}

Hotel mock_hotel()
{
	Hotel sdkHotelMaracanau;

	sdkHotelMaracanau.registerPerson({"Augusto Pedrosa", "Fortaleza", ""});
	sdkHotelMaracanau.registerPerson({"Breno Gomes", "Maracanaú", ""});
	sdkHotelMaracanau.registerPerson({"Estevao Simao", "Fortaleza", ""});
	sdkHotelMaracanau.registerPerson({"Polycarpo Neto", "Caucaia", ""});
	sdkHotelMaracanau.registerPerson({"Rosemberg Braga", "Eusébio", ""});
	sdkHotelMaracanau.registerPerson({"Washington Filho", "Fortaleza", ""});

	sdkHotelMaracanau.showRegisteredPersons();

	return sdkHotelMaracanau;
}