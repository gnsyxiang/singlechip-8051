# ===============================================================
# 
# Release under GPLv2.
# 
# @file    com-var-def.mk
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    29/10 2018 15:35
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        29/10 2018      create the file
# 
#     last modified: 29/10 2018 15:35
# ===============================================================

# scale the maximum concurrency with the number of CPUs.
# # # An additional job is used in order to keep processors busy
# # # If the number of processors is not available, assume one.
PARALLEL_JOBS 	:= $(shell echo $$((1 + `getconf _NPROCESSORS_ONLN 2>/dev/null || echo 1`)))

HOSTMAKE  		:= $(shell which make || echo make)
MAKE1  			:= $(HOSTMAKE) -j1
MAKE 			:= $(HOSTMAKE) -j1

# ------------------
# output information
# ------------------
MSG_CC 	?= CC
MSG_LD 	?= LD
MSG_LIB ?= LIB_COPY
MSG_INC ?= INC_COPY

# ----------------
# cmd redefinition
# ----------------
RM 		:= rm -rf
ECHO 	:= echo
MKDIR 	:= mkdir -p
LN 		:= ln -s
CP 		:= cp -a

TAR_XJVF := tar xjvf

# ----------
# output dir
# ----------
ROOT	?= $(shell pwd)

OBJ_DIR ?= objs
LIB_DIR ?= lib
INC_DIR ?= inc
SRC_DIR ?= src
TST_DIR ?= test
DEM_DIR ?= demo

CON_DIR 	?= configs

TOOLS 		 ?= tools
TOOLS_STCGAL ?= stcgal
TOOLS_SDCC 	 ?= sdcc

INSTALL_DIR  ?= install
INSTALL_PATH ?= $(ROOT)/$(INSTALL_DIR)

# --------
# compiler
# --------
CFLAGS 		:=
LDFLAGS 	:=

# DEBUG_SWITCH := debug
ifeq ($(DEBUG_SWITCH)x, debugx)
	CFLAGS     +=
else
	CFLAGS     +=
endif

DEBUG_SYSTEM := mac

TARGET_SYSTEM ?= c51

ifeq ($(TARGET_SYSTEM)x, c51x)
	COMPILER_PATH := ~/test/skills/singlechip-8051

	SDCC_PATH 	?= $(COMPILER_PATH)/tools/install
	SDCC_BIN 	:= $(SDCC_PATH)/bin/
	SDCC_INC 	:= $(SDCC_PATH)/share/sdcc/include
	SDCC_LIB 	:= $(SDCC_PATH)/share/sdcc/lib

	CROSS_TOOL 	:= $(SDCC_BIN)
endif

CFLAGS 	+= -mmcs51 --std-sdcc99

# --model-small:
#  small模式，对应keil的SMALL模式，
#  变量存在internal ram中，该模式需要变量总占用的空间小于256bit。
#
# --model-medium:
#  medium模式，对应keil的COMPACT模式，变量存在external ram中。
#
# --model-large
# --model-huge
#  large和huge模式是一样的，变量也存在external ram中，
#  不同的是，它可以切换bank。由于c51的最大寻址范围也就是FFFFH，即64K。
#  所以如果要扩展64K以上的ram只能用bank切换的办法。
#  bank切换办法是用一个特殊寄存器来切换bank，将LSB存在r0，MSB存在r1，
#  bank号存在r2。然后用 __sdcc_banked_call来调用位于其他bank的函数，
#  再用__sdcc_banked_ret返回当前函数。
CFLAGS 	+= --model-small

#--iram-size <Value>: 用来检查片内ram的使用情况
#--xram-size <Value>: 用来检查外部ram的使用情况
#--code-size <Value>: 用来检查rom的使用情况
#--stack-size <Value>: 用来检查堆栈的使用情况
# CFLAGS 	+= --iram-size 2

# 可以用xstack选项指定external ram的一段空间作为栈区（通常是前256个字节），
# 这样所有的可重入函数的变量和参数传递都会用堆栈来实现。
# 通常默认的栈空间是在internal ram的后区。
# CFLAGS += --xstack

CC 	 	:= $(CROSS_TOOL)sdcc
SDCCLIB := $(CROSS_TOOL)sdcclib
PACKIHX := $(CROSS_TOOL)packihx

