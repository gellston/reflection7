#pragma once


#include "../config.h"


namespace ref7 {
	namespace detail {
		template <typename T> struct staticTypeDecl;
		template <typename T> constexpr const char* staticTypeName(T&);
		REFLECTION_API void ensureTypeRegistered(TypeId const& id, void (*registerFunc)());
	}
}