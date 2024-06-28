cmake_minimum_required(VERSION 3.29)
project(TST LANGUAGES CXX)

set(SFML_STATIC_LIBRARIES TRUE)



if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")

    message("MSVC compiler")
    set(SFML_DIR ${CMAKE_SOURCE_DIR}/include/SFML-MSVC/lib/cmake/SFML)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Win32_build) 

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

    message("GNU comiler")
    set(SFML_DIR ${CMAKE_SOURCE_DIR}/include/SFML-GNU/lib/cmake/SFML)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Linux_build)

else()
    message("Compiler needs to be GNU or MSVC")
endif()



find_package(SFML 2.6 REQUIRED graphics window audio network system)
add_executable(TST main.cpp)



message(${SFML_FOUND})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-audio sfml-network sfml-system)



if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message("MSVC compiler")
    target_include_directories(TST
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/SFML-MSVC/include)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message("GNU comiler")
    target_include_directories(TST
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/SFML-GNU/include)
else()
    message("Compiler needs to be GNU or MSVC")
endif()

