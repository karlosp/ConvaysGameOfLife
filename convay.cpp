#include "convay.hpp"
#include <algorithm>
#include <map>
#include <vector>

namespace convay {


Position operator+(const Position &lhs,
                                   const Position &rhs) {
  return std::make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

bool operator==(const Position &lhs,
                        const Position &rhs) {
  return lhs.first == rhs.first && lhs.second == rhs.second;
}

Board advance(const Board &board) {

  Board advance;
  std::map<Position, int> count_live_neighbours;

  for (auto &board_cell : board) {
    Board absolute_neighbours;
    for (auto const &rn : relative_neighbours) {
      absolute_neighbours.emplace(board_cell + rn);
    }

    int alive_neighbours =
        std::count_if(absolute_neighbours.begin(), absolute_neighbours.end(),
                      [&board](auto const &cell) { return board.count(cell); });

    // Any live cell with two or three live neighbors lives on to the next
    // generation
    if (alive_neighbours == 2 || alive_neighbours == 3) {
      advance.emplace(board_cell);
    }

    for (auto const &cell : absolute_neighbours) {
      count_live_neighbours[cell]++;
    }
  }

  for (auto const &cell : count_live_neighbours) {
    // Any dead cell with exactly three live neighbors becomes a live cell, as
    // if by reproduction.
    if (cell.second == 3) {
      advance.emplace(cell.first);
    }
  }

  return advance;
}

Board convay::crossXxX(int X) {
  Board cross;
  for (int i = 0; i < X; ++i) {
    for (int j = 0; j < X; ++j) {
      if (i == j)
        cross.emplace(std::make_pair(i, j));
    }
  }

  for (int i = 0; i < X; ++i) {
    for (int j = X - 1; j >= 0; --j) {
      if (i + j == X - 1)
        cross.emplace(std::make_pair(i, j));
    }
  }

  return cross;
}



bool operator<(const Position &lhs,
                       const Position &rhs) {
  return lhs.first < rhs.first || lhs.second < rhs.second;
}
}
