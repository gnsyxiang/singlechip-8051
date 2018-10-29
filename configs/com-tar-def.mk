# ===============================================================
# 
# Release under GPLv2.
# 
# @file    com-tar-def.mk
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    29/10 2018 15:45
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        29/10 2018      create the file
# 
#     last modified: 29/10 2018 15:45
# ===============================================================

clean:
	$(RM) $(TARGET) $(TARGET).hex
	$(RM) $(OBJ_REL)
	$(RM) $(OBJ_IHX)

distclean: clean index-clean
	$(RM) $(OBJ_DIR)

index: index-clean
	$(ECHO) generate index
	ctags -R
	cscope -Rbkq

index-clean:
	$(RM) *.out
	$(RM) tags

.PHONY: all clean distclean debug
#########################################################

$(TARGET): $(TARGET).hex
	objcopy -I ihex -O binary $< $@

$(TARGET).hex: $(OBJ_IHX)
	packihx $^ > $@

$(OBJ_IHX): $(OBJ_REL)
	$(CC) $(CFLAGS) $^ -o $@

# --------
# make *.c
# --------
$(OBJS): $(OBJ_DIR)/%.rel : %.c
	$(MKDIR) $(dir $@)
	$(ECHO) $(MSG_CC) $<
	$(CC) -c $(CFLAGS) $< -o $@

#########################################################
err_no_targets:
	@echo "error: use \"targets = your_target\" to specify your target to make!"
	exit 1

ifeq ($(V),1)
slient_targets=err_no_targets
endif

.SILENT: $(slient_targets)

