LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	command.c	\
	parted.c	\
	strlist.c	\
	ui.c		\
	table.c		\
	version.c	\

LOCAL_CFLAGS :=
LOCAL_MODULE := parted
LOCAL_MODULE_TAGS := optional
LOCAL_STATIC_LIBRARIES := libparted libgnulib libparted-fs libuuid
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include $(LOCAL_PATH)/../lib

include $(BUILD_EXECUTABLE)
