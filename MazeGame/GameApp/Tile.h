#pragma once

#include "WallPosition.h"

class CTile
{
public:
  CTile();
  ~CTile();
  SWallPosition getWall(void);
  void setWall(SWallPosition);

  static constexpr int sWidth = 64;
  static constexpr int sHeight = 64;

private:
  SWallPosition mWall;
};

