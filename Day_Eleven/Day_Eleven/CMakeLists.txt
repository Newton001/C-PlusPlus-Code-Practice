cmake_minimum_required(VERSION 3.16)

project(Day_Eleven LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Day_Eleven main.cpp)

include(GNUInstallDirs)
install(TARGETS Day_Eleven
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
