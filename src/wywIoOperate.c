#include"wywIoOperate.h"
/*WYW_COMMUNICATION  s8 res = false;*/
#define WYW_COMMUNICATION_M(operate, buf, bufSize, operateDelay, retryTimes) \
                {                                                               \
                   WYW_CREAT_TIME(waitTime);                                 \
                   do                                                           \
                   {                                                            \
                     res = operate##_F(buf, bufSize);                           \
                     if(false != res)                                           \
                     {                                                          \
                       PRINTF_1( #operate" success\n");                         \
                       break;                                                   \
                     }                                                          \
                     WYW_SET_TIME(waitTime, operateDelay);                   \
                     WYW_DELAY_TIME(waitTime);                               \
                     (*retryTimes)--;                                           \
                   }while(*retryTimes > 0);                                     \
                   if(false == res)                                             \
                   {                                                            \
                     PRINTF_1(#operate" fail\n");                               \
                   }                                                            \
                }

s8 wyw_send(u8*data, wyw_size_t dataSize, wyw_size_t operateDelay, u8 *retryTimes)
{
  s8 res = false;
  WYW_COMMUNICATION_M(WYW_IO_WRITE, data, dataSize, operateDelay, retryTimes);
  return res;
}

s8 wyw_recive(u8*buf, wyw_size_t bufSize, wyw_size_t operateDelay, u8 *retryTimes)
{
  s8 res = false;
  WYW_COMMUNICATION_M(WYW_IO_READ, buf, bufSize, operateDelay, retryTimes);
  return res;
}
