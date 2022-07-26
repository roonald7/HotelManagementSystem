cmake_minimum_required(VERSION 3.17)

file(TIMESTAMP "${CMAKE_CURRENT_LIST_DIR}/vcpkg.json" vcpkg_json_timestamp)

if(VCPKG_JSON_TIMESTAMP_PREV STREQUAL vcpkg_json_timestamp)
    set(VCPKG_MANIFEST_INSTALL OFF CACHE STRING "" FORCE)
else()
    set(VCPKG_MANIFEST_INSTALL ON CACHE STRING "" FORCE)
endif()

project(
    HotelManagementSystem
    VERSION 0.0.1
    DESCRIPTION "The leading Hello World App"
    LANGUAGES CXX
)        

set(VCPKG_JSON_TIMESTAMP_PREV "${vcpkg_json_timestamp}" CACHE STRING "" FORCE)       
set(nlohmann-json_IMPLICIT_CONVERSIONS OFF)

find_package(clipp CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_subdirectory(proto)

add_library(
    ${PROJECT_NAME}SRCS

    src/guest.cpp
    src/Hotel.cpp
    src/json_models.cpp
    src/person.cpp
    src/utils_io.cpp

    src/services/hotelServices.cpp
    src/services/utilsHotelServices.cpp
)

add_executable(
    ${PROJECT_NAME} 
    
    src/main.cpp
)

target_include_directories(
    ${PROJECT_NAME}SRCS

    PUBLIC
        ./include
        ${CMAKE_CURRENT_BINARY_DIR}
)

target_compile_features(
    ${PROJECT_NAME}SRCS 
    
    PUBLIC
        cxx_std_20
)

target_compile_options(
    ${PROJECT_NAME}SRCS

    PUBLIC
        $<$<CXX_COMPILER_ID:MSVC>:/utf-8>
        $<$<CXX_COMPILER_ID:AppleClang>:-finput-charset=utf-8>
)

target_link_libraries(
    ${PROJECT_NAME}SRCS

    PUBLIC
        clipp::clipp
        fmt::fmt
        nlohmann_json::nlohmann_json
        hotelProtobuf
)

target_link_libraries(
    ${PROJECT_NAME}

    PUBLIC
        ${PROJECT_NAME}SRCS
)

add_custom_target(
    run

    COMMAND
        ${PROJECT_NAME}

    USES_TERMINAL
)

add_dependencies(run ${PROJECT_NAME})