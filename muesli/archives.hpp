#pragma once

#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>

#include <string>

namespace muesli::archives {

#ifdef MUESLI_ARCHIVE_JSON

using Writer = cereal::JSONOutputArchive;
using Reader = cereal::JSONInputArchive;

inline bool IsBinaryFormat() {
  return false;
}

inline std::string_view FormatName() {
  return "json";
}

#elif MUESLI_ARCHIVE_BINARY

using Writer = cereal::BinaryOutputArchive;
using Reader = cereal::BinaryInputArchive;

inline bool IsBinaryFormat() {
  return true;
}

inline std::string_view FormatName() {
  return "binary";
}

#else

#error Muesli: Archive format not set

#endif

}  // namespace muesli::archives
