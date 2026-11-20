#ifndef PHASAR_UTILS_LLVMCOMPATIBILITY_H
#define PHASAR_UTILS_LLVMCOMPATIBILITY_H

#include "llvm/ADT/StringRef.h"
#include "llvm/Config/llvm-config.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/raw_ostream.h"

#include <optional>

#if LLVM_VERSION_MAJOR < 16
namespace llvm {
inline raw_ostream &operator<<(raw_ostream &OS, std::nullopt_t) {
  return OS << "None";
}
} // namespace llvm
#endif

namespace psr {
inline bool startsWith(llvm::StringRef Text, llvm::StringRef Prefix) {
#if LLVM_VERSION_MAJOR < 16
  return Text.startswith(Prefix);
#else
  return Text.starts_with(Prefix);
#endif
}
inline bool endsWith(llvm::StringRef Text, llvm::StringRef Suffix) {
#if LLVM_VERSION_MAJOR < 16
  return Text.endswith(Suffix);
#else
  return Text.ends_with(Suffix);
#endif
}
template <typename To, typename From> auto dynCastIfPresent(From *Value) {
#if LLVM_VERSION_MAJOR < 15
  return llvm::dyn_cast_or_null<To>(Value);
#else
  return llvm::dyn_cast_if_present<To>(Value);
#endif
}
} // namespace psr
#endif
