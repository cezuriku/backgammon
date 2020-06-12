#include "BackgammonBoard.hpp"

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
}
