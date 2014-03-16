# Copyright 2012 Trevor Drake 

LOCAL_PATH:= $(call my-dir)


##### Test List Partitions ####

include $(CLEAR_VARS)
LOCAL_CLANG := true
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include $(LOCAL_PATH)/../lib $(LOCAL_PATH)/../uuid
LOCAL_STATIC_LIBRARIES += libparted libgnulib libparted-fs libuuid
LOCAL_SRC_FILES := list_partitions.c
LOCAL_MODULE := parted_test_list_partitions
include $(BUILD_EXECUTABLE)


##### Test Label ####

include $(CLEAR_VARS)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include $(LOCAL_PATH)/../lib $(LOCAL_PATH)/../uuid
LOCAL_STATIC_LIBRARIES += libparted libgnulib libparted-fs libuuid
LOCAL_SRC_FILES := label.c
LOCAL_MODULE := parted_test_labels
include $(BUILD_EXECUTABLE)

##### Test Reading ####

include $(CLEAR_VARS)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include $(LOCAL_PATH)/../lib $(LOCAL_PATH)/../uuid
LOCAL_STATIC_LIBRARIES += libparted libgnulib libparted-fs libuuid
LOCAL_SRC_FILES := reading.c
LOCAL_MODULE := parted_test_reading
include $(BUILD_EXECUTABLE)

##### Test probe ####

include $(CLEAR_VARS)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include $(LOCAL_PATH)/../lib $(LOCAL_PATH)/../uuid
LOCAL_STATIC_LIBRARIES += libparted libgnulib libparted-fs libuuid
LOCAL_SRC_FILES := probe.c
LOCAL_MODULE := parted_test_probe
include $(BUILD_EXECUTABLE)

##### ped_unit examples ####

include $(CLEAR_VARS)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include $(LOCAL_PATH)/../lib $(LOCAL_PATH)/../uuid
LOCAL_STATIC_LIBRARIES += libparted libgnulib libparted-fs libuuid
LOCAL_SRC_FILES := ped_unit_examples.c
LOCAL_MODULE := parted_ped_unit_examples
include $(BUILD_EXECUTABLE)

