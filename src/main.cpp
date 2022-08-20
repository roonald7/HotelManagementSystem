/*

	Title			: ragc::Hotel Management System
	Language		: C++
	Author			: Ronald Anderson Gomes de Castro
	Date Created	: 23/07/2022
	Last Modified	: 23/07/2022
*/
#include "Hotel.h"
#include "services/hotelServices.h"
#include <fmt/format.h>
#include <grpcpp/grpcpp.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int server_port = 4747;

	auto server_address = fmt::format("0.0.0.0:{:d}", server_port);
	
	ragc::HotelService hotelService;
    grpc::EnableDefaultHealthCheckService(true);
    grpc::ServerBuilder builder;

    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&hotelService);
    
    // Finally assemble the server.
    auto server = builder.BuildAndStart();
    fmt::print("Server listening on {}\n", server_address);

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();

	return 0;
}
