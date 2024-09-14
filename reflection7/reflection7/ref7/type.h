#pragma once


#ifndef REFLECTION7_TYPE
#define REFLECTION7_TYPE


#include "config.h"


#include <typeindex>


namespace ref7 {

	class Value;

	typedef std::type_index TypeID;


	struct NoType {

	};

	enum class ValueKind {
        None,      
        Boolean,   
        Integer,   
        Real,      
        String,    
        Enum,      
        Array,     
        Reference, 
        User       
	};

    enum class ReferenceKind
    {
        None,               
        Instance,           
        Pointer,            
        Reference,          
        SmartPointer,       
        BuiltinArray, //wth?
    };

    enum class FunctionKind
    {
        None,           
        Function,       
        MemberFunction, 
        FunctionWrapper,
        BindExpression, 
        Lambda          
    };


    enum class PropertyKind
    {
        Function,         
        MemberObject      
    };

    enum class PropertyAccessKind
    {
        Simple,
        Enum,
        Container,
        User
    };

    class REFLECTION_API Type
    {
    public:
        virtual ~Type() {}
    };


    namespace policy {
        enum class ReturnKind
        {
            NoReturn,    
            Copy,
            InternalRef,
            Multiple
        };

        enum class ParameterKind
        {
            PassByValue, 
            PassByReference,
        };

        struct ReturnCopy
        {
            static constexpr ReturnKind kind = ReturnKind::Copy;
        };

        struct ReturnInternalRef
        {
            static constexpr ReturnKind kind = ReturnKind::InternalRef;
        };

        struct ReturnMultiple
        {
            static constexpr ReturnKind kind = ReturnKind::Multiple;
        };


        struct Parameter
        {

        };
    }
}





#endif