#ifndef _VECENT_IO_OPERATE_H
#define _VECENT_IO_OPERATE_H


/****************function declear begin**************************/
s8 vecent_send(u8*data, vc_size_t dataSize, vc_size_t operateDelay, u8 *retryTimes);
s8 vecent_recive(u8*buf, vc_size_t bufSize, vc_size_t operateDelay, u8 *retryTimes);
/****************function declear end**************************/

#endif //_VECENT_IO_OPERATE_H
