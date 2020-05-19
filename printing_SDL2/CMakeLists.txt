cmake_minimum_required(VERSION 3.5.0)
cmake_policy(SET CMP0076 NEW)

project(printing_SDL2 LANGUAGES C)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_library(${PROJECT_NAME} SHARED "")

target_sources(${PROJECT_NAME} PUBLIC print_with_sdl.c print_with_sdl.h)

target_link_libraries(${PROJECT_NAME} PUBLIC SDL2)
# target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2 SDL2::SDL2main)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(${PROJECT_NAME} PUBLIC ../game)

target_link_libraries(${PROJECT_NAME} INTERFACE m) #-lm
target_link_libraries(${PROJECT_NAME} PUBLIC game) 

target_compile_definitions(${PROJECT_NAME} PUBLIC USING_LIB=${VALUE}) #-D USING_LIB=1

# add_definitions("-lSDL2")

install(FILES print_to_sdl.h DESTINATION include)
install(TARGETS ${PROJECT_NAME})