
#include "Fields.h"
#include <iostream>
#include <jni.h>
#include <string.h>

JNIEXPORT void JNICALL
Java_Fields_accessFields(JNIEnv* env, jobject obj)
{
    jfieldID fid;
    jclass   cls;

    // Get and Set Instance Field
    cls = env->GetObjectClass(obj);
    fid = env->GetFieldID(cls, "pubInt", "I");
    jint pubInt = env->GetIntField(obj, fid);
    env->SetIntField(obj, fid, 2*pubInt);

    // Get and Set Static Field
    fid = env->GetStaticFieldID(cls, "statPubInt", "I");
    jint statPubInt = env->GetStaticIntField(cls, fid);
    env->SetStaticIntField(cls, fid, 2*statPubInt);

    // Get and Set Instance Field
    fid = env->GetFieldID(cls, "privInt", "I");
    jint privInt = env->GetIntField(obj, fid);
    env->SetIntField(obj, fid, 2*privInt);

    // Get and Set Static Field
    fid = env->GetStaticFieldID(cls, "privStatFloat", "F");
    jfloat privStatFloat = env->GetStaticFloatField(cls, fid);
    env->SetStaticFloatField(cls, fid, 2*privStatFloat);
}

JNIEXPORT void JNICALL
Java_Fields_accessStrings(JNIEnv* env, jobject obj)
{
    // Get and Set String
    jclass cls = env->GetObjectClass(obj);
    jfieldID fid = env->GetFieldID(cls, "strField", "Ljava/lang/String;");
    jstring jstr = (jstring) env->GetObjectField(obj, fid);
    const char *str = env->GetStringUTFChars(jstr, NULL);
    env->ReleaseStringUTFChars(jstr, str);
    jstr = env->NewStringUTF("XYZ");
    env->SetObjectField(obj, fid, jstr);
}

