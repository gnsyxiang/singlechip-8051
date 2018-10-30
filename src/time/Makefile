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

TO_TOP_DIR 	:= ../..

include $(TO_TOP_DIR)/configs/com-var-def.mk
include $(TO_TOP_DIR)/configs/com-rul-def.mk

# --------------
# target setting
# --------------
TARGET 		?= time
TARGET_DEMO ?= main
TARGET_LIB	?= $(TARGET).so

TARGET_PATH ?= $(LIB_DIR)/$(TARGET_LIB)

# ------
# flags
# ------
CFLAGS 	+= -I$(INC_DIR) -I$(TO_TOP_DIR)/$(INC_DIR)

LDFLAGS += -l$(TARGET_LIB) -L$(LIB_DIR)

# -------
# c files
# -------
SRC_C 	:= $(wildcard $(SRC_DIR)/*.c)

OBJ_REL := $(patsubst %.c, $(OBJ_DIR)/%.rel, $(SRC_C))
OBJ_IHX := $(patsubst %.rel, %.ihx, $(OBJ_REL))
OBJS  	?= $(OBJ_REL)

TST_C 	:= $(wildcard $(TST_DIR)/*.c)

TST_REL := $(patsubst %.c, $(OBJ_DIR)/%.rel, $(TST_C))
TST_IHX := $(patsubst %.rel, %.ihx, $(TST_REL))
TST_OBJ ?= $(TST_REL)

###########################################
all: depend $(TARGET_PATH) $(TARGET_DEMO)
	$(cp-lib-inc)

include $(TO_TOP_DIR)/configs/com-tar-def.mk

debug:
	$(ECHO) $(TST_OBJ)

