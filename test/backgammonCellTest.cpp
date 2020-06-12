#include <gtest/gtest.h>

#include "../src/BackgammonBoard.hpp"

class BackgammonBoardCellTest : public ::testing::Test
{
protected:
  BackgammonBoardCellTest() = default;
  virtual ~BackgammonBoardCellTest() = default;
};

TEST_F(BackgammonBoardCellTest, BackgammonBoardCellInitBlack)
{
  BackgammonBoardCell cell(0, 2);
  EXPECT_EQ(0, cell.white);
  EXPECT_EQ(2, cell.black);
}

TEST_F(BackgammonBoardCellTest, BackgammonBoardCellInitWhite)
{
  BackgammonBoardCell cell(2, 0);
  EXPECT_EQ(2, cell.white);
  EXPECT_EQ(0, cell.black);
}
