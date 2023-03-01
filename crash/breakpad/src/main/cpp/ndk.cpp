#include <jni.h>
#include <android/log.h>

#include "client/linux/handler/exception_handler.h"
#include "client/linux/handler/minidump_descriptor.h"


#define TAG "AndroidZ.Breakpad"

#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)




bool DumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                  void* context,
                  bool success) {
    LOGE("============================================ CRASH ============================================");
    LOGE("Dump path: %s\n", descriptor.path());
    LOGE("============================================ CRASH ============================================");
}


extern "C"
JNIEXPORT void JNICALL
Java_google_breakpad_BreakpadInit_initNative(JNIEnv *env, jclass clazz, jstring path_)
{
    const char* path = env->GetStringUTFChars(path_, nullptr);

    google_breakpad::MinidumpDescriptor descriptor(path);
    static google_breakpad::ExceptionHandler eh(descriptor, nullptr, DumpCallback, nullptr, true, -1);

    LOGI("dump dir: %s\n", path);

    env->ReleaseStringUTFChars(path_, path);
}
