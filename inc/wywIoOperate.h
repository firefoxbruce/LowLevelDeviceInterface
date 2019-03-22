#ifndef __WYW_IO_OPERATE_H__
#define __WYW_IO_OPERATE_H__
#include"wywIoOperate.h"

/****************function declear begin**************************/
s8 wyw_send(u8*data, wyw_size_t *dataSize, wyw_size_t operateDelay, u8 *retryTimes);
s8 wyw_recive(u8*buf, wyw_size_t *bufAReadSize, wyw_size_t operateDelay, u8 *retryTimes);
/****************function declear end**************************/

#endif //_WYW_IO_OPERATE_H
