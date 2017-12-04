#ifndef __GSA_LIBRARY_CHECKRESULT_H__
#define __GSA_LIBRARY_CHECKRESULT_H__

#include "gsa/SystemParameters.h"

#include <QString>

namespace gsa {
namespace library {

	enum Module;

	struct GSA_LIBRARY_API CheckResult {
		Module module;
		bool success;
		QString errorString;
	};

} /* namespace library */
} /* namespace gsa */

#endif /* __GSA_LIBRARY_CHECKRESULT_H__ */
