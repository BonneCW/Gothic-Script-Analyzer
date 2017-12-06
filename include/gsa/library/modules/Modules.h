#ifndef __GSA_LIBRARY_MODULES_MODULES_H__
#define __GSA_LIBRARY_MODULES_MODULES_H__

namespace gsa {
namespace library {

	enum Module {
		None = 0,

		AIOutput = 1 << 0,

		All = (1 << 1) - 1
	};

} /* namespace library */
} /* namespace gsa */

#endif /* __GSA_LIBRARY_MODULES_MODULES_H__ */
