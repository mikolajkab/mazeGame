#pragma once

#include <array>

#include "WallPosition.h"

class CMazeMap
{
public:
  CMazeMap(int mapNum);
  virtual ~CMazeMap();

  size_t getWidth();
  size_t getHeight();
  UDirections getWallPosition(int row, int col);
  void switchMap();

  static constexpr int sWidth = 8;
  static constexpr int sHeight = 8;

  std::array<std::array<UDirections, sHeight>, sWidth> map;

private:
  int mMapNum;
};

