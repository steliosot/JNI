#include "Arrays11.h"
#include <iostream.h>
#include <jni.h>
#include <string.h>
//*****************************************************************
JNIEXPORT jobjectArray JNICALL
Java_Arrays11_mulInt2DArray(JNIEnv* env, jobject obj,
                       jobjectArray a, jobjectArray b)
{
    jobjectArray result;
    jintArray oneDim;
    int i,j,k;
    int n = 3;
    int local_a[3][3];
    int local_b[3][3];
    jint local_c[3][3];
    // Copy array a to local_a variable
    for (i = 0; i < n; i++) {
       oneDim = (jintArray) env->GetObjectArrayElement(a, i);
       jint *element = env->GetIntArrayElements(oneDim, 0);
       for (j = 0; j < n; j++) {
          local_a[i][j] = element[j];
       }
    }
    // Copy array b to local_b variable
    for (i = 0; i < n; i++) {
       oneDim = (jintArray) env->GetObjectArrayElement(b, i);
       jint *element = env->GetIntArrayElements(oneDim, 0);
       for (j = 0; j < n; j++) {
          local_b[i][j] = element[j];
       }
    }
    // Arrays multiplication
    for ( i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            local_c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                local_c[i][j] = local_c[i][j] +
                                local_a[i][k] * local_b[k][j];
            }
        }
    }
    // Obtain reference of the int[] array
    jclass intArrCls = env->FindClass("[I");
    if (intArrCls == NULL) {
       return NULL;
    }
    // Create an array of arrays   
    result = env->NewObjectArray(n, intArrCls, NULL);
    if (result == NULL) {
       return NULL;
    }
    // returm Array
    for (i = 0; i < n; i++) {
       jintArray iarr = env->NewIntArray(n);
       if (iarr == NULL) {
          return NULL;
       }
       env->SetIntArrayRegion(iarr, 0, n, local_c[i]);
       env->SetObjectArrayElement(result, i, iarr);
       env->DeleteLocalRef(iarr);
    }
    return result;
}
JNIEXPORT void JNICALL
Java_Arrays11_mulScalarInt2DArray(JNIEnv* env, jobject obj,
                       jobjectArray a, jintArray line)
{
    int x;

    jobjectArray result;
    jintArray oneDim;
    int i,j;

    int n = env->GetArrayLength(a);
    jint *ptmp = new jint[n];

    // Obtain reference of the int[] array
    jclass intArrCls = env->FindClass("[I");
    if (intArrCls == NULL) {
          //cout<<"ERROR";
    }
    // Create an array of arrays   
    result = env->NewObjectArray(n, intArrCls, NULL);
    if (result == NULL) {
          //cout<<"ERROR";
    }
    jint *linep = env->GetIntArrayElements(line, NULL);
    for (i = 0; i < n; i++) {
       oneDim = (jintArray) env->GetObjectArrayElement(a, i);
       jint *element = env->GetIntArrayElements(oneDim, NULL);
       for (j = 0; j < n; j++) {
           ptmp[j] = element[j] * linep[i];
       }
       jintArray iarr = (jintArray)env->NewIntArray(n);
       if (iarr == NULL) {
          //cout<<"ERROR";
       }
       env->SetIntArrayRegion(iarr, 0, n, ptmp);
       env->SetObjectArrayElement(result, i, iarr);
       env->DeleteLocalRef(iarr);
    }
    jclass clss = env->GetObjectClass(obj);
    jmethodID mid = env->GetMethodID(clss, "sendInt2DArray", "([[I)V");
    if (mid == NULL) {
       //cout<<"ERROR";
    }
}	

