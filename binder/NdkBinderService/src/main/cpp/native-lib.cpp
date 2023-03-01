#include <jni.h>
#include <android/binder_ibinder_jni.h>
#include "MyService.h"

using aidl::com::example::binder::MyService;


extern "C"
JNIEXPORT jobject JNICALL
Java_com_example_binder_service_ndk_MyService_createNativeService(JNIEnv *env, jobject thiz)
{
    static MyService service;
    jobject jBinder = AIBinder_toJavaBinder(env, service.asBinder().get());
    return env->NewGlobalRef(jBinder);
}