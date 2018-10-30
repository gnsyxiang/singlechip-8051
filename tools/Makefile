# ===============================================================
# 
# Release under GPLv2.
# 
# @file    Makefile
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    30/10 2018 16:19
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        30/10 2018      create the file
# 
#     last modified: 30/10 2018 16:19
# ===============================================================

TO_TOP_DIR 	:= ..

include $(TO_TOP_DIR)/configs/com-var-def.mk

############################################################
all: $(TOOLS_SDCC) $(TOOLS_STCGAL)

include $(TO_TOP_DIR)/configs/com-tar-def.mk

############################################################
$(TOOLS_SDCC): $(TOOLS_SDCC)-src
ifneq ($(INSTALL_DIR), $(wildcard $(INSTALL_DIR)))
	$(MKDIR) $(INSTALL_DIR)
	cd $(TOOLS_SDCC) \
		&& ./configure --prefix=$(INSTALL_PATH) \
		&& make -j5 \
		&& make install
endif

$(TOOLS_SDCC)-src:
ifneq ($(TOOLS_SDCC), $(wildcard $(TOOLS_SDCC)))
	$(ECHO) "---->> tar $@"
	$(TAR_XJVF) sdcc-src-20181029-10635.tar.bz2
endif

############################################################
$(TOOLS_STCGAL): $(TOOLS_STCGAL)-src

$(TOOLS_STCGAL)-src:
ifneq ($(TOOLS_STCGAL), $(wildcard $(TOOLS_STCGAL)))
	$(ECHO) "---->> download $@"
	git clone https://github.com/grigorig/stcgal.git
endif

