project(RA)
cmake_minimum_required(VERSION 2.8.9)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wextra -Werror -Wall -Wcast-align -Wempty-body -Wformat-security -Winit-self -Warray-bounds")

set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS_DEBUG} -g3 -O0")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2")

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# So we can find our cmake files in /cmake
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(PkgConfig)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(CHECK_LINUX_DRIVERS 1)
endif()

configure_file(${CMAKE_SOURCE_DIR}/include/RA_config.h.cmake ${CMAKE_BINARY_DIR}/include/RA_config.h)

add_subdirectory(include)
add_subdirectory(src)
