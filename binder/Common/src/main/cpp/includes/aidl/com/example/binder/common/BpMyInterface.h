#pragma once

#include "aidl/com/example/binder/common/IMyInterface.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace example {
namespace binder {
namespace common {
class BpMyInterface : public ::ndk::BpCInterface<IMyInterface> {
public:
  BpMyInterface(const ::ndk::SpAIBinder& binder);
  virtual ~BpMyInterface();

  ::ndk::ScopedAStatus basicTypes(int32_t in_anInt, int64_t in_aLong, bool in_aBoolean, float in_aFloat, double in_aDouble, const std::string& in_aString) override;
};
}  // namespace common
}  // namespace binder
}  // namespace example
}  // namespace com
}  // namespace aidl
