#ifndef __GSA_LIBRARY_MODULES_AIOUTPUTMODULE_H__
#define __GSA_LIBRARY_MODULES_AIOUTPUTMODULE_H__

#include "gsa/library/modules/interfaces/LineBasedModuleInterface.h"

namespace gsa {
namespace library {

	class GSA_LIBRARY_API AIOutputModule : public LineBasedModuleInterface {
	public:
		AIOutputModule();

		~AIOutputModule() {
		}

		CheckResult checkLine(QString line) override;
	};

} /* namespace library */
} /* namespace gsa */

#endif /* __GSA_LIBRARY_MODULES_AIOUTPUTMODULE_H__ */
