cmake_minimum_required(VERSION 2.8)

project(Synthese_Image)

set(EXECUTABLE_OUTPUT_PATH
	bin/
)

set(CMAKE_CXX_FLAGS
	"${CMAKE_CXX_FLAGS} -W -Wall -ansi -std=c++11 -g -Weffc++"
)

include_directories(
	include/
)

file(GLOB_RECURSE
	source_files

	src/*
)

add_executable(
	Synthese_Image
	${source_files}
)