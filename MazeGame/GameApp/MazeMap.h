#pragma once

#include "WallPosition.h"

class CMazeMap
{
public:
  CMazeMap();
  virtual ~CMazeMap();

  size_t getWidth();
  size_t getHeight();
  UWallPosition getWallPosition(int row, int col);

  static constexpr int sWidth = 4;
  static constexpr int sHeight = 4;

  UWallPosition map[sHeight][sWidth];
};

