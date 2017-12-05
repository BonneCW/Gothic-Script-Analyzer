#include "gsa/library/FileParser.h"

#include "gsa/library/modules/interfaces/FunctionBasedModuleInterface.h"
#include "gsa/library/modules/interfaces/LineBasedModuleInterface.h"

#include <QFile>
#include <QTextStream>

namespace gsa {
namespace library {

	FileParser::FileParser(QList<ModuleInterface *> modules) : _modules(modules) {
		for (ModuleInterface * module : modules) {
			FunctionBasedModuleInterface * functionBasedModule = dynamic_cast<FunctionBasedModuleInterface *>(module);
			LineBasedModuleInterface * lineBasedModule = dynamic_cast<LineBasedModuleInterface *>(module);
			if (functionBasedModule) {
				_functionBasedModules.append(functionBasedModule);
			}
			if (lineBasedModule) {
				_lineBasedModules.append(lineBasedModule);
			}
		}
	}

	QList<CheckResult> FileParser::parseFile(QString filename) {
		QList<CheckResult> results;

		QFile inFile(filename);
		if (inFile.open(QIODevice::ReadOnly)) {
			QTextStream inStream(&inFile);
			while (!inStream.atEnd()) {
				QString line = inStream.readLine();
				for (LineBasedModuleInterface * lineBasedModule : _lineBasedModules) {
					results.append(lineBasedModule->checkLine(line));
				}
			}
		}

		return results;
	}

} /* namespace library */
} /* namespace gsa */
