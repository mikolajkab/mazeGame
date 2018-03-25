#include "MazeMap.h"

CMazeMap::CMazeMap(int mapNum)
  : mMapNum(mapNum)
{
  switchMap();
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

void CMazeMap::switchMap()
{
  if (mMapNum == 1)
  {
    map =
    {
      {
        { 0b1001,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0101 },
        { 0b1010,0b0101,0b1001,0b0011,0b0001,0b0011,0b0001,0b0001,0b0001,0b0001,0b0011,0b0001,0b0011,0b0001,0b0011,0b0100 },
        { 0b1101,0b1100,0b1000,0b0111,0b1100,0b1101,0b1100,0b1100,0b1110,0b1100,0b1001,0b0110,0b1101,0b1000,0b0011,0b0100 },
        { 0b1000,0b0100,0b1100,0b1011,0b0100,0b1110,0b1100,0b1000,0b0111,0b1000,0b0110,0b1011,0b0000,0b0100,0b1001,0b0100 },
        { 0b1100,0b1100,0b1010,0b0001,0b0010,0b0001,0b0010,0b0110,0b1001,0b0100,0b1011,0b0001,0b0110,0b1000,0b0110,0b1100 },
        { 0b1000,0b0110,0b1101,0b1110,0b1101,0b1100,0b1011,0b0001,0b0100,0b1010,0b0001,0b0110,0b1011,0b0100,0b1001,0b0100 },
        { 0b1010,0b0101,0b1000,0b0011,0b0100,0b1110,0b1001,0b0110,0b1110,0b1001,0b0000,0b0011,0b0101,0b1000,0b0100,0b1100 },
        { 0b1001,0b0100,0b1000,0b0011,0b0110,0b1001,0b0110,0b1001,0b0101,0b1100,0b1010,0b0101,0b1100,0b1100,0b1000,0b0100 },
        { 0b1110,0b1100,0b1100,0b1011,0b0011,0b0010,0b0101,0b1000,0b0110,0b1010,0b0011,0b0010,0b0110,0b1010,0b0100,0b1100 },
        { 0b1001,0b0100,0b1000,0b0011,0b0001,0b0111,0b1000,0b0100,0b1001,0b0111,0b1001,0b0011,0b0011,0b0111,0b1000,0b0100 },
        { 0b1100,0b1010,0b0110,0b1001,0b0110,0b1101,0b1110,0b1010,0b0100,0b1001,0b0110,0b1101,0b1101,0b1011,0b0100,0b1100 },
        { 0b1000,0b0011,0b0001,0b0110,0b1001,0b0010,0b0011,0b0101,0b1110,0b1010,0b0011,0b0000,0b0010,0b0101,0b1010,0b0100 },
        { 0b1000,0b0001,0b0110,0b1001,0b0010,0b0001,0b0111,0b1110,0b1001,0b0001,0b0001,0b0000,0b0001,0b0010,0b0101,0b1110 },
        { 0b1100,0b1000,0b0101,0b1010,0b0001,0b0010,0b0001,0b0011,0b0100,0b1100,0b1100,0b1100,0b1100,0b1101,0b1010,0b0101 },
        { 0b1000,0b0100,0b1110,0b1001,0b0010,0b0001,0b0010,0b0101,0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0001,0b0100 },
        { 0b1110,0b1010,0b0011,0b0010,0b0011,0b0010,0b0011,0b0010,0b0110,0b1110,0b1110,0b1110,0b1110,0b1110,0b1110,0b1110 }
      }
    };
  }
  else if (mMapNum == 2)
  {
    map =
    {
      {
        { 0b1101,0b1001,0b0011,0b0011,0b0011,0b0111,0b1011,0b0011,0b0011,0b0001,0b0011,0b0011,0b0001,0b0011,0b0011,0b0101 },
        { 0b1100,0b1100,0b1011,0b0011,0b0011,0b0011,0b0011,0b0001,0b0011,0b0010,0b0011,0b0001,0b0010,0b0011,0b0101,0b1100 },
        { 0b1000,0b0110,0b1001,0b0011,0b0011,0b0011,0b0011,0b0010,0b0011,0b0011,0b0101,0b1010,0b0011,0b0101,0b1100,0b1100 },
        { 0b1000,0b0101,0b1100,0b1001,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0010,0b0011,0b0111,0b1100,0b1100,0b1100 },
        { 0b1100,0b1100,0b1100,0b1100,0b1001,0b0011,0b0011,0b0111,0b1011,0b0011,0b0011,0b0101,0b1101,0b1100,0b1100,0b1100 },
        { 0b1100,0b1100,0b1100,0b1100,0b1100,0b1001,0b0011,0b0111,0b1011,0b0011,0b0101,0b1100,0b1100,0b1100,0b1100,0b1100 },
        { 0b1100,0b1100,0b1100,0b1100,0b1100,0b1100,0b1001,0b0011,0b0011,0b0101,0b1100,0b1000,0b0100,0b1100,0b1100,0b1100 },
        { 0b1100,0b1100,0b1100,0b1100,0b1100,0b1100,0b1100,0b1001,0b0101,0b1100,0b1100,0b1100,0b1100,0b1100,0b1100,0b1100 },
        { 0b1100,0b1100,0b1000,0b0000,0b0000,0b0000,0b0000,0b0010,0b0110,0b1100,0b1000,0b0100,0b1100,0b1100,0b1100,0b1100 },
        { 0b1100,0b1100,0b1100,0b1100,0b1100,0b1100,0b1010,0b0011,0b0001,0b0110,0b1100,0b1100,0b1100,0b1100,0b1100,0b1100 },
        { 0b1100,0b1100,0b1100,0b1100,0b1110,0b1110,0b1011,0b0011,0b0010,0b0011,0b0110,0b1100,0b1100,0b1100,0b1100,0b1100 },
        { 0b1100,0b1100,0b1100,0b1100,0b1011,0b0011,0b0011,0b0011,0b0001,0b0011,0b0011,0b0110,0b1100,0b1100,0b1000,0b0100 },
        { 0b1000,0b0110,0b1100,0b1010,0b0011,0b0011,0b0011,0b0011,0b0010,0b0011,0b0011,0b0011,0b0110,0b1100,0b1100,0b1100 },
        { 0b1000,0b0101,0b1010,0b0011,0b0011,0b0011,0b0011,0b0011,0b0001,0b0011,0b0011,0b0011,0b0111,0b1110,0b1110,0b1100 },
        { 0b1100,0b1100,0b1011,0b0011,0b0001,0b0011,0b0011,0b0111,0b1010,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0100 },
        { 0b1110,0b1010,0b0011,0b0011,0b0010,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0011,0b0110 }
      }
    };
  }
  else if (mMapNum == 3)
  {
    map =
    {
      {
        { 0b1001,0b0101,0b1001,0b0101,0b1001,0b0101,0b1001,0b0101,0b1001,0b0101,0b1001,0b0101,0b1001,0b0101,0b1001,0b0101 },
        { 0b1100,0b1100,0b1100,0b1110,0b1100,0b1100,0b1100,0b1100,0b1110,0b1100,0b1100,0b1100,0b1100,0b1110,0b1000,0b0100 },
        { 0b1100,0b1100,0b1100,0b1101,0b1000,0b0100,0b1100,0b1000,0b0101,0b1100,0b1000,0b0010,0b0100,0b1001,0b0100,0b1100 },
        { 0b1100,0b1000,0b0100,0b1000,0b0100,0b1100,0b1010,0b0100,0b1100,0b1000,0b0100,0b1101,0b1110,0b1100,0b1110,0b1110 },
        { 0b1100,0b1110,0b1100,0b1100,0b1100,0b1100,0b1101,0b1100,0b1100,0b1100,0b1110,0b1100,0b1001,0b0100,0b1101,0b1101 },
        { 0b1100,0b1101,0b1100,0b1100,0b1100,0b1100,0b1100,0b1000,0b0100,0b1000,0b0101,0b1000,0b0100,0b1100,0b1100,0b1100 },
        { 0b1000,0b0100,0b1000,0b0100,0b1100,0b1100,0b1100,0b1110,0b1100,0b1100,0b1000,0b0100,0b1100,0b1110,0b1000,0b0100 },
        { 0b1100,0b1100,0b1100,0b1100,0b1000,0b0100,0b1000,0b0101,0b1000,0b0110,0b1100,0b1100,0b1100,0b1001,0b0100,0b1100 },
        { 0b1100,0b1100,0b1100,0b1110,0b1100,0b1100,0b1100,0b1100,0b1100,0b1101,0b1100,0b1100,0b1000,0b0100,0b1110,0b1100 },
        { 0b1100,0b1100,0b1100,0b1101,0b1110,0b1100,0b1100,0b1100,0b1000,0b0100,0b1000,0b0110,0b1100,0b1100,0b1101,0b1100 },
        { 0b1110,0b1000,0b0100,0b1100,0b1101,0b1100,0b1100,0b1000,0b0110,0b1000,0b0110,0b1001,0b0100,0b1000,0b0100,0b1110 },
        { 0b1101,0b1100,0b1100,0b1100,0b1000,0b0000,0b0100,0b1110,0b1101,0b1100,0b1001,0b0100,0b1100,0b1100,0b1100,0b1101 },
        { 0b1000,0b0100,0b1110,0b1000,0b0100,0b1100,0b1010,0b0101,0b1100,0b1100,0b1100,0b1100,0b1110,0b1010,0b0110,0b1100 },
        { 0b1100,0b1100,0b1101,0b1100,0b1100,0b1100,0b1101,0b1100,0b1100,0b1010,0b0100,0b1000,0b0101,0b1101,0b1001,0b0100 },
        { 0b1100,0b1100,0b1100,0b1100,0b1000,0b0110,0b1100,0b1100,0b1000,0b0101,0b1000,0b0100,0b1000,0b0100,0b1100,0b1100 },
        { 0b1110,0b1010,0b0110,0b1010,0b0110,0b1011,0b0110,0b1010,0b0110,0b1010,0b0110,0b1010,0b0110,0b1010,0b0110,0b1110 }
      }
    };
  }
  else
  {
    map =
    {
      {
        { 0b1001,0b0001,0b0001,0b0001,0b0001,0b0001,0b0001,0b0001,0b0001,0b0001,0b0001,0b0001,0b0001,0b0001,0b0001,0b0101 },
        { 0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100 },
        { 0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100 },
        { 0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100 },
        { 0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100 },
        { 0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100 },
        { 0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0010,0b0010,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100 },
        { 0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100,0b1001,0b0101,0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100 },
        { 0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100,0b1010,0b0010,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100 },
        { 0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0001,0b0001,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100 },
        { 0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100 },
        { 0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100 },
        { 0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100 },
        { 0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100 },
        { 0b1000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0000,0b0100 },
        { 0b1010,0b0010,0b0010,0b0010,0b0010,0b0010,0b0010,0b0010,0b0010,0b0010,0b0010,0b0010,0b0010,0b0010,0b0010,0b0110 }
      }
    };
    mMapNum = 0;
  }
  mMapNum++;
}