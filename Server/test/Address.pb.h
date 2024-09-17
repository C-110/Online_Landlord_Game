// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Address.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Address_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Address_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Address_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Address_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Address_2eproto;
namespace MyAddress {
class Address;
struct AddressDefaultTypeInternal;
extern AddressDefaultTypeInternal _Address_default_instance_;
}  // namespace MyAddress
PROTOBUF_NAMESPACE_OPEN
template<> ::MyAddress::Address* Arena::CreateMaybeMessage<::MyAddress::Address>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace MyAddress {

// ===================================================================

class Address final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:MyAddress.Address) */ {
 public:
  inline Address() : Address(nullptr) {}
  ~Address() override;
  explicit PROTOBUF_CONSTEXPR Address(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Address(const Address& from);
  Address(Address&& from) noexcept
    : Address() {
    *this = ::std::move(from);
  }

  inline Address& operator=(const Address& from) {
    CopyFrom(from);
    return *this;
  }
  inline Address& operator=(Address&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Address& default_instance() {
    return *internal_default_instance();
  }
  static inline const Address* internal_default_instance() {
    return reinterpret_cast<const Address*>(
               &_Address_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Address& a, Address& b) {
    a.Swap(&b);
  }
  inline void Swap(Address* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Address* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Address* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Address>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Address& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Address& from) {
    Address::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Address* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "MyAddress.Address";
  }
  protected:
  explicit Address(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kAddrFieldNumber = 2,
    kNumFieldNumber = 1,
  };
  // bytes addr = 2;
  void clear_addr();
  const std::string& addr() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_addr(ArgT0&& arg0, ArgT... args);
  std::string* mutable_addr();
  PROTOBUF_NODISCARD std::string* release_addr();
  void set_allocated_addr(std::string* addr);
  private:
  const std::string& _internal_addr() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_addr(const std::string& value);
  std::string* _internal_mutable_addr();
  public:

  // int32 num = 1;
  void clear_num();
  int32_t num() const;
  void set_num(int32_t value);
  private:
  int32_t _internal_num() const;
  void _internal_set_num(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:MyAddress.Address)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr addr_;
    int32_t num_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Address_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Address

// int32 num = 1;
inline void Address::clear_num() {
  _impl_.num_ = 0;
}
inline int32_t Address::_internal_num() const {
  return _impl_.num_;
}
inline int32_t Address::num() const {
  // @@protoc_insertion_point(field_get:MyAddress.Address.num)
  return _internal_num();
}
inline void Address::_internal_set_num(int32_t value) {
  
  _impl_.num_ = value;
}
inline void Address::set_num(int32_t value) {
  _internal_set_num(value);
  // @@protoc_insertion_point(field_set:MyAddress.Address.num)
}

// bytes addr = 2;
inline void Address::clear_addr() {
  _impl_.addr_.ClearToEmpty();
}
inline const std::string& Address::addr() const {
  // @@protoc_insertion_point(field_get:MyAddress.Address.addr)
  return _internal_addr();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Address::set_addr(ArgT0&& arg0, ArgT... args) {
 
 _impl_.addr_.SetBytes(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:MyAddress.Address.addr)
}
inline std::string* Address::mutable_addr() {
  std::string* _s = _internal_mutable_addr();
  // @@protoc_insertion_point(field_mutable:MyAddress.Address.addr)
  return _s;
}
inline const std::string& Address::_internal_addr() const {
  return _impl_.addr_.Get();
}
inline void Address::_internal_set_addr(const std::string& value) {
  
  _impl_.addr_.Set(value, GetArenaForAllocation());
}
inline std::string* Address::_internal_mutable_addr() {
  
  return _impl_.addr_.Mutable(GetArenaForAllocation());
}
inline std::string* Address::release_addr() {
  // @@protoc_insertion_point(field_release:MyAddress.Address.addr)
  return _impl_.addr_.Release();
}
inline void Address::set_allocated_addr(std::string* addr) {
  if (addr != nullptr) {
    
  } else {
    
  }
  _impl_.addr_.SetAllocated(addr, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.addr_.IsDefault()) {
    _impl_.addr_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:MyAddress.Address.addr)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace MyAddress

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Address_2eproto
