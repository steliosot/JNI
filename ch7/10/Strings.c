#include "Strings.h"
#include <iostream.h>
#include <jni.h>
#include <string.h>

JNIEXPORT jstring JNICALL
Java_Strings_getSendMsg(JNIEnv* env, jobject obj, jstring strpar)
{
    jboolean isCopy;
    const char* cstr;
    int len = env->GetStringUTFLength(strpar);
    std::cout << "In C++ : UTF string length " << len << std::endl;
    cstr = env->GetStringUTFChars(strpar, &isCopy);
    std::cout << "In C++ : " << cstr << std::endl;
    if (isCopy == JNI_TRUE) {
       std::cout << "Returned string is copy";
    }
    env->ReleaseStringUTFChars(strpar, cstr);
    return  env->NewStringUTF("Hello from C++");
}

