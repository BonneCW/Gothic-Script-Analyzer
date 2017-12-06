SET(srcdir ${CMAKE_CURRENT_SOURCE_DIR})
SET(includedir ${CMAKE_SOURCE_DIR}/include)

INCLUDE_DIRECTORIES(${includedir})

SET(ScriptAnalyzerHeader
	${includedir}/gsa/SystemParameters.h
	
	${includedir}/gsa/library/CheckResult.h
	${includedir}/gsa/library/FileParser.h
	${includedir}/gsa/library/SeverityLevel.h
	
	${includedir}/gsa/library/modules/AIOutputModule.h
	${includedir}/gsa/library/modules/Modules.h
	
	${includedir}/gsa/library/modules/interfaces/FunctionBasedModuleInterface.h
	${includedir}/gsa/library/modules/interfaces/LineBasedModuleInterface.h
	${includedir}/gsa/library/modules/interfaces/ModuleInterface.h
)

SET(ScriptAnalyzerSrc
	${srcdir}/FileParser.cpp

	${srcdir}/modules/AIOutputModule.cpp

	${srcdir}/modules/interfaces/FunctionBasedModuleInterface.cpp
	${srcdir}/modules/interfaces/LineBasedModuleInterface.cpp
	${srcdir}/modules/interfaces/ModuleInterface.cpp
)

SOURCE_GROUP(modules /modules/*)
SOURCE_GROUP(modules\\interfaces /modules/interfaces/*)

ADD_LIBRARY(ScriptAnalyzer SHARED ${ScriptAnalyzerSrc} ${ScriptAnalyzerHeader})

IF(WIN32)
	add_custom_command(TARGET ScriptAnalyzer POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_BINARY_DIR}/bin/$<CONFIGURATION>/ScriptAnalyzer.dll ${CMAKE_BINARY_DIR}/bin)
ENDIF(WIN32)

TARGET_LINK_LIBRARIES(ScriptAnalyzer ${QT_LIBRARIES})
