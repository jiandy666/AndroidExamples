//
// Created by AJ on 3/2/2022.
//

#ifndef ANDROIDEXAMPLES_MYINTERFACE_H
#define ANDROIDEXAMPLES_MYINTERFACE_H

#include <aidl/com/example/binder/common/BnMyInterface.h>

using ndk::ScopedAStatus;


namespace aidl {
namespace com {
namespace example {


class MyInterface : public BnMyInterface {
    virtual ::ndk::ScopedAStatus basicTypes(int32_t in_anInt, int64_t in_aLong, bool in_aBoolean, float in_aFloat, double in_aDouble, const std::string& in_aString) = 0;

};


}
}
}


#endif //ANDROIDEXAMPLES_MYINTERFACE_H
