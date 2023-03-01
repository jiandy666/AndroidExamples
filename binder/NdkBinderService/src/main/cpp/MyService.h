#pragma once

#include <aidl/com/example/binder/BnMyService.h>

using ndk::ScopedAStatus;


namespace aidl {
namespace com {
namespace example {
namespace binder {


class MyService : public BnMyService
{
public:
    ScopedAStatus basicTypes(int32_t in_anInt, int64_t in_aLong, bool in_aBoolean,
                             float in_aFloat, double in_aDouble,
                             const std::string &in_aString) override;

};


}
}
}
}

