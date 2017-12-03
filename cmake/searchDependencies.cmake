SET(CMAKE_LIBRARY_PATH ${GOTHICSCRIPTANALYZER_DEP_DIR})

#----------------------------------------------------
# GMock
#----------------------------------------------------

IF(WITH_TESTS)
	IF(WIN32 AND NOT ANDROID AND NOT EXISTS "${GOTHICSCRIPTANALYZER_DEP_DIR}/gmock/")
		execute_process(COMMAND ${CMAKE_SOURCE_DIR}/dependencies/build-gmock.bat ${VS_TOOLCHAIN} ${VS_ARCH} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/dependencies)
	ENDIF(WIN32 AND NOT ANDROID AND NOT EXISTS "${GOTHICSCRIPTANALYZER_DEP_DIR}/gmock/")
	IF(UNIX AND NOT ANDROID AND NOT EXISTS "${GOTHICSCRIPTANALYZER_DEP_DIR}/gmock/")
		execute_process(COMMAND ${CMAKE_SOURCE_DIR}/dependencies/build-gmock.sh ${UNIX_COMPILER} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/dependencies)
	ENDIF(UNIX AND NOT ANDROID AND NOT EXISTS "${GOTHICSCRIPTANALYZER_DEP_DIR}/gmock/")
	SET(LIBNAME "GTEST")
	SET(LIBHEADER "gtest/gtest.h")
	SET(GTEST_ROOT ${GOTHICSCRIPTANALYZER_DEP_DIR}/gmock)
	SET(GTEST_COMPONENT ${GTEST_COMPONENT} gtest)

	find_package(EasyFind REQUIRED COMPONENTS ${GTEST_COMPONENT})
	include_directories(SYSTEM ${GTEST_INCLUDE_DIR})
ENDIF(WITH_TESTS)
