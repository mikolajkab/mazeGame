#include "Tile.h"

CTile::CTile()
{
}


CTile::~CTile()
{
}

UWallPosition CTile::getWall()
{
  return mWall;
}

void CTile::setWall(UWallPosition wall)
{
  mWall = wall;
}