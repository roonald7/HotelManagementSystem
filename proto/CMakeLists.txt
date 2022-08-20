find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(Threads)

add_library(
    hotelProtobuf
    
    hotel/hotel.proto
    hotel/guest.proto
)

target_link_libraries(
    hotelProtobuf

    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)

target_compile_features(
    hotelProtobuf

    PRIVATE
        cxx_std_17
)

target_include_directories(
    hotelProtobuf

    PUBLIC 
        ${CMAKE_CURRENT_BINARY_DIR}
)

protobuf_generate(
    TARGET hotelProtobuf 
    LANGUAGE cpp
)

get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)

protobuf_generate(
    TARGET hotelProtobuf 
    LANGUAGE grpc 
    GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
    PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}"
)