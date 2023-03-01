#include "MyService.h"
#include <LogDefs.h>

using aidl::com::example::binder::MyService;


ScopedAStatus MyService::basicTypes(int32_t in_anInt, int64_t in_aLong, bool in_aBoolean,
                                    float in_aFloat, double in_aDouble, const std::string &in_aString)
{
    LOGD("[MyService] [ndk] basicTypes: int=%d, long=%lld, bool=%d, float=%f, double=%f, string=%s",
         in_anInt, in_aLong, in_aBoolean, in_aFloat, in_aDouble, in_aString.c_str());
    return ScopedAStatus::ok();
}