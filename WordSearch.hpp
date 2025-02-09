//
// Created by SnirN on 1/31/2025.
//

#ifndef LEETCODE_150_C___WORDSEARCH_HPP
#define LEETCODE_150_C___WORDSEARCH_HPP

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
  using boardPosition = std::pair<int, int>;

public:
  bool isPositionValid(boardPosition &position) {
    return position.first >= 0 && position.second >= 0;
  }

  int convertPositionToInt(boardPosition &position){
    std::string numStr = std::to_string(position.first) + std::to_string
                         (position.second);
    return std::stoi(numStr);
  }

  bool isPositionAtUse(std::unordered_map<int, bool> &inUseIndexes, boardPosition &position)
  {
    int num = convertPositionToInt(position);
    return inUseIndexes.find(num) != inUseIndexes.end();
  }

  bool isSeqBreak(std::vector<std::vector<char>> &board, std::string &word,
                    int stringIdx, boardPosition &position) {
    return stringIdx != 0 &&
           board[position.first][position.second] != word[stringIdx];
  }

  bool helper(std::vector<std::vector<char>> &board, std::string &word,
              int stringIdx, boardPosition &position,
              std::unordered_map<int, bool> &inUseIndexes, bool &res) {
    if(stringIdx + 1 == word.size()){
      return true;
    }

    if (!isPositionValid(position) ||
        isPositionAtUse(inUseIndexes, position) ||
        isSeqBreak(board, word, stringIdx, position)) {
      return false;
    }

    if (board[position.first][position.second] == word[stringIdx]) {
      int num = convertPositionToInt(position);
      inUseIndexes[num] = true;
      position.first += 1;
      res |= helper(board, word, stringIdx + 1, position, inUseIndexes, res);
      position.first -= 2;
      res |= helper(board, word, stringIdx + 1, position, inUseIndexes, res);
      position.first += 1;
      position.second += 1;
      res |= helper(board, word, stringIdx + 1, position, inUseIndexes, res);
      position.second -= 2;
      res |= helper(board, word, stringIdx + 1, position, inUseIndexes, res);
      //backtrack
      inUseIndexes[num] = false;
      position.second += 1;
    }

    position.first += 1;
    res |= helper(board, word, stringIdx, position, inUseIndexes, res);
    position.first -= 2;
    res |= helper(board, word, stringIdx, position, inUseIndexes, res);
    position.first += 1;
    position.second += 1;
    res |= helper(board, word, stringIdx, position, inUseIndexes, res);
    position.second -= 2;
    res |= helper(board, word, stringIdx, position, inUseIndexes, res);

    return res;
  }

  bool exist(std::vector<std::vector<char>> &board, std::string word) {
    boardPosition position{0, 0};
    std::unordered_map<int, bool> inUseIndexes;
    bool res = false;
    return helper(board, word, 0, position, inUseIndexes, res);
  }
};
#endif // LEETCODE_150_C___WORDSEARCH_HPP
