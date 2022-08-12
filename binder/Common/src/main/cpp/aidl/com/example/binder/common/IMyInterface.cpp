#include <android/binder_parcel_utils.h>
#include <aidl/com/example/binder/common/BpMyInterface.h>
#include <aidl/com/example/binder/common/BnMyInterface.h>
#include <aidl/com/example/binder/common/IMyInterface.h>

namespace aidl {
namespace com {
namespace example {
namespace binder {
namespace common {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnMyInterface> _aidl_impl = std::static_pointer_cast<BnMyInterface>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*basicTypes*/): {
      int32_t in_anInt;
      int64_t in_aLong;
      bool in_aBoolean;
      float in_aFloat;
      double in_aDouble;
      std::string in_aString;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_anInt);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_aLong);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readBool(_aidl_in, &in_aBoolean);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readFloat(_aidl_in, &in_aFloat);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readDouble(_aidl_in, &in_aDouble);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_aString);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->basicTypes(in_anInt, in_aLong, in_aBoolean, in_aFloat, in_aDouble, in_aString);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IMyInterface::descriptor, _aidl_onTransact);

BpMyInterface::BpMyInterface(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpMyInterface::~BpMyInterface() {}

::ndk::ScopedAStatus BpMyInterface::basicTypes(int32_t in_anInt, int64_t in_aLong, bool in_aBoolean, float in_aFloat, double in_aDouble, const std::string& in_aString) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_anInt);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_aLong);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeBool(_aidl_in.get(), in_aBoolean);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeFloat(_aidl_in.get(), in_aFloat);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeDouble(_aidl_in.get(), in_aDouble);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_aString);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*basicTypes*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IMyInterface::getDefaultImpl()) {
    return IMyInterface::getDefaultImpl()->basicTypes(in_anInt, in_aLong, in_aBoolean, in_aFloat, in_aDouble, in_aString);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnMyInterface
BnMyInterface::BnMyInterface() {}
BnMyInterface::~BnMyInterface() {}
::ndk::SpAIBinder BnMyInterface::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IMyInterface
const char* IMyInterface::descriptor = "com.example.binder.common.IMyInterface";
IMyInterface::IMyInterface() {}
IMyInterface::~IMyInterface() {}


std::shared_ptr<IMyInterface> IMyInterface::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IMyInterface>(interface);
  }
  return ::ndk::SharedRefBase::make<BpMyInterface>(binder);
}

binder_status_t IMyInterface::writeToParcel(AParcel* parcel, const std::shared_ptr<IMyInterface>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IMyInterface::readFromParcel(const AParcel* parcel, std::shared_ptr<IMyInterface>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IMyInterface::fromBinder(binder);
  return STATUS_OK;
}
bool IMyInterface::setDefaultImpl(std::shared_ptr<IMyInterface> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IMyInterface::default_impl);
  if (impl) {
    IMyInterface::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IMyInterface>& IMyInterface::getDefaultImpl() {
  return IMyInterface::default_impl;
}
std::shared_ptr<IMyInterface> IMyInterface::default_impl = nullptr;
::ndk::ScopedAStatus IMyInterfaceDefault::basicTypes(int32_t /*in_anInt*/, int64_t /*in_aLong*/, bool /*in_aBoolean*/, float /*in_aFloat*/, double /*in_aDouble*/, const std::string& /*in_aString*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IMyInterfaceDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IMyInterfaceDefault::isRemote() {
  return false;
}
}  // namespace common
}  // namespace binder
}  // namespace example
}  // namespace com
}  // namespace aidl
