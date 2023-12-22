#pragma once

#if PL_DEBUG == 2
#define PL_ERROR(X) std::cout << X << std::endl;
#define PL_LOG(X) std::cout << X << std::endl;

#elif PL_DEBUG == 1
#define PL_ERROR(X) std::cout << X << std::endl;
#define PL_LOG(X)

#else 
#define PL_ERROR(X)
#define PL_LOG(X) 
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

#define PLATINUM_APPLICATION_START(ClassName) \
int main()\
{\
    ClassName::Init();\
    ClassName::RunInterface();\
    return(0);\
}