
/*VECENT_COMMUNICATION  s8 res = false;*/
#define VECENT_COMMUNICATION_M(operate, buf, bufSize, operateDelay, retryTimes) \
                {                                                               \
                   VECENT_CREAT_TIME(waitTime);                                 \
                   do                                                           \
                   {                                                            \
                     res = operate##_F(buf, bufSize);                           \
                     if(false != res)                                           \
                     {                                                          \
                       PRINTF_1( #operate" success\n");                         \
                       break;                                                   \
                     }                                                          \
                     VECENT_SET_TIME(waitTime, operateDelay);                   \
                     VECENT_DELAY_TIME(waitTime);                               \
                     (*retryTimes)--;                                           \
                   }while(*retryTimes > 0);                                     \
                   if(false == res)                                             \
                   {                                                            \
                     PRINTF_1(#operate" fail\n");                               \
                   }                                                            \
                }

s8 vecent_send(u8*data, vc_size_t dataSize, vc_size_t operateDelay, u8 *retryTimes)
{
  s8 res = false;
  VECENT_COMMUNICATION_M(VECENT_IO_WRITE, data, dataSize, operateDelay, retryTimes);
  return res;
}

s8 vecent_recive(u8*buf, vc_size_t bufSize, vc_size_t operateDelay, u8 *retryTimes)
{
  s8 res = false;
  VECENT_COMMUNICATION_M(VECENT_IO_READ, buf, bufSize, operateDelay, retryTimes);
  return res;
}
