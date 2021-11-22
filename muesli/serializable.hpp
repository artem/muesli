#pragma once

#include <muesli/detail/map.hpp>

#include <cereal/cereal.hpp>

/* Usage:
 * struct MyMessage {
 *   uint32_t a;
 *   std::string b;
 *
 *   MUESLI_SERIALIZABLE(a, b)
 * };
 */

#define _MUESLI_SERIALIZE_FIELD(field) \
  a(::cereal::make_nvp(#field, this->field));

#define MUESLI_SERIALIZABLE(...)               \
  template <typename Archive>                  \
  void serialize(Archive& a) {                 \
    MAP(_MUESLI_SERIALIZE_FIELD, __VA_ARGS__); \
  }
