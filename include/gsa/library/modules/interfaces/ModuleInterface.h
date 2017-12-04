#ifndef __GSA_LIBRARY_MODULES_INTERFACES_MODULEINTERFACE_H__
#define __GSA_LIBRARY_MODULES_INTERFACES_MODULEINTERFACE_H__

#include "gsa/SystemParameters.h"

namespace gsa {
namespace library {

	enum Module;

	class GSA_LIBRARY_API ModuleInterface {
	public:
		ModuleInterface(Module module);

		virtual ~ModuleInterface() {
		}

		Module getModule() const {
			return _module;
		}

	private:
		Module _module;
	};

} /* namespace library */
} /* namespace gsa */

#endif /* __GSA_LIBRARY_MODULES_INTERFACES_MODULEINTERFACE_H__ */
