#define osdNumberOfNonTrustedFunctions 38
typedef uint16                 TrustedFunctionIndexType;
typedef void*                    TrustedFunctionParameterRefType;
typedef TrustedFunctionIndexType NonTrustedFunctionIndexType;
typedef TrustedFunctionParameterRefType NonTrustedFunctionParameterRefType;
extern uint8 CallTrustedFunction(TrustedFunctionIndexType, TrustedFunctionParameterRefType);
extern uint8 CallNonTrustedFunction(NonTrustedFunctionIndexType, NonTrustedFunctionParameterRefType);
