#ifndef _WYW_IO_OPERATE_H
#define _WYW_IO_OPERATE_H
#include"deviceMacro.h"

/****************function declear begin**************************/
s8 wyw_send(u8*data, wyw_size_t dataSize, wyw_size_t operateDelay, u8 *retryTimes);
s8 wyw_recive(u8*buf, wyw_size_t bufSize, wyw_size_t operateDelay, u8 *retryTimes);
/****************function declear end**************************/

#endif //_WYW_IO_OPERATE_H
