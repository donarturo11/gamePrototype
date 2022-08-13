cmake_minimum_required(VERSION 3.22)
project(GamePrototype VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

option(CONIO_PATH "linuxconio")
option(ENABLE_CONIO21 0)
option(ENABLE_LINUXCONIO 0)
option(ENABLE_LINUXCONIO_MOD 0)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
set(WINDOWS 1)
set(ENABLE_CONIO21 1)
find_library(CONIO conio)
else()
set(WINDOWS 0)
set(ENABLE_LINUXCONIO 1)
endif()

if(ENABLE_LINUXCONIO)
add_compile_definitions(_CONIO_)
add_compile_definitions(_LINUXCONIO_)
find_library(CONIO conio ${CONIO_PATH})
link_directories(${CONIO_PATH})
endif()

if(ENABLE_CONIO21)
link_directories(${CONIO_PATH})
add_compile_definitions(_CONIO21_)
endif()

include_directories(${CONIO_PATH})
include_directories(./ TUI/)

FILE(GLOB HEADERS TUI/*.h)
FILE(GLOB SOURCES TUI/*.cpp main.cpp)

add_executable(
    ${PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
    )

if(ENABLE_LINUXCONIO_MOD)
target_link_libraries(${PROJECT_NAME} conio)
endif()

if(ENABLE_CONIO21)
target_link_libraries(${PROJECT_NAME} conio_64 ${CONIO_PATH} -static)
endif()