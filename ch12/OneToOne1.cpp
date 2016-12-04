#include <jni.h>
#include <iostream>
#include <stdlib.h>
#include "OneToOne1.h"

JNIEXPORT jint JNICALL Java_OneToOne1_atol(JNIEnv * env, jclass cls,
                     jstring strIn)
{
        const char* str = env->GetStringUTFChars(strIn, NULL);
        int r = atol(str);
        env->ReleaseStringUTFChars(strIn, str);
        return r;
}

