#include "services/hotelServices.h"
#include "services/utilsHotelsServices.h"

namespace ragc
{

    grpc::Status HotelService::GetListOfGuests(grpc::ServerContext* context, const EmptyRequest* request, ::grpc::ServerWriter<GetListOfGuestsReply>* writer)
    {
        GetListOfGuestsReply reply;

        for(const auto &guest : sdkHotel.getHotelDataBase().listOfGuests)
        {
            auto guestList = reply.mutable_data()->add_list_of_guest();
            guestList->set_room(guest.first);
            write_guest_to_proto(guest.second, guestList->mutable_guest());
        }
        
        writer->Write(reply);

        return grpc::Status::OK;
    }

    grpc::Status HotelService::GetListOfRegisterdPerson(grpc::ServerContext* context, const EmptyRequest* request, ::grpc::ServerWriter<GetListOfRegisteredPersonReply>* writer)
    {
        GetListOfRegisteredPersonReply reply;

        for(const auto &person : sdkHotel.getHotelDataBase().listOfRegisteredPerson)
        {
            auto registeredPersonList = reply.mutable_data()->add_list_of_registered_person();
            registeredPersonList->set_id(person.first);
            write_person_to_proto(person.second, registeredPersonList->mutable_person());
        }
        
        writer->Write(reply);

        return grpc::Status::OK;
    }

}