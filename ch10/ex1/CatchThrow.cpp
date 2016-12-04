#include "CatchThrow.h"
#include <iostream>
#include <jni.h>
#include <string.h>

JNIEXPORT void JNICALL
Java_CatchThrow_nativeThrow(JNIEnv* env, jobject obj)
{

    jclass cls;
    jmethodID mid;
    jthrowable excObj;
    cls = env->FindClass("java/lang/IllegalArgumentException");
    mid = env->GetMethodID(cls, "<init>", "()V");
    excObj = (jthrowable) env->NewObject(cls, mid);
    env->Throw(excObj);
}

JNIEXPORT void JNICALL
Java_CatchThrow_nativeThrowNew(JNIEnv* env, jclass clsArg)
{

    jclass cls;
    cls = env->FindClass("java/lang/IllegalArgumentException");
    env->ThrowNew(cls, "Argument ERROR");
}

