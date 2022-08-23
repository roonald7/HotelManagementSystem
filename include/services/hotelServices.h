#pragma once

#include "grpcpp/impl/codegen/server_context.h"
#include "grpcpp/impl/codegen/sync_stream.h"
#include "grpcpp/impl/codegen/call_op_set.h"
#include "hotel/hotel.pb.h"
#include "hotel/hotel.grpc.pb.h"
#include "Hotel.h"

namespace ragc
{
    class HotelService final : public HotelProto::Service
    {
    public:
        HotelService()
        : sdkHotel("SDK Hotel Maracanaú") {}
        
        grpc::Status AddPerson(grpc::ServerContext* context, const AddPersonRequest* request, ::grpc::ServerWriter<CommandResponseStatusReply>* writer) override;
        grpc::Status AddGuest(grpc::ServerContext* context, const AddGuestRequest* request, ::grpc::ServerWriter<CommandResponseStatusReply>* writer) override;
        grpc::Status GetListOfGuests(grpc::ServerContext* context, const EmptyRequest* request, ::grpc::ServerWriter<GetListOfGuestsReply>* writer) override;
        grpc::Status GetListOfRegisterdPerson(grpc::ServerContext* context, const EmptyRequest* request, ::grpc::ServerWriter<GetListOfRegisteredPersonReply>* writer) override;
    private:
        Hotel sdkHotel;
    };
    
}