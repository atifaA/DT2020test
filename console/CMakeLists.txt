cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0076 NEW)

project(console LANGUAGES C)


SET(VALUE CACHE STRING "what you want")

add_library(${PROJECT_NAME} SHARED "")

target_sources(${PROJECT_NAME} PUBLIC print_with_ansi.c print_with_ansi.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})#-I.

target_link_libraries(${PROJECT_NAME} INTERFACE m) #-lm

target_compile_definitions(${PROJECT_NAME} PUBLIC USING_LIB=${VALUE}) #-D USING_LIB=1


install(TARGETS ${PROJECT_NAME})
install(FILES print_with_ansi.h DESTINATION include)