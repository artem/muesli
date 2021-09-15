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

void TestBytes() {
  auto bytes = muesli::Bytes::Serialize(Point{3, 51});
  auto point = bytes.As<Point>();

  assert(point.x == 3);
  assert(point.y == 51);

  std::cout << "Test <Bytes>: Ok!" << std::endl;
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

int main() {
  TestSerialize();
  TestBytes();
  TestTuple();
  return 0;
}
