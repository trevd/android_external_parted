# Copyright 2012 Trevor Drake 

LOCAL_PATH:= $(call my-dir)


##### Test List Partitions ####

include $(CLEAR_VARS)
LOCAL_CLANG := true
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include $(LOCAL_PATH)/../lib
LOCAL_STATIC_LIBRARIES += libparted libgnulib libparted-fs
LOCAL_SRC_FILES := list_partitions.c
LOCAL_MODULE := parted_test_list_partitions
LOCAL_SHARED_LIBRARIES := libext2_uuid
include $(BUILD_EXECUTABLE)


##### Test Label ####

include $(CLEAR_VARS)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include $(LOCAL_PATH)/../lib
LOCAL_STATIC_LIBRARIES += libparted libgnulib libparted-fs
LOCAL_SRC_FILES := label.c
LOCAL_MODULE := parted_test_labels
LOCAL_SHARED_LIBRARIES := libext2_uuid
include $(BUILD_EXECUTABLE)




##### Test Reading ####

include $(CLEAR_VARS)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include $(LOCAL_PATH)/../lib
LOCAL_STATIC_LIBRARIES += libparted libgnulib libparted-fs
LOCAL_SRC_FILES := reading.c
LOCAL_MODULE := parted_test_reading
LOCAL_SHARED_LIBRARIES := libext2_uuid
include $(BUILD_EXECUTABLE)



##### Test probe ####


include $(CLEAR_VARS)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include $(LOCAL_PATH)/../lib
LOCAL_STATIC_LIBRARIES += libparted libgnulib libparted-fs
LOCAL_SRC_FILES := probe.c
LOCAL_MODULE := parted_test_probe
LOCAL_SHARED_LIBRARIES := libext2_uuid
include $(BUILD_EXECUTABLE)


