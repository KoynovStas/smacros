#ifndef SIMPLE_MACROS_HEADER
#define SIMPLE_MACROS_HEADER





#ifdef  __cplusplus
        #define  EXTERN_PREFIX extern "C"
#else
        #define  EXTERN_PREFIX extern
#endif





#define  SET_BIT(reg, num_bit)   (reg |=  (1 << num_bit) )
#define  CLR_BIT(reg, num_bit)   (reg &= ~(1 << num_bit) )
#define  INV_BIT(reg, num_bit)   (reg ^=  (1 << num_bit) )



#define  SET_FLAG(reg, flag)   (reg |=  (flag) )
#define  CLR_FLAG(reg, flag)   (reg &= ~(flag) )
#define  INV_FLAG(reg, flag)   (reg ^=  (flag) )





#undef  ATOMIC_OPP  //Atomic operations and command not supported



#if (__STDC_VERSION__ >= 201112L) && (__STDC_NO_ATOMICS__ != 1)
// The implementation supports atomic types and <stdatomic.h> (C11)
// C is ISO/IEC 9899:2011 (C11) and __STDC_NO_ATOMICS__ is not defined
// __STDC_NO_ATOMICS__ see in 6.10.8.3 Conditional feature macros (standart C11)
// __STDC_VERSION__ in gcc defined if set -std=c11


    #define  ATOMIC_OPP     //Atomic operations supported
    #include <stdatomic.h>


#endif //#if (__STDC_VERSION__ >= 201112L) && (__STDC_NO_ATOMICS__ != 1)




#if    !defined(  ATOMIC_OPP  )   \
    && (defined(__ARM_ARCH_6__)   \
    ||  defined(__ARM_ARCH_6J__)  \
    ||  defined(__ARM_ARCH_6K__)  \
    ||  defined(__ARM_ARCH_6Z__)  \
    ||  defined(__ARM_ARCH_6ZK__) \
    ||  defined(__ARM_ARCH_7__)   \
    ||  defined(__ARM_ARCH_7A__)  \
    ||  defined(__ARM_ARCH_7R__) )


    #define  ATOMIC_OPP        //Atomic operations supported
    #include "atomic_arm.h"    //use our atomic functions
                               //You need add file atomic_arm.S to list of source files to compile.
                               //(see an example: https://github.com/KoynovStas/atomic_arm)


#endif //ifdef __ARM_ARCH_XXX__



#ifdef ATOMIC_OPP

    #define  ATOMIC_SET_BIT(reg, num_bit)  atomic_fetch_or( &reg,  (1 << num_bit))
    #define  ATOMIC_CLR_BIT(reg, num_bit)  atomic_fetch_and(&reg, ~(1 << num_bit))
    #define  ATOMIC_INV_BIT(reg, num_bit)  atomic_fetch_xor(&reg,  (1 << num_bit))


    #define  ATOMIC_SET_FLAG(reg, flag)  atomic_fetch_or( &reg,  (flag))
    #define  ATOMIC_CLR_FLAG(reg, flag)  atomic_fetch_and(&reg, ~(flag))
    #define  ATOMIC_INV_FLAG(reg, flag)  atomic_fetch_xor(&reg,  (flag))


#endif //#ifdef ATOMIC_OPP





//The count of elements in the array.
#define  COUNT_ELEMENTS(array) (sizeof(array) / sizeof(array[0]))





#endif //SIMPLE_MACROS_HEADER
