#ifndef BACKGAMMONBOARD_HPP
#define BACKGAMMONBOARD_HPP
#include <array>
#include <vector>

enum class BackgammonColor
{
  White,
  Black
};

class BackgammonBoardCell
{
public:
  BackgammonBoardCell() : BackgammonBoardCell(0, 0){};
  BackgammonBoardCell(int white, int black) : white_(white), black_(black) {}
  BackgammonBoardCell(BackgammonColor color, int checkers) : white_(0), black_(0)
  {
    switch (color)
    {
    case BackgammonColor::Black:
      black_ = checkers;
      break;
    case BackgammonColor::White:
      white_ = checkers;
      break;
    }
  }

  void set(BackgammonColor color)
  {
    switch (color)
    {
    case BackgammonColor::Black:
      black_ = 1;
      white_ = 0;
      break;
    case BackgammonColor::White:
      white_ = 1;
      black_ = 0;
      break;
    }
  };

  void add(BackgammonColor color)
  {
    switch (color)
    {
    case BackgammonColor::Black:
      black_++;
      break;
    case BackgammonColor::White:
      white_++;
      break;
    }
  };

  void addOpposite(BackgammonColor color)
  {
    switch (color)
    {
    case BackgammonColor::Black:
      white_++;
      break;
    case BackgammonColor::White:
      black_++;
      break;
    }
  };

  void remove(BackgammonColor color)
  {
    switch (color)
    {
    case BackgammonColor::Black:
      black_--;
      break;
    case BackgammonColor::White:
      white_--;
      break;
    }
  };

  int get(BackgammonColor color) const
  {
    switch (color)
    {
    case BackgammonColor::Black:
      return black_;
    case BackgammonColor::White:
      return white_;
    }
    return 0;
  };

  int getOpposite(BackgammonColor color) const
  {
    switch (color)
    {
    case BackgammonColor::Black:
      return white_;
    case BackgammonColor::White:
      return black_;
    }
    return 0;
  };

private:
  int white_;
  int black_;
};

struct BackgammonMove
{
  BackgammonColor color;
  // Value between 1 and 6 for each dice
  std::array<int, 2> dices;
  // vector of moves (origin, destination)
  // origin and destination can be -1 for bar or -2 for off
  std::vector<std::pair<int, int>> moves;
};

class BackgammonBoard
{
public:
  BackgammonBoard();

  void reset();

  const std::array<BackgammonBoardCell, 24> &cells() { return cells_; };
  const BackgammonBoardCell &bar() { return bar_; };
  const BackgammonBoardCell &off() { return off_; };

  void applyMoves(BackgammonColor color, std::vector<std::pair<int, int>> positions);
  void applyMove(BackgammonColor color, std::pair<int, int> positions);

private:
  std::array<BackgammonBoardCell, 24> cells_;
  BackgammonBoardCell bar_;
  BackgammonBoardCell off_;
};

#endif /* BACKGAMMONBOARD_HPP */
