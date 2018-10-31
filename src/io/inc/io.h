/**
 *
 * Release under GPLv2.
 * 
 * @file    io.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    31/10 2018 11:33
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        31/10 2018      create the file
 * 
 *     last modified: 31/10 2018 11:33
 */
#ifndef __SC_IO_H_
#define __SC_IO_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SC_IO_GB
#define SC_IO_EX extern
#else
#define SC_IO_EX
#endif

SC_IO_EX void io_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __SC_IO_H_ */

