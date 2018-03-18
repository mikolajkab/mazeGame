#pragma once

#include "WallPosition.h"

class CMazeMap
{
public:
  CMazeMap();
  virtual ~CMazeMap();

  size_t getWidth();
  size_t getHeight();
  UDirections getWallPosition(int row, int col);

  static constexpr int sWidth = 8;
  static constexpr int sHeight = 8;

  UDirections map[sHeight][sWidth];
};

