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
CP 		:= cp -ar

# ----------
# output dir
# ----------
OBJ_DIR ?= objs
LIB_DIR ?= lib
INC_DIR ?= inc
SRC_DIR ?= src
TST_DIR ?= test
DEM_DIR ?= demo
CON_DIR ?= configs

# --------
# compiler
# --------
CFLAGS 		:=
LIB_CFLAGS 	:=
LDFLAGS 	:=

# DEBUG_SWITCH := debug
ifeq ($(DEBUG_SWITCH)x, debugx)
	CFLAGS     +=
else
	CFLAGS     +=
endif

TARGET_SYSTEM ?= c51

ifeq ($(TARGET_SYSTEM)x, c51)
	GCC_PATH 	?=
	GCC_NAME 	?=

	CROSS_TOOL 	:= $(GCC_PATH)/$(GCC_NAME)
endif

CFLAGS 	+= -mmcs51 

CC 	 	:= $(CROSS_TOOL)sdcc
# CXX 	:= $(CROSS_TOOL)g++
# STRIP  	:= $(CROSS_TOOL)strip

