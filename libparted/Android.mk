
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	debug.c \
	architecture.c \
	device.c \
	exception.c \
	filesys.c \
	libparted.c \
	timer.c \
	unit.c \
	disk.c \
	cs/geom.c \
	cs/constraint.c \
	cs/natmath.c \
	arch/linux.c \
	labels/aix.c \
	labels/bsd.c \
	labels/dos.c \
	labels/dvh.c \
	labels/efi_crc32.c \
	labels/gpt.c \
	labels/loop.c \
	labels/mac.c \
	labels/pc98.c \
	labels/pt-tools.c \
	labels/rdb.c \
	labels/sun.c \

LOCAL_CFLAGS := -Wno-missing-field-initializers
LOCAL_MODULE := libparted
LOCAL_MODULE_TAGS := optional
LOCAL_STATIC_LIBRARIES := libgnulib libparted-fs
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include \
	$(LOCAL_PATH)/../lib \
	external/e2fsprogs/lib \
	fs \
	labels

include $(BUILD_STATIC_LIBRARY)

include $(LOCAL_PATH)/fs/Android.mk

