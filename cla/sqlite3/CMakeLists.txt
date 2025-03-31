add_library(sqlite3 sqlite3.c)
target_link_libraries(sqlite3 PUBLIC ${CMAKE_DL_LIBS})
