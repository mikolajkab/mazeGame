#pragma once

#include "Wall.h"

class CTile
{
public:
  CTile();
  ~CTile();
  SWall getWall(void);
  void setWall(SWall);

  static constexpr int sTileWidth = 64;
  static constexpr int sTileHeight = 64;

private:
  SWall mWall;
};

