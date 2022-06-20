#include <gtest/gtest.h>
#include "./test_stack.cpp"
#include "./test_vector.cpp"
#include "./test_map.cpp"

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}