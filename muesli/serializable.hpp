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

#define MUESLI_SERIALIZABLE(...)          \
  template <typename Archive>             \
  void serialize(Archive& a) {            \
    a(MAP_LIST(CEREAL_NVP, __VA_ARGS__)); \
  }
