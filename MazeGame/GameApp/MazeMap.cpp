#include "MazeMap.h"

CMazeMap::CMazeMap()
  : map
{
  //{ 0b1011,0b0011,0b0011,0b0101 },
  //{ 0b1001,0b0101,0b1001,0b0110 },
  //{ 0b1100,0b1100,0b1010,0b0101 },
  //{ 0b1110,0b1010,0b0011,0b0110 }
  { 0b1001,0b0001,0b0001,0b0101 },
  { 0b1000,0b0000,0b0000,0b0100 },
  { 0b1000,0b0000,0b0000,0b0100 },
  { 0b1010,0b0010,0b0010,0b0110 }
}
{
  ;
}

CMazeMap::~CMazeMap()
{
}

size_t CMazeMap::getWidth()
{
  return sWidth;
}

size_t CMazeMap::getHeight()
{
  return sHeight;
}

UDirections CMazeMap::getWallPosition(int row, int col)
{
  return map[row][col];
}
