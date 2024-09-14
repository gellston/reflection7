#pragma once


#ifndef REFLECTION7_CLASS
#define REFLECTION7_CLASS


#include "config.h"
#include "type.h"

#include <memory>
#include <vector>

namespace ref7 {
	template<typename T> class ClassBuilder;
	class Constructor;
	class Args;
	class ClassVisitor;


	class REFLECTION_API Class : public Type {

		REFLECTION7__NON_COPYABLE(Class);

		struct BaseInfo {
			const Class* base;
			int offset;
		};

		using ConstructorPtr = std::shared_ptr<Constructor>;
		// Property Ptr
		// Function Ptr

		using BaseList = std::vector<BaseInfo>;

	public:

	};
}




#endif