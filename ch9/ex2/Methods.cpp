#include "Methods.h"
#include <iostream>
#include <jni.h>
#include <string.h>

JNIEXPORT void JNICALL
Java_Methods_accessConstructor(JNIEnv* env, jobject obj)
{
    jmethodID mid;
    jclass cls = env->GetObjectClass(obj);
    mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
    if (mid ==NULL){
        return;
    }
    jstring s = env->NewStringUTF("C++");
    env->CallVoidMethod(obj, mid, s);
}
 
JNIEXPORT void JNICALL
Java_Methods_accessStaticMethod(JNIEnv* env, jobject obj)
{
    jmethodID mid;
    jclass cls = env->GetObjectClass(obj);
    mid = env->GetStaticMethodID(cls, "intSumStatic", "(II)I");
    if (mid ==NULL){
        return;
    }
    int s = env->CallStaticIntMethod(cls, mid, 5, 7);
}
 
JNIEXPORT void JNICALL
Java_Methods_accessInstanceMethod(JNIEnv* env, jobject obj)
{
    jmethodID mid;
    jclass cls = env->GetObjectClass(obj);
    mid = env->GetMethodID(cls, "recSendString",
                      "(Ljava/lang/String;)Ljava/lang/String;");
    if (mid ==NULL){
        return;
    }
    jstring s  = env->NewStringUTF("Hello from C++");
    jstring str = (jstring) env->CallObjectMethod(obj, mid, s);
    const char* cstr = env->GetStringUTFChars(str, NULL);
}

