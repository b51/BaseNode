cmake_minimum_required(VERSION 2.8.3)
project(BaseNode)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

#########################################################################
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
  message(STATUS "No build type selected, default to ${CMAKE_BUILD_TYPE}")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -fPIC")
else(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fPIC")
endif(CMAKE_BUILD_TYPE STREQUAL "Release")
#########################################################################

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  GoogleDeps
)

list(APPEND CMAKE_PREFIX_PATH ${GoogleDeps_SOURCE_PREFIX}/share/cartographer)

find_package(Boost REQUIRED COMPONENTS system iostreams)

find_package(cartographer REQUIRED)
include("${CARTOGRAPHER_CMAKE_DIR}/functions.cmake")
option(BUILD_GRPC "build features that require Cartographer gRPC support" false)
google_initialize_cartographer_project()
google_enable_testing()

include(FindPkgConfig)
find_package(Abseil REQUIRED)
find_package(LuaGoogle REQUIRED)
find_package(Eigen3 REQUIRED)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp
)

###########
## Build ##
###########

if (CMAKE_BUILD_TYPE STREQUAL Debug)
  add_definitions(-DDEBUG)
endif()

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}
  src/NodeMain.cc
  src/Node.cc
)

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}
  cartographer
  ${catkin_LIBRARIES}
)
