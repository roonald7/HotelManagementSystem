cmake_minimum_required(VERSION 3.10)

file(TIMESTAMP "${CMAKE_CURRENT_LIST_DIR}/vcpkg.json" vcpkg_json_timestamp)

if(VCPKG_JSON_TIMESTAMP_PREV STREQUAL vcpkg_json_timestamp)
    set(VCPKG_MANIFEST_INSTALL OFF CACHE STRING "" FORCE)
else()
    set(VCPKG_MANIFEST_INSTALL ON CACHE STRING "" FORCE)
endif()

project(HotelManagementSystem
        VERSION 0.0.1
        DESCRIPTION "The leading Hello World App"
        LANGUAGES CXX
)        

set(VCPKG_JSON_TIMESTAMP_PREV "${vcpkg_json_timestamp}" CACHE STRING "" FORCE)       
        
find_package(nlohmann_json CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_library(
    ${PROJECT_NAME}SRCS

    src/Hotel.cpp
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
        cxx_std_17
)

target_link_libraries(
    ${PROJECT_NAME}SRCS

    PUBLIC
        fmt::fmt
)

target_link_libraries(
    ${PROJECT_NAME}

    PUBLIC
        ${PROJECT_NAME}SRCS
)