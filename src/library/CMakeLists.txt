SET(srcdir ${CMAKE_CURRENT_SOURCE_DIR})
SET(includedir ${CMAKE_SOURCE_DIR}/include)

INCLUDE_DIRECTORIES(${includedir})

SET(ScriptAnalyzerHeader
	${includedir}/gsa/SystemParameters.h
	
	${includedir}/gsa/library/CheckResult.h

	${includedir}/gsa/library/modules/Modules.h
	
	${includedir}/gsa/library/modules/interfaces/FunctionBasedModuleInterface.h
	${includedir}/gsa/library/modules/interfaces/LineBasedModuleInterface.h
	${includedir}/gsa/library/modules/interfaces/ModuleInterface.h
)

SET(ScriptAnalyzerSrc
	${srcdir}/modules/interfaces/FunctionBasedModuleInterface.cpp
	${srcdir}/modules/interfaces/LineBasedModuleInterface.cpp
	${srcdir}/modules/interfaces/ModuleInterface.cpp
)

SOURCE_GROUP(modules /modules/*)
SOURCE_GROUP(modules\\interfaces /modules/interfaces/*)

ADD_LIBRARY(ScriptAnalyzer SHARED ${ScriptAnalyzerSrc} ${ScriptAnalyzerHeader})

TARGET_LINK_LIBRARIES(ScriptAnalyzer ${QT_LIBRARIES})
