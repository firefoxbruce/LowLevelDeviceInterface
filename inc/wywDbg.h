#ifndef __WYW_DBG_H__
#define __WYW_DBG_H__
#include"wywDeviceMacro.h"

#ifdef WYW_MCU_PLATFORM
  #define check(A, M) 
#else
  #define check(A, M, ...)
#endif
