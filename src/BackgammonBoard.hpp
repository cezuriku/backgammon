#ifndef BACKGAMMONBOARD_HPP
#define BACKGAMMONBOARD_HPP
#include <array>

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
  BackgammonBoard();

  void reset();

  const std::array<BackgammonBoardCell, 24> &cells() { return cells_; };
  const BackgammonBoardCell &bar() { return bar_; };
  const BackgammonBoardCell &off() { return off_; };

private:
  std::array<BackgammonBoardCell, 24> cells_;
  BackgammonBoardCell bar_;
  BackgammonBoardCell off_;
};

#endif /* BACKGAMMONBOARD_HPP */
