#ifndef COMMON_XERCESSUP_H_
#define COMMON_XERCESSUP_H_

#include <utility>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/Xerces_autoconf_config.hpp>

namespace common::Xerces {

namespace Concept {
template <typename Input>
using transcode_output_t = decltype(xercesc::XMLString::transcode(std::declval<Input>()));

template <typename Input, typename = void>
struct is_transcodable : std::false_type {};

template <typename Input>
struct is_transcodable<Input, std::void_t<transcode_output_t<Input>>> : std::true_type {};

template <typename Input>
constexpr bool is_transcodable_v = is_transcodable<Input>::value;
} // namespace Concept

template <typename Output>
class ScopedTranscode {
public:
  template <typename Input, typename = std::enable_if_t<Concept::is_transcodable_v<Input>>>
  explicit ScopedTranscode(const Input ptr) noexcept : ptr{xercesc::XMLString::transcode(ptr)} {}
  ~ScopedTranscode() { xercesc::XMLString::release(&ptr); }

  ScopedTranscode(const ScopedTranscode &) = delete;
  ScopedTranscode &operator=(const ScopedTranscode &) = delete;

  ScopedTranscode(ScopedTranscode &&other) noexcept : ptr{std::exchange(other.ptr, nullptr)} {}
  ScopedTranscode &operator=(ScopedTranscode &&other) noexcept {
    if (this != &other) {
      xercesc::XMLString::release(&ptr);
      ptr = std::exchange(other.ptr, nullptr);
    }
    return *this;
  }

  operator Output() const noexcept { return ptr; }

private:
  Output ptr;
};

template <typename Input>
explicit ScopedTranscode(Input ptr) -> ScopedTranscode<Concept::transcode_output_t<Input>>;

class ScopedInitialization {
public:
  ScopedInitialization() noexcept { xercesc::XMLPlatformUtils::Initialize(); }
  ScopedInitialization(const ScopedInitialization & /*other*/) noexcept { xercesc::XMLPlatformUtils::Initialize(); }
  ScopedInitialization &operator=(const ScopedInitialization &other) noexcept {
    if (this != &other) { xercesc::XMLPlatformUtils::Initialize(); }
    return *this;
  }
  ScopedInitialization(ScopedInitialization && /*other*/) noexcept { xercesc::XMLPlatformUtils::Initialize(); }
  ScopedInitialization &operator=(ScopedInitialization &&other) noexcept {
    if (this != &other) { xercesc::XMLPlatformUtils::Initialize(); }
    return *this;
  }
  ~ScopedInitialization() { xercesc::XMLPlatformUtils::Terminate(); }
};

inline int toInt(const XMLCh *const xerces_string) {
  return std::atoi(ScopedTranscode(xerces_string));
}
} // namespace common::Xerces

#endif
