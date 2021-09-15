#pragma once

#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>

namespace muesli::archives {

#ifndef NDEBUG

using Writer = cereal::JSONOutputArchive;
using Reader = cereal::JSONInputArchive;

#else

using Writer = cereal::BinaryOutputArchive;
using Reader = cereal::BinaryInputArchive;

#endif

}  // namespace muesli::archives
