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
  EXPECT_EQ(2, board.cells()[0].get(BackgammonColor::Black));
  EXPECT_EQ(5, board.cells()[5].get(BackgammonColor::White));
  // TODO: Check other cells
  EXPECT_EQ(0, board.bar().get(BackgammonColor::Black));
  EXPECT_EQ(0, board.bar().get(BackgammonColor::White));
  EXPECT_EQ(0, board.off().get(BackgammonColor::Black));
  EXPECT_EQ(0, board.off().get(BackgammonColor::White));
}

TEST_F(BackgammonBoardTest, BackgammonBoardMove)
{
  BackgammonBoard board;
  std::vector<std::pair<int, int>> moves{{0, 2}, {0, 3}};
  EXPECT_EQ(2, board.cells()[0].get(BackgammonColor::Black));
  EXPECT_EQ(0, board.cells()[2].get(BackgammonColor::Black));
  EXPECT_EQ(0, board.cells()[3].get(BackgammonColor::Black));
  board.applyMoves(BackgammonColor::Black, moves);
  EXPECT_EQ(0, board.cells()[0].get(BackgammonColor::Black));
  EXPECT_EQ(1, board.cells()[2].get(BackgammonColor::Black));
  EXPECT_EQ(1, board.cells()[3].get(BackgammonColor::Black));
}

TEST_F(BackgammonBoardTest, BackgammonBoardMoveAndHit)
{
  BackgammonBoard board;
  std::vector<std::pair<int, int>> blackMoves{{0, 2}, {0, 3}};
  std::vector<std::pair<int, int>> whiteMoves{{5, 2}, {5, 3}};
  EXPECT_EQ(5, board.cells()[5].get(BackgammonColor::White));
  EXPECT_EQ(0, board.bar().get(BackgammonColor::Black));
  EXPECT_EQ(0, board.bar().get(BackgammonColor::White));
  board.applyMoves(BackgammonColor::Black, blackMoves);
  board.applyMoves(BackgammonColor::White, whiteMoves);
  EXPECT_EQ(1, board.cells()[2].get(BackgammonColor::White));
  EXPECT_EQ(1, board.cells()[3].get(BackgammonColor::White));
  EXPECT_EQ(0, board.cells()[2].get(BackgammonColor::Black));
  EXPECT_EQ(0, board.cells()[3].get(BackgammonColor::Black));
  EXPECT_EQ(3, board.cells()[5].get(BackgammonColor::White));
  EXPECT_EQ(2, board.bar().get(BackgammonColor::Black));
  EXPECT_EQ(0, board.bar().get(BackgammonColor::White));
}