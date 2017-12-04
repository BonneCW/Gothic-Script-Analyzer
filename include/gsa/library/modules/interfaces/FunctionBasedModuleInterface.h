#ifndef __GSA_LIBRARY_MODULES_INTERFACES_FUNCTIONBASEDMODULEINTERFACE_H__
#define __GSA_LIBRARY_MODULES_INTERFACES_FUNCTIONBASEDMODULEINTERFACE_H__

#include "gsa/library/CheckResult.h"

#include "gsa/library/modules/interfaces/ModuleInterface.h"

namespace gsa {
namespace library {

	class GSA_LIBRARY_API FunctionBasedModuleInterface : public ModuleInterface {
	public:
		FunctionBasedModuleInterface(Module module);

		virtual ~FunctionBasedModuleInterface() {
		}

		virtual CheckResult checkFunction(QString function) = 0;
	};

} /* namespace library */
} /* namespace gsa */

#endif /* __GSA_LIBRARY_MODULES_INTERFACES_FUNCTIONBASEDMODULEINTERFACE_H__ */
