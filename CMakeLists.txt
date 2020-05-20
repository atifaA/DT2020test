cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0076 NEW)

project(GameOfLife LANGUAGES C)

add_subdirectory(console)
add_subdirectory(game)
add_subdirectory(printing_SDL2)
set (SRC main.c)

add_executable(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PUBLIC ${SRC})

target_link_libraries(${PROJECT_NAME} PUBLIC console) 
target_link_libraries(${PROJECT_NAME} PUBLIC game) 
target_link_libraries(${PROJECT_NAME} PUBLIC printing_SDL2) 
# target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
# add_compile_options("-lSDL2")


install(TARGETS ${PROJECT_NAME})