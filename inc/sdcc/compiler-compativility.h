/**
 *
 * Release under GPLv2.
 * 
 * @file    compiler-compativility.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    01/11 2018 15:14
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        01/11 2018      create the file
 * 
 *     last modified: 01/11 2018 15:14
 */
#ifndef __SC_COMPILER_COMPATIVILITY_H_
#define __SC_COMPILER_COMPATIVILITY_H_

#ifdef __cplusplus
extern "C" {
#endif

#if defined (SDCC) || defined (__SDCC)

    #define interrupt __interrupt

#elif defined __CX51__

#endif

#ifdef __cplusplus
}
#endif

#endif /* __SC_COMPILER_COMPATIVILITY_H_ */

