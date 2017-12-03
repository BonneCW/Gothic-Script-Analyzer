#ifndef __GSA_SYSTEMPARAMETERS_H__
#define __GSA_SYSTEMPARAMETERS_H__

// Global platform specific defines
#define GSA_PLATFORM_WIN32 1
#define GSA_PLATFORM_LINUX 2
#define BOOST_ALL_DYN_LINK
#define WIN32_LEAN_AND_MEAN
// #define _WIN32_WINNT 0x0501
// Determine the current platform
#if defined(WIN32) || defined(__WIN32__) || defined(_WIN32)
	#define GSA_PLATFORM GSA_PLATFORM_WIN32
	#define WIN32_LEAN_AND_MEAN
#else
	#define GSA_PLATFORM GSA_PLATFORM_LINUX
#endif

// Debug/Release modes
#define GSA_DEBUG	1
#define GSA_RELEASE 2

#if defined(NDEBUG)
	#define GSA_MODE GSA_RELEASE
#else
	#define GSA_MODE GSA_DEBUG
#endif

#ifdef _MSC_VER
#pragma warning(disable : 4251) // dll interface to be used by clients...
#endif

#ifndef GSA_LIBRARY_API
	#if GSA_PLATFORM == GSA_PLATFORM_WIN32
		#ifdef ScriptAnalyzer_EXPORTS
			#define GSA_LIBRARY_API __declspec(dllexport)
		#else
			#define GSA_LIBRARY_API __declspec(dllimport)
		#endif
	#elif GSA_PLATFORM == GSA_PLATFORM_LINUX
		#define GSA_LIBRARY_API
	#else
		#define GSA_LIBRARY_API
	#endif
#endif

#endif /* __GSA_SYSTEMPARAMETERS_H__ */
