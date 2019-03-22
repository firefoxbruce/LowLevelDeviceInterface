#ifndef __WYW_DEVICE_H__
#define __WYW_DEVICE_H__
 s8 device_write(u8 *TxBuf, wyw_size_t *dataSize);
 s8 device_read(u8 *RxBuf, wyw_size_t *bufSize);
#endif
