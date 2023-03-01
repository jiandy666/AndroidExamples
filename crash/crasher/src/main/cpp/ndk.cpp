#include <jni.h>
#include <android/log.h>


#define TAG "Example.Crasher"

#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)




void crash()
{
    int* a = (int*) 0;
    *a = 1;
}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_crasher_MainActivity_crash(JNIEnv *env, jclass clazz)
{
    LOGW("we are going to crash...");
    crash();
}
