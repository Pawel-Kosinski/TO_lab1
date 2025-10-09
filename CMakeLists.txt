cmake_minimum_required(VERSION 3.15)
project(CurrencyConverter CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES 
    "src/utils/*.cpp"
    "src/model/*.cpp"
    "src/services/*.cpp"
    "src/patterns/*.cpp"
    "src/app/*.cpp"
)

add_executable(currency_converter main.cpp ${SOURCES})