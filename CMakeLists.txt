cmake_minimum_required(VERSION 3.0.0)
project(cn VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(cn Proiect/client_c.cpp)

target_link_libraries(cn ws2_32)
    
# add_compile_options(-lws2_32)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
