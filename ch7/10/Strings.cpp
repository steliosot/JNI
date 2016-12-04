#include "Strings.h"
#include <iostream>
#include <jni.h>
#include <string.h>

JNIEXPORT jstring JNICALL
Java_Strings_getSendMsg(JNIEnv* env, jobject obj, jstring strpar)
{
    jboolean isCopy;
    const char* cstr;
    int len = env->GetStringUTFLength(strpar);
    cstr = env ->GetStringUTFLentgh(strpar);
    env->GetStringUTFRegion(strpar, 0, len, cstr);
    return  env->NewStringUTF("ABCDE");
}

