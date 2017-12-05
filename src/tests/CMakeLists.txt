SET(srcdir ${CMAKE_CURRENT_SOURCE_DIR})
SET(includedir ${CMAKE_SOURCE_DIR}/include)

INCLUDE_DIRECTORIES(${includedir})

SET(UnitTesterSrc
	${srcdir}/main.cpp
	
	${srcdir}/test_FileParser.cpp
	${srcdir}/test_Module_AIOutput.cpp
)

ADD_EXECUTABLE(UnitTester ${UnitTesterSrc})

target_link_libraries(UnitTester ScriptAnalyzer ${GTEST_LIBRARIES})

IF(UNIX)
	target_link_libraries(UnitTester pthread)
ENDIF(UNIX)

IF(WIN32)
	add_custom_command(TARGET UnitTester POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_BINARY_DIR}/bin/$<CONFIGURATION>/UnitTester.exe ${CMAKE_BINARY_DIR}/bin)
ENDIF(WIN32)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/FileParser_LineBased.d ${CMAKE_BINARY_DIR}/bin/tests/FileParser_LineBased.d COPYONLY)
