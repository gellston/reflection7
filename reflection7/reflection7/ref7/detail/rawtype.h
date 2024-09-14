#pragma once


#ifndef REFLECTION7_DETAIL_RAWTYPE
#define REFLECTION7_DETAIL_RAWTYPE

#include <memory>

namespace ref7 {
	namespace detail {

        //smart pointer
        template <typename T, typename U>
        struct IsSmartPointer
        {
            static constexpr bool value = false;
        };

        //unique_ptr
        template <typename T, typename U>
        struct IsSmartPointer<std::unique_ptr<T>, U>
        {
            static constexpr bool value = true;
        };

        //shared_ptr
        template <typename T, typename U>
        struct IsSmartPointer<std::shared_ptr<T>, U>
        {
            static constexpr bool value = true;
        };

    
        template <typename T, typename E = void>
        struct DataType
        {
            typedef T Type;
        };

        // const
        template <typename T>
        struct DataType<const T> : public DataType<T> {};

        // reference
        template <typename T>
        struct DataType<T&> : public DataType<T> {};

        // pointer
        template <typename T>
        struct DataType<T*> : public DataType<T> {};

        // array
        template <typename T, size_t N>
        struct DataType<T[N]> : public DataType<T> {};

        // smart pointer
        template <template <typename> class T, typename U>
        struct DataType<T<U>, typename std::enable_if<IsSmartPointer<T<U>, U>::value >::type>
        {
            typedef typename DataType<U>::Type Type;
        };

    }


    template<class T>
    T* get_pointer(T* p)
    {
        return p;
    }

    template<class T>
    T* get_pointer(std::unique_ptr<T> const& p)
    {
        return p.get();
    }

    template<class T>
    T* get_pointer(std::shared_ptr<T> const& p)
    {
        return p.get();
    }

}

#endif