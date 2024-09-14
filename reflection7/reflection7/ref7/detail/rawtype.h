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

        /**
         * \class DataType
         *
         * \brief Helper structure used to extract the raw type of a composed type
         *
         * DataType<T> recursively removes const, reference and pointer modifiers from the given type.
         * In other words:
         *
         * \li DataType<T>::Type == T
         * \li DataType<const T>::Type == DataType<T>::Type
         * \li DataType<T&>::Type == DataType<T>::Type
         * \li DataType<const T&>::Type == DataType<T>::Type
         * \li DataType<T*>::Type == DataType<T>::Type
         * \li DataType<const T*>::Type == DataType<T>::Type
         *
         * \remark DataType is able to detect smart pointers and properly extract the stored type
         */

         // Generic version -- T doesn't match with any of our specialization, and is thus considered a raw data type
         //  - int -> int, int[] -> int, int* -> int.
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