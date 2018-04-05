#include "Tile.h"

CTile::CTile()
{
}

CTile::~CTile()
{
}

UDirections CTile::getWall()
{
  return mWall;
}

void CTile::setWall(UDirections wall)
{
  mWall = wall;
}