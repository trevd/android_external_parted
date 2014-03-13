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
LOCAL_STATIC_LIBRARIES := libparted libgnulib libparted-fs
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include $(LOCAL_PATH)/../lib
LOCAL_SHARED_LIBRARIES := libext2_uuid

include $(BUILD_EXECUTABLE)
