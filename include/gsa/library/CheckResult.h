#ifndef __GSA_LIBRARY_CHECKRESULT_H__
#define __GSA_LIBRARY_CHECKRESULT_H__

#include "gsa/SystemParameters.h"

#include <QString>

namespace gsa {
namespace library {

	enum Module;
	enum class SeverityLevel;

	struct GSA_LIBRARY_API CheckResult {
		Module module;
		bool success = false;
		QString errorString;
		SeverityLevel level;

		bool operator==(const CheckResult & other) const {
			return module == other.module && success == other.success && errorString == other.errorString && level == other.level;
		}

		friend std::ostream & operator<<(std::ostream & out, const CheckResult & result) {
			out << "Module: " << result.module << ", Success: " << result.success << ", Level: " << int(result.level) << ", Error: " << result.errorString.toStdString();
			return out;
		}
	};

} /* namespace library */
} /* namespace gsa */

#endif /* __GSA_LIBRARY_CHECKRESULT_H__ */
