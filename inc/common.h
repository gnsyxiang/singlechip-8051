/**
 *
 * Release under GPLv2.
 * 
 * @file    common.h
 * @brief   
 * @author  gnsyxiang <gnsyxiang@163.com>
 * @date    22/11 2018 14:46
 * @version v0.0.1
 * 
 * @since    note
 * @note     note
 * 
 *     change log:
 *     NO.     Author              Date            Modified
 *     00      zhenquan.qiu        22/11 2018      create the file
 * 
 *     last modified: 22/11 2018 14:46
 */
#ifndef __SC_COMMON_H_
#define __SC_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    INT_POLITY_HIGHT = 0,
    INT_POLITY_LOW,

    INT_POLITY_MAX
} int_polity_t;

enum {
    ENABLE = 0,
    DISABLE,
};

#ifdef __cplusplus
}
#endif

#endif /* __SC_COMMON_H_ */

