#pragma once

#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>

#include <string>

namespace muesli::archives {

#ifndef NDEBUG

using Writer = cereal::JSONOutputArchive;
using Reader = cereal::JSONInputArchive;

inline bool IsBinaryFormat() {
  return false;
}

inline std::string_view FormatName() {
  return "json";
}

#else

using Writer = cereal::BinaryOutputArchive;
using Reader = cereal::BinaryInputArchive;

inline bool IsBinaryFormat() {
  return true;
}

inline std::string_view FormatName() {
  return "binary";
}

#endif

}  // namespace muesli::archives
