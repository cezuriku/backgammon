#include "BackgammonBoard.hpp"

BackgammonBoard::BackgammonBoard()
{
  reset();
}

void BackgammonBoard::reset()
{
  for (int i = 0; i < 24; i++)
  {
    cells_[i] = BackgammonBoardCell();
  }
  cells_[0] = BackgammonBoardCell(0, 2);
  cells_[5] = BackgammonBoardCell(5, 0);
  cells_[7] = BackgammonBoardCell(3, 0);
  cells_[11] = BackgammonBoardCell(0, 5);
  cells_[12] = BackgammonBoardCell(5, 0);
  cells_[16] = BackgammonBoardCell(0, 3);
  cells_[18] = BackgammonBoardCell(0, 5);
  cells_[23] = BackgammonBoardCell(2, 0);

  bar_ = BackgammonBoardCell();
  off_ = BackgammonBoardCell();
}

void BackgammonBoard::applyMoves(BackgammonColor color,
                                 std::vector<std::pair<int, int>> moves)
{
  for (auto &move : moves)
    applyMove(color, move);
};

void BackgammonBoard::applyMove(BackgammonColor color, std::pair<int, int> move)
{
  if (move.first != -1)
  {
    cells_[move.first].remove(color);
  }
  else
  {
    bar_.remove(color);
  }

  if (move.second == -2)
  {
    // go off the board
    off_.add(color);
  }
  else if (cells_[move.second].getOpposite(color) == 1)
  {
    // This is a hit
    bar_.addOpposite(color);
    cells_[move.second].set(color);
  }
  else
  {
    cells_[move.second].add(color);
  }
};