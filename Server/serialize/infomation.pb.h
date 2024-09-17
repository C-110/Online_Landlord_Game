// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: infomation.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_infomation_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_infomation_2eproto

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_infomation_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_infomation_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_infomation_2eproto;
class Information;
struct InformationDefaultTypeInternal;
extern InformationDefaultTypeInternal _Information_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::Information* Arena::CreateMaybeMessage<::Information>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

enum RequestCode : int {
  UserLogin = 0,
  Register = 1,
  AesFenfa = 2,
  AutoRoom = 3,
  ManualRoom = 4,
  SearchRoom = 5,
  RequestCode_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  RequestCode_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool RequestCode_IsValid(int value);
constexpr RequestCode RequestCode_MIN = UserLogin;
constexpr RequestCode RequestCode_MAX = SearchRoom;
constexpr int RequestCode_ARRAYSIZE = RequestCode_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* RequestCode_descriptor();
template<typename T>
inline const std::string& RequestCode_Name(T enum_t_value) {
  static_assert(::std::is_same<T, RequestCode>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function RequestCode_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    RequestCode_descriptor(), enum_t_value);
}
inline bool RequestCode_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, RequestCode* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<RequestCode>(
    RequestCode_descriptor(), name, value);
}
enum RespondCode : int {
  LoginOk = 0,
  RegisterOk = 1,
  RsaFenFa = 2,
  AesVerifOK = 3,
  JoinRoomOK = 4,
  StartGame = 5,
  SearchRoomOK = 6,
  DealCards = 7,
  Failed = 8,
  RespondCode_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  RespondCode_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool RespondCode_IsValid(int value);
constexpr RespondCode RespondCode_MIN = LoginOk;
constexpr RespondCode RespondCode_MAX = Failed;
constexpr int RespondCode_ARRAYSIZE = RespondCode_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* RespondCode_descriptor();
template<typename T>
inline const std::string& RespondCode_Name(T enum_t_value) {
  static_assert(::std::is_same<T, RespondCode>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function RespondCode_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    RespondCode_descriptor(), enum_t_value);
}
inline bool RespondCode_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, RespondCode* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<RespondCode>(
    RespondCode_descriptor(), name, value);
}
// ===================================================================

