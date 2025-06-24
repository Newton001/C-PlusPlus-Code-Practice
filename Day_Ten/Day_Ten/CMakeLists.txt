cmake_minimum_required(VERSION 3.16)

project(Day_Ten LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Day_Ten main.cpp)

include(GNUInstallDirs)
install(TARGETS Day_Ten
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
