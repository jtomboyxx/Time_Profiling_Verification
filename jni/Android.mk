LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_LDFLAGS := 

LOCAL_CFLAGS := 

LOCAL_CFLAGS += -Werror -fopenmp

LOCAL_CFLAGS  += -D_ANDROID_

LOCAL_SRC_FILES:= Time_Profiling_Verification.c \

LOCAL_C_INCLUDES:=$(LOCAL_PATH)

LOCAL_SHARED_LIBRARIES:= 

LOCAL_32_BIT_ONLY := true

LOCAL_MODULE:= Time_Profiling_Verification
LOCAL_CLANG := false
LOCAL_MODULE_TAGS := optional

LOCAL_LDLIBS += -llog -ldl -fopenmp

include $(BUILD_EXECUTABLE)
