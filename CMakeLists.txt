cmake_minimum_required(VERSION 3.1)

project(mecacell-examples)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # useful for clangd and other autocompletion tools
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -Wall -Wextra -pedantic")


set(MECACELL_PATH ../MecaCell)
include_directories(${MECACELL_PATH})

add_subdirectory(basic)

