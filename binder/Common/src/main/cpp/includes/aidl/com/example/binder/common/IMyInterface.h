#pragma once

#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace com {
namespace example {
namespace binder {
namespace common {
class IMyInterface : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IMyInterface();
  virtual ~IMyInterface();



  static std::shared_ptr<IMyInterface> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IMyInterface>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IMyInterface>* instance);
  static bool setDefaultImpl(std::shared_ptr<IMyInterface> impl);
  static const std::shared_ptr<IMyInterface>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus basicTypes(int32_t in_anInt, int64_t in_aLong, bool in_aBoolean, float in_aFloat, double in_aDouble, const std::string& in_aString) = 0;
private:
  static std::shared_ptr<IMyInterface> default_impl;
};
class IMyInterfaceDefault : public IMyInterface {
public:
  ::ndk::ScopedAStatus basicTypes(int32_t in_anInt, int64_t in_aLong, bool in_aBoolean, float in_aFloat, double in_aDouble, const std::string& in_aString) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace common
}  // namespace binder
}  // namespace example
}  // namespace com
}  // namespace aidl
