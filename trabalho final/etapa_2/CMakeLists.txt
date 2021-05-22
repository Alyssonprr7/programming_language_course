cmake_minimum_required(VERSION 3.19)
project(etapa_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(etapa_2 main.cpp databaseOperations.cpp utils.cpp)

target_link_libraries(etapa_2 mysqlcppconn)