LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	xmalloc.c \
	xalloc-die.c \
	argmatch.c \
	progname.c \
	closeout.c \
	c-ctype.c \
	c-strcasecmp.c \
	error.c \
	exitfail.c \
	close-stream.c \
	quote.c \
	quotearg.c \
	fpending.c \
	version-etc.c \
	version-etc-fsf.c \
	canonicalize-lgpl.c \
	malloca.c \
	basename-lgpl.c \
	xstrtoll.c \

LOCAL_MODULE := libgnulib
LOCAL_MODULE_TAGS := optional
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include

include $(BUILD_STATIC_LIBRARY)

