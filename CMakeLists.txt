cmake_minimum_required(VERSION 3.0.0)
project(E_Lexicon VERSION 0.1.0 LANGUAGES C)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

add_executable(E_Lexicon E_Lexicon.h Control.c Data.c Databass.c Main.c Menu.c)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()
