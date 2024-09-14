#pragma once




#ifndef REFLECTION7_VALUE
#define REFLECTION7_VALUE


#include "config.h"
#include "type.h"


#include <iosfwd>


namespace ref7 {
	class REFLECTION_API Value {
	public:

		Value();

		template <typename T> Value(const T& val);

		Value(const Value& other);

		Value(Value&& other);

		void operator = (const Value& other);

		ValueKind kind() const;

		template <typename T> T to() const;

		template <typename T> T& ref();

		template <typename T> const T& cref() const;

		template <typename T> bool isCompatible() const;

		//template <typename T> typename T::result_type visit(T visitor) const; //모르겠음

		bool operator == (const Value& other) const;

		bool operator != (const Value& other) const { return !(*this == other); }

		bool operator < (const Value& other) const;

		bool operator > (const Value& other) const
		{
			return !(*this < other || *this == other);
		}

		bool operator <= (const Value& other) const
		{
			return (*this < other || *this == other);
		}

		bool operator >= (const Value& other) const
		{
			return !(*this < other);
		}


		static const Value nothing;  //뭔지 모르겠다..

	private:



		ValueKind m_type;
	};


	REFLECTION_API std::istream& operator>>(std::istream& stream, Value& value);
	REFLECTION_API std::ostream& operator<<(std::ostream& stream, const Value& value);
}


#endif