cmake_minimum_required(VERSION 3.25)
project(TST LANGUAGES CXX)


add_executable(TST main.cpp)


# If we are building on windows than use a static library
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message("MSVC compiler")

    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR ${CMAKE_SOURCE_DIR}/include/SFML-MSVC/lib/cmake/SFML)
    find_package(SFML 2.6 REQUIRED graphics window audio network system)

    target_include_directories(TST
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/SFML-MSVC/include)
    
# If we are compiling on linux use the dynamic labraries installed on the computer
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message("GNU comiler")

    target_include_directories(TST
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include)

else()
    message("Compiler needs to be GNU or MSVC")
endif()

# find sfml
find_package(SFML 2.5 REQUIRED graphics window audio network system)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-audio sfml-network sfml-system)