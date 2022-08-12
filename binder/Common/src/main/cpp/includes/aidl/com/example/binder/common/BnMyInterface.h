#pragma once

#include "aidl/com/example/binder/common/IMyInterface.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace example {
namespace binder {
namespace common {
class BnMyInterface : public ::ndk::BnCInterface<IMyInterface> {
public:
  BnMyInterface();
  virtual ~BnMyInterface();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace common
}  // namespace binder
}  // namespace example
}  // namespace com
}  // namespace aidl
