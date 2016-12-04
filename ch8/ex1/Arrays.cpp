#include "Arrays.h"
#include <iostream>
#include <jni.h>
#include <string.h>
//*****************************************************************
JNIEXPORT jintArray JNICALL
Java_Arrays_createIntArray(JNIEnv* env, jobject obj, jint size)
{
    jintArray iarr = env->NewIntArray(size);
    return iarr;
}

//*****************************************************************
JNIEXPORT jint JNICALL
Java_Arrays_sumSmallArray(JNIEnv* env, jobject obj, jintArray arrpar)
{
    int i, sum = 0;
    jint buf[10];
    // Copy the contents of int array to a preallocated C buffer
    env->GetIntArrayRegion(arrpar, 0, 10, buf);
    for (i = 0; i < 10; i++) {
        sum += buf[i];
    }
    return sum;
}
//*****************************************************************
JNIEXPORT jint JNICALL
Java_Arrays_sumLargeArray(JNIEnv* env, jobject obj, jintArray arrpar)
{
    jboolean isCopy;
    int i, sum = 0;
    jint *carr;
    // Obtains a pointer to the contents of int array
    carr = env->GetIntArrayElements(arrpar, &isCopy);
    if (carr == NULL)
        return 0;
    // Get the number of elements in the array
    int len = env->GetArrayLength(arrpar);
    for (i = 0; i < len; i++) {
        sum += carr[i];
    }
    env->ReleaseIntArrayElements(arrpar, carr, 0);
    return sum;
}

JNIEXPORT void JNICALL
Java_Arrays_updateArray(JNIEnv* env, jobject obj, jintArray arrpar)
{
    jboolean isCopy;
    jint *carr;
    // Obtains a pointer to the contents of int array
    carr = env->GetIntArrayElements(arrpar, &isCopy);
    if (carr != NULL) {
        // Get the number of elements in the array
        int len = env->GetArrayLength(arrpar);
        for (int i = 0; i < len; i++) {
            carr[i] = carr[i] * 2;
        }
        if(isCopy == JNI_FALSE){
           env->ReleaseIntArrayElements(arrpar, carr, 0);
        }
    }
}

