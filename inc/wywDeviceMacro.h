#ifndef __WYW_DEVICE_MACRO_H__
#define __WYW_DEVICE_MACRO_H__


/**********define the target platform begin************/
#define WYW_MCU_PLATFORM
#define WYW_ARM_LINUX_PLATFORM
#define WYW_ARM_ANDROID_PLATFORM
/**********define the target platform end************/

/**********define the printf switch only for mcu begin************/
#ifdef WYW_MCU_PLATFORM
//#define WYW_PRINTF_SWITCH_OFF
#endif
/**********define the printf switch only for mcu end***********/

/**********define debug log level begin***********/
//#define WYW_NORMAL_LOG
//#define WYW_DEBUG_LOG

#ifdef WYW_DEBUG_LOG
  #ifndef WYW_NORMAL_LOG
    #define WYW_NORMAL_LOG
  #endif
#endif //VENCENT_DEBUG_LOG_ENABLE
/**********define debug log level end***********/

/**********define the LOG TAG begin*****************/
#ifdef WYW_MCU_PLATFORM
  #define WYW_LOG_TAG     "WYW_MCU:"
#elif defined WYW_ARM_LINUX_PLATFORM
  #define WYW_LOG_TAG     "WYW_ARM_LINUX:"
#elif defined WYW_ARM_ANDROID_PLATFORM
  #define WYW_LOG_TAG     "WYW_ARM_ANDROID:"
#else
  #define WYW_LOG_TAG     "WYW_LOCAL:"
#endif
/**********define the LOG TAG end*****************/

/**********define the LOG PRINTF begin************/
#ifdef WYW_MCU_PLATFORM
  #ifdef WYW_PRINTF_SWITCH_OFF
    #define WYW_PRINTF()  
    #define WYW_PRINTF_1(n1)
    #define WYW_PRINTF_2(n1, n2)
  #else
    #define WYW_PRINTF()  
    #define WYW_PRINTF_1(n1)
    #define WYW_PRINTF_2(n1, n2)
  #endif
#elif defined WYW_ARM_LINUX_PLATFORM
  #include<stdio.h>
  #define WYW_PRINTF(n, ...) printf(WYW_LOG_TAG, n, ##__VA_ARGS__)
  #define WYW_PRINTF_1(n, ...) WYW_PRINTF(n, ##__VA_ARGS__)
  #define WYW_PRINTF_2(n, ...) WYW_PRINTF(n, ##__VA_ARGS__)
#elif defined WYW_ARM_ANDROID_PLATFORM
  #include<android/log.h>
  #define WYW_PRINTF( ...) __android_log_print(ANDROID_LOG_DEBUG, WYW_LOG_TAG, __VA_ARGS__)
  #define WYW_PRINTF_1(n1) WYW_PRINTF(n1)
  #define WYW_PRINTF_2(n1, n2) WYW_PRINTF(n1, n2)
#else
  #include<stdio.h>
  #define WYW_PRINTF(n, ...) printf(WYW_LOG_TAG, n, ##__VA_ARGS__)
  #define WYW_PRINTF_1(n, ...) WYW_PRINTF(n, ##__VA_ARGS__)
  #define WYW_PRINTF_2(n, ...) WYW_PRINTF(n, ##__VA_ARGS__)
#endif
/**********define the LOG PRINTF end************/

/**********define the data type& function macro begin***********/
#ifdef WYW_MCU_PLATFORM
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

  #define WYW_EMPTY_POINTER  ((void *)0)
  typedef u32 wyw_size_t;

  #define WYW_CREAT_TIME_M(waitTime) 
  #define WYW_SET_TIME_M(waitTime, n)
  #define WYW_DELAY_TIME_M(waitTime)
  #define WYW_IO_WRITE_F(data, dataSize)
  #define WYW_IO_READ_F(buf, bufSize)

#elif defined WYW_ARM_LINUX_PLATFORM
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

  #define WYW_EMPTY_POINTER  NULL
  typedef u32 wyw_size_t;

  #define WYW_CREAT_TIME_M(waitTime) 
  #define WYW_SET_TIME_M(waitTime, n)
  #define WYW_DELAY_TIME_M(waitTime)
  #define WYW_IO_WRITE_F(data, dataSize)
  #define WYW_IO_READ_F(buf, bufSize)

#elif defined WYW_ARM_ANDROID_PLATFORM
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

  #define WYW_EMPTY_POINTER  NULL
  typedef u32 wyw_size_t;
 
  #define WYW_CREAT_TIME_M(waitTime) 
  #define WYW_SET_TIME_M(waitTime, n)
  #define WYW_DELAY_TIME_M(waitTime)
  #define WYW_IO_WRITE_F(data, dataSize)
  #define WYW_IO_READ_F(buf, bufSize)

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

  #define WYW_EMPTY_POINTER  NULL
  typedef u32 wyw_size_t;

  #define WYW_CREAT_TIME_M(waitTime) 
  #define WYW_SET_TIME_M(waitTime, n)
  #define WYW_DELAY_TIME_M(waitTime)
  #define WYW_IO_WRITE_F(data, dataSize)
  #define WYW_IO_READ_F(buf, bufSize)
#endif
/**********define the data type& function macro end***********/
#endif //_DEVICE_MACRO_H
