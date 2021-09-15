#pragma once

#include <ctti/type_id.hpp>

#include <string>
#include <sstream>

namespace muesli::detail {

template <typename T>
std::string GetTypeName() {
  const auto name = ctti::nameof<T>();
  std::stringstream out;
  out << name;
  return out.str();
}

}  // namespace muesli::detail
