cmake_minimum_required(VERSION 3.27)
project(whiskers)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

set(RAYLIB_PATH ${CMAKE_CURRENT_LIST_DIR}/raylib-5.0_linux_amd64)

find_library(RAYLIB_LIBRARY raylib)
include_directories("raylib-5.0_linux_amd64/include/")
link_directories("raylib-5.0_linux_amd64/lib/")

add_executable(whiskers 
	main.cpp
	include/tile.cpp
	include/event.cpp
	include/isometric.cpp
	include/predefentity.cpp
	include/region.cpp
	)

target_include_directories(whiskers PUBLIC "include/" "assets/")

file(COPY "assets" DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(whiskers libraylib.so)
