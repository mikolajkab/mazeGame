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

  static constexpr int sWidth = 16;
  static constexpr int sHeight = 16;
  static constexpr SPosition goalPosition[]= { { 7,7 },{ 7,8 },{ 8,7 },{ 8,8 } };

  std::array<std::array<UDirections, sHeight>, sWidth> map;

private:
  int mMapNum;
};

