#pragma once

#include <muesli/serialize.hpp>

#include <cereal/types/tuple.hpp>

#include <tuple>
#include <utility>

namespace muesli {

template <typename... Types>
std::string SerializeValues(Types&&... values) {
  auto packed_values = std::make_tuple(std::forward<Types>(values)...);
  return Serialize(packed_values);
};

namespace detail {

template <typename... Types>
struct Packer {
  using ValuesTuple = std::tuple<typename std::decay<Types>::type...>;
};

}  // namespace detail

template <typename... Types>
auto DeserializeValues(const std::string& bytes) {
  using ValuesTuple = typename detail::Packer<Types...>::ValuesTuple;

  return Deserialize<ValuesTuple>(bytes);
};

}  // namespace muesli
