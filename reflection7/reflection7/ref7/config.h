#pragma once


#ifndef REFLECTION7_CONFIG
#define REFLECTION7_CONFIG



#ifndef REFLECTION7_EXPORT
#define REFLECTION7_API __declspec(dllimport)
#else 
#define REFLECTION_API __declspec(dllexport)
#endif


#define REFLECTION7__NON_COPYABLE(CLS) \
CLS(CLS const&) = delete; \
CLS& operator=(CLS const&) = delete




#endif