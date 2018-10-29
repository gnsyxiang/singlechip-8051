# ===============================================================
# 
# Release under GPLv2.
# 
# @file    Makefile
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    29/10 2018 15:41
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        29/10 2018      create the file
# 
#     last modified: 29/10 2018 15:41
# ===============================================================

TO_TOP_DIR 	:= ./

include $(TO_TOP_DIR)/configs/com-var-def.mk

# --------------
# target setting
# --------------
TARGET 	?= main

# ------
# cflags
# ------
CFLAGS 	:= -I$(INC_DIR)

# -------
# c files
# -------
SRC_C 	:= $(wildcard $(SRC_DIR)/*.c)
SRC_C 	+= $(wildcard $(TST_DIR)/*.c)

OBJ_REL := $(patsubst %.c, $(OBJ_DIR)/%.rel, $(SRC_C))
OBJ_IHX := $(patsubst %.rel, %.ihx, $(OBJ_REL))
OBJS  	?= $(OBJ_REL)

###########################################
all: $(TARGET)

include $(TO_TOP_DIR)/configs/com-tar-def.mk

debug:
	$(ECHO) $(SRC_C)

