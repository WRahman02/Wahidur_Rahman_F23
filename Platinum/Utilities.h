#pragma once

#if PL_DEBUG == 2
	#define PL_ERROR(x) std::cout << x << std::endl;
	#define PL_LOG(x) std::cout << x << std::endl;

#elif PL_DEBUG == 1
	#define PL_ERROR(x) std::cout << x << std::endl;
	#define PL_LOG(x)
#else
	#define PL_ERROR(x)
	#define PL_LOG(x)
#endif

#ifdef PLATINUM_MSCPP
	#ifdef PLATINUM_LIB
		#define PLATINUM_API __declspec(dllexport)
	#else
		#define PLATINUM_API __declspec(dllimport)
	#endif
#else
	#define PLATINUM_API
#endif

#define PLATINUM_APPLICATION_START(ClassName)\
int main()\
{\
	ClassName::Init();\
	ClassName::RunInterface();\
	return (0);\
}