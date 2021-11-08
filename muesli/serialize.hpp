#pragma once

#include <muesli/detail/type_name.hpp>

#include <muesli/archives.hpp>
#include <muesli/bytes.hpp>

#include <cereal/types/string.hpp>

#include <sstream>

namespace muesli {

// Helpers for 'cereal' library
// https://github.com/USCiLab/cereal

//////////////////////////////////////////////////////////////////////

namespace detail {

struct Header {
  std::string type_name;

  template <typename Archive>
  void serialize(Archive& a) {
    a(CEREAL_NVP(type_name));
  }
};

}  // namespace detail

//////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

template <typename T>
void Serialize(const T& object, std::ostream& output) {
  // Prepare header
  detail::Header header;
  header.type_name = detail::GetTypeName<T>();

  {
    archives::Writer writer(output);
    writer(CEREAL_NVP(header));
    writer(CEREAL_NVP(object));
  }
}

#else

template <typename T>
void Serialize(const T& object, std::ostream& output) {
  archives::Writer writer(output);
  writer(object);
}

#endif

template <typename T>
Bytes Serialize(const T& object) {
  std::stringstream str_output;
  Serialize(object, str_output);
  return str_output.str();
}

//////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

template <typename T>
T Deserialize(std::istream& input) {
  const auto type_name = detail::GetTypeName<T>();

  detail::Header header;
  T object;

  {
    archives::Reader reader(input);
    reader(header);

    if (header.type_name != type_name) {
      std::stringstream error;
      error << "Cannot deserialize value of type '" << type_name
            << "', serialized value has type '" << header.type_name << "'";

      throw std::runtime_error(error.str());
    }

    reader(object);  // Read the data from the archive
  }

  return object;
}

#else

template <typename T>
T Deserialize(std::istream& input) {
  T object;
  {
    archives::Reader reader(input);
    reader(object);
  }
  return object;
}

#endif

template <typename T>
T Deserialize(const Bytes& str) {
  std::stringstream str_input(str);
  return Deserialize<T>(str_input);
}

}  // namespace muesli
