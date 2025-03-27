cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(osoconn VERSION 1.1)

configure_file(${PROJECT_SOURCE_DIR}/data/AISCSections.db ${PROJECT_BINARY_DIR}/data/AISCSections.db COPYONLY)

configure_file(${PROJECT_SOURCE_DIR}/include/osoconnConfig.h.in ${PROJECT_SOURCE_DIR}/include/osoconnConfig.h)
add_subdirectory(sqlite3)

add_executable(osoconn main.cpp)

target_link_libraries(osoconn PUBLIC sqlite3)

target_include_directories(osoconn PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/connections
    ${PROJECT_SOURCE_DIR}/sqlite3
    )
