#ifndef __GSA_LIBRARY_FILEPARSER_H__
#define __GSA_LIBRARY_FILEPARSER_H__

#include "gsa/library/CheckResult.h"

#include <QList>

namespace gsa {
namespace library {

	class FunctionBasedModuleInterface;
	class LineBasedModuleInterface;
	class ModuleInterface;

	class GSA_LIBRARY_API FileParser {
	public:
		FileParser(QList<ModuleInterface *> modules);

		QList<CheckResult> parseFile(QString filename);

	private:
		QList<ModuleInterface *> _modules;
		QList<LineBasedModuleInterface *> _lineBasedModules;
		QList<FunctionBasedModuleInterface *> _functionBasedModules;
	};

} /* namespace library */
} /* namespace gsa */

#endif /* __GSA_LIBRARY_FILEPARSER_H__ */
