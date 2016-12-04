#include "CatchThrow1.h"
#include <iostream>
#include <jni.h>
#include <string.h>

JNIEXPORT void JNICALL
Java_CatchThrow1_catchException(JNIEnv* env, jobject obj, jint intArg)
{
    jclass cls;
    jclass NPExcCls, InstExcCls, IAExcCls, excCls;
    jmethodID mid;
    jthrowable excObj;
    NPExcCls   = env->FindClass("java/lang/NullPointerException");
    if (NPExcCls == NULL) {
       return;
    }
    InstExcCls = env->FindClass("java/lang/InstantiationException");
    if (InstExcCls == NULL) {
       return;
    }
    IAExcCls   = env->FindClass("java/lang/IllegalArgumentException");
    if (IAExcCls == NULL) {
       return;
    }
    cls = env->GetObjectClass(obj);
    if (cls == NULL) {
       return;
    }
    mid = env->GetMethodID(cls, "callbackThrow", "(I)V");
    if (mid == NULL) {
       return;
    }
    env->CallVoidMethod(obj, mid, intArg);
    excObj = env->ExceptionOccurred();
    if (excObj != NULL) {
         if (env->IsInstanceOf(excObj, NPExcCls) == JNI_TRUE) {
           env->ExceptionDescribe();
           env->ExceptionClear();
       } else {
           return;
       }
    }
}

