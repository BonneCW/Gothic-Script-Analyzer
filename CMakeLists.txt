cmake_minimum_required (VERSION 2.8.12)

#########################################################################
#########################################################################
#
# Global Build Configuration Options
#
#########################################################################

OPTION(WITH_TESTS "builds with tests" ON)

project(GothicScriptAnalyzer CXX)

SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 0)
SET(VERSION_PATCH 1)

INCLUDE(cmake/variables.cmake)

execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/bin)

#########################################################################
# Library Section
#########################################################################

INCLUDE(cmake/searchDependencies.cmake)

INCLUDE(cmake/addToBinDir.cmake)

INCLUDE_DIRECTORIES(include)

ADD_SUBDIRECTORY(src)
