#include "CMaze.h"

CMaze::CMaze()
{
  int i, j, k;

  for (i = 0; i < sTileHeight; i++)
  {
    for (j = 0; j < sTileWidth; j++)
    {
      k = ((((i & 0x8) == 0) ^ ((j & 0x8)) == 0)) * 255;
      background[i][j][0] = (GLubyte)k;
      background[i][j][1] = (GLubyte)k;
      background[i][j][2] = (GLubyte)k;
      background[i][j][3] = (GLubyte)255;
    }
  }
}

CMaze::~CMaze()
{
}

const int CMaze::getTileHeight()
{
  return sTileHeight;
}

const int CMaze::getTileWidth()
{
  return sTileWidth;
}

GLuint CMaze::getTextName(void)
{
  return mTexName;
}