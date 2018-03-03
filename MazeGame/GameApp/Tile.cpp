#include "Tile.h"

CTile::CTile()
{
}


CTile::~CTile()
{
}

SWall CTile::getWall()
{
  return mWall;
}

void CTile::setWall(SWall wall)
{
  mWall = wall;
}