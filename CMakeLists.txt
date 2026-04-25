cmake_minimum_required (VERSION 3.10)

project ("Gryphon")

add_executable (Gryphon "src/Gryphon.cpp" "src/ALU.cpp" "src/CPU.cpp")

find_package(Curses REQUIRED)

target_include_directories (Gryphon PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(Gryphon PRIVATE ${CURSES_INCLUDE_DIR})
target_link_libraries(Gryphon PRIVATE ${CURSES_LIBRARIES})
add_custom_command(TARGET Gryphon PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:Gryphon>)