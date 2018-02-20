#pragma once
#include <array>

#include <GL/freeglut.h>

using std::array;

typedef void(*FuncSig)(void);

class CMaze
{
public:
  CMaze();
  ~CMaze();
  const int getTileHeight();
  const int getTileWidth();
  GLuint getTextName(void);

private:
  GLuint mTexName;
  static constexpr int sTileHeight = 64;
  static constexpr int sTileWidth = 64;

public:
  array<array<array<GLubyte, 4>, sTileWidth>, sTileHeight> background;
};

