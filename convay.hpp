#ifndef CONVAY_HPP
#define CONVAY_HPP
#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>

namespace convay {
using Position = std::pair<int, int>;
using Board = std::set<Position>;

Position operator+(Position const &lhs, Position const &rhs);

bool operator==(Position const &lhs, Position const &rhs);

bool operator<(Position const &lhs, Position const &rhs);

// clang-format off
const Board relative_neighbours{{-1,-1}, {0,-1}, {1, -1},
                                {-1, 0},         {1,  0},
                                {-1, 1}, {0, 1}, {1,  1}};
// clang-format on

Board advance(const Board &board);

// clang-format off
const Board pentadecathlon{{0,0}, {1,0}, {2,0},
                           {0,1},        {2,1},
                           {0,2}, {1,2}, {2,2},
                           {0,3}, {1,3}, {2,3},
                           {0,4}, {1,4}, {2,4},
                           {0,5}, {1,5}, {2,5},
                           {0,6},        {2,6},
                           {0,7}, {1,7}, {2,7}};
// clang-format on

Board crossXxX(int X);
}

inline std::ostream &operator<<(std::ostream &os, convay::Board const &board) {

  const auto min_max_x = std::minmax_element(
      board.cbegin(), board.cend(),
      [](convay::Position const &lhs, convay::Position const &rhs) {
        return lhs.first < rhs.first;
      });

  const auto min_max_y = std::minmax_element(
      board.cbegin(), board.cend(),
      [](convay::Position const &lhs, convay::Position const &rhs) {
        return lhs.second < rhs.second;
      });

  for (int row = min_max_y.first->second; row <= min_max_y.second->second;
       ++row) {
    for (int col = min_max_x.first->first; col <= min_max_x.second->first;
         ++col) {
      if (board.count(convay::Position(col, row))) {
        os << "X";
      } else {
        os << " ";
      }
    }
    os << "\n";
  }

  for (int col = 0; col <= min_max_x.second->first - min_max_x.first->first;
       ++col) {
    os << "~";
  }
  os << "\n";

  return os;
}
#endif // CONVAY_HPP
