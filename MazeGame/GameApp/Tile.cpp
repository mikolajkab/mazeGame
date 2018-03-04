#include "Tile.h"

CTile::CTile()
{
}


CTile::~CTile()
{
}

SWallPosition CTile::getWall()
{
  return mWall;
}

void CTile::setWall(SWallPosition wall)
{
  mWall = wall;
}