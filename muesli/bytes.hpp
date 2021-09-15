#pragma once

#include <muesli/serialize.hpp>
#include <muesli/serializable.hpp>

namespace muesli {

class Bytes {
 public:
  Bytes(std::string bytes) : bytes_(std::move(bytes)) {
  }

  Bytes() = default;

  template <typename T>
  static Bytes Serialize(const T& value) {
    return {::muesli::Serialize<T>(value)};
  }

  template <typename T>
  T As() const {
    return Deserialize<T>(bytes_);
  }

  const std::string& Raw() const {
    return bytes_;
  }

  MUESLI_SERIALIZABLE(bytes_)

 private:
  std::string bytes_;
};

}  // namespace muesli