class Information final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Information) */ {
 public:
  inline Information() : Information(nullptr) {}
  ~Information() override;
  explicit PROTOBUF_CONSTEXPR Information(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Information(const Information& from);
  Information(Information&& from) noexcept
    : Information() {
    *this = ::std::move(from);
  }

  inline Information& operator=(const Information& from) {
    CopyFrom(from);
    return *this;
  }
  inline Information& operator=(Information&& from) noexcept {
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
  static const Information& default_instance() {
    return *internal_default_instance();
  }
  static inline const Information* internal_default_instance() {
    return reinterpret_cast<const Information*>(
               &_Information_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Information& a, Information& b) {
    a.Swap(&b);
  }
  inline void Swap(Information* other) {
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
  void UnsafeArenaSwap(Information* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Information* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Information>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Information& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Information& from) {
    Information::MergeImpl(*this, from);
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
  void InternalSwap(Information* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Information";
  }
  protected:
  explicit Information(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUserNameFieldNumber = 1,
    kRoomNameFieldNumber = 2,
    kData1FieldNumber = 3,
    kData2FieldNumber = 4,
    kData3FieldNumber = 5,
    kReqcodeFieldNumber = 6,
    kRescodeFieldNumber = 7,
  };
  // string userName = 1;
  void clear_username();
  const std::string& username() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_username(ArgT0&& arg0, ArgT... args);
  std::string* mutable_username();
  PROTOBUF_NODISCARD std::string* release_username();
  void set_allocated_username(std::string* username);
  private:
  const std::string& _internal_username() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_username(const std::string& value);
  std::string* _internal_mutable_username();
  public:

  // string roomName = 2;
  void clear_roomname();
  const std::string& roomname() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_roomname(ArgT0&& arg0, ArgT... args);
  std::string* mutable_roomname();
  PROTOBUF_NODISCARD std::string* release_roomname();
  void set_allocated_roomname(std::string* roomname);
  private:
  const std::string& _internal_roomname() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_roomname(const std::string& value);
  std::string* _internal_mutable_roomname();
  public:

  // string data1 = 3;
  void clear_data1();
  const std::string& data1() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_data1(ArgT0&& arg0, ArgT... args);
  std::string* mutable_data1();
  PROTOBUF_NODISCARD std::string* release_data1();
  void set_allocated_data1(std::string* data1);
  private:
  const std::string& _internal_data1() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_data1(const std::string& value);
  std::string* _internal_mutable_data1();
  public:

  // string data2 = 4;
  void clear_data2();
  const std::string& data2() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_data2(ArgT0&& arg0, ArgT... args);
  std::string* mutable_data2();
  PROTOBUF_NODISCARD std::string* release_data2();
  void set_allocated_data2(std::string* data2);
  private:
  const std::string& _internal_data2() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_data2(const std::string& value);
  std::string* _internal_mutable_data2();
  public:

  // string data3 = 5;
  void clear_data3();
  const std::string& data3() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_data3(ArgT0&& arg0, ArgT... args);
  std::string* mutable_data3();
  PROTOBUF_NODISCARD std::string* release_data3();
  void set_allocated_data3(std::string* data3);
  private:
  const std::string& _internal_data3() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_data3(const std::string& value);
  std::string* _internal_mutable_data3();
  public:

  // .RequestCode reqcode = 6;
  void clear_reqcode();
  ::RequestCode reqcode() const;
  void set_reqcode(::RequestCode value);
  private:
  ::RequestCode _internal_reqcode() const;
  void _internal_set_reqcode(::RequestCode value);
  public:

  // .RespondCode rescode = 7;
  void clear_rescode();
  ::RespondCode rescode() const;
  void set_rescode(::RespondCode value);
  private:
  ::RespondCode _internal_rescode() const;
  void _internal_set_rescode(::RespondCode value);
  public:

  // @@protoc_insertion_point(class_scope:Information)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr username_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr roomname_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr data1_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr data2_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr data3_;
    int reqcode_;
    int rescode_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_infomation_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Information

// string userName = 1;
inline void Information::clear_username() {
  _impl_.username_.ClearToEmpty();
}
inline const std::string& Information::username() const {
  // @@protoc_insertion_point(field_get:Information.userName)
  return _internal_username();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Information::set_username(ArgT0&& arg0, ArgT... args) {
 
 _impl_.username_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Information.userName)
}
inline std::string* Information::mutable_username() {
  std::string* _s = _internal_mutable_username();
  // @@protoc_insertion_point(field_mutable:Information.userName)
  return _s;
}
inline const std::string& Information::_internal_username() const {
  return _impl_.username_.Get();
}
inline void Information::_internal_set_username(const std::string& value) {
  
  _impl_.username_.Set(value, GetArenaForAllocation());
}
inline std::string* Information::_internal_mutable_username() {
  
  return _impl_.username_.Mutable(GetArenaForAllocation());
}
inline std::string* Information::release_username() {
  // @@protoc_insertion_point(field_release:Information.userName)
  return _impl_.username_.Release();
}
inline void Information::set_allocated_username(std::string* username) {
  if (username != nullptr) {
    
  } else {
    
  }
  _impl_.username_.SetAllocated(username, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.username_.IsDefault()) {
    _impl_.username_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Information.userName)
}

// string roomName = 2;
inline void Information::clear_roomname() {
  _impl_.roomname_.ClearToEmpty();
}
inline const std::string& Information::roomname() const {
  // @@protoc_insertion_point(field_get:Information.roomName)
  return _internal_roomname();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Information::set_roomname(ArgT0&& arg0, ArgT... args) {
 
 _impl_.roomname_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Information.roomName)
}
inline std::string* Information::mutable_roomname() {
  std::string* _s = _internal_mutable_roomname();
  // @@protoc_insertion_point(field_mutable:Information.roomName)
  return _s;
}
inline const std::string& Information::_internal_roomname() const {
  return _impl_.roomname_.Get();
}
inline void Information::_internal_set_roomname(const std::string& value) {
  
  _impl_.roomname_.Set(value, GetArenaForAllocation());
}
inline std::string* Information::_internal_mutable_roomname() {
  
  return _impl_.roomname_.Mutable(GetArenaForAllocation());
}
inline std::string* Information::release_roomname() {
  // @@protoc_insertion_point(field_release:Information.roomName)
  return _impl_.roomname_.Release();
}
inline void Information::set_allocated_roomname(std::string* roomname) {
  if (roomname != nullptr) {
    
  } else {
    
  }
  _impl_.roomname_.SetAllocated(roomname, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.roomname_.IsDefault()) {
    _impl_.roomname_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Information.roomName)
}

// string data1 = 3;
inline void Information::clear_data1() {
  _impl_.data1_.ClearToEmpty();
}
inline const std::string& Information::data1() const {
  // @@protoc_insertion_point(field_get:Information.data1)
  return _internal_data1();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Information::set_data1(ArgT0&& arg0, ArgT... args) {
 
 _impl_.data1_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Information.data1)
}
inline std::string* Information::mutable_data1() {
  std::string* _s = _internal_mutable_data1();
  // @@protoc_insertion_point(field_mutable:Information.data1)
  return _s;
}
inline const std::string& Information::_internal_data1() const {
  return _impl_.data1_.Get();
}
inline void Information::_internal_set_data1(const std::string& value) {
  
  _impl_.data1_.Set(value, GetArenaForAllocation());
}
inline std::string* Information::_internal_mutable_data1() {
  
  return _impl_.data1_.Mutable(GetArenaForAllocation());
}
inline std::string* Information::release_data1() {
  // @@protoc_insertion_point(field_release:Information.data1)
  return _impl_.data1_.Release();
}
inline void Information::set_allocated_data1(std::string* data1) {
  if (data1 != nullptr) {
    
  } else {
    
  }
  _impl_.data1_.SetAllocated(data1, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.data1_.IsDefault()) {
    _impl_.data1_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Information.data1)
}

// string data2 = 4;
inline void Information::clear_data2() {
  _impl_.data2_.ClearToEmpty();
}
inline const std::string& Information::data2() const {
  // @@protoc_insertion_point(field_get:Information.data2)
  return _internal_data2();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Information::set_data2(ArgT0&& arg0, ArgT... args) {
 
 _impl_.data2_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Information.data2)
}
inline std::string* Information::mutable_data2() {
  std::string* _s = _internal_mutable_data2();
  // @@protoc_insertion_point(field_mutable:Information.data2)
  return _s;
}
inline const std::string& Information::_internal_data2() const {
  return _impl_.data2_.Get();
}
inline void Information::_internal_set_data2(const std::string& value) {
  
  _impl_.data2_.Set(value, GetArenaForAllocation());
}
inline std::string* Information::_internal_mutable_data2() {
  
  return _impl_.data2_.Mutable(GetArenaForAllocation());
}
inline std::string* Information::release_data2() {
  // @@protoc_insertion_point(field_release:Information.data2)
  return _impl_.data2_.Release();
}
inline void Information::set_allocated_data2(std::string* data2) {
  if (data2 != nullptr) {
    
  } else {
    
  }
  _impl_.data2_.SetAllocated(data2, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.data2_.IsDefault()) {
    _impl_.data2_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Information.data2)
}

// string data3 = 5;
inline void Information::clear_data3() {
  _impl_.data3_.ClearToEmpty();
}
inline const std::string& Information::data3() const {
  // @@protoc_insertion_point(field_get:Information.data3)
  return _internal_data3();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Information::set_data3(ArgT0&& arg0, ArgT... args) {
 
 _impl_.data3_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Information.data3)
}
inline std::string* Information::mutable_data3() {
  std::string* _s = _internal_mutable_data3();
  // @@protoc_insertion_point(field_mutable:Information.data3)
  return _s;
}
inline const std::string& Information::_internal_data3() const {
  return _impl_.data3_.Get();
}
inline void Information::_internal_set_data3(const std::string& value) {
  
  _impl_.data3_.Set(value, GetArenaForAllocation());
}
inline std::string* Information::_internal_mutable_data3() {
  
  return _impl_.data3_.Mutable(GetArenaForAllocation());
}
inline std::string* Information::release_data3() {
  // @@protoc_insertion_point(field_release:Information.data3)
  return _impl_.data3_.Release();
}
inline void Information::set_allocated_data3(std::string* data3) {
  if (data3 != nullptr) {
    
  } else {
    
  }
  _impl_.data3_.SetAllocated(data3, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.data3_.IsDefault()) {
    _impl_.data3_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Information.data3)
}

// .RequestCode reqcode = 6;
inline void Information::clear_reqcode() {
  _impl_.reqcode_ = 0;
}
inline ::RequestCode Information::_internal_reqcode() const {
  return static_cast< ::RequestCode >(_impl_.reqcode_);
}
inline ::RequestCode Information::reqcode() const {
  // @@protoc_insertion_point(field_get:Information.reqcode)
  return _internal_reqcode();
}
inline void Information::_internal_set_reqcode(::RequestCode value) {
  
  _impl_.reqcode_ = value;
}
inline void Information::set_reqcode(::RequestCode value) {
  _internal_set_reqcode(value);
  // @@protoc_insertion_point(field_set:Information.reqcode)
}

// .RespondCode rescode = 7;
inline void Information::clear_rescode() {
  _impl_.rescode_ = 0;
}
inline ::RespondCode Information::_internal_rescode() const {
  return static_cast< ::RespondCode >(_impl_.rescode_);
}
inline ::RespondCode Information::rescode() const {
  // @@protoc_insertion_point(field_get:Information.rescode)
  return _internal_rescode();
}
inline void Information::_internal_set_rescode(::RespondCode value) {
  
  _impl_.rescode_ = value;
}
inline void Information::set_rescode(::RespondCode value) {
  _internal_set_rescode(value);
  // @@protoc_insertion_point(field_set:Information.rescode)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::RequestCode> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::RequestCode>() {
  return ::RequestCode_descriptor();
}
template <> struct is_proto_enum< ::RespondCode> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::RespondCode>() {
  return ::RespondCode_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_infomation_2eproto
