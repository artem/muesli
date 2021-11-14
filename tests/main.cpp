#include <muesli/archives.hpp>

#include <muesli/serialize.hpp>
#include <muesli/serializable.hpp>

#include <muesli/bytes.hpp>
#include <muesli/tuple.hpp>

#include <cassert>

//////////////////////////////////////////////////////////////////////

struct Point {
  uint32_t x;
  uint32_t y;

  MUESLI_SERIALIZABLE(x, y)
};

struct TestObject {
  std::string name;
  uint64_t count;
  Point point;

  MUESLI_SERIALIZABLE(name, count, point)
};

//////////////////////////////////////////////////////////////////////

void TestSerialize() {
  TestObject a{"Test", 1932342111, {12345, 54321}};

  auto bytes = muesli::Serialize(a);
  auto b = muesli::Deserialize<TestObject>(bytes);

  assert(a.name == b.name);
  assert(a.count == b.count);
  assert(a.point.x == b.point.x);
  assert(a.point.y == b.point.y);

  std::cout << "Test <Serialize>: Ok!" << std::endl;
}

//////////////////////////////////////////////////////////////////////

void TestTuple() {
  auto bytes = muesli::SerializeValues<Point, std::string, Point>(
      {1, 2}, "Hi", {42, 41});

  auto [p1, message, p2] = muesli::DeserializeValues<Point, std::string, Point>(bytes);

  assert(p1.x == 1);
  assert(p1.y == 2);

  assert(message == "Hi");

  assert(p2.x == 42);
  assert(p2.y == 41);

  std::cout << "Test <Tuple>: Ok!" << std::endl;
}

//////////////////////////////////////////////////////////////////////

enum class State {
  UnCommitted,
  Committed };

State PackUnpack(State state) {
  auto bytes = muesli::Serialize(state);
  auto value = muesli::Deserialize<State>(bytes);
  return value;
}

void TestEnumClass() {
  assert(PackUnpack(State::Committed) == State::Committed);

  std::cout << "Test <EnumClass>: Ok!" << std::endl;
}

//////////////////////////////////////////////////////////////////////

void Preamble() {
  std::cout << "Archive format: "
            << muesli::archives::FormatName() << std::endl;
  std::cout << "IsBinaryFormat: "
            << muesli::archives::IsBinaryFormat() << std::endl;

  std::cout << std::endl;
}

//////////////////////////////////////////////////////////////////////

int main() {
  Preamble();
  TestSerialize();
  TestTuple();
  TestEnumClass();
  return 0;
}
