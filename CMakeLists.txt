cmake_minimum_required(VERSION 3.25)
project(DMS-Pi-Dash LANGUAGES CXX)

set(SOURCES can/CanDecoder.cpp gui/Clock.cpp gui/Gauge.cpp gui/GaugeCluster.cpp PiDash.cpp Main.cpp)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-4.0)
message(STATUS "lib dir:" ${GTKMM_LIBRARY_DIRS})
message(STATUS "include dir:" ${GTKMM_INCLUDE_DIRS})
include_directories(file ${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
add_definitions(${GTK_CFLAGS_OTHER})
add_executable(main ${SOURCES})
target_link_libraries(main ${GTK_LIBRARIES})
