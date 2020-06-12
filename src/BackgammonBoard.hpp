#ifndef BACKGAMMONBOARD_HPP
#define BACKGAMMONBOARD_HPP
#include <iostream>

struct BackgammonBoardCell
{
  BackgammonBoardCell() : BackgammonBoardCell(0, 0){};
  BackgammonBoardCell(int white, int black) : white(white), black(black) {}
  int white;
  int black;
};

class BackgammonBoard
{
public:
  BackgammonBoard() = default;

  void reset();

private:
  BackgammonBoardCell cells_[24];
  BackgammonBoardCell bar;
  BackgammonBoardCell off;
};

#endif /* BACKGAMMONBOARD_HPP */
