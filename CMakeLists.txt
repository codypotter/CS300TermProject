cmake_minimum_required(VERSION 3.10)

project(CS300TermProject)

include_directories(include libs)

add_executable(CS300TermProject main.cpp Database.cpp Service.cpp Member.cpp Provider.cpp libs/json_reader.cpp libs/json_writer.cpp libs/json_value.cpp)
