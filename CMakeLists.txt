cmake_minimum_required(VERSION 3.14)
project(muesli)

include(cmake/CheckCompiler.cmake)
include(cmake/CompileOptions.cmake)

option(MUESLI_TESTS "Build muesli tests" OFF)
option(MUESLI_DEVELOPER "Muesli development mode" OFF)

set(MUESLI_ARCHIVE "JSON" CACHE STRING "Muesli archive format")

add_subdirectory(third_party)

add_subdirectory(muesli)

if(MUESLI_TESTS OR MUESLI_DEVELOPER)
    add_subdirectory(tests)
endif()
