#include "Calc.h"
#include <iostream>
#include <jni.h>
#include <string.h>

JNIEXPORT jint JNICALL
Java_Calc_sum(JNIEnv* env, jobject obj, jint num1, jint num2)
{
   jint res = num1 + num2;
   return res;
}

JNIEXPORT jdouble JNICALL
Java_Calc_div(JNIEnv* env, jclass cls, jdouble num1, jdouble num2)
{
    jdouble res = num1 / num2;
    return res;
}

