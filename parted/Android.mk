LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

parted_src_files := \
	command.c	\
	parted.c	\
	strlist.c	\
	ui.c		\
	table.c		\
	version.c	\


parted_static_libraries := libparted libgnulib libparted-fs libuuid
parted_c_includes := $(LOCAL_PATH)/../include $(LOCAL_PATH)/../lib

include $(CLEAR_VARS)
LOCAL_SRC_FILES := $(parted_src_files)
LOCAL_MODULE := parted
LOCAL_MODULE_TAGS := optional
LOCAL_STATIC_LIBRARIES := $(parted_static_libraries)
LOCAL_C_INCLUDES := $(parted_c_includes)

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := $(parted_src_files)
LOCAL_MODULE := parted-static
LOCAL_MODULE_TAGS := optional
LOCAL_STATIC_LIBRARIES := $(parted_static_libraries) libc
LOCAL_C_INCLUDES := $(parted_c_includes)
LOCAL_FORCE_STATIC_EXECUTABLE := true
include $(BUILD_EXECUTABLE)
