cmake_minimum_required(VERSION 3.16)

project(Even_Odd_Checker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Even_Odd_Checker main.cpp)

include(GNUInstallDirs)
install(TARGETS Even_Odd_Checker
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
