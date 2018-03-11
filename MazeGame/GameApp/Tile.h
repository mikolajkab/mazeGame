#pragma once

#include "WallPosition.h"

class CTile
{
public:
  CTile();
  ~CTile();
  UWallPosition getWall(void);
  void setWall(UWallPosition);

  static constexpr int sWidth = 64;
  static constexpr int sHeight = 64;

private:
  UWallPosition mWall;
};

