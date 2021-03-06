# Copyright 2015 Samuel Ghineț
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required (VERSION 3.1)

option(PROJ_LIB_TYPES "Use zSearch and zLib as static libs." "STATIC")
if (NOT PROJ_LIB_TYPES)
    set(PROJ_LIB_TYPES "STATIC")
endif()

message(STATUS "homeDir=${CMAKE_HOME_DIRECTORY}")
message(STATUS "listDir=${CMAKE_CURRENT_LIST_DIR}")

SET(isTop 0)
if ("${CMAKE_HOME_DIRECTORY}" STREQUAL "${CMAKE_CURRENT_LIST_DIR}")
	SET(isTop 1)
	message(STATUS "this is TOP: ${isTop}")
	set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
	message(STATUS "module path= ${CMAKE_MODULE_PATH}")
	include(Macros)
	# include(Init)
endif()

enable_testing()

project(zLib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY    ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY    ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY    ${CMAKE_BINARY_DIR}/bin)

set(CFLAG CMAKE_CXX_FLAGS_DEBUG)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++14 -fvisibility=hidden")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	string(REPLACE "/MD" "/MT" ${CFLAG} "${${CFLAG}}")
	message(STATUS "link flags: ${CMAKE_CXX_FLAGS_DEBUG}")
endif()

if (${isTop} EQUAL 1)
	message(STATUS "building as TOP, i.e. building zLib separately")
	set(GMOCK_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/gmock-1.7.0/include")
	set(GMOCK_LIB_DIR "${CMAKE_BINARY_DIR}/bin")

	set(GTEST_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/gmock-1.7.0/gtest/include")
	set(GTEST_LIB_DIR "${CMAKE_BINARY_DIR}/bin")

	message(STATUS "GMOCK_INCLUDE_DIR=${GMOCK_INCLUDE_DIR}")
	message(STATUS "GTEST_INCLUDE_DIR=${GTEST_INCLUDE_DIR}")
	message(STATUS "GMOCK_LIB_DIR=${GMOCK_LIB_DIR}")
	message(STATUS "GTEST_LIB_DIR=${GTEST_LIB_DIR}")

	if ("${PROJ_LIB_TYPES}" STREQUAL "STATIC")
		add_subdirectory(gmock-1.7.0)
	endif()
endif()

add_subdirectory(zLib)
add_subdirectory(Tests)
