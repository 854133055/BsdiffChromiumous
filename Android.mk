LOCAL_PATH := $(call my-dir)


#bzlib模块
include $(CLEAR_VARS)
LOCAL_SRC_FILES := \
	blocksort.c \
	huffman.c \
	crctable.c \
	randtable.c \
	compress.c \
	decompress.c \
	bzip2.c \
	bzip2recover.c \
	mk251.c \
	spewG.c \
	unzcrash.c \
	bzlib.c

LOCAL_MODULE := libbz
include $(BUILD_STATIC_LIBRARY)

#divsufsort模块
libdivsufsort_src_files := \
    divsufsort.c \
    sssort.c \
    trsort.c \
    utils.c

libdivsufsort_cflags := \
    -Wall \
    -Werror \
    -Wextra \
    -DHAVE_CONFIG_H=1

libdivsufsort_export_c_include_dirs := $(LOCAL_PATH)/android_include

# libdivsufsort using 32-bit integers for the suffix array (target static lib)
include $(CLEAR_VARS)
LOCAL_MODULE := libdivsufsort
LOCAL_SRC_FILES := $(libdivsufsort_src_files)
#LOCAL_EXPORT_C_INCLUDE_DIRS := $(libdivsufsort_export_c_include_dirs)
LOCAL_CFLAGS := $(libdivsufsort_cflags)
include $(BUILD_STATIC_LIBRARY)

# libdivsufsort using 64-bit integers for the suffix array (target static lib)
#include $(CLEAR_VARS)
#LOCAL_MODULE := libdivsufsort64
#LOCAL_SRC_FILES := $(libdivsufsort_src_files)
#LOCAL_EXPORT_C_INCLUDE_DIRS := $(libdivsufsort_export_c_include_dirs)
#LOCAL_CFLAGS := \
#    $(libdivsufsort_cflags) \
#    -DBUILD_DIVSUFSORT64
#include $(BUILD_STATIC_LIBRARY)


#bspatch模块
include $(CLEAR_VARS)
LOCAL_MODULE    := bsdiff
LOCAL_SRC_FILES := \
			bspatch.c \
			bsdiff.c \
			extents.c \
			exfile.c \
			fopencookie.c \

LOCAL_STATIC_LIBRARIES := divsufsort libbz #引入divsufsort库
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := diffpatch
LOCAL_SRC_FILES := diffpatch.c
LOCAL_STATIC_LIBRARIES := bsdiff
LOCAL_LDLIBS += -llog#android log
include $(BUILD_SHARED_LIBRARY)