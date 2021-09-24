#pragma once

#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>

#include <string>

namespace muesli::archives {

//////////////////////////////////////////////////////////////////////

struct BinaryArchives {
  using Writer = cereal::BinaryOutputArchive;
  using Reader = cereal::BinaryInputArchive;

  static const bool kIsBinary = true;

  static const char* FormatName() {
    return "binary";
  }
};

//////////////////////////////////////////////////////////////////////

struct JsonArchives {
  using Writer = cereal::JSONOutputArchive;
  using Reader = cereal::JSONInputArchive;

  static const bool kIsBinary = false;

  static const char* FormatName() {
    return "json";
  }
};

//////////////////////////////////////////////////////////////////////

#ifdef MUESLI_ARCHIVE_JSON

using Archives = JsonArchives;

#elif MUESLI_ARCHIVE_BINARY

using Archives = BinaryArchives;

#else

// #error Muesli: Archive format not set
using Archives = JsonArchives;

#endif

//////////////////////////////////////////////////////////////////////

using Writer = Archives::Writer;
using Reader = Archives::Reader;

inline bool IsBinaryFormat() {
  return Archives::kIsBinary;
}

inline std::string_view FormatName() {
  return Archives::FormatName();
}

}  // namespace muesli::archives
