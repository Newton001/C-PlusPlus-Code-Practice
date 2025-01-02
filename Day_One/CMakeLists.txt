# Set cmake version
cmake_minimum_required(VERSION 3.5)

# Set Name of project and language
project(Day_One LANGUAGES CXX)

find_package(Threads REQUIRED)

# set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")

# Create executable using the specified src
add_executable(${PROJECT_NAME} main.cpp
)

#Link Libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

# Define required c++ standard to C++20
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

# Set compile options, enable warnings
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -Wall>
    $<$<CXX_COMPILER_ID:MSVC>: /W3>
)

# Check if the file exists
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/threadLog.txt")
    # If file exists, copy it to the binary directory
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/threadLog.txt DESTINATION ${PROJECT_BINARY_DIR})
else()
    # If file doesn't exist, create an empty file
    file(WRITE "${CMAKE_CURRENT_SOURCE_DIR}/threadLog.txt" "")
    message(STATUS "threadLog.txt file was created.")

    # Now copy the newly created file
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/threadLog.txt DESTINATION ${PROJECT_BINARY_DIR})
endif()


