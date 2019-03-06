#ifndef _DEVICE_MACRO_H
#define _DEVICE_MACRO_H

/**********define the target platform begin************/
#define VECENT_MCU_PLATFORM
#define VECENT_ARM_LINUX_PLATFORM
#define VECENT_ARM_ANDROID_PLATFORM
/**********define the target platform end************/

/**********define debug log level begin***********/
//#define VECENT_NORMAL_LOG
//#define VECENT_DEBUG_LOG

#ifdef VECENT_DEBUG_LOG
  #ifndef VECENT_NORMAL_LOG
    #define VECENT_NORMAL_LOG
  #endif
#endif //VENCENT_DEBUG_LOG_ENABLE
/**********define debug log level end***********/

/**********define the LOG TAG begin*****************/
#ifdef VECENT_MCU_PLATFORM
  #define VECENT_LOG_TAG     "VECENT_MCU:"
#elif defined VECENT_ARM_LINUX_PLATFORM
  #define VECENT_LOG_TAG     "VECENT_ARM_LINUX:"
#elif defined VECENT_ARM_ANDROID_PLATFORM
  #define VECENT_LOG_TAG     "VECENT_ARM_ANDROID:"
#else
  #define VECENT_LOG_TAG     "VECENT_LOCAL:"
#endif
/**********define the LOG TAG end*****************/

/**********define the LOG PRINTF begin************/
#ifdef VECENT_MCU_PLATFORM
  #define VECENT_PRINTF()  
  #define VECENT_PRINTF_1(n1)
  #define VECENT_PRINTF_2(n1, n2)
#elif defined VECENT_ARM_LINUX_PLATFORM
  #include<stdio.h>
  #define VECENT_PRINTF(n, ...) printf(VECENT_LOG_TAG, n, ##__VA_ARGS__)
  #define VECENT_PRINTF_1(n, ...) VECENT_PRINTF(n, ##__VA_ARGS__)
  #define VECENT_PRINTF_2(n, ...) VECENT_PRINTF(n, ##__VA_ARGS__)
#elif defined VECENT_ARM_ANDROID_PLATFORM
  #include<android/log.h>
  #define VECENT_PRINTF( ...) __android_log_print(ANDROID_LOG_DEBUG, VECENT_LOG_TAG, __VA_ARGS__)
  #define VECENT_PRINTF_1(n1) VECENT_PRINTF(n1)
  #define VECENT_PRINTF_2(n1, n2) VECENT_PRINTF(n1, n2)
#else
  #include<stdio.h>
  #define VECENT_PRINTF(n, ...) printf(VECENT_LOG_TAG, n, ##__VA_ARGS__)
  #define VECENT_PRINTF_1(n, ...) VECENT_PRINTF(n, ##__VA_ARGS__)
  #define VECENT_PRINTF_2(n, ...) VECENT_PRINTF(n, ##__VA_ARGS__)
#endif
/**********define the LOG PRINTF end************/

/**********define the data type& function macro begin***********/
#ifdef VECENT_MCU_PLATFORM
  typedef signed char s8;
  typedef signed short s16;
  typedef signed int  s32;
  typedef signed long s64;
  typedef unsigned char u8;
  typedef unsigned short u16;
  typedef unsigned int u32;
  typedef unsigned long u64;
  
  #ifndef false
    #define false -1
  #endif
  
  #ifndef true
    #define true 0
  #endif

  #define VECENT_EMPTY_POINTER  ((void *)0)
  typedef u32 vc_size_t;

  #define VECENT_CREAT_TIME_M(waitTime) 
  #define VECENT_SET_TIME_M(waitTime, n)
  #define VECENT_DELAY_TIME_M(waitTime)
  #define VECENT_IO_WRITE_F(data, dataSize)
  #define VECENT_IO_READ_F(buf, bufSize)

#elif defined VECENT_ARM_LINUX_PLATFORM
  typedef signed char s8;
  typedef signed short s16;
  typedef signed int  s32;
  typedef signed long s64;
  typedef unsigned char u8;
  typedef unsigned short u16;
  typedef unsigned int u32;
  typedef unsigned long u64;

  #ifndef false
    #define false -1
  #endif
  
  #ifndef true
    #define true 0
  #endif

  #define VECENT_EMPTY_POINTER  NULL
  typedef u32 vc_size_t;

  #define VECENT_CREAT_TIME_M(waitTime) 
  #define VECENT_SET_TIME_M(waitTime, n)
  #define VECENT_DELAY_TIME_M(waitTime)
  #define VECENT_IO_WRITE_F(data, dataSize)
  #define VECENT_IO_READ_F(buf, bufSize)

#elif defined VECENT_ARM_ANDROID_PLATFORM
  typedef signed char s8;
  typedef signed short s16;
  typedef signed int  s32;
  typedef signed long s64;
  typedef unsigned char u8;
  typedef unsigned short u16;
  typedef unsigned int u32;
  typedef unsigned long u64;

  #ifndef false
    #define false -1
  #endif
  
  #ifndef true
    #define true 0
  #endif

  #define VECENT_EMPTY_POINTER  NULL
  typedef u32 vc_size_t;
 
  #define VECENT_CREAT_TIME_M(waitTime) 
  #define VECENT_SET_TIME_M(waitTime, n)
  #define VECENT_DELAY_TIME_M(waitTime)
  #define VECENT_IO_WRITE_F(data, dataSize)
  #define VECENT_IO_READ_F(buf, bufSize)

#else
  typedef signed char s8;
  typedef signed short s16;
  typedef signed int  s32;
  typedef signed long s64;
  typedef unsigned char u8;
  typedef unsigned short u16;
  typedef unsigned int u32;
  typedef unsigned long u64;

  #ifndef false
    #define false -1
  #endif
  
  #ifndef true
    #define true 0
  #endif

  #define VECENT_EMPTY_POINTER  NULL
  typedef u32 vc_size_t;

  #define VECENT_CREAT_TIME_M(waitTime) 
  #define VECENT_SET_TIME_M(waitTime, n)
  #define VECENT_DELAY_TIME_M(waitTime)
  #define VECENT_IO_WRITE_F(data, dataSize)
  #define VECENT_IO_READ_F(buf, bufSize)
#endif
/**********define the data type& function macro end***********/
#endif //_DEVICE_MACRO_H
