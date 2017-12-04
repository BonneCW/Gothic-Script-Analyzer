SET(srcdir ${CMAKE_CURRENT_SOURCE_DIR})
SET(includedir ${CMAKE_SOURCE_DIR}/include)

INCLUDE_DIRECTORIES(${includedir})

SET(ScriptAnalyzerHeader
	${includedir}/gsa/library/CheckResult.h

	${includedir}/gsa/library/modules/interfaces/LineBasedModuleInterface.h
	${includedir}/gsa/library/modules/interfaces/ModuleInterface.h
)

SET(ScriptAnalyzerSrc
	${srcdir}/modules/interfaces/LineBasedModuleInterface.cpp
	${srcdir}/modules/interfaces/ModuleInterface.cpp
)

ADD_LIBRARY(ScriptAnalyzer SHARED ${ScriptAnalyzerSrc} ${ScriptAnalyzerHeader})

TARGET_LINK_LIBRARIES(ScriptAnalyzer ${QT_LIBRARIES})
