cmake_minimum_required(VERSION 3.5)

project(editor LANGUAGES CXX)

file(GLOB SRCS *.cpp)
file(GLOB HDRS *.h)

add_executable(editor ${SRCS} ${HDRS} )

set_target_properties(
        editor
        PROPERTIES 
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
