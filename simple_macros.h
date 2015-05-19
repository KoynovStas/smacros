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





#endif //SIMPLE_MACROS_HEADER
