#include <gtest/gtest.h>

#include "../src/BackgammonBoard.hpp"

class BackgammonBoardTest : public ::testing::Test
{
protected:
  BackgammonBoardTest() = default;
  virtual ~BackgammonBoardTest() = default;
};

TEST_F(BackgammonBoardTest, BackgammonBoardInit)
{
  BackgammonBoard board;
  EXPECT_EQ(2, board.cells()[0].black);
  EXPECT_EQ(5, board.cells()[5].white);
  // TODO: Check other cells
  EXPECT_EQ(0, board.bar().white);
  EXPECT_EQ(0, board.bar().black);
  EXPECT_EQ(0, board.off().white);
  EXPECT_EQ(0, board.off().black);
}
