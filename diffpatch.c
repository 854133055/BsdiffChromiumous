/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <string.h>
#include <jni.h>

#include <sys/types.h>

#include "bzlib.h"
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdint.h>
#include <string.h>

#include "bsdiff.h"
#include "bspatch.h"

#include <android/log.h>

#include "diffpatch.h"

#include "bzlib_private.h"
#define LOG_TAG "GrayScaleLog"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

jint JNI_OnLoad(JavaVM *vm, void* reserved) {
    LOGD("JNI_OnLoad……");
    return JNI_VERSION_1_4;
}

JNIEXPORT jint JNICALL Java_com_ziroom_grayscale_patch_DiffPatch_bspatch(JNIEnv *env,
        jobject obj, jstring old, jstring newPatch , jstring patch){
    int argc = 4;
    char *argv[argc];
    argv[0] = "bspatch";
    argv[1] = (char *) ((*env)->GetStringUTFChars(env, old, 0));
    argv[2] = (char *) ((*env)->GetStringUTFChars(env, newPatch, 0));
    argv[3] = (char *) ((*env)->GetStringUTFChars(env, patch, 0));
    LOGD("Start JNICALL Java_com_ziroom_grayscale_patch_DiffPatch_bspatch(%s, %s, %s)", argv[1], argv[2],
         argv[3]);
    int ret = bspatch(argv[1], argv[2], argv[3], NULL, NULL);
    LOGD("End JNICALL Java_com_ziroom_grayscale_patch_DiffPatch_bspatch(%s, %s, %s)", argv[1], argv[2],
         argv[3]);
    (*env)->ReleaseStringUTFChars(env, old, argv[1]);
    (*env)->ReleaseStringUTFChars(env, newPatch, argv[2]);
    (*env)->ReleaseStringUTFChars(env, patch, argv[3]);
    return ret;
}
JNIEXPORT jint JNICALL Java_com_ziroom_grayscale_patch_DiffPatch_bsdiff(JNIEnv *env,
        jobject obj, jstring old, jstring newPatch , jstring patch){
    int argc = 4;
    char *argv[argc];
    argv[0] = "bsdiff";
    argv[1] = (char *) ((*env)->GetStringUTFChars(env, old, 0));
    argv[2] = (char *) ((*env)->GetStringUTFChars(env, newPatch, 0));
    argv[3] = (char *) ((*env)->GetStringUTFChars(env, patch, 0));
    LOGD("Start JNICALL Java_com_ziroom_grayscale_patch_DiffPatch_bsdiff(%s, %s, %s)", argv[1], argv[2],
         argv[3]);
    int ret = bsdiff(argv[1], argv[2], argv[3]);
    LOGD("End JNICALL Java_com_ziroom_grayscale_patch_DiffPatch_bsdiff(%s, %s, %s)", argv[1], argv[2],
         argv[3]);
    (*env)->ReleaseStringUTFChars(env, old, argv[1]);
    (*env)->ReleaseStringUTFChars(env, newPatch, argv[2]);
    (*env)->ReleaseStringUTFChars(env, patch, argv[3]);
    return ret;
}