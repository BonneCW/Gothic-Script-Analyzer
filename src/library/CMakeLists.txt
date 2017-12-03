SET(srcdir ${CMAKE_CURRENT_SOURCE_DIR})
SET(includedir ${CMAKE_SOURCE_DIR}/include)

INCLUDE_DIRECTORIES(${includedir})

SET(ScriptAnalyzerSrc
	${srcdir}/ModuleInterface.cpp
)

ADD_LIBRARY(ScriptAnalyzer SHARED ${ScriptAnalyzerSrc})
