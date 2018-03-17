#pragma once

#include "WallPosition.h"

class CTile
{
public:
  CTile();
  ~CTile();
  UDirections getWall(void);
  void setWall(UDirections);

  static constexpr int sWidth = 64;
  static constexpr int sHeight = 64;

private:
  UDirections mWall;
};

