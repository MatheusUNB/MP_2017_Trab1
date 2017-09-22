#include "sample1.h"
#include "gtest/gtest.h"
namespace {

//TESTES

//INVALIDO
TEST(soma_string, INVALIDO) {
  EXPECT_EQ(-1,soma_string(""));
  EXPECT_EQ(-1,soma_string("1"));
}

//VALIDO
TEST(soma_string, VALIDO) {
  EXPECT_EQ(6,soma_string("1,2,3\n"));
}

}  // namespace

