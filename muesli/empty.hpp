#pragma once

namespace muesli {

struct EmptyMessage {
  template <typename Archive>
  void serialize(Archive& /*unused*/) {
    ;
  }
};

}  // namespace muesli
