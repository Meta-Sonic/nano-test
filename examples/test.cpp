#include "utest.h"
#include <stdexcept>

namespace {

TEST_CASE("Example", Expect, "Expects") {
  int a = 0;
  EXPECT_NOT_NULL(&a);
  EXPECT_NULL(nullptr);

  EXPECT_EQ(1, 1);
  EXPECT_NE(0, 1);

  EXPECT_LT(5, 6);
  EXPECT_LE(5, 6);
  EXPECT_LE(5, 5);

  EXPECT_GT(7, 6);
  EXPECT_GE(7, 6);
  EXPECT_GE(5, 5);

  EXPECT_STR_EQ("A", "A");
  EXPECT_STR_NE("A", "B");

  EXPECT_FLOAT_EQ(2.2f, 2.2f);
  EXPECT_FLOAT_EQ(2.2000001f, 2.2f);

  EXPECT_FLOAT_NE(2.2f, 2.3f);

  EXPECT_FLOAT_EQ_T(4.5f, 4.5f, 0.1f);
  EXPECT_FLOAT_EQ_T(4.5f, 4.6f, 0.1f);

  EXPECT_FLOAT_NE_T(4.5f, 4.7f, 0.01f);
}

inline void foo_throw(bool err) {
  if (err) {
    throw std::range_error("bad range");
  }
}

TEST_CASE("Example", Exception, "Check exceptions", NANO_TEST_ABORT_ON_ERROR) {
  ASSERT_EXCEPTION(foo_throw(true), std::range_error);
  EXPECT_EXCEPTION(foo_throw(true), std::exception);
  // ASSERT_EXCEPTION(foo_throw(true), std::bad_cast);
}

TEST_CASE("Example", Range) {
  int a[] = { 1, 2, 3 };
  long b[] = { 1, 2, 4 };

  EXPECT_RANGE_EQ(&a[0], &b[0], 2);
  EXPECT_RANGE_GE(&a[0], &b[0], 2);
  ASSERT_RANGE_EQ(&a[0], &b[0], 3);
}
} // namespace.
