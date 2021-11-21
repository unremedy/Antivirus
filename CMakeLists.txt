cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

include("cmake/HunterGate.cmake")

HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.314.tar.gz"
        SHA1 "95c47c92f68edb091b5d6d18924baabe02a6962a"
)
project(Antivirus)

add_library(${PROJECT_NAME} STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/Scanning.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/CreatingHash.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/WorkingWithDB.cpp
        )

add_executable(antivirus
        ${CMAKE_CURRENT_SOURCE_DIR}/demo/main.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>"
        )

hunter_add_package(OpenSSL)
find_package(OpenSSL REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC OpenSSL::SSL OpenSSL::Crypto)

target_link_libraries(antivirus ${PROJECT_NAME})