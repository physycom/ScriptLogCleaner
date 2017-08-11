cmake_minimum_required (VERSION 3.1)
project (ScriptLogCleaner)
set (CMAKE_CXX_STANDARD 11)

if(MSVC)
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(ScriptLogCleaner ${CMAKE_SOURCE_DIR}/src/ScriptLogCleaner.cpp)

install (TARGETS 
	ScriptLogCleaner  
	DESTINATION ${CMAKE_SOURCE_DIR}/bin/
)

