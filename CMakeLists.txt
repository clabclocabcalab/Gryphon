cmake_minimum_required (VERSION 3.10)

project ("Gryphon")

add_executable (Gryphon "src/Gryphon.cpp" "src/ALU.cpp")

target_include_directories (Gryphon PRIVATE ${CMAKE_SOURCE_DIR}/include)