#ifndef __GSA_LIBRARY_MODULES_LIBRARY_LINEBASEDMODULEINTERFACE_H__
#define __GSA_LIBRARY_MODULES_LIBRARY_LINEBASEDMODULEINTERFACE_H__

#include "gsa/library/CheckResult.h"

#include "gsa/library/modules/interfaces/ModuleInterface.h"

namespace gsa {
namespace library {

	class GSA_LIBRARY_API LineBasedModuleInterface : public ModuleInterface {
	public:
		LineBasedModuleInterface(Module module);

		virtual ~LineBasedModuleInterface() {
		}

		virtual CheckResult checkLine(QString line) = 0;
	};

} /* namespace library */
} /* namespace gsa */

#endif /* __GSA_LIBRARY_MODULES_LIBRARY_LINEBASEDMODULEINTERFACE_H__ */
